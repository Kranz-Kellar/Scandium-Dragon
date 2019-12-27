#pragma once
#include <vector>
//#include "Module.h"
#include "modules/WindowHandler.h"
using namespace std;

namespace SD {

	class Engine
	{
		bool isWork;

		void _addModule(Module* newModule);
		vector<Module*> _modules;
	public:

		Engine() : isWork(true) {}

		void init();
		void update();
		void terminate();
	};

}

