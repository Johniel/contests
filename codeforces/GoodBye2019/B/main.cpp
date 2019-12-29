// codeforces/GoodBye2019/B/main.cpp
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

  int tc;
  while (cin >> tc) {
    while (tc--) {
      int n;
      cin >> n;
      vector<int> a(n);
      cin >> a;

      int x = -1;
      for (int i = 0; i + 1 < a.size(); ++i) {
        if (2 <= abs(a[i] - a[i + 1])) {
          x = i;
        }
      }

      if (x == -1) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
        cout << x + 1 << ' ' << x + 2 << endl;
      }
    }
  }

  return 0;
}
