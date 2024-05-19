#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int c = n;
    int seven, four;
    while(c >= 0) {
        seven = c/7;
        four = (n-c)/4;
        if(seven*7 + four*4 == n) {
            if(seven && four) {
                string s(seven, '7');
                string f(four, '4');
                cout << f+s;
                return;
            } else if(seven) {
                string s(seven, '7');
                cout << s;
                return;
            } else if(four) {
                string f(four, '4');
                cout << f;
                return;
            }
        }
        c -= 4;
    }
    cout << -1;
}

int main() {
    solve();
    return 0;
}
