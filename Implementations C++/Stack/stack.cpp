#include <bits/stdc++.h>

using namespace std;

template<class genType, int size = 50>
class dynamic_array {
    public:
        dynamic_array() {
            elements = new genType[size];
        }
        bool is_empty() {
            return this->capacity == 0;
        }
        void push_back(genType element) {
            capacity++;
            if (capacity == total_size - 1) {
                genType* new_array = new genType[total_size * 2];
                for (int i = 0; i < capacity - 1; i++) {
                    new_array[i] = elements[i];
                }
                new_array[capacity - 1] = element;
                delete [] elements;
                elements = new_array;
                total_size = total_size * 2;
            } else {
                elements[capacity - 1] = element;
            }
        }
        genType pop_back() {
            if (capacity == 0) {
                return (genType) NULL;
            }
            capacity--;
            return elements[capacity];
        }

        genType get_element(int index) {
            if (index < 0 || index > this->capacity - 1) {
                cout << "Error - Invalid index\n";
                return (genType) NULL;
            }
            return this->elements[index];
        }

        genType front() {
            if (is_empty()) {
                return (genType) NULL;
            }
            return (genType) this->elements[0];
        }

        genType back() {
            if (is_empty()) {
                return (genType) NULL;
            }
            return (genType) this->elements[this->capacity - 1];
        }

        int get_capacity() {
            return capacity;
        }

        int get_total_size() {
            return total_size;
        }

        void print_elements() {
            if (capacity == 0)
                return;
            for (int i = 0; i < capacity; i++) {
                cout << to_string(elements[i]) << ' ';
            }
            cout << '\n';
        }
    private:
        int capacity = 0;
        int total_size = size;
        genType* elements;
};

template <class genType>
class stack_a {
    private:
        dynamic_array<genType, 10> elements;
        int size;
    public:
        stack_a() {
            this->size = 0;
        }
        bool is_empty() {
            return this->size == 0;
        }
        void push(genType key) {
            this->elements.push_back(key);
            this->size++;
        }
        genType pop() {
            if (this->elements.is_empty()) {
                cout << "Error - Empty stack\n";
                return (genType) NULL;
            }
            genType top = this->elements.back();
            this->elements.pop_back();
            return top;
        }
        genType top() {
            if (this->elements.is_empty()) {
                cout << "Error - Empty stack\n";
                return (genType) NULL;
            }
            return this->elements.back();
        }
        int get_size() {
            return this->size;
        }
        void print_stack() {
            if (is_empty())
                return;
            for (int i = 0; i < this->elements.get_capacity(); i++) {
                cout << this->elements.get_element(i) << ' ';
            }
            cout << '\n';
        }
};

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

template <class genType>
class stack_ll {
    private:
        doubly_linked_list<genType> list;
        int size;
    public:
        stack_ll() {
            this->size = 0;
        }
        bool is_empty() {
            return this->size == 0;
        }
        void push(genType key) {
            this->list.push_front(key);
            this->size++;
        }
        genType pop() {
            if (this->size == 0) {
                cout << "Error - Empty stack\n";
                return (genType) NULL;
            }
            genType removed = this->list.top_front();
            this->list.pop_front();
            this->size--;
            return removed;
        }
        genType top() {
            return this->list.top_front();
        }
        int get_size() {
            return this->size;
        }
        void print_stack() {
            if (is_empty())
                return;
            this->list.print_list();
        }
};

int main() {
    stack_ll<int> s;
    for (int i = 0; i < 10; i++) {
        s.push(i + 1);
    }
    s.print_stack();
    cout << s.get_size() << '\n';
    cout << to_string(s.top()) << '\n';
    for (int i = 0; i < 5; i++) {
        s.pop();
        s.print_stack();
    }
    return 0;
}