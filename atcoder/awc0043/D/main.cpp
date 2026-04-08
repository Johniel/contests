// github.com/Johniel/contests
// atcoder/awc0043/D/main.cpp

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

template<typename T>
struct PrefixSum {
  vector<T> sum;
  PrefixSum(vector<T> v) {
    sum.push_back(T(0));
    for (int i = 0; i < v.size(); ++i) {
      sum.push_back(sum.back() + v[i]);
    }
  }
  T operator () (size_t begin, size_t end) const {
    assert(begin <= end);
    return sum.at(end) - sum.at(begin);
  }
  T operator () (size_t end) const { return (*this)(0, end); }
  size_t size(void) const { return (int)sum.size() - 1; }
};

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

template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<int128> a(n);
    cin >> a;
    sort(a.begin(), a.end());
    PrefixSum<int128> sum(a);
    int128 z = 0;
    for (int i = 0; i < a.size(); ++i) {
      z += sum(0, i) - (a[i] * i);
      z += (a[i] * i) - sum(i + 1, sum.size());
    }
    cout << -z << endl;
  }
  return 0;
}
