// github.com/Johniel/contests
// codeforces/994div2/C/main.cpp

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

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n, x, y;
  while (cin >> n >> x >> y) {
    --x;
    --y;

    vec<int> a;
    for (int i = 0; i < n; ++i) {
      a.push_back(i % 2);
    }
    if (n % 2) a[0] = 2;

    auto fn = [&] (void) {
      for (int i = 0; i < a.size(); ++i) {
        vec<int> v;
        v.push_back(a.at((i + 1) % n));
        v.push_back(a.at((i - 1 + n) % n));
        if (i == x) v.push_back(a[y]);
        if (i == y) v.push_back(a[x]);
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        v.push_back(1 << 29);
        for (int j = 0; j < v.size(); ++j) {
          if (v[j] != j) {
            unless (j == a[i]) {
              return false;
            }
            break;
          }
        }
      }
      return true;
    };

    for (int i = 0; i <= 2; ++i) {
      for (int j = 0; j <= 2; ++j) {
        if (i == j) continue;
        for (int k = 0; k <= 2; ++k) {
          for (int l = 0; l <= 2; ++l) {
            for (int p = 0; p <= 2; ++p) {
              for (int q = 0; q <= 2; ++q) {
                a[x] = i;
                a[y] = j;
                a[(x - 1 + n) % n] = k;
                a[(x + 1 + 0) % n] = l;
                a[(y - 1 + n) % n] = p;
                a[(y + 1 + 0) % n] = q;
                if (fn()) {
                  p = q = k = l = i = j = (1 << 29);
                }
              }
            }
          }
        }
      }
    }

    each (i, a) cout << i << ' '; cout << endl;
    assert(fn());
  }
  return 0;
}
