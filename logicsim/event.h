#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
        
  bool operator()(const Event *Event1, Event const *Event2) {
    return Event1->time < Event2->time;
  }

} EventLess;
	
#endif
