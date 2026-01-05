/**
 * 🧱 Mo's Algorithm (Offline Range Queries)
 * 
 * Mo's algorithm allows answering Q range queries on an array of size N 
 * in O((N+Q) * sqrt(N)) by reordering queries.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int BLOCK_SIZE = 320; // sqrt(100000)

struct Query {
    int l, r, id;
    bool operator<(const Query& other) const {
        int b1 = l / BLOCK_SIZE;
        int b2 = other.l / BLOCK_SIZE;
        if (b1 != b2) return b1 < b2;
        return (b1 & 1) ? (r < other.r) : (r > other.r); // Optimization
    }
};

int cur_ans = 0;
int freq[1000005];

void add(int val) {
    if (freq[val] == 0) cur_ans++;
    freq[val]++;
}

void remove(int val) {
    freq[val]--;
    if (freq[val] == 0) cur_ans--;
}

int main() {
    int n = 5;
    vector<int> a = {1, 1, 2, 1, 3};
    vector<Query> queries = {{0, 2, 0}, {1, 4, 1}};
    
    sort(queries.begin(), queries.end());

    vector<int> answers(queries.size());
    int cur_l = 0, cur_r = -1;

    for (auto& q : queries) {
        while (cur_l > q.l) add(a[--cur_l]);
        while (cur_r < q.r) add(a[++cur_r]);
        while (cur_l < q.l) remove(a[cur_l++]);
        while (cur_r > q.r) remove(a[cur_r--]);
        answers[q.id] = cur_ans;
    }

    cout << "Query Answers (Distinct elements in range):" << endl;
    for (int res : answers) cout << res << endl;

    return 0;
}
