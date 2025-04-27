// github.com/Johniel/contests
// atcoder/abc403/F/main.cpp

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

const int N = 2000 + 3;
str memo[N][2]; // 0:add, 1:mul

int fn(int x)
{
  int len = 0;
  while (x) {
    ++len;
    if (x % 10 != 1) return -1;
    x /= 10;
  }
  return len;
 }

str fn(const str& a, const str& b) {
  if (a.size() < b.size()) return a;
  return b;
}

str rec(int n, int expr)
{
  if (n == 0) assert(false);
  str& ret = memo[n][expr];
  if (ret.size()) return ret;

  str mn(N, '_');
  if (!expr) {
    int x = fn(n);
    if (x != -1) mn = str(x, '1');
  }
  // (length "(1+1+1)*(1+1+1)")
  if (expr) {
    for (int i = 1; i < n; ++i) {
      mn = fn(mn, "(" + rec(i, true) + "+" + rec(n - i, true) + ")");
      mn = fn(mn, "(" + rec(i, false) + "+" + rec(n - i, true) + ")");
      mn = fn(mn, "(" + rec(i, true) + "+" + rec(n - i, false) + ")");
      mn = fn(mn, "(" + rec(i, false) + "+" + rec(n - i, false) + ")");
      if (n % i == 0 && i != 1) {
        int j = n / i;
        int A = fn(i);
        int B = fn(j);
        str a(max(0, A), '1');
        str b(max(0, B), '1');
        if (0 < A && 0 < B) {
          mn = fn(mn, a + "*" + b);
        }
        if (0 < A) {
          mn = fn(mn, a + "*" + rec(j, true));
        }
        if (B != -1) {
          mn = fn(mn, rec(i, true) + "*" + b);
        }
        mn = fn(mn, rec(i, true) + "*" + rec(j, true));
      }
    }
  } else {
    for (int i = 1; i < n; ++i) {
      mn = fn(mn, rec(i, true) + "+" + rec(n - i, true));
      mn = fn(mn, rec(i, false) + "+" + rec(n - i, true));
      mn = fn(mn, rec(i, true) + "+" + rec(n - i, false));
      mn = fn(mn, rec(i, false) + "+" + rec(n - i, false));
      if (n % i == 0 && i != 1) {
        int j = n / i;
        int A = fn(i);
        int B = fn(j);
        str a(max(0, A), '1');
        str b(max(0, B), '1');
        if (A != -1 && B != -1) {
          mn = fn(mn, a + "*" + b);
        }
        if (A != -1) {
          mn = fn(mn, a + "*" + rec(j, true));
        }
        if (B != -1) {
          mn = fn(mn, rec(i, true) + "*" + b);
        }
        mn = fn(mn, rec(i, true) + "*" + rec(j, true));
      }
    }
  }

  return ret = mn;
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    fill(&memo[0][0], &memo[N - 1][2 - 1] + 1, str(""));
    str a = rec(n, 0);
    str b = rec(n, 1);
    cout << fn(a, b) << endl;
  }
  return 0;
}
