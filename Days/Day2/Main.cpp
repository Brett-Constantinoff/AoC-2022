#include "Day2.h"
#include "../Common.h"
#include "../Timer.h"

int main()
{
	Timer t;
	t.start();
	Day2 day2(FILE_PATH "Day2/puzzleInput.txt");
	day2.Question1();
	day2.Question2();
	t.stop();
	return 0;
}