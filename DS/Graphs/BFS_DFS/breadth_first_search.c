#include "new_head.h"


char *s[5] = {"WHITE","GRAY","BLACK"};

graph_node **queue;
int front, back;

void enqueue(graph_node *s) {
	queue[back++] = s;	
}


graph_node* dequeue() {
	return queue[front++];
}

void print_all(graph_node v[], int n) {
	int i = 0;
	for(i = 0; i<n; i++) {
		printf("%d: %s\n",v[i].node_num,s[(v[i].color)]);	
	}
	printf("----------------------------------------------------------------\n");
}

void bfs(graph *adj_list, int n) {
	graph_node vertex[n];	
	int i = 0;
	/* Initialization step */
	for(i = 0; i<n; i++) {
		vertex[i].node_num = adj_list[i].node_num;
		vertex[i].color = WHITE;
		vertex[i].d = INF;
		vertex[i].parent_node = NULL;
	}
	queue = (graph_node **)malloc(sizeof(graph_node)*n);
	front = 0;
	back = 0;

	graph_node *s = &vertex[0];
	s->d = 0;
	s->color = GRAY;
	s->parent_node = NULL;
	enqueue(s);
	graph_node *u, *v;
	while(front != back) {
		print_all(vertex,n);
		u = dequeue();
		graph **cp = adj_list[u->node_num].connected_to;
		for(i = 0; i<n; i++) {
			if(cp[i] != NULL) {
				int node_index = cp[i]->node_num;
				v = &vertex[node_index];
				if(v->color == WHITE) {
					v->parent_node = u;
					v->d = u->d+1;
					v->color = GRAY;
					enqueue(v);
				}
			}
		}
		u->color = BLACK;
	}

	free(queue);
	queue = NULL;
}
