// codeforces/556div2/D/main.cpp
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

  int n, q;
  string s;
  while (cin >> n >> q >> s) {
    const int M = 100000 + 5;
    map<char, int> next[M];
    for (int i = s.size() - 1; 0 <= i; --i) {
      next[i] = next[i + 1];
      next[i][s[i]] = i;
    }

    const int inf = 1 << 29;
    const int N = 256;
    static int dp[N][N][N];
    fill(&dp[0][0][0], &dp[N - 1][N - 1][N - 1], inf);
    dp[0][0][0] = 0;

    int cnt[3] = {0, 0, 0};
    while (q--) {
      char op;
      int x;
      cin >> op >> x;
      --x;
      if (op == '-') {
        --cnt[x];
      } else {
        char c;
        cin >> c;
        int& a = dp[cnt[0]][cnt[1]][cnt[2]];
        ++cnt[x];
        int& b = dp[cnt[0]][cnt[1]][cnt[2]];
        if (b < inf) {
          setmin(a, next[b][c] + 1);
        }
      }
      cout << (dp[cnt[0]][cnt[1]][cnt[2]] != inf ? "YES" : "NO") << endl;
    }
  }

  return 0;
}
