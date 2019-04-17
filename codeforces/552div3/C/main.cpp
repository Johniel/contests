// codeforces/552div3/C/main.cpp
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

  vector<lli> v(3);
  while (cin >> v) {
    lli x = v[0] / 3;
    lli y = v[1] / 2;
    lli z = v[2] / 2;
    lli mn = min({x, y, z});
    v[0] -= mn * 3;
    v[1] -= mn * 2;
    v[2] -= mn * 2;
    vector<lli> u;
    u.push_back(0);
    u.push_back(1);
    u.push_back(2);
    u.push_back(0);
    u.push_back(2);
    u.push_back(1);
    u.push_back(0);
    lli mx = mn * 7;
    for (int loop = 0; loop < 10; ++loop) {
      u.push_back(u.front());
      u.erase(u.begin());
      const vector<lli> tmp = v;
      int cnt = 0;
      while (true) {
        bool f = true;
        each (i, u) {
          if (v[i] == 0) {
            f = false;
            break;
          }
          --v[i];
          ++cnt;
        }
        if (!f) break;
      }
      setmax(mx, mn * 7 + cnt);
      v = tmp;
    }
    cout << mx << endl;
  }
  
  return 0;
}
