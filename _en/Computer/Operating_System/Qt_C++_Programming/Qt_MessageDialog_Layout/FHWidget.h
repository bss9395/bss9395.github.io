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

class FHWidget: public QWidget {
    Q_OBJECT

signals:
    void signalRelayout();

public:
    explicit FHWidget(QWidget* parent = nullptr)
        : QWidget(parent) {
        QWidget::setAttribute(Qt::WA_StyledBackground, true);    // 启用O_OBJECT宏，需要设置Qt::WA_StyledBackground，否则背景样式不生效

    }

    virtual ~FHWidget() {

    }

public:
    void setWrap(bool wrap) {
        _wrap = wrap;
    }
    bool getWrap() {
        return _wrap;
    }

    static const int _esaturate_none = 0b0000;
    static const int _esaturate_line = 0b0001;
    static const int _esaturate_box  = 0b0010;
    void setSaturateV(int saturateV) {
        _saturateV = saturateV;
    }
    int getSaturateV() {
        return _saturateV;
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

    void setSpacings(std::array<int, 2> spacings) {
        _spacingH = spacings[0];
        _spacingV = spacings[1];
    }
    std::array<int, 2> getSpacings() {
        return std::array<int, 2> {
            _spacingH, _spacingV
        };
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

    QSize sizeHint() const override {
        qDebug().nospace() << __FUNCTION__;
        int width = _marginL + _metricWidth + _marginR;
        int height = _marginT + _metricHeight + _marginB;
        if(width <= 1) {
            width = 1;
        }
        if(height <= 1) {
            height = 1;
        }
        return QSize(width, height);
    }

public:
    void addWidget(QWidget* widget, double stretchH) {
        qDebug().nospace() << __FUNCTION__ << ", stretchH = " << stretchH;
        if(stretchH <= 0.0 || qFuzzyIsNull(stretchH) == true) {
            stretchH = 0.0;
        }

        for(auto iter = _items.begin(); iter != _items.end(); ) {
            if(iter->_widget == widget) {
                iter = _items.erase(iter);
                break;
            }
            ++iter;
        }
        widget->setParent(this);
        _items.push_back(Item(widget, stretchH));
    }

    void setStretchV(QWidget* widget, double stretchH) {
        qDebug().nospace() << __FUNCTION__ << ", stretchH = " << stretchH;
        if(stretchH <= 0.0 || qFuzzyIsNull(stretchH) == true) {
            stretchH = 0.0;
        }

        for(int col = 0; col < _items.size(); col += 1) {
            if(_items[col]._widget == widget) {
                _items[col]._stretchH = stretchH;
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

    void doWrap() {
        // qDebug().nospace() << __FUNCTION__;
        _lines.resize(0);
        int boxWidth = this->width() - _marginL - _marginR;
        Line* line = nullptr;
        int lastWidth = 0;
        for(int idx = 0; idx < _items.size(); idx += 1) {
            Item* item = &_items[idx];
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

            item->_hintHeight = sizeHint.height();
            if((item->_widget->minimumHeight() <= item->_hintHeight) == false) {
                item->_hintHeight = item->_widget->minimumHeight();
            }
            if((item->_hintHeight <= item->_widget->maximumHeight()) == false) {
                item->_hintHeight = item->_widget->maximumHeight();
            }

            if(_lines.empty() == true || (_wrap == true && (lastWidth + item->_hintWidth < boxWidth) == false)) {
                _lines.resize(_lines.size() + 1);
                line = &_lines[_lines.size() - 1];
                lastWidth = 0;
            }
            line->_items.push_back(*item);
            lastWidth += item->_hintWidth + _spacingH;
        }
    }

    void doBalance() {
        qDebug().nospace() << __FUNCTION__;
        doWrap();

        // 计算_metricWidth和计算_metricHeight
        _metricWidth  = 0;
        _metricHeight = 0;
        for(int row = 0; row < _lines.size(); row += 1) {
            Line* line = &_lines[row];
            // 计算line->fixedWidth和line->denominator
            int fixedWidth = _marginL + _marginR;
            double denominator = 0.0;
            for(int col = 0; col < line->_items.size(); col += 1) {
                Item* item = &(line->_items[col]);
                fixedWidth += (col == 0) ? 0 : _spacingH;
                if(item->_stretchH == 0.0 || item->_hintWidth == 0) {
                    fixedWidth  += item->_hintWidth;
                } else {
                    denominator += item->_stretchH * item->_hintWidth;
                }
            }

            // 计算item->_metricWidth
            // 计算line->_metricWidth和计算line->_metricHeight
            line->_metricWidth = 0;
            int varyWidth = this->width() - fixedWidth;    // varyWidth有可能为负值
            for(int col = 0; col < line->_items.size(); col += 1) {
                Item* item = &(line->_items[col]);
                if(item->_stretchH == 0.0 || item->_hintWidth == 0) {
                    item->_metricWidth = item->_hintWidth;
                } else {
                    item->_metricWidth = varyWidth * (item->_stretchH * item->_hintWidth) / denominator;    // denominator有可能为零值
                }
                line->_metricWidth += (col == 0) ? item->_metricWidth : (_spacingH + item->_metricWidth);

                if(item->_widget->inherits("QLabel") == true && item->_widget->hasHeightForWidth() == true) {
                    int width = item->_metricWidth;
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
                if(line->_metricHeight < item->_hintHeight) {
                    line->_metricHeight = item->_hintHeight;
                }
            }
            if(_metricWidth < line->_metricWidth) {
                _metricWidth = line->_metricWidth;
            }
            _metricHeight += (row == 0) ? line->_metricHeight : (_spacingV + line->_metricHeight);

            // 执行item->resize()和更新_metricHeight
            int boxHeight = this->height() - _marginT - _marginB;
            for(int col = 0; col < line->_items.size(); col += 1) {
                Item* item = &(line->_items[col]);
                if(_saturateV == _esaturate_none) {
                    item->_widget->resize(item->_metricWidth, item->_hintHeight);      // resize()有可能为minimumSize()或者maximumSize()
                } else if(_saturateV == _esaturate_line) {
                    item->_widget->resize(item->_metricWidth, line->_metricHeight);    // resize()有可能为minimumSize()或者maximumSize()
                } else if(_saturateV == _esaturate_box && _wrap == false) {
                    item->_widget->resize(item->_metricWidth, boxHeight);              // resize()有可能为minimumSize()或者maximumSize()
                    if(row == 0 && col == 0) {
                        _metricHeight = 0;
                    }
                    if(_metricHeight < item->_widget->height()) {
                        _metricHeight = item->_widget->height();
                    }
                }
            }
        }
    }

public:
    void doLayout() {
        qDebug().nospace() << __FUNCTION__;
        doBalance();

        // 测试用，无实际作用
        static bool fit = false;
        if(fit == true) {
            int fitWidth  = _marginL + _metricWidth + _marginR;
            int fitHeight = _marginT + _metricHeight + _marginB;
            this->resize(fitWidth, fitHeight);    // this->resize()不触发ResizeEvent()
        }

        ////////////////////////////////

        int boxWidth = this->width() - _marginL - _marginR;
        int boxHeight = this->height() - _marginT - _marginB;
        int lastT = 0;
        if(_alignMain & Qt::AlignTop) {
            lastT = _marginT;
        } else if(_alignMain & Qt::AlignVCenter) {
            lastT = _marginT + (boxHeight -  _metricHeight) / 2;
        } else if(_alignMain & Qt::AlignBottom) {
            lastT = _marginT + boxHeight - _metricHeight;
        }
        for(int row = 0; row < _lines.size(); row += 1) {
            Line* line = &_lines[row];
            int lastL = 0;
            if(_alignMain & Qt::AlignLeft) {
                lastL = _marginL;
            } else if(_alignMain & Qt::AlignHCenter) {
                lastL = _marginL + (boxWidth - line->_metricWidth) / 2;
            } else if(_alignMain & Qt::AlignRight) {
                lastL = _marginL + boxWidth - line->_metricWidth;
            }
            for(int col = 0; col < line->_items.size(); col += 1) {
                Item* item = &(line->_items[col]);
                int offsetL = 0;
                if(_alignMinor & Qt::AlignLeft) {
                    offsetL = 0;
                } else if(_alignMinor & Qt::AlignHCenter) {
                    offsetL = 0 + (item->_metricWidth - item->_widget->width()) / 2;
                } else if(_alignMinor & Qt::AlignRight) {
                    offsetL = 0 + item->_metricWidth - item->_widget->width();
                }
                int offsetT = 0;
                if(_alignMinor & Qt::AlignTop) {
                    offsetT = 0;
                } else if(_alignMinor & Qt::AlignVCenter) {
                    offsetT = 0 + (line->_metricHeight - item->_widget->height()) / 2;
                } else if(_alignMinor & Qt::AlignBottom) {
                    offsetT = 0 + line->_metricHeight - item->_widget->height();
                }
                item->_widget->move(lastL + offsetL, lastT + offsetT);
                lastL += item->_metricWidth + _spacingH;
            }
            lastT += line->_metricHeight + _spacingV;
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
    bool _wrap = true;
    int _saturateV = _esaturate_none;
    int _alignMain  = Qt::AlignHCenter | Qt::AlignVCenter;
    int _alignMinor = Qt::AlignHCenter | Qt::AlignVCenter;
    int _marginL = 0;
    int _marginT = 0;
    int _marginR = 0;
    int _marginB = 0;
    int _spacingH = 0;
    int _spacingV = 0;

    struct Item {
        QWidget* _widget = nullptr;
        double _stretchH = 0;
        int _hintWidth = 0;
        int _hintHeight = 0;
        int _metricWidth = 0;

        Item() {

        }
        Item(QWidget* widget, double stretchH) {
            _widget = widget;
            _stretchH = stretchH;
        }
    };
    QVector<Item> _items;
    struct Line {
        QVector<Item> _items;
        int _metricWidth = 0;
        int _metricHeight = 0;
    };
    QVector<Line> _lines;
    int _metricWidth = 0;
    int _metricHeight = 0;
    QSize _lastSizeHint;
};
