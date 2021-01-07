#include<bits/stdc++.h>
using namespace std;

void solve();

int months, records;
float payment, loan;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("my-output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    scanf("%d %f %f %d", &months, &payment, &loan, &records);

    while (months > 0)
    {
        solve();
        printf("\n");
        
        scanf("%d %f %f %d", &months, &payment, &loan, &records);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

void solve()
{
	int next_rec_month, current_month = 0;
	float next_rec_dep, current_dep = 0, current_loan = loan;
	float car_price = loan + payment;
	
	cerr << "Car price: " << car_price << endl;
	
	// Car month 0 depreciation
	
	scanf("%d %f", &next_rec_month, &next_rec_dep);
	records--;
	car_price -= car_price * next_rec_dep;
	
	cerr << "Car price after driving: " << car_price << endl;
	
	if (current_loan < car_price)
	{
		printf("%d months", current_month);
		while (records--)
		{
			scanf("%d %f", &next_rec_month, &next_rec_dep);
		}
		
		return;
	}
	
	current_month++;
	
	// Car following depreciations
	
	while (records--)
	{
		scanf("%d %f", &next_rec_month, &next_rec_dep);
		
		cerr << "Next rec: " << next_rec_month << " - " << next_rec_dep << endl;
		
		while (current_month < next_rec_month)
		{	
			current_loan -= payment;
			car_price -= car_price * current_dep;
			
			cerr << "Depreciation: " << current_dep << endl;
			cerr << "Current month: " << current_month << ", Record month: " << next_rec_month << endl;
			cerr << "Loan - Car price: " << current_loan << " - " << car_price << endl;
			cerr << "==============================" << endl;
			
			if (current_loan < car_price)
			{
				if (current_month == 1)
				{
					printf("%d month", current_month);
				}
				else
				{
					printf("%d months", current_month);
				}
				
				cerr << "Months: " << current_month << endl << endl << endl;
				while (records--)
				{
					scanf("%d %f", &next_rec_month, &next_rec_dep);
				}
				
				return;
			}
			
			current_month++;
		}
		
		current_dep = next_rec_dep;
	}
	
	while (current_month < months)
	{
		current_loan -= payment;
		car_price -= car_price * current_dep;
		
		cerr << "Depreciation: " << current_dep << endl;
		cerr << "Current month: " << current_month << ", Month: " << months << endl;
		cerr << "Loan - Car price: " << current_loan << " - " << car_price << endl;
		cerr << "==============================" << endl;
		
		if (current_loan < car_price)
		{
			printf("%d months", current_month);
				
			cerr << "Months: " << current_month << endl << endl << endl;
			return;
		}
		
		current_month++;
	}
}
