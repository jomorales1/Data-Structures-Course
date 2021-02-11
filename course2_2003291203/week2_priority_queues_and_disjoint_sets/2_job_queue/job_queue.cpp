#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    queue<uint_fast64_t> tasks;
    uint_fast64_t time;
    for (int i = 0; i < m; i++) {
        cin >> time;
        tasks.push(time);
    }
    priority_queue<int, vector<int>, greater<int>> threads;
    for (int i = 0; i < n; i++) {
        threads.push(i);
    }
    priority_queue<pair<uint_fast64_t, int>, vector<pair<uint_fast64_t, int>>, greater<pair<uint_fast64_t, int>>> events;
    uint_fast64_t current_time = 0;
    while (!tasks.empty()) {
        if (events.empty()) {
            int limit = min((int) threads.size(), (int) tasks.size());
            for (int i = 0; i < limit; i++) {
                cout << threads.top() << ' ' << current_time << '\n';
                uint_fast64_t new_time = current_time + tasks.front();
                events.push({new_time, threads.top()});
                tasks.pop(); threads.pop();
            }
        } else {
            pair<uint_fast64_t, int> event = events.top();
            threads.push(event.second);
            events.pop();
            current_time = (uint_fast64_t) event.first;
            if (!events.empty()) {
                while (events.top().first == current_time) {
                    threads.push(events.top().second);
                    events.pop();
                    if (events.empty()) break;
                }
            }
            int limit = min((int) threads.size(), (int) tasks.size());
            for (int i = 0; i < limit; i++) {
                cout << threads.top() << ' ' << current_time << '\n';
                uint_fast64_t new_time = current_time + tasks.front();
                events.push({new_time, threads.top()});
                tasks.pop(); threads.pop();
            }
        }
    }
    return 0;
}