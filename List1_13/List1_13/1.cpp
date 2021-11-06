#include <iostream>
#include <string>
#include "List.h"

using namespace std;

void findFirstNegativeAndDelete(TList& head) {
    TList p = head->next, q = head;
    TList  qlast =head;
    int flag = 0;
    if ((head->data) < 0) {
        deleteFromHead(head);
        return;
    }
    while (p !=nullptr) {
        if(p->data < 0)
        qlast = p;
        if (p->data < 0 && flag == 0) {
            q = p;
            flag = 1;
        }
        p = p->next;
    }
    if (p != nullptr && q->data == qlast->data && q->data < 0)
        deleteAfterNode(q);
    if (q->data < 0 && p != nullptr) {
        deleteAfterNode(q);
        deleteAfterNode(qlast);
    }
}

void deleteElemsWithIdenticalElemsOnBothSides(TList& head) {
    if (head != nullptr && head->next != nullptr && head->next->next != nullptr) {
        TList p = head, q = head->next->next;
        while (q != nullptr) {
            if (p->data == q->data) {
                deleteAfterNode(p);
            }
            p = p->next;
            q = p->next->next;
        }
    }
}

void findEAndCreate(TList& head, int e) {
    TList q = head;
    while (q->next != nullptr && q->data != e){
        q = q->next;
        if (q->data == e) {
            if (q->next == nullptr) {
                addToEnd(head, q->data);
            }
            else {
                addAfterNode(q, q->data);
            }
        }
    }
}

void findFirstAndLastNegativeAndDelete(TList& head)
{
    TList prev = head, p = head->next, before = head;
    if ((head->data) < 0) {
        deleteFromHead(head);
    }
    else {
        while (p != nullptr && p->data >= 0) {
            prev = p;
            p = p->next;
        }
        if (p != nullptr && p->next == nullptr) deleteFromEnd(head);
        if (p != nullptr) {
            deleteAfterNode(prev);
            p = prev->next;
        }
    }
    if (p != nullptr) {
        while (p != nullptr) {
            if (p->data < 0) before = prev;
            prev = p;
            p = p->next;
        }
        cout << before << "  ||  " << before->next<<"  ||  "<< before->next->next << endl;
        cout << before << "  ||  " << before->data << "  ||  " << before->next->data << endl;
        if (before->next->next == nullptr && before->next->data < 0) deleteFromEnd(head);
        else 
        if (before->next->data < 0) deleteAfterNode(before);
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    
    TList head;
    init(head);
    int n, elem;
    cin >> n;
    for (int i = 0; i < n; i++) {
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

        cout << "Input 9 to find first negative element and delete this element " << endl;
        cout << "Input 10 to delete elements with identical elements on both sides " << endl;
        cout << "Input 11 to find E and create " << endl;
        cout << "Input 12 to find First And Last Negative And Delete " << endl;


        cout <<'\n'<< "Input 13 to break" << std::endl << std::endl << endl;
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
            findFirstNegativeAndDelete(head);
            printList(head);
            chose = 0;
            break;
        case 10:
            deleteElemsWithIdenticalElemsOnBothSides(head);
            printList(head);
            chose = 0;
            break;
        case 11:
            int e;
            cin >> e;
            findEAndCreate(head, e);
            printList(head);
            chose = 0;
            break;
        case 12:
            findFirstAndLastNegativeAndDelete(head);
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