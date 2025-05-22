#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#define Sanic_speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Ret return 0;
#define ret return;
#define all(x) x.begin(), x.end()
#define el "\n";
#define elif else if
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pops pop_back
#define cYES cout << "YES" << "\n";
#define cNO cout << "NO" << "\n";
#define cYes cout << "Yes" << "\n";
#define cNo cout << "No" << "\n";
#define cel cout << "\n";
#define frs(i, a, b) for(int i = a; i < b; ++i)
#define fre(i, a, b) for(int i = a; i <= b; ++i)
#define wh(t) while (t--)
#define SORAI int main()
using namespace std;
typedef unsigned long long ull;

void solve() {
    int n, m, ans = 0;
    cin >> n >> m;
    int task[n];
    int mac[m];
    frs(i, 0, n) { cin >> task[i]; }
    frs(i, 0, m) { mac[i] = 0; }
    sort(task, task + n, greater<int>());
    frs(i, 0, n) {
        int posi = 0;
        frs(j, 1, m) {
            if (mac[j] < mac[posi]) {
                posi = j;
            }
        }
        mac[posi] += task[i];
    }
    frs(i, 0, m) {
        ans = max(ans, mac[i]);
    }
    cout << ans << el
}

SORAI{
    Sanic_speed
    int t = 1;// cin >> t;
    wh(t) { solve(); }
}