// github.com/Johniel/contests
// atcoder/abc394/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "set{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "map{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }
template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

const int N = 2 * 1e5 + 3;
vec<int> g[N];
vec<int> h[N];

int mx = -1;
int vis[N];
int rec(int curr, int prev)
{
  vis[curr] = true;
  vec<int> v;
  each (next, g[curr]) {
    if (next == prev) continue;
    v.push_back(rec(next, curr));
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int z = 1;
  for (int i = 0; i < v.size() && i < 3; ++i) {
    z += v[i];
  }
  int s = 1;
  for (int i = 0; i < v.size() && i < 4; ++i) {
    s += v[i];
  }
  setmax(mx, s * 3 + 2);
  return z;
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    fill(g, g + n, vec<int>());
    fill(h, h + n, vec<int>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    set<int> alk;
    for (int i = 0; i < n; ++i) {
      if (4 <= g[i].size()) alk.insert(i);
    }
    for (int i = 0; i < n; ++i) {
      each (j, g[i]) {
        if (4 <= g[i].size() && 4 <= g[j].size()) {
          h[i].push_back(j);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      g[i] = h[i];
    }
    mx = -1;
    fill(vis, vis + N, false);
    each (r, alk) {
      if (!vis[r]) {
        int x = rec(r, r);
        setmax(mx, x * 3 + 2);
      }
    }
    cout << mx << endl;
  }
  return 0;
}
