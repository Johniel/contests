// github.com/Johniel/contests
// codeforces/946div3/D/main.cpp

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
  str s;
  while (cin >> n >> s) {

    if (s.size() == 4) {
      str t = "WESN";
      str u = s;
      sort(t.begin(), t.end());
      sort(u.begin(), u.end());
      if (u == t) {
        for (int i = 0; i < s.size(); ++i) {
          if (s[i] == 'S' || s[i] == 'N') cout << 'R';
          else cout << 'H';
        }
        cout << endl;
        continue;
      }
    }

    const int N = count(s.begin(), s.end(), 'N');
    const int E = count(s.begin(), s.end(), 'E');
    const int S = count(s.begin(), s.end(), 'S');
    const int W = count(s.begin(), s.end(), 'W');
    if (abs(N - S) % 2) {
      cout << "NO" << endl;
      continue;
    }
    if (abs(E - W) % 2) {
      cout << "NO" << endl;
      continue;
    }

    str t(s.size(), '_');
    map<char, int> freq;
    freq['N'] = N;
    freq['E'] = E;
    freq['S'] = S;
    freq['W'] = W;
    each (k, freq) {
      int rem = k.second / 2;
      for (int i = 0; i < s.size() && rem; ++i) {
        if (s[i] == k.first) {
          --rem;
          t[i] = 'R';
        }
      }
    }

    replace(t.begin(), t.end(), '_', 'H');
    if (count(t.begin(), t.end(), 'R') == t.size()) {
      cout << "NO" << endl;
      continue;
    }
    if (count(t.begin(), t.end(), 'H') == t.size()) {
      cout << "NO" << endl;
      continue;
    }
    cout << t << endl;
  }
  return 0;
}
