#include<stdio.h>

int check_odd(int a) {
	return !(a&&1);	
}

int main() {
	int prevEven = 0, preOdd = 0,currEven = 0, currOdd = 0;
	
	int x, y, z;
	scanf("%d %d %d",&x, &y, &z);

	int m = 0;	
	int counter = 1;
	while(m != 1) {
		if(currOdd == z || currEven == z) {
			m = 1;
			printf("%d\n",counter);
		}

		else if((currOdd > z) && (currEven > z)) {
			m = 1;
			printf("-1\n");
		}

		else {
			currOdd = prevEven + x;
			currEven = currOdd + y;
			prevEven = currEven;
			counter += 2;
		}
			
	}
}
