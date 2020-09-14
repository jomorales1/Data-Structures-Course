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

int main() {
    stack_a<int> s;
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