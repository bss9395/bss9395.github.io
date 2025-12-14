
#include <QApplication>
#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

/*
enum PatternOption {
    NoPatternOption                = 0x0000,
    CaseInsensitiveOption          = 0x0001,
    DotMatchesEverythingOption     = 0x0002,
    MultilineOption                = 0x0004,
    ExtendedPatternSyntaxOption    = 0x0008,
    InvertedGreedinessOption       = 0x0010,
    DontCaptureOption              = 0x0020,
    UseUnicodePropertiesOption     = 0x0040,
    // Formerly (no-ops deprecated in 5.12, removed 6.0):
    // OptimizeOnFirstUsageOption = 0x0080,
    // DontAutomaticallyOptimizeOption = 0x0100,
};
QRegularExpression::PatternOption::NoPatternOption
未设置模式选项。

QRegularExpression::PatternOption::CaseInsensitiveOption
模式应以不区分大小写的方式与主题字符串匹配。该选项与 Perl 正则表达式中的 /i 修饰符相对应。

QRegularExpression::PatternOption::DotMatchesEverythingOption
模式字符串中的点元字符 (.) 允许匹配主题字符串中的任何字符，包括换行符（通常点不匹配换行符）。该选项相当于 Perl 正则表达式中的/s 修饰符。

QRegularExpression::PatternOption::MultilineOption
模式字符串中的圆括号 (^) 和元字符 ($) 允许分别匹配主题字符串中紧接换行符之后和之前的字符，以及主题字符串的开头和结尾。该选项与 Perl 正则表达式中的/m 修饰符相对应。

QRegularExpression::PatternOption::ExtendedPatternSyntaxOption
模式字符串中任何未转义且在字符类之外的空白都会被忽略。此外，字符类外未转义的尖括号（#）会导致忽略后面的所有字符，直到第一个换行符（包含）。这可以用来增加模式字符串的可读性，以及在正则表达式中添加注释；如果模式字符串是从文件中加载或由用户编写的，这一点尤其有用，因为在 C++ 代码中，总是可以使用字符串文字的规则在模式字符串外添加注释。该选项与 Perl 正则表达式中的/x 修饰符相对应。

QRegularExpression::PatternOption::InvertedGreedinessOption
量词的贪婪性是倒置的：*,+,?,{m,n} 等变为 "懒惰"，而它们的 "懒惰 "版本（*?,+?,??,{m,n}? 等）变为 "贪婪"。该选项在 Perl 正则表达式中没有对应的选项。

QRegularExpression::PatternOption::DontCaptureOption
非命名捕获组不捕获子字符串；命名捕获组仍按原意工作，隐式捕获组编号 0 与整个匹配对应。该选项在 Perl 正则表达式中没有对应的选项。

QRegularExpression::PatternOption::UseUnicodePropertiesOption
\w 、\d 等字符类的含义及其对应字符类（\W 、\D 等）的含义从仅匹配 ASCII 字符改为匹配具有相应 Unicode 属性的任何字符。例如，\d 改为匹配任何具有 Unicode Nd（十进制数字）属性的字符；\w 改为匹配任何具有 Unicode L（字母）或 N（数字）属性以及下划线的字符，依此类推。该选项与 Perl 正则表达式中的/u 修饰符相对应。


enum MatchType {
    NormalMatch = 0,
    PartialPreferCompleteMatch,
    PartialPreferFirstMatch,
    NoMatch
};
QRegularExpression::MatchType::NormalMatch
正常匹配。

QRegularExpression::MatchType::PartialPreferCompleteMatch
模式字符串与主题字符串进行部分匹配。如果发现了部分匹配，则将其记录下来，并像往常一样尝试其他匹配选项。如果找到完全匹配，则优先于部分匹配；在这种情况下，只报告完全匹配。如果没有找到完全匹配（只有部分匹配），则报告部分匹配。

QRegularExpression::MatchType::PartialPreferFirstMatch
模式字符串与主题字符串部分匹配。如果找到部分匹配，则停止匹配并报告部分匹配。在这种情况下，不会尝试其他匹配选项（可能导致完全匹配）。此外，这种匹配类型假定主题字符串只是更大文本的一个子串，而且（在该文本中）主题字符串末尾之外还有其他字符。这可能会导致令人惊讶的结果；

QRegularExpression::MatchType::NoMatch
不进行匹配。默认构造QRegularExpressionMatch 或QRegularExpressionMatchIterator 将此值作为匹配类型返回。使用这种匹配类型对用户来说用处不大，因为根本不会发生匹配。


enum MatchOption {
    NoMatchOption              = 0x0000,
    AnchorAtOffsetMatchOption  = 0x0001,
    AnchoredMatchOption Q_DECL_ENUMERATOR_DEPRECATED_X(
        "Use AnchorAtOffsetMatchOption instead") = AnchorAtOffsetMatchOption, // Rename@Qt6.0
    DontCheckSubjectStringMatchOption = 0x0002
};
QRegularExpression::MatchOption::NoMatchOption
未设置匹配选项。

QRegularExpression::MatchOption::AnchoredMatchOption
请使用 AnchorAtOffsetMatchOption。

QRegularExpression::MatchOption::AnchorAtOffsetMatchOption
为了使匹配成功，即使模式字符串不包含任何在该点锚定匹配的元字符，匹配也必须精确地从传递给match() 的偏移开始。需要注意的是，通过该选项并不能将匹配的终点锚定到主题的终点；如果要完全锚定正则表达式，请使用anchoredPattern() 。

QRegularExpression::MatchOption::DontCheckSubjectStringMatchOption
在尝试匹配之前，不会检查主题字符串的 UTF-16 有效性。请谨慎使用此选项，因为尝试匹配无效字符串可能会导致程序崩溃和/或构成安全问题。
*/

void _PartialPreferCompleteMatch() {
    qDebug().nospace().noquote() << __FUNCTION__;
    QRegularExpression expression1(R"!(^(Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec) [0-9]{1,2}, [0-9]{4,4})!", QRegularExpression::DotMatchesEverythingOption);
    QRegularExpressionMatch match1 = expression1.match("Jan 21,", 0, QRegularExpression::PartialPreferCompleteMatch);
    qDebug().noquote() << "match1.hasMatch()        = " << match1.hasMatch();
    qDebug().noquote() << "match1.hasPartialMatch() = " << match1.hasPartialMatch();
    qDebug().noquote() << "match1.captured(0)       = " << match1.captured(0);

    QRegularExpression expression2(R"!(^(Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec) [0-9]{1,2}, [0-9]{4,4})!", QRegularExpression::DotMatchesEverythingOption);
    QRegularExpressionMatch match2 = expression2.match("Dec 8, 1985", 0, QRegularExpression::PartialPreferCompleteMatch);
    qDebug().noquote() << "match2.hasMatch()        = " << match2.hasMatch();
    qDebug().noquote() << "match2.hasPartialMatch() = " << match2.hasPartialMatch();
    qDebug().noquote() << "match2.captured(0)       = " << match2.captured(0);

    QRegularExpression expression3(R"!(abc\w{1,}X|def)!", QRegularExpression::DotMatchesEverythingOption);
    QRegularExpressionMatch match3 = expression3.match("abcdef", 0, QRegularExpression::PartialPreferCompleteMatch);
    qDebug().noquote() << "match3.hasMatch()        = " << match3.hasMatch();
    qDebug().noquote() << "match3.hasPartialMatch() = " << match3.hasPartialMatch();
    qDebug().noquote() << "match3.captured(0)       = " << match3.captured(0);
}


void _PartialPreferFirstMatch() {
    qDebug().nospace().noquote() << __FUNCTION__;
    QRegularExpression expression1 = QRegularExpression(R"!(abc|ab)!", QRegularExpression::DotMatchesEverythingOption);
    QRegularExpressionMatch match1 = expression1.match("ab", 0, QRegularExpression::PartialPreferFirstMatch);
    qDebug().noquote() << "match1.hasMatch()        = " << match1.hasMatch();
    qDebug().noquote() << "match1.hasPartialMatch() = " << match1.hasPartialMatch();
    qDebug().noquote() << "match1.captured(0)       = " << match1.captured(0);

    QRegularExpression expression2 = QRegularExpression(R"!(abc(def))!", QRegularExpression::DotMatchesEverythingOption);
    QRegularExpressionMatch match2 = expression2.match("abc", 0, QRegularExpression::PartialPreferFirstMatch);
    qDebug().noquote() << "match2.hasMatch()        = " << match2.hasMatch();
    qDebug().noquote() << "match2.hasPartialMatch() = " << match2.hasPartialMatch();
    qDebug().noquote() << "match2.captured(0)       = " << match2.captured(0);

    QRegularExpression expression3 = QRegularExpression(R"!((abc)*)!", QRegularExpression::DotMatchesEverythingOption);
    QRegularExpressionMatch match3 = expression3.match("abc", 0, QRegularExpression::PartialPreferFirstMatch);
    qDebug().noquote() << "match3.hasMatch()        = " << match3.hasMatch();
    qDebug().noquote() << "match3.hasPartialMatch() = " << match3.hasPartialMatch();
    qDebug().noquote() << "match3.captured(0)       = " << match3.captured(0);
}


void _ZeroWidthPositiveLookAhead() {
    qDebug().nospace().noquote() << __FUNCTION__;
    QRegularExpression expression = QRegularExpression(R"!([0-9]{1,}(?=px))!");
    QRegularExpressionMatchIterator iter = expression.globalMatch("px1 pt 2px 3em 4px");
    while(iter.hasNext()) {
        QRegularExpressionMatch match = iter.next();
        qDebug().noquote() << "match.hasMatch()        = " << match.hasMatch();
        qDebug().noquote() << "match.hasPartialMatch() = " << match.hasPartialMatch();
        qDebug().noquote() << "match.captured(0)       = " << match.captured(0);
    }
}

void _ZeroWidthPositiveLookBehind() {
    qDebug().nospace().noquote() << __FUNCTION__;
    QRegularExpression expression = QRegularExpression(R"!((?<=px)[0-9]{1,})!");
    QRegularExpressionMatchIterator iter = expression.globalMatch("px1 pt 2px 3em 4px");
    while(iter.hasNext()) {
        QRegularExpressionMatch match = iter.next();
        qDebug().noquote() << "match.hasMatch()        = " << match.hasMatch();
        qDebug().noquote() << "match.hasPartialMatch() = " << match.hasPartialMatch();
        qDebug().noquote() << "match.captured(0)       = " << match.captured(0);
    }
}

void _Match_Lazy() {
    qDebug().nospace().noquote() << __FUNCTION__;
    QString text = "<div>第一段</div><div>第二段</div>";
    QRegularExpression lazy("<div>.*?</div>");
    QRegularExpressionMatch match = lazy.match(text);
    qDebug().noquote() << "match.hasMatch()        = " << match.hasMatch();
    qDebug().noquote() << "match.hasPartialMatch() = " << match.hasPartialMatch();
    qDebug().noquote() << "match.captured(0)       = " << match.captured(0);
}

void _Match_Greedy() {
    qDebug().nospace().noquote() << __FUNCTION__;
    QString text = "<div>第一段</div><div>第二段</div>";
    QRegularExpression greedy("<div>.*</div>");
    QRegularExpressionMatch match = greedy.match(text);
    qDebug().noquote() << "match.hasMatch()        = " << match.hasMatch();
    qDebug().noquote() << "match.hasPartialMatch() = " << match.hasPartialMatch();
    qDebug().noquote() << "match.captured(0)       = " << match.captured(0);
}

void _Match_Insensitive() {
    qDebug().nospace().noquote() << __FUNCTION__;
    QString text = "aBCdEfgH";
    QRegularExpression sensitive("([^abCD]|e){1,}", QRegularExpression::CaseInsensitiveOption);
    QRegularExpression insensitive("((?i)[^abCD](?-i)|e){1,}", QRegularExpression::CaseInsensitiveOption);
    qDebug().nospace().noquote() << "sensitive.isValid() = " << sensitive.isValid();
    qDebug().nospace().noquote() << "insensitive.isValid() = " << insensitive.isValid();
    QRegularExpressionMatch match_sensitive = sensitive.match(text);
    qDebug().noquote() << "match_sensitive.hasMatch()        = " << match_sensitive.hasMatch();
    qDebug().noquote() << "match_sensitive.hasPartialMatch() = " << match_sensitive.hasPartialMatch();
    qDebug().noquote() << "match_sensitive.captured(0)       = " << match_sensitive.captured(0);
    QRegularExpressionMatch match_insensitive = insensitive.match(text);
    qDebug().noquote() << "match_insensitive.hasMatch()        = " << match_insensitive.hasMatch();
    qDebug().noquote() << "match_insensitive.hasPartialMatch() = " << match_insensitive.hasPartialMatch();
    qDebug().noquote() << "match_insensitive.captured(0)       = " << match_insensitive.captured(0);
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // _PartialPreferCompleteMatch();
    // _PartialPreferFirstMatch();
    // _ZeroWidthPositiveLookAhead();
    // _ZeroWidthPositiveLookBehind();

    // _Match_Lazy();
    // _Match_Greedy();
    _Match_Insensitive();

    return a.exec();
}
