// github.com/Johniel/contests
// atcoder/abc428/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;


using int128 = __int128;


int128 sto128(string &s)
{
  __int128 val = 0;
  for (int i = 0; i < s.size() && isdigit(s[i]); ++i) {
    val = (10 * val) + (s[i] - '0');
  }
  return val;
}

// https://kenkoooo.hatenablog.com/entry/2016/11/30/163533
ostream& operator << (ostream& os, __int128_t value)
{
  ostream::sentry s(os);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = end(buffer) - d;
    if (os.rdbuf()->sputn(d, len) != len) {
      os.setstate(ios_base::badbit);
    }
  }
  return os;
}

istream& operator >> (istream& is, int128& val)
{
  string s;
  is >> s;
  val = sto128(s);
  return is;
}



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

constexpr lli mod = 998244353; // 1e9 + 7;


int128 f1(str s)
{
  int128 n = 0;
  each (c, s) n = n * 10 + (c - '0');
  return n;
}

str f2(int128 n)
{
  str s;
  while (n) {
    s += '0' + (n % 10);
    n /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}

// https://scicomp.stackexchange.com/questions/36153/hack-for-using-hardware-to-take-square-roots-of-128-bit-numbers

typedef unsigned __int128 I;

#define LOG2(X) ((unsigned) (8*sizeof(ulong) - 1 - __builtin_clzl((X))))
/* log2 rounded down; works only in gcc */

inline long log2l(I x)
{
 ulong high, low;

 high = x>>64;
 if(high)
   return LOG2(high)+64;
 else {
  low = x&(~((ulong) 0));
  return LOG2(low);
 }
}

ulong sqrt128(I n)
/* returns floor of sqrt(n) */
/* works for 0<=n<2^{125} */
{
 int flag=0, k, be;
 ulong head, q, a1, num, den, s,sp,sp2,rp;
 I r;

 k = log2l(n); be=k/4+1;
 if((k%4)<2) {
   flag = 1;
   n <<= 2;
 }
 head = n>>(2*be);
 a1 = n - (head<<(2*be));
 a1 >>= be;

 sp = sqrtl(head); sp2 = sp*sp;
 if(head>sp2)
   rp = head-sp2;
 else {
   rp=(head+2*sp-1)-sp2;
   sp--;
 }

 /* So: sp = integer part of sqrt(head), rp = head-sp*sp */
 num = ((rp<<be)+a1); den = 2*sp;
 q = num/den;
 s = (sp<<be) + q;

 if(((I) s)*((I) s) > n)
   s--;

 if(flag)
   s >>= 1;

 return s;
}


int128 fn(int128 n)
{
  long double r = sqrtl((long double)n);
  int128 x = r;
  while ((x + 1) * (x + 1) <= n) ++x;
  while (x * x > n) --x;
  return x;
}

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  lli C;
  lli D;

  vec<int128> w;
  w.push_back(1);
  for (int i = 0; i < 200; ++i) w.push_back(w.back() * 10);

  while (cin >> C >> D) {
    int128 z = 0;

    for (int k = 1; k <= 11; ++k) {
      int128 mnX = max<int128>(1, w[k - 1] - C);
      int128 mxX = min<int128>(D, w[k] - 1 - C);
      unless (mnX <= mxX) continue;
      int128 base = C * w[k];
      int128 x = base + (C + mnX);
      int128 y = base + (C + mxX);

      int128 a = fn(x);
      int128 b = fn(y);

      if (a * a != x) ++a;

      z += max<int128>(0, b - a + 1);
    }
    cout << z << endl;
  }
  return 0;
}
