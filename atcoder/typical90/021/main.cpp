// atcoder/typical90/021/main.cpp
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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

namespace {
  // https://atcoder.jp/contests/typical90/tasks/typical90_u

  const int N = 1e5 + 3;
  bool vis[N];

  void rec(vec<int> graph[N], int curr, int ord[], int &cnt)
  {
    vis[curr] = true;
    for (auto& next : graph[curr]) {
      unless (vis[next]) rec(graph, next, ord, cnt);
    }
    ord[--cnt] = curr;
    return ;
  }

  vector<int> g[N];
  vector<int> h[N];
  void init(const int size)
  {
    fill(g, g + size, vector<int>());
  }

  int ord[N];
  int scc[N];
  vector<vector<int>> detect_scc(const int size)
  {
    int cnt, prev = size - 1;
    vector<vector<int>> ret;
    fill(ord, ord + size, -1);
    fill(scc, scc + size, -1);
    fill(h, h + size, vector<int>());
    for (int curr = 0; curr < size; ++curr) {
      for (const auto& next : g[curr]) {
        h[next].push_back(curr);
      }
    }
    cnt = size;
    fill(vis, vis + size, false);
    for (int i = 0; i < size; ++i) {
      unless (vis[i]) rec(g, i, ord, cnt);
    }
    cnt = size;
    fill(vis, vis + size, false);
    for (int i = 0; i < size; ++i) {
      unless (vis[ord[i]]) {
        rec(h, ord[i], scc, cnt);
        int j = prev;
        vector<int> T;
        for (j = prev; 0 <= j && scc[j] != -1; --j) T.push_back(scc[j]);
        prev = j;
        ret.push_back(T);
      }
    }
    return ret;
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  while (cin >> n >> m) {
    init(n);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
    }
    vec<vec<int>> scc = detect_scc(n);
    lli z = 0;
    each (i, scc) {
      lli x = i.size();
      z += x * (x - 1) / 2;
    }
    cout << z << endl;
  }

  return 0;
}
