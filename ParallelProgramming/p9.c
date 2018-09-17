#include<stdio.h>
#include<omp.h>

int main() {
	double x = omp_get_wtime();
	#pragma omp parallel
	{
		#pragma omp sections
		{
			#pragma omp section
			printf("%d \n",omp_get_thread_num());

			#pragma omp section
			printf("%d \n",omp_get_thread_num());

			#pragma omp section
			printf("%d \n",omp_get_thread_num());

			#pragma omp section
			printf("%d \n",omp_get_thread_num());
		}
	}
	double y = omp_get_wtime();
	printf("%f",y-x);
}
