#include "new_head.h"

extern void bfs(graph *, int);

void free_up(struct Graph *adj_list,int n) {
	int i = 0; 
	for(i = 0; i<n; i++) {
		free(adj_list[i].connected_to);
		adj_list[i].connected_to = NULL;
	}

	free(adj_list);
	adj_list = NULL;
}

int main() {
	int n; 
	printf("Enter the number of nodes: ");
	scanf("%d",&n);

	graph *adj_list = (graph *) malloc(sizeof(graph)*n);

	int i = 0;
	int j = 0;
	int is_connected = 0;
	for(i = 0; i<n; i++) {
		adj_list[i].node_num = i;
		adj_list[i].connected_to = (graph **)malloc(sizeof(graph)*n);
		printf("Enter the nodes connected to %d: ",i);
		for(j = 0; j<n; j++) {
			scanf("%d",&is_connected);	
			if(is_connected == 1)  {
				printf("%d is connected_to %d\n",i,j);
				adj_list[i].connected_to[j] = &adj_list[j];
			}
			else {
				adj_list[i].connected_to[j] = NULL;
			}
		}
	}

	for(i = 0; i<n; i++) {
		printf("%d: ",adj_list[i].node_num);	
		for(j = 0; j<n; j++) {
			if(adj_list[i].connected_to[j] != NULL) {
				printf("%d ",adj_list[i].connected_to[j]->node_num);
			}
		}
		printf("\n");
	}
	printf("-----------------------------------------------------------------\n");
	
	bfs(adj_list,n);
	free_up(adj_list,n);
}
