#include<stdio.h>
#define INF 9999999

int m[7][7];
int s[7][7];

void matrix_chain_mul(int p[]) {
	int n = 7;
	int i = 0, j = 0, l = 0, k = 0, q = 0;
	for(i = 0; i<=n; i++) {
		m[i][i] = 0;
	}

	for(l = 1; l<=n; l++) {
		printf("for(l=%d,l<=%d;l++)\n",l,n);
		for(i = 1; i<=(n-l); i++) {
			printf("\tfor(i=%d;i<=(%d-%d)=%d;i++)\n",i,n,l,(n-l));
			j = i+l-1;
			printf("\t\tj = %d+%d-1=%d\n",i,l,j);
			if(i < j)
				m[i][j] = INF;
			for(k = i; k<j; k++) {
				printf("\t\t\tfor(k = %d; k<%d; %d++)\n",i,j,k);
				q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				printf("\t\t\t\t(q=(m[%d][%d]=%d)+(m[%d][%d]=%d)+%d*%d*%d) = %d\n",i,k,m[i][k],k+1,j,m[k+1][j],p[i-1],p[k],p[j],q);
				if(q < m[i][j] && i<j) {
					printf("\t\t\t\tif %d < m[%d][%d]=%d\n",q,i,j,m[i][j]);
					m[i][j] = q;
					printf("\t\t\t\tm[%d][%d] = %d\n",i,j,q);
					s[i][j] = k;
					printf("\t\t\t\ts[%d][%d] = %d\n",i,j,k);
				}
			}
		}
	}
}

int main() {
	int p[7] = {30,35,15,5,10,20,25};
	matrix_chain_mul(p);

	printf("===============================================================================================================\n");
	int i = 0, j = 0;
	for(i = 0; i<7; i++) {
		for(j = 0; j<7; j++) {
			if(i < j && m[i][j] != 0)
				printf("m[%d][%d]=%d\t\ts[%d][%d]=%d\n",i,j,m[i][j],i,j,s[i][j]);
		}
	}
}
