// github.com/Johniel/contests
// atcoder/abc267/F/main.cpp

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
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

const int N = 2* 1e5 + 3;
vec<int> g[N];
int cost[N];

void rec(int curr, int prev)
{
  if (curr != prev) {
    cost[curr] = cost[prev] + 1;
  }
  each (next, g[curr]) {
    if (next != prev) rec(next, curr);
  }
  return ;
}

map<int, vec<int>> m;
map<pair<int, int>, int> r;
vec<int> path;

void fn(int curr, int prev)
{
  path.push_back(curr);
  each (i, m[curr]) {
    int j = (int)path.size() - i - 1;
    if (0 <= j && j < path.size()) {
      r[make_pair(curr, i)] = path.at(j);
    }
  }

  each (next, g[curr]) {
    if (next != prev) fn(next, curr);
  }

  path.pop_back();
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, q;
  while (cin >> n) {
    fill(g, g + N, vec<int>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vec<pair<int, int>> v;
    m.clear();
    cin >> q;
    while (q--) {
      int a, k;
      cin >> a >> k;
      --a;
      m[a].push_back(k);
      v.push_back({a, k});
      r[make_pair(a, k)] = -2;
    }
    cost[0] = 0;
    rec(0, 0);
    int x = max_element(cost, cost + n) - cost;
    cost[x] = 0;
    rec(x, x);
    int y = max_element(cost, cost + n) - cost;
    fn(x, x);
    fn(y, y);
    each (i, v) {
      assert(r.count(i));
      cout << r[i]+1 << endl;
    }
  }
  return 0;
}
