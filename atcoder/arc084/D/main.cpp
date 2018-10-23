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

  const int N = 1e5 + 10;
  
  int k;
  while (cin >> k) {
    const lli inf = 1LL << 60;
        
    priority_queue<pair<int, int>> q;

    lli cost[N];
    cost[0] = inf;
    for (int i = 1; i < N; ++i) {
      cost[i] = i;
      q.push({-i, i});
    }

    while (q.size()) {
      pair<int, int> p = q.top();
      q.pop();
      int c = -1 * p.first;
      int curr = p.second;
      // cout << curr << ' ' << c << ' ' << cost[curr] << endl;
      if (cost[curr] != c) continue;
      for (int i = 0; i <= 9; ++i) {
        int next = (curr * 10 + i) % k;
        lli d = c + i;
        if (cost[next] > d) {
          cost[next] = d;
          q.push({-d, next});
        }
      }
    }
    cout << cost[0] << endl;
  }
  
  return 0;
}
