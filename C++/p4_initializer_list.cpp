#include"vector.h"

int main() {
	vector v1 = {1,2,3,4,5,6,7};

	for(int i = 0; i<v1.size();i++) {
		cout << v1.get(i) << " " ;
	}
	cout << endl;
}
