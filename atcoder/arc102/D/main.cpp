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

  int L;
  while (cin >> L) {
    int x = 0;
    for (int i = 0; (1 << i) <= L; ++i) {
      if (L & (1 << i)) {
        x = i;
      }
    }

    vector<tuple<int, int, int>> es;
    for (int i = 0; i < x; ++i) {
      es.push_back(make_tuple(i, i + 1, 1 << (x - i - 1)));
      es.push_back(make_tuple(i, i + 1, 0));
    }

    int y = 1 << x;
    for (int i = 0; i < x; ++i) {
      if (L & (1 << i)) {
        es.push_back(make_tuple(0, x - i, y));
        y += 1 << i;
      }
    }

    set<int> v;
    each (e, es) {
      v.insert(get<0>(e));
      v.insert(get<1>(e));
    }
    cout << v.size() << ' ' << es.size() << endl;
    each (e, es) {
      cout << get<0>(e) + 1 << ' ' << get<1>(e) + 1 << ' ' << get<2>(e) << endl;
      assert(get<0>(e) < get<1>(e));
    }
  }
  
  return 0;
}
