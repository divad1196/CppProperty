#define CATCH_CONFIG_MAIN // provides main(); this line is required in only one .cpp file
#include "Catch2/single_include/catch2/catch.hpp"
#include "../src/property.h"

#include <string>
#include <iostream>

std::string getter (const std::string& value) {
    return value + "xyz";
}

std::string setter (std::string& value, const std::string& new_value) {
    return value = "setted to : " + new_value;
}

TEST_CASE( "Constructor", "[bst]") {
    

    SECTION( "Empty tree" ) {
        Property<std::string, getter, setter> p("abcde");
        std::cout << (std::string)p << std::endl;
        
        p = "new value";
        std::cout << (std::string)p << std::endl;
    }
}
