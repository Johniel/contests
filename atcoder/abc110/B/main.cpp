#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template <typename P, typename Q>
ostream& operator<<(ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, vector<T> v)
{
  os << "(";
  each (i, v)
    os << i << ",";
  os << ")";
  return os;
}

int main(int argc, char* argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  int a, b;
  while (cin >> n >> m >> a >> b) {
    vector<int> x(n);
    vector<int> y(m);
    each (i, x)
      cin >> i;
    each (i, y)
      cin >> i;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    a = max(a, x.back()) + 1;
    b = min(b, y.front());
    cout << (a <= b ? "No War" : "War") << endl;
  }

  return 0;
}
