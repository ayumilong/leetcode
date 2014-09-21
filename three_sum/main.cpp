/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

void print(const std::string &s){
	std::cout << s << std::endl;
}

void trim(std::string &s){ //Delete leading and trailing spaces of a string
	std::size_t len = s.size();
	if(len == 0){
		return;
	}
	std::size_t i = 0;
	while(i < len){
		if(s[i] != ' '){
			break;
		}
	}
	if(i == len){
		s = "";
		return;
	}
	s.erase(0, i); //Delete leading spaces
	len = s.size();

	std::size_t j = len - 1;
	while(j > i){
		if(s[j] != ' '){
			break;
		}
	}
	if(j != len - 1){
		s.erase(j + 1, len - j - 1); //Delete trailing spaces
	}
}

class Solution {
public:
	vector<vector<int> > coolThreeSum(vector<int> &num) {
		if (num.size()<3) return vector< vector<int> > ();
		sort(num.begin(), num.end());
		vector< vector<int> > set;
		for(int id=0; id<num.size()-2; id++) {
		    int ids = id+1, ide = int(num.size())-1;
		    while(ids<ide && ids<num.size() && ide>=0) {
		        if (num.at(ids) + num.at(ide) + num.at(id) == 0) {
		            vector<int> ans(3, 0);
		            ans.at(0) = num.at(id); ans.at(1) = num.at(ids);
		            ans.at(2) = num.at(ide); 
		            set.push_back(ans); 
		            ids++; ide--;
		            while(ids<num.size() && (num.at(ids-1) == num.at(ids)))
		                ids++;
		            while(ide>id && (num.at(ide+1) == num.at(ide)))
		                ide--;
		        }
		        else if (num.at(ids) + num.at(ide) + num.at(id) > 0) 
		            ide--;
		        else ids++;
		    }
		    while((id+1)<int(num.size()) && (num.at(id+1) == num.at(id)))
		        id++;
		}
		return set;
	}
	std::vector<std::vector<int> > newThreeSum(std::vector<int> &num) {
		std::vector<std::vector<int> > res;
        if(num.size() <= 2) return res;

        sort(num.begin(), num.end());

        int sameI = INT_MAX;

        for(int i = 0; i < num.size() -2 ; ++i)
        {
            if(num[i] == sameI) continue;
            sameI = num[i];

            int sameJ = INT_MAX;
            for(int j = i + 1; j < num.size() - 1; ++j)
            {
                if(num[j] == sameJ) continue;
                sameJ = num[j];
                int target = -(num[i] + num[j]);

                if(binary_search(num.begin() + j + 1, num.end(), target))
                {
					std::vector<int> newRes;
                    newRes.push_back(num[i]);
                    newRes.push_back(num[j]);
                    newRes.push_back(target);
                    res.push_back(newRes);
                }
            }
        }

        return res;
    }

	std::vector<std::vector<int> > threeSum(std::vector<int> &num) {
		int len = num.size();
		//Sort the original numbers
		sort(num.begin(), num.end());
		std::vector<std::vector<int> > result;
		for(int i = 0; i < len - 2;){
			int dst = 0 - num[i];
			std::map<int, int> re;
			for(int j = i + 1; j < len;){
				if(re.find(dst - num[j]) != re.end() || (num[j] == num[j + 1] && 2 * num[j] == dst)){ //Find a result
					std::vector<int> instance(3);
					instance[0] = num[i];
					instance[1] = dst - num[j]; 
					instance[2] = num[j];
					//instance is already in non-desending order
					result.push_back(instance);
				}
				re[num[j]] = num[j];
				int k = j + 1;
				while(k < len && num[k] == num[j]){//Skip same numbers
					++k;
				}
				j = k;
			}
			int k = i + 1;
			while(k < len && num[k] == num[i]){ //Skip same numbers
				++k;
			}
			i = k;
		}
		return result;
    }
};

int main(){
	int value;
	std::vector<int> nums;
	while(std::cin >> value){
		nums.push_back(value);
	}
	Solution s;
	std::vector<std::vector<int> > result = s.threeSum(nums);
	int len = result.size();
	std::cout << len << std::endl;
	for(int i = 0; i < len; ++i){
		int tmpLen = result[i].size();
		for(int j = 0; j < tmpLen; ++j){
			std::cout << result[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
