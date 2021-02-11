#include <bits/stdc++.h>

using namespace std;

#define NEG(x) (-(x))

template <class genType>
class min_priority_queue_t {
    public:
        vector<pair<int, int>> swaps;
        min_priority_queue_t(int msize) {
            this->max_size = msize;
            this->elements = new genType[msize + 1];
        }
        void insert(genType value) {
            if (this->size == this->max_size) {
                cout << "Not enough space.\n";
                return;
            }
            this->size++;
            this->elements[this->size] = NEG(value);
            sift_up(this->size);
        }
        genType extract_min() {
            if (this->size == 0) {
                cout << "Empty heap.\n";
                return (genType) NULL;
            }
            genType result = this->elements[1];
            this->elements[1] = this->elements[this->size];
            this->size--;
            sift_down(1);
            return (genType) NEG(result);
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
            extract_min();
        }
        void change_priority(int index, genType priority) {
            genType old_priority = this->elements[index];
            this->elements[index] = NEG(priority);
            if (priority > old_priority) {
                sift_up(index);
            } else {
                sift_down(index);
            }
        }
        void build_heap(genType *a, int n) {
            this->max_size = n;
            this->size = n;
            this->elements = new genType[n + 1];
            for (int i = 1; i <= n; i++) {
                this->elements[i] = NEG(a[i - 1]);
            }
            for (int i = n / 2; i >= 1; i--) {
                sift_down(i);
            }
        }
        string to_string_t() {
            string res = "[";
            for (int i = 1; i <= this->size; i++) {
                res += to_string(NEG(this->elements[i]));
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
        int max_size;
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
                this->swaps.push_back({index, max_index});
                swap(this->elements[index], this->elements[max_index]);
                sift_down(max_index);
            }
        }
};

int main() {
    int n = 0; cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    min_priority_queue_t<int> queue(n);
    queue.build_heap(a, n);
    cout << queue.swaps.size() << '\n';
    for (auto s : queue.swaps) {
        cout << (s.first - 1) << ' ' << (s.second - 1) << '\n';
    }
    return 0;
}
