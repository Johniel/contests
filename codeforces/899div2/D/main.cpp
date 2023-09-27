// github.com/Johniel/contests
// codeforces/899div2/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (const auto p = make_pair(_i, c.at(_i)); true)
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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

const int N = 2 * 1e5 + 3;
vec<int> g[N];
vec<int> a;
// pair<lli, lli> cost[N];
// lli cost[N];
vec<lli> cost;
// int size[N];
vec<lli> sz;
pair<lli, int> rec1(int curr, int prev)
{
  sz[curr] = 1;
  cost[curr] = 0;
  each (next, g[curr]) {
    if (next == prev) continue;
    auto [c, s] = rec1(next, curr);
    cost[curr] += c;
    sz[curr] += s;
  }
  cost[curr] += (a[curr] ^ a[prev]) * sz[curr];
  return make_pair(cost[curr], sz[curr]);
}

vec<lli> r;
void rec2(int curr, int prev)
{
  if (curr) {
    r[curr] = r[prev];
    // cout << curr+1  << ": " << (a[curr] ^ a[prev]) << "*" << make_pair(sz[curr], r.size() - sz[curr]) << endl;
    r[curr] -= (a[curr] ^ a[prev]) * sz[curr];
    r[curr] += (a[curr] ^ a[prev]) * (r.size() - sz[curr]);
  }
  each (next, g[curr]) {
    if (next == prev) continue;
    rec2(next, curr);
  }
  return ;
}

int main(int argc, char *argv[])
{
  int _;
  cin >> _;

  int n;
  while (cin >> n) {
    cost.resize(n, 0);
    sz.resize(n, 0);
    a.resize(n);
    cin >> a;
    fill(g, g + n, vec<int>());
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    cost.resize(n);
    r.resize(n);
    rec1(0, 0);
    r[0] = cost[0];

    // cout << cost << endl;
    // cout << sz << endl;

    rec2(0, 0);
    each (i, r) cout << i << ' '; cout << endl;
    // cout << endl;
  }

  return 0;
}
