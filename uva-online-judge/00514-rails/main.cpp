#include<bits/stdc++.h>
using namespace std;

int coaches;

void print_stack(stack<int> s)
{
	int size = s.size();
	
	if (size < 1)
	{
		cerr << "Empty queue" << endl;
		return;
	}
	
	int tmp[size];
	
	for (int i = 0; i < size; i++)
	{
		tmp[i] = s.top();
		s.pop();
		cerr << tmp[i] << " ";
	}
	
	cerr << endl;
	
	for (int i = size - 1; i >= 0; i--)
	{
		s.push(tmp[i]);
	}
}

void solve()
{
	stack<int> station;
	int b[coaches];
	int a[coaches];
	int next_a = coaches - 1;
	int a_elements = 0;
	int next_b = coaches - 1;
	bool valid = true;
	
	for (int i = 0; i < coaches; i++)
	{
		a[i] = i + 1;
	}
	
	
	cin >> b[0];
	
	while (b[0] != 0)
	{	
		for (int i = 1; i < coaches; i++)
		{
			cin >> b[i];
		}
		
		while (valid && a_elements < coaches)
		{
			//print_stack(station);
			if (station.size() > 0 && station.top() == a[next_a])
			{
				station.pop();
				next_a--;
				a_elements++;
			}
			else
			{
				if (next_b < 0)
				{
					valid = false;
					break;
				}
				
				station.push(b[next_b]);
				next_b--;
			}
		}
		
		while (station.size() > 0)
		{
			station.pop();
		}
		
		cout << (valid ? "Yes" : "No") << endl;
		// cerr << endl;
		
		next_a = coaches - 1;
		next_b = coaches - 1;
		a_elements = 0;
		valid = true;
		cin >> b[0];
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
    
    cin >> coaches;

    while (coaches != 0)
    {
        solve();
        
        cin >> coaches;
        
		cout << "\n";
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
