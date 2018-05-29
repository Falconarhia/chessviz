#include <board.h>
#include <ctest.h>


CTEST(pawn, move)
{
    // Given
    struct Turn z;
    const int a = parce(&z, "1. a1-b1 d2-d3");

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, a);
}

CTEST(pawn, checkmate)
{
    // Given
    struct Turn z;
    const int a = parce(&z, "1. a1-b1#");

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, a);
}

CTEST(pawn, start_x)
{
    // Given
    struct Turn z;
    const int a = parce(&z, "1. z1-b1#");

    // Then
    const int expected = 4;
    ASSERT_EQUAL(expected, a);
}

CTEST(pawn, start_y)
{
    // Given
    struct Turn z;
    const int a = parce(&z, "1. a11-b1#");

    // Then
    const int expected = 6;
    ASSERT_EQUAL(expected, a);
}

CTEST(pawn, stop_x)
{
    // Given
    struct Turn z;
    const int a = parce(&z, "1. a1-x1#");

    // Then
    const int expected = 7;
    ASSERT_EQUAL(expected, a);
}

CTEST(pawn, stop_y)
{
    // Given
    struct Turn z;
    const int a = parce(&z, "1. a1-b15#");

    // Then
    const int expected = 9;
    ASSERT_EQUAL(expected, a);
}

CTEST(pawn, pwbit)
{
    // Given
    struct Turn z;
    const int a = parce(&z, "1. a1xb1#");

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, a);
}

CTEST(pawn, action)
{
    // Given
    struct Turn z;
    const int a = parce(&z, "1. a1+b1#");

    // Then
    const int expected = 7;
    ASSERT_EQUAL(expected, a);
}

CTEST(king, move)
{
    // Given
    struct Turn z;
    const int a = parce(&z, "1. Ka1-b1 Kd2-d3");

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, a);
}

CTEST(king, checkmate)
{
    // Given
    struct Turn z;
    const int a = parce(&z, "1. Ka1-b1#");

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, a);
}

CTEST(king, start_x)
{
    // Given
    struct Turn z;
    const int a = parce(&z, "1. Kz1-b1#");

    // Then
    const int expected = 5;
    ASSERT_EQUAL(expected, a);
}

CTEST(king, start_y)
{
    // Given
    struct Turn z;
    const int a = parce(&z, "1. Ka11-b1#");

    // Then
    const int expected = 7;
    ASSERT_EQUAL(expected, a);
}

CTEST(king, stop_x)
{
    // Given
    struct Turn z;
    const int a = parce(&z, "1. Ka1-x1#");

    // Then
    const int expected = 8;
    ASSERT_EQUAL(expected, a);
}

CTEST(king, stop_y)
{
    // Given
    struct Turn z;
    const int a = parce(&z, "1. Ka1-b15#");

    // Then
    const int expected = 10;
    ASSERT_EQUAL(expected, a);
}

CTEST(king, pwbit)
{
    // Given
    struct Turn z;
    const int a = parce(&z, "1. Ka1xb1#");

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, a);
}

CTEST(king, action)
{
    // Given
    struct Turn z;
    const int a = parce(&z, "1. Ka1+b1#");

    // Then
    const int expected = 8;
    ASSERT_EQUAL(expected, a);
}



