#include <stdio.h>
#include <assert.h>

//test to check number pair matches color pair
void testNumberToPair(int pairNumber, enum MajorColor expectedMajor, enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

//test to check color pair matches number pair
void testPairToNumber(enum MajorColor major, enum MinorColor minor, int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}

// function to print the color pair - number pair as a reference manual
void display_reference_manual()
{
	ColorPair Pair;
	int numberpair = 1;
	char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
	printf(" PAIRNUMBER \t\t\t\t\t MAJORCOLOR-MINORCOLOR \n");
	while (numberpair <= MAX_COLORPAIR_NAME_CHARS)
	{
		ColorPair Pair = GetColorFromPairNumber(numberpair);
    	ColorPairToString(&Pair, colorPairNames);
		printf(" %d \t\t\t\t\t %s\n ",numberpair,colorPairNames);
		numberpair++;
		
	}
	
}