// codeforces/798div2/D/main.cpp
// author: @___Johniel
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
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

pair<int, int> rot45(int i, int j) {
  return {i - j, i + j};
}

pair<int, int> rot315(int i, int j) {
  return {-i + j, -(i +j)};
  pair<int, int> p = {i, j};
  for (int i = 0; i < 7; ++i) {
    p = rot45(p.first, p.second);
  }
  return p;
}


int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  int h, w;
  while (cin >> h >> w) {
    const int H = 1000 + 3;
    const int W = 1000 + 3;
    static char g[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    vec<pair<int, int>> v;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == 'B') {
          v.push_back(rot45(i, j));
        }
      }
    }

    // cout << v << endl;
    int mni = +(1 << 29);
    int mnj = +(1 << 29);
    int mxi = -(1 << 29);
    int mxj = -(1 << 29);
    each (i, v) {
      setmin(mni, i.first);
      setmax(mxi, i.first);
      setmin(mnj, i.second);
      setmax(mxj, i.second);
    }

    int mn = 1 << 29;
    pair<int, int> p;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        pair<int, int> q = rot45(i, j);
        int s = 0;
        setmax(s, max(abs(q.first - mxi), abs(q.first - mni)));
        setmax(s, max(abs(q.second - mxj), abs(q.second - mnj)));
        if (s < mn) {
          mn = s;
          p = {i, j};
        }
      }
    }
    cout << p.first + 1 << ' ' << p.second + 1 << endl;
  }

  return 0;
}
