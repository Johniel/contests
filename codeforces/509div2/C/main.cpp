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

  lli n, m, d;
  while (cin >> n >> m >> d) {
    vector<int>  a(n);
    each (i, a) cin >> i;
    vector<int> b = a;
    
    map<int, int> ord;
    for (int i = 0; i < a.size(); ++i) {
      ord[a[i]] = i;
    }

    sort(a.begin(), a.end());
    
    int mx = 0;
    for (int i = 0; i < a.size(); ++i) {
      mx = max<int>(mx, upper_bound(a.begin(), a.end(), a[i] + d) - (a.begin() + i));
    }

    map<int, int> color;
    int cnt = 0;
    each (i, a) {
      color[i] = cnt++;
      cnt %= mx;
    }
    cout << mx << endl;
    each (i, b)  cout << color[i] + 1 << ' ';
    cout << endl;
  }

  return 0;
}
