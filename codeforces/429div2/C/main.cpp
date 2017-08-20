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

  int m;
  while (cin >> m) {
    vector<pair<int, int>> a;
    for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      a.push_back(make_pair(x, i));
    }

    vector<pair<int, int>> b;
    for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      b.push_back(make_pair(x, i));
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    
    // each (i, a) cout << i << endl;
    // cout << endl;
    // each (i, b) cout << i << endl;
    // cout << endl;

    vector<int> c(m);
    for (int i = 0; i < m; ++i) {
      c[b[i].second] = a[i].first;
    }
    each (i, c) cout << i << ' ' ; cout << endl;
  }
  
  return 0;
}
