// atcoder/abc146/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

const int N = 1e5 + 5;
vector<int> g[N];
int color[N];

map<pair<int, int>, int> idx;

int rec(int curr, int prev)
{
  int c = 0;
  each (next, g[curr]) {
    if (next == prev) continue;
    int a = idx[make_pair(curr, next)];
    int b = idx[make_pair(next, curr)];
    if (color[idx[make_pair(curr, prev)]] == c) ++c;
    color[a] = color[b] = c++;
    rec(next, curr);
  }
  return 0;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    fill(g, g + N, vector<int>());
    fill(color, color + N, -(1 << 29));
    vector<pair<int, int>> v;
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      pair<int, int> e = {a, b};
      pair<int, int> r = {b, a};
      v.push_back(e);
      idx[e] = idx[r] = i;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    // int root = 0;
    // for (int i = 0; i < N; ++i) {
    //   if (g[root].size() < g[i].size()) {
    //     root = i;
    //   }
    // }
    color[idx[make_pair(0, -1)] = N - 1] = 1 << 29;
    rec(0, -1);
    cout << *max_element(color, color + n) + 1 << endl;
    each (i, v) cout << color[idx[i]] + 1 << endl;
    // cout << endl;
  }

  return 0;
}
