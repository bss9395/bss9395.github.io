/* Cpp_Recommendation.cpp
Author: BSS9395
Update: 2025-05-25T17:16:00+08@China-ShangHai+08
Credit: https://leetcode.cn/problems/search-suggestions-system/description/
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
	vector<vector<string>> _Recommendate_LowerBound(vector<string> &products, string &searchWord) {
		std::sort(products.begin(), products.end());

		vector<vector<string>> result;
		string query = "";
		auto fore = products.begin();
		for (auto& ch : searchWord) {
			query += ch;
			auto back = lower_bound(fore, products.end(), query);
			vector<string> selects;
			for (int i = 0; i < 3; i += 1) {
				if (back + i < products.end() && (*(back + i)).find(query) == 0) {
					selects.push_back(*(back + i));
				} else {
					break;
				}
			}
			result.push_back(selects);
			fore = back;
		}
		return result;
	}

public:
	struct Trie {
		unordered_map<char, Trie> children;
		priority_queue<string> words;
	};
	void _Add_Word(Trie* root, string& word) {
		Trie* iter = root;
		for (char& ch : word) {
			if (iter->children.count(ch) == 0) {
				iter->children[ch] = Trie();
			}
			iter = &iter->children[ch];
			iter->words.push(word);
			if (3 < iter->words.size()) {
				iter->words.pop();
			}
		}
	}

	vector<vector<string>> _Recommendate_Trie(vector<string>& products, string searchWord) {
		Trie root = Trie();
		for (int i = 0; i < products.size(); ) {
			_Add_Word(&root, products[i]);
			i += 1;
		}

		vector<vector<string>> result;
		Trie* iter = &root;
		bool flag = false;
		for (int i = 0; i < searchWord.size(); ) {
			char ch = searchWord[i];
			vector<string> selects;
			if (flag == true || iter->children.count(ch) == false) {
				result.push_back(selects);
				flag = true;
				i += 1;
				continue;
			}
			iter = &iter->children[ch];
			while (iter->words.empty() == false) {
				selects.push_back(iter->words.top());
				iter->words.pop();
			}
			reverse(selects.begin(), selects.end());
			result.push_back(selects);
			i += 1;
		}
		return result;
	}
};

void _Test_Recommendate_LowerBound() {
	vector<string> products = {
	"mobile", "mouse", "moneypot", "monitor", "mousepad"  // mobile moneypot monitor mouse mousepad
	};
	string searchWord = "mause";
	vector<vector<string>> result = Solution()._Recommendate_LowerBound(products, searchWord);
	for (int i = 0; i < result.size(); ) {
		vector<string>& presult = result[i];
		string ans = "[";
		for (int j = 0; j < presult.size(); ) {
			if (j != 0) {
				ans += ", ";
			}
			ans += presult[j];
			j += 1;
		}
		ans += "]";
		std::cout << ans << std::endl;
		i += 1;
	}
}

void _Test_Recommendate_Trie() {
	vector<string> products = {
	"mobile", "mouse", "moneypot", "monitor", "mousepad"
	};
	string searchWord = "mause";
	vector<vector<string>> result = Solution()._Recommendate_Trie(products, searchWord);
	for (int i = 0; i < result.size(); ) {
		vector<string>& presult = result[i];
		string ans = "[";
		for (int j = 0; j < presult.size(); ) {
			if (j != 0) {
				ans += ", ";
			}
			ans += presult[j];
			j += 1;
		}
		ans += "]";
		std::cout << ans << std::endl;
		i += 1;
	}
}


int main() {
	_Test_Recommendate_LowerBound();
	_Test_Recommendate_Trie();

	return 0;
}