// atcoder/abc001/C/main.cpp
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

string fn1(int m)
{
  if (34875 <= m) return "N";
  if (32625 <= m) return "NNW";
  if (30375 <= m) return "NW";
  if (28125 <= m) return "WNW";
  if (25875 <= m) return "W";
  if (23625 <= m) return "WSW";
  if (21375 <= m) return "SW";
  if (19125 <= m) return "SSW";
  if (16875 <= m) return "S";
  if (14625 <= m) return "SSE";
  if (12375 <= m) return "SE";
  if (10125 <= m) return "ESE";
  if (7875 <= m) return "E";
  if (5625 <= m) return "ENE";
  if (3375 <= m) return "NE";
  if (1125 <= m) return "NNE";
  return "N";
}

int fn2(double m)
{
  if (327.0 <= m) return 12;
  if (285.0 <= m) return 11;
  if (245.0 <= m) return 10;
  if (208.0 <= m) return 9;
  if (172.0 <= m) return 8;
  if (139.0 <= m) return 7;
  if (108.0 <= m) return 6;
  if (80.0 <= m) return 5;
  if (55.0 <= m) return 4;
  if (34.0 <= m) return 3;
  if (16.0 <= m) return 2;
  if (3.0 <= m) return 1;
  return 0;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  double deg, dis;
  while (cin >> deg >> dis) {
    int x = fn2(round(dis / 6));
    if (x == 0) cout << "C 0" << endl;
    else cout << fn1(deg*10) << ' ' << x << endl;
  }
  
  return 0;
}
