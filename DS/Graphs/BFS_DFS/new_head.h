#include<stdio.h>
#include<stdlib.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF 99999999

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
	int f;
	int color;
} ;
