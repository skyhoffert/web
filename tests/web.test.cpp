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

TEST_CASE( "Instantiation.", "[web]" ) {
    Web* web = new Web(4);

    REQUIRE(web->Size() == 0);

    delete web;
}
