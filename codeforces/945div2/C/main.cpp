// github.com/Johniel/contests
// codeforces/945div2/C/main.cpp

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

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int eval(vec<int> v)
{
  int z = 0;
  for (int i = 1; i + 1 < v.size(); ++i) {
    z += (v[i - 1] < v[i] && v[i] > v[i + 1]);
  }
  return z;
}

vec<int> fn1(vec<int> a)
{
  const int n = a.size();
  vec<pair<int, int>> v;
  for (int i = 0; i < a.size(); i += 2) {
    v.push_back(make_pair(a[i], i));
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  vec<int> b(n, -999);
  for (int i = 0; i < v.size(); ++i) {
    b[v[i].second] = i + 1;
  }
  v.clear();
  for (int i = 1; i < a.size(); i += 2) {
    v.push_back(make_pair(a[i], i));
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); ++i) {
    b[v[i].second] = n - i;
  }
  return b;
}

vec<int> fn2(vec<int> a)
{
  reverse(a.begin(), a.end());
  vec<int> b = fn1(a);
  reverse(b.begin(), b.end());
  return b;
}

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n;
  while (cin >> n) {
    vec<int> a(n);
    cin >> a;
    vec<int> b1 = fn1(a);
    vec<int> b2 = fn2(a);
    vec<int> v;
    vec<int> c1, c2;
    for (int i = 0; i < a.size(); ++i) {
      c1.push_back(a[i] + b1[i]);
      c2.push_back(a[i] + b2[i]);
    }
    if (eval(c1) < eval(c2)) v = b2;
    else v = b1;
    // cout << make_pair(eval(c1), eval(c2)) << endl;
    // cout << b1 << endl;
    // cout << c1 << endl;
    // cout << b2 << endl;
    // cout << c2 << endl;
    each (i, v) cout << i << ' '; cout << endl;
  }
  return 0;
}
