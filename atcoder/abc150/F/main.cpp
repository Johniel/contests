// github.com/Johniel/contests
// atcoder/abc150/F/main.cpp

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

// s自身とすべてのsuffixとの共通接頭辞の文字数を返す。
// つまり、{|LCP(s[0], s.substring(0))|, |LCP(s[0], s.substring(1))|, |LCP(s[0], s.substring(2))|, ... }
// verified at ABC257G
vector<int> z_algorithm(const string& s)
{
  vector<int> v(s.size());
  v[0] = s.size();
  int i = 1, j = 0;
  while(i < s.size()){
    while(i + j < s.size() && s[j] == s[i + j]) j++;
    v[i] = j;

    if(j == 0){
      i++;
      continue;
    }
    int k = 1;
    while(k < j && k + v[k] < j){
      v[i + k] = v[k];
      k++;
    }
    i += k;
    j -= k;
  }
  return v;
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<int> a(n), b(n);
    cin >> a >> b;

    const int K = 3 * 2 * 1e5 + 3;
    static int m[K]; // m[k]=x
    static int cnt[K];
    fill(m, m + K, 0);
    fill(cnt, cnt + K, 0);

    const int W = 32;
    for (int nth = 0; nth < W; ++nth) {
      str s, t, u;
      const int y = (1 << nth);
      for (int i = 0; i < n; ++i) {
        s += '0' + (0 ^ !!(y & a[i]));
        u += '0' + (1 ^ !!(y & a[i]));
        t += '0' + !!(y & b[i]);
      }
      s = t + s + s;
      u = t + u + u;
      { // 0
        vec<int> v = z_algorithm(s);
        for (int i = n; i + n < v.size(); ++i) {
          if (n <= v[i]) {
            const int k = i - n;
            m[k] += (0 * y);
            ++cnt[k];
          }
        }
      }
      { // 1
        vec<int> v = z_algorithm(u);
        for (int i = n; i + n < v.size(); ++i) {
          if (n <= v[i]) {
            const int k = i - n;
            m[k] += (1 * y);
            ++cnt[k];
          }
        }
      }
    }

    vec<pair<int, int>> v;
    for (int i = 0; i < K; ++i) {
      if (cnt[i] == W) {
        v.push_back(make_pair(i, m[i]));
      }
    }
    sort(v.begin(), v.end());
    each (i, v) cout << i.first << ' ' << i.second << endl;
  }
  return 0;
}
