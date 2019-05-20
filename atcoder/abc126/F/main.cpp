// atcoder/abc126/F/main.cpp
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

  int m, k;
  while (cin >> m >> k) {
    if (k == 0) {
      for (int i = 0; i < (1 << m); ++i) {
        cout << i << ' ' << i << ' ';
      }
      cout << endl;
      continue;
    }

    vector<lli> v;
    v.push_back(0);
    v.push_back(k);
    v.push_back(0);
    int x = 0;
    for (int i = 1; i < (1 << m); ++i) {
      if (i != k) {
        v.push_back(i);
        x ^= i;
      }
    }
    v.push_back(k);
    for (int i = (1 << m) - 1; 1 <= i; --i) {
      if (i != k) v.push_back(i);
    }

    if (x == k) {
      each (i, v) cout << i << ' ';
      cout << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}
