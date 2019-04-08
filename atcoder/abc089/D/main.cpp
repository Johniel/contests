// atcoder/abc089/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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

  int h, w, d;
  while (cin >> h >> w >> d) {
    const int H = 300 + 1;
    const int W = 300 + 1;

    int g[H][W];
    map<int, pair<int, int>> m;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
        m[g[i][j]] = {i, j};
      }
    }

    map<int, int> cnt;
    for (int src = 1; src <= d; ++src) {
      int curr = src;
      int sum = 0;
      while (curr <= h * w) {
        cnt[curr] = sum;
        int next = curr + d;
        pair<int, int> a = m[curr];
        pair<int, int> b = m[next];
        sum += abs(a.first - b.first) + abs(a.second - b.second);
        curr = next;
      }
      cnt[curr] = sum;
    }

    int q;
    cin >> q;
    while (q--) {
      int a, b;
      cin >> a >> b;
      cout << cnt[b] - cnt[a] << endl;
    }
  }

  return 0;
}
