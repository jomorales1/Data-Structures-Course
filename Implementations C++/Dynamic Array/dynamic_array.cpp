#include <bits/stdc++.h>

using namespace std;

template<class genType, int size = 50>
class dynamic_array {
    public:
        dynamic_array() {
            elements = new genType[size];
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
                return elements[capacity];
            }
            capacity--;
            return elements[capacity];
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

int main() {
    dynamic_array<int, 10> d;
    for (int i = 0; i < 11; i++) {
        d.push_back(i + 1);
    }
    d.print_elements();
    cout << d.get_capacity() << '\n';
    cout << d.get_total_size() << '\n';
    for (int i = 0; i < 11; i++) {
        cout << d.pop_back() << '\n';
    }
    d.print_elements();
    cout << d.get_capacity() << '\n';
    cout << d.get_total_size() << '\n';
    return 0;
}