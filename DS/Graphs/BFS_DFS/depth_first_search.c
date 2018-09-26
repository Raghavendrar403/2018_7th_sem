#include "new_head.h"
int time = 0;
graph_node *vertex;
extern void print_all(graph_node *, int);

void dfs_visit(int index, graph *adj_list, int n) {
	time = time + 1;
	vertex[index].d = time;
	vertex[index].color = GRAY;
	
	graph **cp = adj_list[index].connected_to;
	int i = 0;	
	for(i = 0; i<n; i++) {
		if((cp[i] != NULL) && (vertex[i].color == WHITE)) {
			vertex[i].parent_node = &vertex[index];
			dfs_visit(i, adj_list, n);
		}
	}
	vertex[index].color = BLACK;
	time = time + 1;
	vertex[index].f = time;
	print_all(vertex, n);
}

void dfs(graph *adj_list, int n) {
	int i = 0;
	vertex = (graph_node *) malloc(sizeof(graph_node)*n);
	for(i = 0; i<n; i++) {
		vertex[i].node_num = adj_list[i].node_num;
		vertex[i].color = WHITE;
		vertex[i].parent_node = NULL;
	}
	time = 0;
	for(i = 0; i<n; i++) {
		if(vertex[i].color == WHITE) {
			dfs_visit(i,adj_list,n);		
		}
	}
}
