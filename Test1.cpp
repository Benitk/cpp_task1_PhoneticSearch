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




TEST_CASE("Test replacement of z and s - vice versa, lower-case and upper-case") {
    string text = "sally yyy zebra";
    CHECK(find(text, "zebra") == string("zebra"));
    CHECK(find(text, "sebra") == string("zebra"));
    CHECK(find(text, "Sebra") == string("zebra"));
    CHECK(find(text, "sally") == string("sally"));
    CHECK(find(text, "zally") == string("sally"));
    CHECK(find(text, "Zally") == string("sally"));
}


TEST_CASE("Test replacement of d and t - vice versa, lower-case and upper-case") {
    string text = "zzz desktop yyy xxx";
    CHECK(find(text, "DeskTop") == string("desktop"));
    CHECK(find(text, "Desktop") == string("desktop"));
    CHECK(find(text, "tesktop") == string("desktop"));
    CHECK(find(text, "teskdop") == string("desktop"));
    CHECK(find(text, "Teskdop") == string("desktop"));
    CHECK(find(text, "desktop") == string("desktop"));
    CHECK(find(text, "deskdop") == string("desktop"));
    CHECK(find(text, "DeskDop") == string("desktop"));
    CHECK(find(text, "deskTop") == string("desktop"));
}

TEST_CASE("Test replacement of o and u - vice versa, lower-case and upper-case") {
    string text = "xxx yyy our";
    CHECK(find(text, "our") == string("our"));
    CHECK(find(text, "Our") == string("our"));
    CHECK(find(text, "oUr") == string("our"));
    CHECK(find(text, "OUr") == string("our"));
    CHECK(find(text, "oor") == string("our"));
    CHECK(find(text, "uur") == string("our"));
    CHECK(find(text, "uor") == string("our"));
    CHECK(find(text, "UUr") == string("our"));
    CHECK(find(text, "OOr") == string("our"));
}

TEST_CASE("Test replacement of i and y , lower-case and upper-case") {
    string text = "xxx zzz idigital";
    CHECK(find(text, "Idigital") == string("idigital"));
    CHECK(find(text, "idIgital") == string("idigital"));
    CHECK(find(text, "idigItal") == string("idigital"));
    CHECK(find(text, "IdIgital") == string("idigital"));
    CHECK(find(text, "IdigItal") == string("idigital"));
    CHECK(find(text, "IdIgItal") == string("idigital"));
    CHECK(find(text, "ydigital") == string("idigital"));
    CHECK(find(text, "idygital") == string("idigital"));
    CHECK(find(text, "idigytal") == string("idigital"));
    CHECK(find(text, "Idygital") == string("idigital"));
    CHECK(find(text, "Idigytal") == string("idigital"));
    CHECK(find(text, "IdYgital") == string("idigital"));
    CHECK(find(text, "IdigYtal") == string("idigital"));
    CHECK(find(text, "IdYgYtal") == string("idigital"));
    CHECK(find(text, "YdYgYtal") == string("idigital"));
}

TEST_CASE("Test replacement of o and u, z and s , lower-case and upper-case") {
    string text = "xxx should yyy";
    CHECK(find(text, "should") == string("should"));
    CHECK(find(text, "zhould") == string("should"));
    CHECK(find(text, "zhoold") == string("should"));
    CHECK(find(text, "shuuld") == string("should"));
    CHECK(find(text, "zhOUld") == string("should"));
    CHECK(find(text, "ShoUld") == string("should"));
    CHECK(find(text, "zhoOld") == string("should"));
    CHECK(find(text, "Zhuold") == string("should"));
    CHECK(find(text, "ShUuld") == string("should"));
    CHECK(find(text, "Zhoold") == string("should"));

}

