//The lead vehicle starts broadcasting it's own speed/position information

#include "SimplePlatoon.h"

using namespace veins;

Define_Module(veins::SimplePlatoon);

void SimplePlatoon::initialize(int stage){
	DemoBaseApplLayer::initialize(stage);
	if(stage == 0){
	    currentSubscribedServiceId = -1;
		sendPeriod = 0.1;
		wsmSendEvt = new cMessage("wsm send task", 77);
		controlPeriod = 0.1;
		controlEvt = new cMessage("platoon control task", 88);
		
		lastMsg = PlatoonMsg();
	}
	else if(stage == 1){
		if(myId == 15){
		    currentSubscribedServiceId = 17;
			startService(Channel::sch2, currentSubscribedServiceId, "NumVehicle Service");
		}
        scheduleAt(simTime()+sendPeriod, wsmSendEvt);
        scheduleAt(simTime()+controlPeriod, controlEvt);
	}
}

void SimplePlatoon::handleSelfMsg(cMessage* msg){
	if(msg->getKind() == 77){
	    PlatoonMsg* pmsg = new PlatoonMsg();
		pmsg->setSenderAddress(myId);
		pmsg->setSenderPos(curPosition);
		pmsg->setSenderVel(curSpeed);
		pmsg->setTimeStampP(simTime());
		sendDown(pmsg->dup());
		delete pmsg;
		scheduleAt(simTime() + sendPeriod, wsmSendEvt);
	}
	else if (msg->getKind() == 88){
		platoonControl();
		scheduleAt(simTime() + controlPeriod, controlEvt);
	}
	else{
		DemoBaseApplLayer::handleSelfMsg(msg);
	}
}

void SimplePlatoon::onWSM(BaseFrame1609_4* frame){
	if (PlatoonMsg* pmsg = dynamic_cast<PlatoonMsg*>(frame)){
		if (pmsg->getSenderAddress() == myId - 6)
			lastMsg = *pmsg;
	}
}

void SimplePlatoon::platoonControl(){
	Coord precedingVehicleVel = lastMsg.getSenderVel();
	Coord precedingVehiclePos = lastMsg.getSenderPos();
	
	double desiredDistance = 10;
	
	double errorDistance = (precedingVehiclePos - curPosition).length();
	double diffSpeed = (precedingVehicleVel - curSpeed).length();
	
	double k1 = 1, k2 = 1;
	double acc = k1*errorDistance + k2*diffSpeed;
	
	std::cout << "t" << simTime() << ":DistErr [" << lastMsg.getSenderAddress()
	          << "]=[" << myId << "]:" << errorDistance
	          << "acc:" << acc << std::endl;
	
	if (acc > 0){
		traciVehicle->setAccel(acc);
		traciVehicle->setSpeedMode(0x06);
		traciVehicle->setSpeed(100.0);
	} 
	else if (acc < 0){
		traciVehicle->setDecel(-acc);
		traciVehicle->setEmergencyDecel(-acc);
		traciVehicle->setSpeedMode(0x06);
		traciVehicle->setSpeed(0.0);
	}
	else{
		traciVehicle->setDecel(0);
		traciVehicle->setEmergencyDecel(0);
		traciVehicle->setSpeedMode(0x06);
		traciVehicle->setSpeed(curSpeed.length());
	}
}
