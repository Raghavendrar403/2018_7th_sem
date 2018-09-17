#include<stdio.h>
#include<omp.h>

int main() {
	 omp_set_num_threads(3);
	 #pragma omp parallel
	 {
		int id = omp_get_thread_num();
		printf("Hello World %d\n",id);
	 }
}
