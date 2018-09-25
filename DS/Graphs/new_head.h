#include<stdio.h>
#include<stdlib.h>
typedef struct Graph graph;
struct Graph {
	int node_num;
	graph **connected_to;
};
