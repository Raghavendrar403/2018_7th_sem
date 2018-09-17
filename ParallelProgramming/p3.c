#include<omp.h>
#include<stdio.h>

int main() {
	#pragma omp parallel 
	{
		int id = omp_get_thread_num();
		printf("Thread %d\n",id);

		#pragma omp barrier
		printf("This statement is executed after a barrier %d\n",id);
		#pragma omp barrier		

		int i = 0;
		#pragma omp for nowait
		for(int i = 0; i<10; i++) {
			;
		}
		printf("Thread - %d \n", id);
		printf("This statement is  after the for Thread - %d\n",id);
	}
}
