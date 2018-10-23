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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<int> a(n - 1), b(n - 1);
    cin >> a >> b;

    const int N = 1e5 + 10;
    int dp[N][4];
    fill(&dp[0][0], &dp[N - 1][4 - 1] + 1, -2);
    for (int i = 0; i < 4; ++i) {
      dp[0][i] = -1;
    }
    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < 4; ++j) {
        if (dp[i][j] == -2) continue;
        for (int k = 0; k < 4; ++k) {
          if ((j | k) == a[i] && (j & k) == b[i]) {
            dp[i + 1][k] = j;
          }
        }
      }
    }

    int path = -2;
    for (int i = 0; i < 4; ++i) {
      if (dp[a.size()][i] != -2) {
        path = i;
      }
    }
    if (path == -2) {
      cout << "NO" << endl;
      continue;
    }
    vector<int> t;
    for (int i = a.size(); 0 <= i; --i) {
      t.push_back(path);
      path = dp[i][path];
    }
    reverse(t.begin(), t.end());
    cout << "YES" << endl;
    each (i, t) cout << i << ' ' ;
    cout << endl;
  }
  
  return 0;
}
