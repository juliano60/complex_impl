#include "catch.hpp"
#include "Complex.hpp"

using namespace tutorial;

TEST_CASE ("canAdd") {
    Complex x{2,3};
    Complex y{4,5};

    auto r1 = x+y;
    REQUIRE(r1.real() == Approx(6));
    REQUIRE(r1.imag() == Approx(8));

    auto r2 = x+2;
    REQUIRE(r2.real() == Approx(4));
    REQUIRE(r2.imag() == Approx(3));

    auto r3 = 2+x;
    REQUIRE(r3.real() == Approx(4));
    REQUIRE(r3.imag() == Approx(3));
}

TEST_CASE ("testEquality") {
    Complex x{2,3};
    Complex y{2,3};
    Complex z{6};

    REQUIRE(x==y);
    REQUIRE(x!=z);
    REQUIRE(6==z);
}

TEST_CASE ("testUserDefinedLiteral") {
    Complex a{2.4_i};

    REQUIRE(a.imag() == Approx(2.4));
}

TEST_CASE ("testMultiplication") {
    Complex a{3,4};
    Complex b{2,5};

    Complex z = a*b;

    REQUIRE(z.real() == Approx(-14));
    REQUIRE(z.imag() == Approx(23));
}

TEST_CASE( "testDivision") {
    Complex a{4,-5};
    Complex b{1,2};

    Complex z = a/b;

    REQUIRE(z.real() == Approx(-1.2));
    REQUIRE(z.imag() == Approx(-2.6));
}
