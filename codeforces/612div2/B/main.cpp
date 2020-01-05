// codeforces/612div2/B/main.cpp
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

  int n, f;
  while (cin >> n >> f) {
    vector<string> v(n);
    cin >> v;
    sort(v.begin(), v.end());
    map<string, int> m;
    for (int i = 0; i < v.size(); ++i) {
      m[v[i]] = i;
    }

    lli sum = 0;
    string s(f, '_');
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = 0; k < f; ++k) {
          if (v[i][k] == v[j][k]) {
            s[k] = v[i][k];
          } else {
            s[k] = char(int('S') + int('T') + int('E') - v[i][k] - v[j][k]);
          }
        }
        if (v[j] < s) {
          sum += (j < m[s]);
        }
      }
    }
    cout << sum << endl;
  }

  return 0;
}
