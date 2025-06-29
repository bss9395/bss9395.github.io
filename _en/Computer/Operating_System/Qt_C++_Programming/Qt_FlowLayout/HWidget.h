#pragma once

#include <QDebug>
#include <QEvent>
#include <QList>
#include <QResizeEvent>
#include <QVector>
#include <QWidget>
#include <array>

class HWidget: public QWidget {
    Q_OBJECT

public:
    explicit HWidget(QWidget* parent = nullptr)
        : QWidget(parent) {
        QWidget::setAttribute(Qt::WA_StyledBackground, true);    // 启用O_OBJECT宏，需要设置Qt::WA_StyledBackground，否则背景样式不生效

    }

    virtual ~HWidget() {

    }

public:
    void resizeEvent(QResizeEvent* event) override {
        qDebug().nospace() << __FUNCTION__ << ", event = " << event;
        doLayout();
    }

	QSize sizeHint() const override {
		qDebug().nospace() << __FUNCTION__;
		int width = _marginL + _metricWidth + _marginR;
		int height = _marginT + _metricHeight + _marginB;
		return QSize(width, height);
	}

public:
	void setFit(bool fit) {
		_fit = fit;
	}

	bool getFit() {
		return _fit;
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

    void setSpacingH(int spacingH) {
        _spacingH = spacingH;
    }

    int getSpacingH() {
        return _spacingH;
    }

    void setAlignments(std::array<int, 2> alignment) {
        _alignMain = alignment[0];
        _alignMinor = alignment[1];
    }

    std::array<int, 2> getAlignments() {
        return std::array<int, 2> {
            _alignMain, _alignMinor
        };
    }

    void addWidget(QWidget* widget, double stretch = 0.0) {
        qDebug().nospace() << __FUNCTION__ << ", stretch = " << stretch;
        if(stretch <= 0.0 || qFuzzyIsNull(stretch) == true) {
            stretch = 0.0;
        }

        widget->setParent(this);
		_items.push_back(Item(widget, stretch));
        doLayout();
    }

private:
    void doBalance() {
        // qDebug().nospace() << __FUNCTION__;
        int fixedWidth = _marginL + _marginR;
        double denominator = 0.0;
        for(int col = 0; col < _items.size(); col += 1) {
			Item* item = &_items[col];
            item->_widget->adjustSize();    // 若sizeHint()有效则调整为sizeHint()，若sizeHint()无效则不调整
            fixedWidth += (col == 0) ? 0 : _spacingH;
            if(item->_stretch == 0.0) {
                fixedWidth += item->_widget->width();
            } else {
                denominator += item->_stretch * item->_widget->width();
            }
        }

        int varyWidth = this->width() - fixedWidth;    // varyWidth有可能为负值
        _metricWidth = 0;
		_metricHeight = 0;
        for(int col = 0; col < _items.size(); col += 1) {
            Item* item = &_items[col];
			item->_metricWidth = (item->_stretch == 0.0) ? item->_widget->width() : varyWidth * (item->_stretch * item->_widget->width()) / denominator;
			item->_widget->resize(item->_metricWidth, item->_widget->height());    // resize()有可能为minimumSize()或者maximumSize()
			_metricWidth += (col == 0) ? item->_metricWidth : (_spacingH + item->_metricWidth);
			if (_metricHeight < item->_widget->height()) {
				_metricHeight = item->_widget->height();
			}
        }
    }

    void doLayout() {
        qDebug().nospace() << __FUNCTION__;
        doBalance();
		if (_fit == true) {
			int width = _marginL + _metricWidth + _marginR;
			int height = _marginT + _metricHeight + _marginB;
			this->resize(width, height);    // this的左上角保持不变，resize()有可能为minimumSize()或者maximumSize()
			// qDebug().nospace() << "this->geometry() = " << this->geometry();
		}

        int boxWidth = this->width() - _marginL - _marginR;
        int boxHeight = this->height() - _marginT - _marginB;
		int lastL = 0;		
		if (_alignMain & Qt::AlignLeft) {
			lastL = _marginL;
		} else if (_alignMain & Qt::AlignHCenter) {
			lastL = _marginL + (boxWidth - _metricWidth) / 2;
		} else if (_alignMain & Qt::AlignRight) {
			lastL = _marginL + boxWidth - _metricWidth;
		}
		int lastT = 0;
		if (_alignMain & Qt::AlignTop) {
			lastT = _marginT;
		} else if (_alignMain & Qt::AlignVCenter) {
			lastT = _marginT + (boxHeight - _metricHeight) / 2;
		} else if (_alignMain & Qt::AlignBottom) {
			lastT = _marginT + boxHeight - _metricHeight;
		}
        for(int col = 0; col < _items.size(); col += 1) {
			Item* item = &_items[col];
            int offsetL = 0;
            if(_alignMinor & Qt::AlignLeft) {
                offsetL = 0;
            } else if(_alignMinor & Qt::AlignHCenter) {
                offsetL = 0 + (item->_metricWidth - item->_widget->width()) / 2;
            } else if(_alignMinor & Qt::AlignRight) {
                offsetL = 0 + item->_metricWidth - item->_widget->width();
            }
			int offsetT = 0;
			if (_alignMinor & Qt::AlignTop) {
				offsetT = 0;
			} else if (_alignMinor & Qt::AlignVCenter) {
				offsetT = 0 + (_metricHeight - item->_widget->height()) / 2;
			} else if (_alignMinor & Qt::AlignBottom) {
				offsetT = 0 + _metricHeight - item->_widget->height();
			}
			item->_widget->move(lastL + offsetL, lastT + offsetT);
			lastL += item->_metricWidth + _spacingH;
        }
    }

private:
	bool _fit = false;
    int _alignMain = Qt::AlignLeft | Qt::AlignTop;
    int _alignMinor = Qt::AlignHCenter | Qt::AlignVCenter;
    int _marginL = 0;
    int _marginT = 0;
    int _marginR = 0;
    int _marginB = 0;
    int _spacingH = 0;

	struct Item {
		QWidget* _widget = nullptr;
		double _stretch = 0.0;
		int _metricWidth = 0;

		Item() {

		}
		Item(QWidget* widget, double stretch) {
			_widget = widget;
			_stretch = stretch;
		}
	};
	QVector<Item> _items;
    int _metricWidth = 0;
	int _metricHeight = 0;
};
