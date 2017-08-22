#include "Tests\catch.hpp"
#include "CCE\FileIOSys\File.hpp"

TEST_CASE("Initilizing the File object", "[File]")
{
	{
		cce::File file;
		REQUIRE(file.testValue == 50);
		file.testValue = 1240;
		REQUIRE(file.testValue == 1240);
	}
}