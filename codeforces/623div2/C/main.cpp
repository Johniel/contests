// codeforces/623div2/C/main.cpp
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

constexpr lli mod = 1e9 + 7;


int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int _;
  cin >> _;

  int n;
  while (cin >> n) {
    vector<int> b(n);
    cin >> b;
    each (i, b) --i;

    set<int> s;
    for (int i = 0; i < 2 * n; ++i) {
      s.insert(i);
    }
    each (i, b) s.erase(i);

    vec<int> c(2 * n, -1);
    for (int i = 0; i < b.size(); ++i) {
      c[i * 2] = b[i];
    }

    for (int i = 0; i < b.size(); ++i) {
      auto itr = s.upper_bound(b[i]);
      if (itr == s.end()) break;
      c[i * 2 + 1] = *itr;
      s.erase(*itr);
    }

    if (s.size()) cout << -1 << endl;
    else {
      for (int i = 0; i < b.size(); ++i) {
        assert(b[i] == min(c[i*2], c[i*2+1]));
      }
      each (i, c) cout << i + 1 << ' '; cout << endl;
    }
  }

  return 0;
}
