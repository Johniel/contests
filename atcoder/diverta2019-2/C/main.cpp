// atcoder/diverta2019-2/C/main.cpp
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

vector<pair<lli, lli>> path;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    path.clear();
    vector<lli> a(n);
    cin >> a;
    sort(a.begin(), a.end());

    if (n == 1) {
      cout << a[0] << endl;
      continue;
    }
    if (n == 2) {
      cout << a[1] - a[0] << endl;
      cout << a[1] << ' ' << a[0] << endl;
      continue;
    }

    vector<lli> pos, neg;
    each (i, a) {
      if (0 <= i) pos.push_back(i);
      else neg.push_back(i);
    }

    if (neg.empty()) {
      path.push_back({pos.front(), pos.back()});
      neg.push_back(pos.front() - pos.back());
      pos.pop_back();
      pos.erase(pos.begin());
    } else if (pos.empty()) {
      path.push_back({neg.back(), neg.front()});
      pos.push_back(neg.back() - neg.front());
      neg.pop_back();
      neg.erase(neg.begin());
    }

    while (1 < pos.size()) {
      lli x = pos.back();
      lli y = neg.back();
      pos.pop_back();
      neg.pop_back();
      path.push_back({y, x});
      neg.push_back(y - x);
    }

    while (neg.size()) {
      lli x = pos.back();
      lli y = neg.back();
      pos.pop_back();
      neg.pop_back();
      path.push_back({x, y});
      pos.push_back(x - y);
    }

    cout << pos.front() << endl;
    each (i, path) cout << i.first << ' ' << i.second << endl;
    // cout << endl;
  }

  return 0;
}
