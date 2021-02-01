#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000;

vector<int> coefficients;

void solve()
{
  int degree, num;
  int d, k;
  int n;
  unsigned long long res;
  
  cin >> degree;
  degree++;
  
  while (degree--)
  {
    cin >> num;
    coefficients.push_back(num);
  }
  
  cin >> d >> k;
  
  n = 1;
  
  while (k > 0)
  {
    k -= n * d;
    n++;
  }
  
  n--;
  
  res = coefficients[0];
  
  // if k == 1,000,000 and d = 1 --> n +-= 1400
  // max value of tmp = 1400 ^ 20 = 8.367 ^ 62
  // we need 64 bytes to represent the value
  unsigned long long tmp = n;
  
  for (int i = 1; i < (int)coefficients.size(); i++)
  {
    res += coefficients[i] * tmp;
    tmp *= n;
  }
  
  cout << res;
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

  int t = 1;
  cin >> t;

  while (t--)
  {
    solve();
    cout << "\n";
    coefficients.clear();
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
