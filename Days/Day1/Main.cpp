#include "Day1.h"
#include "../Common.h"
#include "../Timer.h"

int main()
{
	Timer t;
	t.start();
	Day1 day1(FILE_PATH "puzzleInput.txt");
	day1.Question1();
	day1.Question2();
	t.stop();
	return 0;
}