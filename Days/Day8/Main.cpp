#include "Day8.h"
#include "../Common.h"
#include "../Timer.h"

int main()
{
	Timer t;
	t.start();
	Day8 day8(FILE_PATH "Day8/puzzleInput.txt");
	day8.Question1();
	day8.Question2();
	t.stop();
	return 0;
}