#include "SkipList.h"
#include <iostream>

using namespace std;

SkipList list;

void Find(int k) {
    cout << "Found: " << (list.Find(k) ? list.Find(k)->value : -1) << endl;
}

void Delete(int k) {
    cout << "Delete: " << (list.Delete(k) ? "YES" : "NO") << endl;
}

void Insert(int k) {
    cout << "Insert: " << (list.Insert(k, k) ? "YES" : "NO") << endl;
}

int main() {
    char ch;
    int k;
    while (true) {
        cin >> ch >> k;
        switch (ch) {
            case 'F':
                Find(k);
                break;
            case 'D':
                Delete(k);
                break;
            case 'I':
                Insert(k);
                break;
            default:
                break;
        }
    }
}
