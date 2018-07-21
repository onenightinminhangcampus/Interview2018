//Find the maximum subsum of a unsorted one dimensional array with both negative
//and positive value

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

int max(int a,int b,int c)
{
	int max = a;
	if (max < b) max = b;
	if (max < c) max = c;
	return max;
}

int maxMidSum(vector<int> avec, int lower, int middle, int upper)
{
	//Max from lower to middle-1
	int maxLeft = INT8_MIN;
	int sumLeft = 0;
	for(int i=(middle-1);i>=lower;i--)
	{
		sumLeft += avec[i];
		if (sumLeft > maxLeft) maxLeft = sumLeft;
	}
	//Max from middle+1 to upper
	int maxRight = INT8_MIN;
	int sumRight = 0;
	for(int i=(middle+1);i<=upper;i++)
	{
		sumRight += avec[i];
		if (sumRight > maxRight) maxRight = sumRight;
	}
	return avec[middle] + maxLeft + maxRight;
}

int maxSubSum(vector<int> avec,int lower,int upper)
{
	if(lower == upper)
	{
		return avec[lower];
	} else if(lower == upper-1)
	{
		return max(avec[lower], avec[upper], avec[lower] + avec[upper]);
	}

	int mid = (lower + upper) / 2;

	return max(maxSubSum(avec, lower, mid ), maxSubSum(avec, mid , upper), maxMidSum(avec, lower, mid, upper) );

}

int main()
{
	vector<int> avec = { -4,5,3,7,-9,-1,9,3,1,-10 };

	int sum = maxSubSum(avec, 0, avec.size() - 1);
	cout << sum << endl;
	cin.get();
    return 0;
}

