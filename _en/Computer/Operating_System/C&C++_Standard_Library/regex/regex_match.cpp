/* regex_match.cpp
Author: BSS9395
Update: 2020-08-24T12:24:00+08@China-Guangdong-Zhanjiang+08
Design: Regular Expression
Original: https://www.cplusplus.com/reference/regex/regex_match/
*/


#if CPP14
C - strings(1)
template <class charT, class traits>
bool regex_match(const charT* s, const basic_regex<charT, traits>& rgx, regex_constants::match_flag_type flags = regex_constants::match_default);

strings(2)
template <class ST, class SA, char charT, class traits>
bool regex_match(const basic_string<charT, ST, SA>& s, const basic_regex<charT, traits>& rgx, regex_constants::match_flag_type flags = regex_constants::match_default);

ranges(3)
template <class BidirectionalIterator, class charT, class traits>
bool regex_match(BidirectionalIterator first, BidirectionalIterator last, const basic_regex<charT, traits>& rgx, regex_constants::match_flag_type flags = regex_constants::match_default);

with match_results(4, 5, 6)
template <class charT, class Alloc, class traits>
bool regex_match(const charT* s, match_results<const charT*, Alloc>& m, const basic_regex<charT, traits>& rgx, regex_constants::match_flag_type flags = regex_constants::match_default);

template <class ST, class SA, class Alloc, class charT, class traits>
bool regex_match(const basic_string<charT, ST, SA>& s, match_results<typename basic_string<charT, ST, SA>::const_iterator, Alloc>& m, const basic_regex<charT, traits>& rgx, regex_constants::match_flag_type flags = regex_constants::match_default);

template <class BidirectionalIterator, class Alloc, class charT, class traits>
bool regex_match(BidirectionalIterator first, BidirectionalIterator last, match_results<BidirectionalIterator, Alloc>& m, const basic_regex<charT, traits>& rgx, regex_constants::match_flag_type flags = regex_constants::match_default);

moving string(deleted) (7)
template <class ST, class SA, class Alloc, class charT, class traits>
bool regex_match(const basic_string<charT, ST, SA>&&, match_results<typename basic_string<charT, ST, SA>::const_iterator, Alloc>&, const basic_regex<charT, traits>&, regex_constants::match_flag_type = regex_constants::match_default) = delete;
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


//const char *text = "brilliantstarrysky9395@gmail.com";
//const char *pattern = "^[a-zA-Z0-9]+@[a-zA-Z0-9]+.[a-zA-Z0-9]+";
const char *text = "subject";
const char *pattern = "(sub)(.*)";

void Regex_Match() {
    if (regex_match(string(text), regex(pattern))) {
        cout << "matched" << endl;
    }

    string str(text);
    smatch str_mat;
    // if (regex_match(string(text), str_mat, regex(pattern))) {
    if (regex_match(str, str_mat, regex(pattern))) {
        cout << str_mat.size() << " matches: ";
        for (int i = 0; i < str_mat.size(); i += 1) {
            cout << "[" << str_mat[i] << "]";
        }
        cout << endl;
    }

    ////////////////////////////////////

    if (regex_match(text, regex(pattern))) {
        cout << "matched" << endl;
    }

    cmatch cstr_mat;
    if (regex_match(text, cstr_mat, regex(pattern))) {
        cout << cstr_mat.size() << " matches: ";
        for (int i = 0; i < cstr_mat.size(); i += 1) {
            cout << "[" << cstr_mat[i] << "]";
        }
        cout << endl;
    }
}

int main(int argc, char *argv[]) {
    Regex_Match();

    return 0;
}