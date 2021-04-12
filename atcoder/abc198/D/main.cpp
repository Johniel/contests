// atcoder/abc198/D/main.cpp
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

  str a, b, c;
  while (cin >> a >> b >> c) {
    set<char> vis;
    each (c, a) vis.insert(c);
    each (c, b) vis.insert(c);
    each (c, c) vis.insert(c);

    if (10 < vis.size()) {

    }

    map<char, int> m;
    each (c, vis) {
      int s = m.size();
      m[c] = s;
    }

    lli x, y, z;
    x = -1;
    str s = "0123456789";
    sort(s.begin(), s.end());
    do {
      char buff1[20];
      char buff2[20];
      char buff3[20];
      fill(buff1, buff1 + 20, 0);
      fill(buff2, buff2 + 20, 0);
      fill(buff3, buff3 + 20, 0);
      for (int i = 0; i < a.size(); ++i) buff1[i] = s[m[a[i]]];
      for (int i = 0; i < b.size(); ++i) buff2[i] = s[m[b[i]]];
      for (int i = 0; i < c.size(); ++i) buff3[i] = s[m[c[i]]];
      if (buff1[0] == '0') continue;
      if (buff2[0] == '0') continue;
      if (buff3[0] == '0') continue;
      lli p = atoll(buff1);
      lli q = atoll(buff2);
      lli r = atoll(buff3);
      if (p + q == r) {
        x = p;
        y = q;
        z = r;
      }
    } while (next_permutation(s.begin(), s.end()));

    if (x == -1) {
      cout << "UNSOLVABLE" << endl;
    } else {
      cout << x << endl;
      cout << y << endl;
      cout << z << endl;
    }
  }

  return 0;
}
