#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, a[400005], se[400005], so[400005];

int main() 
{
    int t; cin >> t;
    while(t--) {
        cin >> n;
        n *= 2;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 2; i <= n; i += 2) {
            so[i] = so[i - 2] + a[i] - a[i - 1];
        }
        for(int i = 3; i <= n; i += 2) {
            se[i] = se[i - 2] + a[i] - a[i - 1];
        }
        for(int i = 2; i <= n; i += 2) se[i] = se[i - 1];

        for(int i = 3; i <= n; i += 2) so[i] = so[i - 1];
        ll ans = -so[n];
        for(int i = 1; i <= n / 2; i++) {
            if(i % 2 == 1) ans += 2 * (so[n - i + 1] - so[i]);
            else ans += 2 * (se[n - i + 1] - se[i]);
            cout << ans << " ";
        }
        cout << endl;
    }
}