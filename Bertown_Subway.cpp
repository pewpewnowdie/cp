#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n, -1); 
    }
    int find(int u) {
        if (parent[u] < 0)
            return u;
        return parent[u] = find(parent[u]); 
    }
    void merge(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            if (parent[pu] < parent[pv]) 
                swap(pu, pv);
            parent[pv] += parent[pu]; 
            parent[pu] = pv;
        }
    }
};

void solve() {
    int n;
    cin >> n;
    DSU ds(n);
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        ds.merge(i, t - 1);
    }
    vector<int> componentSizes;
    for(int i = 0; i < n; i++) {
        if(ds.parent[i] < 0) {
            componentSizes.push_back(-ds.parent[i]);
        }
    }

    if (componentSizes.size() == 1) {
        cout << fixed << (long long)pow(componentSizes[0], 2);
        return;
    }

    sort(componentSizes.rbegin(), componentSizes.rend());

    int max1 = componentSizes[0];
    int max2 = componentSizes[1];
    long long result = pow(max1 + max2, 2);

    for (int i = 2; i < componentSizes.size(); i++) {
        result += pow(componentSizes[i], 2);
    }

    cout << fixed << result;
}

int main() {
    solve();
    return 0;
}
