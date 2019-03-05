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

  const int N = 100000 + 5;
  
  int n, m;
  while (cin >> n >> m) {
    vector<pair<int, lli>> g[N];
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].push_back({b, +c});
      g[b].push_back({a, -c});
    }

    map<int, lli> pos;
    set<int> vis;
    function<void(int)> rec = [&] (int curr) {
      vis.insert(curr);
      each (e, g[curr]) {
        int next = e.first;
        auto c = e.second;
        if (vis.count(next)) continue;
        pos[next] = pos[curr] + c;
        rec(next);
      }
      return ;
    };
    for (int i = 0; i < N; ++i) {
      if (vis.count(i)) continue;
      pos[i] = 0;
      rec(i);
    }
    
    bool f = true;
    for (int i = 0; i < N; ++i) {
      each (e, g[i]) {
        int src = i;
        int dst = e.first;
        auto c = e.second;
        f = (f && pos[dst] == (pos[src] + c));
      }
    }
    cout << (f ? "Yes" : "No") << endl;
  }
  
  return 0;
}
