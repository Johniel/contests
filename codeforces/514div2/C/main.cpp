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
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }

    vector<int> r;
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
      v.push_back(i);
    }

    int z = -1;
    while (1 < v.size()) {
      vector<int> u;
      for (int i = 0; i < v.size(); ++i) {
        if (v[i] % v[1]) {
          r.push_back(v[0]);
          z = v[i];
        } else {
          u.push_back(v[i]);
        }
      }
      v = u;
    }
    
    int x = v.back();
    int y = r.back();
    r.pop_back();

    r.push_back(__gcd(x, z));
    r.push_back(max(x, z));
    each (i, r) cout << i << ' ' ;
    cout << endl;
  }

  return 0;
}
