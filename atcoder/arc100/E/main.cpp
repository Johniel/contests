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

  int k;
  while (cin >> k) {
    vector<int> a(1 << k);
    each (i, a) cin >> i;

    // http://d.hatena.ne.jp/todo314/20120614/1339695202

    pair<int, int> mx[a.size()];
    for (int i = 0; i < a.size(); ++i) {
      mx[i] = make_pair(a[i], 0);
    }
    auto merge = [&] (int i, int j) {
      vector<int> v({mx[i].first, mx[i].second, mx[j].first, mx[j].second});
      sort(v.begin(), v.end());
      reverse(v.begin(), v.end());
      mx[i] = make_pair(v[0], v[1]);
    };
    for (int i = 0; i < k; ++i) {
      for (int bit = 0; bit < (1 << k); ++bit) {
        if (bit & (1 << i)) {
          merge(bit, bit ^ (1 << i));
        }
      }
    }

    int x = mx[0].first + mx[1].second;
    for (int i = 1; i < a.size(); ++i) {
      x = max(x, mx[i].first + mx[i].second);
      cout << x << endl;
    }
  }
  
  return 0;
}
