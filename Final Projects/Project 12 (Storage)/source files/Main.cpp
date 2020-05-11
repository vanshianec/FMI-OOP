#include "ApplicationLauncher.h"
#include "Serializer.h"
#include "Deserializer.h"

#include <fstream>
#include <iostream>

int main()
{
	Visitor* serializer = new Serializer();
	Visitor* deserializer = new Deserializer();

	ApplicationLauncher launcher(serializer, deserializer);
	launcher.run(); 

	delete serializer;
	delete deserializer;
}