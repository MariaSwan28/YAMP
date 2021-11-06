#include <iostream>
#include <string>
#include "List.h"

using namespace std;

void findMaxAndDelete(TList& head) {
	TList p = head, q = head;
	int max = p->data;
    if ((p->next) == nullptr) {
        deleteFromHead(head);
        return;
    }
    if (head->next->data > max) {
        max = head->next->data;
        q = p;
    }
	while (p->next != nullptr) {
		if (p->next->data > max) {
			max = p->next->data;
			q = p;
		}
		p = p->next;
	}
    if (max == head->data) {
        deleteFromHead(head);
        return;
    }
	if (q == head) deleteAfterNode(head);
	else deleteAfterNode(q);
}
void findMinAndCreate(TList& head) {
	TList p = head, after = head, before = head,k=head;
	int min = 0;
    
    while (k->data <= 0) {
        if (k->next == nullptr) 
            return;
        k = k->next;
    }

    min = k->data;
    if ((k->next) != nullptr) {
        if (p->next->data < min && p->next->data > 0) {
            min = p->next->data;
            after = p->next;
        }
        while ((p->next->next) != nullptr) {
            if (p->next->next->data < min && p->next->next->data > 0) {
                min = p->next->next->data;
                after = p->next->next;
                before = p->next;
            }
            p = p->next;
        }
            if (p->next->data < min && p->next->data > 0) {
                min = p->next->data;
                after = p->next;
                before = p->next;
            }
    }
    if (after == head->next) {
        addAfterNode(head, min);
        addAfterNode(after, min);
        return;
    }
    if (after-> next== nullptr) {
            addAfterNode(before, min);
            addToEnd(after, min);
            return;
    }
	else {
		addAfterNode(before, min);
		addAfterNode(after, min);
        return;
	}
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    TList head;
    init(head);
    int n, elem;
    cin >> n;
    for(int i=0;i<n;i++){
    cout << "Input elem : ";
    cin >> elem;
    addToEnd(head, elem);
    }

    int z = 1;
    while (z != 0) {
        cout << endl << endl;
        cout << "Input 1 to input element to head" << endl;
        cout << "Input 2 to input element to end" <<endl;
        cout << "Input 3 to input element after n element" <<endl;
        cout << "Input 4 to delete from head" << endl;
        cout << "Input 5 to delete from end" << endl;
        cout << "Input 6 to delete after n elements" << endl;
        cout << "Input 7 to clear" << endl;
        cout << "Input 8 to print" << endl;
        cout << "Input 9 to find max element and delete this element " << endl;
        cout << "Input 10 to find min element and create before, after  this element new elements with min value " << endl;

        cout << "Input 11 to break" << std::endl << std::endl << endl;
        int chose;
        cin >> chose;
        switch (chose) {
        
        case 1:
            cout << "Input elem" << std::endl;
            cin >> elem;
            addToHead(head, elem);
            printList(head);
            chose = 0;
            break;
        case 2:
            cout << "Input elem" << std::endl;
            cin >> elem;
            addToEnd(head, elem);
            printList(head);
            chose = 0;
            break;
        case 3:
            cout << "Input elem" << std::endl;
            cin >> elem;
            cout << "Input n" << std::endl;
            cin >> n;
            TList p;
            p = head;
            for (int i = 0; i < n; i++) {
                if (p != nullptr) {
                    p = p->next;
                }
            }
            addAfterNode(p, elem);
            printList(head);
            chose = 0;
            break;
        case 4:
            deleteFromHead(head);
            printList(head);
            chose = 0;
            break;
        case 5:
            deleteFromEnd(head);
            printList(head);
            chose = 0;
            break;
        case 6:
            cout << "Input n" << std::endl;
            cin >> n;
            p = head;
            for (int i = 0; i < n; i++) {
                if (p != nullptr) {
                    p = p->next;
                }
            }
            deleteAfterNode(p);
            printList(head);
            chose = 0;
            break;
        case 7:
            clear(head);
            printList(head);
            chose = 0;
            break;
        case 8:
            printList(head);
            chose = 0;
            break;
        case 9:
            findMaxAndDelete(head);
            printList(head);
            chose = 0;
            break;
        case 10:
            findMinAndCreate(head);
            printList(head);
            chose = 0;
            break;
        default:
            z = 0;
            break;
        }
    }

    printList(head);
    clear(head);

    system("pause");
    return 0;
}