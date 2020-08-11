// atcoder/code-formula-2014-qualb/C/main.cpp
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

  str a, b;
  while (cin >> a >> b) {
    str s, t;
    map<char, int> cnt;
    bool f = true;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] != b[i]) {
        s += a[i];
        t += b[i];
      }
    }

    int dup = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      setmax<int>(dup, count(a.begin(), a.end(), c));
    }
    dup = (1 < dup);

    if (7 < s.size()) {
      cout << "NO" << endl;
      continue;
    }

    if (s.empty()) {
      cout << (dup ? "YES" : "NO") << endl;
      continue;
    }

    f = false;
    for (int a = 0; a < s.size(); ++a) {
      for (int b = a + 1; b < s.size(); ++b) {
        str s1 = s;
        swap(s1[a], s1[b]);
        if (dup && s1 == t) {
          f = true;
          a = b = (1 << 29);
        }
        for (int x = 0; x < s.size(); ++x) {
          for (int y = x + 1; y < s.size(); ++y) {
            str s2 = s1;
            swap(s2[x], s2[y]);
            if (dup && s2 == t) {
              f = true;
              a = b = x = y = (1 << 29);
            }
            for (int p = 0; p < s.size(); ++p) {
              for (int q = p + 1; q < s.size(); ++q) {
                str s3 = s2;
                swap(s3[p], s3[q]);
                if (s3 == t) {
                  f = true;
                  a = b = x = y = p = q = (1 << 29);
                }
              }
            }
          }
        }
      }
    }
    cout << (f ? "YES" : "NO") << endl;
  }

  return 0;
}
