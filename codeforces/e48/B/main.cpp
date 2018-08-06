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

  int n, m, q;
  string s, t;
  while (cin >> n >> m >> q >> s >> t) {
    s += "$";

    const int N = n + 2;
    int occ[N];
    fill(occ, occ + N, 0);

    for (int i = 0; i < n; ++i) {
      bool f = true;
      for (int j = 0; f && j < m; ++j) {
        f = f && (s[i + j] == t[j]);
      }
      occ[i + 1] += f;
    }
    // for (int i = 0; i < N; ++i) cout << i << ' ' << occ[i] << endl;
    for (int i = 0; i <= n; ++i) occ[i + 1] += occ[i];
    // for (int i = 0; i < N; ++i) cout << i << ' ' << occ[i] << endl;
    
    while (q--) {
      int begin;
      int end;
      cin >> begin >> end;
      if (end - begin + 1 < m) {
        cout << 0 << endl;
        continue;
      }
      cout << occ[end - m + 1] - occ[begin - 1] << endl;
      // cout << make_pair(begin, end) << ' ' << make_pair(end - m + 1, begin - 1) << endl;
    }
    // cout << endl;
    // return 0;
  }
  
  return 0;
}
