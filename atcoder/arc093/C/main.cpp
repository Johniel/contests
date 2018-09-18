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

  int n;
  while (cin >> n) {
    vector<int> a(n);
    each (i, a) cin >> i;
    a.push_back(0);
    a.insert(a.begin(), 0);
    
    lli sum = 0;
    for (int i = 0; i + 1 < a.size(); ++i) {
      sum += abs(a[i] - a[i + 1]);
    }

    for (int i = 1; i + 1 < a.size(); ++i) {
      lli x = sum;
      x -= abs(a[i - 1] - a[i]);
      x += abs(a[i - 1] - a[i + 1]);
      x -= abs(a[i + 1] - a[i]);
      cout << x << endl;
    }
  }
  
  return 0;
}
