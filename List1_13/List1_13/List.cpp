#include <iostream>
#include <string>
#include "List.h"

using namespace std;

void init(TList& head) {
	head = nullptr;
}
void addToHead(TList &head, int elem) {
	TList p = new Node;
	p->data = elem;
	p->next = head;
	head = p;
}
void addToEnd(TList& head, int elem) {
	TList p = head;
	if (p == nullptr) {
		addToHead(head, elem);
	}

	else {
		while ((p->next) != nullptr) {
			p = p->next;
		}

		addAfterNode(p, elem);
	}
}

void addAfterNode(TList pNode, int elem) {
	TList p = new Node;
	p->data = elem;
	p->next = pNode->next;
	pNode->next = p;
}
void deleteFromHead(TList& head) {
	TList p = head;
	head = head->next;
	p->next = nullptr;
	delete p;
	p = nullptr;
}
void deleteAfterNode(TList pNode) {
	TList p = pNode->next;
	pNode->next = p->next;
	p->next = nullptr;
	delete p;
	p = nullptr;
}
void deleteFromEnd(TList head) {
	TList p = head;
	if ((p->next) == nullptr) {
		clear(head);
		return;
	}
	while ((p->next->next) != nullptr) {
		p = p->next;
	}
	delete p->next;
	p->next = nullptr;
}
bool isEmpty(TList head){
	return head == nullptr;
}
void clear(TList& head) {
	while (!isEmpty(head)) deleteFromHead(head);
}
void printList(TList head) {
	TList p = head;
	while (p != nullptr) {
		cout << p->data << ' ';
		p = p->next;
	}
}
