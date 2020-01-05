// codeforces/hello2020/B/main.cpp
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
    vector<int> v[n];
    for (int i = 0; i < n; ++i) {
      int m;
      cin >> m;
      v[i].resize(m);
      cin >> v[i];
    }

    vector<int> mx;
    bool ascent[n];
    int m = 0;
    for (int i = 0; i < n; ++i) {
      vector<int> u = v[i];
      sort(u.begin(), u.end());
      reverse(u.begin(), u.end());
      ascent[i] = (u != v[i]);
      if (!ascent[i]) {
        mx.push_back(u.front());
      } else {
        ++m;
      }
    }
    sort(mx.begin(), mx.end());

    lli sum = 0;
    for (int i = 0; i < n; ++i) {
      if (ascent[i]) {
        sum += n;
      } else {
        auto itr = upper_bound(mx.begin(), mx.end(), v[i].back());
        sum += mx.end() - itr;
        sum += m;
      }
    }
    cout << sum << endl;
  }

  return 0;
}
