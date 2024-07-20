// github.com/Johniel/contests
// atcoder/abc363/F/main.cpp

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


map<lli, pair<lli, lli>> m;

vec<lli> p;

map<lli, bool> memo;

vec<pair<lli, lli>> path;

bool rec(lli n)
{
  if (memo.count(n)) return memo[n];
  {
    str s = to_string(n);
    str t = s;
    reverse(t.begin(), t.end());
    if (t == s && count(s.begin(), s.end(), '0') == 0) {
      path.push_back(make_pair(n, -1));
      return memo[n] = true;
    }
  }

  each (k, m) {
    if (n < k.first) break;
    if (n % k.first == 0) {
      lli x = n / k.first;
      if (x != n && rec(x)) {
        path.push_back(k.second);
        return memo[n] = true;
      }
    }
  }
  return memo[n] = false;;
}

int main(int argc, char *argv[])
{
  for (lli i = 2; i <= (1e7); ++i) {
    str s = to_string(i);
    if (count(s.begin(), s.end(), '0')) continue;
    str t = s;
    reverse(t.begin(), t.end());
    lli a = stoll(s);
    lli b = stoll(t);
    if (a * b <= 1e12) m[a * b] = make_pair(a, b);
  }

  lli n;
  while (cin >> n) {

    memo.clear();
    path.clear();
    if (rec(n)) {
      reverse(path.begin(), path.end());
      str s;
      each (i, path) {
        if (s.size()) s += '*';
        s += to_string(i.first);
      }
      reverse(path.begin(), path.end());
      if (1 < path.size()) {
        each (i, path) {
          if (i.second != -1) {
            if (s.size()) s += '*';
            s += to_string(i.second);
          }
        }
      }
      if (s.size() <= 1000) cout << s << endl;
      else cout << -1 << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
