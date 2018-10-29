#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

const int MAX_N = 2 * 10e5;
const int inf = 1 << 29;

template<typename T>
struct RMQ {
  int n;
  vector<T> dat;

  RMQ(int n_) {
    n = 1;
    while (n < n_) n *= 2;
    dat = vector<T>(2 * n - 1, inf);
  }

  void update(int k, T a) {
    k += n - 1;
    dat[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
  }

  T query(size_t a, size_t b) {
    return query(a, b, 0, 0, n);
  }

  T query(size_t a, size_t b, size_t k, size_t l, size_t r) {
    if (r <= a || b <= l) return inf;
    if (a <= l && r <= b) return dat[k];

    int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

    return min(vl, vr);
  }
};


int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<int> a(n);
    cin >> a;

    map<int, int> idx;
    for (int i = 0; i < n; ++i) {
      idx[a[i]] = i;
    }

    RMQ<int> odd(n);
    RMQ<int> even(n);

    for (int i = 0; i < n; ++i) {
      if (i % 2) odd.update(i, a[i]);
      else even.update(i, a[i]);
    }
    
    vector<int> v;

    using range = pair<int, int>;
    priority_queue<pair<int, range>, vector<pair<int, range>>> q;
    q.push(make_pair(-1, make_pair(0, n)));
    while (!q.empty()) {
      pair<int, range> curr = q.top();
      range r = curr.second;
      q.pop();

      if (r.first % 2 == 0) {
        int x = even.query(r.first, r.second);
        int y = odd.query(idx[x], r.second);
      
        if (x == inf || y == inf) continue;

        v.push_back(x);
        v.push_back(y);

        range a(r.first, idx[x]);
        range b(idx[x] + 1, idx[y]);
        range c(idx[y] + 1, r.second);

        q.push(make_pair(-1 * even.query(a.first, a.second), a));
        q.push(make_pair(-1 * odd.query(b.first, b.second), b));
        q.push(make_pair(-1 * even.query(c.first, c.second), c));
      } else {
        int x = odd.query(r.first, r.second);
        int y = even.query(idx[x], r.second);
      
        if (x == inf || y == inf) continue;

        v.push_back(x);
        v.push_back(y);

        range a(r.first, idx[x]);
        range b(idx[x] + 1, idx[y]);
        range c(idx[y] + 1, r.second);

        q.push(make_pair(-1 * odd.query(a.first, a.second), a));
        q.push(make_pair(-1 * even.query(b.first, b.second), b));
        q.push(make_pair(-1 * odd.query(c.first, c.second), c));
      }
    }

    each (i, v) cout << i << ' ';
    cout << endl;
  }

  return 0;
}
