#include<bits/stdc++.h>
using namespace std;

int days;

void solve()
{
	int day_bills = 0;
	int bill = 0;
	unsigned long long cost = 0; // Not working with int
	multiset<int> urn;
	multiset<int>::iterator it_max;
	multiset<int>::iterator it_min;
	
	while (days--)
	{
		cin >> day_bills;
		
		while (day_bills--)
		{
			cin >> bill;
			urn.insert(bill);
		}
		
		it_min = urn.begin();
		it_max = urn.end();
		it_max--;
		
		cost += *it_max - *it_min;
		
		urn.erase(it_min);
		urn.erase(it_max);
	}
	
	cout << cost;
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
    
    cin >> days;

    while (days != 0)
    {
        solve();
        cout << "\n";
        
        cin >> days;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
