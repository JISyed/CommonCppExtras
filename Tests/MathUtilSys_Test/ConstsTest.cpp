#include "Tests\catch.hpp"
#include "CCE\MathUtilSys\Consts.hpp"

TEST_CASE("Test Math Constants", "[Math]")
{
	REQUIRE(cce::Math::Consts::Pi == 3.1415926535f);
}