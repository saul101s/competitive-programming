#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000;

int km, fc;

void solve()
{
  string action;
  float max_fuel = 0.0f, current_fuel = 0.0f;
  int last_km = km, leaks = 0;
  
  do
  {
    cin >> km;
    cin >> action;
    
    current_fuel -= ((fc / 100.0) + leaks) * (km - last_km);
    
    if (current_fuel < 0)
    {
      max_fuel += -current_fuel;
      current_fuel = 0;
    }
    
    if (action == "Fuel")
    { 
      cin >> action;
      cin >> fc;
    }
    else if (action == "Leak")
    {
      leaks++;
    }
    else if (action == "Gas")
    {
      cin >> action;
      current_fuel = max_fuel;
    }
    else if (action == "Mechanic")
    {
      leaks = 0;
    }
    
    last_km = km;
    
  } while (action != "Goal");

  printf("%.3f", max_fuel);
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
  
  cin >> km;
  cin.ignore(18, '\n');
  
  while (cin >> fc && fc)
  {
    solve();
    printf("\n");
    
    cin >> km;
    cin.ignore(18, '\n');
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
