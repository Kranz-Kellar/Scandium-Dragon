#include "Engine.h"


void SD::Engine::_addModule(Module* newModule)
{
	this->_modules.push_back(newModule);
}

void SD::Engine::init()
{
	//adding modules here
	WindowHandler* windowHandler = new WindowHandler();
	this->_addModule(windowHandler);


	for (auto module : _modules) {
		module->init();
	}
}

void SD::Engine::update()
{
	uint32_t deltaTime = 0;
	while (isWork) {
		//count delta

		for (auto module : _modules) {
			module->update(deltaTime);
		}
	}
}

void SD::Engine::terminate()
{
	for (auto module : _modules) {
		module->terminate();
		delete module;
	}
}
