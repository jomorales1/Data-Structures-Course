#include <bits/stdc++.h>

using namespace std;

template <class genType, int msize = 50>
class priority_queue_t {
    public:
        priority_queue_t() {
            this->elements = new genType[msize + 1];
        }
        void insert(genType value) {
            if (this->size == this->max_size) {
                cout << "Not enough space.\n";
                return;
            }
            this->size++;
            this->elements[this->size] = value;
            sift_up(this->size);
        }
        genType extract_max() {
            if (this->size == 0) {
                cout << "Empty heap.\n";
                return (genType) NULL;
            }
            genType result = this->elements[1];
            this->elements[1] = this->elements[this->size];
            this->size--;
            sift_down(1);
            return (genType) result;
        }
        void remove(int index) {
            if (typeid(genType) == typeid(int)) {
                this->elements[index] = INT_MAX;
            } else if (typeid(genType) == typeid(double)) {
                this->elements[index] = DBL_MAX;
            } else if (typeid(genType) == typeid(long long)) {
                this->elements[index] = __LONG_LONG_MAX__;
            } else {
                cout << "Data type not supported.\n";
                return;
            }
            sift_up(index);
            extract_max();
        }
        void change_priority(int index, genType priority) {
            genType old_priority = this->elements[index];
            this->elements[index] = priority;
            if (priority > old_priority) {
                sift_up(index);
            } else {
                sift_down(index);
            }
        }
        string to_string_t() {
            string res = "[";
            for (int i = 1; i <= this->size; i++) {
                res += to_string(this->elements[i]);
                if (i != this->size) {
                    res += ", ";
                } else {
                    res += "]\n";
                }
            }
            return res;
        }
    private:
        int size = 0;
        int max_size = msize;
        genType* elements;

        int parent(int index) {
            return index / 2;
        }
        int left_child(int index) {
            return 2 * index;
        }
        int right_child(int index) {
            return 2 * index + 1;
        }
        void sift_up(int index) {
            while (index > 1 && this->elements[parent(index)] < this->elements[index]) {
                swap(this->elements[parent(index)], this->elements[index]);
                index = parent(index);
            }
        }
        void sift_down(int index) {
            int max_index = index;
            int left = left_child(index);
            if (left <= this->size && this->elements[left] > this->elements[max_index])
                max_index = left;
            int right = right_child(index);
            if (right <= this->size && this->elements[right] > this->elements[max_index])
                max_index = right;
            if (index != max_index) {
                swap(this->elements[index], this->elements[max_index]);
                sift_down(max_index);
            }
        }
};

int main() {
    priority_queue_t<int, 20> queue;
    for (int i = 10; i >= 5; i--) {
        queue.insert(i - 5);
        queue.insert(i);
    }
    cout << queue.to_string_t();
    queue.remove(3);
    cout << queue.to_string_t();
    cout << to_string(queue.extract_max()) << '\n';
    cout << queue.to_string_t();
    return 0;
}