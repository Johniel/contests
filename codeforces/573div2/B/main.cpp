// codeforces/573div2/B/main.cpp
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

char buff[100];

bool fn(map<string, int> m)
{
  string t = "spm";
  for (int i = 1; i <= 9; ++i) {
    each (c, t) {
      sprintf(buff, "%d", i);
      string x(buff);
      sprintf(buff, "%d", i+1);
      string y(buff);
      sprintf(buff, "%d", i+2);
      string z(buff);
      x += c;
      y += c;
      z += c;
      if (m[x] == 3) return true;
      if (m[x] && m[y] && m[z]) return true;
    }
  }
  return false;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<string> u;
  for (int i = 1; i <= 9; ++i) {
    sprintf(buff, "%ds", i);
    string x(buff);
    sprintf(buff, "%dp", i);
    string y(buff);
    sprintf(buff, "%dm", i);
    string z(buff);
    u.push_back(x);
    u.push_back(y);
    u.push_back(z);
  }

  vector<string> v(3);
  while (cin >> v) {
    map<string, int> m;
    each (i, v) ++m[i];

    int mn = 3;
    if (fn(m)) mn = 0;

    each (i, u) {
      ++m[i];
      if (fn(m)) setmin(mn, 1);
      --m[i];
    }

    each (i, u) {
      each (j, u) {
        ++m[i];
        ++m[j];
        if (fn(m)) setmin(mn, 2);
        --m[i];
        --m[j];
      }
    }

    cout << mn << endl;
  }

  return 0;
}
