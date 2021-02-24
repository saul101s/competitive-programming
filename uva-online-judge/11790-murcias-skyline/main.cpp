#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int c = 1;
int N;
vi h, w;
vi lis, lds;

void calculate_lis_lds()
{
  lis[0] = w[0];
  lds[0] = w[0];
  
  for (int i = 1; i < N; i++)
  {
    int lis_ans = w[i];
    int lds_ans = w[i];
    
    for (int j = i - 1; j >= 0; j--)
    {
      if (h[i] > h[j]) lis_ans = max(lis_ans, lis[j] + w[i]);
      if (h[i] < h[j]) lds_ans = max(lds_ans, lds[j] + w[i]);
    }
    
    lis[i] = lis_ans;
    lds[i] = lds_ans;
  }
}

int get_max_lis()
{
  int res = -1;
  
  for (int i = 0; i < N; i++)
  {
    res = max(res, lis[i]);
  }
  
  return res;
}

int get_max_lds()
{
  int res = -1;
  
  for (int i = 0; i < N; i++)
  {
    res = max(res, lds[i]);
  }
  
  return res;
}

void solve()
{
  cin >> N;
  
  lis.assign(N, -1);
  lds.assign(N, -1);
  h.assign(N, 0);
  w.assign(N, 0);
  
  for (int i = 0; i < N; i++)
  {
    cin >> h[i];
  }
  for (int i = 0; i < N; i++)
  {
    cin >> w[i];
  }
  
  calculate_lis_lds();
  
  int inc = get_max_lis();
  int dec = get_max_lds();
  
  cout << "Case " << c++ << ".";
  
  if (dec > inc)
  {
    cout << " Decreasing (" << dec << "). Increasing (" << inc << ").";
  }
  else
  {
    cout << " Increasing (" << inc << "). Decreasing (" << dec << ").";
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
