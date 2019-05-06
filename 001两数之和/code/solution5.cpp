#include <vector>
#include<iostream>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	
    	vector<int> result;
    	map<int, int>:: iterator it;
		map<int, int> mapNums;
		for (int i = 0; i < nums.size(); ++i)
		{
			mapNums.insert(make_pair(nums[i], i));
			it = mapNums.find(target - nums[i]);
			if (it != mapNums.end() && it->second != i)
			{
				result.push_back(i);
				result.push_back(it->second);
				return result;
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