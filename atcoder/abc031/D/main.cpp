// atcoder/abc031/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int k, n;
  while (cin >> k >> n) {
    vector<pair<string, string>> v(n);
    cin >> v;

    for (int _1 = 1; _1 <= 3; ++_1) {
      for (int _2 = 1; _2 <= 3; ++_2) {
        for (int _3 = 1; _3 <= 3; ++_3) {
          for (int _4 = 1; _4 <= 3; ++_4) {
            for (int _5 = 1; _5 <= 3; ++_5) {
              for (int _6 = 1; _6 <= 3; ++_6) {
                for (int _7 = 1; _7 <= 3; ++_7) {
                  for (int _8 = 1; _8 <= 3; ++_8) {
                    for (int _9 = 1; _9 <= 3; ++_9) {
                      map<char, int> len;
                      len['1'] = _1;
                      len['2'] = _2;
                      len['3'] = _3;
                      len['4'] = _4;
                      len['5'] = _5;
                      len['6'] = _6;
                      len['7'] = _7;
                      len['8'] = _8;
                      len['9'] = _9;

                      bool f = true;
                      map<char, string> m;
                      each (i, v) {
                        int j = 0;
                        each (c, i.first) {
                          string s;
                          for (int x = 0; x < len[c]; ++x) {
                            if (j == i.second.size()) s += '@';
                            else s += i.second[j++];
                          }
                          if (m.count(c)) f = f && (m[c] == s);
                          else m[c] = s;
                        }
                        f = f && (j == i.second.size());
                      }
                      if (f) {
                        each (x, m) cout << x.second << endl;
                        _1 = _2 = _3 = _4 = _5 = _6 = _7 = _8 = _9 = 10;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  return 0;
}
