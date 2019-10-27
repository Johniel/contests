// codeforces/595div3/B/main.cpp
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

  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    each (i, a) --i;

    const int N = 2 * 1e5 + 5;
    static int m[N];
    fill(m, m + N, -1);
    function<int(int, int, int)> rec = [&] (int curr, int prev, int cnt = 0) {
      if (m[curr] != -1) return m[curr];
      m[curr] = -2;
      int next = a[curr];
      if (m[next] == -2) return m[next] = cnt + 1;
      return m[next] = rec(next, curr, cnt+1);
    };

    for (int i = 0; i < n; ++i) {
      cout << rec(i, -1, 0) << ' ';
    }
    cout << endl;
  }

  return 0;
}
