#include <bits/stdc++.h>

using namespace std;

class hash_table_t {
    public:
        hash_table_t(int m) {
            this->buckets = m;
            this->table = new vector<string>[m];
        }
        void add(const string &s) {
            size_t hash = hash_code(s);
            bool found = false;
            for (string a : this->table[hash]) {
                if (a == s) {
                    found = true; break;
                }
            }
            if (!found) this->table[hash].push_back(s);
        }
        void erase(const string &s) {
            size_t hash = hash_code(s);
            int pos = -1;
            int n = (int) this->table[hash].size();
            for (int i = 0; i < n; i++) {
                if (this->table[hash][i] == s) {
                    pos = i; break;
                }
            }
            if (pos != -1) this->table[hash].erase(this->table[hash].begin() + pos);
        }
        bool find(const string &s) {
            size_t hash = hash_code(s);
            for (string a : this->table[hash]) {
                if (a == s) return true;
            }
            return false;
        }
        void check(int index) {
            int n = (int) this->table[index].size();
            for (int i = n - 1; i >= 0; i--) {
                cout << this->table[index][i] << ' ';
            }
            cout << '\n';
        }
    private:
        int buckets;
        vector<string>* table;
        size_t hash_code(const string &s) {
            unsigned long long hash = 0LL;
            static const size_t multiplier = 263;
            static const size_t prime = 1000000007;
            int n = (int) s.length();
            for (int i = n - 1; i >= 0; i--) {
                int as = s[i];
                hash = (hash * multiplier + as) % prime;
            }
            return hash % this->buckets;
        }
};

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int m = 0; cin >> m;
    hash_table_t ht(m);
    int n = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        string action; cin >> action;
        if (action == "add") {
            string s; cin >> s;
            ht.add(s);
        } else if (action == "del") {
            string s; cin >> s;
            ht.erase(s);
        } else if (action == "find") {
            string s; cin >> s;
            bool res = ht.find(s);
            if (res) cout << "yes\n";
            else cout << "no\n";
        } else {
            int index; cin >> index;
            ht.check(index);
        }
    }
    return 0;
}