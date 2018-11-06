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

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    vector<pair<int, int>> c(m);
    cin >> c;

    const int N = 1e5 + 5;
    map<int, int> cnt[N];

    vector<pair<int, int>> d = c;
    sort(d.begin(), d.end(), [] (auto a, auto b) { return a.second < b.second; });
    each (i, d) {
      int x = cnt[i.first].size();
      cnt[i.first][i.second] = x;
    }

    each (i, c) {
      printf("%06d%06d\n", i.first, cnt[i.first][i.second] + 1);
    }
  }
  
  return 0;
}
