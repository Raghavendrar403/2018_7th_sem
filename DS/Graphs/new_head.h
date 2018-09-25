#include<stdio.h>
#include<stdlib.h>

typedef struct Graph graph;
struct Graph {
	int node_num;
	graph **connected_to;
};

typedef struct gp graph_node;
struct gp{
	int node_num;
	graph_node *parent_node;
	int d;
	int color;
} ;
