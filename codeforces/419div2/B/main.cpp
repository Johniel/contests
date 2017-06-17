#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k, q;
  while (cin >> n >> k >> q) {
    const int N = 200000 + 10;
    lli x[N];
    fill(x, x + N, 0);
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      ++x[a];
      --x[b + 1];
    }
    for (int i = 1; i < N; ++i) {
      x[i] += x[i - 1];
    }
    lli y[N];
    for (int i = 0; i < N; ++i) {
      y[i] = (k <= x[i]);
    }
    for (int i = 1; i < N; ++i) {
      y[i] += y[i - 1];
    }
    while (q--) {
      int a, b;
      cin >> a >> b;
      cout << y[b] - y[a - 1] << endl;
    }
  }
  
  return 0;
}
