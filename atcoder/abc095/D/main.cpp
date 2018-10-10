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

lli fn(lli x[], lli v[], lli c, const int N)
{
  lli y[N + 1];
  y[0] = 0;
  for (int i = 0; i < N; ++i) {
    y[i + 1] = y[i] + v[i];
  }
  for (int i = 0; i < N; ++i) {
    y[i + 1] -= (x[i] + x[i]);
    y[i + 1] = max(y[i + 1], y[i]);
  }

  lli mx = 0;
  
  lli sum = 0;
  for (int i = N - 1; 0 <= i; --i) {
    sum += v[i];
    lli z = sum - (c - x[i]) + y[i];
    mx = max(mx, z);
  }
  
  return mx;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  lli c;
  while (cin >> n >> c) {
    lli x[n];
    lli v[n];
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> v[i];
    }

    lli a = fn(x, v, c, n);

    reverse(x, x + n);
    reverse(v, v + n);
    for (int i = 0; i < n; ++i) {
      x[i] = c - x[i];
    }
    lli b = fn(x, v, c, n);

    cout << max(a, b) << endl;
  }
  
  return 0;
}
