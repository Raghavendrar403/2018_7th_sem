#include "vector.h"

int main() {
	vector v1 = {1,2,3,4,5};
	vector v2 = v1;

	v2.set(3,200);

	for(int i = 0; i<v2.size();i++) {
		cout << v1.get(i) << " " << v2.get(i) << endl;
	}

	cout << endl;
}
