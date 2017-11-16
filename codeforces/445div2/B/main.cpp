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
    vector<int> v(n);
    each (i, v) cin >> i;

    const int c = set<int>(v.begin(), v.end()).size();
    reverse(v.begin(), v.end());

    int x = 0;
    set<int> vis;
    each (i, v) {
      vis.insert(i);
      if (vis.size() == c) {
        x = i;
        break;
      }
    }
    cout << x << endl;
  }
  
  return 0;
}
