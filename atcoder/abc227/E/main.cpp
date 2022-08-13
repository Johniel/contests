// https://github.com/johniel/atcoder/abc227/E/main.cpp

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

// const int N = 50;
// const int M = N * N / 2;
// lli memo[N][N][N][M];
vec<vec<vec<vec<lli>>>> memo;
vec<int> a, b, c;
int L;
lli rec(int k, int e, int y, int s)
{
  if (L < s) return 0;
  lli& ret = memo[k][e][y][s];
  if (ret != -1) return ret;
  if (k == a.size() && e == b.size() && y == c.size()) return 1;

  auto fn = [&] (int x) {
    int t = 0;
    t += lower_bound(a.begin() + k, a.end(), x) - (a.begin() + k);
    t += lower_bound(b.begin() + e, b.end(), x) - (b.begin() + e);
    t += lower_bound(c.begin() + y, c.end(), x) - (c.begin() + y);
    return t;
  };

  lli z = 0;
  if (k < a.size()) z += rec(k + 1, e, y, s + fn(a[k]));
  if (e < b.size()) z += rec(k, e + 1, y, s + fn(b[e]));
  if (y < c.size()) z += rec(k, e, y + 1, s + fn(c[y]));
  return ret = z;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  str s;
  while (cin >> s >> L) {
    const int K = count(s.begin(), s.end(), 'K');
    const int E = count(s.begin(), s.end(), 'E');
    const int Y = count(s.begin(), s.end(), 'Y');
    const int M = s.size() * s.size() / 2;
    memo = vec<vec<vec<vec<lli>>>>(K + 1, vec<vec<vec<lli>>>(E + 1, vec<vec<lli>>(Y + 1, vec<lli>(M + 1, -1))));

    a = b = c = vec<int>();
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'K') a.push_back(i);
      if (s[i] == 'E') b.push_back(i);
      if (s[i] == 'Y') c.push_back(i);
    }
    // fill(&memo[0][0][0][0], &memo[N - 1][N - 1][N - 1][M - 1] + 1, -1);
    cout << rec(0, 0, 0, 0) << endl;
  }

  return 0;
}
