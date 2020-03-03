// atcoder/arc006/A/main.cpp
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

  vector<int> a(6);
  vector<int> b(6);
  int c;
  while (cin >> a >> c >> b) {
    map<int, int> m;
    each (i, a) ++m[i];
    each (i, b) ++m[i];
    int cnt = 0;
    each (i, m) cnt += (i.second == 2);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (cnt == 6) {
      cout << 1 << endl;
      continue;
    }
    if (cnt == 5 && binary_search(b.begin(), b.end(), c) && m[c] == 1) {
      cout << 2 << endl;
      continue;
    }
    if (cnt == 5) {
      cout << 3 << endl;
      continue;
    }
    if (cnt == 4) {
      cout << 4 << endl;
      continue;
    }
    if (cnt == 3) {
      cout << 5 << endl;
      continue;
    }
    cout << 0 << endl;
  }

  return 0;
}
