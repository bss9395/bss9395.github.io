/* Charset.cpp
Author: BSS9395
Update: 2023-05-25T15:39:00+08@China-Guangdong-Zhanjiang+08
Design: Charset Converter
*/

/*************************************************************/
/* RFC 3629 defines the mapping as follows :
 *
 * Char. number range  |        UTF-8 octet sequence
 *    (hexadecimal)    |              (binary)
 * --------------------+---------------------------------------------
 * 0000 0000-0000 007F | 0xxxxxxx
 * 0000 0080-0000 07FF | 110xxxxx 10xxxxxx
 * 0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
 * 0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 *
 * Encoding a character to UTF-8 proceeds as follows:
 *
 * 1.  Determine the number of octets required from the character number
 *     and the first column of the table above.  It is important to note
 *     that the rows of the table are mutually exclusive, i.e., there is
 *     only one valid way to encode a given character.
 *
 * 2.  Prepare the high-order bits of the octets as per the second
 *     column of the table.
 *
 * 3.  Fill in the bits marked x from the bits of the character number,
 *     expressed in binary.  Start by putting the lowest-order bit of
 *     the character number in the lowest-order position of the last
 *     octet of the sequence, then put the next higher-order bit of the
 *     character number in the next higher-order position of that octet,
 *     etc.  When the x bits of the last octet are filled in, move on to
 *     the next to last octet, then to the preceding one, etc. until all
 *     x bits are filled in.
 *
 * The definition of UTF-8 prohibits encoding character numbers between
 * U+D800 and U+DFFF,...
*/

#define _CRT_SECURE_NO_WARNINGS
#include <locale>
#include <codecvt>
using namespace std;

class Charset {
#ifdef _WIN32
#define _Platform(windows, linux) windows
#elif __linux__
#define _Platform(windows, linux) linux
#endif

public:
	typedef const char* Locale;
	static inline Locale _native     = _Platform(""      , "");
	static inline Locale _utf_8      = _Platform(".UTF-8", "en_GB.UTF-8");
	static inline Locale _gbk        = _Platform(".936"  , "zh_CN.GBK");
	static inline Locale _ios_8859_1 = _Platform(".28591", "en_GB.ISO-8859-1");
	
public:
	static auto _Update_Locale(Locale locale = _native) -> Locale {
		char* lc_all = setlocale(LC_ALL, NULL);
		fprintf(stderr, "[%s:%d, %s]locale=%s\n", __FILE__, __LINE__, __FUNCTION__, lc_all);
		setlocale(LC_ALL, locale), _locale = locale;
		lc_all = setlocale(LC_ALL, NULL);
		fprintf(stderr, "[%s:%d, %s]locale=%s\n", __FILE__, __LINE__, __FUNCTION__, lc_all);
		return locale;
	}
	static inline Locale _locale = _Update_Locale(_native);

	static auto _From_WString(const wstring& wstr = L"你好，世界！", Locale locale = _native) -> string {
		char* lc_all = setlocale(LC_ALL, locale);
		// fprintf(stderr, "[%s:%d, %s]locale=%s\n", __FILE__, __LINE__, __FUNCTION__, lc_all);
		if (lc_all == NULL) {
			return string{};
		}

		string str = string{};
		str.resize((wstr.size() + 1) * 4);
		int count = (int)wcstombs(&str[0], &wstr[0], str.size());
		// fprintf(stderr, "[%s:%d, %s]numb=%d, %s\n", __FILE__, __LINE__, __FUNCTION__, count, &str[0]);
		str.resize((1 <= count) ? count : 0);
		
		setlocale(LC_ALL, _locale);
		return str;
	}

	static auto _Into_WString(const string& str = "你好，世界！", Locale locale = _native) -> wstring {
		char* lc_all = setlocale(LC_ALL, locale);
		// fprintf(stderr, "[%s:%d, %s]locale=%s\n", __FILE__, __LINE__, __FUNCTION__, lc_all);
		if (lc_all == NULL) {
			return wstring{};
		}

		wstring wstr = wstring{};
		wstr.resize(str.size() + 1);
		int count = (int)mbstowcs(&wstr[0], &str[0], wstr.size());
		// fprintf(stderr, "[%s:%d, %s]numb=%d, %ls\n", __FILE__, __LINE__, __FUNCTION__, count, &wstr[0]);
		wstr.resize((1 <= count) ? count : 0);

		setlocale(LC_ALL, _locale);
		return wstr;
	}

#define _WS(wstr)  Charset::_From_WString(wstr)
#define _SW(str)   Charset::_Into_WString(str)

public:
	static void _Test_From_WString() {
		string str = _WS(L"你好，世界！");
		fprintf(stdout, "%s\n", &str[0]);
			
		str = Charset::_From_WString();
		fprintf(stdout, "%s\n", &str[0]);
	}
	static void _Test_Into_WString() {
		wstring wstr = _SW("你好，世界！");
		fwprintf(stdout, L"%ls\n", &wstr[0]);

		wstr = Charset::_Into_WString();
		fwprintf(stdout, L"%ls\n", &wstr[0]);
	}
};

int main(int argc, char* argv[]) {
	Charset::_Test_From_WString();
	Charset::_Test_Into_WString();

	return 0;
}
