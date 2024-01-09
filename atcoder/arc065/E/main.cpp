// github.com/Johniel/contests
// atcoder/arc065/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

template<typename T = long long int>
struct BIT {
  vector<T> v;
  const int n;

  BIT(int n_ = 0) : n(n_), v(n_ + 1, 0) {}

  T operator () (int i) const {
    T s = 0;
    while (i > 0) {
      s += v.at(i);
      i -= i & -i;
    }
    return s;
  }

  T query(int begin, int end) const {
    assert(begin <= end);
    return (*this)(end) - (*this)(begin);
  }

  T operator () (int begin, int end) const {
    return query(begin, end);
  }

  void add(int i, T x) {
    ++i;
    while (i <= n) {
      v.at(i) += x;
      i += i & -i;
    }
    return ;
  }

  size_t lower_bound(const T query) const {
    int small = 0;
    int large = v.size();
    while (small + 1 < large) {
      auto mid = (small + large) / 2;
      if ((*this)(mid) <= query) small = mid;
      else large = mid;
    }
    if (query <= (*this)(small)) return small;
    if (query <= (*this)(large)) return large;
    return size();
  }

  size_t size(void) const { return n; }
};

template<typename T>
T manhattan_distance(pair<T, T> a, pair<T, T> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

// (x,y) => (x-y,x+y)
// manhattan_rot45 ignores 1/sqrt(2)
// マンハッタン距離の45度回転後はチェビシェフ距離
template<typename T>
pair<T, T> manhattan_rot45(pair<T, T> p) {
  return make_pair(p.first - p.second, p.first + p.second);
}

template<typename T>
T chebyshev_distance(pair<T, T> a, pair<T, T> b) {
  return max(abs(a.first - b.first), abs(a.second - b.second));
}

template<typename T>
T chebyshev_distance(vector<T> a, vector<T> b) {
  assert(a.size() == b.size());
  T mx = std::numeric_limits<T>::min();
  for (int i = 0; i < a.size(); ++i) {
    mx = max(mx, abs(a[i] - b[i]));
  }
  return mx;
}


int main(int argc, char *argv[])
{
  int n, a, b;
  while (cin >> n >> a >> b) {
    --a;
    --b;
    vec<pair<lli, lli>> v(n);
    cin >> v;
    each (i, v) i = manhattan_rot45(i);
    // cout << v << endl;
    map<pair<lli, lli>, int> inv;
    for (int i = 0; i < v.size(); ++i) {
      inv[v[i]] = i;
    }

    map<lli, set<lli>> x, y;
    for (int i = 0; i < v.size(); ++i) {
      x[v[i].first].insert(v[i].second);
      y[v[i].second].insert(v[i].first);
    }
    map<lli, set<lli>> ex = x;
    map<lli, set<lli>> ey = y;
    map<pair<lli, lli>, int> ordx, ordy;
    {
      int k;
      k = 1; each (i, x) each (j, i.second) ordx[make_pair(i.first, j)] = k++;
      k = 1; each (i, y) each (j, i.second) ordy[make_pair(j, i.first)] = k++;
    }

    const lli cd = chebyshev_distance(v[a], v[b]);
    set<int> vis;
    function<lli(int)> rec = [&] (int curr) {
      lli z = 0;
      vis.insert(curr);
      const pair<lli, lli> a = v[curr];

      each (sign, vec<int>({-1, +1})) {
        const lli d = a.first + cd * sign;
        auto itr1 = x[d].lower_bound(a.second - cd);
        auto itr2 = x[d].lower_bound(a.second + cd + 1);
        if (itr1 != x[d].end() && itr2 != x[d].begin()) {
          --itr2;
          pair<lli, lli> b = make_pair(d, *itr1);
          pair<lli, lli> e = make_pair(d, *itr2);
          z += (ordx[e] + 1) - ordx[b];
        }
      }
      each (sign, vec<int>({-1, +1})) {
        const lli d = a.second + cd * sign;
        auto itr1 = y[d].lower_bound(a.first - cd + 1);
        auto itr2 = y[d].lower_bound(a.first + cd + 1 - 1);
        if (itr1 != y[d].end() && itr2 != y[d].begin()) {
          --itr2;
          pair<lli, lli> b = make_pair(*itr1, d);
          pair<lli, lli> e = make_pair(*itr2, d);
          z += (ordy[e] + 1) - ordy[b];
        }
      }

      set<int> e;
      each (sign, vec<int>({-1, +1})) {
        const lli d = a.first + cd * sign;
        while (true) {
          auto itr = ex[d].lower_bound(a.second - cd);
          if (itr != ex[d].end() && *itr <= a.second + cd) {
            pair<lli, lli> b = make_pair(d, *itr);
            ex[b.first].erase(b.second);
            ey[b.second].erase(b.first);
            e.insert(inv[b]);
          } else {
            break;
          }
        }
      }
      each (sign, vec<int>({-1, +1})) {
        const lli d = a.second + cd * sign;
        while (true) {
          auto itr = ey[d].lower_bound(a.first - cd);
          if (itr != ey[d].end() && *itr <= a.first + cd) {
            pair<lli, lli> b = make_pair(*itr, d);
            ex[b.first].erase(b.second);
            ey[b.second].erase(b.first);
            e.insert(inv[b]);
          } else {
            break;
          }
        }
      }
      each (next, e) unless (vis.count(next)) z += rec(next);
      return z;
    };
    lli z = rec(a);
    cout << z / 2 << endl;
  }
  return 0;
}
