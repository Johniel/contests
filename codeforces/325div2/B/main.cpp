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
  int n;
  while (cin >> n) {
    int a1[n];
    int a2[n];
    int b[n];
    for (int i = 0; i < n - 1; ++i) {
      cin >> a1[i];
    }
    for (int i = 0; i < n - 1; ++i) {
      cin >> a2[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }


    int acc1[n];
    int acc2[n];

    fill(acc1, acc1 + n, 0);
    fill(acc2, acc2 + n, 0);

    for (int i = 1; i < n; ++i) {
      acc1[i] += acc1[i - 1] + a1[i - 1];
    }


    for (int i = n - 2; 0 <= i; --i) {
      acc2[i] += acc2[i + 1] + a2[i];
    }

    // for (int i = 0; i < n; ++i) cout << acc1[i] << ' '; cout << endl;
    // for (int i = 0; i < n; ++i) cout << acc2[i] << ' '; cout << endl;

    int mn = 1 << 29;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        const int x = acc1[i] + b[i] + acc2[i];
        const int y = acc1[j] + b[j] + acc2[j];
        const int cost = x + y;
        mn = min(mn, cost);
      }
    }

    cout << mn << endl;
  }
  return 0;
}
