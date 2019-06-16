// atcoder/diverta2019-2/B/main.cpp
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
    vector<pair<int, int>> v(n);
    cin >> v;

    vector<pair<int, int>> c;
    each (i, v) {
      each (j, v) {
        if (i != j) {
          int p = i.first - j.first;
          int q = i.second - j.second;
          c.push_back({p, q});
        }
      }
    }

    sort(v.begin(), v.end());
    int mn = n;
    each (i, c) {
      set<pair<int, int>> vis;
      int cnt = 0;
      each (j, v) {
        unless (vis.count(j)) {
          ++cnt;
          for (int k = 0; ; ++k) {
            pair<int, int> x = j;
            x.first += k * i.first;
            x.second += k * i.second;
            unless (binary_search(v.begin(), v.end(), x)) break;
            if (vis.count(x)) break;
            vis.insert(x);
          }
        }
      }
      setmin(mn, cnt);
    }

    cout << mn << endl;
  }

  return 0;
}
