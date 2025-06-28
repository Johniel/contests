// github.com/Johniel/contests
// atcoder/abc412/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

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

constexpr lli mod = 998244353; // 1e9 + 7;

// https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409
std::vector<bool> sieve(lli L, lli R) {
  lli n = sqrt(R)+1;  // 念のため多めに
  std::vector<bool> aux(n, true);  // 小さい篩
  std::vector<bool> res(R-L, true);  // 大きい篩
  for (lli i = 2; i*i < n; ++i) {
    if (!aux[i]) continue;
    for (lli j = i*i; j < R; j += i)
      aux[j] = false;
    for (lli j = std::max(i, (L+i-1)/i)*i; j < R; j += i)
      res[j] = false;
  }
  return res;
}

// https://qiita.com/pell3221/items/0d1040ac74b052ec7e44
// vector<lli> segment_sieve(lli a, lli b) {


// https://atcoder.jp/contests/abc412/editorial/13387
vector<int> prime_enumerate(int N) {
  vector<bool> is_prime(N + 1, true);
  vector<int> primes;
  if (N < 2) return primes;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= N; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i) is_prime[j] = false;
    }
  }
  for (int i = 2; i <= N; ++i) {
    if (is_prime[i]) primes.push_back(i);
  }
  return primes;
}

int main(int argc, char *argv[])
{
  const int N = 1e7 + 5;
  static bool prime[N];
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for (lli i = 2; i * i < N; ++i) {
    for (lli j = 2; i * j < N; ++j) {
      prime[i * j] = false;
    }
  }
  vector<lli> ps;
  for (int i = 0; i < N; ++i) {
    if (prime[i]) ps.push_back(i);
  }

  lli L, R;
  while (cin >> L >> R) {
    vec<int> v(R - L, 0);
    lli z = 1;
    each (p, ps) {
      for (lli x = (L / p + 1) * p; x <= R; x += p) {
        if (v[x - (L + 1)]) continue;
        v[x - (L + 1)] = 1;
        lli y = x;
        while (y % p == 0) y /= p;
        if (y == 1) ++z;
      }
    }
    each (i, v) z += (i == 0);
    cout << z << endl;
  }
  return 0;
}
