#include<iostream>
using namespace std;
#define INF -99999999
int max(int a, int b) {
	if(a<b)
		return b;
	else
		return a;
}
int prices[10] =  {1,5,8,9,10,17,17,20,24,30};

int cut_rod(int p[], int n) {
	if(n == 0)
		return 0;
	
	int	q = INF;
	for(int i = 1; i<=n; i++) {
		q = max(q, p[i-1]+cut_rod(p,n-i));
	}
	return q;
}

int main() {
	int size = 10;
	int n = 0;
	cin>> n;
	int s = cut_rod(prices,n);
	cout << endl << s << endl;
}
