
#include <stdio.h>
#include "core/Engine.h"

#include "util/Logger.h"

using namespace SD;

int main() {
	Engine engine;

	engine.init();
	engine.update();
	engine.terminate();

	return 0;
}