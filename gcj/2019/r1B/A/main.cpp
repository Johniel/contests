// gcj/2019/r1B/A/main.cpp
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

void fn()
{
  int p, q;
  cin >> p >> q;

  const int Q = q + 5;
  vector<int> x(Q, 0);
  vector<int> y(Q, 0);

  for (int i = 0; i < p; ++i) {
    int s, t;
    char d;
    cin >> s >> t >> d;
    if (d == 'S') {
      ++y[0];
      --y[t];
    }
    if (d == 'N') {
      ++y[t + 1];
    }
    if (d == 'W') {
      ++x[0];
      --x[s];
    }
    if (d == 'E') {
      ++x[s + 1];
    }
  }
  for (int i = 0; i + 1 < Q; ++i) {
    x[i + 1] += x[i];
    y[i + 1] += y[i];
  }

  // cout << endl;
  // cout << y << endl;
  // cout << x << endl;

  int s = max_element(x.begin(), x.end()) - x.begin();
  int t = max_element(y.begin(), y.end()) - y.begin();

  static int cnt = 0;
  cout << "Case #" << ++cnt << ": " << s << ' ' << t << endl;

  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  cin >> tc;
  while (tc--) fn();

  return 0;
}
