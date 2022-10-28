#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

class singlyLinkedList {
public:
	singlyLinkedList(); //basic constructor
	bool empty();		//check if list empty or not
	void append(int data);	//add data to the last of the list
	void insertion(int idx, int data);	//insert data to specific index
	void deletion(int idx);				//delete data from specific index
	void print();						//print data from the list
	void min();

private:
	node* head;	//
	node* tail;
	int listSize;
};

void singlyLinkedList::min() {
	node* curNode = head;
	int min = curNode->data;

	if (empty()) {
		cout << "empty" << endl;
		return;
	}
	while (curNode != NULL) {
		//min = curNode->data;
		if (min > curNode->data) min = curNode->data;
		curNode = curNode->next;
	}
	cout << min << endl;
}

singlyLinkedList::singlyLinkedList() {
	head = tail = NULL;
	listSize = 0;
}

bool singlyLinkedList::empty() {
	if (listSize == 0) {
		return true;
	}
	else {
		return false;
	}
}

void singlyLinkedList::append(int data) {
	node* newNode = new node; //create a node as a dynamic allocation
	newNode->data = data;
	newNode->next = NULL;
	if (empty()) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	listSize++;
}

void singlyLinkedList::insertion(int idx, int data) {
	if (idx < 0 || idx > listSize) {
		return;
	}
	else if (idx == listSize) {
		append(data);
	}
	else if (idx == 0) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = head;
		head = newNode;
		listSize++;
	}
	else {
		node* newNode = new node;
		newNode->data = data;
		node* curNode = head;
		for (int i = 1; i < idx; i++) {
			curNode = curNode->next;
		}

		newNode->next = curNode->next;
		curNode->next = newNode;
		listSize++;
	}
}

void singlyLinkedList::deletion(int idx) {
	if (empty() || idx <0 || idx>listSize) {
		cout << -1 << endl;
		return;
	}

	node* curNode = head;
	if (idx == 0) {
		if (listSize == 1) head = tail = NULL;
		else head = head->next;
	}
	
	else {
		node* preNode = head;
		for (int i = 0; i < idx; i++) {
			preNode = curNode;
			curNode = curNode->next;
		}

		preNode->next = curNode->next;
		if (curNode == tail) {
			tail = preNode;
		}
	}
	cout << curNode->data << endl;
	delete curNode;
	listSize--;
}

void singlyLinkedList::print() {
	if (empty()) {
		cout << "empty" << endl;
	}

	node* curNode = head;
	while (curNode != NULL) {
		cout << curNode->data << " ";
		curNode = curNode->next;
	}
	cout << endl;
}

int main() {
	int query, data, idx;
	string cmd;

	cin >> query;

	singlyLinkedList sll;

	while (query > 0) {
		cin >> cmd;
		if (cmd == "Append") {
			cin >> data;
			sll.append(data);
			sll.print();
		}
		else if (cmd == "Print") {
			sll.print();
		}
		else if (cmd == "Delete") {
			cin >> idx;
			sll.deletion(idx);
		}
		else if (cmd == "Insert") {
			cin >> idx >> data;
			sll.insertion(idx, data);
			sll.print();
		}
		else if (cmd == "Min") {
			sll.min();
		}
		query--;
	}
}

/*
20
Append 38
Print
Append 25
Delete 7
Append 19
Print
Delete 0
Print
Insert 1 18
Insert 1 34
Append 6
Insert 4 15
Delete 9
Min
Delete 1
Append 30
Delete 1
Min
Append 16
*/