#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int n;
int age;

void solve()
{
	vi ages;
	
  while (n--)
  {
    cin >> age;
    ages.push_back(age);
  }
  
  sort(ages.begin(), ages.end());
    
  for (int i = 0; i < (int)ages.size() - 1; ++i)
    cout << ages[i] << " ";
    
  cout << ages.back();
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
  
  cin >> n;

  while (n > 0)
  {
    solve();
    cout << "\n";
    cin >> n;
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
