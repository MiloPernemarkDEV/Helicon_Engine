#include "Application.h"
	


int main ()
{
	Helicon::Application app;

	if (!app.LaunchCoreSystems()) 
	{
		throw std::runtime_error("Failed to launch core systems");
	}

	if (!app.LaunchModules())
	{
		throw std::runtime_error("Failed to launch modules");
	}
	
	app.GameLoop();	

	app.ShutdownModules();

	app.ShutdownCore();

	return EXIT_SUCCESS;
}