#include <bits/stdc++.h>

using namespace std;

int mod(int a, int b) {
    int c = a % b;
    return (c < 0) ? c + b : c;
}

template <class genType, int size = 50>
class queue_a {
    private:
        int read;
        int write;
        int total_size;
        int number_elements;
        genType* elements;
    public:
        queue_a() {
            this->read = 0;
            this->write = 0;
            this->total_size = size;
            this->number_elements = 0;
            this->elements = new genType[size];
        }
        bool is_empty() {
            return this->number_elements == 0;
        }
        void enqueue(genType key) {
            if (mod(this->read - this->write, this->total_size) == 1) {
                cout << "Error - Queue is full\n";
                return;
            }
            this->elements[this->write] = key;
            this->write = mod(this->write + 1, this->total_size);
            this->number_elements++;
        }
        genType dequeue() {
            if (is_empty()) {
                cout << "Error - Empty queue\n";
                return (genType) NULL;
            }
            genType removed = this->elements[this->read];
            this->read = mod(this->read + 1, this->total_size);
            this->number_elements--;
            return removed;
        }
        genType peek() {
            return (genType) this->elements[this->read];
        }
        int get_total_size() {
            return this->total_size;
        }
        int get_number_elements() {
            return this->number_elements;
        }
        void print_queue() {
            if (is_empty())
                return;
            int index = this->read;
            for (int i = 0; i < this->number_elements; i++) {
                cout << this->elements[index] << ' ';
                index = mod(index + 1, this->total_size);
            }
            cout << '\n';
        }
        void print() {
            for (int i = 0; i < this->total_size; i++) {
                cout << this->elements[i] << ' '; 
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
class queue_ll {
    private:
        doubly_linked_list<genType> list;
        int size;
    public:
        queue_ll() {
            this->size = 0;
        }
        bool is_empty() {
            return this->size == 0;
        }
        void enqueue(genType key) {
            this->list.push_back(key);
            this->size++;
        }
        genType dequeue() {
            if (is_empty()) {
                cout << "Error - Empty queue\n";
                return (genType) NULL;
            }
            genType removed = this->list.top_front();
            this->list.pop_front();
            this->size--;
            return removed;
        }
        genType peek() {
            if (is_empty()) {
                cout << "Error - Empty queue\n";
                return (genType) NULL;
            }
            return this->list.top_front();
        }
        int get_size() {
            return this->size;
        }
        void print_queue() {
            if (is_empty())
                return;
            this->list.print_list();
        }
};

int main() {
    cout << "Queue array\n";
    queue_a<int, 10> queue;
    for (int i = 0; i < 5; i++) {
        queue.enqueue(i + 1);
    }
    queue.print_queue();
    for (int i = 0; i < 3; i++) {
        queue.dequeue();
    }
    queue.print_queue();
    for (int i = 5; i < 10; i++) {
        queue.enqueue(i + 1);
    }
    queue.print_queue();
    cout << to_string(queue.peek()) << '\n';
    queue.print();
    for (int i = 0; i < 6; i++) {
        queue.dequeue();
    }
    queue.print_queue();
    queue.print();
    for (int i = 0; i < 6; i++) {
        queue.enqueue(i + 11);
    }
    queue.print_queue();
    queue.print();
    cout << '\n';
    cout << "Queue linked list\n";
    queue_ll<int> queue2;
    for (int i = 0; i < 5; i++) {
        queue2.enqueue(i + 1);
    }
    cout << to_string(queue2.peek()) << '\n';
    queue2.print_queue();
    for (int i = 0; i < 2; i++) {
        queue2.dequeue();
    }
    queue2.print_queue();
    for (int i = 0; i < 10; i++) {
        queue2.enqueue(i + 6);
    }
    queue2.print_queue();
    cout << queue2.get_size() << '\n';
    return 0;
}