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
    int n, m;
    cin >> n >> m;
    vector<set<int>> langs;
    DSU ds(n);
    for(int i = 0; i < n; i++) {
        set<int> lang;
        int no;
        cin >> no;
        while(no--) {
            int curr;
            cin >> curr;
            lang.insert(curr);
            for(int j = 0; j < i; j++) {
                if(langs[j].find(curr) != langs[j].end()) ds.merge(i,j);
            }
        }
        langs.push_back(lang);
    }
    int count = -1;
    int zero = 0;
    for(int i = 0; i < n; i++) {
        if(langs[i].empty()) zero++;
        if(ds.parent[i] < 0) count++;
    }
    cout << count + (zero == n) << endl;
}

int main() {
    solve();
    return 0;
}
