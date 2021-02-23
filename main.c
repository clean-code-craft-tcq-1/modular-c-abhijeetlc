#include <stdio.h>
#include <assert.h>
#include"test.h"

//enumerate major and minor colors
enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

//structure to store minor and major colors
typedef extern struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair; 

//Major colors for print
const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};

//Calculate number of major colors
int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

//you cannot change the minor color value
const char* MinorColorNames[] = 
{
   "Blue", "Orange", "Green", "Brown", "Slate"
};

//Maximum and minimum number-color pairs
const int MAX_COLORPAIR_NAME_CHARS = 25;
const int MIN_COLORPAIR_NAME_CHARS = 1;

//Minor color number
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

//find the sprintf function, is this printing the reference document
//int sprintf (char *string, const char *form, … );

void ColorPairToString(const ColorPair* colorPair, char* buffer) 
{
   sprintf(buffer, "%s %s", MajorColorNames[colorPair->majorColor], MinorColorNames[colorPair->minorColor]);
}

ColorPair GetColorFromPairNumber(int pairNumber)
{	if (pairNumber > MAX_COLORPAIR_NAME_CHARS || pairNumber < MIN_COLORPAIR_NAME_CHARS) {   //hidden req ?  to ensure invalid number is not entered
		printf(" Come back when sober :D "); //printf comment added on a light note, feedback if not to be done so.
	}
	else {
    		ColorPair colorPair;
    		int zeroBasedPairNumber = pairNumber - 1;
    		colorPair.majorColor = (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    		colorPair.minorColor = (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    		return colorPair;
	}
}
//function to obtain number pair with colorpair as input
int GetPairNumberFromColor(const ColorPair* colorPair) {
    return (colorPair->majorColor * numberOfMinorColors + colorPair->minorColor + 1);
}

int main() 
{
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);
    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
    display_reference_manual(); // print reference manual of number pair - color pair
    return 0;
}

