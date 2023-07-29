// github.com/Johniel/contests
// codeforces/888div3/E/main.cpp

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

template<typename T> vector<T>& operator -- (vector<T> &v) { for (auto& i: v) --i; return v; }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

const int N = 2 * 1e5;
// vec<int> g[N];
vec<vec<int>> g;
vec<lli> cost;
// lli memo[N];
vec<lli> memo;
lli rec(int curr)
{
  lli& ret = memo.at(curr);
  if (ret != -1) return ret;
  if (g[curr].empty()) return ret = cost[curr];
  lli sum = 0;
  each (next, g[curr]) {
    sum += min(rec(next), cost[next]);
  }
  return ret = min(sum, cost[curr]);
}

int main(int argc, char *argv[])
{
  int _;
  cin >> _;

  int n, k;
  while (cin >> n >> k) {
    // fill(g, g + N, vec<int>());
    g.resize(N, vec<int>({}));
    cost.resize(n);
    cin >> cost;
    for (int i = 0; i < k; ++i) {
      int x;
      cin >> x;
      cost[x - 1] = 0;
    }
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      g[i].resize(x);
      cin >> g[i];
      --g[i];
    }
    // fill(memo, memo + N, -1);
    memo.resize(N);
    fill(memo.begin(), memo.end(), -1);
    for (int i = 0; i < n; ++i) {
      cout << rec(i) << ' ';
    }
    cout << endl;
  }
  return 0;
}
