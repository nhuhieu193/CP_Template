//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 2000005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define Task "foundstring"

using namespace std;

typedef long long ll;
typedef long double ld;

int T[maxn], n, res = 0;

string s, B;

void KMP(){
    s = "ABACABAB";
       //00101232
    int len = s.length();
    s = " " + s; // danh so tu 1;
    T[1] = 0;
	int k = 0;
    for (int i = 2; i <= len; i++)
    {
		while (k > 0 && s[k+1] != s[i]) k = T[k];
		if (s[k+1] == s[i]) k++;
		T[i] = k;
    }
    for (int i = 1; i <= len; i++) cout << T[i];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
//    freopen(Task".inp", "r", stdin);
//    freopen(Task".out", "w", stdout);
//    cin >> s >> B;
//    n = s.length();
//    s = " " + s + " " + B;
    KMP();
//    cout << res << endl;
//    for (int i = n + 1; i < s.length(); i++)
//        if (T[i] == n) cout << i - n*2 << " ";
    return 0;
}

