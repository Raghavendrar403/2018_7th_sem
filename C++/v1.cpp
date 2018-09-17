#include "vector.h"

vector *f(int s) {
	vector *p = new vector(s);
	
	return p;
}

int main() {
	vector *q = f(5);	
	cout << q->size() << endl;
	for(int i = 0; i<q->size();i++) {
		q->set(i,3.0*i);
		cout << i << ": " << q->get(i) << endl;
	}

	// since you are deleting a single instance of 
	// an entire class, you dont use delete[] q
	delete q;
}
