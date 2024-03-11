// github.com/Johniel/contests
// codeforces/933div3/G/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define makepair(a, b) make_pair(a, b)
// #define endl "\n"

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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

const int N = 4 * (2 * 1e5) + 3;
vec<pair<int, int>> g[N];

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n, m;
  while (cin >> n >> m) {
    const int N = n + m + m;
    fill(g, g + N, vec<pair<int, int>>());
    map<int, int> repaint;
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      if (!repaint.count(c)) {
        int sz = repaint.size();
        repaint[c] = sz;
      }
      c = repaint[c];
      int x = n + (c * 2 + 0);
      int y = n + (c * 2 + 1);
      g[a].push_back(make_pair(x, 0));
      g[b].push_back(make_pair(x, 0));
      g[y].push_back(make_pair(b, 0));
      g[y].push_back(make_pair(a, 0));
    }
    for (int i = 0; i < repaint.size(); ++i) {
      int x = n + (i * 2 + 0);
      int y = n + (i * 2 + 1);
      g[x].push_back(make_pair(y, 1));
    }
    int src, dst;
    cin >> src >> dst;
    --src;
    --dst;
    const int inf = 1 << 29;
    int cost[N];
    fill(cost, cost + N, inf);
    cost[src] = 0;
    deque<int> q;
    q.push_back(src);
    while (q.size()) {
      int curr = q.front();
      q.pop_front();
      each (e, g[curr]) {
        auto [next, c] = e;
        if (cost[next] != inf) continue;
        if (c) {
          cost[next] = cost[curr] + 1;
          q.push_back(next);
        } else {
          cost[next] = cost[curr] + 0;
          q.push_front(next);
        }
      }
    }
    cout << cost[dst] << endl;
  }
  return 0;
}
