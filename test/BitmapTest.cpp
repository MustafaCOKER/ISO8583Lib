#define BOOST_TEST_MODULE BitmapTest

#include <boost/test/included/unit_test.hpp>

#include "Bitmap.h"

constexpr char TEST_CASE_NAME[] = "BitmapTestSuit";

BOOST_AUTO_TEST_CASE( BitmapTestSuit )
{
    BOOST_TEST_MESSAGE( "Testing initialization for BitMapTest" );
    Bitmap bitMaptest;

    BOOST_REQUIRE( bitMaptest.toHex().compare("0000000000000000") == 0 );

    bitMaptest.set(1);

    BOOST_CHECK( bitMaptest.get(1) == true );
    BOOST_CHECK( bitMaptest.toHex().compare("8000000000000000") == 0 );


    bitMaptest.set(64);
    bitMaptest.set(1);
    bitMaptest.unset(21);

    BOOST_CHECK( bitMaptest.get(1) == true );
    BOOST_CHECK( bitMaptest.get(64) == true );
    BOOST_CHECK( bitMaptest.get(21) == false );
    BOOST_CHECK( bitMaptest.toHex().compare("8000000000000001") == 0 );

    bitMaptest.unset(64);
    bitMaptest.unset(1);
    bitMaptest.unset(21);

    BOOST_CHECK( bitMaptest.get(1) == false );
    BOOST_CHECK( bitMaptest.get(64) == false );
    BOOST_CHECK( bitMaptest.get(21) == false );
    BOOST_CHECK( bitMaptest.toHex().compare("0000000000000000") == 0 );

    bitMaptest.flip(1);
    bitMaptest.flip(8);
    bitMaptest.flip(9);
    bitMaptest.flip(16);

    bitMaptest.flip(32);
    bitMaptest.flip(48);
    bitMaptest.flip(64);

    bitMaptest.flip(32); // flip again
    bitMaptest.flip(48); // flip again
    bitMaptest.flip(64); // flip again

    BOOST_CHECK( bitMaptest.get(1) == true );
    BOOST_CHECK( bitMaptest.get(8) == true );
    BOOST_CHECK( bitMaptest.get(9) == true );
    BOOST_CHECK( bitMaptest.get(16) == true );
    BOOST_CHECK( bitMaptest.get(32) == false );
    BOOST_CHECK( bitMaptest.get(48) == false );
    BOOST_CHECK( bitMaptest.get(64) == false );
    BOOST_CHECK( bitMaptest.toHex().compare("8181000000000000") == 0 );

    bitMaptest.clear();
    BOOST_REQUIRE( bitMaptest.toHex().compare("0000000000000000") == 0 );

    bitMaptest.set(3);
    bitMaptest.set(5);  // would be flipped
    bitMaptest.set(14); // would be flipped
    bitMaptest.set(26);
    bitMaptest.set(39);

    bitMaptest.flip(5);
    bitMaptest.flip(14);
    BOOST_CHECK( bitMaptest.toHex().compare("2000004002000000") == 0 );
}