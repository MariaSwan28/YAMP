#include <iostream>
#include <string>
#include <fstream>
#include "List.h"

using namespace std;

string* split(string data, char separator) {
    string* elem=new string[4];
    int i = 0, j = 0, n = data.size();
    while (i < n) {
        while (data[i] != separator) {
            elem[j] += data[i];
            i++;
            if (i == n) break;

        }
        i++;
        //cout << elem[j] << endl;
        j++;
    }
    return elem;
}


int main()
{
    setlocale(LC_CTYPE, "rus");
    ifstream file("D:\\file.txt", ios_base::in);
    ofstream fileResult("D:\\fileResult.txt", ios_base::out);

    TList head;
	init(head);
    string data;
    if (!file.is_open()) {
        cout << "Ошибка. " << endl;
    }
    else {
        while (!file.eof()) {
            getline(file, data);
            string* elem = split(data, ';');
            addToEnd(head, elem);
        }
        sortList(head);
        string out=findSubscribersWithALotOfPhoneNumbers(head);

        fileResult << printList(head);
        fileResult <<"Абоненты, имеющие два и более телефонных номера: "<<'\n'<< out;

        clear(head);
        file.close(); 
        fileResult.close();
    }
	system("pause");
	return 0;
}