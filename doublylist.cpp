#include <iostream>
#include<vector>
#include<string>
using namespace std;

/*

Please write a doubly linked list of floats in C++.
The implementation should have the following members
LinkedList() (Parameter - less constructor)
LinkedList(vector<float> source)
float operator[](int index)
Append(float value)
Insert(int index, float value)
Remove(Node node);
Clear()
ToString()
*/

class node {
public:
	float data;
	node* next;
	node* prev;
};

void LinkedList(vector<float> source);
void PrintForward(node* head);
// void Append_num_end(float value, node* head, node* tail);

int main(int argc, char** argv)
{
	node* head;
	node* tail;
	node* n;

	vector<float> source = {1.4, 5.4, 6.7, 8.5, 2.3};
	LinkedList(source);
	float num = 3.6;
//	Append_num_end(num, head, tail);

	return 0;
}

void PrintForward(node* head) {
	node* temp = head;

	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void PrintReverse(node* tail) {
	node* temp = tail;

	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}


void LinkedList(vector<float> source) {
	node* head;
	node* tail;
	node* n;

	// determine how many elements we have in the vector
	int len = 0;
	for (int element : source)
		len++;

	// define head node
	n = new node;
	n->data = source[0];
	n->prev = NULL;
	head = n;
	tail = n;
	
	// define tail node	
	n = new node;
	n->data = source[(len - 1)];
	n->prev = tail;
	tail->next = n;
	tail = n;
	tail->next = NULL;

	// define nodes in the middle
	for (int i = 0; i <= (len); ++i) {
		if (i == 0) { continue; }
		if (i == len) { continue; }
		
		n = new node;
		n->data = source[i];
		n->prev = tail;
		tail->next = n;
		tail = n;
	}
}
/*
void Append_num_end(float value, node* head, node* tail) {
	node* n;
	node* tail = tail;
	node* head = head;

	n = new node;
	n->data = value;
	n->prev = tail;
	tail->next = n;
	tail = n;
	tail->next = NULL;
}
*/