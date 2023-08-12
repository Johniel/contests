// github.com/Johniel/contests
// atcoder/abc314/E/main.cpp

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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

const int N = 100 + 3;
const int M = 100 + 3;
const int C = 1000 + 3;

vec<double> c;
vec<vec<int>> v;
int n, m;
const int K = C * M;
double memo[M];
double rec(int point)
{
  if (m <= point) return 0;
  double& ret = memo[point];
  if (0 <= ret) return ret;

  // cout << point << ' ' << ret << endl;

  double mn = 1e128;
  for (int i = 0; i < n; ++i) {
    const double p = v[i].size();
    const double z = count(v[i].begin(), v[i].end(), 0);
    double x = 0;
    for (int j = 0; j < v[i].size(); ++j) {
      if (v[i][j] == 0) continue;
      x += rec(point + v[i][j]);
    }
    x = (x + p * c[i]) / (p - z);
    setmin(mn, x);
  }
  return ret = mn;
}

int main(int argc, char *argv[])
{
  while (cin >> n >> m) {
    c.resize(n);
    v.resize(n);
    for (int i = 0; i < n; ++i) {
      int p;
      cin >> c[i] >> p;
      v[i].resize(p);
      cin >> v[i];
    }
    fill(&memo[0], &memo[M - 1] + 1, -1);
    cout << rec(0) << endl;
  }
  return 0;
}
