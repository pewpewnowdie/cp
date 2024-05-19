#include <bits/stdc++.h>
using namespace std;

void solve() {
    int num;
    cin >> num;
    vector<int> res;
    int pos = 0;
    while(num) {
        int d = num%10;
        int no = d * (int) pow(10,pos);
        if (d) res.push_back(no);
        pos++;
        num /= 10;
    }
    cout << res.size() << endl;
    for(auto itr : res) {
        cout << itr << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
