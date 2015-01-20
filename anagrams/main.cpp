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
#include <unordered_map>
#include <algorithm>
#include <functional>

using namespace std;

class Solution{
public:
	vector<string> anagrams(vector<string> &strs){
		int len = strs.size();
		vector<string> result;
		if(len == 0){
			return result;
		}
		unordered_map<string, int> strMap;
		for(int i = 0; i < len; ++i){
			string cur = strs[i];
			sort(cur.begin(), cur.end());
			unordered_map<string, int>::iterator iter = strMap.find(cur);
			if(iter == strMap.end()){
				strMap[cur] = -1 - i;
			}else{
				if(iter -> second < 0){
					result.push_back(strs[-1 - iter -> second]);
					iter -> second = 1;
				}
				result.push_back(strs[i]);
			}
		}
		return result;
	}
};

int main(){
	string value;
	vector<string> strs;
	while(std::cin >> value){
		strs.push_back(value);
	}
	Solution s;
	vector<string> result = s.anagrams(strs);
	int len = result.size();
	for(int i = 0; i < len; ++i){
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;

	hash<string> strHash;//Hash function
	std::cout << strHash("Hello") << "  " << strHash("World") << std::endl;
	return 0;
}

class Singleton{
private:
	Singleton() {}
	static Singleton *instance;
	
	class DeleteInstance{
	public:
		~DeleteInstance(){
			if(Singleton::instance){
				delete instance;
			}
		}
	};
	static DeleteInstance di;
public:
	static Singleton* getInstance(){
		if(instance == NULL){
			instance = new Singleton();
		}
		return instance;
	}
};
