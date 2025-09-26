#define GLEW_NO_GLU
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>



#include "App.h"

int main(void)
{
	App* app = new App();
	app->initialization();
	app->createShaders();
	app->createModels();
	app->run();

	return 0;
}