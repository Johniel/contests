// github.com/Johniel/contests
// codeforces/908div2/C/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

const int N = 2 * 1e5 + 3;
int dist[N];
map<int, vec<int>> g;
int n, k;
void rec(int curr, int d)
{
  each (e, g[curr]) {
    // int next = (curr - (e + 1) + n) % n;
    int next = (curr + (e + 1)) % n;
    if (dist[next] != -1) {
      // cout << curr << ' ' << next << ' ' << e << ' ' << dist[next] << ' ' << d << endl;
      if (dist[next] - d <= k) throw "";
      continue;
    }
    dist[next] = dist[curr] + 1;
    rec(next, d + 1);
  }

  return ;
}

int main(int argc, char *argv[])
{
  { int _; cin >> _; }

  while (cin >> n >> k) {
    vec<int> b(n);
    cin >> b;
    each (i, b) --i;

    if (n == 1) {
      cout << (b[0] == 0 ? "Yes" : "No") << endl;
      continue;
    }

    vec<int> v;
    for (int i = 0; i < b.size(); ++i) {
      if (b[i] < b.size()) {
        int x = (n + b[i] - i) % (n);
        x = (x - (b[i] + 1) + n) % n;
        v.push_back(x);
      } else {
        v.push_back(-1);
      }
    }

    g.clear();
    for (int i = 0; i < b.size(); ++i) {
      g[v[i]].push_back(b[i]);
    }

    g.erase(-1);
    // cout << v << endl;
    // each (i, g) cout << "> " << i.first << ' ' << i.second << endl;

    bool f = false;
    try {
      fill(dist, dist + n, -1);
      dist[0] = 0;
      rec(0, 0);
      if (k <= *max_element(dist, dist + n)) f = true;
    } catch (const char* e) {
      f = true;
    }
    cout << (f ? "Yes" : "No") << endl;
  }

  return 0;
}
