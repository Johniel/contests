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
    vector<int> a(n);
    cin >> a;
    int mx = 0;
    for (int i = 1; i <= 1000; ++i) {
      set<int> vis;
      for (int j = i; j <= 1000; ++j) {
        if (binary_search(a.begin(), a.end(), j)) {
          vis.insert(j);
        } else {
          break;
        }
      }
      if (vis.empty()) continue;
      auto a = *vis.begin();
      auto b = *vis.rbegin();
      // cout << make_pair(a, b) << endl;
      int x = b - a - 2 + 1;
      if (a == 1) ++x;
      if (b == 1000) ++x;
      setmax(mx, x);
    }
    cout << mx << endl;
  }
  
  return 0;
}
