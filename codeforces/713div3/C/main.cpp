// codeforces/713div3/C/main.cpp
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

  int _;
  cin >> _;

  str s;
  int a, b;
  while (cin >> a >> b >> s) {
    each (c, s) {
      if (c == '0') --a;
      if (c == '1') --b;
    }

    for (int i = 0; i < s.size() / 2; ++i) {
      int j = s.size() - i - 1;
      if (s[i] == '?' && s[j] != '?') {
        s[i] = s[j];
        if (s[i] == '0') --a;
        if (s[i] == '1') --b;
        continue;
      }
      if (s[i] != '?' && s[j] == '?') {
        s[j] = s[i];
        if (s[i] == '0') --a;
        if (s[i] == '1') --b;
        continue;
      }
    }

    if (s.size() % 2 && a % 2) {
      s[s.size() / 2] = '0';
      --a;
    } else if (s.size() % 2 && b % 2) {
      s[s.size() / 2] = '1';
      --b;
    }

    for (int i = 0; i < s.size(); ++i) {
      int j = s.size() - i - 1;
      if (s[i] == '?' && s[j] == '?') {
        if (a < b) {
          s[i] = s[j] = '1';
          b -= 2;
        } else {
          s[i] = s[j] = '0';
          a -= 2;
        }
      }
    }

    bool f = a == 0 && b == 0 && (count(s.begin(), s.end(), '?') == 0);
    for (int i = 0; i < s.size(); ++i) {
      int j = s.size() - i - 1;
      f = f && (s[i] == s[j]);
    }

    if (f) cout << s << endl;
    else cout << -1 << endl;
  }

  return 0;
}
