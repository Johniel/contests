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

  int n;
  while (cin >> n) {
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    int b[n];
    for (int i = 0; i < n; ++i) {
      b[i] = count(a, a + n, i);
    }

    const int mx = *max_element(a, a + n);

    bool f = true;
    for (int i = 0; i < mx/2; ++i) {
      f = f && (b[i] == 0);
    }

    int mid = (mx + 1) / 2;
    for (int i = mid + 1; i <= mx; ++i) {
      b[i] -= 2;
    }
    if (mx % 2) b[mid] -= 2;
    else        b[mid] -= 1;
    f = f && (0 <= *min_element(b, b + n));
    
    f = f && (b[mid] == 0);
    
    cout << (f ? "Possible" : "Impossible") << endl;
  }
  
  return 0;
}
