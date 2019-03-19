// codeforces/547div3/C/main.cpp
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

  int n;
  while (cin >> n) {
    vector<int> v(n - 1);
    cin >> v;

    vector<int> u;
    u.push_back(0);
    each (i, v) u.push_back(u.back() + i);
    int mn = *min_element(u.begin(), u.end());
    each (i, u) i = i - mn + 1;

    set<int> vis(u.begin(), u.end());
    bool f = true;
    for (int i = 1; i <= n; ++i) {
      f = f && vis.count(i);
    }

    if (f) {
      each (i, u) cout << i << ' ';
      cout << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}
