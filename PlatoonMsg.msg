//a message about velocity information

cplusplus {{
	#include "veins/base/utils/Coord.h"
	#include "veins/modules/messages/BaseFrame1609_4_m.h"
	#include "veins/base/utils/SimpleAddress.h"
}}

namespace veins;

class BaseFrame1609_4;
class noncobject Coord;
class LAddress::L2Type extends void;

packet PlatoonMsg extends BaseFrame1609_4{
	Coord senderPos;
	Coord senderVel;
	simtime_t timeStampP;
	LAddress::L2Type senderAddress = -1;
}