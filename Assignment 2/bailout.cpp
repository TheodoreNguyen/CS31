#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Company name: ";				//section defining company name
	string companyName;
	getline(cin, companyName);
	if (companyName == "")
	{
		cout << "---" << endl;
		cout << "You must enter a company name." << endl;
		return 1;
	}
	
	cout << "Annual sales (in trillions): ";		//section defining sales
	double salesAnnual;
	cin >> salesAnnual;
	if (salesAnnual < 0)
	{
		cout << "---" << endl;
		cout << "The annual sales amount must be nonnegative." << endl;
		return 1;
	}

	cout << "Industry: ";						//section defining the industry
	cin.ignore(10000, '\n');
	string industry;
	getline(cin, industry);
	if (industry == "")
	{
		cout << "---" << endl;
		cout << "You must enter an industry." << endl;
		return 1;
	}

	cout << "Number of employees: ";		//section defining employees
	double employees;
	cin >> employees;
	if (employees < 0)
	{
		cout << "---" << endl;
		cout << "The number of employees must be positive." << endl;
		return 1;
	}

	cout << "---" << endl;

	double credit1;						//variable defining; rateIndustry and creditEmployee are more specific
	double rate1 = 0.20;
	double credit2;
	double rate2 = 0.10;				//rate or credit 1,2,3 defines which interval the salesAnnual are in
	double rate2Industry = 0.15;
	double credit3;
	double rate3 = 0.03;				//interval 1 is <= 500; interval 2 is > 500 & <=900; interval 3 is > 900
	double rateEmployee = 0.01;
	double creditEmployee;
	double creditTotal;

	if (salesAnnual <= 500)			//chose to analyze each interval separately instead of having efficient code
	{
		credit1 = salesAnnual * rate1;	//section dealing with interval 1 for sales <= 500
		credit2 = credit3 = 0;
	}

	if (salesAnnual > 500 && salesAnnual <= 900)	//section dealing with interval 2 for 500 < sales <= 900
	{	
		credit1 = 500 * rate1;
		if (industry == "mud" || industry == "phishing")
		{
			credit2 = (salesAnnual - 500) * rate2Industry;
		}
		else
		{
			credit2 = (salesAnnual - 500) * rate2;
		}
		credit3 = 0;
	}

	if (salesAnnual > 900)							//section dealing with interval 3 for sales > 900
	{
		credit1 = 500 * rate1;
		if (industry == "mud" || industry == "phishing")
		{
			credit2 = 400 * rate2Industry;
		}
		else
		{
			credit2 = 400 * rate2;
		}
		credit3 = (salesAnnual - 900) * rate3;
	}

	if (salesAnnual >= 700)							//section dealing with employee credit benefit if sales >= 700
	{
		creditEmployee = employees * rateEmployee;
	}
	else
	{
		creditEmployee = 0;
	}
	
										//final equation of borrowing capacity, decimal fixing to 2

	creditTotal = credit1 + credit2 + credit3 + creditEmployee;		

	cout.setf(ios::fixed);
	cout.precision(2);
	cout << companyName << " can borrow up to G" << creditTotal << " trillion." << endl;

}