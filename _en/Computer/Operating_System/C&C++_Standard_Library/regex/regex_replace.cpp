/* regex_replace.cpp
Author: BSS9395
Update: 2022-02-19T16:50:00+08@China-Guangdong-Zhanjiang+08
Design: Regular Expression
Original: https://www.cplusplus.com/reference/regex/regex_replace/
*/

/* CPP11
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
*/

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
typedef intptr_t iptr;

void Regex_Replace_string() {
    string stri = string(R"(there is a subsequence in the string.)");
    string patt = string(R"(\b(sub)(\S*)\b)");
    string repl = string(R"($1-$2)");

    cout << regex_replace(string(stri), regex(patt), string(repl)) << endl;

    cout << regex_replace(string(stri), regex(patt), string(repl), std::regex_constants::format_no_copy) << endl;
}

void Regex_Replace_cstring() {
    const char *stri = R"(there is a subsequence in the string.)";
    const char * patt = R"(\b(sub)(\S*)\b)";
    const char * repl = R"($1-$2)";

    cout << regex_replace(stri, regex(patt), repl) << endl;

    cout << regex_replace(stri, regex(patt), repl, std::regex_constants::format_no_copy) << endl;
}


int main(int argc, char *argv[]) {
    // Regex_Replace_string();
    Regex_Replace_cstring();

    return 0;
}
