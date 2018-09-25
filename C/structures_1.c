#include<stdio.h>
#include<stdlib.h>

struct node {
	int x;
	struct node** X;
};

int main() {
	struct node *Node;
	Node = (struct node*) calloc (10, sizeof(struct node));
	
	Node[0].X = (struct node **) malloc(sizeof(struct node)*10);
	Node[0].x = 0;
	Node[0].X[0] = &Node[1];
	Node[0].X[1] = &Node[2];

	int i = 0;
	for(i = 0; i<10; i++) {
		Node[i].x = i;
		Node[0].X[i] = &Node[i];
	}
	
	struct node** cp = Node[0].X;
	for(i = 0; i<10; i++) {
		printf("%d ",cp[i]->x);
	}
}
