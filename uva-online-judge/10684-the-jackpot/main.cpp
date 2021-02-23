#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int N;
int A[10000];

void solve()
{
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  
  int max_gain = 0;
  int gain = 0;
  
  for (int i = 0; i < N; i++)
  {
    gain += A[i];
    
    if (gain < 0)
    {
      gain = 0;
    }
    else
    {
      if (gain > max_gain)
      {
        max_gain = gain;
      }
    }
  }
  
  if (max_gain)
  {
    cout << "The maximum winning streak is " << max_gain << ".";
  }
  else
  {
    cout << "Losing streak.";
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

  while (cin >> N && N)
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
