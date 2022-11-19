// github.com/Johniel/contests
// atcoder/abc278/F/main.cpp

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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

vec<str> v;
const int N = 17;
const int M = 1 << N;
int memo[M][N];
int rec(int bit, int x)
{
  int& ret = memo[bit][x];
  if (ret != -1) return ret;
  int mx = 0;
  if (x == N - 1) {
    for (int i = 0; i < v.size(); ++i) {
      setmax(mx, rec(1 << i, i) ^ 1);
    }
  } else {
    for (int i = 0; i < v.size(); ++i) {
      if (bit & (1 << i)) continue;
      if (v[x].back() == v[i].front()) {
        setmax(mx, rec(bit | (1 << i), i) ^ 1);
      }
    }
  }
  return ret = mx;
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    v.resize(n);
    cin >> v;
    fill(&memo[0][0], &memo[M - 1][N], -1);
    cout << (rec(0, N - 1) ? "First" : "Second") << endl;
  }
  return 0;
}
