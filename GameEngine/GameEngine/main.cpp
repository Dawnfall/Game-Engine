#include "TestGame.h"
#include "CoreEngine.h"
#include "Display.h"
#include "Mesh.h"
#include "Shader.h"

#include <string>
#include <iostream>

int main(int argc, char** argv)
{
	TestGame g;

	CoreEngine cE(&g);

	cE.Start(100);


	std::cerr << "Press any key...";
	std::cin.ignore();

	return 0;
}