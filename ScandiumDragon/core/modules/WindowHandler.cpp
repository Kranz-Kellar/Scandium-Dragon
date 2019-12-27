#include "WindowHandler.h"

void SD::WindowHandler::init()
{
	this->enable();

	if (!glfwInit()) {
		Logger::Log(LOG_CRITICAL, "glfwInit() error!");
		return;
	}

	this->windowPtr = glfwCreateWindow(this->windowWidth, this->windowHeight, this->windowTitle, NULL, NULL);
	if (!this->windowPtr) {
		Logger::Log(LOG_CRITICAL, "glfwCreateWindow() error! Terminating glfw...");
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(this->windowPtr);
}

void SD::WindowHandler::update(uint32_t delta)
{
	if (!this->isEnabled) {
		return;
	}
	if (glfwWindowShouldClose(this->windowPtr)) {
		this->terminate();
		return;
	}

	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(this->windowPtr);
	glfwPollEvents();
}

void SD::WindowHandler::terminate()
{
	glfwTerminate();
	Logger::Log(LOG_DEBUG, "glfw was terminated");
}

void SD::WindowHandler::onEvent(Event* event)
{
}
