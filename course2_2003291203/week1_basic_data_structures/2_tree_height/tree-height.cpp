#include <bits/stdc++.h>

using namespace std;

template <class genType>
class node {
    public:
        genType key;
        vector<node<genType>*> children;
        node(genType key) {
            this->key = key;
        }
        void add_children(node<genType>* child) {
            this->children.push_back(child);
        }
        int number_children() {
            return this->children.size();
        }
};

long long height(node<int>* tree) {
    if (tree->number_children() == 0)
        return 1;
    long long maximum = 0LL;
    for (auto &child : tree->children) {
        maximum = max(maximum, height(child));
    }
    return (1LL + maximum);
}

int main() {
    int n; cin >> n;
    vector<node<int>> nodes;
    int root, parent_index;
    for (int i = 0; i < n; i++) {
        node<int> new_node(i);
        nodes.push_back(new_node);
    }
    for (int i = 0; i < n; i++) {
        cin >> parent_index;
        if (parent_index == -1) {
            root = i;
        } else {
            nodes[parent_index].add_children(&nodes[i]);
        }
    }
    cout << height(&nodes[root]) << '\n';
    return 0;
}