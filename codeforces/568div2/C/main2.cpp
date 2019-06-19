// codeforces/568div2/C/main2.cpp
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

  int n, m;
  while (cin >> n >> m) {
    vector<int> v(n);
    cin >> v;

    const int N = 101;
    int cnt[N];
    fill(cnt, cnt + N, 0);

    vector<int> u;
    for (int i = 0; i < v.size(); ++i) {
      lli sum = v[i];
      int x = 0;
      for (int j = 0; j < N; ++j) {
        if (sum + cnt[j] * j <= m) {
          x += cnt[j];
          sum += cnt[j] * j;
        } else {
          int y = (m - sum) / j;
          x += y;
          break;
        }
      }
      ++cnt[v[i]];
      u.push_back(i - x);
    }

    each (i, u) cout << i << ' '; cout << endl;
  }

  return 0;
}
