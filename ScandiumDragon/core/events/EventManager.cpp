#include "EventManager.h"
#include "../Module.h"

queue<SD::Event*> SD::EventManager::_eventQueue;
map<SD::EventType, SD::modules> SD::EventManager::_subscribedModules;


void SD::Module::subscribeOnEventOfType(EventType type)
{
	EventManager::subscribeOnEvents(type, this);
}

void SD::Module::invokeEvent(Event* event)
{
	EventManager::addEventToQueue(event);
}

void SD::EventManager::_invokeEvent(EventType type, Event* event)
{
	for (uint32_t i = 0; i < _subscribedModules[type].size(); i++) {
		_subscribedModules[type][i]->onEvent(event);
	}
}

void SD::EventManager::subscribeOnEvents(EventType type, Module* module)
{
	_subscribedModules[type].push_back(module);
}

void SD::EventManager::addEventToQueue(Event* event)
{
	_eventQueue.push(event);
}

void SD::EventManager::invokeAllEvents()
{
	while (!_eventQueue.empty()) {
		Event* event = _eventQueue.front();
		_eventQueue.pop();
		_invokeEvent(event->type, event);
	}
}
