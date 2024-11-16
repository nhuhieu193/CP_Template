#include <bits/stdc++.h>
#define f(i,a,b) for (int i=a;i<=b;i++)
#define int long long
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxn = 103;

int a[maxn],f[maxn][100005],n,m;
int W;
pii b[maxn];
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>W;
    f(i,1,n) cin>>b[i].F>>b[i].S;
    f(j,1,W) f(i,1,n) {
        if (j>= b[i].F) f[i][j] = max(f[i-1][j] , f[i-1][j-b[i].F] + b[i].S);else f[i][j] = f[i-1][j];
    }

//    f(i,1,n) {f(j,1,W) cout<<f[i-1][j-b[i].F] + b[i].S<<" ";cout<<endl;}

    cout<<f[n][W];
    return 0;

}

