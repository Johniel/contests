// github.com/Johniel/contests
// atcoder/abc281/F/main.cpp

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
template<typename T> using heap = priority_queue<T>;

lli mod;

namespace math {
  const int N = 500 + 3;
  lli nck[N][N];
  void init(void)
  {
    fill(&nck[0][0], &nck[N - 1][N - 1] + 1, 0);
    nck[0][0] = 1;
    for (int i = 0; i + 1 < N; ++i) {
      for (int j = 0; j < i + 1; ++j) {
        (nck[i + 1][j] += nck[i][j]) %= mod;
        (nck[i + 1][j + 1] += nck[i][j]) %= mod;
      }
    }
    return ;
  }
};

namespace math {
  lli mod_pow(lli n, lli p, lli M = mod)
  {
    if (p == 0) return 1;
    if (p == 1) return n % M;
    lli m = mod_pow(n, p / 2, M);
    m *= m;
    m %= M;
    if (p % 2) m = (m * n) % M;
    return m;
  }
};

const int N = 500 + 3;
const int M = N * N;
lli p2[M];

lli memo[N][N];
lli rec(int remained, int prev)
{
  if (remained == 0) return (p2[prev] - 1 + mod) % mod;

  lli& ret = memo[remained][prev];
  if (ret != -1) return ret;

  lli z = 0;
  for (int i = 1; i <= remained; ++i) {
    // 同じ距離同士の頂点間に辺を作る
    lli a = p2[(i - 1) * i / 2];
    // 距離が1つ近い頂点との間に辺を作る。
    // 直前がprev個だとして、そのうち少なくとも１つとは辺を作らなければならない。
    // nC1 + nC2 + nC3 + ... + nCn
    // nC0 + ... + nCnは2^nだから(2^n)-nになるはず。これがi頂点分あるのでi乗する。
    lli b = math::mod_pow((p2[prev] - 1 + mod) % mod, i);
    // iを選ぶ方法はnCk。
    lli c = math::nck[remained][i];

    lli x = (((a * b) % mod) * c) % mod;
    lli y = rec(remained - i, i);
    // cout << make_pair(remained, prev) << ' ' << i << ' ' << vec<lli>({a, b, c}) << ' ' << endl;
    (z += x * y % mod) %= mod;
  }
  return ret = z;
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n >> mod) {
    math::init();
    p2[0] = 1; for (int i = 1; i < M; ++i) p2[i] = (p2[i - 1] * 2) % mod;
    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, - 1);
    cout << rec(n - 2, 1) << endl;
  }
  return 0;
}
