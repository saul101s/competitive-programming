#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

void solve()
{
  int N;
  int above = 0;
  scanf("%d", &N);
  
  int marks[N];
  float average = 0.f;
  
  for (int i  = 0; i < N; i++)
  {
    scanf("%d", &marks[i]);
    average += marks[i];
  }
  
  average /= (float)N;
  
  for (int i = 0; i < N; i++)
  {
    if ( (float)marks[i] > average )
    {
      above++;
    }
  }
  
  printf("%.3f%%", ((float)above / (float)N) * 100.f);
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
  scanf("%d", &t);

  while (t--)
  {
    solve();
    printf("\n");
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
