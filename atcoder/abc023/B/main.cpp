// atcoder/abc023/B/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "("; each (i, s) os << i << ","; os << ")"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "("; each (i, m) os << i << ","; os << ")"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string s;
  while (cin >> n >> s) {
    string t = "b";
    int cnt = 0;
    while (true) {
      unless (t.size() < s.size()) break;
      ++cnt;
      t = "a" + t + "c";
      unless (t.size() < s.size()) break;
      ++cnt;
      t = "c" + t + "a";
      unless (t.size() < s.size()) break;
      ++cnt;
      t = "b" + t + "b";
    }
    cout << (t == s ? cnt : -1) << endl;
  }

  return 0;
}
