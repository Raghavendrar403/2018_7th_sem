#include<iostream>

using namespace std;

int main() {
	int y = 10;
	int& r = y;
	r = 20;
	cout << y <<  endl;
}
