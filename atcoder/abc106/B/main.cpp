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

int f(int n) {
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cnt += (n % i == 0);
  }
  return cnt;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      cnt += (f(i) == 8) && i % 2 == 1;
    }
    cout << cnt << endl;
  }
  
  return 0;
}
