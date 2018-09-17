#include<stdio.h>

struct adjList {
	int node;
	int weight;
};

int main() {
	adjList adj[5];
	int ptr = 0;

	adj[ptr] = adjList{,20};

	printf("%d %d\n",adj[ptr].node, adj[ptr].weight);
}
