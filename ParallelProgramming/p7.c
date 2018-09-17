#include<stdio.h>
#include<omp.h>

int main() {
	int id = 9999;
	int i = 0;
	#pragma omp parallel for firstprivate(id) 
	for(i = 0; i<omp_get_num_threads(); i++)
	{
		printf("Inherted from master thread: %d executed by: %d\n",id,omp_get_thread_num());
		id = omp_get_thread_num();	
	}

	printf("Final Value: %d \n",id);
}
