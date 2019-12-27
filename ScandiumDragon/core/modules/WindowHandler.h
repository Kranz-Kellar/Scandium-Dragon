#pragma once
#include "../Module.h"
#include <GLFW/glfw3.h>

namespace SD {

	class WindowHandler : public Module
	{
		GLFWwindow* windowPtr;
		int windowWidth = 640;
		int windowHeight = 480;
		const char* windowTitle = "Default";
	public:
		
		WindowHandler() {}
		virtual ~WindowHandler() override {};

		void init() override;
		void update(uint32_t delta) override;
		void terminate() override;

		void onEvent(Event* event) override;
	};

}

