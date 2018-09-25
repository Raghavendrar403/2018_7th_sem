#include<stdio.h>

struct animal {
	const char* lion;
	const char* tiger;
};

int main() {
	struct animal const ani =  {
		.lion = "LION",
		.tiger = "TIGER",
	};

	printf("%s %s \n",ani.lion,ani.tiger);
}

