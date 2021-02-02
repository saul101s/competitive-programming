#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000;

int f, r;

void solve()
{
  int fteeths[f];
  int rteeths[r];
  float quotients[f*r];
  int idx = 0;
  float quo = 0.0f, max_quo = 0.0f;
  
  for (int i = 0; i < f; i++)
  {
    cin >> fteeths[i];
  }
  
  for (int i = 0; i < r; i++)
  {
    cin >> rteeths[i];
  }
  
  for (int i = 0; i < f; i++)
  {
    for (int j = 0; j < r; j++)
    {
      quotients[idx++] = (float)rteeths[j] / fteeths[i];
    }
  }
  
  sort(quotients, quotients + f*r);
  
  for (int i = 1; i < f*r; i++)
  {
    quo = quotients[i] / quotients[i-1];
    if (quo > max_quo)
    {
      max_quo = quo;
    }
  }
  
  cout << (round(max_quo * 100) / 100);
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

  while (cin >> f >> r)
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
