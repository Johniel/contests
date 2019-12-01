// atcoder/sumitrust2019/D/main.cpp
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

bool fn(string s, string t)
{
  queue<char> q;
  each (c, t) q.push(c);
  each (c, s) {
    if (q.front() == c) q.pop();
    if (q.empty()) return true;
  }
  return false;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n;
  string s;
  while (cin >> n >> s) {
    lli sum = 0;
    char buff[1000];
    for (int i = 0; i < 1000; ++i) {
      sprintf(buff, "%03d", i);
      sum += fn(s, string(buff));
    }
    cout << sum << endl;
  }

  return 0;
}
