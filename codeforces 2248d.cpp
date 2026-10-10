#include<bits/stdc++.h>
using namespace std;

int a[200005];
int b[200005];
int c[200005];

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n, q; cin >> n >> q;
        string s, u; cin >> s >> u;
        a[0] = 0;
        b[0] = 0;
        c[0] = 0;
        for(int i = 1; i <= n; i++) {
            a[i] = a[i - 1];
            b[i] = b[i - 1];
            c[i] = c[i - 1];
            if(s[i - 1] == '0' && u[i - 1] == '1') a[i]++;
            if(s[i - 1] == '1' && u[i - 1] == '0') b[i]++;
            if(s[i - 1] == u[i - 1]) c[i]++;
        }
        while (q--) {
            int l, r; cin >> l >> r;
            int x = a[r] - a[l - 1];
            int y = b[r] - b[l - 1];
            int z = c[r] - c[l - 1];
            if(abs(x - y) <= z) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}