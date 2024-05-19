#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    bool flag = true;
    string s(m, '#');
    string s2(m-1, '.');
    cout << s << endl;
    n--;
    while(n) {
        if(flag) {
            cout << s2 << '#' << endl;
        } else {
            cout << '#' << s2 << endl;
        }
        n -= 2;
        flag = !flag;
        cout << s << endl;
    }
}

int main() {
    solve();
    return 0;
}
