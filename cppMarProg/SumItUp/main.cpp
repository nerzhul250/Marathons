#include <vector>
#include <iostream>
#include <map>
#include <functional>
#include<algorithm>

using namespace std;
vector <int> a;
map<vector <int>, bool> m;
int n,k;
bool tt = false;
int sum(int s,vector <int> temp,int size1)
{

	if (m[temp])
		return 0;
	int i;

	if (s>k)
		return 0;
	if (s == k)
	{
			m[temp] = true;
			tt = true;
			for ( i = 0; i <temp.size()-1; i++)
			{
				cout << temp[i] << "+";
			}
			cout << temp[i] << endl;
	}
	else
	{
		if (size1 >= n)
			return 0;
		temp.push_back(a[size1]);
		sum(s + a[size1], temp, size1 + 1);
		temp.pop_back();
		sum(s,temp,size1 + 1);
	}
	return 0;
}

int main()
{
	while (true)
	{

		a.clear();
		m.clear();
		cin >> k >> n;
		a.resize(n);
		if (n == 0 && k == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		sort(a.begin(), a.end(),greater<int>());
		tt = false;
		cout << "Sums of " << k << ":" << endl;
		sum(0, vector<int>(), 0);
		if (tt == false)
			cout << "NONE" << endl;
	}

	return 0;
}
