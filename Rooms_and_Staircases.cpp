#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = -1, r = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            l = i;
            break;
        }
    }
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == '1') {
            r = i;
            break;
        }
    }
    if(l == -1) {
        cout << n << endl;
        return;
    }
    vector<int> res(3);
    res[0] = n+1;
    res[1] = n - (n-r-1) + n - (n-r-1);
    res[2] = n - l + n - l;
    sort(res.begin(), res.end());
    cout << res[2] << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
