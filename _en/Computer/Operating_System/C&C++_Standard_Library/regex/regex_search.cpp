/* regex_search.cpp
Author: BSS9395
Update: 2020-08-24T12:24:00+08@China-Guangdong-Zhanjiang+08
Design: Regular Expression
Original: https://www.cplusplus.com/reference/regex/regex_search/
*/

#if CPP14
C - strings(1)
template <class charT, class traits>
bool regex_search(const charT* s, const basic_regex<charT, traits>& rgx, regex_constants::match_flag_type flags = regex_constants::match_default);

strings(2)
template <class ST, class SA, char charT, class traits>
bool regex_search(const basic_string<charT, ST, SA>& s, const basic_regex<charT, traits>& rgx, regex_constants::match_flag_type flags = regex_constants::match_default);

ranges(3)
template <class BidirectionalIterator, class charT, class traits>
bool regex_search(BidirectionalIterator first, BidirectionalIterator last, const basic_regex<charT, traits>& rgx, regex_constants::match_flag_type flags = regex_constants::match_default);

with match_results(4, 5, 6)
template <class charT, class Alloc, class traits>
bool regex_search(const charT* s, match_results<const charT*, Alloc>& m, const basic_regex<charT, traits>& rgx, regex_constants::match_flag_type flags = regex_constants::match_default);

template <class ST, class SA, class Alloc, class charT, class traits>
bool regex_search(const basic_string<charT, ST, SA>& s, match_results<typename basic_string<charT, ST, SA>::const_iterator, Alloc>& m, const basic_regex<charT, traits>& rgx, regex_constants::match_flag_type flags = regex_constants::match_default);

template <class BidirectionalIterator, class Alloc, class charT, class traits>
bool regex_search(BidirectionalIterator first, BidirectionalIterator last, match_results<BidirectionalIterator, Alloc>& m, const basic_regex<charT, traits>& rgx, regex_constants::match_flag_type flags = regex_constants::match_default);

moving string(deleted) (7)
template <class ST, class SA, class Alloc, class charT, class traits>
bool regex_search(const basic_string<charT, ST, SA>&&, match_results<typename basic_string<charT, ST, SA>::const_iterator, Alloc>&, const basic_regex<charT, traits>&, regex_constants::match_flag_type = regex_constants::match_default) = delete;
#endif


#include <iostream>
#include <string>
#include <regex>

using std::cout;
using std::endl;
using std::string;
using std::regex;
using std::cmatch;
using std::smatch;
using std::regex_match;
using std::regex_replace;
using std::regex_search;

const char *text = "this subject has a submarine as a subsequence.";
const char *pattern = "\\b(sub)(\\w*)";

void Regex_Search() {
    string str = string(text);
    smatch str_mat;
    while (regex_search(str, str_mat, regex(pattern))) {
        for (int i = 0; i < str_mat.size(); i += 1) {
            cout << "[" << str_mat[i] << "]";
        }
        cout << endl;
        str = str_mat.suffix().str();
    }
}

void search();
int main(int argc, char *argv[]) {
    Regex_Search();

    return 0;
}