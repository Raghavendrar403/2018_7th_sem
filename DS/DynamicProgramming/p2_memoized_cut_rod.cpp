#include<iostream>
using namespace std;
long int prices[10] = {1,5,8,9,10,17,17,20,24,30};
#define INF -999999
long int memoized_cut_rod_aux(long int *, long int , long int *);

long int max(int a, int b) {
	if(a<b)
		return b;
	else 
		return a;
}

long int memoized_cut_rod(long int p[],long int n) {
	long int r[n];
	for(long int i = 0; i<=n; i++) {
		r[i] = INF;
	}
	return memoized_cut_rod_aux(p,n,r);
}

long int memoized_cut_rod_aux(long int p[], long int n, long int r[]) {
	if(r[n] >= 0)	 {
		//cout << n << ":" << r[n] << endl;
		return r[n];
	}
	long int q;
	if(n == 0) {
		q = 0;	
	}

	else {
		q = INF;
		for(long int i = 1; i<=n; i++)
			q = max(q, p[i-1] + memoized_cut_rod_aux(p, n-i, r));
	}
	r[n] = q;
	if(n == 13)
		cout << q << endl;
	return q;
}

int main() {
	long int n = 0;
	cin >> n;
	long int cost = memoized_cut_rod(prices,n);
	cout << cost << endl;
}
