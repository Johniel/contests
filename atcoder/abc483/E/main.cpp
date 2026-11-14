// github.com/Johniel/contests
// atcoder/abc483/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& v) { os << "("; for (const auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, const set<T>& s) { os << "set{"; for (const auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, const map<K, V>& m) { os << "map{"; for (const auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (const auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, const deque<T>& q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
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

constexpr lli mod = 998244353; // 1e9 + 7;

struct UnionFind {
  vector<int> r, p;
  UnionFind(int n): r(n, 0), p(n, -1) {}
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (r[a] > r[b]) swap(a, b);
    p[b] += p[a];
    p[a] = b;
    if (r[a] == r[b]) ++r[b];
    return true;
  }
  int find(int a) {
    return (p[a] < 0) ? a : p[a] = find(p[a]);
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
  size_t size(int n) {
    return -p.at(find(n));
  }
};

const int N = 2 * 1e5 +3;
vec<int>  g[N];

int main(int argc, char *argv[])
{
  const int P = 27;

  int n, m;
  while (cin >> n >> m) {
    vec<str> v(n);
    cin >> v;

    vec<ull> u;
    vec<ull> w({1});
    for (int i = 0; i < 6; ++i) {
      w.push_back(w.back() * P);
    }
    // cout << w.back() * ('z' - 'a' + 1) << endl;

    unordered_map<str, int> freq;
    each (s, v) {
      ++freq[s];

      for (int i = 0; i < s.size(); ++i) {
        str t = s;
        t[i] = '.';
        ++freq[t];
      }
      for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j < s.size(); ++j) {
          str t = s;
          t[i] = '.';
          t[j] = '.';
          ++freq[t];
        }
      }
    }

    lli x = 0;
    lli y = 0;
    lli z = 0;
    for (int i = 0; i < v.size(); ++i) {
      const str& s = v[i];
      z += freq[s] - 1;

      for (int j = 0; j < m; ++j) {
        str t = s;
        t[j] = '.';
        x += (freq[t] - 1);
        // x += freq[t];
      }

      for (int j = 0; j < m; ++j) {
        for (int k = j + 1; k < m; ++k) {
          str t = s;
          t[j] = '.';
          t[k] = '.';
          y += (freq[t] - 1);
          // y += freq[t];
        }
      }

      // cout << s << ' ' << z << ' ' << x << ' ' << y << endl;
// abc 0 1 3
// abd 0 2 5
// bac 0 2 6

    }
    // cout << z/2 << endl;

    // cout << z << endl;
    // cout << x - z << endl;
    // cout << y - x + z << endl;

    // cout << z/2 << endl;
    // cout << (x - z * m) / 2 << endl;
    // cout << (y - (x * (m - 1) * m / 2) + (z * (m - 1))) / 2 << endl;

    // z*mパターンだけ重複する。
    lli b = x - (z * m);
    // lli c = y - (b * (m - 1)) + (z * (m - 1) * m / 2);
    // lli c = y - (b * (m - 1)) - (z * (m - 1) * m / 2);

    lli c = y - b - c;
    cout << (z + b + c) / 2 << endl;
  }
  return 0;
}
