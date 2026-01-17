

drop database if exists Management;
create database Management;

create table Management.Teacher (
    _id 	int				not null    auto_increment,
    _name   varchar(256)    null,
	primary key(_id)
);

create table Management.Student (
    _id 			int				not null	auto_increment,
    _name			varchar(255)	null,
    _teacher_id	    int				null,
    primary key(_id),
    foreign key(_teacher_id) references Management.Teacher(_id)
);

insert into Management.Teacher values
(null, 'Yeeku'),
(null, 'Leegang'),
(null, 'Martine');

insert into Management.Student values
(null, '张三', 1),
(null, '张三', 1),
(null, '李四', 1),
(null, '王五', 2),
(null, '_王五', 2),
(null, null, 2),
(null, '赵六', null);

--------------------------------------------------------------------------------

select Student.*, Teacher._name
from Management.Student as Student, Management.Teacher as Teacher
where Student._teacher_id = Teacher._id;

--------------------------------------------------------------------------------

drop procedure if exists Management.P_Add;

delimiter //
create procedure Management.P_Add(a int, b int, out sum int)
begin
set sum = a + b;
end
//

--------------------------------------------------------------------------------

create table Management.Images (
    _id     int             not null    auto_increment,
    _name   varchar(255)    null,
    _data   mediumblob      null,
    primary key(_id)
);

--------------------------------------------------------------------------------

show databases;
use information_schema;
show tables;

select * 
from information_schema.schemata;

select *
from information_schema.tables 
where table_schema='management';

select *
from information_schema.columns
where table_name='student';

--------------------------------------------------------------------------------
