#include<bits/stdc++.h>
using namespace std;

void solve();

int n, p;
int c = 1;

void solve()
{
  string proposal("");
	string selected_proposal("");
	int req_met, selected_proposal_reqs = 0;
	float price, selected_proposal_price = 1000000000.0f;
	
  cin.ignore(1024, '\n');
	while (n--) cin.ignore(1024, '\n');

	while (p--)
	{
    getline(cin, proposal, '\n');
		cin >> price >> req_met;
    
    // cout << proposal << " " << price << " " << req_met << endl;
    
    if (req_met > selected_proposal_reqs)
    {
      selected_proposal = proposal;
      selected_proposal_reqs = req_met;
      selected_proposal_price = price;
    }
    else if (req_met == selected_proposal_reqs)
    {
      if (price < selected_proposal_price)
      {
        selected_proposal = proposal;
        selected_proposal_price = price;
      }
    }
		
    getline(cin, proposal, '\n');
    while (req_met--) getline(cin, proposal, '\n');
	}
	
  cout << "RFP #" << c++ << endl;
	cout << selected_proposal;
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

  cin >> n >> p;

  while (true)
  {
    solve();
    
    cout << endl;
      
    cin >> n >> p;
    if (!n && !p) break;
    cout << endl;
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
