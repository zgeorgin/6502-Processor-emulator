#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include <processor.h>

TEST_CASE("testing condReg_t registors", "[condReg_t]")
{
    SECTION("testing for maximum")
    {
        condReg_t P;
        uint8_t value = UINT8_MAX;
        P.reg_value = value;
        REQUIRE(P.get(Conditions::C) == 1);
        REQUIRE(P.get(Conditions::Z) == 1);
        REQUIRE(P.get(Conditions::I) == 1);
        REQUIRE(P.get(Conditions::D) == 1);
        REQUIRE(P.get(Conditions::B) == 1);
        REQUIRE(P.get(Conditions::L) == 1);
        REQUIRE(P.get(Conditions::V) == 1);
        REQUIRE(P.get(Conditions::N) == 1);
    }

    SECTION("random tests for set operation")
    {
        condReg_t P;
        bool a[8] = {0};
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 8; j++) a[j] = rand() % 2;
            P.set(Conditions::C, a[0]);
            P.set(Conditions::Z, a[1]);
            P.set(Conditions::I, a[2]);
            P.set(Conditions::D, a[3]);
            P.set(Conditions::B, a[4]);
            P.set(Conditions::L, a[5]);
            P.set(Conditions::V, a[6]);
            P.set(Conditions::N, a[7]);

            REQUIRE(P.get(Conditions::C) == a[0]);
            REQUIRE(P.get(Conditions::Z) == a[1]);
            REQUIRE(P.get(Conditions::I) == a[2]);
            REQUIRE(P.get(Conditions::D) == a[3]);
            REQUIRE(P.get(Conditions::B) == a[4]);
            REQUIRE(P.get(Conditions::L) == a[5]);
            REQUIRE(P.get(Conditions::V) == a[6]);
            REQUIRE(P.get(Conditions::N) == a[7]);
        }
    }
}