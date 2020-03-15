// codeforces/628div2/C/main.cpp
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

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

int di[] = {0, 1, -1, 0, 1, -1, 1, -1};
int dj[] = {1, 0, 0, -1, 1, -1, -1, 1};
constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    const int N = 1e5 + 5;
    static vector<int> g[N];
    fill(g, g + N, vec<int>());

    map<pair<int, int>, int> idx;

    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
      idx[make_pair(a, b)] = i;
      idx[make_pair(b, a)] = i;
    }

    int x = 0;
    for (int i = 0; i < n; ++i) {
      if (g[x].size() < g[i].size()) {
        x = i;
      }
    }

    if (g[x].size() <= 2) {
      for (int i = 0; i < n - 1; ++i) {
        cout << i << endl;
      }
    } else {
      int cnt = 0;
      set<pair<int, int>> vis;
      map<int, int> m;
      each (y, g[x]) {
        pair<int, int> p = make_pair(x, y);
        pair<int, int> q = make_pair(y, x);
        vis.insert(p);
        vis.insert(q);
        m[idx[p]] = cnt++;
      }
      for (int i = 0; i < N; ++i) {
        each (j, g[i]) {
          pair<int, int> p = make_pair(i, j);
          pair<int, int> q = make_pair(j, i);
          if (!vis.count(p)) {
            vis.insert(p);
            vis.insert(q);
            m[idx[p]] = cnt++;
          }
        }
      }
      for (int i = 0; i < n - 1; ++i) {
        cout << m[i] << endl;
      }
    }
    // cout << endl;
  }

  return 0;
}
