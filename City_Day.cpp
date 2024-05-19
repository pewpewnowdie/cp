#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> days(n);
    for(int i = 0; i < n; i++) {
        cin >> days[i];
    }
    vector<bool> left(n, true);
    vector<bool> right(n, true);
    for(int l = 0; l < n; l++) {
        int t = l-1;
        while(t >= 0 && l - t <= x) {
            if(days[l] > days[t]) {
                left[l] = false;
                break;
            }
            t--;
        }
    }
    for(int r = n-1; r >= 0; r--) {
        int t = r+1;
        while(t < n && t - r <= y) {
            if(days[r] > days[t]) {
                right[r] = false;
                break;
            }
            t++;
        }
    }
    for(int i = 0; i < n; i++) {
        if(left[i] == true && right[i] == true) {
            cout << i+1 << endl;
            return;
        }
    }
}

int main() {
    solve();
    return 0;
}
