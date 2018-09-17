#include<iostream>
using namespace std;
int main() {
	void *p;

	int *pi = static_cast<int*>(p);
	*pi = 20;
	int *pj = static_cast<int *>(p);

	cout << *pi ;
}
