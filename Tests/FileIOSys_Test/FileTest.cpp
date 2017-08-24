#include "Tests\catch.hpp"
#include "CCE\FileIOSys\File.hpp"

TEST_CASE("Opening a file at beginning", "[File]")
{
	FILE* testHandle = 0;

	{
		cce::File file("NewData1.txt",
					   cce::File::Mode::Read,
					   cce::File::Type::Text,
					   cce::File::Options::StartOfFile);
	}

	fopen_s(&testHandle, "NewData1.txt", "r");
	REQUIRE(testHandle != 0);
	if (testHandle != 0)
	{
		fclose(testHandle);
	}

}