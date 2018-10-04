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

  int n;
  while (cin >> n) {
    vector<string> v(n);
    each (i, v)
      cin >> i;
    bool f = set<string>(v.begin(), v.end()).size() == n;
    for (int i = 0; i + 1 < n; ++i) {
      f = f && (v[i].back() == v[i + 1].front());
    }
    cout << (f ? "Yes" : "No") << endl;
  }

  return 0;
}
