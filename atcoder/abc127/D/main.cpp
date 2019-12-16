// atcoder/abc127/D/main.cpp
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
    vector<int> a(n);
    cin >> a;

    vector<pair<int, int>> v(m);
    cin >> v;
    each (i, a) v.push_back(make_pair(1, i));

    sort(v.begin(), v.end(), [] (auto i, auto j) {
      return i.second < j.second;
    });

    vector<lli> b;
    while (b.size() < n) {
      b.push_back(v.back().second);
      --v.back().first;
      if (v.back().first == 0) v.pop_back();
    }

    cout << accumulate(b.begin(), b.end(), 0LL) << endl;
  }

  return 0;
}
