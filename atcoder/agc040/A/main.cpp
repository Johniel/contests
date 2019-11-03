// atcoder/agc040/A/main.cpp
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

  string s;
  while (cin >> s) {
    vector<string> v;
    string t;
    each (c, s) {
      if (t.empty() || t.back() == c) t += c;
      else {
        v.push_back(t);
        t = string(1, c);
      }
    }
    if (t.size()) v.push_back(t);
    // cout << v << endl;
    lli sum = 0;
    each (i, v) {
      sum += (lli)i.size() * (i.size() + 1) / 2;
    }
    for (int i = 0; i + 1 < v.size(); ++i) {
      if (v[i][0] == '<') {
        sum -= min(v[i].size(), v[i + 1].size());
      }
    }
    cout << sum << endl;
  }

  return 0;
}
