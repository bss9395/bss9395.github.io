#pragma once

#include <QDebug>
#include <QEvent>
#include <QFontMetrics>
#include <QLabel>
#include <QList>
#include <QResizeEvent>
#include <QStyle>
#include <QVector>
#include <QWidget>
#include <array>

class VWidget: public QWidget{
    Q_OBJECT

signals:
    void signalRelayout();

public:
    explicit VWidget(QWidget* parent = nullptr)
        : QWidget(parent) {
        QWidget::setAttribute(Qt::WA_StyledBackground, true);    // 启用O_OBJECT宏，需要设置Qt::WA_StyledBackground，否则背景样式不生效

    }

    virtual ~VWidget() {

    }

public:
    static const int _esaturate_none = 0b0000;
    static const int _esaturate_line = 0b0001;
    static const int _esaturate_box  = 0b0010;
    void setSaturateH(int saturateH) {
        _saturateH = saturateH;
    }
    int getSaturateH() {
        return _saturateH;
    }

    void setAlignments(std::array<int, 2> alignments) {
        _alignMain  = alignments[0];
        _alignMinor = alignments[1];
    }

    std::array<int, 2> getAlignments() {
        return std::array<int, 2> {
            _alignMain, _alignMinor
        };
    }

    void setMargins(std::array<int, 4> margins) {
        _marginL = margins[0];
        _marginT = margins[1];
        _marginR = margins[2];
        _marginB = margins[3];
    }
    std::array<int, 4> getMargins() {
        return std::array<int, 4> {
            _marginL, _marginT, _marginR, _marginB
        };
    }

    void setSpacingV(int spacingV) {
        _spacingV = spacingV;
    }
    int getSpacingV() {
        return _spacingV;
    }

    QSize sizeHint() const override {
        qDebug().nospace() << __FUNCTION__;
        int width = _marginL + _metricWidth + _marginR;
        int height = _marginT + _metricHeight + _marginB;
        if(width <= 0) {
            width = 1;
        }
        if(height <= 0) {
            height = 1;
        }
        return QSize(width, height);
    }

public:
    void addWidget(QWidget* widget, double stretchV) {
        qDebug().nospace() << __FUNCTION__ << ", stretchV = " << stretchV;
        if(stretchV <= 0.0 || qFuzzyIsNull(stretchV) == true) {
            stretchV = 0.0;
        }

        for(auto iter = _items.begin(); iter != _items.end(); ) {
            if(iter->_widget == widget) {
                iter = _items.erase(iter);
                break;
            }
            ++iter;
        }
        widget->setParent(this);
        _items.push_back(Item(widget, stretchV));
    }

    void setStretchV(QWidget* widget, double stretchV) {
        qDebug().nospace() << __FUNCTION__ << ", stretchV = " << stretchV;
        if(stretchV <= 0.0 || qFuzzyIsNull(stretchV) == true) {
            stretchV = 0.0;
        }

        for(int col = 0; col < _items.size(); col += 1) {
            if(_items[col]._widget == widget) {
                _items[col]._stretchV = stretchV;
            }
        }
    }

private:
    QSize _lastSize;
    void resizeEvent(QResizeEvent* event) override {
        if(_lastSize == event->size()) {
            return;
        }
        _lastSize = event->size();
        qDebug().nospace() << __FUNCTION__ << ", event = " << event << ", size() = " << event->size() << ", oldSize() = " << event->oldSize();
        doLayout();
    }

    void doBalance() {
        // qDebug().nospace() << __FUNCTION__;
        // 计算_metricWidth
        _metricWidth = 0;
        for(int col = 0; col < _items.size(); col += 1) {
            Item* item = &_items[col];
            QSize sizeHint = item->_widget->sizeHint();
            if(item->_widget->property("_sizeHint").isValid() == true) {
                sizeHint = item->_widget->property("_sizeHint").toSize();
            }
            item->_hintWidth = sizeHint.width();
            if((item->_widget->minimumWidth() <= item->_hintWidth) == false) {
                item->_hintWidth = item->_widget->minimumWidth();
            }
            if((item->_hintWidth <= item->_widget->maximumWidth()) == false) {
                item->_hintWidth = item->_widget->maximumWidth();
            }
            if(_metricWidth < item->_hintWidth) {
                _metricWidth = item->_hintWidth;
            }

            item->_hintHeight = sizeHint.height();
            if((item->_widget->minimumHeight() <= item->_hintHeight) == false) {
                item->_hintHeight = item->_widget->minimumHeight();
            }
            if((item->_hintHeight <= item->_widget->maximumHeight()) == false) {
                item->_hintHeight = item->_widget->maximumHeight();
            }
        }

        // 计算fixedHeight与计算denominator
        qDebug().nospace() << "this->width() = " << this->width() << ", _marginL = " << _marginL << ", _marginR = " << _marginR;
        int boxWidth = this->width() - _marginL - _marginR;
        int fixedHeight = _marginT + _marginB;
        double denominator = 0.0;
        for(int col = 0; col < _items.size(); col += 1) {
            Item* item = &_items[col];
            if(item->_widget->inherits("QLabel") == true && item->_widget->hasHeightForWidth() == true) {
                int width = item->_hintWidth;
                if(_saturateH == _esaturate_line) {
                    width = _metricWidth;
                } else if(_saturateH == _esaturate_box) {
                    width = boxWidth;
                }
                if((item->_widget->minimumWidth() <= width) == false) {
                    width = item->_widget->minimumWidth();
                }
                if((width <= item->_widget->maximumWidth()) == false) {
                    width = item->_widget->maximumWidth();
                }
                item->_hintHeight = item->_widget->heightForWidth(width);

                // 移除QLabel多行文本的尾空白
                if(item->_widget->property("_lineHeightRatio").isValid() == true) {
                    bool ok = false;
                    double lineHeightRatio = item->_widget->property("_lineHeightRatio").toDouble(&ok);
                    if (ok == true && 1.0 < lineHeightRatio) {
                        item->_widget->style()->unpolish(item->_widget);
                        item->_widget->style()->polish(item->_widget);
                        QFontMetrics fontMetrics = item->_widget->fontMetrics();
                        int lineSpace = fontMetrics.height() * (lineHeightRatio - 1.0);
                        item->_hintHeight -= lineSpace;
                    }
                }

                if((item->_widget->minimumHeight() <= item->_hintHeight) == false) {
                    item->_hintHeight = item->_widget->minimumHeight();
                }
                if((item->_hintHeight <= item->_widget->maximumHeight()) == false) {
                    item->_hintHeight = item->_widget->maximumHeight();
                }
            }

            fixedHeight += (col == 0) ? 0 : _spacingV;
            if(item->_stretchV == 0.0 || item->_hintHeight == 0) {
                fixedHeight += item->_hintHeight;
            } else {
                denominator += item->_stretchV * item->_hintHeight;
            }
        }

        // 计算item->_metricHeight和执行item->_widget->resize()
        // 更新_metricWidth和计算_metricHeight
        _metricHeight = 0;
        int varyHeight = this->height() - fixedHeight;    // varyHeight有可能为负值
        for(int col = 0; col < _items.size(); col += 1) {
            Item* item = &_items[col];
            if(item->_stretchV == 0.0 || item->_hintHeight == 0) {
                item->_metricHeight = item->_hintHeight;
            } else {
                item->_metricHeight = varyHeight * (item->_stretchV * item->_hintHeight) / denominator;    // denominator有可能为零值
            }
            _metricHeight += (col == 0) ? item->_metricHeight : (_spacingV + item->_metricHeight);

            if(_saturateH == _esaturate_none) {
                item->_widget->resize(item->_hintWidth, item->_metricHeight);    // resize()有可能为minimumSize()或者maximumSize()
            } else if(_saturateH == _esaturate_line) {
                item->_widget->resize(_metricWidth, item->_metricHeight);        // resize()有可能为minimumSize()或者maximumSize()
            } else if(_saturateH == _esaturate_box) {
                item->_widget->resize(boxWidth, item->_metricHeight);            // resize()有可能为minimumSize()或者maximumSize()
                if(col == 0) {
                    _metricWidth = 0;
                }
                if(_metricWidth < item->_widget->width()) {
                    _metricWidth = item->_widget->width();
                }
            }
        }
    }

public:
    void doLayout() {
        qDebug().nospace() << __FUNCTION__;
        doBalance();

        // 测试用，无实际作用
        bool fit = false;
        if(fit == true) {
            int fitWidth = _marginL + _metricWidth + _marginR;
            int fitHeight = _marginT + _metricHeight + _marginB;
            this->resize(fitWidth, fitHeight);    // this->resize()不触发ResizeEvent()
        }

        ////////////////////////////////

        int boxWidth = this->width() - _marginL - _marginR;
        int lastL = 0;
        if(_alignMain & Qt::AlignLeft) {
            lastL = _marginL;
        } else if(_alignMain & Qt::AlignHCenter) {
            lastL = _marginL + (boxWidth - _metricWidth) / 2;
        } else if(_alignMain & Qt::AlignRight) {
            lastL = _marginL + boxWidth - _metricWidth;
        }
        int boxHeight = this->height() - _marginT - _marginB;
        int lastT = 0;
        if(_alignMain & Qt::AlignTop) {
            lastT = _marginT;
        } else if(_alignMain & Qt::AlignVCenter) {
            lastT = _marginT + (boxHeight - _metricHeight) / 2;
        } else if(_alignMain & Qt::AlignBottom) {
            lastT = _marginT + boxHeight - _metricHeight;
        }
        for(int col = 0; col < _items.size(); col += 1) {
            Item* item = &_items[col];
            int offsetL = 0;
            if(_alignMinor & Qt::AlignLeft) {
                offsetL = 0;
            } else if(_alignMinor & Qt::AlignHCenter) {
                offsetL = 0 + (_metricWidth - item->_widget->width()) / 2;
            } else if(_alignMinor & Qt::AlignRight) {
                offsetL = 0 + _metricWidth - item->_widget->width();
            }
            int offsetT = 0;
            if(_alignMinor & Qt::AlignTop) {
                offsetT = 0;
            } else if(_alignMinor & Qt::AlignVCenter) {
                offsetT = 0 + (item->_metricHeight - item->_widget->height()) / 2;
            } else if(_alignMinor & Qt::AlignBottom) {
                offsetT = 0 + item->_metricHeight - item->_widget->height();
            }
            item->_widget->move(lastL + offsetL, lastT + offsetT);
            lastT += item->_metricHeight + _spacingV;
        }

        ////////////////////////////////

        QSize fitSizeHint = sizeHint();    // sizeHint()有修正
        bool relayout = (_lastSizeHint != fitSizeHint);
        _lastSizeHint = fitSizeHint;
        if (relayout == true) {
            emit this->signalRelayout();
        }
    }

private:
    int _saturateH = _esaturate_line;
    int _alignMain  = Qt::AlignHCenter | Qt::AlignVCenter;
    int _alignMinor = Qt::AlignHCenter | Qt::AlignVCenter;
    int _marginL = 0;
    int _marginT = 0;
    int _marginR = 0;
    int _marginB = 0;
    int _spacingV = 0;

    struct Item {
        QWidget* _widget = nullptr;
        double _stretchV = 0.0;
        int _hintWidth = 0;
        int _hintHeight = 0;
        int _metricHeight = 0;

        Item() {

        }
        Item(QWidget* widget, double stretchV) {
            _widget = widget;
            _stretchV = stretchV;
        }
    };
    QVector<Item> _items;
    int _metricWidth = 0;
    int _metricHeight = 0;
    QSize _lastSizeHint;
};
