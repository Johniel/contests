# [Tell Your World](http://codeforces.com/contest/849/problem/B)
以下の3パターンを調べる
+ (0,y0)と(1,y1)が同一線上に有る場合
+ (0,y0)と(2,y2)が同一線上に有る場合
+ (1,y1)と(2,y2)が同一線上に有る場合


## Codes
```cpp
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

point normal(point v)
{
  return v * point(0, -1);
}

double dot(point a, point b)
{
  return (a.real() * b.real() + a.imag() * b.imag());
}

double cross(point a, point b)
{
  return (a.real() * b.imag() - a.imag() * b.real());
}

namespace CCW{
  enum{ RIGHT = 1, LEFT = -1, FRONT = -2, BACK = +2, OTHER = 0 };
};
int ccw(point a, point b, point c)
{
  b -= a;
  c -= a;
  if( cross(b, c) < 0 )return CCW::RIGHT;
  if( cross(b, c) > 0 )return CCW::LEFT;
  if( dot(b, c) < 0 )return CCW::BACK;
  if( norm(b) < norm(c) )return CCW::FRONT;
  return CCW::OTHER;
}

double angle(point a, point b)
{
  double r = a.real() - b.real();
  double i = a.imag() - b.imag();
  return i / r;
}

bool intersect_ll(point a1, point a2, point b1, point b2)
{
  return angle(a1, a2) != angle(b1, b2);
}

bool fn1(vector<point> v)
{
  vector<int> idx1;
  vector<int> idx2;
  idx1.push_back(0);
  idx1.push_back(1);

  const int N = v.size();
  for (int i = 2; i < N; ++i) {
    int dir = ccw(v[0], v[1], v[i]);
    if (dir == CCW::FRONT || dir == CCW::BACK || dir == 0) {
      idx1.push_back(i);
    } else {
      idx2.push_back(i);
    }
  }

  for (int i = 0; i + 2 < idx2.size(); ++i) {
    int a = idx2[i + 0];
    int b = idx2[i + 1];
    int c = idx2[i + 2];
    int dir = ccw(v[a], v[b], v[c]);
    if (dir == CCW::FRONT || dir == CCW::BACK || dir == 0) {
    } else {
      return false;
    }
  }

  if (2 <= idx1.size() && 2 <= idx2.size()) {
    if (intersect_ll(v[idx1[0]], v[idx1[1]],
                     v[idx2[0]], v[idx2[1]]))
    {
      return false;
    }
  }

  if (idx1.empty()) return false;
  if (idx2.empty()) return false;

  // cout << "A: " ; each (i, idx1) cout << v[i] << ' '; cout << endl;
  // cout << "B: " ; each (i, idx2) cout << v[i] << ' '; cout << endl;

  return true;
}

bool fn2(vector<point> v)
{
  swap(v[1], v[2]);
  return fn1(v);
}

bool fn3(vector<point> v)
{
  swap(v[0], v[2]);
  return fn1(v);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<point> v;
    for (int i = 0; i < n; ++i) {
      double y;
      cin >> y;
      v.push_back(point(i + 1, y));
    }

    cout << (fn1(v) || fn2(v) || fn3(v) ? "Yes" : "No") << endl;
  }

  return 0;
}
```
