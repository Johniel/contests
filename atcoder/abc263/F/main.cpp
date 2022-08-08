// atcoder/abc263/F/main.cpp
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

const int M = 17;
const int N = (1 << M);
int g[N][M];
map<pair<pair<int, int>, int>, lli> memo;
map<pair<int, int>, lli> memo2;
lli rec(const int begin, const int end, const int won, const int R)
{
  const pair<pair<int, int>, int> key = {{begin, end}, won};
  const pair<int, int> key2 = {begin, end};
  if (memo.count(key)) return memo[key];
  if (memo2.count(key2)) return memo2[key2];
  if (begin + 1 == end) return 0;

  const int mid = begin + (end - begin) / 2;
  lli mx = 0;

  if (won == N - 1) {
    for (int k = begin; k < end; ++k) {
      setmax(mx, rec(begin, end, k, R) + g[k][R + 1]);
    }
    return memo2[key2] = mx;
  } else if (begin <= won && won < mid) {
    const int i = won;
    mx = rec(begin, mid, i, R - 1) + rec(mid, end, (N - 1), R - 1);
  } else if (mid <= won && won < end) {
    const int j = won;
    mx = rec(begin, mid, (N - 1), R - 1) + rec(mid, end, j, R - 1);
  }
  return memo[key] = mx;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    for (int i = 0; i < (1 << n); ++i) {
      g[i][0] = 0;
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j + 1];
      }
    }
    memo.clear();
    memo2.clear();
    cout << rec(0, (1 << n), (N - 1), n - 1) << endl;
  }

  return 0;
}
