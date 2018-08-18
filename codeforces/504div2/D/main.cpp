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

class RMQ {
public:
  int *n, size;
  RMQ(){}
  RMQ(int a[], int s)
  {
    build(a, s);
  }
  void build(int a[], int s){
    int lg = 1;
    size = s;
    for(int i=1; i<s; i*=2)++lg;
    int *tmp = n = new int[s * lg];
    copy(a, a+s, tmp);
    for(int i=1; i<s; i*=2){
      copy(tmp, tmp+s, tmp+s); tmp += s;
      for (int j = 0; j < s - i; ++j) {
        tmp[j] = min(tmp[j], tmp[j+i]);
      }
    }
    return ;
  }
  int query(int b, int e){//[b:e]
    if(e < b)swap(e, b);
    int k;
    for(k = 0; (1 << (k+1)) <= (e-b+1); ++k);
    return min(n[b + size * k], n[e + size * k - (1<<k) + 1]);//min(), max()
  }
};


int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  while (cin >> n >> q) {
    vector<int> a(n);
    each (i, a) cin >> i;

    if (count(a.begin(), a.end(), 0) == n) {
      cout << "YES" << endl;
      for (int i = 0; i < n; ++i) {
        cout << q << ' ';
      }
      cout << endl;
      continue;
    }

    if (*max_element(a.begin(), a.end()) != q) {
      each (i, a) {
        if (i == 0) {
          i = q;
          break;
        }
      }
    }

    vector<int> b = a;
    vector<int> c = a;
    
    for (int i = 1; i < n; ++i) {
      if (b[i] == 0) {
        if (0 <= i - 1 && i + 1 < n) b[i] = max(b[i - 1], b[i + 1]);
        else b[i] = b[i - 1];
      }
    }
    for (int i = n - 2; 0 <= i; --i) {
      if (c[i] == 0) {
        if (0 <= i - 1 && i + 1 < n) c[i] = max(c[i - 1], c[i + 1]);
        else c[i] = c[i + 1];
      }      
    }

    for (int i = 0; i < a.size(); ++i) {
      a[i] = max(b[i], c[i]);
    }

    map<int, int> mn;
    map<int, int> mx;
    for (int i = 0; i < a.size(); ++i) {
      if (mn.count(a[i])) {
        mx[a[i]] = i;
      } else {
        mn[a[i]] = i;
      }
    }

    each (i, a) {
      if (mx[i] == 0) mx[i] = mn[i];
    }

    int d[a.size()];
    copy(a.begin(), a.end(), d);
    RMQ rmq = RMQ(d, a.size());

    // cout << a << endl;
    // cout << b << endl;
    // cout << c << endl;
    // each (i, a) cout << i << ": " << mn[i] << ' ' << mx[i] << ", " << rmq.query(mn[i], mx[i]) << endl;
    
    bool f = *max_element(a.begin(), a.end()) == q;
    each (i, a) {
      f = f && (rmq.query(mn[i], mx[i]) == i);
    }
    
    if (f) {
      cout << "YES" << endl;
      each (i, a) cout << i << ' ';
      cout << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  
  return 0;
}
