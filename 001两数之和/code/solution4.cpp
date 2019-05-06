#include <vector>
#include<iostream>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> result;
		if (nums.size() < 2)
		{
			return result;	
		}

		map<int, int> mapNums;
		for (int i = 0; i < nums.size(); ++i)
		{
			int otherValue = target - nums[i];
			map<int, int>:: iterator it = mapNums.find(otherValue);
			if (it != mapNums.end() && it->second != i)
			{
				result.push_back(mapNums[otherValue]);
				result.push_back(i);
				break;
			}

			int num = nums[i];
			mapNums[num] = i;


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