/* Implementation of Basic Functions in a Singly Linked List */

#include<stdio.h>
#include<stdlib.h> /* for malloc and free functions */
#include<time.h>	/* used as seed to srand function */
typedef struct Node node;
struct Node {
	int value;
	struct Node *next;
};

/* prints the value of a node */
void print_node(node *n) {
	printf("Value: %d\n",n->value);
}

/* prints the entire linked list */
void print_ll(node *head) {
	node *start = head;

	if(start->next == NULL) {
		printf("The Linked List is empty\n");
	}

	else {
		do {
			start = start->next;
			printf("(%d)->",start->value);	
		} while(start->next != NULL);
		printf("NULL");

		printf("\n");
	}
}

/* Append a node to the LL given the head of the LL */
void append(node *head, node *new_node) {
	node *start = head;
	while(start->next != NULL)
		start = start->next;

	start->next = new_node;
	new_node->next = NULL;
}

/* Give me a new node with a random value */
node *new_node() {
	static int n = 0;
	node *nn = (node *)malloc(sizeof(node));	
	nn->value = n;
	nn->next = NULL;
	n = n+1;
	return nn;
}

/* Insert the node after a particular node with a given node */
int insert_node(node *head, node *n, int val) {
	node *start = head->next;
	while(start != NULL) {
		if(start->value == val)	 {
			n->next = start->next;
			start->next = n;
			return 1;
		}
		start = start->next;
	}
	return 0;
}

/* Free the memory location of a node */
void free_node(node *x) {
	free(x);
	x = NULL;
}

/* Free the entire LL */
void free_ll(node *head) {
	while(head != NULL)	 {
		node *temp = head;
		head = head->next;
		free_node(temp);

	}
}

/* Delete a node given its value */
int delete_node(node *head, int val) {
	node *trail = head;
	node *temp = head->next;

	while(temp != NULL) {
		if(temp->value == val) {
			trail->next = temp->next;
			free_node(temp);
			return 1;
		}
		temp = temp->next;
		trail = trail->next;
	}
	return 0;
}

/* Reverse the Linked List */
void reverse(node *head) {
	node *n = head->next;
	node *p = head;
	/* The first element in the LL */
	p = n;
	n = n->next;
	p->next = NULL;
	/* Reversing all elements after the first element */
	while(n != NULL) {
		node *temp = n->next;		
		n->next = p;
		p = n;
		n = temp;
	}
	head->next = p;
}

int main() {
	node *head = new_node();
	node *n1 = new_node();
	node *n2 = new_node();
	node *n3 = new_node();
	node *n4 = new_node();
	node *n5 = new_node();
	node *n6 = new_node();
	append(head,n1);
	append(head,n2);
	append(head,n3);
	append(head,n4);
	append(head,n5);
	append(head,n6);
	print_ll(head);

	reverse(head);
	print_ll(head);

	free_ll(head);
}
