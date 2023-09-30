#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int main() {

    int kase;
    cin >> kase;
    while (kase--) {
        int v, e;
        cin >> v >> e;
        vector<vector<pair<int, int>>> gp(v);
        while (e--) {
            int start, end, w;
            cin >> start >> end >> w;
            gp[start].push_back({end, w});
        }
        queue<int> spfa;
        int vst[v] = {}, dist[v];
        memset(dist, inf, sizeof(dist));
        bool inqueue[v] = {}, flag = true;
        dist[0] = 0;
        spfa.push(0);
        while (!spfa.empty()) {
            int tmp = spfa.front();
            spfa.pop();
            vst[tmp]++;
            if (vst[tmp] > v) {
                flag = 0;
                break;
            }
            inqueue[tmp] = false;
            for (auto ele : gp[tmp]) {
                if (ele.second + dist[tmp] < dist[ele.first]) {
                    dist[ele.first] = ele.second + dist[tmp];
                    if (!inqueue[ele.first]) {
                        spfa.push(ele.first);
                        inqueue[ele.first] = true;
                    }
                }
            }
        }
        if (flag)
            cout << "not possible\n";
        else
            cout << "possible\n";
    }

    return 0;
}