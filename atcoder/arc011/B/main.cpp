// atcoder/arc011/B/main.cpp
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
  while (cin >> n) {
    vec<str> v(n);
    cin >> v;

    vec<str> u;
    each (s, v) {
      str t;
      each (c, s) {
        c = tolower(c);
        if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') continue;
        if (c == 'b' || c == 'c') t += '1';
        if (c == 'd' || c == 'w') t += '2';
        if (c == 't' || c == 'j') t += '3';
        if (c == 'f' || c == 'q') t += '4';
        if (c == 'l' || c == 'v') t += '5';
        if (c == 's' || c == 'x') t += '6';
        if (c == 'p' || c == 'm') t += '7';
        if (c == 'h' || c == 'k') t += '8';
        if (c == 'n' || c == 'g') t += '9';
        if (c == 'z' || c == 'r') t += '0';
      }
      if (t.size()) u.push_back(t);
    }

    for (int i = 0; i < u.size(); ++i) {
      if (i) cout << ' ';
      cout << u[i];
    }
    cout << endl;
  }

  return 0;
}
