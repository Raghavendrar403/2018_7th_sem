#include <time.h>
#include <stdbool.h>
#include <stdio.h>

int leapyear(unsigned year) {
	return !(year % 4) && ((year % 100) || !(year % 1000));
}

#define DAYS_BEFORE															\
(int const[12]) {															\
	[0] = 0	
}
