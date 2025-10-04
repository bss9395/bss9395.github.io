/* Cpp_Find_Chains.cpp
Author: bss9395
Update: 2025/10/01T15:25:00+08@China-GuangDong-ZhanJiang+08
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

/*
输入：graph  = {{"U1", {"U1", "U2"}}, {"U2", {"U3"}}, {"U3", {}}, {"U4", {"U5"}}, {"U5", {}}};
输出：result = {{"U1", "U1"}, {"U1", "U2", "U3"}, {"U4", "U5"}};
*/
class Solution {
public:
	void _Chain_DFS(unordered_map<string, vector<string>> &graph, unordered_map<string, bool> &flag, unordered_map<string, bool> &circle, vector<string> &chain, string &curr, vector<vector<string>> &chains) {
		flag[curr] = true;
		auto iter = graph.find(curr);
		if (iter != graph.end()) {
			chain.push_back(iter->first);
			if (circle[iter->first] == true) {
				chains.push_back(chain);
				return;
			}
			circle[iter->first] = true;
			if (iter->second.empty() == true) {
				chains.push_back(chain);
				return;
			}
			for (auto next = iter->second.begin(); next != iter->second.end(); ) {
				_Chain_DFS(graph, flag, circle, chain, *next, chains);
				chain.pop_back();
				++next;
			}
		}
	}

	vector<vector<string>> _Find_Chains(unordered_map<string, vector<string>> &graph) {
		unordered_map<string, bool> flag;
		for (auto iter = graph.begin(); iter != graph.end();) {
			flag[iter->first] = false;
			++iter;
		}

		vector<vector<string>> chains;
		for (auto iter = graph.begin(); iter != graph.end(); ) {
			vector<string> chain;
			if (flag[iter->first] == false) {
				unordered_map<string, bool> circle;
				for (auto iter = graph.begin(); iter != graph.end(); ) {
					circle[iter->first] = false;
					++iter;
				}

				chain.push_back(iter->first);
				circle[iter->first] = true;
				for (auto next = iter->second.begin(); next != iter->second.end(); ) {
					_Chain_DFS(graph, flag, circle, chain, *next, chains);
					chain.pop_back();
					++next;
				}
			}
			++iter;
		}
		return chains;
	}
};

int main() {
	unordered_map<string, vector<string>> graph;
	graph["U1"] = { "U1", "U2" };
	graph["U2"] = { "U3" };
	graph["U3"] = {};
	graph["U4"] = { "U5" };
	graph["U5"] = {};

	vector<vector<string>> result = Solution()._Find_Chains(graph);
	std::cout << "========================================" << std::endl;
	for (int i = 0; i < result.size();) {
		for (int j = 0; j < result[i].size(); ) {
			std::cout << result[i][j] << " ";
			j += 1;
		}
		std::cout << std::endl;
		i += 1;
	}

	return 0;
}
