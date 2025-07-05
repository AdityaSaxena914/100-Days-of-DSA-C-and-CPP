#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& edges) {
        typedef pair<int, int> P;

        vector<vector<tuple<int, int, int>>> gr(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int start = edges[i][2];
            int end = edges[i][3];
            gr[u].push_back(make_tuple(v, start, end));
        }

        vector<int> time(n, INT_MAX);
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push(make_pair(0, 0));
        time[0] = 0;

        while (!pq.empty()) {
            int currTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (currTime > time[node]) continue;

            for (int i = 0; i < gr[node].size(); i++) {
                int next = get<0>(gr[node][i]);
                int s = get<1>(gr[node][i]);
                int e = get<2>(gr[node][i]);

                if (currTime > e) continue;

                int wait = max(currTime, s) + 1;
                if (wait < time[next]) {
                    time[next] = wait;
                    pq.push(make_pair(wait, next));
                }
            }
        }

        return time[n - 1] == INT_MAX ? -1 : time[n - 1];
    }
};

int main() {
    Solution solver;

    int n = 3;
    vector<vector<int>> edges = {
        {0, 1, 0, 1},
        {1, 2, 2, 5}
    };

    int result = solver.minimumTime(n, edges);
    cout << "Minimum time to reach destination: " << result << endl;

    return 0;
}
