
#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

/* ^^  include guards */

/* Prototypes for the functions */

void testNumberToPair(int pairNumber, enum MajorColor expectedMajor, enum MinorColor expectedMinor);
void testPairToNumber(enum MajorColor major, enum MinorColor minor, int expectedPairNumber);
void display_reference_manual();
