// github.com/Johniel/contests
// atcoder/abc196/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

const lli inf = 1LL << 60;

struct Fn {
  lli _1, _2, _3;
  Fn() : _1(+inf), _2(-inf), _3(0) { }
  Fn(int t, lli a) : _1(+inf), _2(-inf), _3(0) {
    if (t == 1) _3 = a;
    if (t == 2) _2 = a;
    if (t == 3) _1 = a;
  }
  lli eval(lli x) const { return min(_1, max(_2, x + _3)); }
};

Fn operator | (const Fn& A, const Fn& B)
{
  Fn C;
  C._1 = min(A._1, max(A._2, B._1 + A._3));
  C._2 = max(A._2, min(B._2 + A._3, B._1 + A._3));
  C._3 = A._3 + B._3;
  return C;
}

ostream& operator << (ostream& os, Fn fn)
{
  os << "f(x) := min(" << fn._1 << ", max(" << fn._2 << ", x+" << fn._3 << "))";
  return os;
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    Fn fn;
    // cout << fn << endl;
    for (int i = 0; i < n; ++i) {
      lli a;
      int t;
      cin >> a >> t;
      // fn = fn | Fn(t, a);
      fn = Fn(t, a) | fn;
      // cout << fn << endl;
    }
    int q;
    cin >> q;
    while (q--) {
      lli x;
      cin >> x;
      cout << fn.eval(x) << endl;
    }
  }
  return 0;
}
