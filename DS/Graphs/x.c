#include "head.h"
int front = 0;
int rear = 0;
int queue[20];
int visited[6] = {0,0,0,0,0,0};

int distance[6] = {0,0,0,0,0,0};
struct Node graph[6];

void push(int s) {
	if(rear < 20) {
		queue[rear] = s;
		rear++;
	}

	else {
		printf("The queue is full\n");
		exit(0);
	}
}

int pop() {
	return queue[front++];
}

int all_visited() {
	int i = 0;
	for(i = 0; i<6; i++) {
		if(visited[i] == 0)
			return 0;
	}
	return 1;
}

int queue_empty() {
	if(front == rear) 
		return 1;
	else
		return 0;
}

void bfs() {
	int s = 0;
	push(s);

	distance[s] = 0;

	while(!queue_empty()) {
		if(all_visited()) {
			break;
		}

		int elem = pop();	
			
		if(!visited[elem]) {
			visited[elem] = 1;
			printf("%d \n",elem+1);
			int l, r;
			if(graph[elem].leftNode != NULL) {
				l = graph[elem].leftNode->node_num-1;
				push(l);
				if(distance[l] == 0 && !visited[l]) {
					distance[l] = distance[elem]+1;	
				}
			}

			if(graph[elem].rightNode != NULL) {
				r = graph[elem].rightNode->node_num-1;
				push(r);
				if(distance[r] == 0 && !visited[r]) {
					distance[r] = distance[elem]+1;	
				}
			}

			//printf("%d %d %d\n",elem,l,r);
		}
	}

	int i = 0;
	printf("\n\n");
	for(i = 0; i<6; i++) {
		printf("%d: %d\n",i+1,distance[i]);	
	}
}

int main() {

	graph[0] = {1,&graph[3],&graph[1]};
	graph[1] = {2,&graph[4],&graph[2]};
	graph[2] = {3,&graph[1],&graph[6]};
	graph[3] = {4,&graph[0],NULL};
	graph[4] = {5,&graph[1],&graph[5]};
	graph[5] = {6,&graph[2],&graph[4]};

	bfs();	
}
