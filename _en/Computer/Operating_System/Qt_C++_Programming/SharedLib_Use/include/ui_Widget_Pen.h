/********************************************************************************
** Form generated from reading UI file 'Widget_Pen.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_PEN_H
#define UI_WIDGET_PEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Pen
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *GB_Attribute;
    QVBoxLayout *verticalLayout_2;
    QFrame *F_Form;
    QFormLayout *formLayout;
    QLabel *L_Width;
    QSpinBox *SB_Width;
    QLabel *L_Cap;
    QComboBox *CB_Cap;
    QLabel *L_Joint;
    QComboBox *CB_Joint;
    QLabel *L_Style;
    QComboBox *CB_Style;
    QLabel *L_Color;
    QPushButton *PB_Color;
    QFrame *F_Submit;
    QHBoxLayout *horizontalLayout;
    QPushButton *PB_Accept;
    QPushButton *PB_Reject;

    void setupUi(QWidget *Widget_Pen)
    {
        if (Widget_Pen->objectName().isEmpty())
            Widget_Pen->setObjectName(QString::fromUtf8("Widget_Pen"));
        Widget_Pen->resize(348, 215);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget_Pen->sizePolicy().hasHeightForWidth());
        Widget_Pen->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Widget_Pen);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        GB_Attribute = new QGroupBox(Widget_Pen);
        GB_Attribute->setObjectName(QString::fromUtf8("GB_Attribute"));
        sizePolicy.setHeightForWidth(GB_Attribute->sizePolicy().hasHeightForWidth());
        GB_Attribute->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(GB_Attribute);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        F_Form = new QFrame(GB_Attribute);
        F_Form->setObjectName(QString::fromUtf8("F_Form"));
        F_Form->setFrameShape(QFrame::StyledPanel);
        F_Form->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(F_Form);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        L_Width = new QLabel(F_Form);
        L_Width->setObjectName(QString::fromUtf8("L_Width"));
        L_Width->setMinimumSize(QSize(0, 0));
        L_Width->setMaximumSize(QSize(16777215, 16777215));

        formLayout->setWidget(0, QFormLayout::LabelRole, L_Width);

        SB_Width = new QSpinBox(F_Form);
        SB_Width->setObjectName(QString::fromUtf8("SB_Width"));
        SB_Width->setFocusPolicy(Qt::ClickFocus);

        formLayout->setWidget(0, QFormLayout::FieldRole, SB_Width);

        L_Cap = new QLabel(F_Form);
        L_Cap->setObjectName(QString::fromUtf8("L_Cap"));

        formLayout->setWidget(1, QFormLayout::LabelRole, L_Cap);

        CB_Cap = new QComboBox(F_Form);
        CB_Cap->setObjectName(QString::fromUtf8("CB_Cap"));
        CB_Cap->setFocusPolicy(Qt::ClickFocus);

        formLayout->setWidget(1, QFormLayout::FieldRole, CB_Cap);

        L_Joint = new QLabel(F_Form);
        L_Joint->setObjectName(QString::fromUtf8("L_Joint"));

        formLayout->setWidget(2, QFormLayout::LabelRole, L_Joint);

        CB_Joint = new QComboBox(F_Form);
        CB_Joint->setObjectName(QString::fromUtf8("CB_Joint"));
        CB_Joint->setFocusPolicy(Qt::ClickFocus);

        formLayout->setWidget(2, QFormLayout::FieldRole, CB_Joint);

        L_Style = new QLabel(F_Form);
        L_Style->setObjectName(QString::fromUtf8("L_Style"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(L_Style->sizePolicy().hasHeightForWidth());
        L_Style->setSizePolicy(sizePolicy1);
        L_Style->setMinimumSize(QSize(0, 0));
        L_Style->setMaximumSize(QSize(16777215, 16777215));

        formLayout->setWidget(3, QFormLayout::LabelRole, L_Style);

        CB_Style = new QComboBox(F_Form);
        CB_Style->setObjectName(QString::fromUtf8("CB_Style"));
        CB_Style->setFocusPolicy(Qt::ClickFocus);

        formLayout->setWidget(3, QFormLayout::FieldRole, CB_Style);

        L_Color = new QLabel(F_Form);
        L_Color->setObjectName(QString::fromUtf8("L_Color"));
        L_Color->setMinimumSize(QSize(0, 0));
        L_Color->setMaximumSize(QSize(16777215, 16777215));

        formLayout->setWidget(4, QFormLayout::LabelRole, L_Color);

        PB_Color = new QPushButton(F_Form);
        PB_Color->setObjectName(QString::fromUtf8("PB_Color"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(PB_Color->sizePolicy().hasHeightForWidth());
        PB_Color->setSizePolicy(sizePolicy2);
        PB_Color->setFocusPolicy(Qt::ClickFocus);

        formLayout->setWidget(4, QFormLayout::FieldRole, PB_Color);


        verticalLayout_2->addWidget(F_Form);

        F_Submit = new QFrame(GB_Attribute);
        F_Submit->setObjectName(QString::fromUtf8("F_Submit"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(F_Submit->sizePolicy().hasHeightForWidth());
        F_Submit->setSizePolicy(sizePolicy3);
        F_Submit->setFrameShape(QFrame::StyledPanel);
        F_Submit->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(F_Submit);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(6, 6, 6, 6);
        PB_Accept = new QPushButton(F_Submit);
        PB_Accept->setObjectName(QString::fromUtf8("PB_Accept"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(PB_Accept->sizePolicy().hasHeightForWidth());
        PB_Accept->setSizePolicy(sizePolicy4);
        PB_Accept->setMinimumSize(QSize(72, 0));
        PB_Accept->setMaximumSize(QSize(72, 16777215));

        horizontalLayout->addWidget(PB_Accept);

        PB_Reject = new QPushButton(F_Submit);
        PB_Reject->setObjectName(QString::fromUtf8("PB_Reject"));
        sizePolicy4.setHeightForWidth(PB_Reject->sizePolicy().hasHeightForWidth());
        PB_Reject->setSizePolicy(sizePolicy4);
        PB_Reject->setMinimumSize(QSize(72, 0));
        PB_Reject->setMaximumSize(QSize(72, 16777215));

        horizontalLayout->addWidget(PB_Reject);


        verticalLayout_2->addWidget(F_Submit);


        verticalLayout->addWidget(GB_Attribute);

        QWidget::setTabOrder(SB_Width, CB_Cap);
        QWidget::setTabOrder(CB_Cap, CB_Joint);
        QWidget::setTabOrder(CB_Joint, PB_Accept);
        QWidget::setTabOrder(PB_Accept, PB_Reject);

        retranslateUi(Widget_Pen);

        QMetaObject::connectSlotsByName(Widget_Pen);
    } // setupUi

    void retranslateUi(QWidget *Widget_Pen)
    {
        Widget_Pen->setWindowTitle(QCoreApplication::translate("Widget_Pen", "Form", nullptr));
        GB_Attribute->setTitle(QCoreApplication::translate("Widget_Pen", "\347\224\273\347\254\224\345\261\236\346\200\247", nullptr));
        L_Width->setText(QCoreApplication::translate("Widget_Pen", "\347\272\277\345\256\275", nullptr));
        L_Cap->setText(QCoreApplication::translate("Widget_Pen", "\347\272\277\347\253\257", nullptr));
        L_Joint->setText(QCoreApplication::translate("Widget_Pen", "\347\272\277\350\277\236", nullptr));
        L_Style->setText(QCoreApplication::translate("Widget_Pen", "\347\272\277\345\236\213", nullptr));
        L_Color->setText(QCoreApplication::translate("Widget_Pen", "\351\242\234\350\211\262", nullptr));
        PB_Color->setText(QString());
        PB_Accept->setText(QCoreApplication::translate("Widget_Pen", "\347\241\256\345\256\232", nullptr));
        PB_Reject->setText(QCoreApplication::translate("Widget_Pen", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_Pen: public Ui_Widget_Pen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_PEN_H
