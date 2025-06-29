#include <QDebug>
#include <QString>
#include <QVector>
#include <QVariant>
#include <QRegularExpression>

QString _Named_Fomat(const QString& format, const QVector<QPair<QString, QVariant>>& values) {
    QString result = format;
    for (int i = 0; i < values.size(); i += 1) {
        QRegularExpression expression = QRegularExpression("[{]{1,1}[ ]{0,}" + values[i].first + "[ ]{0,}[}]{1,1}", QRegularExpression::DotMatchesEverythingOption);
        result.replace(expression, values[i].second.toString());
    }
    return result;
}

void _Test_Named_Fomat() {
    QString message = _Named_Fomat("{name}: \n\tHello, { name }! You are {age} years old.", {
        {"name", "Alice"},
        {"age", 25}
    });
    qDebug().noquote().nospace() << message;
}

int main() {
    _Test_Named_Fomat();
}
