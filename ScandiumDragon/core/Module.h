#pragma once
#include <stdint.h>
#include "ModuleType.h"
#include "events/EventManager.h"

namespace SD {

	class Module
	{
		ModuleType type;
		bool isEnabled;
	public:
		virtual ~Module() = 0;

		virtual void init() = 0;
		virtual void update(uint32_t delta) = 0;
		virtual void terminate() = 0;

		virtual void subscribeOnEventOfType(EventType type);
		virtual void invokeEvent(Event* event);
		virtual void onEvent(Event* event) = 0;

		virtual void disable() { isEnabled = false; }
		virtual void enable() { isEnabled = true; }
	};

}
