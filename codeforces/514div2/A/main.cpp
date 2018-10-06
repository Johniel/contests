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

  int n, l, a;
  while (cin >> n >> l >> a) {
    vector<pair<int, int>> v(n);
    each (i, v) cin >> i.first >> i.second;
    v.push_back(make_pair(0, 0));
    v.push_back(make_pair(l, 0));
    sort(v.begin(), v.end());

    int cnt = 0;
    for (int i = 0; i + 1 < v.size(); ++i) {
      cnt += (v[i + 1].first - (v[i].first + v[i].second)) / a;
    }
    cout << cnt << endl;
  }
  
  return 0;
}
