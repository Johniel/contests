// atcoder/abc148/F/main.cpp
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

const int N = 1e5 + 5;
vector<int> g[N];

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a, b;
  while (cin >> n >> a >> b) {
    --a;
    --b;
    fill(g, g + N, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }

    const int inf = 1 << 29;
    int A[N];
    int B[N];
    fill(A, A + N, inf);
    fill(B, B + N, inf);
    A[a] = 0;
    B[b] = 0;
    {
      queue<int> q;
      for (q.push(b); q.size(); q.pop()) {
        int curr = q.front();
        each (next, g[curr]) {
          if (B[next] == inf) {
            B[next] = B[curr] + 1;
            q.push(next);
          }
        }
      }
    }
    int mx = 0;
    {
      queue<int> q;
      for (q.push(a); q.size(); q.pop()) {
        int curr = q.front();
        setmax(mx, B[curr] - 1);
        // cout << curr << endl;
        each (next, g[curr]) {
          if (A[next] == inf && A[curr] + 1 <= B[next]) {
            A[next] = A[curr] + 1;
            q.push(next);
          }
        }
      }
    }
    cout << mx << endl;
    // cout << endl;
  }


  return 0;
}
