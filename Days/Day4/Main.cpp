#include "Day4.h"
#include "../Common.h"
#include "../Timer.h"

int main()
{
	Timer t;
	t.start();
	Day4 day4(FILE_PATH "Day4/puzzleInput.txt");
	day4.Question1();
	day4.Question2();
	t.stop();
	return 0;
}