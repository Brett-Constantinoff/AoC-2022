#include "Day6.h"
#include "../Common.h"
#include "../Timer.h"

int main()
{
	Timer t;
	t.start();
	Day6 day6(FILE_PATH "Day6/puzzleInput.txt");
	day6.Question1();
	t.stop();
	day6.Question2();
	//t.stop();
	return 0;
}