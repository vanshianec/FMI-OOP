
#include "ApplicationLauncher.h"
#include "ClassTests.h"

/**
*   @brief Application launch point.
*/

int main()
{
	ApplicationLauncher launcher;
	launcher.run();	

	/* Uncomment to run test cases */

	//doctest::Context().run();

	return 0;
}

