#pragma once
#include "EventType.h"

namespace SD {

	class Event {
	public:
		EventType type;

		Event(EventType _type) : type(_type) {}
		virtual ~Event() = 0;
	};

}