// github.com/Johniel/contests
// atcoder/abc319/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
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

const int N = 1e5;
const int M = 8 * 7 * 5 * 3;
lli memo[N][M];
vec<pair<int, lli>> bus;
int n;
inline lli rec(int curr, int m)
{
  if (curr == n - 1) return 0;

  lli& ret = memo[curr][m];
  if (ret != -1) return ret;

  if (m % bus[curr].first == 0) {
    return ret = rec(curr + 1, (m + bus[curr].second) % M) + bus[curr].second;
  } else {
    lli x = (m / bus[curr].first + 1) * bus[curr].first;
    return ret = rec(curr + 1, (x + bus[curr].second) % M) + bus[curr].second + (x - m);
  }
}

int main(int argc, char *argv[])
{
  // int n;
  lli x, y;
  while (cin >> n >> x >> y) {
    bus.resize(n - 1);
    cin >> bus;
    // fill(&memo[0][0], &memo[N - 1][M - 1] + 1, -1);

    static lli z[M];
    fill(z, z + M, x + y);
    for (int k = 0; k < M; ++k) {
      lli t = (k + x) % M;
      for (int i = 0; i < bus.size(); ++i) {
        lli nt = (t + bus[i].first - 1) / bus[i].first * bus[i].first;
        z[k] += (nt - t) + bus[i].second;
        t = (nt + bus[i].second) % M;
      }
    }

    int q;
    cin >> q;
    while (q--) {
      // lli z; cin >> z; cout << z + rec(0, (z + x) % M) + x + y << endl;
      lli a; cin >> a; cout << a + z[a % M] << endl;
    }
  }
  return 0;
}
