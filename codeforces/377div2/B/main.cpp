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

const int N = 500 + 10;
int a[N];

const int inf = 1 << 29;
int b[N];

int f(int x, const int n, const int k)
{
  copy(a, a + N, b);
  b[0] += x;
  for (int i = 1; i < n; ++i) {
    const int diff = k - (b[i] + b[i - 1]);
    b[i] += max(diff, 0);
  }
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += abs(a[i] - b[i]);
  }
  return sum;
}

int main(int argc, char *argv[])
{
  std::ios::sync_with_stdio(false);
  int n, k;
  while (cin >> n >> k) {
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int c[N];
    int mn = inf;
    for (int i = 0; i <= 500; ++i) {
      int x = f(i, n, k);
      if (x < mn) {
        mn = x;
        copy(b, b + N, c);
      }
    }
    cout << mn << endl;
    for (int i = 0; i < n; ++i) {
      if (i) cout << ' ' ;
      cout << c[i];
    }
    cout << endl;
  }
  return 0;
}
