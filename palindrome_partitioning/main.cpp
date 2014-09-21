/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Thu 27 Feb 2014 11:28:59 PM EST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

class Solution {
private:
	std::vector<bool> hasCompute;
	std::vector<std::vector<std::vector<std::string> > > midResult;

	bool isPalindrome(const std::string s){
		int len = s.size();
		int i;
		for(i = 0; i < len/2; ++i){
			if(s[i] != s[len - i - 1]){
				break;
			}
		}
		if(i == len/2){
			return true;
		}else{
			return false;
		}
	}

	int rlLongestPalindrome(const std::string s){
		int len = s.size();
		int longestLen = len - 1; //The next position of the end of the longest palindrome
		for(int i = len - 2; i >= 0; --i){
			if(s[len - 1] == s[i]){//If the first character is the same with the last character, curStr maybe a palindrome string
				std::string curStr = s.substr(i, len - i);
				if(isPalindrome(curStr)){
					longestLen = i;
				}
			}
		}
		return len - longestLen;
	}

	int lrLongestPalindrome(const std::string s){
		int len = s.size();
		int longestLen = 0; //The next position of the end of the longest palindrome
		for(int i = 1; i < len; ++i){
			if(s[0] == s[i]){//If the first character is the same with the last character, curStr maybe a palindrome string
				std::string curStr = s.substr(0, i + 1);
				if(isPalindrome(curStr)){
					longestLen = i;
				}
			}
		}
		return longestLen + 1;
	}

	std::vector<std::vector<std::string> > connect(const std::string& str, std::vector<std::vector<std::string> >& midResult){
		int len = midResult.size();
		std::vector<std::vector<std::string> > result(midResult.begin(), midResult.end());
		if(len == 0){
			std::vector<std::string> temp;
			temp.push_back(str);
			result.push_back(temp);
		}
		for(int i = 0; i < len; ++i){
			result[i].insert(result[i].begin(), str);
		}
		return result;
	}

	void saveMidResult(std::vector<std::vector<std::string> >& result, std::vector<std::vector<std::string> >& temp){
		int len = temp.size();
		for(int i = 0; i < len; ++i){
			result.push_back(temp[i]);
		}
	}
public:
	std::vector<std::vector<std::string> > partition(std::string s){
		int len = s.size();
		if(hasCompute.size() == 0){
			hasCompute.resize(len + 1, false);
			midResult.resize(len + 1);
		}
		for(int i = 0; i < len; ++i){
			std::string curStr = s.substr(0, i + 1);
			std::vector<std::vector<std::string> > temp;
			if(isPalindrome(curStr)){//If the current string is a palindrome
				if(not hasCompute[len - i - 1]){
					midResult[len - i - 1] = partition(s.substr(i + 1, len - i - 1));
					hasCompute[len - i - 1] = true;
				}
				temp = connect(curStr, midResult[len - i - 1]); 
			}
			saveMidResult(midResult[len], temp);
		}
		return midResult[len];
    }
	int oldMinCut(std::string s){ //Return the minimum cut number
		int len = s.size();
		int lrMinCut = 0;
		int rlMinCut = 0;
		int lastPos = 0;
		for(int i = 0; i < len; ){
			lastPos = i;
			i += lrLongestPalindrome(s.substr(i, len - i));
			//std::cout << "Line 110: i = " << i << " lastPos = " << lastPos << " " << s.substr(lastPos, i - lastPos) << std::endl;
			++lrMinCut;
		}
		lastPos = 0;
		for(int i = len - 1; i >= 0; ){
			lastPos = i;
			i -= rlLongestPalindrome(s.substr(0, i + 1));
			//std::cout << "Line 102: i = " << i << " lastPos = " << lastPos << " " << s.substr(i + 1, lastPos - i) << std::endl;
			++rlMinCut;
		}
		return lrMinCut < rlMinCut ? lrMinCut - 1 : rlMinCut - 1;
    }
};

int main(){
	Solution s;
	std::vector<std::vector<std::string> > result;
result = s.partition("ababbbabbaba");
	int len1 = result.size();
	for(int i = 0; i < len1; ++i){
		int len2 = result[i].size();
		for(int j = 0; j < len2; ++j){
			std::cout << result[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Min cut: \n" << s.oldMinCut("adabdcaebdcebdcacaaaadbbcadabcbeabaadcbcaaddebdbddcbdacdbbaedbdaaecabdceddccbdeeddccdaabbabbdedaaabcdadbdabeacbeadbaddcbaacdbabcccbaceedbcccedbeecbccaecadccbdbdccbcbaacccbddcccbaedbacdbcaccdcaadcbaebebcceabbdcdeaabdbabadeaaaaedbdbcebcbddebccacacddebecabccbbdcbecbaeedcdacdcbdbebbacddddaabaedabbaaabaddcdaadcccdeebcabacdadbaacdccbeceddeebbbdbaaaaabaeecccaebdeabddacbedededebdebabdbcbdcbadbeeceecdcdbbdcbdbeeebcdcabdeeacabdeaedebbcaacdadaecbccbededceceabdcabdeabbcdecdedadcaebaababeedcaacdbdacbccdbcece") << std::endl;
	return 0;
}
