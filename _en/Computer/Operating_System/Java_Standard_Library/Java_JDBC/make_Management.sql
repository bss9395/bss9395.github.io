
drop database if exists Management;
create database Management;
use Management;

create table `Teacher` (
	`_id` 	int				not null	auto_increment,
	`_name`	varchar(256)	null,
	primary key(`_id`)
);

create table `Student` (
	`_id` 			int				not null	auto_increment,
    `_name`			varchar(255)	null,
    `_teacher_id`	int				null,
    primary key(`_id`),
    foreign key(`_teacher_id`) references `Teacher`(`_id`)
);

insert into Teacher values
(null, 'Yeeku'),
(null, 'Leegang'),
(null, 'Martine');

insert into Student values
(null, '张三', 1),
(null, '张三', 1),
(null, '李四', 1),
(null, '王五', 2),
(null, '_王五', 2),
(null, null, 2),
(null, '赵六', null);
