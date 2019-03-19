// codeforces/547div3/F1/main.cpp
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

// (first, second]
vector<pair<int, int>> scheduling(vector<pair<int, int>> v)
{
  vector<pair<int, int>> u;
  sort(v.begin(), v.end(), [] (auto i, auto j) { return i.second < j.second; });
  int f = 0;
  for (int i = 0; i < v.size(); ++i) {
    if (f <= v[i].first) {
      u.push_back(v[i]);
      f = v[i].second;
    }
  }
  return u;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<lli> v(n);
    cin >> v;

    map<lli, vector<pair<int, int>>> m;
    for (int i = 0; i < v.size(); ++i) {
      lli sum = 0;
      for (int j = i; j < v.size(); ++j) {
        sum += v[j];
        m[sum].push_back({i, j + 1});
      }
    }

    vector<pair<int, int>> u;
    each (i, m) {
      auto w = scheduling(i.second);
      if (u.size() < w.size()) u = w;
    }

    cout << u.size() << endl;
    each (i, u) cout << i.first + 1 << ' ' << i.second << endl;
  }

  return 0;
}
