/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool computeInterleave(string s1, int pos1, string s2, int pos2, string s3, int pos3, vector<vector<char> >& dp){
		int len1 = s1.size();
		int len2 = s2.size();
		int len3 = s3.size();
		int i1 = pos1;
		int i2 = pos2;
		int i3 = pos3;
		while(i3 < len3){
			if(s3[i3] != s1[i1] && se[i3] != s2[i2]){
				return false;
			}
			if(s3[i3] == s1[i1]){
				if('u' == dp[i1 + 1][i2]){
					return true;
				}else{
					bool result == computeInterleave();
					if(resut){
						dp[len1 - i1 - 1][len2 - i2] = 't';
						return true;
					}else{
						dp[len1 - i1 - 1][len2 - i2] = 'f';
					}
				}
			}
			if(s3[i3] == s2[i2]){
			}else{
				return false;
			}
		}
		dp[len1 - pos1][len2 - pos2] = 't';
		return true;
	}

    bool isInterleave(string s1, string s2, string s3) {
		int len1 = s1.size();
		int len2 = s2.size();
		int len3 = s3.size();
		if(len1 + len2 != len3){
			return false;
		}
		vector<vector<bool> > dp(len1 + 1, vector<char>(len2 + 1, 'u'));
		return computeInterleave(s1, 0, s2, 0, s3, 0, dp);
    }
};

int main(){
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	Solution s;
	if(s.isInterleave(s1, s2, s3)){
		cout << "True" << endl;
	}else{
		cout << "False" << endl;
	}
	return 0;
}
