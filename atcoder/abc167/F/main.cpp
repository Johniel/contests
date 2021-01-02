// atcoder/abc167/F/main.cpp
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

  int n;
  while (cin >> n) {
    vec<str> v(n);
    cin >> v;

    vec<pair<int, str>> a, b;
    each (s, v) {
      str t;
      each (c, s) {
        if (t.size() && t.back() == '(' && c == ')') {
          t.pop_back();
        } else {
          t += c;
        }
      }
      int x = count(t.begin(), t.end(), '(');
      int y = count(t.begin(), t.end(), ')');
      if (y < x) {
        a.push_back({y, s});
      } else {
        b.push_back({-x, s});
      }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    str s;
    each (i, a) s += i.second;
    each (i, b) s += i.second;
    int x = 0;
    each (c, s) {
      if (c == '(') ++x;
      if (c == ')') --x;
      if (x < 0) break;
    }
    if (x == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}
