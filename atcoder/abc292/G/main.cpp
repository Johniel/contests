// github.com/Johniel/contests
// atcoder/abc292/G/main.cpp

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
constexpr lli mod = 998244353;

const int N = 40 + 3;
const int A = 10 + 3;
vec<str> v;
lli memo[N][N][N][A];
lli rec(int begin, int end, int nth, const int x)
{
  if (begin == end) return 1;
  if (10 <= x) return 0;
  if (nth == v.front().size()) return begin + 1 == end;

  lli& ret = memo[begin][end][nth][x];
  if (ret != -1) return ret;

  // rec(begin, end, nth, x) := beginからendまでの範囲で上からnth桁目を__x以上に__しつつ単調増加にできるパターン数。

  // この範囲全てx+1
  lli z = rec(begin, end, nth, x + 1);
  for (int i = begin; i < end; ++i) {
    if (v[i][nth] != '?' && v[i][nth] != x + '0') break;
    // beginからi+1までnth桁目が同じx。そのため次の桁以降で大小関係を決める。
    lli a = rec(begin, i + 1, nth + 1, 0);
    // iとi+1でnth桁目を一致させない。i+1以降は独立に決まる。
    lli b = rec(i + 1, end, nth, x + 1);
    //
    (z += a * b % mod) %= mod;
  }
  return ret = z;
}

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    v.resize(n);
    cin >> v;
    fill(&memo[0][0][0][0], &memo[N - 1][N - 1][N - 1][A - 1] + 1, -1);
    cout << rec(0, n, 0, 0) << endl;
  }
  return 0;
}
