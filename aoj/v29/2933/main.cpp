// aoj/zprocon1/D/main.cpp
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

  int n, m;
  while (cin >> n >> m) {
    vector<lli> v(m);
    cin >> v;
    v.push_back(n + 1);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    vector<lli> u;
    for (int i = v[0]; i < n; ++i) {
      auto j = *upper_bound(v.begin(), v.end(), i) - i - 1;
      if (j) u.push_back(j);
    }
    sort(u.begin(), u.end());

    int q;
    cin >> q;
    while (q--) {
      int x;
      cin >> x;

      lli small = 1;
      lli large = n;
      while (small + 1 < large) {
        lli mid = (small + large) / 2;
        lli y = u.end() - lower_bound(u.begin(), u.end(), mid) + (v[0] - 1);
        if (y <= x) large = mid;
        else small = mid;
      }
      int a = u.end() - lower_bound(u.begin(), u.end(), small) + (v[0] - 1);
      int b = u.end() - lower_bound(u.begin(), u.end(), large) + (v[0] - 1);
      if (a <= x) cout << small << endl;
      else if (b <= x) cout << large << endl;
      else cout << -1 << endl;
    }
  }

  return 0;
}
