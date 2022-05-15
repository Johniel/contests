// atcoder/abc218/G/main.cpp
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

vec<lli> a;
vec<int> freq;
const int N = 2 * 1e5 + 3;
vec<int> g[N];

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<typename T>
class ordered_set : public tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> {};

ordered_set<pair<lli, int>> vis;
lli rec(int curr, int prev, int turn = 0)
{
  vis.insert(make_pair(a[curr], freq[curr]));
  lli best = (vis.find_by_order(vis.size() / 2)->first + vis.find_by_order((vis.size() - 1) / 2)->first) / 2;
  if ((curr != 0 && g[curr].size() == 1) || g[curr].empty()) {
    vis.erase(make_pair(a[curr], freq[curr]));
    return best;
  }
  const lli inf = 1LL << 60;
  if (turn % 2) {
    best = +inf;
    each (next, g[curr]) {
      if (next == prev) continue;
      setmin(best, rec(next, curr, turn + 1));
    }
  } else {
    best = -inf;
    each (next, g[curr]) {
      if (next == prev) continue;
      setmax(best, rec(next, curr, turn + 1));
    }
  }
  vis.erase(make_pair(a[curr], freq[curr]));
  return best;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    a.resize(n);
    cin >> a;
    freq.resize(n, 0);
    map<lli, int> m;
    for (int i = 0; i < a.size(); ++i) {
      freq[i] = m[a[i]]++;
    }
    fill(g, g + N, vec<int>());
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    vis.clear();
    cout << rec(0, 0) << endl;
  }

  return 0;
}
