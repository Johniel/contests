// github.com/Johniel/contests
// atcoder/abc398/F/main.cpp

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
  str s;
  while (cin >> s) {
    const int n = s.size();
    str r = s;
    reverse(r.begin(), r.end());
    const str t = r + "|" + s;
    // 500000
    vec<int> v = z_algorithm(t);

    // cout << t << endl << v << endl;

    int mn = (1 << 29);
    for (int i = s.size(); i < v.size(); ++i) {
      if (i + v[i] == v.size()) {
        int len = v[i] + (n - v[i]) * 2;
        setmin(mn, len);
      }
    }
    cout << s << flush;
    mn -= s.size();
    while (mn < s.size()) s.pop_back();
    reverse(s.begin(), s.end());
    cout << s << endl;
  }
  return 0;
}
