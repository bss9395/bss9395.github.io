#ifndef SETTING_H
#define SETTING_H

#define Header_h
#include "Common.h"
#include "System.h"

class Settings {
public:
    static inline const QString _Create_Table = R"(
CREATE TABLE "People" (
    "_Identity"	     TEXT NOT NULL UNIQUE,
    "_Name"	         TEXT NOT NULL,
    "_Avatar"	     BLOB,
    "_Gender"	     TEXT,
    "_Birthday"	     TEXT,
    "_Homepage"	     TEXT,
    "_Mobile"	     TEXT,
    "_Email"	     TEXT,
    "_Company"	     TEXT,
    "_Department"    TEXT,
    "_Title"	     TEXT,
    "_Employee"	     TEXT,
    "_Degree"	     TEXT,
    "_Address"	     TEXT,
    "_Memo"	         TEXT,
    PRIMARY KEY("_Identity")
);
)";

    static inline const QString _Select_Table = R"(
SELECT *
FROM [People];
)";

    static inline const QString _Initialize_Table = R"(
INSERT INTO [People]
([_Identity], [_Name], [_Avatar], [_Gender], [_Birthday], [_Homepage], [_Mobile], [_Email], [_Company], [_Department], [_Title], [_Employee], [_Degree], [_Address], [_Memo])
VALUES
("440882199309051156", "黄志贵", NULL, "男", "1993-09-05", "http://github.com/bss9395", "13611464445", "brilliantstarrysky9395@outlook.com", "Andromeda", "DoLang编译器部", "软件工程师", "20220905", "本科", "中国-广东-湛江", NULL),
("440882199308051156", "黄志贵", NULL, "男", "1993-08-05", "http://bss9395.me", "13611464445", "bss9395@yeah.net", "BSS9395", "数据库开发部", "软件工程师", "20220805", "本科", "中国-广东-深圳", NULL);
)";

    static inline const QString _Delete_Talbe = R"(
DELETE FROM [People];
)";

public:
    typedef const char *Mark;
    static inline const Mark _Select = "Select";
    static inline const Mark _Insert = "Insert";
    static inline const Mark _Update = "Update";
    static inline const Mark _Delete = "Delete";


    typedef Sequence<iptr, const char *, const char *> Type;
    static inline const Type _Database = Type(-2, "Contacts", "通讯录");
    static inline const Type _Table = Type(-1, "People", "人脉");
    static inline const Type _Primary = Type(0, "_Identity", "身份证");
    static inline const Type _Identity = Type(0, "_Identity", "身份证");
    static inline const Type _Name = Type(1, "_Name", "姓名");
    static inline const Type _Avatar = Type(2, "_Avatar", "头像");
    static inline const Type _Gender = Type(3, "_Gender", "性别");
    static inline const Type _Birthday = Type(4, "_Birthday", "生日");
    static inline const Type _Homepage = Type(5, "_Homepage", "主页");
    static inline const Type _Mobile = Type(6, "_Mobile", "手机");
    static inline const Type _Email = Type(7, "_Email", "邮件");
    static inline const Type _Company = Type(8, "_Company", "公司");
    static inline const Type _Department = Type(9, "_Department", "部门");
    static inline const Type _Title = Type(10, "_Title", "职称");
    static inline const Type _Employee = Type(11, "_Employee", "工号");
    static inline const Type _Degree = Type(12, "_Degree", "学历");
    static inline const Type _Address = Type(13, "_Address", "地址");
    static inline const Type _Memo = Type(14, "_Memo", "备注");
};

#endif // SETTING_H
