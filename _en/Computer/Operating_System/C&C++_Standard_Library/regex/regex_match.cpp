/* regex_match.cpp
Author: BSS9395
Update: 2022-02-19T16:44:00+08@China-Guangdong-Zhanjiang+08
Design: Regular Expression
Credit: https://www.cplusplus.com/reference/regex/regex_match/
*/

/* CPP14
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

void Regex_Match_string() {
    string stri(R"(brilliantstarrysky9395@gmail.com)");
    smatch smat;
    regex patt = regex(R"(^[a-zA-Z0-9]+@[a-zA-Z0-9]+.[a-zA-Z0-9]+)");

    if (regex_match(stri, patt)) {
        cout << "matched" << endl;
    }

    if (regex_match(stri, smat, patt)) {
        cout << smat.size() << " matches: ";
        for (iptr i = 0, size = (iptr)smat.size(); i < size; i += 1) {
            cout << "[" << smat[i] << "]";
        }
        cout << endl;
    }
}

void Regex_Match_cstring() {
    const char *stri = R"(subject)";
    cmatch cmat;
    const char *patt = R"((sub)(.*))";

    if (regex_match(stri, regex(patt))) {
        cout << "matched" << endl;
    }

    if (regex_match(stri, cmat, regex(patt))) {
        cout << cmat.size() << " matches: ";
        for (iptr i = 0, size = (iptr)cmat.size(); i < size; i += 1) {
            cout << "[" << cmat[i] << "]";
        }
        cout << endl;
    }
}

int main(int argc, char *argv[]) {
    // Regex_Match_string();
    Regex_Match_cstring();

    return 0;
}
