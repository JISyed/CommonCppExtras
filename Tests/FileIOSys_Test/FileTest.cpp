#include "Tests\catch.hpp"
#include "CCE\FileIOSys\File.hpp"

TEST_CASE("Initilizing the File object", "[File]")
{
	cce::File file("RandomNonsense.bin", 
					cce::File::Mode::Read, 
					cce::File::Type::Binary, 
					cce::File::Options::EndOfFile,
					false
	);
}