// yukicoder/1995/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

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
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  while (cin >> n >> m) {
    vec<pair<int, int>> v(m);
    cin >> v;

    map<int, int> idx;
    int cnt = 0;
    idx[1] = cnt++;
    idx[n] = cnt++;
    each (i, v) {
      unless (idx.count(i.first)) idx[i.first] = cnt++;
      unless (idx.count(i.second)) idx[i.second] = cnt++;
    }

    const int N = cnt;
    vec<pair<int, int>> g[N];
    each (i, v) {
      int a = idx[i.first];
      int b = idx[i.second];
      int c = 2 * (i.second - i.first) - 1;
      g[a].push_back({b, c});
    }
    vec<int> u;
    each (i, idx) u.push_back(i.first);
    sort(u.begin(), u.end());
    for (int i = 0; i + 1 < u.size(); ++i) {
      int a = idx[u[i]];
      int b = idx[u[i + 1]];
      int c = (u[i + 1] - u[i]) * 2;
      g[a].push_back({b, c});
    }

    map<int, int> cost;
    each (i, idx) cost[i.second] = n * 2;

    priority_queue<pair<int, int>> q;
    q.push({0, idx[1]});
    cost[idx[1]] = 0;
    while (q.size()) {
      auto p = q.top();
      q.pop();
      if (cost[p.second] != abs(p.first)) continue;
      each (e, g[p.second]) {
        int c = abs(p.first) + e.second;
        if (cost[e.first] > c) {
          cost[e.first] = c;
          q.push({-c, e.first});
        }
      }
    }
    cout << cost[idx[n]] << endl;
  }

  return 0;
}
