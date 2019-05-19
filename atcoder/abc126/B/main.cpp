// atcoder/abc126/B/main.cpp
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

bool yymm(string s)
{
  string t;
  t += s[2];
  t += s[3];

  set<string> mm;
  for (int i = 1; i <= 12; ++i) {
    char buff[10];
    sprintf(buff, "%02d", i);
    mm.insert(string(buff));
  }
  return mm.count(t);
}

bool mmyy(string s)
{
  string t;
  t += s[0];
  t += s[1];

  set<string> mm;
  for (int i = 1; i <= 12; ++i) {
    char buff[10];
    sprintf(buff, "%02d", i);
    mm.insert(string(buff));
  }
  return mm.count(t);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while (cin >> s) {
    if (mmyy(s) && yymm(s)) cout << "AMBIGUOUS" << endl;
    else if (mmyy(s)) cout << "MMYY" << endl;
    else if (yymm(s)) cout << "YYMM" << endl;
    else cout << "NA" << endl;
  }

  return 0;
}
