#include<iostream>
using namespace std;
class vector {
		long unsigned int sz;
		double *ele;
	public:
		vector(long unsigned int s) 
			: sz{s},
			  ele{new double[s]} {
			  	for(int i = 0; i<s; i++)
					ele[i] = 0;
			  }

		vector& operator=(const vector& a);

		vector(initializer_list<double> lst)
			: sz{lst.size()},
			ele{new double[sz]} {
				copy(lst.begin(), lst.end(), ele);
			}

		vector(vector& v)
			: sz{v.size()},
			ele{new double[sz]} {
				for(int i = 0; i<sz; i++) {
					ele[i] =  v.get(i);
				}
			}

		long unsigned int size() const {return sz;}
	
		~vector() {
			delete[] ele;
		}

		double get(int n) {
			return ele[n];
		}

		void set(int n, double v) {
			ele[n] = v;
		}


};

vector&	vector::operator=(const vector& a)  {
	double *p = new double[a.sz];
	copy(a.ele, a.ele+sz, ele);
	delete[] ele;
	ele = p;
	sz = a.sz;
	return *this;
}
