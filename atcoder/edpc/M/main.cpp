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

template<typename T, T MOD>
class SegTree {
public:
  SegTree (int n_) {
    n = 1;
    while (n < n_) n *= 2;
    v.resize(n * 2 - 1, 0);
  }
  void clear(void) {
    fill(v.begin(), v.end(), 0);
  }
  void add(int begin, int end, T x) {
    return add(begin, end, x, 0, 0, n);
  }
  T operator [] (size_t k) {
    T sum = 0;
    k += n - 1;
    while (0 < k) {
      (sum += v[k]) %= MOD;
      k = (k - 1) / 2;
    }
    return sum;
  }
private:
  vector<T> v;
  int n;
  void add(int begin, int end, T x, int k, int l, int r) {
    if (r <= begin || end <= l) {
      return ;
    }

    if (begin <= l && r <= end) {
      (v[k] += x) %= MOD;
    } else {
      add(begin, end, x, k * 2 + 1, l, (l + r) / 2);
      add(begin, end, x, k * 2 + 2, (l + r) / 2, r);
    }
    return ;
  }
  T sum(int begin, int end, int k, int l, int r) {
    if (r <= begin || end <= l) {
      return 0;
    }

    if (begin <= l && r <= end) {
      return v[k];
    } else {
      auto x = sum(begin, end, k * 2 + 1, l, (l + r) / 2);
      auto y = sum(begin, end, k * 2 + 2, (l + r) / 2, r);
      return (x + y) % MOD;
    }
  }
};

// int main(int argc, char *argv[])
// {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);

//   constexpr lli mod = 1e9 + 7;

//   int n, k;
//   while (cin >> n >> k) {
//     vector<int> a(n);
//     cin >> a;

//     const int K = 1e5 + 5;
//     SegTree<lli, mod> curr(K), next(K);
//     curr.add(0, 1, 1);

//     each (i, a) {
//       next.clear();
//       for (int j = 0; j <= k; ++j) {
//         lli x = curr[j];
//         if (x) next.add(j, min(k, j + i) + 1, x);
//         else break;
//       }
//       curr = next;
//     }
//     cout << curr[k] << endl;
//   }

//   return 0;
// }

struct Acc {
  vector<lli> sum;
  Acc(vector<lli> v) {
    sum.push_back(0);
    each (i, v) {
      sum.push_back(sum.back() + i);
    }
  }
  lli query(lli begin, lli end) {
    return sum[end] - sum[begin];
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (cin >> n >> k) {
    vector<int> a(n);
    cin >> a;

    const int K = 1e5 + 5;

    const lli mod = 1e9 + 7;
    
    vector<lli> curr(K, 0);
    curr[0] = 1;
    each (i, a) {
      Acc acc(curr);
      vector<lli> next(K, 0);
      for (int j = 0; j <= k; ++j) {
        (next[j] += acc.query(max(0, j - i), j + 1)) %= mod;
      }
      curr = next;
    }
    cout << curr[k] << endl;
  }
  
  return 0;
}
