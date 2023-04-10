// github.com/Johniel/contests
// atcoder/abc297/E/main.cpp

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

vec<lli> a;
lli rec(int nth, lli k)
{
  if (a.size() == nth) return 1;
  // cout << nth << ' ' << k << endl;
  lli z = 0;
  for (int i = 0; i <= k / a[nth]; ++i) {
    z += rec(nth + 1, k - i * a[nth]);
  }
  return z;
}

lli fn(const lli k)
{
  priority_queue<lli> q;
  set<lli> fixed, inserted;
  q.push(0);
  inserted.insert(0);

  const lli mx = *min_element(a.begin(), a.end()) * k;

  while (fixed.size() <= k) {
    lli x = abs(q.top());
    q.pop();
    if (fixed.count(x)) continue;
    // cout << q.size() << ' ' << fixed.size() << ' ' << inserted.size() << endl;
    fixed.insert(x);
    each (i, a) {
      lli y = x + i;
      if (mx < y) continue;
      unless (inserted.count(y)) {
        inserted.insert(y);
        q.push(-y);
      }
    }
  }
  fixed.erase(0);
  auto itr = fixed.end();
  --itr;
  return *itr;
  // cout << k << ' ' << fixed.size() << endl;
  // return fixed.size() - 1;
}

int main(int argc, char *argv[])
{
  int n, k;
  while (cin >> n >> k) {
    a.resize(n);
    cin >> a;
    const lli inf = 1LL << 60;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        if (a[j] % a[i] == 0) {
          a[j] = inf;
        }
      }
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    while (a.back() == inf) a.pop_back();
    n = a.size();
    reverse(a.begin(), a.end());
    // cout << a << endl;

    cout << fn(k) << endl;

    // sort(a.begin(), a.end());
    // set<lli> vis;
    // for (int i = 0; i <= k; ++i) {
    //   vis.insert(i * a.front());
    // }

    // lli small = 0;
    // lli large = *min_element(a.begin(), a.end()) * k + 1;
    // while (small + 1 < large) {
    //   cout << make_pair(small, large) << endl;
    //   lli mid = (small + large) / 2;
    //   if (fn(mid)) small = mid;
    //   else large = mid;
    // }
    // cout << small << endl;
  }
  return 0;
}
