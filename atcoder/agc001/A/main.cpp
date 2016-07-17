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
    vector<int> v;
    for (int i = 0; i < 2 * n; ++i) {
      int m;
      cin >> m;
      v.push_back(m);
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 0; i < v.size(); i += 2) {
      sum += v[i];
    }
    cout << sum << endl;
  }
  return 0;
}
