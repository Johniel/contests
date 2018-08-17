# atcoder/arc051/A

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

int main(int argc, char *argv[])
{

  int x1, y1;
  int x2, x3;
  int y2, y3;
  int r;
  while (cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3) {
    bool blue = true;
    bool red = true;

    {
      vector<pair<int, int>> v;
      v.push_back(make_pair(x2, y2));
      v.push_back(make_pair(x2, y3));
      v.push_back(make_pair(x3, y2));
      v.push_back(make_pair(x3, y3));

      each (p, v) {
        double X = x1 - p.first;
        double Y = y1 - p.second;
        double dist = sqrt(X * X + Y * Y);
        blue = blue && dist <= r;
      }
    }
    {
      vector<pair<int, int>> v;
      v.push_back(make_pair(x1, y1 - r));
      v.push_back(make_pair(x1, y1 + r));
      v.push_back(make_pair(x1 - r, y1));
      v.push_back(make_pair(x1 + r, y1));
      each (p, v) {
        red = red && (x2 <= p.first) && (p.first <= x3) && (y2 <= p.second) && (p.second <= y3);
      }
    }

    cout << (!red ? "YES" : "NO") << endl;
    cout << (!blue ? "YES" : "NO") << endl;
  }
  return 0;
}
```
