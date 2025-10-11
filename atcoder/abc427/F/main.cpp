// github.com/Johniel/contests
// atcoder/abc427/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
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

// constexpr lli mod = 998244353; // 1e9 + 7;

unordered_map<lli, lli> a0, a1;
unordered_map<lli, lli> b0, b1;

lli mod;

vec<lli> a;
void reca(int idx, lli sum, bool prev)
{
  if (idx == a.size()) {
    if (prev) ++a1[sum];
    else ++a0[sum];
    return ;
  }

  if (prev) {
    reca(idx + 1, sum, false);
  } else {
    reca(idx + 1, (sum + a[idx]) % mod, true);
    reca(idx + 1, sum, false);
  }

  return ;
}

vec<lli> b;
void recb(int idx, lli sum, bool prev, bool head)
{
  if (idx == b.size()) {
    if (head) ++b1[sum];
    else ++b0[sum];
    return ;
  }

  if (prev) {
    recb(idx + 1, sum, false, head);
  } else {
    if (idx == 0) {
      recb(idx + 1, (sum + b[idx]) % mod, true, true);
      recb(idx + 1, sum, false, false);
    } else {
      recb(idx + 1, (sum + b[idx]) % mod, true, head);
      recb(idx + 1, sum, false, head);
    }
  }

  return ;
}

int main(int argc, char *argv[])
{
  // 9<=log10(2^30)
  int n;
  while (cin >> n >> mod) {
    a.resize(n);
    cin >> a;

    if (n == 1) {
      cout << 1 + (a.front() % mod == 0) << endl;
      continue;
    }

    b.clear();
    while (n / 2 < a.size()) {
      b.push_back(a.back());
      a.pop_back();
    }
    reverse(b.begin(), b.end());

    a0.clear();
    a1.clear();
    b0.clear();
    b1.clear();

    // for (int bit = 0; bit < (1 << a.size()); ++bit) {
    //   bool f = true;
    //   lli z = 0;
    //   for (int i = 0; i < a.size(); ++i) {
    //     int j = i + 1;
    //     if ((bit & (1 << i)) && (bit & (1 << j))) { f = false; break; }
    //     if (bit & (1 << i)) (z += a[i]) %= mod;
    //   }
    //   if (f) {
    //     if (bit & (1 << (a.size() - 1))) ++a1[z];
    //     else ++a0[z];
    //   }
    // }

    // for (int bit = 0; bit < (1 << b.size()); ++bit) {
    //   bool f = true;
    //   lli z = 0;
    //   for (int i = 0; i < b.size(); ++i) {
    //     int j = i + 1;
    //     if ((bit & (1 << i)) && (bit & (1 << j))) { f = false; break; }
    //     if (bit & (1 << i)) (z += b[i]) %= mod;
    //   }
    //   if (f) {
    //     if (bit & (1 << 0)) ++b1[z];
    //     else ++b0[z];
    //   }
    // }
    reca(0, 0, false);
    recb(0, 0, false, false);

    lli z = 0;
    each (k, a0) {
      lli x = (mod - k.first) % mod;
      if (b0.count(x)) z += k.second * b0[x];
      if (b1.count(x)) z += k.second * b1[x];
    }
    each (k, a1) {
      lli x = (mod - k.first) % mod;
      if (b0.count(x)) z += k.second * b0[x];
    }
    cout << z << endl;
    // break;
  }
  return 0;
}
