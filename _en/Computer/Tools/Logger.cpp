/* Logger.cpp
Author: BSS9395
Update: 2023-05-21T00:48:00+08@China-Guangdong-Zhanjiang+08
Design: Logger for Debugging
*/

#define _CRT_SECURE_NO_WARNINGS
#include <array>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Exception {
public:
	Exception(const wstring& what) {
		_what = what;
	}

public:
	wstring _what = wstring{};
};

class Logger {
public:
#ifdef _WIN32
#define _Platform(windows, linux) windows
#elif __linux__
#define _Platform(windows, linux) linux
#endif
	typedef const char* Locale;
	static inline Locale _native     = _Platform("", "");
	static inline Locale _utf_8      = _Platform(".UTF-8", "en_GB.UTF-8");
	static inline Locale _gbk        = _Platform(".936", "zh_CN.GBK");
	static inline Locale _ios_8859_1 = _Platform(".28591", "en_GB.ISO-8859-1");

public:
	static auto _Instance(const wstring& instance) -> Logger* {
		for (int i = 0; i < Logger::_loggers.size(); i += 1) {
			if (instance == Logger::_loggers[i]->_instance) {
				return Logger::_loggers[i];
			}
		}
		if (Logger::_loggers.size() < Logger::_loggers_pool) {  // note: non-thread safe but efficient.
			Logger* logger = new Logger();                      // note: allocated once never to be destroyed.
			logger->_instance = instance;
			Logger::_loggers.push_back(logger);
			return logger;
		}
		return nullptr;
	}

public:
	static inline auto _levels = array<const char*, 10>{};
	static inline auto _index  = 0;
	static inline auto _note   = (_levels[_index += 1] = "note ", _index);
	static inline auto _debug  = (_levels[_index += 1] = "debug", _index);
	static inline auto _alert  = (_levels[_index += 1] = "alert", _index);
	static inline auto _error  = (_levels[_index += 1] = "error", _index);
	static inline auto _fatal  = (_levels[_index += 1] = "fatal", _index);
	static inline auto _loggers_pool = 10;
	static inline auto _loggers      = vector<Logger*>{};
	static inline auto _logger       = Logger::_Instance(L"logger");

public:
	wstring _instance = L"logger";
	int     _level    = Logger::_debug;
	Locale  _locale   = _utf_8;
	bool    _console  = true;
	FILE*   _file     = stderr;
	bool    _make     = true;
	string  _filename = "logger.text";
	string  _mode     = "at";

public:
	void _Logging(int level, const char* filename, int line, const char* function) {
		_Logging(level, filename, line, function, L"");
	}
	template<typename ...Types_>
	void _Logging(int level, const char* filename, int line, const char* function, const wstring& format, const Types_& ...types) {
		if (_level <= level) {
			(_make    == true) ? (remove(&_filename[0]), _make = false) : _make;  // note: delete file, not truncate file.
			(_console == true) ? _file : (setlocale(LC_ALL, &_locale[0]), _file = fopen(&_filename[0], &_mode[0]));

			const char* idx = strrchr(filename, '/');
			(idx == NULL) ? (idx = strrchr(filename, '\\')) : idx;
			fprintf(_file, "[%s, %s:%d, %s]", _levels[level], idx == NULL ? filename : idx + 1, line, function);

			if (0 < format.size()) {
				try {
					auto stream = wstring{};
					auto format0 = &format[0];
					_Format(stream, format0, types...);
					fwprintf(_file, L"%ls", &stream[0]);
				}
				catch (const Exception& exception) {
					fwprintf(_file, L"\n\nSystem exited due to exception: %ls\n\n", &exception._what[0]);
					exit(1);
				}
			}
			fwprintf(_file, L"\n");
			fflush(_file);

			(_console == true) ? 0 : (setlocale(LC_ALL, _native), fclose(_file));
		}
	}
#define _Note(...)   _Logging(Logger::_note , __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)
#define _Debug(...)  _Logging(Logger::_debug, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)
#define _Alert(...)  _Logging(Logger::_alert, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)
#define _Error(...)  _Logging(Logger::_error, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)
#define _Fatal(...)  _Logging(Logger::_fatal, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)

	static auto _Format(wstring& stream, const wchar_t*& format) -> void {
		while (format[0] != '\0') {
			stream += format[0];
			format += 1;
		}
	}
	template<typename Type_, typename ...Types_>
	static auto _Format(wstring& stream, const wchar_t*& format, const Type_& type, const Types_& ...types) -> void {
		while (format[0] != L'\0') {
			while (format[0] != L'\0' && format[0] != L'{') {
				stream += format[0];
				format += 1;
			}
			if (format[0] == L'{') {
				format += 1;
				auto width_mini = 0;
				auto width_maxi = 0;
				while (format[0] == L' ') {
					format += 1;
				}
				while (L'0' <= format[0] && format[0] <= L'9') {
					width_mini = width_mini * 10 + (format[0] - L'0');
					format += 1;
				}
				if (format[0] == L':') {
					format += 1;
					while (L'0' <= format[0] && format[0] <= L'9') {
						width_maxi = width_maxi * 10 + (format[0] - L'0');
						format += 1;
					}
				}
				while (format[0] == L' ') {
					format += 1;
				}
				if (format[0] == L'}') {
					format += 1;
					_Print(stream, width_mini, width_maxi, type);
					_Format(stream, format, types...);
				}
				else {
					throw Exception(L"if (iter[0] == L'}') {");
				}
			}
		}
	}

	static auto _Print(wstring& stream, int width_mini, int base, const int& type) -> void {
		_Print(stream, width_mini, base, (long long)type);
	}
	static auto _Print(wstring& stream, int width_mini, int base, const long long& type) -> void {
		static auto chars = L"0123456789ABCDEF";
		(base == 2 || base == 10 || base == 16) ? base : (base = 10);
		auto posi = true;
		auto inte = (0 <= type) ? +type : (posi = false, -type);

		//////////////////////////////////////

		auto buffer = wstring{};
		buffer.reserve(32);
		do {
			buffer += chars[(inte % base)];
			inte /= base;
		} while (0 < inte);
		(posi == false) ? (buffer += L'-') : buffer;
		(width_mini < buffer.size()) ? (width_mini = (int)buffer.size()) : width_mini;
		stream.resize(stream.size() + width_mini);
		auto tail = &stream[(int)(stream.size() - 1)];
		auto r = 0;
		for (auto size = (int)buffer.size(); r < size; ) {
			tail[-r] = buffer[r];
			r += 1;
		}
		while (r < width_mini) {
			tail[-r] = L' ';
			r += 1;
		}
	}

	static auto _Print(wstring& stream, int width_mini, int width_prec, const float& type) -> void {
		_Print(stream, width_mini, width_prec, (double)type);
	}
	static auto _Print(wstring& stream, int width_mini, int width_prec, const double& type) -> void {
		static auto chars = L"0123456789ABCDEF";
		(2 <= width_prec) ? width_prec : (width_prec = 5);
		auto base = 10;
		auto width_inte = width_mini - width_prec;
		auto posi = true;
		auto numb = (0.0 <= type) ? +type : (posi = false, -type);
		auto inte = (int)numb;
		auto frac = numb - inte;

		//////////////////////////////////////

		auto buffer = wstring{};
		buffer.reserve(32);
		do {
			buffer += chars[(inte % base)];
			inte /= base;
		} while (0 < inte);
		(posi == false) ? (buffer += L'-') : buffer;
		(width_inte < (int)buffer.size()) ? (width_inte = (int)buffer.size()) : width_inte;
		stream.resize(stream.size() + width_inte);
		auto tail = &stream[(int)(stream.size()) - 1];
		auto r = 0;
		for (auto size = (int)buffer.size(); r < size; ) {
			tail[-r] = buffer[r];
			r += 1;
		}
		while (r < width_inte) {
			tail[-r] = L' ';
			r += 1;
		}

		//////////////////////////////////////

		stream.resize(stream.size() + width_prec);
		auto head = &stream[stream.size() - width_prec];
		head[0] = L'.';
		auto i = 1;
		while (i < width_prec) {
			frac *= base;
			head[i] = chars[(int)frac];
			i += 1, frac -= (int)frac;
		}
	}

	static auto _Print(wstring& stream, int width_mini, int width_maxi, const wstring& type) -> void {
		(1 <= width_mini) ? width_mini : (width_mini = 0);
		(width_mini <= width_maxi) ? width_maxi : (width_maxi = width_mini);

		//////////////////////////////////////

		auto width = (int)type.size();
		(width_mini <= 0 || width_mini <= width) ? width : (width = width_mini);
		(width_maxi <= 0 || width <= width_maxi) ? width : (width = width_maxi);
		stream.resize(stream.size() + width);
		auto iter = &stream[stream.size() - width];
		auto i = 0;
		for (auto size = type.size() < width ? type.size() : width; i < size; ) {
			iter[i] = type[i];
			i += 1;
		}
		while (i < width) {
			iter[i] = L' ';
			i += 1;
		}
	}
};

//int main(int argc, char* argv[]) {
//	Logger::_logger->_Debug(L"{}", 112345);
//	Logger::_logger->_Debug(L"{5:2}", 11.2345);
//	Logger::_logger->_Debug(L"{5:2}", L"11.2345");
//	return 0;
//}
