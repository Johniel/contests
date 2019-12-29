// atcoder/abc149/D/main.cpp
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

  int n, k;
  int r, s, p;
  string t;
  while (cin >> n >> k >> r >> s >> p >> t) {
    for (int i = 0; i < t.size(); ++i) {
      t[i] = toupper(t[i]);
    }

    map<char, char> win;
    win['P'] = 'S';
    win['S'] = 'R';
    win['R'] = 'P';

    const int N = 1e5 + 5;
    static bool vis[N];
    fill(vis, vis + N, false);

    vector<string> v;
    for (int i = 0; i < t.size(); ++i) {
      if (vis[i]) break;
      string x;
      for (int j = i; j < t.size(); j += k) {
        x += t[j];
        vis[j] = true;
      }
      v.push_back(x);
    }
    // cout << v << endl;

    const int R = 0;
    const int P = 1;
    const int S = 2;
    const int X = 3;

    map<int, char> rev;
    rev[R] = 'R';
    rev[P] = 'P';
    rev[S] = 'S';

    auto score = [&] (char c) {
      if (c == R) return r;
      if (c == P) return p;
      if (c == S) return s;
      assert(false);
    };

    lli sum = 0;
    each (x, v) {
      const int M = 4;
      static lli dp[N][M];

      for (int i = 0; i < x.size() + 2; ++i) {
        for (int j = 0; j < M; ++j) {
          dp[i][j] = -(1LL << 60);
        }
      }

      dp[0][X] = 0;
      for (int i = 0; i < x.size(); ++i) {
        for (int last = 0; last <= 3; ++last) {
          if (dp[i][last] < 0) continue;
          for (int next = 0; next < 3; ++next) {
            if (last == next) continue;
            assert(rev[next]);
            if (win[x[i]] == rev[next]) {
              setmax(dp[i + 1][next], dp[i][last] + score(next));
            } else {
              setmax(dp[i + 1][next], dp[i][last]);
            }
          }
        }
      }
      lli mx = 0;
      for (int i = 0; i < x.size() + 2; ++i) {
        for (int j = 0; j < M; ++j) {
          setmax(mx, dp[i][j]);
        }
      }
      sum += mx;
    }
    cout << sum << endl;
  }

  return 0;
}
