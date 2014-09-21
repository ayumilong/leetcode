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
	std::vector<int> findSubstring(std::string S, std::vector<std::string> &L) {
		std::vector<int> result;
		std::map<std::string, int> needToFind;
		std::map<std::string, int> hasFound;
		int LLen = L.size();
		if(LLen == 0){
			return result;
		}
		for(int i = 0; i < LLen; ++i){
			++needToFind[L[i]];
		}

		int SLen = S.size();
		int wordLen = L[0].size();
		int count = 0;
		int start = -1;
		bool newTry = true;
		for(int i = 0; i < SLen; ){
			if(newTry && SLen - i < LLen * wordLen){
				break;
			}
			std::string cur = S.substr(i, wordLen);
			if(needToFind.find(cur) != needToFind.end()){
				newTry = false;
				if(count == 0){
					start = i;
				}
				++count;
				if((++hasFound[cur]) > needToFind[cur]){ //Not suitable, try next
					i = start + 1;
					count = 0;
					hasFound.clear();
					start = -1;
					newTry = true;
					continue;
				}
				if(count == LLen){ //Find a substring
					result.push_back(start);
					i = start + 1;
					newTry = true;
					count = 0;
					hasFound.clear();
					start = -1;
					continue;
				}
				i += wordLen;
			}else{
				if(start != -1){
					i = start + 1;
					start = -1;
				}else{
					++i;
				}
				newTry = true;
				count = 0;
				hasFound.clear();
			}
		}
		return result;
	}
	/*
	std::vector<std::string> connect(std::string word, std::vector<std::string> middleResult, int len){
		std::vector<std::string> result;
		int resultLen = middleResult.size();
		for(int i = 0; i < resultLen; ++i){
			int wordLen = middleResult[i].size();
			for(int j = 0; j <= wordLen; j += len){
				result.push_back(middleResult[i].substr(0, j) + word + middleResult[i].substr(j));
			}
		}
		return result;
	}
	std::vector<std::string> concatenation(std::vector<std::string> &words){
		int len = words.size();
		std::vector<std::string> result;
		if(len == 0){
			return result;
		}
		if(len == 1){
			result.push_back(words[0]);
			return result;
		}
		int wordLen = words[0].size();
		if(wordLen == 0){
			result.push_back("");
			return result;
		}
		std::vector<std::string> newWords(words.begin() + 1, words.end());
		std::vector<std::string> middleResult = concatenation(newWords);
		result = connect(words[0], middleResult, wordLen);
		return result;
	}

	std::vector<int> findSubstring(std::string S, std::vector<std::string> &L) {
		std::vector<int> result;
		std::vector<std::string> wordStr = concatenation(L);
		int wordStrLen = wordStr.size();
		if(wordStrLen == 0){
			return result;
		}
		int strLen = wordStr[0].size();
		int len = S.size();
		if(strLen > len){
			return result;
		}
		for(int i = 0; i < wordStrLen; ++i){
			size_t start = 0;
			while((start = S.find(wordStr[i], start)) != std::string::npos){
				result.push_back(start);
				start += wordStr[i].size(); 
			}
		}
		return result;
    }
	*/
};

int main(){
	Solution s;
	std::vector<std::string> words;
	words.push_back("aa");
	words.push_back("aa");
	std::vector<int> strs = s.findSubstring("aaaaaaaaaaaa", words);
	int len = strs.size();
	for(int i = 0; i < len; ++i){
		std::cout << strs[i] << std::endl;
	}
	return 0;
}
