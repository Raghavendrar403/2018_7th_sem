#include<iostream>
using namespace std;

long long int max(long long int a, long long int b) {
	if(a<b)
		return b;
	
	else
		return a;
}

long long int bottom_up(int p[], int n) {
	long long int r[n+1];
	for(int i = 0; i<=n; i++) {
		r[i] = -99999;
	}
	r[0] = 0;

	for(int j = 1; j<=n; j++) {
		long long int q = -99999;
		for(int i = 1; i<=j; i++) {
			q = max(q, p[i-1]+r[j-i]);
		}
		r[j] = q;
	}
	return r[n];
}

int main() {
	int prices[10] = {1,5,8,9,10,17,17,20,24,30};
	int n = 0;
	cin >> n;
	long long int s = bottom_up(prices, n);
	cout << s << endl;
}
