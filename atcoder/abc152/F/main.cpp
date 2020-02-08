// atcoder/abc152/F/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }
template<typename P, typename Q> inline pair<Q, P> reverse(pair<P, Q> p) { return make_pair(p.second, p.first); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    const int inf = 1 << 29;
    const int N = 50 + 5;
    vec<int> g[N];

    int idx[N][N];

    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
      idx[a][b] = idx[b][a] = i;
    }

    int m;
    cin >> m;
    vec<pair<int, int>> v(m);
    cin >> v;
    each (i, v) {
      --i.first;
      --i.second;
    }

    static lli b[N][N];
    fill(&b[0][0], &b[N - 1][N - 1] + 1, 0);
    for (int src = 0; src < N; ++src) {
      function<void(int, int)> rec = [&] (int curr, int prev) {
        if (curr != prev) {
          b[src][curr] = b[src][prev] | (1LL << idx[curr][prev]);
        }
        each (next, g[curr]) {
          if (next != prev) rec(next, curr);
        }
        return ;
      };
      rec(src, src);
    }

    lli sum = 0;
    for (int bit = 0; bit < (1 << v.size()); ++bit) {
      lli x = 0;
      for (int i = 0; i < v.size(); ++i) {
        if (bit & (1 << i)) {
          x |= b[v[i].first][v[i].second];
        }
      }
      int y = __builtin_popcountll(bit);
      int z = __builtin_popcountll(x);
      if (y % 2) {
        sum -= (1LL << (n - 1 - z));
      } else {
        sum += (1LL << (n - 1 - z));
      }
    }
    cout << sum << endl;
  }

  return 0;
}
