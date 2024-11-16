#include <bits/stdc++.h>
#define f(i,a,b) for (int i=a;i<=b;i++)
#define int long long
#define pii pair<int,int>
using namespace std;

const int maxn = 300005;

int n,m,a[maxn],b[maxn],z[maxn];

void tinh_z(){
    int L=0,R=0;
    f(i,2,n) {
        int x=0;
        if (i<R) {x = min (z[i-L+1],R-i+1);}
        while (i+x <=n && b[i+x] == b[x+1]) x++;
        z[i] = x;
        if (R < i+x-1) {
            L=i;
            R= i+x-1;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    f(i,1,n) cin>>b[i];
    tinh_z();
    int re=1e9;
    f(i,1,n) if (z[i+1] == n-i) re = min(re,n-z[i+1]);
    cout<<re<<endl;
//    cout<<n-*max_element(z+1,z+1+n);

    return 0;
}
