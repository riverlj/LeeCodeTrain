#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> result;
		if (nums.size() < 2)
		{
			return result;	
		}

		for (int i=0; i<nums.size(); i++) 
		{
			bool find = false;
			for (int j = i+1; j < nums.size(); ++j)
			{
				if (nums[i]+nums[j] == target)
				{
					result.push_back(i);
					result.push_back(j);
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
};

int main() 
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);
	int target = 9;
	Solution *solution = new Solution();
	std::vector<int> v = solution->twoSum(nums, target);
	cout<<v[0] << endl;
	cout<<v[1] << endl;	

	return 0;
}