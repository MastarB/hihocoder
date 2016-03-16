#include<vector>
#include<iostream>
#define add nums.push_back 
using namespace std;

int partition(vector<int>&nums,int a, int b)
{
	int p =  nums[a];
	int i = a + 1;
	int j = b;
	while(i <= j)
	{
		if(nums[i] > p)
		{
			swap(nums[i], nums[j]);
			j--;
		}
		else i++;
	}
	swap(nums[a],nums[i-1]);
	return  i-1;
}

void quicksort(vector<int>& nums, int i, int j)
{
	if(i<j)
	{
		int p = partition(nums,i,j);
		quicksort(nums,i,p-1);
	
		quicksort(nums,p+1,j);
	}
}

void sort(vector<int>&nums)
{
	quicksort(nums,0,nums.size()-1);
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	vector<int>nums;
	add(0);
	add(4);
	add(3);
	add(0);
	for(int i = 0 ;i < nums.size(); i++)
	cout<<nums[i]<<' ';
	cout<<endl;
	sort(nums);
	for(int i = 0 ;i < nums.size(); i++)
	cout<<nums[i]<<' ';
	
	
}
