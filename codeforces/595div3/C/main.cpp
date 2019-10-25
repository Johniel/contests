// codeforces/595div3/C/main.cpp
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

  int q;
  lli n;
  while (cin >> q) {
    while (q--) {
      cin >> n;
      vector<int> v;
      while (n) {
        v.push_back(n % 3);
        n /= 3;
      }
      v.push_back(0);

      int j = -1;
      for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 2) j = i;
      }
      if (j != -1) {
        fill(v.begin(), v.begin() + j, 0);
        for (int i = j; i < v.size(); ++i) {
          if (v[i] == 0) {
            v[i] = 1;
            break;
          }
          v[i] = 0;
        }
      }

      lli w = 1;
      lli sum = 0;
      for (int i = 0; i < v.size(); ++i) {
        if (v[i]) sum += w;
        w *= 3;
      }
      cout << sum << endl;
    }
  }

  return 0;
}
