//
// Generated file, do not edit! Created by nedtool 5.5 from simple_platoon/PlatoonMsg.msg.
//

#ifndef __VEINS_PLATOONMSG_M_H
#define __VEINS_PLATOONMSG_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0505
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef VEINS_API
#  if defined(VEINS_EXPORT)
#    define VEINS_API  OPP_DLLEXPORT
#  elif defined(VEINS_IMPORT)
#    define VEINS_API  OPP_DLLIMPORT
#  else
#    define VEINS_API
#  endif
#endif

// cplusplus {{
	#include "veins/base/utils/Coord.h"
	#include "veins/modules/messages/BaseFrame1609_4_m.h"
	#include "veins/base/utils/SimpleAddress.h"
// }}


namespace veins {

/**
 * Class generated from <tt>simple_platoon/PlatoonMsg.msg:15</tt> by nedtool.
 * <pre>
 * packet PlatoonMsg extends BaseFrame1609_4
 * {
 *     Coord senderPos;
 *     Coord senderVel;
 *     simtime_t timeStampP;
 *     LAddress::L2Type senderAddress = -1;
 * }
 * </pre>
 */
class VEINS_API PlatoonMsg : public ::veins::BaseFrame1609_4
{
  protected:
    Coord senderPos;
    Coord senderVel;
    ::omnetpp::simtime_t timeStampP;
    LAddress::L2Type senderAddress;

  private:
    void copy(const PlatoonMsg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PlatoonMsg&);

  public:
    PlatoonMsg(const char *name=nullptr, short kind=0);
    PlatoonMsg(const PlatoonMsg& other);
    virtual ~PlatoonMsg();
    PlatoonMsg& operator=(const PlatoonMsg& other);
    virtual PlatoonMsg *dup() const override {return new PlatoonMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual Coord& getSenderPos();
    virtual const Coord& getSenderPos() const {return const_cast<PlatoonMsg*>(this)->getSenderPos();}
    virtual void setSenderPos(const Coord& senderPos);
    virtual Coord& getSenderVel();
    virtual const Coord& getSenderVel() const {return const_cast<PlatoonMsg*>(this)->getSenderVel();}
    virtual void setSenderVel(const Coord& senderVel);
    virtual ::omnetpp::simtime_t getTimeStampP() const;
    virtual void setTimeStampP(::omnetpp::simtime_t timeStampP);
    virtual LAddress::L2Type& getSenderAddress();
    virtual const LAddress::L2Type& getSenderAddress() const {return const_cast<PlatoonMsg*>(this)->getSenderAddress();}
    virtual void setSenderAddress(const LAddress::L2Type& senderAddress);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const PlatoonMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, PlatoonMsg& obj) {obj.parsimUnpack(b);}

} // namespace veins

#endif // ifndef __VEINS_PLATOONMSG_M_H

