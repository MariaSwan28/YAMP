#include <iostream>
#include <string>
#include "List.h"

using namespace std;

char* createAlphabet() {
	char* alphabet = new char[58 * 2];
	int index = 0;
	for (char i = 'a'; i <= 'z'; i++) {
		alphabet[index] = i;
		index++;
	}
	for (char i = 'A'; i <= 'Z'; i++) {
		alphabet[index] = i;
		index++;
	}
	for (char i = 'à'; i <= 'ÿ'; i++) {
		alphabet[index] = i;
		index++;
	}
	for (char i = 'À'; i <= 'ß'; i++) {
		alphabet[index] = i;
		index++;
	}
	return alphabet;
}

void init(TList& head) {
	head = nullptr;
}
Addres readAddres(string data, char separator) {
	Addres add;
	int i = 0,j=0, n = data.size();
	
	while (i < n) {
		string elem="";
		while (data[i] != separator) {
			elem += data[i];
			i++;
			if (i == n) break;
		}
		i++;
		//cout << elem << endl;
		if (j == 0) add.streat=elem;
		if (j == 1) add.house = elem;
		if (j == 2) add.flat = elem;
		j++;
	}
	return add;
}

void addToHead(TList& head, string* array) {
	TList p = new Node;
	p->name = array[0];
	p->add = readAddres(array[1],' ');
	p->phone = array[2];
	p->balance = array[3];
	p->next = head;
	head = p;
}
void addToEnd(TList& head, string* array) {
	TList p = head;
	if (p == nullptr) {
		addToHead(head, array);
	}

	else {
		while ((p->next) != nullptr) {
			p = p->next;
		}

		addAfterNode(p, array);
	}
}

int findIndex(char findChar, char* alphabet) {
	int k = -1;
	for (int i = 0; i < 58*2; i++) {
		if (findChar == (alphabet[i])) k = i;
	}
	return k;
}
void swap(TList p1, TList p2) {
	string x1 = p1->name, x21=p1->add.streat, x22=p1->add.house, x23=p1->add.flat;
	string x3 = p1->phone, x4 = p1->balance;
	p1->name = p2->name; p1->add.streat = p2->add.streat;
	p1->add.house= p2->add.house; p1->add.flat = p2->add.flat;
	p1->phone = p2->phone; p1->balance = p2->balance;

	p2->name = x1; p2->add.streat = x21;
	p2->add.house = x22; p2->add.flat = x23;
	p2->phone = x3; p2->balance = x4;
}

void sortList(TList& head) {
	char* alphabet = createAlphabet();
	TList p = head;
	TList maxptr = head;
	while(p->next){
		maxptr = p;
		TList cur = p->next;
		while (cur->next && p->next) {
			int i = 0,j=0;
			while (i<(maxptr->name.size()) && j < (cur->name.size())&& (findIndex(maxptr->name[i], alphabet))== findIndex( cur->name[j], alphabet)) {
				if (maxptr->name[i] == ' ') i++;
				if (cur->name[j] == ' ') j++;
				i++;
				j++;
			}
			if (findIndex(maxptr->name[i], alphabet) > findIndex(cur->name[j], alphabet) && i < maxptr->name.size() && j < cur->name.size())
				swap(maxptr, cur);
			cur = cur->next;
		}
		p = p->next;
	}
}

string findSubscribersWithALotOfPhoneNumbers(TList& head) {
	char* alphabet = createAlphabet();
	string out = "";
	TList p = head;
	int prev = 0;
	while (p->next) {
		TList cur = p->next;
		int i = 0, j = 0, k = 1;
		while (i < (p->name.size()) && j < (cur->name.size()) && (findIndex(p->name[i], alphabet)) == findIndex(cur->name[j], alphabet)) {
			k++;
			if (p->name[i] == ' ') i++;
			if (cur->name[j] == ' ') j++;
			i++;
			j++;
		}
		if (k == p->name.size() - 1) {
			i = 0; j = 0, k = 0;
			while (i < (p->add.streat.size()) && j < (cur->add.streat.size()) && (findIndex(p->add.streat[i], alphabet)) == findIndex(cur->add.streat[j], alphabet)) {
				k++;
				if (p->add.streat[i] == ' ') i++;
				if (cur->add.streat[j] == ' ') j++;
				i++;
				j++;
			}
			if (k == p->add.streat.size()) {
				if (stoi(p->add.house) == stoi(cur->add.house) && stoi(p->add.flat) == stoi(cur->add.flat)) {
					if (prev == 0) {
						out += p->name + ' ' + p->add.streat + ' ' + p->add.house + ' ' + p->add.flat + ' ' + p->phone + ' ' + p->balance + '\n';
						prev = 1;
					}
					out += cur->name + ' ' + cur->add.streat + ' ' + cur->add.house + ' ' + cur->add.flat + ' ' + cur->phone + ' ' + cur->balance + '\n';
				}
			}

		}
		else prev = 0;
		cur = p;
		p = p->next;

	}
	return out;
}

void addAfterNode(TList pNode, string* array) {
	TList p = new Node;
	p->name = array[0];
	p->add = readAddres(array[1], ' ');
	p->phone = array[2];
	p->balance = array[3];
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
bool isEmpty(TList head) {
	return head == nullptr;
}
void clear(TList& head) {
	while (!isEmpty(head)) deleteFromHead(head);
}
string printList(TList head) {
	TList p = head;
	string out = "";
	while (p != nullptr) {
		out += p->name + ' ' + p->add.streat + ' ' + p->add.house + ' ' + p->add.flat + ' ' + p->phone + ' ' + p->balance + '\n';
		p = p->next;
	}
	return out;
}
