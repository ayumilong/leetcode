/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Mon 17 Mar 2014 07:56:16 PM EDT
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

#define max(a, b) ((a) > (b) ? (a) : (b))

class Solution{
public:
	int lengthOfLongestSubstring(std::string s){  
		std::vector<bool> charTable(256, false);  
        int maxLen = 0;  
        int startIndex = 0;  
		int len = s.size();
        int i;  
        for(i = 0; i < len; ++i){  
            if(charTable[s[i]] == true){//Find a repeat character  
                maxLen = max(i - startIndex, maxLen);  
                while(s[startIndex] != s[i]){//Skip  
                    charTable[s[startIndex++]] = false;  
				}
                ++startIndex;  
            }else{
				charTable[s[i]] = true;
			}	
        }  
       	return max(maxLen, i-startIndex);  
    }  

	/*
    int lengthOfLongestSubstring(std::string s){
		int len = s.size();
		size_t maxLen = 0;
		for(int i = 0; i < len; ++i){
			std::string subStr = s.substr(i, 1); 
			int j;
			for(j = i + 1; j < len; ++j){
				if(subStr.find_first_of(s[j]) != std::string::npos){//Find a repeat character
					break;
				}
				subStr += s[j];
			}
			if(maxLen < subStr.size()){
				maxLen = subStr.size();
			}
			if(j == len){
				break;
			}
		}
		return maxLen;
    }
	*/
};

int main(){
	Solution s;
	std::string str;
	while(std::cin >> str){
		std::cout << s.lengthOfLongestSubstring(str) << std::endl;
	}
	return 0;
}
