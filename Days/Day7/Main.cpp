#include "Day7.h"
#include "../Common.h"
#include "../Timer.h"

int main()
{
	Timer t;
	t.start();
	Day7 day7(FILE_PATH "Day7/puzzleInput.txt");
	day7.Question1();
	day7.Question2();
	t.stop();
	return 0;
}