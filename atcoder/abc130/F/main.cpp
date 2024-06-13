// github.com/Johniel/contests
// atcoder/abc130/F/main.cpp

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
  int n;
  while (cin >> n) {
    lli x[n], y[n];
    char dir[n];
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i] >> dir[i];
      x[i] *= 2;
      y[i] *= 2;
    }

    const lli inf = 1LL << 29;

    lli mnDx = +inf;
    lli mnDy = +inf;
    lli mnLx = +inf;
    lli mnLy = +inf;
    lli mnRx = +inf;
    lli mnRy = +inf;
    lli mnUx = +inf;
    lli mnUy = +inf;

    lli mxDx = -inf;
    lli mxDy = -inf;
    lli mxLx = -inf;
    lli mxLy = -inf;
    lli mxRx = -inf;
    lli mxRy = -inf;
    lli mxUx = -inf;
    lli mxUy = -inf;

    for (int i = 0; i < n; ++i) {
      if (dir[i] == 'U') {
        setmin(mnUx, x[i]);
        setmin(mnUy, y[i]);
        setmax(mxUx, x[i]);
        setmax(mxUy, y[i]);
      }
      if (dir[i] == 'D') {
        setmin(mnDx, x[i]);
        setmin(mnDy, y[i]);
        setmax(mxDx, x[i]);
        setmax(mxDy, y[i]);
      }
      if (dir[i] == 'R') {
        setmin(mnRx, x[i]);
        setmin(mnRy, y[i]);
        setmax(mxRx, x[i]);
        setmax(mxRy, y[i]);
      }
      if (dir[i] == 'L') {
        setmin(mnLx, x[i]);
        setmin(mnLy, y[i]);
        setmax(mxLx, x[i]);
        setmax(mxLy, y[i]);
      }
    }

    vec<lli> t;

    t.push_back((mnDy - mnUy) / 2);
    t.push_back((mnDy - mxUy) / 2);
    t.push_back((mxDy - mnUy) / 2);
    t.push_back((mxDy - mxUy) / 2);

    t.push_back(mxLy - mnUy);
    t.push_back(mxRy - mnUy);
    t.push_back(mnLy - mnUy);
    t.push_back(mnRy - mnUy);

    t.push_back(mxLy - mxUy);
    t.push_back(mxRy - mxUy);
    t.push_back(mnLy - mxUy);
    t.push_back(mnRy - mxUy);

    t.push_back(mxLy - mnDy);
    t.push_back(mxRy - mnDy);
    t.push_back(mnLy - mnDy);
    t.push_back(mnRy - mnDy);

    t.push_back(mxLy - mxDy);
    t.push_back(mxRy - mxDy);
    t.push_back(mnLy - mxDy);
    t.push_back(mnRy - mxDy);


    t.push_back((mnLx - mnRx) / 2);
    t.push_back((mxLx - mnRx) / 2);
    t.push_back((mnLx - mxRx) / 2);
    t.push_back((mxLx - mxRx) / 2);

    t.push_back(mxDx - mnRx);
    t.push_back(mxUx - mnRx);
    t.push_back(mnDx - mnRx);
    t.push_back(mnUx - mnRx);

    t.push_back(mxDx - mxRx);
    t.push_back(mxUx - mxRx);
    t.push_back(mnDx - mxRx);
    t.push_back(mnUx - mxRx);

    t.push_back(mxDx - mxLx);
    t.push_back(mxUx - mxLx);
    t.push_back(mnDx - mxLx);
    t.push_back(mnUx - mxLx);

    t.push_back(mxDx - mxLx);
    t.push_back(mxUx - mxLx);
    t.push_back(mnDx - mxLx);
    t.push_back(mnUx - mxLx);

    t.push_back(0LL);
    each (i, t) i = abs(i);
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());

    lli z = 1LL << 61;

    each (i, t) {
      lli mnX = +inf;
      lli mxX = -inf;
      lli mnY = +inf;
      lli mxY = -inf;
      for (int j = 0; j < n; ++j) {
        lli X = x[j];
        lli Y = y[j];
        if (dir[j] == 'U') Y += i;
        if (dir[j] == 'D') Y -= i;
        if (dir[j] == 'R') X += i;
        if (dir[j] == 'L') X -= i;
        setmin(mnX, X);
        setmin(mnY, Y);
        setmax(mxX, X);
        setmax(mxY, Y);
      }
      setmin(z, (mxX - mnX) * (mxY - mnY));
    }
    assert(0 <= z);
    cout << z / 4.0 << endl;
  }
  return 0;
}
