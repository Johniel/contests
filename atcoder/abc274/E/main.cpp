// github.com/Johniel/contests
// atcoder/abc274/E/main.cpp

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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

const int N = 12 + 1;
const int M = 5;
const int K = N + M + 1;

const int C = 1 << N;
const int T = 1 << M;
double memo[C][T][K];
int n, m;

vec<pair<int, int>> a, b;

double cost(int i, int j)
{
  pair<int, int> src, dst;
  if (i < a.size()) {
    src = a[i];
  } else {
    src = b[i - a.size()];
  }
  if (j < a.size()) {
    dst = a[j];
  } else {
    dst = b[j - a.size()];
  }

  double x = src.first - dst.first;
  double y = src.second - dst.second;

  x *= x;
  y *= y;
  return sqrt(x + y);
}

double rec(int c, int t, int k)
{
  double& ret = memo[c][t][k];
  unless (ret < 0) return ret;

  int w = __builtin_popcount(t);
  double p = (1 << w);

  double mn = 1e128;
  if (c == (1 << n) - 1) {
    mn = cost(k, 0) / p;
  }

  for (int i = 0; i < n; ++i) {
    if (c & (1 << i)) continue;
    int x = i;
    setmin(mn, rec(c | (1 << i), t, x) + cost(k, i) / p);
  }
  for (int i = 0; i < m; ++i) {
    if (t & (1 << i)) continue;
    int x = i + n;
    setmin(mn, rec(c, t | (1 << i), x) + cost(k, x) / p);
  }

  return ret = mn;
}

int main(int argc, char *argv[])
{
  while (cin >> n >> m) {
    a.resize(n);
    b.resize(m);
    cin >> a >> b;
    fill(&memo[0][0][0], &memo[C - 1][T - 1][K - 1] + 1, -1);

    a.insert(a.begin(), make_pair(0, 0));
    ++n;

    cout << rec((1 << 0), 0, 0) << endl;
  }
  return 0;
}
