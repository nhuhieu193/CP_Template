#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN = 1e5 + 1;

int n, x;
int P[maxN], L[maxN], R[maxN], Size[maxN], root;

void SetChild(int Parent, int Child, bool InRight)
{
    P[Child] = Parent;
    if (InRight) R[Parent] = Child;
    else L[Parent] = Child;
}

void Init()
{
    fill(P, P + n + 1, 0);
    fill(L, L + n + 1, 0);
    fill(R, R + n + 1, 0);
    for (int i = 1; i <= n; ++i)
        SetChild(i, i - 1, false);
    for (int i = 0; i <= n; ++i)
        Size[i] = i;
    root = n;
}

void Print(int x)
{
    if (x == 0) return;
    Print(L[x]);
    cout << x << ' ';
    Print(R[x]);
}

//TĆ¬m nĆŗt thį»© i trong cĆ¢y gį»‘c T
int Locate(int T, int i)
{
    while (true)
    {
        int s = Size[L[T]]; //KĆ­ch thĘ°į»›c con trĆ�i
        if (s + 1 == i) return T;
        if (s + 1 > i)
            T = L[T];
        else
        {
            i -= s + 1;
            T = R[T];
        }
    }
}

void Update(int x)
{
    Size[x] = Size[L[x]] + Size[R[x]] + 1;
}

void UpTree(int x)
{
    int y = P[x], z = P[y];
    if (x == R[y])
    {
        int b = L[x];
        SetChild(y, b, true);
        SetChild(x, y, false);
    }
    else
    {
        int b = R[x];
        SetChild(y, b, false);
        SetChild(x, y, true);
    }
    SetChild(z, x, R[z] == y);
    Update(y);
    Update(x);
}

/*
//Äįŗ©y nĆŗt x lĆŖn lĆ m gį»‘c cĆ¢y
void MoveToRoot(int x)
{
    while (P[x] != 0) UpTree(x);
}
*/

//Äįŗ©y nĆŗt x lĆŖn lĆ m gį»‘c cĆ¢y
void MoveToRoot(int x)
{
    while (true)
    {
        int y = P[x];
        if (y == 0) break;
        int z = P[y];
        if (z != 0)
        {
            if ((R[z] == y) == (R[y] == x)) UpTree(y);
            else UpTree(x);
        }
        UpTree(x);
    }
}

void Split(int T, int& A, int& B, int i)
{
    if (i == 0)
    {
        A = 0; B = T; return;
    }
    int x = Locate(T, i);
    MoveToRoot(x);
    A = x;
    B = R[x];
    R[A] = 0;
    P[B] = 0;
    Update(A);
}

int Join(int A, int B)
{
    if (A == 0) return B;
    while (R[A] != 0) A = R[A];
    MoveToRoot(A);
    SetChild(A, B, true);
    Update(A);
    return A;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("CARDS.INP", "r", stdin);
    freopen("CARDS.OUT", "w", stdout);
    cin >> n >> x;
    Init();
    while (x-- > 0)
    {
        int i, m, j;
        cin >> i >> m >> j;
        int A, B, C;
        Split(root, A, B, i - 1);
        Split(B, B, C, m);
        root = Join(A, C);
        Split(root, A, C, j - 1);
        root = Join(Join(A, B), C);
    }
    Print(root);
}
