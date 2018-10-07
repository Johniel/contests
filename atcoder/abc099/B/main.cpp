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

template<typename P, typename Q>
istream& operator >> (istream& is, pair<P, Q>& p)
{
  is >> p.first >> p.second;
  return is;
}

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

template<typename T>
istream& operator >> (istream& is, vector<T>& v)
{
  each (i, v) is >> i;
  return is;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b;
  while (cin >> a >> b) {
    const int N = 1000;
    lli c[N];
    c[0] = 0;
    for (int i = 1; i < N; ++i) {
      c[i] = c[i - 1] + i;
    }
    for (int i = 0; i + 1 < N; ++i) {
      if (b - a == c[i + 1] - c[i]) {
        cout << c[i] - a << endl;
      }
    }
  }
  
  return 0;
}
