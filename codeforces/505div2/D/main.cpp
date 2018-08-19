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

const int N = 700 + 10;
int a[N];
int memo_r[N][N];
int memo_l[N][N];

int gcd(int a, int b)
{
  unless (a > b) swap(a, b);
  return b ? gcd(b, a % b) : a;
}

int right(int, int);
int left(int, int);

int left(int begin, int end)
{
  if (begin == end) return 1;
  // cout << "L: " << make_pair(begin, end) << endl;
  if (memo_l[begin][end] != -1) return memo_l[begin][end];
  int parent = end;
  for (int i = begin; i < parent; ++i) {
    if (gcd(a[i], a[parent]) != 1) {
      bool f = true;
      f = f && left(begin, i);
      f = f && right(i, parent - 1);
      if (f) return memo_l[begin][end] = 1;
    }
  }
  return memo_l[begin][end] = 0;
}

int right(int begin, int end)
{
  if (begin == end) return 1;
  // cout << "R: " << make_pair(begin, end) << endl;
  if (memo_r[begin][end] != -1) return memo_r[begin][end];
  int parent = begin;
  for (int i = begin + 1; i <= end; ++i) {
    if (gcd(a[i], a[parent]) != 1) {
      bool f = true;
      f = f && left(parent + 1, i);
      f = f && right(i, end);
      if (f) return memo_r[begin][end] = 1;
    }
  }
  return memo_r[begin][end] = 0;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    fill(&memo_l[0][0], &memo_l[N - 1][N - 1] + 1, -1);
    fill(&memo_r[0][0], &memo_r[N - 1][N - 1] + 1, -1);
    bool f = left(0, n - 1) || right(0, n - 1);
    for (int i = 0; i < n; ++i) {
      f = f || (left(0, i) && right(i, n - 1));
    }
    cout << (f ? "Yes" : "No") << endl;
  }
  
  return 0;
}
