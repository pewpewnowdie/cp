#include<bits/stdc++.h>
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
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        ds.merge(arr[i]-1, temp-1);
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(ds.parent[i] < 0) count++;
    }
    long long result = 1;
    for(int i = 0; i < count; i++) {
        result = (result * 2) % (int)(1e9+7);
    }
    cout << result << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
