// codeforces/e94/B/main.cpp
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

  lli p, f, cnts, cntw, s, w;
  while (cin >> p >> f >> cnts >> cntw >> s >> w) {
    // 剣の方が軽いものとする
    unless (s < w) {
      swap(s, w);
      swap(cnts, cntw);
    }
    lli mx = 0;
    // 一人目に持たせる剣の個数
    for (lli p_cnts = 0; p_cnts <= cnts; ++p_cnts) {
      unless (p_cnts * s <= p) continue;
      lli p_cntw = min((p - p_cnts * s) / w, cntw);

      lli f_cnts = min(f / s, cnts - p_cnts);
      lli f_cntw = min((f - f_cnts * s) / w, cntw - p_cntw);
      setmax(mx, p_cnts + p_cntw + f_cnts + f_cntw);
    }
    cout << mx << endl;
  }

  return 0;
}