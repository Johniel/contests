// github.com/Johniel/contests
// codeforces/949div2/C/main.cpp

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

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n;
  while (cin >> n) {
    vec<lli> a(n);
    cin >> a;

    if (count(a.begin(), a.end(), -1) == a.size()) {
      for (int i = 0; i < a.size(); ++i) {
        if (i % 2) cout << 1 << ' ';
        else cout << 2 << ' ';
      }
      cout << endl;
      continue;
    }

    vec<int> idx;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] != -1) idx.push_back(i);
    }
    for (int i = 0; i + 1 < idx.size(); ++i) {
      int j = idx[i];
      int k = idx[i + 1];
      while (j + 1 < k) {
        if (a[j] == 1 && a[k] == 1) {
          a[j + 1] = 2;
          ++j;
        } else {
          if (a[j] < a[k]) {
            a[k - 1] = a[k] / 2;
            --k;
          } else {
            a[j + 1] = a[j] / 2;
            ++j;
          }
        }
      }
    }
    {
      int k = idx.front();
      while (0 <= k - 1) {
        if (a[k] == 1) a[k - 1] = 2;
        else           a[k - 1] = a[k] / 2;
        --k;
      }
    }
    {
      int k = idx.back();
      while (k + 1 < a.size()) {
        if (a[k] == 1) a[k + 1] = 2;
        else           a[k + 1] = a[k] / 2;
        ++k;
      }
    }
    bool f = true;
    for (int i = 0; i < a.size(); ++i) {
      f = f && (1 <= a[i] && a[i] <= 1e9);
    }
    for (int i = 0; i + 1 < a.size(); ++i) {
      bool x = false;
      bool y = false;
      if (a[i] == a[i + 1] / 2) x = true;
      if (a[i + 1] == a[i] / 2) y = true;
      f = f && (x || y);
    }
    unless (f) {
      cout << -1 << endl;
    } else {
      each (i, a) cout << i << ' '; cout << endl;
    }
  }
  return 0;
}
