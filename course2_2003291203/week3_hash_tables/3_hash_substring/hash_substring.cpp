#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

const long long p = 1e9 + 7;

long long poly_hash(string &s, int left, int right, long long x) {
    long long hash = 0LL;
    int n = (int) s.length();
    for (int i = right; i >= left; i--) {
        hash = (hash * x + (long long) s[i]) % p;
    }
    return hash;
}

vector<long long> precompute_hashes(string &T, int pattern_len, long long x) {
    int len = (int) T.length();
    int n = len - pattern_len + 1;
    vector<long long> hashes(n);
    hashes[n - 1] = poly_hash(T, n - 1, len - 1, x);
    long long y = 1LL;
    for (int i = 1; i <= pattern_len; i++) {
        y = (y * x) % p;
    }
    for (int i = n - 2; i >= 0; i--) {
        hashes[i] = ((x * hashes[i + 1]) + (long long) T[i] - y * ((long long) T[i + pattern_len])) % p;
    }
    return hashes;
}

bool are_equal(string &T, int start, string &S) {
    for (int i = 0; i < (int) S.length(); i++) {
        if (T[start + i] != S[i]) {
            return false;
        }
    }
    return true;
}

vector<int> rabin_karp(string &T, string &P) {
    long long x = (long long) (rand() % (p - 1)) + 1;
    vector<int> result;
    long long p_hash = poly_hash(P, 0, (int) P.length(), x);
    vector<long long> H = precompute_hashes(T, (int) P.length(), x);
    int n = (int) H.size();
    for (int i = 0; i < n; i++) {
        if (p_hash != H[i]) {
            continue;
        }
        if (are_equal(T, i, P)) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    string P; cin >> P;
    string T; cin >> T;
    vector<int> result = rabin_karp(T, P);
    for (int pos : result) {
        cout << pos << ' ';
    }
    cout << '\n';
    return 0;
}