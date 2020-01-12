// atcoder/abc001/D/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    const int N = 2400 + 3;
    static bool x[N];
    fill(x, x + N, false);

    // vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      replace(s.begin(), s.end(), '-', ' ');
      istringstream iss(s.c_str());
      int begin, end;
      iss >> begin >> end;
      begin -= begin % 5;
      if (end % 5) end += 5 - (end % 5);
      if (end % 100 == 60) {
        end += 40;
      }
      // v.push_back(make_pair(begin, end));
      for (int j = begin; j <= end; ++j) {
        x[j] = true;
      }
    }
    // sort(v.begin(), v.end());
    // for (int i = 0; i < v.size(); ++i) {
    //   if (i + 1 < v.size() && v[i].first <= v[i + 1].first && v[i + 1].first <= v[i].second) {
    //     setmax(v[i + 1].second, v[i].second);
    //     setmin(v[i + 1].first, v[i].first);
    //   } else {
    //     printf("%04d-%04d\n", v[i].first, v[i].second);
    //   }
    // }

    bool prev = false;
    vector<int> v;
    for (int j = 0; j < N; ++j) {
      if (x[j] != prev) v.push_back(j);
      prev = x[j];
    }
    assert(v.size() % 2 == 0);
    for (int i = 0; i + 1 < v.size(); i += 2) {
      printf("%04d-%04d\n", v[i], v[i + 1] - 1);
    }
  }
  
  return 0;
}


// template<typename V>
// class BIT {
// public:
//   vector<V> bit;
//   int n;
//   BIT (int n_)
//   {
//     n = n_;
//     bit.resize(n + 1);
//   }
//   V sum(int i)
//   {
//     ++i; // 1-origin
//     V s = 0;
//     while (i > 0) {
//       s += bit[i];
//       i -= i & -i;
//     }
//     return s;
//   }
//   void add(int i, V x)
//   {
//     ++i; // 1-origin
//     while (i <= n)
//     {
//       bit[i] += x;
//       i += i & -i;
//     }
//     return ;
//   }
//   void set(int i, V x)
//   {
//     return add(i, x - bit[i]);
//   }
//   V query(int begin, int end)
//   {
//     return sum(end) - sum(begin - 1);
//   }
// };


// int main(int argc, char *argv[])
// {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);

//   int n;
//   while (cin >> n) {
//     const int N = 2400 + 3;
//     BIT<int> bit(N);
//     for (int i = 0; i < n; ++i) {
//       string s;
//       cin >> s;
//       replace(s.begin(), s.end(), '-', ' ');
//       istringstream iss(s.c_str());
//       int begin, end;
//       iss >> begin >> end;
//       begin -= begin % 5;
//       if (end % 5) end += 5 - (end % 5);
//       bit.add(begin + 1, +1);
//       bit.add(end + 2, -1);
//     }

//     vector<int> v;
//     for (int i = 0; i < N; ++i) {
//       if (bit.sum(i) == 0 && bit.sum(i + 1) != 0) {
//         v.push_back(i);
//       }
//       if (bit.sum(i + 1) != 0 && bit.sum(i + 2) == 0) {
//         v.push_back(i);
//       }
//     }
    
//     for (int i = 0; i + 1 < v.size(); i += 2) {
//       printf("%04d-%04d\n", v[i], v[i + 1]);
//     }
//   }
  
//   return 0;
// }
