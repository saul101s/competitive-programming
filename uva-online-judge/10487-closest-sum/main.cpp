#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000;

int n;

void solve()
{
  int m, q, closest, dmin, tmp;
  int A[n];
  
  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
  }
  
  sort(A, A + n);
  
  cin >> m;
  
  while (m--)
  {
    cin >> q;
    
    if (n == 1)
    {
      closest = A[0];
      cout << "Closest sum to " << q << " is " << closest << ".\n";
      continue;
    }
    
    closest = A[0] + A[1];
    dmin = abs(closest - q);
    
    if (n == 2)
    {
      cout << "Closest sum to " << q << " is " << closest << ".\n";
      continue;
    }
    
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (A[i] == A[j])
        {
          continue;
        }
        
        tmp = A[i] + A[j];
        
        if (tmp - q > dmin)
        {
          break;
        }
        
        if (abs(tmp - q) < dmin)
        {
          closest = tmp;
          dmin = abs(tmp - q);
        }
      }
    }
    
    cout << "Closest sum to " << q << " is " << closest << ".\n";
  }
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

  int c = 1;

  while (cin >> n && n)
  {
    cout << "Case " << c++ << ":" << "\n";
    solve();
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
