// atcoder/abc022/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

namespace std{
  bool operator < (point a, point b){
    if(a.real() != b.real())return a.real() < b.real();
    return a.imag() < b.imag();
  }
};

bool cmp_real(const point &a, const point &b)
{
  if(a.real() != b.real())return a.real() < b.real();
  return a.imag() < b.imag();
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

//uva 10065
vector<point> andrew(vector<point> v)
{
  if(v.size() < 3)return vector<point>();
  sort(v.begin(), v.end(), cmp_real);
  vector<point> r[2];
  for(int i=0; i<2; ++i){
    for(int j=0; j<v.size(); ++j){
      r[i].push_back( v[j] );
      while(2 < r[i].size()){
        vector<point>::iterator itr = r[i].end();
        if( ccw( *(itr-3), *(itr-2), *(itr-1) ) == CCW::RIGHT )break;
        else r[i].erase( itr-2 );
      }
    }
    for(int j=0; j<v.size(); ++j){
      // v[j].imag() *= -1;
      v[j] = point(v[j].real(), v[j].imag() * -1);
    }
  }
  for(int i=r[1].size()-2; 0<i; --i){
    // r[1][i].imag() *= -1;
    r[1][i] = point(r[1][i].real(), r[1][i].imag() * -1);
    r[0].push_back( r[1][i] );
  }
  return r[0];
}

int main(int argc, char *argv[])
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.setf(std::ios_base::fixed);
  std::cout.precision(15);

  int n;
  while (cin >> n) {
    vec<point> a, b;
    for (int i = 0; i < n; ++i) {
      double x, y;
      cin >> x >> y;
      a.push_back(point(x, y));
    }
    for (int i = 0; i < n; ++i) {
      double x, y;
      cin >> x >> y;
      b.push_back(point(x, y));
    }

    a = andrew(a);
    b = andrew(b);

    auto fn = [] (point a, point b) {
      double r = a.real() - b.real();
      double i = a.imag() - b.imag();
      return sqrt(r * r + i * i);
    };

    double x = 0;
    for (int i = 0; i < a.size(); ++i) {
      int j = (i + 1) % a.size();
      x += fn(a[i], a[j]);
    }

    double y = 0;
    for (int i = 0; i < b.size(); ++i) {
      int j = (i + 1) % b.size();
      y += fn(b[i], b[j]);
    }

    cout << y / x << endl;
  }

  return 0;
}
