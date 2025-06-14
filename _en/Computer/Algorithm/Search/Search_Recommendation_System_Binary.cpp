#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
		sort(products.begin(), products.end());

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
};


int main() {
	Solution solution;
	vector<string> products = {
		"mobile", "mouse", "moneypot", "monitor", "mousepad"  // mobile moneypot monitor mouse mousepad
	};
	string searchWord = "mouse";
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