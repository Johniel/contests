// github.com/Johniel/contests
// atcoder/abc344/E/main.cpp

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

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<int> a(n);
    cin >> a;

    map<int, int> conv;
    map<int, int> rev;
    auto get = [&] (int x) {
      if (conv.count(x)) return conv[x];
      int y = conv.size();
      conv[x] = y;
      rev[y] = x;
      return y;
    };

    each (i, a) i = get(i);

    const int N = 2 * 2 * 1e5 + 3;
    static int next[N];
    static int prev[N];
    fill(next, next + N, -1);
    fill(prev, prev + N, -1);
    for (int i = 0; i + 1 < a.size(); ++i) {
      next[a[i]] = a[i + 1];
    }
    for (int i = 1; i < a.size(); ++i) {
      prev[a[i]] = a[i - 1];
    }
    set<int> vis;
    each (i, a) vis.insert(i);
    int q;
    cin >> q;
    while (q--) {
      int op, x, y;
      cin >> op;
      if (op == 1) {
        cin >> x >> y;
        x = get(x);
        y = get(y);
        int z = next[x];
        next[x] = y;
        next[y] = z;
        if (z != -1) prev[z] = y;
        prev[y] = x;
        vis.insert(y);
      }
      if (op == 2) {
        cin >> y;
        y = get(y);
        int x = prev[y];
        int z = next[y];
        if (x != -1) next[x] = z;
        if (z != -1) prev[z] = x;
        next[y] = prev[y] = -1;
        vis.erase(y);
      }
    }

    if (vis.size() == 1) {
      cout << rev[*vis.begin()] << endl;
    } else {
      int x = 0;
      for (int i = 0; i < N; ++i) {
        if (vis.count(i) == 0) continue;
        if (prev[i] == -1 && next[i] == -1) continue;
        if (prev[i] == -1) {
          x = i;
          break;
        }
      }
      for (int i = 0; i < vis.size(); ++i) {
        cout << rev[x] << ' ';
        x = next[x];
      }
      cout << endl;
    }
  }
  return 0;
}
