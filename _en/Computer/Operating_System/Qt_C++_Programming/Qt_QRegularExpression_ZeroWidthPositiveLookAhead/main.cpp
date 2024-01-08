
#include <QApplication>
#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>


void _PartialPreferCompleteMatch() {
    qDebug().noquote() << __FUNCTION__;

    QRegularExpression expression1(R"!(^(Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec) [0-9]{1,2}, [0-9]{4,4})!", QRegularExpression::DotMatchesEverythingOption);
    QRegularExpressionMatch match1 = expression1.match("Jan 21,", 0, QRegularExpression::PartialPreferCompleteMatch);
    qDebug().noquote() << "match1.hasMatch()        = " << match1.hasMatch();
    qDebug().noquote() << "match1.hasPartialMatch() = " << match1.hasPartialMatch();


    QRegularExpression expression2(R"!(^(Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec) [0-9]{1,2}, [0-9]{4,4})!", QRegularExpression::DotMatchesEverythingOption);
    QRegularExpressionMatch match2 = expression2.match("Dec 8, 1985", 0, QRegularExpression::PartialPreferCompleteMatch);
    qDebug().noquote() << "match2.hasMatch()        = " << match2.hasMatch();
    qDebug().noquote() << "match2.hasPartialMatch() = " << match2.hasPartialMatch();


    QRegularExpression expression3(R"!(abc\w{1,}X|def)!", QRegularExpression::DotMatchesEverythingOption);
    QRegularExpressionMatch match3 = expression3.match("abcdef", 0, QRegularExpression::PartialPreferCompleteMatch);
    qDebug().noquote() << "match3.hasMatch()        = " << match3.hasMatch();
    qDebug().noquote() << "match3.hasPartialMatch() = " << match3.hasPartialMatch();
    qDebug().noquote() << "match3.captured(0)       = " << match3.captured(0);
}


void _PartialPreferFirstMatch() {
    qDebug().noquote() << __FUNCTION__;

    QRegularExpression expression1 = QRegularExpression(R"!(abc|ab)!", QRegularExpression::DotMatchesEverythingOption);
    QRegularExpressionMatch match1 = expression1.match("ab", 0, QRegularExpression::PartialPreferFirstMatch);
    qDebug().noquote() << "match1.hasMatch()        = " << match1.hasMatch();
    qDebug().noquote() << "match1.hasPartialMatch() = " << match1.hasPartialMatch();


    QRegularExpression expression2 = QRegularExpression(R"!(abc(def))!", QRegularExpression::DotMatchesEverythingOption);
    QRegularExpressionMatch match2 = expression2.match("abc", 0, QRegularExpression::PartialPreferFirstMatch);
    qDebug().noquote() << "match2.hasMatch()        = " << match2.hasMatch();
    qDebug().noquote() << "match2.hasPartialMatch() = " << match2.hasPartialMatch();


    QRegularExpression expression3 = QRegularExpression(R"!((abc)*)!", QRegularExpression::DotMatchesEverythingOption);
    QRegularExpressionMatch match3 = expression3.match("abc", 0, QRegularExpression::PartialPreferFirstMatch);
    qDebug().noquote() << "match3.hasMatch()        = " << match3.hasMatch();
    qDebug().noquote() << "match3.hasPartialMatch() = " << match3.hasPartialMatch();
}


void _ZeroWidthPositiveLookAhead() {
    qDebug().noquote() << __FUNCTION__;

    QRegularExpression expression = QRegularExpression(R"!([0-9]{1,}(?=px))!");
    QRegularExpressionMatchIterator iter = expression.globalMatch("px1 pt 2px 3em 4px");
    QStringList words;
    while(iter.hasNext()) {
        QRegularExpressionMatch match = iter.next();
        qDebug().noquote() << "match.captured(0) = " << match.captured(0);
    }
}

void _ZeroWidthPositiveLookBehind() {
    qDebug().noquote() << __FUNCTION__;

    QRegularExpression expression = QRegularExpression(R"!((?<=px)[0-9]{1,})!");
    QRegularExpressionMatchIterator iter = expression.globalMatch("px1 pt 2px 3em 4px");
    QStringList words;
    while(iter.hasNext()) {
        QRegularExpressionMatch match = iter.next();
        qDebug().noquote() << "match.captured(0) = " << match.captured(0);
    }
}


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // _PartialPreferCompleteMatch();
    // _PartialPreferFirstMatch();
    _ZeroWidthPositiveLookAhead();
    _ZeroWidthPositiveLookBehind();

    return a.exec();
}
