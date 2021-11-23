#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "duration.hpp"


// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. 

TEST_CASE("duration")
{
    // d)
    Duration d1;
    Duration d2(5);
    Duration d3(50);

    REQUIRE(d1.GetDuration() == 0);
    REQUIRE(d2.GetDuration() == 5);
    REQUIRE(d3.GetDuration() == 50);

    // e)
    d1.Tick();
    REQUIRE(d1.GetDuration() == 1);

    // f)
    d2.Tick(5);
    REQUIRE(d2.GetDuration() == 10);

    // g)
    d2.SetAlarm(15);
    REQUIRE(d2.Tick() == false);
    REQUIRE(d2.Tick(5) == true);

    // h)
    // Throws assertion error if alarm < time
    // d3.SetAlarm(5);

    // i)
    d1.SetAlarm(1);
    REQUIRE(d1.Tick() == true);
    d1.SetAlarm(3);
    REQUIRE(d1.Tick(5) == true);

}