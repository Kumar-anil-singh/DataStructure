#include<iostream>
using namespace std;

int kadaneAlgo(int arr[], int n)
{
	int currsum=0,maxsum=0;
	for(int i=0;i<n;i++)
	{
		currsum = currsum+arr[i];
		if(currsum > maxsum)
			maxsum = currsum;
		if(currsum < 0)
			currsum = 0;
	}
	return maxsum;
}

int main()
{
	int arr[] = {5, -4, -2, 6, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<kadaneAlgo(arr,n);
}
