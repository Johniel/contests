// codeforces/573div2/D/main.cpp
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
    map<int, int> m;

    vector<int> a(n);
    cin >> a;
    sort(a.begin(), a.end());

    int dup = 0;
    int x = 0;
    each (i, a) {
      ++m[i];
      if (m[x] < m[i]) x = i;
      dup += (2 <= m[i]);
    }

    const string SECOND = "cslnb";
    const string FIRST = "sjfnb";

    if (2 < m[x] || 1 < dup) {
      cout << SECOND << endl;
      continue;
    }

    int turn = 0;
    if (dup) {
      if (x == 0) {
        cout << SECOND << endl;
        continue;
      }
      if (m[x] && m[x - 1]) {
        cout << SECOND << endl;
        continue;
      }
      --m[x];
      ++turn;
      each (i, a) {
        if (i == x) {
          --i;
          break;
        }
      }
      sort(a.begin(), a.end());
    }

    vector<int> b;
    for (int i = 0; i < a.size(); ++i) {
      b.push_back(i);
    }
    lli sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += a[i] - b[i];
    }
    cout << ((sum + turn) % 2 ? FIRST : SECOND) << endl;
  }

  return 0;
}
