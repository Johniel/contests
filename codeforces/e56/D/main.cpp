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

const int N = 3 * 1e5 + 5;
vector<int> g[N];

int color[N];
int cnt[2];
bool rec(int curr, int c = 0)
{
  color[curr] = c;
  ++cnt[c];
  each (next, g[curr]) {
    if (color[next] == -1) {
      bool f = rec(next, c ^ 1);
      if (!f) return false;
    }
    if (color[next] == color[curr]) {
      return false;
    }
  }
  return true;
}

const lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli x[N];
  x[0] = 1;
  for (int i = 1; i < N; ++i) {
    x[i] = (x[i - 1] * 2) % mod;
  }
  
  int tc;
  while (cin >> tc) {    
    while (tc--) {

      int n, m;
      cin >> n >> m;

      fill(color, color + n, -1);
      fill(g, g + n, vector<int>());
      
      for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
      }

      vector<lli> v;
      bool f = true;
    
      for (int i = 0; i < n && f; ++i) {
        if (color[i] != -1) continue;
        cnt[0] = cnt[1] = 0;
        f = f && rec(i);

        if (cnt[0] + cnt[1] == 1) {
          v.push_back(3);
        } else {
          lli sum = 0;
          sum += (x[cnt[0]] + x[cnt[1]]) % mod;
          sum %= mod;
          v.push_back(sum);
        }
      }

      lli sum = f ? 1 : 0;
      each (i, v) {
        (sum *= i) %= mod;
      }
      cout << sum << endl;
    }
  }  
  return 0;
}
