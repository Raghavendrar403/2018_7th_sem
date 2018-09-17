#include"head.h"

int visited[5];

void dfs_algo(struct Node *node) {
	if(!visited[node->node_num-1]) {
		visited[node->node_num-1] = 1;
		printf("%d \n",node->node_num);
		if(node->leftNode != NULL)
			dfs_algo(node->leftNode);
		if(node->rightNode != NULL)
			dfs_algo(node->rightNode);
	}
}

int main() {
	Node graph[5];	
	graph[0] = {1,&graph[3],&graph[1]};
	graph[1] = {2,&graph[4],&graph[2]};
	graph[2] = {3,&graph[1],&graph[4]};
	graph[3] = {4,NULL,NULL};
	graph[4] = {5,&graph[2],&graph[1]};

	dfs_algo(&graph[0]);
}
