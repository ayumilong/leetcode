/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <random>
#include <ctime>
#include <string>

class Solution{
public:
	std::string longestPalindrome(std::string s){
		int i, j, n, maxLen = 0;
        n = s.length();
        if (n <= 1) return s;

        bool P[1001][1001];
        const char * ptr = s.data();
        for (i = 0; i < n; i++){
            P[i][i] = true;
        }

		std::string retval;
        int st,le;
        for (i = 0; i < n-1; i++){
            P[i][i+1] = (ptr[i] == ptr[i+1]);
            if (P[i][i+1]){
                st = i;
                le = 2;
            }
        }

        for (i = 2; i < n; i++){
            for (j = 0; j < n-i; j++){
                P[j][j+i] = P[j+1][j+i-1] && (ptr[j] == ptr[j+i]);

                if (P[j][j+i] && maxLen < i+1){ // Should be i + 1
                    maxLen = i+1; // Should be i + 1
                    st = j;
                    le = i+1; // Should be i + 1
                }
            }
        }
        return s.substr(st,le);
	}
	/*
	 * This solution is too slow
	bool isPalindrome(std::string s){
		int len = s.size();
		int i;
		for(i = 0; i < len/2; ++i){
			if(s[i] != s[len - i - 1]){
				break;
			}
		}
		if(i != len/2){
			return false;
		}
		return true;
	}
	std::string longestPalindrome(std::string s){
		int len = s.size();
		if(len == 0){
			return "";
		}
		if(isPalindrome(s)){
			return s;
		}
		bool palindrome[1000][1000];
		int longest = 1;
		std::string longestStr = s.substr(0, 1);
		for(int i = 1; i < len; ++i){
			if(len - i <= longest){
				break;
			}
			for(int j = len - 1; j >= i; --j){
				int curLen = j - i + 1;
				if(curLen <= longest){
					break;
				}
				std::string tmp = s.substr(i, j - i + 1);
				if(palindrome[i - 1][j] == false){ //Maybe this is a palindrome
					if(isPalindrome(tmp)){ //Find a palindrome
						palindrome[i][j] = true;
						if(longest < (j - i + 1)){ //If the current palindrome is a longer one or not
							longest = j - i + 1;
							longestStr = tmp; 
						}
						break;
					}
				}else{
					palindrome[i][j] = true;
				}
			}
		}
		return longestStr;
    }
	*/
};

int main(){

	std::default_random_engine e(time(0));
	std::uniform_int_distribution<unsigned> d(97, 122);
	std::string s;
	for(int i = 0; i < 20; ++i){
		s += (char)d(e);
	}
	std::cout << s << std::endl;

	Solution lp;
	std::cout << lp.longestPalindrome("zudfweormatjycujjirzjpyrmaxurectxrtqedmmgergwdvjmjtstdhcihacqnothgttgqfywcpgnuvwglvfiuxteopoyizgehkwuvvkqxbnufkcbodlhdmbqyghkojrgokpwdhtdrwmvdegwycecrgjvuexlguayzcammupgeskrvpthrmwqaqsdcgycdupykppiyhwzwcplivjnnvwhqkkxildtyjltklcokcrgqnnwzzeuqioyahqpuskkpbxhvzvqyhlegmoviogzwuiqahiouhnecjwysmtarjjdjqdrkljawzasriouuiqkcwwqsxifbndjmyprdozhwaoibpqrthpcjphgsfbeqrqqoqiqqdicvybzxhklehzzapbvcyleljawowluqgxxwlrymzojshlwkmzwpixgfjljkmwdtjeabgyrpbqyyykmoaqdambpkyyvukalbrzoyoufjqeftniddsfqnilxlplselqatdgjziphvrbokofvuerpsvqmzakbyzxtxvyanvjpfyvyiivqusfrsufjanmfibgrkwtiuoykiavpbqeyfsuteuxxjiyxvlvgmehycdvxdorpepmsinvmyzeqeiikajopqedyopirmhymozernxzaueljjrhcsofwyddkpnvcvzixdjknikyhzmstvbducjcoyoeoaqruuewclzqqqxzpgykrkygxnmlsrjudoaejxkipkgmcoqtxhelvsizgdwdyjwuumazxfstoaxeqqxoqezakdqjwpkrbldpcbbxexquqrznavcrprnydufsidakvrpuzgfisdxreldbqfizngtrilnbqboxwmwienlkmmiuifrvytukcqcpeqdwwucymgvyrektsnfijdcdoawbcwkkjkqwzffnuqituihjaklvthulmcjrhqcyzvekzqlxgddjoir") << std::endl;

	return 0;
}
