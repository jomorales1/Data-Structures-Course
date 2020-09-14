#include <bits/stdc++.h>

using namespace std;

template <class genType>
class node {
    public:
        genType key;
        node<genType>* next;

        node() {
            this->next = NULL;
        }
};

template <class genType>
class linked_list {
    private:
        int size;
        node<genType>* head;
        node<genType>* tail;

        void add_after(node<genType> &n, genType key) {
            node<genType>* new_node = new node<genType>;
            new_node->key = key;
            new_node->next = n->next;
            n->next = new_node;
            if (this->tail == n) {
                this->tail = new_node;
            }
            this->size++;
        }

        void add_before(node<genType> &n, genType key) {
            node<genType>* new_node = new node<genType>;
            new_node->key = key;
            if (this->head == n) {
                push_front(key);
                return;
            }
            node<genType>* current = this->head;
            while (current->next != n) {
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
            this->size++;
        }
    public:
        linked_list() {
            this->head = NULL;
            this->tail = NULL;
            this->size = 0;
        }
        bool is_empty() {
            return this->size == 0;
        }
        void push_front(genType key) {
            node<genType>* new_node = new node<genType>;
            new_node->key = key;
            new_node->next = this->head;
            this->head = new_node;
            if (is_empty())
                this->tail = this->head;
            this->size++;
        }
        genType pop_front() {
            if (is_empty()) {
                cout << "Error - Empty list\n";
                return (genType) NULL;
            }
            node<genType>* first = this->head;
            this->head = this->head->next;
            if (this->head == NULL)
                this->tail = NULL;
            this->size--;
            return (genType) first->key;
        }
        genType top_front() {
            return (genType) this->head->key;
        }
        void push_back(genType key) {
            node<genType>* new_node = new node<genType>;
            new_node->key = key;
            new_node->next = NULL;
            if (is_empty()) {
                this->head = new_node;
                this->tail = new_node;
            } else {
                this->tail->next = new_node;
                this->tail = new_node;
            }
            this->size++;
        }
        genType pop_back() {
            if (is_empty()) {
                cout << "Error - Empty list\n";
                return (genType) NULL;
            }
            node<genType>* last = this->tail;
            if (this->head == this->tail) {
                this->head = NULL;
                this->tail = NULL;
            } else {
                node<genType>* current = this->head;
                while (current->next->next != NULL) {
                    current = current->next;
                }
                current->next = NULL;
                this->tail = current;
            }
            this->size--;
            return (genType) last->key;
        }
        genType top_back() {
            return (genType) this->tail->key;
        }
        bool find(genType key) {
            if (is_empty())
                return false;
            node<genType>* current = this->head;
            while (current != NULL) {
                if (current->key == key)
                    return true;
                current = current->next;
            }
            return false;
        }
        void erase(genType key) {
            if (!find(key)) {
                cout << "Error - Key is not in the list\n";
                return;
            }
            if (this->head->key == key) {
                this->head = this->head->next;
                if (this->head == NULL)
                    this->tail = NULL;
                return;
            }
            node<genType>* current = this->head;
            while (current->next->key != key) {
                current = current->next;
            }
            current->next = current->next->next;
            this->size--;
        }
        int get_size() {
            return this->size;
        }
        void print_list() {
            if (is_empty()) {
                cout << "Empty\n";
                return;
            }
            node<genType>* current = this->head;
            while (current != NULL) {
                cout << to_string(current->key) << ' ';
                current = current->next;
            }
            cout << '\n';
        }
};

int main() {
    linked_list<int> list;
    for (int i = 0; i < 5; i++) {
        list.push_back(i + 1);
    }
    for (int i = 5; i < 10; i++) {
        list.push_front(i + 1);
    }
    list.print_list();
    cout << to_string(list.top_front()) << '\n';
    cout << to_string(list.top_back()) << '\n';
    cout << to_string(list.find(6)) << '\n';
    list.erase(6);
    list.print_list();
    return 0;
}