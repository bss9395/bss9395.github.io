/* Search_Recommendation_System.cpp
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

struct Trie {
	unordered_map<char, Trie*> child;
	priority_queue<string> words;
};

class Solution {
public:
	void addWord(Trie* root, string& word) {
		Trie* iter = root;
		for (char& ch : word) {
			if (iter->child.count(ch) == 0) {
				iter->child[ch] = new Trie();
			}
			iter = iter->child[ch];
			iter->words.push(word);
			if (3 < iter->words.size()) {
				iter->words.pop();
			}
		}
	}

	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
		Trie* root = new Trie();
		for (string& word : products) {
			addWord(root, word);
		}

		vector<vector<string>> result;
		Trie* iter = root;
		bool flag = false;
		for (char& ch : searchWord) {
			vector<string> selects;
			if (flag == true || iter->child.count(ch) == false) {
				result.push_back(selects);
				flag = true;
			} else {
				iter = iter->child[ch];				
				while (iter->words.empty() == false) {
					selects.push_back(iter->words.top());
					iter->words.pop();
				}
				reverse(selects.begin(), selects.end());
				result.push_back(selects);
			}
		}
		return result;
	}
};

int main() {
	Solution solution;
	vector<string> products = {
		"mobile","mouse","moneypot","monitor","mousepad"
	};
	string searchWord = "aouse";
	vector<vector<string>> result = solution.suggestedProducts(products, searchWord);
	for (auto& first : result) {
		string ans = "";
		ans += "[";
		for (auto& second : first) {
			ans += second + ", ";
		}
		if (3 <= ans.size()) {
			ans.pop_back(), ans.pop_back();
		}
		ans += "]";
		cout << ans << endl;
	}

	return 0;
}
