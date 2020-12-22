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

void max_sliding_window_naive(vector<int> const & A, int w) {
    for (int i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (int j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));
        cout << window_max << " ";
    }
    return;
}

void find_max(queue_ll<int> q) {
    int maximum = 0;
    while (!q.is_empty()) {
        if (q.peek() > maximum)
            maximum = q.peek();
        q.dequeue();
    }
    cout << maximum << ' ';
}

void max_sliding_window(const vector<int> &a, int m) {
    int n = a.size();
    int max_upto[n]; 
    stack<int> s; 
    s.push(0); 
    for (int i = 1; i < n; i++) { 
        while (!s.empty() && a[s.top()] < a[i]) { 
            max_upto[s.top()] = i - 1; 
            s.pop(); 
        } 
        s.push(i); 
    }
    while (!s.empty()) { 
        max_upto[s.top()] = n - 1; 
        s.pop(); 
    } 
    int j = 0; 
    for (int i = 0; i <= n - m; i++) { 
        while (j < i || max_upto[j] < i + m - 1) 
            j++; 
        cout << a[j] << " "; 
    } 
    cout << endl;
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m; cin >> m;
    max_sliding_window(a, m);
    return 0;
}
