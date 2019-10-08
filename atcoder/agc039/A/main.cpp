// atcoder/agc039/A/main.cpp
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
  lli k;
  while (cin >> s >> k) {
    vector<string> v;
    string t;
    each (c, s) {
      if (t.size() && t.back() != c) {
        v.push_back(t);
        t = "";
      }
      t += c;
    }
    if (t.size()) v.push_back(t);

    if (v.size() == 1) {
      cout << s.size() * k / 2 << endl;
      continue;
    }

    lli x = 0;
    if (v.front().front() == v.back().back()) {
      x += (v.front().size() + v.back().size()) / 2 * (k - 1);
      x += v.front().size() / 2;
      x += v.back().size() / 2;
      lli sum = 0;
      for (int i = 1; i + 1< v.size(); ++i) {
        sum += v[i].size() / 2;
      }
      cout << sum * k + x << endl;
    } else {
      lli sum = 0;
      each (i, v) sum += i.size() / 2;
      cout << sum * k << endl;
    }



  }

  return 0;
}
