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

struct Acc {
  vector<lli> sum;
  Acc(vector<lli> v) {
    sum.push_back(0);
    each (i, v) {
      sum.push_back(sum.back() + i);
    }
  }
  lli query(lli begin, lli end) {
    return sum[end] - sum[begin];
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, q;
  while (cin >> n >> m >> q) {
    vector<lli> g[n];
    fill(g, g + n, vector<lli>(n, 0));

    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      ++g[a][b];
    }

    vector<Acc> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(Acc(g[i]));
    }

    while (q--) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      lli sum = 0;
      for (int i = a; i <= b; ++i) {
        sum += v[i].query(a, b + 1);
      }
      cout << sum << endl;
    }
  }
  
  return 0;
}
