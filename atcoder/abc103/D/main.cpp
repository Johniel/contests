#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    const int BEGIN = 1;
    const int END = 0;
    vector<tuple<int, int, int>> v;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      v.push_back(make_tuple(a, BEGIN, i));
      v.push_back(make_tuple(b, END, i));
    }
    v.push_back(make_tuple(1 << 29, END, m));
    sort(v.begin(), v.end());
    int cnt = 0;
    set<int> vis;
    for (int i = 0, j = 0; i < v.size(); ++i) {
      int a, b, c;
      tie(a, b, c) = v[i];
      if (b == END && vis.count(c) == 0) {
        if (i + 1 == v.size()) break;
        ++cnt;
        while (j <= i) {
          int x, y, z;
          tie(x, y, z) = v[j];
          vis.insert(z);
          ++j;
        }
      }
    }
    cout << cnt << endl;
  }
  
  return 0;
}
