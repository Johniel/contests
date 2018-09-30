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
    vector<int> v(n);
    each (i, v)
      cin >> i;
    map<int, int> a, b;
    for (int i = 0; i < v.size(); ++i) {
      if (i % 2) {
        ++a[v[i]];
      } else {
        ++b[v[i]];
      }
    }

    vector<pair<int, int>> p;
    p.push_back(make_pair(n / 2, 1 << 29));
    each (i, a) {
      p.push_back(make_pair(n / 2 - i.second, i.first));
    }
    sort(p.begin(), p.end());
    // reverse(p.begin(), p.end());

    vector<pair<int, int>> q;
    q.push_back(make_pair(n / 2, (1 << 29) - 1));
    each (i, b) {
      q.push_back(make_pair(n / 2 - i.second, i.first));
    }
    sort(q.begin(), q.end());
    // reverse(q.begin(), q.end());

    // cout << p << endl;
    // cout << q << endl;

    int mn = 1 << 28;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        if (p[i].second != q[j].second) {
          mn = min(mn, p[i].first + q[j].first);
        }
      }
    }
    cout << mn << endl;
  }

  return 0;
}
