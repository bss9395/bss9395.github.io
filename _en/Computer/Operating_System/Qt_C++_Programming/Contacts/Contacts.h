/* Contacts.h
Author: BSS9395
Update: 2022-02-18T23:40:00+08@China-Guangdong-Zhanjiang+08
Design: Contacts
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Contacts_h
#define Contacts_h

#define  Header_h
#include "Common.h"
#include "ui_Contacts.h"
#include "System.h"
#include "Delegate.h"

class Contacts : public QMainWindow {
    Q_OBJECT

public:
    struct Employee {
        static inline iptr _Mini_EmployeeID = 1;
        static inline iptr _Maxi_EmployeeID = 10000;
        static inline QStringList _Genders = {
            "男", "女"
        };
        static inline double _Mini_Height = 1.0;
        static inline double _Maxi_Height = 3.0;
        static inline QString _Date_Format = "yyyy-MM-dd";
        static inline QStringList _Provinces = {
            "北京", "上海", "天津", "重庆", "安徽", "河北", "河南", "湖北", "湖南", "山西", "陕西", "江苏", "江西"
        };
        static inline QStringList _Departments = {
            "销售部", "技术部", "生产部", "行政部"
        };
        static inline QStringList _Degrees = {
            "博士", "硕士", "本科", "专科", "高中", "初中", "小学"
        };
        static inline iptr _Mini_Salary = 1000;
        static inline iptr _Maxi_Salary = 50000;
        static inline iptr _Step_Salary = 100;

        ////////////////////////////////

        typedef const char *Field;
        static inline const Field _Table = "employee";

        static inline const Field _EmployID = "empNo";
        static inline const Field _Name = "Name";
        static inline const Field _Gender = "Gender";
        static inline const Field _Height = "Height";
        static inline const Field _Birthday = "Birthday";
        static inline const Field _Mobile = "Mobile";
        static inline const Field _Province = "Province";
        static inline const Field _City = "City";
        static inline const Field _Department = "Department";
        static inline const Field _Education = "Education";
        static inline const Field _Salary = "Salary";
        static inline const Field _Memo = "Memo";
        static inline const Field _Photo = "Photo";

        static inline const Field _Remark_EmployID = "工号";
        static inline const Field _Remark_Name = "姓名";
        static inline const Field _Remark_Gender = "性别";
        static inline const Field _Remark_Height = "身高";
        static inline const Field _Remark_Birthday = "出生";
        static inline const Field _Remark_Mobile = "电话";
        static inline const Field _Remark_Province = "省份";
        static inline const Field _Remark_City = "城市";
        static inline const Field _Remark_Department = "部门";
        static inline const Field _Remark_Education = "学历";
        static inline const Field _Remark_Salary = "薪资";
        static inline const Field _Remark_Memo = "备注";
        static inline const Field _Remark_Photo = "照片";
    };

public:
    Ui::Contacts *_ui = nullptr;
    QSqlDatabase _database = QSqlDatabase();
    QSqlTableModel *_model = nullptr;
    QItemSelectionModel *_selection = nullptr;
    QDataWidgetMapper *_mapper = nullptr;

public:
    explicit Contacts(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Contacts) {
        _ui->setupUi(this);
        System::Logging(__FUNCTION__);

        QObject::connect(_selection, &QItemSelectionModel::currentChanged, [this](QModelIndex current, QModelIndex previous) -> void {

        });

        QObject::connect(_selection, &QItemSelectionModel::currentRowChanged, [this](QModelIndex current, QModelIndex previous) -> void {

        });

        QObject::connect(_ui->A_Load, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Load, &QAction::triggered, [this]() -> void {");

            QString caption = "数据库文件";
            QString filter = "SQLite(*.db *.db3)";
            QString filename = QFileDialog::getOpenFileName(this, caption, QDir::currentPath(), filter);
            if(filename.size() <= 0) {
                return ;
            }
            _database = QSqlDatabase::addDatabase("QSQLITE");  // note: add database driver.
            _database.setDatabaseName(filename);
            // _database.setHostName();
            // _database.setUserName();
            // _database.setPassword();
            if(_database.open() == false) {
                QString caption = "无法加载数据库";
                QString label = "加载数据库失败";
                QMessageBox::warning(this, caption, label, QMessageBox::Ok, QMessageBox::NoButton);
                return ;
            }

            _model = new QSqlTableModel(this, _database);
            _selection = new QItemSelectionModel(_model);
            _mapper = new QDataWidgetMapper(this);
            _mapper->setModel(_model);
            _mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
            _ui->TV_Table->setModel(_model);
            _ui->TV_Table->setSelectionModel(_selection);

            ////////////////////////////////////////////////////////////////////

            _model->setTable("employee");
            _model->setEditStrategy(QSqlTableModel::OnManualSubmit);  // note: OnManualSubmit | OnRowChange | OnFieldChange
            _model->setSort(_model->fieldIndex("empNo"), Qt::AscendingOrder);
            if(_model->select() == false) {  // note: caling select() will revert any unsubmitted changes and remove any inserted columns.
                QString caption = "无法加载数据库";
                QString label = _model->lastError().text();
                QMessageBox::critical(this, caption, label, QMessageBox::Ok, QMessageBox::NoButton);
                return ;
            }

            _model->setHeaderData(_model->fieldIndex(Employee::_EmployID), Qt::Horizontal, Employee::_Remark_EmployID);
            _model->setHeaderData(_model->fieldIndex(Employee::_Name), Qt::Horizontal, Employee::_Remark_Name);
            _model->setHeaderData(_model->fieldIndex(Employee::_Gender), Qt::Horizontal, Employee::_Remark_Gender);
            _model->setHeaderData(_model->fieldIndex(Employee::_Height), Qt::Horizontal, Employee::_Remark_Height);
            _model->setHeaderData(_model->fieldIndex(Employee::_Birthday), Qt::Horizontal, Employee::_Remark_Birthday);
            _model->setHeaderData(_model->fieldIndex(Employee::_Mobile), Qt::Horizontal, Employee::_Remark_Mobile);
            _model->setHeaderData(_model->fieldIndex(Employee::_Province), Qt::Horizontal, Employee::_Remark_Province);
            _model->setHeaderData(_model->fieldIndex(Employee::_City), Qt::Horizontal, Employee::_Remark_City);
            _model->setHeaderData(_model->fieldIndex(Employee::_Department), Qt::Horizontal, Employee::_Remark_Department);
            _model->setHeaderData(_model->fieldIndex(Employee::_Education), Qt::Horizontal, Employee::_Remark_Education);
            _model->setHeaderData(_model->fieldIndex(Employee::_Salary), Qt::Horizontal, Employee::_Remark_Salary);
            _model->setHeaderData(_model->fieldIndex(Employee::_Memo), Qt::Horizontal, Employee::_Remark_Memo);
            _model->setHeaderData(_model->fieldIndex(Employee::_Photo), Qt::Horizontal, Employee::_Remark_Photo);

            QStringList genders = {
                "男", "女"
            };
            ComboBox_Delegate *genders_delegate = new ComboBox_Delegate(this, genders, true);
            _ui->TV_Table->setItemDelegateForColumn(_model->fieldIndex(Employee::_Gender), genders_delegate);

            QStringList departments = {
                "销售部", "技术部", "生产部", "行政部"
            };
            ComboBox_Delegate *departments_delegate = new ComboBox_Delegate(this, departments, true);
            _ui->TV_Table->setItemDelegateForColumn(_model->fieldIndex(Employee::_Department), departments_delegate);

            _mapper->addMapping(_ui->SB_EmployeeID, _model->fieldIndex(Employee::_EmployID));
            _mapper->addMapping(_ui->LE_Name, _model->fieldIndex(Employee::_Name));
            _mapper->addMapping(_ui->CB_Gender, _model->fieldIndex(Employee::_Gender));
            _mapper->addMapping(_ui->DSB_Height, _model->fieldIndex(Employee::_Height));
            _mapper->addMapping(_ui->DE_Birthday, _model->fieldIndex(Employee::_Birthday));
            _mapper->addMapping(_ui->LE_Mobile, _model->fieldIndex(Employee::_Mobile));
            _mapper->addMapping(_ui->CB_Province, _model->fieldIndex(Employee::_Province));
            _mapper->addMapping(_ui->LE_City, _model->fieldIndex(Employee::_City));
            _mapper->addMapping(_ui->CB_Department, _model->fieldIndex(Employee::_Department));
            _mapper->addMapping(_ui->CB_Education, _model->fieldIndex(Employee::_Education));
            _mapper->addMapping(_ui->SB_Salary, _model->fieldIndex(Employee::_Salary));
            _mapper->addMapping(_ui->PLT_Memo, _model->fieldIndex(Employee::_Memo));

            _mapper->toFirst();
            QSqlRecord fields = _model->record();
            for(iptr i = 0, size = fields.count(); i < size; i += 1) {
                _ui->CB_Fields->addItem(fields.fieldName(i));
            }
        });

    }

    virtual ~Contacts() override {
        System::Logging(__FUNCTION__);

        delete _ui;
    }

public:



};

#endif // Contacts_h
