/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2020-02
 */

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

//Erel's tests: 

TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    /* Add more checks here */
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    /* Add more checks here */
}

/* Add more test cases here */


//Hila's tests

TEST_CASE("Test v replaced by w case") {
    string text = "Corona wirus please go from here FOREWER";
    CHECK(find(text, "virus") == string("wiros")); 
    CHECK(find(text, "VIRUS") == string("wiros")); 
    CHECK(find(text, "forever") == string("FOREWER")); 
    CHECK(find(text, "forewer") == string("FOREWER")); 
}

TEST_CASE("Test w replaced by v case") { 

}

TEST_CASE("Test return the currect word, v&w") {

}

TEST_CASE("Test b replaced by f case") {

}

TEST_CASE("Test b replaced by p case") {
    
}

TEST_CASE("Test f replaced by b case") {
    
}

TEST_CASE("Test f replaced by p case") {
    
}

TEST_CASE("Test p replaced by f case") {
    
}

TEST_CASE("Test p replaced by b case") {
    
}

TEST_CASE("Test return the currect word, b&p&f") {

}