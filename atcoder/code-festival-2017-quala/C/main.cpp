// atcoder/code-festival-2017-quala/C/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int h, w;
  while (cin >> h >> w) {
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    if (h * w == 1) {
      cout << "Yes" << endl;
      continue;
    }

    map<char, int> m;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        ++m[g[i][j]];
      }
    }

    if (h % 2 == 0 && w % 2 == 0) {
      bool f = true;
      each (i, m) f = f && (i.second % 4 == 0);
      cout << (f ? "Yes" : "No") << endl;
      continue;
    }

    if (h % 2 && w % 2) {
      int odd = 0;
      each (i, m) {
        if (i.second % 2) {
          ++odd;
          --i.second;
        }
      }
      if (odd != 1) {
        cout << "No" << endl;
        continue;
      }
    }

    int k = w * h;
    if (w % 2 && h % 2) {
      k -= w - 1;
      k -= h - 1;
      --k;
    } else if (w % 2) {
      k -= h;
    } else if (h % 2) {
      k -= w;
    }

    // cout << k << endl;
    each (i, m) {
      int mn = min(k, i.second / 4 * 4);
      k -= mn;
      i.second -= mn;
    }

    bool f = true;
    each (i, m) {
      f = f && (i.second % 2 == 0);
    }
    cout << (f && k == 0 ? "Yes" : "No") << endl;
  }

  return 0;
}
