// atcoder/typical90/019/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

const int N = 200 + 3;
lli memo[N][N];
vec<lli> a;
lli rec(int begin, int end)
{
  lli& ret = memo[begin][end];
  if ((end - begin) % 2) return 1LL << 60;
  if (ret != -1) return ret;
  if (begin == end) return ret = 0;

  lli mn = 1LL << 60;
  for (int i = begin; i < end; ++i) {
    for (int j = i + 1; j < end; ++j) {
      setmin(mn, abs(a[i] - a[j]) + rec(begin, i) + rec(i + 1, j) + rec(j + 1, end));
    }
  }

  return ret = mn;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    n *= 2;
    a.resize(n);
    cin >> a;
    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, -1);
    cout << rec(0, n) << endl;
  }

  return 0;
}
