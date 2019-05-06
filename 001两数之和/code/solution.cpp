#include<iostream>
using namespace std;


int* getSolutions(int *nums, int numsSize, int target)
{
	int* result = (int *)malloc(2 * sizeof(int));
	if (numsSize < 2)
	{
		return result;	
	}

	for (int i=0; i<numsSize; i++) 
	{
		bool find = false;
		for (int j = i+1; j < numsSize; ++j)
		{
			if (nums[i]+nums[j] == target)
			{
				result[0] = i;
				result[1] = j;
				find = true;
				break;
			}
		}
		if (find)
		{
			break;
		}
	}

	return result;
}


int main() 
{
	int nums[] = {2, 7, 11, 15};
	int target = 9;
	int *result = getSolutions(nums, 4, target);
	cout << result[0] << endl;
	cout << result[1] << endl;
	return 0;
}