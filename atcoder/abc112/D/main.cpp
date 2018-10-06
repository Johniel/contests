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

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  while (cin >> n >> m) {
    vector<int> v;
    for (int i = 1; i * i < m; ++i) {
      if (m % i == 0) {
        v.push_back(i);
        v.push_back(m / i);
      }
    }

    int x = 1;
    each (i, v) {
      int y = i * (m / i / n);
      if (y) {
        int z = y;
        if ((m / i) % n) z += i;
        x = max(x, __gcd(y, z));
      }
    }
    cout << x << endl;
  }
  
  return 0;
}
