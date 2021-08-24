/* regex_replace.cpp
Author: BSS9395
Update: 2020-08-24T12:24:00+08@China-Guangdong-Zhanjiang+08
Design: Regular Expression
Original: https://www.cplusplus.com/reference/regex/regex_replace/
*/

#if CPP11
c - string / c - string(1)
template <class traits, class charT>
basic_string<charT> regex_replace(const charT* s, const basic_regex<charT, traits>& rgx, const charT* fmt, regex_constants::match_flag_type flags = regex_constants::match_default);

c - string / string(2)
template <class traits, class charT, class ST, class SA>
basic_string<charT> regex_replace(const charT*s, const basic_regex<charT, traits>& rgx, const basic_string<charT, ST, SA>& fmt, regex_constants::match_flag_type flags = regex_constants::match_default);

string / c - string(3)
template <class traits, class charT, class ST, class SA>
basic_string<charT, ST, SA> regex_replace(const basic_string<charT, ST, SA>& s, const basic_regex<charT, traits>& rgx, const charT* fmt, regex_constants::match_flag_type flags = regex_constants::match_default);

string / string(4)
template <class traits, class charT, class ST, class SA, class FST, class FSA>
basic_string<charT, ST, SA> regex_replace(const basic_string<charT, ST, SA>& s, const basic_regex<charT, traits>& rgx, const basic_string<charT, FST, FSA>& fmt, regex_constants::match_flag_type flags = regex_constants::match_default);

range / c - string(5)
template <class OutputIterator, class BidirectionalIterator, class traits, class charT>
OutputIterator regex_replace(OutputIterator out, BidirectionalIterator first, BidirectionalIterator last, const basic_regex<charT, traits>& rgx, const charT* fmt, regex_constants::match_flag_type flags = regex_constants::match_default);

range / string(6)
template <class OutputIterator, class BidirectionalIterator, class traits, class charT, class ST, class SA>
OutputIterator regex_replace(OutputIterator out, BidirectionalIterator first, BidirectionalIterator last, const basic_regex<charT, traits>& rgx, const basic_string<charT, ST, SA>& fmt, regex_constants::match_flag_type flags = regex_constants::match_default);
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

const char *text = "there is a subsequence in the string.";
const char *pattern = "\\b(sub)(\\S*)\\b";
const char *action = "sub-$2";

void Regex_Replace() {
    cout << regex_replace(string(text), regex(pattern), string(action)) << endl;

    cout << regex_replace(string(text), regex(pattern), string(action), std::regex_constants::format_no_copy) << endl;

    ////////////////////////////////////

    cout << regex_replace(text, regex(pattern), action) << endl;

    cout << regex_replace(text, regex(pattern), action, std::regex_constants::format_no_copy) << endl;
}


int main(int argc, char *argv[]) {
    Regex_Replace();
    return 0;
}