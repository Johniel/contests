// vjudge/309481/C/main.cpp
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

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // map<int, int> cnt;
  // set<int> vis;

  // char buff[100];
  // for (lli x = 1; x < 1000000; ++x) {
  //   for (lli y = x; y < 1000000; y += x) {
  //     sprintf(buff, "%d", x);
  //     string s(buff);
  //     sprintf(buff, "%d", y);
  //     string t(buff);
  //     while (s.size() > t.size()) {
  //       t = "0" + t;
  //     }
  //     if (s.size() != t.size()) continue;
  //     s += t;
  //     lli z = atol(s.c_str());
  //     if (z % x == 0 && z % y == 0)  {
  //       cout << z << endl;
  //       ++cnt[s.size() / 2];
  //     }
  //   }
  // }

  // each (i, cnt) cout << i << endl;

  int n;
  while (cin >> n) {
    if (n == 1) cout << 14 << endl;
    else if (n == 2) cout << 155 << endl;
    else {
      cout << 1575 << string(n - 3, '0') << endl;
    }
  }

  return 0;
}
