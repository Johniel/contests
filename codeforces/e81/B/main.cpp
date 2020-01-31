// codeforces/e81/B/main.cpp
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
template<typename T> inline pair<T, T> reverse(pair<T, T> p) { return make_pair(p.second, p.first); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  lli n, x;
  string s;
  cin >> tc;
  while (cin >> n >> x >> s) {
    const lli _1 = count(s.begin(), s.end(), '1');
    const lli _0 = count(s.begin(), s.end(), '0');
    const lli diff = _0 - _1;
    lli o, z;
    o = z = 0;
    int cnt = (x == 0);
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '0') ++z;
      else ++o;
      lli y = x - (z - o);
      if (diff) {
        if (y % diff == 0) {
          cnt += (0 <= y / diff);
        }
      } else if (y == 0) {
        ++cnt;
      }
    }
    cout << (cnt && (diff == 0) ? -1 : cnt) << endl;
  }

  return 0;
}
