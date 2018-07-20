//For a sorted array with duplicated value. Find the starting and ending index of the duplicated value.
//using binary search
#include "stdafx.h"
#include <vector>
#include <iostream>

int findLower(std::vector<int> avec, int val,int lower,int upper)
{
	if (lower > upper) return lower;
	
	int mid = lower + (upper - lower) / 2;
	if (avec[mid] >= val)
	{
		return findLower(avec, val, lower, mid-1);
	} else
	{
	    return findLower(avec, val, mid+1, upper);
	}
}

int findUpper(std::vector<int> avec, int val, int lower, int upper)
{
	if (lower > upper) return upper;
	int mid = lower + (upper - lower) / 2;
	if(avec[mid]<=val)
	{
		return findUpper(avec, val, mid+1, upper);
	}else
	{
		return findUpper(avec, val, lower, mid-1);
	}
}

int main()
{
	std::vector<int> avec = { 1,2,3,5,5,5,8,9 };
	int val = 5;
	int lower = findLower(avec, val, 0, avec.size() - 1);
	std::cout << lower << std::endl;
	int upper = findUpper(avec, val, lower, avec.size() - 1);
	std::cout << upper << std::endl;
	std::cin.get();
    return 0;
}
