#define CATCH_CONFIG_RUNNER
#include "Tests\catch.hpp"

int main(int argc, char* argv[])
{
	int result = Catch::Session().run(argc, argv);

	std::printf("Press any key to continue...\n");
	std::getchar();

	return (result < 0xff ? result : 0xff);
}