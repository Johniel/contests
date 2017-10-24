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
    vector<int> v;
    for (int i = 1; i < n; i += 2) {
      v.push_back(i);
    }
    for (int i = 0; i < n; i += 2) {
      v.push_back(i);
    }
    for (int i = 1; i < n; i += 2) {
      v.push_back(i);
    }
    cout << v.size() << endl;
    each (i, v) cout << i+1 << ' ' ; cout << endl;
  }
  
  return 0;
}
