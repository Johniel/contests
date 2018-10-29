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

  int h, w, n;
  while (cin >> h >> w >> n) {
    vector<int> a(n);
    cin >> a;

    vector<pair<int, int>> v;
    for (int i = 0; i < h; ++i) {
      if (i % 2) {
        for (int j = 0; j < w; ++j) {
          v.push_back(make_pair(i, j));
        }
      } else {
        for (int j = w - 1; 0 <= j; --j) {
          v.push_back(make_pair(i, j));
        }
      }
    }

    int g[h][w];
    int color = 1;
    each (i, a) {
      for (int j = 0; j < i; ++j) {
        pair<int, int> p = v.back();
        v.pop_back();
        g[p.first][p.second] = color;
      }
      ++color;
    }
    assert(v.empty());
    
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cout << g[i][j] << ' ';
      }
      cout << endl;
    }
  }

  return 0;
}
