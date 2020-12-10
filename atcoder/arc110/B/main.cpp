// atcoder/arc110/B/main.cpp
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
  str s;
  while (cin >> n >> s) {
    if (n == 1 && s == "0") {
      cout << 10000000000LL << endl;
      continue;
    }
    if (n == 1 && s == "1") {
      cout << 20000000000LL << endl;
      continue;
    }

    const str t = "110";
    int x = -1;
    for (int i = 0; i < t.size(); ++i) {
      bool g = true;
      for (int j = 0; j < s.size(); ++j) {
        g = g && (t[(i + j) % t.size()] == s[j]);
      }
      if (g) {
        x = i;
        break;
      }
    }

    if (x == -1) {
      cout << 0 << endl;
      continue;
    }

    if (s[n - 1] == '0') {
    } else if (s[n - 2] == '0' && s[n - 1] == '1') {
      s += '1';
      s += '0';
    } else if (s[n - 2] == '1' && s[n - 1] == '1') {
      s += '0';
    }

    if (x == 0) {
    } else if (x == 1) {
      s = "1" + s;
    } else if (x == 2) {
      s = "11" + s;
    }

    cout << (30000000000LL - s.size()) / t.size() + 1 << endl;
  }

  return 0;
}
