// atcoder/abc162/D/main.cpp
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
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.setf(std::ios_base::fixed);
  std::cout.precision(15);

  int n;
  str s;
  while (cin >> n >> s) {
    vec<int> r, g, b;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'R') r.push_back(i);
      if (s[i] == 'G') g.push_back(i);
      if (s[i] == 'B') b.push_back(i);
    }

    lli z = 0;
    const int sum = (int)'R' + (int)'G' + (int)'B';
    for (int i = 0; i < s.size(); ++i) {
      for (int j = i + 1; j < s.size(); ++j) {
        if (s[i] != s[j]) {
          const char c = sum - s[i] - s[j];
          if (c == 'R') {
            int x = r.end() - lower_bound(r.begin(), r.end(), j + 1);
            int y = binary_search(r.begin(), r.end(), j + abs(i - j));
            z += x - y;
          }
          if (c == 'G') {
            int x = g.end() - lower_bound(g.begin(), g.end(), j + 1);
            int y = binary_search(g.begin(), g.end(), j + abs(i - j));
            z += x - y;
          }
          if (c == 'B') {
            int x = b.end() - lower_bound(b.begin(), b.end(), j + 1);
            int y = binary_search(b.begin(), b.end(), j + abs(i - j));
            z += x - y;
          }
        }
      }
    }
    cout << z << endl;
  }

  return 0;
}
