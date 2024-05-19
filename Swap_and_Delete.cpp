#include <bits/stdc++.h>
using namespace std;

void solve() {
    int arr[] = {0,0};
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        arr[s[i]-'0']++;
    }
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            if(arr[0] == 0) {
                cout << arr[1] << endl;
                return;
            }
            arr[0]--;
        } else {
            if(arr[1] == 0) {
                cout << arr[0] << endl;
                return;
            }
            arr[1]--;
        }
    }
    cout << 0 << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
