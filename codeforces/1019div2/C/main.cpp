// github.com/Johniel/contests
// codeforces/1019div2/C/main.cpp

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

bool f010(vec<int> a, int k)
{
  deque<int> q;
  int x = 0;
  int y = 0;
  int z = 0;
  each (i, a) {
    int w = (i <= k ? -1 : +1);
    q.push_back(w);
    z += w;
  }
  // auto tmp = q;
  while (q.size()) {
    x += q.front();
    z -= q.front();
    q.pop_front();
    if (x <= 0) break;
  }
  if (q.empty()) return false;
  while (q.size()) {
    y += q.back();
    z -= q.back();
    q.pop_back();
    if (y <= 0) break;
  }
  if (q.empty()) return false;
  // cout << x << ' ' << z << ' ' << y << ' ' << endl; cout << tmp << endl;
  return true;
}


bool f001(vec<int> a, int k)
{
  vec<int> b({0});
  each (i, a) {
    b.push_back(i <= k ? -1 : +1);
  }
  for (int i = 0; i + 1 < b.size(); ++i) {
    b[i + 1] += b[i];
  }
  set<pair<int, int>> vis;
  for (int i = 1; i < b.size(); ++i) {
    vis.insert(make_pair(b[i], i));
  }
  for (int i = 1; i < b.size(); ++i) {
    vis.erase(make_pair(b[i], i));
    if (b[i] <= 0) {
      auto itr = vis.lower_bound(make_pair(b[i], i));
      if (itr != vis.end() && itr->first <= b[i]) return true;
    }
  }

  return false;
}

bool f100(vec<int> a, int k)
{
  reverse(a.begin(), a.end());
  return f001(a, k);
}

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n, k;
  while (cin >> n >> k) {
    vec<int> a(n);
    cin >> a;
    bool f = false;
    f = (f || f010(a, k));
    f = (f || f100(a, k));
    f = (f || f001(a, k));
    cout << (f ? "Yes" : "No") << endl;

  }
  return 0;
}
