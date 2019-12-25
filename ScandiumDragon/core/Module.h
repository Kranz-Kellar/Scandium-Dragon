#pragma once
#include <stdint.h>
#include "ModuleType.h"

namespace SD {

	class Module
	{
		ModuleType type;
		bool isEnabled;
	public:
		virtual void init() = 0;
		virtual void update(uint32_t delta) = 0;
		virtual void terminate() = 0;

		virtual void disable() { isEnabled = false; }
		virtual void enable() { isEnabled = true; }
	};

}
