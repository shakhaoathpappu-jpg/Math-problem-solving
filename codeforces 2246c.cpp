#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int N = 200005;

ll p[N];

int main() 
{
    p[0] = 1;
    for(int i = 1; i < N; i++) {
        p[i] = p[i - 1] * 2 % mod;
    }
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        int m = 0;
        while(m < n && a[m] == -1) m++;
        ll ans = 1;
        for(int i = m; i < n; ) {
            int j = i;
            while(j < n && a[j] == a[i]) j++;
            ans = ans * p[j - i - 1] % mod;
            i = j;
        }
        int q = 0;
        for(int i = m; i < n - 1; i++) {
            if(a[i + 1] == a[i] + 1) q++;
        }
        ll e, o;
        if(m == 0) {
            e = 1;
            o = 0;
        }
        else e = o = p[m - 1];
        ll res = ans * e % mod;
        res = (res + ans * o % mod * q) % mod;
        cout << res << endl;
    }
}