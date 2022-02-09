#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int n;
char people[100][101];
char word[16];
string song("Happy birthday to you Happy birthday to you Happy birthday to Rujia Happy birthday to you");

void solve()
{
  stringstream ss(song);
  
  for (int i = 0; i < n; i++)
  {
    cin >> people[i];
  }
  
  int i = 0;
  
  while (i % 16 != 0 || i < n)
  {
    if (i % 16 == 0) ss.seekg(0);
    ss >> word;
    cout << people[i%n] << ": " << word << "\n";
    i++;
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

  cin >> n;
  solve();

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
