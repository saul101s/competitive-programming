#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000
#define EPS 1e-7

int p, q, r, s, t, u;

double func(double x)
{
  return (p * exp(-x)) + (q * sin(x)) + (r * cos(x)) + (s * tan(x)) + t * x * x + u;
}

void solve()
{
  double tmp = func(0.0), tmp2 = func(1.0);
  
  if (tmp * tmp2 > 0.0)
  {
    printf("No solution");
    return;
  }
  
  double lo = 0.0, hi = 1.0, mid = 0.0;
  
  while (lo + EPS < hi)
  {
    mid = (lo + hi) / 2.0;
    if (func(lo) * func(mid) <= 0){
      hi = mid;
    } else {
      lo = mid;
    }
  }
  
  printf("%.4lf", mid);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("my-output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
  #endif

  while (cin >> p >> q >> r >> s >> t >> u)
  {
    solve();
    printf("\n");
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
