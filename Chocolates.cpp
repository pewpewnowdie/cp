#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int currMin = arr[n-1];
    long long sum = arr[n-1];
    for(int i = n-2; i >= 0; i--) {
        if(arr[i] < currMin) {
            currMin = arr[i];
            sum += arr[i];
        } else {
            if(currMin <= 1) break;
            sum += currMin-1;
            currMin--;
        }
    }
    cout << sum;
}

int main () {
    solve();
    return 0;
}
