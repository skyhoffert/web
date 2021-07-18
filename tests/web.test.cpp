//
// Sky Hoffert
// Unit test for web.
// Created Jul-12-2021.
// Last modified Jul-12-2021.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "web.hpp"

#include <chrono>
#include <thread>
#include <iostream>

TEST_CASE("Instantiation.", "[web]") {
    Web* web = new Web(4);

    REQUIRE(web->Size() == 0);

    delete web;
}

TEST_CASE("Empty operations.", "[web]") {
    Web* web = new Web(4);

    REQUIRE(web->Contains(10) == false);
    REQUIRE(web->Find(10) == nullptr);

    delete web;
}

TEST_CASE("Insert a single value.", "[web]") {
    Web* web = new Web(4);

    REQUIRE(web->Insert(10) == 0);

    REQUIRE(web->Contains(10) == true);
    REQUIRE(web->Find(10) != nullptr);

    REQUIRE(web->Contains(9) == false);
    REQUIRE(web->Find(9) == nullptr);

    delete web;
}

TEST_CASE("Insert two values.", "[web]") {
    Web* web = new Web(4);

    REQUIRE(web->Insert(10) == 0);
    REQUIRE(web->Insert(5) == 0);

    // Web after the two above lines should be simply:
    //   (10) ->  (5)
    //        ->   -
    //        ->   -
    //        ->   -

    REQUIRE(web->Contains(10) == true);
    REQUIRE(web->Find(10) != nullptr);
    REQUIRE(web->Contains(5) == true);
    REQUIRE(web->Find(5) != nullptr);

    REQUIRE(web->Contains(9) == false);
    REQUIRE(web->Find(9) == nullptr);

    delete web;
}
