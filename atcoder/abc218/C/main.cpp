// atcoder/abc218/C/main.cpp
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
char a[N][N];
char b[N][N];
char c[N][N];

bool fn(const int n)
{
  vec<pair<int, int>> p, q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] == '#') p.push_back(make_pair(i, j));
      if (b[i][j] == '#') q.push_back(make_pair(i, j));
    }
  }

  {
    int x, y;
    x = y = (1 << 29);
    each (i, p) {
      setmin(x, i.first);
      setmin(y, i.second);
    }
    each (i, p) {
      i.first -= x;
      i.second -= y;
    }
  }
  {
    int x, y;
    x = y = (1 << 29);
    each (i, q) {
      setmin(x, i.first);
      setmin(y, i.second);
    }
    each (i, q) {
      i.first -= x;
      i.second -= y;
    }
  }
  sort(p.begin(), p.end());
  sort(q.begin(), q.end());
  return p == q;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> b[i][j];
      }
    }

    bool f = false;
    for (int _ = 0; _ < 4; ++_) {
      f = f || fn(n);
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          c[i][j] = b[n - j - 1][i];
        }
      }
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          b[i][j] = c[i][j];
        }
      }
    }
    cout << (f ? "Yes" : "No") << endl;
  }

  return 0;
}
