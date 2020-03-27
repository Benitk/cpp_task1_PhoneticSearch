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
}

//OUR's tests

TEST_CASE("Test v replaced by w case") {
    string text = "Corona wirus please go from here FOREWER";
    CHECK(find(text, "virus") == string("wirus")); 
    CHECK(find(text, "VIRUS") == string("wirus")); 
    CHECK(find(text, "forever") == string("FOREWER")); 
    CHECK(find(text, "forewer") == string("FOREWER")); 
}

TEST_CASE("Test w replaced by v case") { 
    string text = "Ve vant to kNOv cpp";
    CHECK(find(text, "we") == string("Ve"));
    CHECK(find(text, "want") == string("vant"));
    CHECK(find(text, "know") == string("kNOv"));
    CHECK(find(text, "KNOV") == string("kNOv"));
}

TEST_CASE("Test return the currect word, v&w") {
    string text = "we check you when everything is fine"; 
    CHECK(find(text, "we") == string("we"));
    CHECK(find(text, "when") == string("when"));
    CHECK(find(text, "everything") == string("everything"));
}

TEST_CASE("Test b replaced by f case") {
    string text = "FE what you want to fe fye";
    CHECK(find(text, "be") == string("FE")); //check multiply: should return the first
    CHECK(find(text, "bye") == string("fye")); 
}

TEST_CASE("Test b replaced by p case") {
    string text = "py the way I love pANanas";
    CHECK(find(text, "by") == string("py")); 
    CHECK(find(text, "Bananas") == string("pANanas")); 
}

TEST_CASE("Test f replaced by b case") {
    string text = "borever jbciw";
    CHECK(find(text, "forever") == string("borever")); 
    CHECK(find(text, "FORever") == string("borever")); 
    CHECK(find(text, "jfciw") == string("jbciw")); 
}

TEST_CASE("Test f replaced by p case") {
    string text = "Ill go to see priends Por the next 4 hours";
    CHECK(find(text, "FRIENDS") == string("priends"));
    CHECK(find(text, "for") == string("Por"));
}

TEST_CASE("Test p replaced by f case") {
    string text = "poFcorn";
    CHECK(find(text, "popcorn") == string("poFcorn"));
    CHECK(find(text, "fofcorn") == string("poFcorn"));
}

TEST_CASE("Test p replaced by b case") {
    string text = "BbB or not to be";
    CHECK(find(text, "ppp") == string("BbB")); 
    CHECK(find(text, "PE") == string("be")); 
}

TEST_CASE("Test return the currect word, b&p&f") {
    string text = "fantastic popcorn on the bar";
    CHECK(find(text, "fantastic") == string("fantastic")); 
    CHECK(find(text, "popcorn") == string("popcorn")); 
    CHECK(find(text, "bar") == string("bar")); 
}

TEST_CASE("Test g replaced by j case") {
    string text = "jood jrade";
    CHECK(find(text, "GOOD") == string("jood")); 
    CHECK(find(text, "jOOd") == string("jood")); 
    CHECK(find(text, "grade") == string("jrade")); 
}

TEST_CASE("Test j replaced by g case") {
    string text = "gust more tests";
    CHECK(find(text, "just") == string("gust")); 
    CHECK(find(text, "GUST") == string("gust")); 
}

TEST_CASE("Test return the currect word, g&j") {
    string text = "its just a new day and im feeling good";
    CHECK(find(text, "just") == string("just")); 
    CHECK(find(text, "good") == string("good")); 
    CHECK(find(text, "GOOD") == string("good")); 
}

TEST_CASE("Test c replaced by k case") {
    string text = "klose";
    CHECK(find(text, "close") == string("klose")); 
    CHECK(find(text, "CLOSE") == string("klose")); 
    CHECK(find(text, "klOSE") == string("klose")); 
}

TEST_CASE("Test c replaced by q case") {
    string text = "qommon Qase";
    CHECK(find(text, "common") == string("qommon")); 
    CHECK(find(text, "case") == string("Qase")); 
    CHECK(find(text, "COMMON") == string("qommon")); 
}

TEST_CASE("Test k replaced by q case") {
    string text = "qeep going";
    CHECK(find(text, "keep") == string("qeep")); 
    CHECK(find(text, "KEep") == string("qeep")); 
}

TEST_CASE("Test k replaced by c case") {
    string text = "Capara"; 
    CHECK(find(text, "capara") == string("Capara")); 
    CHECK(find(text, "kapara") == string("Capara")); 
}

TEST_CASE("Test q replaced by c case") {
    string text = "cuite";
    CHECK(find(text, "quite") == string("cuite")); 
    CHECK(find(text, "QUITE") == string("cuite")); 
}

TEST_CASE("Test q replaced by k case") {
    string text = "kuery";
    CHECK(find(text, "query") == string("kuery")); 
    CHECK(find(text, "QUERY") == string("kuery")); 
}

TEST_CASE("Test return the currect word, c&k&q") {
    string text = "ok car qqqq";
    CHECK(find(text, "OK") == string("ok"));
    CHECK(find(text, "car") == string("car"));
    CHECK(find(text, "qQqq") == string("qqqq"));
}

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

