// atcoder/arc111/B/main.cpp
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

const int N = 400000 + 5;
vec<int> g[N];
bool vis[N];

pair<int, bool> rec(int curr, int prev)
{
  vis[curr] = true;
  int sum = 1;
  bool cycle = false;
  each (next, g[curr]) {
    if (next == prev) continue;
    if (vis[next]) {
      cycle = true;
      continue;
    }
    auto p = rec(next, curr);
    sum += p.first;
    cycle |= p.second;
  }
  return {sum, cycle};
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    fill(g, g + N, vec<int>());
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    for (int i = 0; i < N; ++i) {
      sort(g[i].begin(), g[i].end());
      g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
    }

    int x = 0;
    fill(vis, vis + N, false);
    for (int i = 0; i < N; ++i) {
      if (!vis[i]) {
        auto p = rec(i, -1);
        if (p.second) x += p.first;
        else x += p.first - 1;
      }
    }
    cout << x << endl;
  }

  return 0;
}
