// github.com/Johniel/contests
// atcoder/abc454/E/main.cpp

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

str fn1(int n, int a, int b)
{
  if (n % 2) return str();
  unless (a % 2 == 0 && b % 2) return str();
  str s;
  int h = 0;
  for (int i = 0; i < n; ++i) {
    if (h == a) {
      // s += '|';
      int w = 0;
      while (w + 2 < b) {
        s += "DRUR";
        w += 2;
      }
      s += "DR";
      w += 1;
      while (w + 2 < n) {
        s += "RURD";
        w += 2;
      }
      h += 2;
      // s += '|';
      break;
    } else {
      s += str(n - 1, 'R');
      s += "D";
      ++h;
      s += str(n - 1, 'L');
      s += "D";
      ++h;
    }
  }
  while (h < n) {
    s += "D";
    ++h;
    s += str(n - 1, 'L');
    s += "D";
    ++h;
    s += str(n - 1, 'R');
  }
  // s.pop_back();
  return s;
}

str fn2(int n, int a, int b)
{
  if (n % 2) return str();
  unless (a % 2 && b % 2 == 0) return str();
  str s;
  int w = 0;
  for (int j = 0; j < n; ++j) {
    if (w == b) {
      // s += '|';
      int h = 0;
      while (h + 2 < a) {
        s += "RDLD";
        h += 2;
      }
      s += "RD";
      h += 1;
      while (h + 2 < n) {
        s += "DLDR";
        h += 2;
      }
      w += 2;
      // s += '|';
      break;
    } else {
      s += str(n - 1, 'D');
      s += "R";
      ++w;
      s += str(n - 1, 'U');
      s += "R";
      ++w;
    }
  }
  while (w < n) {
    s += "R";
    ++w;
    s += str(n - 1, 'U');
    s += "R";
    ++w;
    s += str(n - 1, 'D');
  }
  // s.pop_back();
  return s;
}


int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n, a, b;
  while (cin >> n >> a >> b) {
    if (n == 2) {
      if (a == 1 && b == 2) {
        cout << "Yes" << endl;
        cout << "DR" << endl;
        continue;
      }
      if (a == 2 && b == 1) {
        cout << "Yes" << endl;
        cout << "RD" << endl;
        continue;
      }
    }
    --a;
    --b;
    str s = fn1(n, a, b);
    str t = fn2(n, a, b);
    if (0) ;
    else if (s.size()) cout << "Yes" << endl << s << endl;
    else if (t.size()) cout << "Yes" << endl << t << endl;
    else cout << "No" << endl;
  }
  return 0;
}
