#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

template<typename T>
class BIT {
public:
  BIT(int n_)
  {
    n = n_;
    bit.resize(n + 1, 0);
  }
  T sum (int i)
  {
    return _sum(i + 1);
  }
  void add(int i, T x)
  {
    return _add(i + 1, x);
  }
private:
  vector<T> bit;
  int n;
  T _sum(int i)
  {
    T s = 0;
    while (i > 0) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }
  void _add(int i, T x)
  {
    while (i <= n) {
      bit[i] += x;
      i += i & -i;
    }
    return ;
  }
};

// https://codeforces.com/blog/entry/18879
lli subsequence_median(vector<int> v, int b)
{
  each (i, v) {
    if (i < b) i = -1;
    else i = +1;
  }
  v.insert(v.begin(), 0);

  for (int i = 1; i < v.size(); ++i) {
    v[i] += v[i - 1];
  }

  vector<int> ord;
  for (int i = 0; i < v.size(); ++i) {
    ord.push_back(i);
  }
  stable_sort(ord.begin(), ord.end(), [&] (int a, int b) { return v[a] < v[b]; });

  BIT<lli> bit(v.size());
  lli sum = 0;
  for (int i = 0; i < v.size(); ++i) {
    sum += bit.sum(ord[i]);
    bit.add(ord[i], 1);
  }

  return sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n;
  while (cin >> n) {
    vector<int> a(n);
    each (i, a) cin >> i;

    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    int small = 0;
    int large = b.size();
    while (small + 1 < large) {
      int mid = (small + large) / 2;
      if ((n * (n - 1) / 2 + n + 1) / 2 <= subsequence_median(a, b[mid])) small = mid;
      else large = mid;
    }

    cout << b[small] << endl;
  }
  return 0;
}
