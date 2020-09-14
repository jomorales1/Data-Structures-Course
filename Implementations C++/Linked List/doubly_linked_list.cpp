#include <bits/stdc++.h>

using namespace std;

template <class genType>
class node {
    public:
        genType key;
        node<genType>* prev;
        node<genType>* next;

        node() {
            this->prev = NULL;
            this->next = NULL;
        }
};

template <class genType>
class doubly_linked_list {
    private:
        int size;
        node<genType>* head;
        node<genType>* tail;

        void add_after(node<genType> &n, genType key) {
            node<genType>* new_node = new node<genType>;
            new_node->key = key;
            new_node->next = n->next;
            new_node->prev = n;
            n->next = new_node;
            if (new_node->next != NULL)
                new_node->next->prev = new_node;
            if (this->tail == n)
                this->tail = new_node;
            this->size++;
        }
        void add_before(node<genType> &n, genType key) {
            node<genType>* new_node = new node<genType>;
            new_node->key = key;
            new_node->next = n;
            new_node->prev = n->prev;
            n->prev = new_node;
            if (new_node != NULL)
                new_node->prev->next = new_node;
            if (this->head == n)
                this->head = new_node;
            this->size++;
        }
    public:
        doubly_linked_list() {
            this->head = NULL;
            this->tail = NULL;
            this->size = 0;
        }
        bool is_empty() {
            return this->size == 0;
        }
        void push_back(genType key) {
            node<genType>* new_node = new node<genType>;
            new_node->key = key;
            new_node->next = NULL;
            if (this->tail == NULL) {
                this->head = new_node;
                this->tail = new_node;
                new_node->prev = NULL;
            } else {
                this->tail->next = new_node;
                new_node->prev = this->tail;
                this->tail = new_node;
            }
            this->size++;
        }
        genType pop_back() {
            if (this->head == NULL) {
                cout << "Error - Empty list\n";
                return (genType) NULL;
            }
            genType result = this->tail->key;
            if (this->head == this->tail) {
                this->head = NULL;
                this->tail = NULL;
            } else {
                this->tail = this->tail->prev;
                this->tail->next = NULL;
            }
            this->size--;
            return result;
        }
        genType top_back() {
            return (genType) this->tail->key;
        }
        void push_front(genType key) {
            node<genType>* new_node = new node<genType>;
            new_node->key = key;
            new_node->prev = NULL;
            if (this->head == NULL) {
                new_node->next = NULL;
                this->head = new_node;
                this->tail = new_node;
            } else {
                this->head->prev = new_node;
                new_node->next = this->head;
                this->head = new_node;
            }
            this->size++;
        }
        genType pop_front() {
            if (this->head == NULL) {
                cout << "Error - Empty list\n";
                return (genType) NULL;
            }
            genType result = this->head->key;
            if (this->head == this->tail) {
                this->head = NULL;
                this->tail = NULL;
            } else {
                this->head = this->head->next;
                this->head->prev = NULL;
            }
            this->size--;
            return result;
        }
        genType top_front() {
            return (genType) this->head->key;
        }
        bool find(genType key) {
            if (this->head == NULL)
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
                this->head->prev = NULL;
                if (this->head == NULL)
                    this->tail = NULL;
                return;
            }
            node<genType>* current = this->head;
            while (current->next->key != key) {
                current = current->next;
            }
            current->next = current->next->next;
            current->next->next->prev = current;
            this->size--;
        }
        int get_size() {
            return this->size;
        }
        void print_list() {
            if (this->head == NULL)
                return;
            node<genType>* current = this->head;
            while (current != NULL) {
                cout << to_string(current->key) << ' ';
                current = current->next;
            }
            cout << '\n';
        }
};

int main() {
    doubly_linked_list<int> list;
    for (int i = 0; i < 10; i++) {
        list.push_back(i + 1);
    }
    for (int i = 10; i < 20; i++) {
        list.push_front(i + 1);
    }
    cout << list.get_size() << '\n';
    list.print_list();
    cout << to_string(list.top_front()) << ' ' << to_string(list.top_back()) << '\n';
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            list.pop_front();
        } else {
            list.pop_back();
        }
    }
    cout << list.get_size() << '\n';
    list.print_list();
    return 0;
}