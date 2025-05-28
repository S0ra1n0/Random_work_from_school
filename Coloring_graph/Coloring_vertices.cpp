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
    int color = 0, n, m, alt1, alt2;
    cin >> n >> m;
    int a[n], rank[n];
    bool visit[n];
    frs(i, 0, n) {a[i] = -1; visit[i] = 1; rank[i] = 0;}
    vector<vector<int>> vertex(n);
    frs(i, 0, m) {
        cin >> alt1 >> alt2;
        ++rank[alt1];
        ++rank[alt2];
        vertex[alt1].pb(alt2);
        vertex[alt2].pb(alt1);
    }
    cout << "Vertex's rank: " << el
    frs(i, 0, n) {
        cout << rank[i] << " ";
    }
    cel
    //executing
    int checking = -1;
    do {
        checking = -1;
        int posi = -1;
        frs(i, 0, n) {
            if (visit[i] == 1) {
                if (rank[i] > checking) {
                    checking = rank[i];
                    posi = i;
                }
            }
        }
        if (checking == -1) {break;}
        vector<int> temp;
        for (int i = 0; i < vertex[posi].size(); ++i) {
            if (visit[vertex[posi][i]] == 0) {
                temp.pb(a[vertex[posi][i]]);
            }
        }
        if (temp.size() == 0) {
            a[posi] = 0;
            if (color == 0) {++color;}
        } else {
            sort(all(temp));
            int sce = 0, step = 0;
            for (int i = 0; i < temp.size(); ++i) {
                if (i > 0) {
                    if (temp[i] == temp[i-1]) {continue;}
                }
                if (temp[i] != step) {
                    a[posi] = step;
                    sce = 1;
                    break;
                } else {++step;}
            }
            if (sce == 0) {a[posi] = step; if (step == color) {++color;}}
        }
        frs(i, 0, rank[posi]) {
            --rank[vertex[posi][i]];
        }
        rank[posi] = -1;
        visit[posi] = 0;
    } while (checking != -1);
    //result
    cout << "Color: "
    cout << color << el
    frs(i, 0, n) {
        cout << a[i] << " ";
    }
}

SORAI {
    Sanic_speed
    int t = 1;// cin >> t;
    wh(t) {solve();}
}
