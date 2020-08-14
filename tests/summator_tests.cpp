#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest.h"
#include "thirdparty/doctest/doctest.h"
#include "summator.h"


TEST_CASE("testing the Summator class") 
{
    // class under test 
    Summator* cut = new Summator();


    // clean up 
    delete cut;
}