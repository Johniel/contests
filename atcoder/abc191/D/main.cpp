// github.com/Johniel/contests
// atcoder/abc191/D/main.cpp

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

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

lli parse(str s)
{
  istringstream sin(s);
  lli x;
  sin >> x;
  x *= 10000;
  char c;
  sin >> c;
  lli y = 0;
  for (int _ = 0; _ < 4; ++_) {
    lli z = 0;
    if (sin >> c) z = c - '0';
    y = y * 10 + z;
  }
  if (x < 0) y *= -1;
  return x + y;
}

int main(int argc, char *argv[])
{
  str _x, _y, _r;
  while (cin >> _x >> _y >> _r) {
    const lli W = 10000;
    const lli X = parse(_x) % W;
    const lli Y = parse(_y) % W;
    const lli R = parse(_r);

    lli z = 0;
    lli d = 1;
    for (lli x = X - R; x <= X + R; x += d) {
      if (x % W) continue;
      d = W;
      auto fn = [&] (lli y) {
        return (X - x) * (X - x) + (Y - y) * (Y - y) <= R * R;
      };
      lli a, b;
      {
        lli small = 0;
        lli large = abs(Y) + R + 10;
        while (small + 1 < large) {
          lli mid = (small + large) / 2;
          if (fn(Y + mid)) small = mid;
          else large = mid;
        }
        a = Y + small;
      }
      {
        lli small = 0;
        lli large = abs(Y) + R + 10;
        while (small + 1 < large) {
          lli mid = (small + large) / 2;
          if (fn(Y - mid)) small = mid;
          else large = mid;
        }
        b = Y - small;
      }
      // cout << make_pair(x, a) << ' ' << make_pair(x, b) << endl;
      // if (a < 0) a = (abs(a) + W - 1) * -1;
      // else a = abs(a) + W - 1;

      a /= W;

      // if (a < 0) {
      //   a = -1 * (abs(a) + W - 1) / W;
      // } else {
      //   a /= W;
      // }

      if (b < 0) {
        b /= W;
      } else {
        b = (abs(b) + W - 1) / W;
      }
      // z += (a - b) / W + 1;
      z += a - b + 1;
      // z += a - b;
      // cout << make_pair(x, a) << ' ' << make_pair(x, b) << endl;
    }
    cout << z << endl;
    // break;
  }
  return 0;
}
