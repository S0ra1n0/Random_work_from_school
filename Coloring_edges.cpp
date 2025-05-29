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
    int v, e, color = 0;
    cin >> v >> e;
    vector<pair<int, int>> edge(e); //Vertices of edge
    vector<int> ecolor(e, -1); //Color for that edge
    vector<vector<int>> link(v); //Storing the vertices that 1 is linked to
    vector<vector<int>> vcolor(v); // Colored edge(s) of that vertex
    int rank[v];
    int origin_rank[v];
    fill_n(rank, v, 0);
    frs(i, 0, e) {
        cin >> edge[i].fi >> edge[i].se;
        ++rank[edge[i].fi];
        ++rank[edge[i].se];
        link[edge[i].fi].pb(edge[i].se);
        link[edge[i].se].pb(edge[i].fi);
    }
    frs(i, 0, v) {
        sort(all(link[i]));
        origin_rank[i] = rank[i];
    }
    int checking;
    while (true) {
        checking = -1;
        int posi;
        frs(i, 0, v) {
            if (rank[i] > checking) {
                checking = rank[i];
                posi = i;
            }
        }
        if (checking == -1) {break;}
        elif (checking == 0) {rank[posi] = -1; continue;}
        for (int i = 0; i < origin_rank[posi]; ++i) {
            if (rank[link[posi][i]] == -1) {continue;}
            vector<int> t_color;
            int step = 0;
            int situ = 0;
            frs(j, 0, vcolor[posi].size()) {
                t_color.pb(vcolor[posi][j]);
            }
            frs(j, 0, vcolor[link[posi][i]].size()) {
                t_color.pb(vcolor[link[posi][i]][j]);
            }
            if (t_color.empty()) {
                vcolor[posi].pb(0);
                vcolor[link[posi][i]].pb(0);
                if (color == 0) {++color;}
                frs(j, 0, e) {
                    if (edge[j].fi == posi && edge[j].se == link[posi][i]) {
                        ecolor[j] = 0;
                        break;
                    } elif (edge[j].fi == link[posi][i] && edge[j].se == posi) {
                        ecolor[j] = 0;
                        break;
                    }
                }
                continue;
            }
            sort(all(t_color));
            for (int j = 0; j < t_color.size(); ++j) {
                if (j > 0) {
                    if (t_color[j] == t_color[j-1]) {continue;}
                }
                if (t_color[j] > step) {
                    situ = 1;
                    break;
                }
                ++step;
            }
            if (situ == 0) {
                vcolor[posi].pb(step);
                vcolor[link[posi][i]].pb(step);
                frs(j, 0, e) {
                    if (edge[j].fi == posi && edge[j].se == link[posi][i]) {
                        ecolor[j] = step;
                        break;
                    } elif (edge[j].fi == link[posi][i] && edge[j].se == posi) {
                        ecolor[j] = step;
                        break;
                    }
                }
                if (step == color) {
                    ++color;
                }
            } else {
                vcolor[posi].pb(step);
                vcolor[link[posi][i]].pb(step);
                frs(j, 0, e) {
                    if (edge[j].fi == posi && edge[j].se == link[posi][i]) {
                        ecolor[j] = step;
                        break;
                    } elif (edge[j].fi == link[posi][i] && edge[j].se == posi) {
                        ecolor[j] = step;
                        break;
                    }
                }
            }
        }
        frs(i, 0, rank[posi]) {
            --rank[link[posi][i]];
        }
        rank[posi] = -1;
    }
    cout << "Minimum color for all edges: " << color << el
    frs(i, 0, e) {
        cout << "Color of edge (" << edge[i].fi << ", " << edge[i].se << "): " << ecolor[i] << el
    }
}

SORAI {
    Sanic_speed
    int t = 1; //cin >> t;
    wh(t) {solve();}
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
