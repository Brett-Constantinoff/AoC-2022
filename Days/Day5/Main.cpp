#include "Day5.h"
#include "../Common.h"
#include "../Timer.h"

int main()
{
	Timer t;
	t.start();
	Day5 day5(FILE_PATH "Day5/testInput.txt");
	day5.Question1();
	day5.Question2();
	t.stop();
	return 0;
}