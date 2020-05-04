// atcoder/exawizards2019/C/main.cpp
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

  int n, m;
  str s;
  while (cin >> n >> m >> s) {
    vec<pair<char, char>> v(m);
    cin >> v;
    auto f = [&] () {
      auto fn = [&] (int x) {
        each (i, v) {
          if (s[x] == i.first) {
            if (i.second == 'R') ++x;
            if (i.second == 'L') --x;
          }
          if (x == s.size()) return false;
          if (x == -1) return true;
        }
        return false;
      };
      int small = 0;
      int large = s.size();
      while (small + 1 < large) {
        int mid = (small + large) / 2;
        if (fn(mid)) small = mid;
        else large = mid;
      }
      return fn(small) ? small + 1 : 0;
    };
    int x = f();
    reverse(s.begin(), s.end());
    each (i, v) {
      i.second = 'R' + 'L' - i.second;
    }
    x += f();
    cout << n - x << endl;
  }

  return 0;
}
