// codeforces/556div2/C/main.cpp
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
    vector<int> a(n);
    cin >> a;
    map<int, int> m;
    each (i, a) ++m[i];

    vector<int> b;
    if (m[1] == n) {
      b = vector<int>(n, 1);
      each (i, b) cout << i << ' ' ; cout << endl;
      continue;
    }
    if (m[2] == n) {
      b = vector<int>(n, 2);
      each (i, b) cout << i << ' ' ; cout << endl;
      continue;
    }

    if (3 <= m[1]) {
      b.push_back(1); --m[1];
      b.push_back(1); --m[1];
      b.push_back(1); --m[1];
    } else {
      b.push_back(2); --m[2];
      b.push_back(1); --m[1];
    }

    while (m[2]) {
      b.push_back(2);
      --m[2];
    }
    while (m[1]) {
      b.push_back(1);
      --m[1];
    }
    each (i, b) cout << i << ' ' ; cout << endl;
  }

  return 0;
}
