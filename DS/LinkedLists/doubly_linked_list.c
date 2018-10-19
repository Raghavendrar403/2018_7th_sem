/* Implementation of basic operations on a Doubly Linked List */

#include<stdio.h>
#include<stdlib.h>

typedef struct Node node;
struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
};

node *new_node() {
	static int i = 0;
	node *nn = (node *) malloc(sizeof(node));
	nn->data = i;
	nn->next = NULL;
	nn->prev = NULL;
	i = i+1;
	return nn;
}

void print_node(node *n) {
	printf("(%d)\n",n->data);	
}

void print_ll(node *head) {
	if(head->next == NULL) {
		printf("The Linked list is empty\n");
	}

	else {
		node *start = head->next;
		printf("NULL<-->");
		while(start != NULL) {
			printf("(%d)<-->",start->data);
			start = start->next;
		}
		printf("NULL\n");
	}
}

node *get_lastNode(node *head) {
	if(head->next == NULL)
		return NULL;

	else {
		node *start = head;
		while(start->next != NULL)
			start = start->next;

		return start;
	}
}

void insert_last(node *head, node *n) {
	node *start;
	if(head->next != NULL) 
		start = get_lastNode(head);

	else
		start = head;		

	start->next = n;
	n->prev = start;
	n->next = NULL;
}

void insert_first(node *head, node *n) {
	node *start = head;
	if(start->next == NULL) {
		start->next = n;
		n->prev = NULL;
		n->next = NULL;
	}

	else {
		node *temp = start->next;
		start->next = n;
		n->next = temp;
		n->prev = NULL;
		temp->prev = n;
	}
}

void free_node(node *x) {
	free(x);
	x = NULL;
}

void delete_first(node *head) {
	if(head->next == NULL) {
		printf("The Linked List is empty\n");
	}

	/* if there is only one element in the LL */
	else if(head->next == get_lastNode(head)) {
		node *temp = head->next;
		head->next = NULL;
		free_node(temp);
	}

	else {
		node *x = head->next;
		head->next = x->next;
		x->next->prev = NULL;
		free_node(x);
	}
}

void delete_last(node *head) {
	if(head->next == NULL) {
		printf("The Linked List is empty\n");	
		return ;
	}
	
	/* if there is only one element in the LL */
	node *last = get_lastNode(head);
	if(head->next == last) {
		head->next = NULL;
		free_node(last);
	}
		
	else {
		node *p = last->prev;
		p->next = NULL;
		free_node(last);
	}
}

int main() {
	node *head = new_node();	
	node *n1 = new_node();
	node *n2 = new_node();
	node *n3 = new_node();
	node *n4 = new_node();
	node *n5 = new_node();
	node *n6 = new_node();
	insert_first(head, n1);
	insert_first(head, n2);
	insert_first(head, n3);
	insert_first(head, n4);
	insert_first(head, n5);
	insert_first(head, n6);
	print_ll(head);
}
