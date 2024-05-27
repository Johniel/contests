// github.com/Johniel/contests
// atcoder/abc355/E/main.cpp

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

int main(int argc, char *argv[])
{
  map<pair<int, int>, pair<int, int>> label;
  vec<pair<int, int>> es;
  for (int i = 0; i <= 18; ++i) {
      for (int j = 0; j <= (1 << 18); ++j) {
      lli a = (1LL << i) * j;
      lli b = (1LL << i) * (j + 1);
      if (b <= (1 << 18)) {
        es.push_back(make_pair(a, b));
        label[es.back()] = make_pair(i, j);
      } else {
        break;
      }
    }
  }
  map<int, vec<int>> g;
  each (e, es) {
    if (e.first == e.second) continue;
    g[e.first].push_back(e.second);
    g[e.second].push_back(e.first);
  }

  int n, L, R;
  while (cin >> n >> L >> R) {
    ++R;
    map<int, int> path;
    path[L] = L;
    queue<int> q;
    for (q.push(L); q.size() && !path.count(R); q.pop()) {
      int curr = q.front();
      each (next, g[curr]) {
        if (path.count(next)) continue;
        path[next] = curr;
        q.push(next);
      }
    }
    assert(path.count(R));

    vec<int> v;
    int x = R;
    while (x != L) {
      v.push_back(x);
      x = path[x];
    }
    v.push_back(L);
    reverse(v.begin(), v.end());

    int z = 0;
    for (int i = 0; i + 1 < v.size(); ++i) {
      int a = min(v[i], v[i + 1]);
      int b = max(v[i], v[i + 1]);
      pair<int, int> key = make_pair(a, b);
      assert(label.count(key));
      pair<int, int> p = label[key];
      cout << "? " << p.first << ' ' << p.second << endl;
      int c;
      cin >> c;
      if (v[i] < v[i + 1]) z += c;
      else z -= c;
      z = (z + 100) % 100;
    }
    cout << "! " << z << endl;
  }
  return 0;
}
