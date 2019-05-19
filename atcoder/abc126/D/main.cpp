// atcoder/abc126/D/main.cpp
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
vector<pair<int, int>> g[N];

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    fill(g, g + N, vector<pair<int, int>>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].push_back({b, c % 2});
      g[b].push_back({a, c % 2});
    }

    map<int, int> color;
    function<void(int, int, int)> rec = [&] (int curr, int prev, int x) {
      color[curr] = x;
      each (e, g[curr]) {
        int next = e.first;
        if (next == prev) continue;
        rec(next, curr, x ^ e.second);
      }
      return ;
    };
    rec(0, -1, 0);

    for (int i = 0; i < n; ++i) {
      cout << color[i] << endl;
    }
  }

  return 0;
}
