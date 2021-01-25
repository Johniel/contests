// codeforces/697div3/F/main.cpp
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

const int N = 1000 + 3;
int a[N][N];
int b[N][N];

bool fn(const int n)
{
  static int f[N];
  fill(f, f + N, false);
  for (int j = 0; j < n; ++j) {
    f[j] = (a[0][j] != b[0][j]);
  }

  for (int i = 0; i < n; ++i) {
    str s, t;
    str r;
    for (int j = 0; j < n; ++j) {
      r += b[i][j] + '0';
      char c = (a[i][j] ^ f[j]);
      s += '0' + c;
      t += '0' + (c ^ 1);
    }
    unless (r == s || r == t) return false;
  }
  return true;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        char c;
        cin >> c;
        a[i][j] = c - '0';
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        char c;
        cin >> c;
        b[i][j] = c - '0';
      }
    }

    bool f = fn(n);
    for (int j = 0; j < n; ++j) {
      a[0][j] ^= 1;
    }
    f = f || fn(n);
    cout << (f ? "yes" : "no") << endl;
  }

  return 0;
}
