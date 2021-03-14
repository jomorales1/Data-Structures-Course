#include <bits/stdc++.h>

using namespace std;

const int N = 1e8;
unordered_map<int, string> phone_book;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        string action; cin >> action;
        if (action == "add") {
            int number; cin >> number;
            string name; cin >> name;
            phone_book[number] = name;
        } else if (action == "del") {
            int number; cin >> number;
            if (phone_book.count(number))
                phone_book.erase(number);
        } else {
            int number; cin >> number;
            if (phone_book.count(number)) {
                cout << phone_book[number] << '\n';
            } else {
                cout << "not found\n";
            }
        }
    }
    return 0;
}