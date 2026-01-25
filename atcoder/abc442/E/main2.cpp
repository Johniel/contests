// github.com/Johniel/contests
// atcoder/abc442/E/main.cpp

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


// [-M_PI,+M_PI]の範囲で偏角を返す。
double angle(double x, double y)
{
  return atan2(y, x);
}

// https://betrue12.hateblo.jp/entry/2020/01/05/151244
// https://codeforces.com/contest/1284/submission/68206915
template<typename Pair>
void argument_sort(vector<Pair>& A){
    auto orthant = [](Pair& a){
        if(a.second >= 0) return (a.first >= 0 ? 0 : 1);
        else return (a.first >= 0 ? 3 : 2);
    };
    vector<Pair> tmp[4];
    for(auto& p : A) tmp[orthant(p)].emplace_back(p);
    A.clear();
    for(int k=0; k<4; k++){
        sort(tmp[k].begin(), tmp[k].end(), [](auto& p1, auto& p2){ return (int64_t(p1.first)*p2.second - int64_t(p2.first)*p1.second > 0); });
        for(auto& p : tmp[k]) A.emplace_back(p);
    }
}

int main(int argc, char *argv[])
{
  int n, q;
  while (cin >> n >> q) {
    vec<pair<lli, lli>> v(n);
    cin >> v;
    map<pair<lli, lli>, int> dup;
    vec<pair<lli, lli>> u;
    {
      each (p, v) {
        auto [i, j] = p;
        lli div = __gcd(i, j);
        div = abs(div);
        i /= div;
        j /= div;
        p.first = i;
        p.second = j;
        ++dup[p];
        if (dup[p] == 1) u.push_back(p);
      }
    }
    argument_sort<pair<lli, lli>>(u);
    map<pair<lli, lli>, int> idx;
    for (int i = 0; i < u.size(); ++i) {
      idx[u[i]] = i;
    }
    // cout << dup << endl;
    // cout << u << endl;
    vec<int> w;
    each (i, u) w.push_back(dup[i]);
    for (int i = 0; i < u.size(); ++i) {
      w.push_back(w[i]);
    }
    PrefixSum<int> sum(w);
    while (q--) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      swap(a, b);
      a = idx[v[a]];
      b = idx[v[b]];
      unless (a <= b) b += u.size();
      cout << sum(a, b + 1) << endl;
    }
  }
  return 0;
}
