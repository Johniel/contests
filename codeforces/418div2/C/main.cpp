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
  string s;
  int q;
  while (cin >> n >> s >> q) {
    map<pair<int, char>, int> memo;
    while (q--) {
      int x;
      char c;
      cin >> x >> c;
      pair<int, char> key = make_pair(x, c);
      if (memo.count(key)) {
        cout << memo[key] << endl;
        continue;
      }
      int mx = 0;
      int begin = 0;
      int end = 0;
      int y = x;
      while (begin < s.size()) {
        while (end < s.size()) {
          if (s[end] != c && y == 0) break;
          y -= (s[end] != c);
          ++end;
        }
        mx = max(mx, end - begin);
        y += (s[begin++] != c);
      }
      cout << (memo[key] = mx) << endl;
    }
  }
  
  return 0;
}
