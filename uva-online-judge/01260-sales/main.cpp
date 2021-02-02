#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000;

void solve()
{
  int n, sum, counter;
  n = sum = counter = 0;
  cin >> n;
  
  int A[n];
  
  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
  }
  
  for (int i = 1; i < n; i++)
  {
    counter = 0;
    
    for (int j = 0; j < i; j++)
    {
      if (A[j] <= A[i])
      {
        counter++;
      }
    }
    
    sum += counter;
  }
  
  cout << sum;
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
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
