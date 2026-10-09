#include<bits/stdc++.h>
using namespace std;
const int N = 300300;
vector<int> p[N];

int main() 
{
    int t; cin >> t;
    for(int i = 2; i < N; i++) {
        if(p[i].empty()) {
            for(int j = i; j < N; j += i) {
                p[j].push_back(i);
            }
        }
    }
    while(t--) {
        int n, x; cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        long long ans = 0;
        for(auto i : p[x]) {
            long long sum = 0;
            for(auto j : a) {
                if(j % i == 0) sum += j;
            }
            ans = max(ans, sum);
        }
        cout << ans << endl;
    }
}