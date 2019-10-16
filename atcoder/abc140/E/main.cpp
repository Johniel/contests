// atcoder/abc140/E/main.cpp
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
    vector<lli> v(n);
    cin >> v;

    vector<pair<int, lli>> u;
    for (int i = 0; i < v.size(); ++i) {
      u.push_back({i, v[i]});
    }
    sort(u.begin(), u.end(), [] (auto i, auto j) { return i.second > j.second; });

    set<pair<int, lli>> s;
    s.insert({-1, -1});
    s.insert({-1, -2});
    s.insert({n, n+1});
    s.insert({n, n+2});

    lli sum = 0;
    each (i, u) {
      s.insert(i);
      if (i.second == n) continue;
      auto x = s.find(i);
      auto b = --x;
      auto a = --x;
      ++x;
      ++x;
      auto c = ++x;
      auto d = ++x;
      --x;
      --x;

      sum += x->second * (b->first - a->first) * (c->first - x->first);
      sum += x->second * (d->first - c->first) * (x->first - b->first);
    }
    cout << sum << endl;
  }

  return 0;
}
