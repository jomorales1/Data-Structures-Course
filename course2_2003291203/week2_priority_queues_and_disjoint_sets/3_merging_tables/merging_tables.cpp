#include <bits/stdc++.h>

using namespace std;

class disjoint_set_t {
    private:
        int* parent;
        int* rank;
        int* size;
		int max_table_size;
    public:
        disjoint_set_t(int n) {
            this->parent = new int[n];
            this->rank = new int[n];
            this->size = new int[n];
			this->max_table_size = 0;
        }
        void make_set(int i) {
            this->parent[i] = i;
            this->rank[i] = 0;
        }
        int find(int i) {
            if (i != this->parent[i])
                this->parent[i] = find(this->parent[i]);
            return this->parent[i];
        }
        void merge(int i, int j) {
            int i_id = find(i);
            int j_id = find(j);
            if (i_id == j_id) {
				cout << this->max_table_size << '\n'; 
				return;
			}
            if (this->rank[i_id] > this->rank[j_id]) {
                this->parent[j_id] = i_id;
				this->size[i_id] += this->size[j_id];
				this->size[j_id] = 0;
				this->max_table_size = max(this->max_table_size, this->size[i_id]);
            } else {
                this->parent[i_id] = j_id;
                if (this->rank[i_id] == this->rank[j_id])
                    this->rank[j_id] = this->rank[j_id] + 1;
				this->size[j_id] += this->size[i_id];
				this->size[i_id] = 0;
				this->max_table_size = max(this->max_table_size, this->size[j_id]);
            }
			cout << this->max_table_size << '\n';
        }
		void setup(int n) {
			int s;
			for (int i = 0; i < n; i++) {
				make_set(i);
				cin >> s;
				this->size[i] = s;
				this->max_table_size = max(this->max_table_size, s);
			}
		}
};

int main() {
	int n = 0, m = 0;
	cin >> n >> m;
	disjoint_set_t dsu(n);
	dsu.setup(n);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--; b--;
		dsu.merge(a, b);
	}
	return 0;
}