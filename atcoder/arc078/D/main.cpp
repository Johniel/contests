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

vector<int> path;
bool rec(int curr, int prev, int target)
{
  if (curr == target) {
    path.push_back(curr);
    return true;
  }
  each (next, g[curr]) {
    if (next == prev) continue;
    if (rec(next, curr, target)) {
      path.push_back(curr);
      return true;
    }
  }
  return false;
}

int color[N];
void fn(int curr, int prev)
{
  if (color[curr] == 0) color[curr] = color[prev];
  each (next, g[curr]) {
    if (next == prev) continue;
    fn(next, curr);
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    fill(g, g + N, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    path.clear();
    rec(0, 0, n - 1);
    reverse(path.begin(), path.end());
    // cout << path << endl;

    fill(color, color + N, 0);

    for (int i = 0; i < path.size(); ++i) {
      if (i < (path.size() + 1) / 2) color[path[i]] = 1;
      else color[path[i]] = 2;
    }
    fn(0, 0);
    fn(n - 1, n - 1);

    // for (int i = 0; i < n; ++i) {
    //   cout << i + 1 << ' ' << color[i] << endl;
    // }    
    
    int x = count(color, color + N, 1);
    int y = count(color, color + N, 2);
    // cout << make_pair(x, y) << endl;
    cout << (x > y ? "Fennec" : "Snuke") << endl;
  }

  return 0;
}
