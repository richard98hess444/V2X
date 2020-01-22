//When WSM is received we save it in lastMsg

#pragma once

#include "veins/modules/application/ieee80211p/DemoBaseApplLayer.h"
#include "PlatoonMsg_m.h"

namespace veins {
	
	class VEINS_API SimplePlatoon : public DemoBaseApplLayer{
		public:
			void initialize(int stage) override;
		
		protected:
			int currentSubscribedServiceId;
			cMessage* wsmSendEvt;
			simtime_t sendPeriod;
			simtime_t controlPeriod;
			
			cMessage* controlEvt;
			
			PlatoonMsg lastMsg;
		protected:
			void onWSM(BaseFrame1609_4* wsm) override;
			//void onWSA(DemoServiceAdvertisment* wsa) override;
			void handleSelfMsg(cMessage* msg) override;
			void platoonControl();
	};
}//namespace veins
