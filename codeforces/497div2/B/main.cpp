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
    vector<pair<int, int>> v(n);
    each (i, v) cin >> i.first >> i.second;

    if (v[0].first < v[0].second) swap(v[0].first, v[0].second);
    for (int i = 0; i + 1 < v.size(); ++i) {
      if (v[i].first < v[i + 1].first) {
        swap(v[i + 1].first, v[i + 1].second);
      }
      if (v[i].first >= v[i + 1].second && v[i + 1].second > v[i + 1].first) {
        swap(v[i + 1].first, v[i + 1].second);
      }
    }
    
    bool flg = true;
    for (int i = 0; i + 1 < v.size(); ++i) {
      flg = flg && (v[i].first >= v[i + 1].first);
    }
    // each (i, v) cout << i.first << ' ' ; cout << endl;
    cout << (flg ? "YES" : "NO") << endl;
  }
  
  return 0;
}
