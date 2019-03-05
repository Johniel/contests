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

  int n, a, b, c;
  while (cin >> n >> a >> b >> c) {
    vector<int> v(n);
    cin >> v;

    const int inf = 1 << 29;
    int mn = inf;

    for (int bit = 0; bit < (1 << (n + n)); ++bit) {
      int y = bit;
      int sum = 0;
      int len[4] = {0, 0, 0, 0};
      for (int i = 0; i < v.size(); ++i) {
        const int x = y % 4;
        y /= 4;
        if (x != 3 && len[x]) sum += 10;
        len[x] += v[i];
      }
      unless (len[0] && len[1] && len[2]) continue;
      sum += abs(len[0] - a) + abs(len[1] - b) + abs(len[2] - c);
      setmin(mn, sum);
    }
    cout << mn << endl;
  }  
  return 0;
}
