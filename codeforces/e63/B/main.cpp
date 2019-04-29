// codeforces/e63/B/main.cpp
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
  string s;
  while (cin >> n >> s) {
    deque<int> x;
    deque<int> y;

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '8') x.push_back(i);
      else             y.push_back(i);
    }

    for (int i = 0; 11 < x.size() + y.size(); ++i) {
      if (i % 2) {
        if (x.size()) x.pop_front();
        else          y.pop_back();
      } else {
        if (y.size()) y.pop_front();
        else          x.pop_back();
      }
    }

    vector<int> v;
    while (x.size()) {
      v.push_back(x.front());
      x.pop_front();
    }
    while (y.size()) {
      v.push_back(y.front());
      y.pop_front();
    }
    sort(begin(v), end(v));

    string t;
    each (i, v) t += s[i];
    assert(t.size() == 11);

    cout << (t[0] == '8' ? "YES" : "NO") << endl;
  }

  return 0;
}
