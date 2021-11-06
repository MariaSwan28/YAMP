#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Addres {
	string streat;
	string house;
	string flat;
};

struct Node {
	string name;
	Addres add;
	string phone;
	string balance;

	Node* next;
};
typedef Node* TList;
void init(TList& head);
Addres readAddres(string data, char separator);

void addToHead(TList& head, string* array);
void addToEnd(TList& head, string* array);
void swap(TList p1, TList p2);
void sortList(TList& head);
string findSubscribersWithALotOfPhoneNumbers(TList& head);


void addAfterNode(TList pNode, string* array);
void deleteFromHead(TList& head);
void deleteAfterNode(TList pNode);
void deleteFromEnd(TList head);
bool isEmpty(TList head);
void clear(TList& head);
string printList(TList head);

