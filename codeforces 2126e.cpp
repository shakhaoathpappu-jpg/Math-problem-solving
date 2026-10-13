#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) 
{
    return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) 
{
    return a / gcd(a, b) * b;
}

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ll> a(n + 1), b(n + 1), c(n + 1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];
        for(int i = 1; i <= n; i++) {
            c[i] = lcm(a[i], b[i]);
        }
        ll pre = 0;
        bool ok = true;
        for(int i = 1; i <= n; i++) {
            pre = gcd(pre, c[i]);
            if(pre != a[i]) {
                ok = false;
                break;
            }
        }
        ll suf = 0;
        if(ok) {
            for(int i = n; i >= 1; i--) {
                suf = gcd(suf, c[i]);
                if(suf != b[i]) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}