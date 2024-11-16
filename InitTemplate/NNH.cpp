#include <bits/stdc++.h>
#define f(i,a,b) for(int i = a;i <= b;++i)
//#define int long long
#define ll long long
#define pii pair<int,int>
#define piii pair<int , pii>
#define piiii pair <pii , pii>
#define F first
#define S second
#define task "BITSTR"
#define mod 1000000007
#define endl '\n'
#define minimize(x,y) x = (x > y ? y : x)
#define maximize(x,y) x = (x < y ? y : x)
using namespace std;
const int maxn = 500005;

int gcd(int x , int y) {
    return y ? gcd  (y , x % y) : x;
}

string Y = "YES\n" , N = "NO\n" , Al = "Alice\n" , Bo = "Bob\n";

ll POWW(ll t , ll x) {
    if (x == 0) return 1;
    ll B = POWW(t , x / 2);
    ll C = B * B % mod;
    if (x & 1) C = C * t % mod;
    return C;
}

int n,m,k;

/// Author : CBN_K28_nhuhieu193

/// welcome to my amazing code !!!


void process() {

}

/// This is end of my solution.

int32_t main() {
    ios_base::sync_with_stdio(false);
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);
    cin.tie(0);
    int ntest = 1;
//    cin >> ntest;
    while (ntest--) {
        process();
    }
}
