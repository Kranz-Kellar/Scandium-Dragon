#pragma once

#include <queue>
#include <vector>
#include <map>

#include "Event.h"

using namespace std;






namespace SD {

	class Module;
	typedef vector<Module*> modules;

	class EventManager
	{	
		
		static queue<Event*> _eventQueue;
		static map<EventType, modules> _subscribedModules;

		static void _invokeEvent(EventType type, Event* event);
	public:
		static void subscribeOnEvents(EventType type, Module* module);
		static void addEventToQueue(Event* event);
		static void invokeAllEvents();
	};

}
