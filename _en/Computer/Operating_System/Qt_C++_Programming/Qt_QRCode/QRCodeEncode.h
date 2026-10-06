#pragma once

#include <QWidget>
#include <QDebug>
#include <QRegularExpression>
#include <QUrlQuery>
#include <QLabel>
#include <QObject>
#include <QLineEdit>
#include <QTextEdit>
#include "QZXingImageProvider.h"
#include "QZXing.h"

class QRCodeEncode: public QWidget {
    Q_OBJECT

    QTextEdit* _edit_encode = nullptr;
    QLabel*    _label       = nullptr;
    QTextEdit* _edit_decode = nullptr;

public:
    QRCodeEncode(QWidget* parent = nullptr)
        : QWidget(parent) {
        this->setFixedSize(1000, 500);
        _edit_encode = new QTextEdit(this);
        _edit_encode->setFixedSize(1000, 50);
        _edit_encode->move(0, 0);
        _label = new QLabel(this);
        _label->setFixedSize(400, 400);
        _label->move(0, 50);
        _label->setStyleSheet("background-color:yellow;");
        _edit_decode = new QTextEdit(this);
        _edit_decode->setReadOnly(true);
        _edit_decode->setFixedSize(1000, 50);
        _edit_decode->move(0, 450);

//        QImage result = _Encode("encode/Hello world!?correctionLevel=L&format=qrcode&border=false&transparent=false&explicitSize=auto", nullptr, QSize(200, 200));
//        _label->setPixmap(QPixmap::fromImage(result));
//        _Decoder(result);

        QObject::connect(_edit_encode, &QTextEdit::textChanged, this, [this]() {
            QImage image = _Encoder(_edit_encode->toPlainText());
            _label->setPixmap(QPixmap::fromImage(image));
            QString text = _Decoder(image);
            qDebug() << "decoder: " << text;
            _edit_decode->setText(text);
        });
    }

    QImage  _Encode(const QString &id, QSize* size = nullptr, const QSize &requestedSize = QSize(300, 300)) {
        int slashIndex = id.indexOf('/');
        if(slashIndex == -1) {
            qWarning() << "Can't parse url" << id << ". Usage is encode?<format>/<data>";
            return QImage();
        }

        // Detect operation (ex. encode)
        QString operationName = id.left(slashIndex);
        if(operationName != "encode") {
            qWarning() << "Operation not supported: " << operationName;
            return QImage();
        }

        QString data;
        QZXing::EncoderFormat format = QZXing::EncoderFormat_QR_CODE;
        QZXing::EncodeErrorCorrectionLevel correctionLevel = QZXing::EncodeErrorCorrectionLevel_L;
        bool border = false;
        bool transparent = false;
        QSize explicitSize = requestedSize;

        int customSettingsIndex = id.lastIndexOf(QRegularExpression("\\?(correctionLevel|format|border|transparent)="));
        if(customSettingsIndex >= 0) {
            int startOfDataIndex = slashIndex + 1;
            data = id.mid(startOfDataIndex, customSettingsIndex - (startOfDataIndex));

            // The dummy option has been added due to a bug(?) of QUrlQuery
            // it could not recognize the first key-value pair provided
            QUrlQuery optionQuery("options?dummy=&" + id.mid(customSettingsIndex + 1));

            if(optionQuery.hasQueryItem("format")) {
                QString formatString = optionQuery.queryItemValue("format");
                if(formatString != "qrcode") {
                    qWarning() << "Format not supported: " << formatString;
                    return QImage();
                }
            }

            QString correctionLevelString = optionQuery.queryItemValue("correctionLevel");
            if(correctionLevelString == "H") {
                correctionLevel = QZXing::EncodeErrorCorrectionLevel_H;
            } else if(correctionLevelString == "Q") {
                correctionLevel = QZXing::EncodeErrorCorrectionLevel_Q;
            } else if(correctionLevelString == "M") {
                correctionLevel = QZXing::EncodeErrorCorrectionLevel_M;
            } else if(correctionLevelString == "L") {
                correctionLevel = QZXing::EncodeErrorCorrectionLevel_L;
            }

            if(optionQuery.hasQueryItem("border")) {
                border = optionQuery.queryItemValue(("border")) == "true";
            }

            if(optionQuery.hasQueryItem("transparent")) {
                transparent = optionQuery.queryItemValue("transparent") == "true";
            }

            if(optionQuery.hasQueryItem("explicitSize")) {
                QString explicitSizeStr = optionQuery.queryItemValue("explicitSize");
                bool ok;
                int size = explicitSizeStr.toInt(&ok);
                if(ok) {
                    explicitSize = QSize(size, size);
                }
            }
        } else {
            data = id.mid(slashIndex + 1);
        }

#ifdef ENABLE_ENCODER_GENERIC
        QZXingEncoderConfig encoderConfig(format, explicitSize, correctionLevel, border, transparent);
        QString dataTemp(QUrl::fromPercentEncoding(data.toUtf8()));
        QImage result = QZXing::encodeData(dataTemp, encoderConfig);
#else
        QImage result;
        qDebug() << "barcode encoder disabled. Add 'CONFIG += enable_encoder_qr_code'";
#endif
        if(size != nullptr) {
            *size = result.size();
        }
        return result;
    }

    QImage  _Encoder(const QString& text) {
        QImage image = QZXing::encodeData(text, QZXing::EncoderFormat_QR_CODE);
        return image;
    }

    QString _Decoder(const QImage& image) {
        if(image.isNull()) {
            return QString();
        }
        QZXing decoder;
        decoder.setDecoder(QZXing::DecoderFormat_QR_CODE | QZXing::DecoderFormat_EAN_13);
        decoder.setSourceFilterType(QZXing::SourceFilter_ImageNormal);
        decoder.setTryHarderBehaviour(QZXing::TryHarderBehaviour_ThoroughScanning | QZXing::TryHarderBehaviour_Rotate);
        QString text = decoder.decodeImage(image);
        return text;
    }
};
