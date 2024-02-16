// github.com/Johniel/contests
// codeforces/926div2/F/main.cpp

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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

namespace math {
  // gcd(a,b)を返す。xとyにはax+by=±gcd(a,b)を満たす数を設定する。
  lli extgcd(lli a, lli b, lli& x, lli& y)
  {
    lli g = a;
    x = 1;
    y = 0;
    if (b != 0) {
      g = extgcd(b, a % b, y, x);
      y -= (a / b) * x;
    }
    return g;
  }

  lli mod_inverse(lli a, lli m)
  {
    lli x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
  }
};

const int N = 5 * 1e5 + 3;
int l[N];
int r[N];
int val[N];
vec<int> v;

void rec(int curr)
{
  if (0 <= l[curr]) rec(l[curr]);
  v.push_back(val[curr]);
  if (0 <= r[curr]) rec(r[curr]);
  return ;
}

int main(int argc, char *argv[])
{
  vec<lli> inv(N);
  for (int i = 1; i < N; ++i) {
    inv[i] = math::mod_inverse(i, mod);
  }

  { int _; cin >> _; }
  int n, C;
  while (cin >> n >> C) {
    for (int i = 0; i < n; ++i) {
      cin >> l[i] >> r[i] >> val[i];
      --l[i];
      --r[i];
    }
    v.clear();
    rec(0);
    if (v.front() == -1) v.insert(v.begin(), 1);
    if (v.back() == -1) v.push_back(C);
    vec<int> idx;
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] != -1) idx.push_back(i);
    }
    lli z = 1;
    for (int k = 0; k + 1 < idx.size(); ++k) {
      const int i = idx[k];
      const int j = idx[k + 1];
      unless (v[i] <= v[j]) {
        z = 0;
        break;
      }
      lli x = (v[j] - v[i] + 1);
      lli y = j - i - 1;
      lli w = 1;
      for (int k = 0; k < y; ++k) {
        w *= (x + y - k - 1) % mod;
        w %= mod;
        w *= inv[k + 1];
        w %= mod;
      }
      (z *= w) %= mod;
    }
    cout << z << endl;
  }
  return 0;
}
