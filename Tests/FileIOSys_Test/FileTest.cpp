#include "Tests\catch.hpp"
#include "CCE\FileIOSys\File.hpp"
#include <string>

TEST_CASE("Opening a file at beginning", "[File]")
{
	FILE* testHandle = 0;

	auto mode = cce::File::Mode::Read;
	auto fileType = cce::File::Type::Text;
	auto options = cce::File::Options::StartOfFile;
	std::string fileName = std::string("NewData1.txt");

	SECTION("Opening text file for reading")
	{
		mode = cce::File::Mode::Read;
		fileType = cce::File::Type::Text;
		options = cce::File::Options::StartOfFile;
		fileName = std::string("NewDataR.txt");
	}

	SECTION("Opening text file for writing")
	{
		mode = cce::File::Mode::Write;
		fileType = cce::File::Type::Text;
		options = cce::File::Options::StartOfFile;
		fileName = std::string("NewDataW.txt");
	}

	SECTION("Opening text file for read & write")
	{
		mode = cce::File::Mode::ReadAndWrite;
		fileType = cce::File::Type::Text;
		options = cce::File::Options::StartOfFile;
		fileName = std::string("NewDataRW.txt");
	}


	SECTION("Opening binary file for reading")
	{
		mode = cce::File::Mode::Read;
		fileType = cce::File::Type::Binary;
		options = cce::File::Options::StartOfFile;
		fileName = std::string("NewDataR.bin");
	}

	SECTION("Opening binary file for writing")
	{
		mode = cce::File::Mode::Write;
		fileType = cce::File::Type::Binary;
		options = cce::File::Options::StartOfFile;
		fileName = std::string("NewDataW.bin");
	}

	SECTION("Opening binary file for read & write")
	{
		mode = cce::File::Mode::ReadAndWrite;
		fileType = cce::File::Type::Binary;
		options = cce::File::Options::StartOfFile;
		fileName = std::string("NewDataRW.bin");
	}


	{
		cce::File file(fileName.c_str(), mode, fileType, options);
	}

	fopen_s(&testHandle, fileName.c_str(), "r");
	REQUIRE(testHandle != 0);
	if (testHandle != 0)
	{
		fclose(testHandle);
	}

}