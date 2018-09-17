#include<stdio.h>
#include<omp.h>

int main() {
	#pragma omp parallel
	 {
		printf("This is executed by thread %d\n",omp_get_thread_num());	
		#pragma omp master
		 {
		 	printf("This statement is executed by the master thread %d\n",omp_get_thread_num());
			
		 }
		 #pragma omp single
		 {
		 	printf("This statement is executed by a single thread %d\n",omp_get_thread_num());
		}

	 }
}
