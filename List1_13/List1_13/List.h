#pragma once
#include <iostream>

struct Node {
	int data;
	Node* next;
};
typedef Node* TList;
void init(TList &head);			
void addToHead(TList& head, int elem);
void addToEnd(TList& head, int elem);
void addAfterNode(TList pNode, int elem);
void deleteFromHead(TList& head);
void deleteAfterNode(TList pNode);
void deleteFromEnd(TList head);
bool isEmpty(TList head);
void clear(TList& head);
void printList(TList head);
