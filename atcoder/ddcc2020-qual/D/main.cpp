// atcoder/ddcc2020-qual/D/main.cpp
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

  int m;
  while (cin >> m) {
    vec<pair<int, lli>> v(m);
    cin >> v;

    lli x[10] = {0, };
    each (i, v) {
      x[i.first] += i.second;
    }

    lli y = 0;
    for (int i = 0; i < 1e8; ++i) {
      x[9] += x[1] / 9;
      y += (x[1] / 9) * 8;
      x[1] %= 9;
      if (1 < x[1]) {
        y += x[1] - 1;
        ++x[x[1] * 1];
        x[1] = 0;
      }

      x[8] += x[2] / 4;
      y += (x[2] / 4) * 3;
      x[2] %= 4;
      if (1 < x[2]) {
        y += x[2] - 1;
        ++x[x[2] * 2];
        x[2] = 0;
      }

      x[9] += x[3] / 3;
      y += (x[3] / 3) * 2;
      x[3] %= 3;
      if (1 < x[3]) {
        y += x[3] - 1;
        ++x[x[3] * 3];
        x[3] = 0;
      }

      x[8] += x[4] / 2;
      y += x[4] / 2;
      x[4] %= 2;

      x[1] += x[5] / 2;
      x[0] += x[5] / 2;
      y += x[5] / 2;
      x[5] %= 2;

      x[1] += x[6] / 2;
      x[2] += x[6] / 2;
      y += x[6] / 2;
      x[6] %= 2;

      x[1] += x[7] / 2;
      x[4] += x[7] / 2;
      y += x[7] / 2;
      x[7] %= 2;

      x[1] += x[8] / 2;
      x[6] += x[8] / 2;
      y += x[8] / 2;
      x[8] %= 2;

      x[1] += x[9] / 2;
      x[8] += x[9] / 2;
      y += x[9] / 2;
      x[9] %= 2;
    }
    vec<int> u;
    for (int i = 1; i < 10; ++i) {
      for (int j = 0; j < x[i]; ++j) {
        u.push_back(i);
      }
    }
    while (1 < u.size()) {
      int p = u.back();
      u.pop_back();
      int q = u.back();
      u.pop_back();
      if (10 <= p + q) {
        u.push_back(1);
        u.push_back((p + q) % 10);
      } else {
        u.push_back(p + q);
      }
      ++y;
    }
    cout << y+x[0] << endl;
  }

  return 0;
}
