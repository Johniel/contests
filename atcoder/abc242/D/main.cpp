// atcoder/abc242/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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

char fn(char c, lli k, lli t)
{
  if (t == 0) return c;
  if (k == 0) {
    str s;
    if (c == 'A') s = "ABC";
    if (c == 'B') s = "BCA";
    if (c == 'C') s = "CAB";
    return s[t % 3];
  }
  str s;
  if (c == 'A') s = "BC";
  if (c == 'B') s = "CA";
  if (c == 'C') s = "AB";
  return fn(s[k % 2], k / 2, --t);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  str s;
  int q;
  while (cin >> s >> q) {
    while (q--) {
      lli t, k;
      cin >> t >> k;
      --k;
      lli w = (1LL << min(t, 61LL));
      // cout << make_pair(k, w) << ' ' << (k+w-1)/w << "th: " << make_pair(s[k/w], k%w) << t << endl;
      cout << fn(s[k/w], k%w, t) << endl;
    }
    // cout << endl;
  }

  return 0;
}
