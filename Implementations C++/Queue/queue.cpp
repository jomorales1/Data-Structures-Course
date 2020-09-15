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

int main() {
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
    return 0;
}