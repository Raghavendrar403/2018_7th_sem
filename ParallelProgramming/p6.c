#include<stdio.h>
#include<omp.h>

int main() {
	omp_lock_t lock;
	omp_init_lock(&lock);
	#pragma omp parallel
	{
		int id = omp_get_thread_num();
		omp_set_lock(&lock);
		printf("This is inside a lock so only one thread %d can execute it\n",id);
		omp_unset_lock(&lock);
	}
	omp_destroy_lock(&lock);
}
