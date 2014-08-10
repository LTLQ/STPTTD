#include <stdio.h>
#include <iostream>
using namespace std;
typedef unsigned long long ll;

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

const int mod = 1000000007;

int main() {
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int n;
    while(scanf("%d", &n) != EOF) {
        if(n == 1) {
            printf("1\n");
            continue;
        }
        int l = (n + 1) / 3;
        if(3*l == n) {
            cout << mod_pow(3, l, mod) << endl;
        } else if(3 * l + 1 == n) {
            cout << mod_pow(3, l - 1, mod) * 4 << endl;
        } else {
            cout << mod_pow(3, l - 1, mod) * 2 << endl;
        }
    }
    return 0;
}
