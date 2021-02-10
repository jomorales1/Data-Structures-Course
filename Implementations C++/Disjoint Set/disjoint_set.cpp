#include <bits/stdc++.h>

using namespace std;

template <int size = 10>
class disjoint_set_t {
    private:
        int* parent;
        int* rank;
    public:
        disjoint_set_t() {
            this->parent = new int[size];
            this->rank = new int[size];
        }
        void make_set(int i) {
            if (i < 0 || i >= size) {
                cout << "Error: Invalid Index\n"; return;
            }
            this->parent[i] = i;
            this->rank[i] = 0;
        }
        int find(int i) {
            if (i < 0 || i >= size) {
                cout << "Error: Invalid Index\n"; return -1;
            }
            if (i != this->parent[i])
                this->parent[i] = find(this->parent[i]);
            return this->parent[i];
        }
        void merge(int i, int j) {
            int i_id = find(i);
            int j_id = find(j);
            if (i_id == j_id) return;
            if (this->rank[i_id] > this->rank[j_id]) {
                this->parent[j_id] = i_id;
            } else {
                this->parent[i_id] = j_id;
                if (this->rank[i_id] == this->rank[j_id])
                    this->rank[j_id] = this->rank[j_id] + 1;
            }
        }
        string to_string_t() {
            string res = "";
            for (int i = 0; i < size; i++) {
                res += to_string(i) + ": " + to_string(this->parent[i]) + '\n';
            }
            return res;
        }
};

int main() {
    disjoint_set_t<10> dsu;
    for (int i = 0; i < 10; i++) {
        dsu.make_set(i);
    }
    dsu.merge(1, 5);
    dsu.merge(0, 9);
    dsu.merge(5, 3);
    dsu.merge(6, 0);
    dsu.merge(9, 2);
    dsu.merge(1, 7);
    for (int i = 0; i < 10; i++) {
        cout << i << ": " << dsu.find(i) << '\n';
    }
    cout << '\n';
    cout << dsu.to_string_t();
    return 0;
}