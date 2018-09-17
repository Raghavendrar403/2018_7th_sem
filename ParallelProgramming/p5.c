#include<stdio.h>
#include<omp.h>

int main() {
	#pragma omp parallel
	{
		printf("This statement is executed in parallel %d\n",omp_get_thread_num());
		#pragma ordered
		{	
			printf("These statements are executed in sequential order %d\n",omp_get_thread_num());
			printf("%d\n",omp_get_thread_num());
			printf("%d\n",omp_get_thread_num());
			printf("%d\n",omp_get_thread_num());
			printf("%d\n",omp_get_thread_num());
		}
	}
}
