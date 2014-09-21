/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Tue 18 Feb 2014 10:29:41 PM EST
 ************************************************************************/

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
private:
	std::vector<int> isTrue;
	std::vector<std::vector<std::string>> midResult;

	void contactWords(const std::string& word, std::vector<std::string>& words){
		int len = words.size();
		for(int i = 0; i < len; ++i){
			words[i] = word + " " + words[i];
		}
	}

	void pushWords(std::vector<std::string>& words, const std::vector<std::string>& temp){
		int len = temp.size();
		for(int i = 0; i < len; ++i){
			words.push_back(temp[i]);
		}
	}
public:
	std::vector<std::string> wordBreak(std::string s, std::unordered_set<std::string> &dict) {
		std::vector<std::string> result;
		int len = s.size();
		isTrue.clear();
		midResult.clear();
		isTrue.resize(len, 0);
		midResult.resize(len, std::vector<std::string>());
		std::string word = "";
		for(int i = 0; i < len; ++i){
			word += s[i];
			if(dict.find(word) != dict.end()){//If find the current word
				if(i != len - 1){ //Not the end of sentence s
					if(isTrue[len - i - 2] == 0){//The first time
						midResult[len - i - 2] = wordBreak(s.substr(i + 1, len - i), dict);
						if(midResult[len - i - 2].size() != 0){//Find a solution
							isTrue[len - i - 2] = 1;
						}else{
							isTrue[len - i - 2] = -1;
						}
					}
					if(isTrue[len - i - 2] == 1){//Find a solution
						std::vector<std::string> temp = midResult[len - i - 2];
						contactWords(word, temp);
						pushWords(result, temp);
					}
				}else{//Reached the end of the sentence s, so just push_back and return
					result.push_back(word);
					return result;
				}
			}
		}
		return result; //Return all the solutions
    }

    bool wordBreakI(std::string s, std::unordered_set<std::string> &dict) {
		int len = s.size();
		isTrue.clear();
		isTrue.resize(len, 0);
		std::string word = "";
		for(int i = 0; i < len; ++i){
			word += s[i];
			if(dict.find(word) != dict.end()){//If find the current word
				if(i != len - 1){
					if(isTrue[len - i - 2] == 0){
						if(wordBreakI(s.substr(i + 1, len - i), dict)){
							isTrue[len - i - 2] = 1;
						}else{
							isTrue[len - i - 2] = -1;
						}
					}
					if(isTrue[len - i - 2] == 1){
						return true;
					}
				}else{
					return true;
				}
			}
		}
		return false;
    }
};

void printWords(const std::vector<std::string>& result){
	int len = result.size();
	for(int i = 0; i < len; ++i){
		std::cout << result[i] << std::endl;
	}
}

int main(){
	std::unordered_set<std::string> dict;
	dict.insert("aaaa");
	dict.insert("aa");
	dict.insert("a");
	Solution s;
	std::vector<std::string> result = s.wordBreak("aaaaaaa", dict);
	std::cout << result.size() << std::endl;
	if(result.size() != 0){
		printWords(result);
	}else{
		std::cout << "False" << std::endl;
	}
	if(s.wordBreakI("aaaaaaa", dict)){
		std::cout << "true" << std::endl;
	}else{
		std::cout << "False" << std::endl;
	}
	dict.clear();
	dict.insert("car");
	dict.insert("ca");
	dict.insert("rs");
	if(s.wordBreakI("cars", dict)){
		std::cout << "true" << std::endl;
	}else{
		std::cout << "False" << std::endl;
	}
	return 0;
}
