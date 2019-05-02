// codeforces/e64/A/main.cpp
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
    bool f = true;
    for (int i = 0; i + 1< a.size(); ++i) {
      if (a[i] == 2 && a[i + 1] == 3) f = false;
      if (a[i] == 3 && a[i + 1] == 2) f = false;
    }
    if (!f) {
      cout << "Infinite" << endl;
      continue;
    }

    map<pair<int, int>, int> m;
    m[{1,2}] = 3;
    m[{1,3}] = 4;
    m[{2,1}] = 3;
    m[{3,1}] = 4;
    int sum = 0;
    for (int i = 0; i + 1 < a.size(); ++i) {
      sum += m[{a[i], a[i + 1]}];
      if (i + 2 < a.size() && a[i] == 3 && a[i + 1] == 1 && a[i + 2] == 2) {
        --sum;
      }
    }
    cout << "Finite" << endl;
    cout << sum << endl;
  }

  return 0;
}
