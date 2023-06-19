#ifndef COURSE_SELECTION_SYSTEM
#define COURSE_SELECTION_SYSTEM
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

//课程信息类
//编号 名称 年级 学院 专业 开课学院 课程类别 课程性质 课程归属 上课星期 上课节次
class course
{
protected:
    //基本信息
    string course_id;//课程编号
    string course_name;//课程名称
    //筛选信息
    string course_grade;//年级
    string course_college;//学院
    string course_profession;//专业
    string course_college_open;//开课学院
    string course_type;//课程类别
    string course_nature;//课程性质
    string course_belong;//课程归属
    //课程时间
    string course_week;//上课星期
    string course_time;//上课节次
public:
    //构造函数
    course(string course_id, string course_name, string course_grade, string course_college, string course_profession, string course_college_open, string course_type, string course_nature, string course_belong, string course_week, string course_time) :course_id(course_id), course_name(course_name), course_grade(course_grade), course_college(course_college), course_profession(course_profession), course_college_open(course_college_open), course_type(course_type), course_nature(course_nature), course_belong(course_belong), course_week(course_week), course_time(course_time) {};
    //基础功能:查询课程信息
    static void Search_course_information();
};
//学生选课信息派生类
class stu_course :public course
{
private:
    string stu_account;//学生学号
    string stu_temp_course_id;//待操作选课信息的课程编号
    string stu_temp_course_week;//待操作选课信息的课程星期
    string stu_temp_course_time;//待操作选课信息的课程节次
public:
    //构造函数
    stu_course(string course_id, string course_name, string course_grade, string course_college, string course_profession, string course_college_open, string course_type, string course_nature, string course_belong, string course_week, string course_time, string stu_account, string stu_temp_course_id, string stu_temp_course_week, string stu_temp_course_time) :course(course_id, course_name, course_grade, course_college, course_profession, course_college_open, course_type, course_nature, course_belong, course_week, course_time), stu_account(stu_account), stu_temp_course_id(stu_temp_course_id), stu_temp_course_week(stu_temp_course_week), stu_temp_course_time(stu_temp_course_time) {};
    //根据待操作课程编号获得课程星期和节次
    void Get_course_week_time();
    //选课是否冲突
    bool Isconflict();
    //退课是否为存在的课程
    bool Iscourse(string course_id);
    //输出课表
    string Get_course(string course_week, string course_time);
    //功能1:选课
    void Choose_course();
    //功能2:退课
    void Drop_course();
    //功能3:显示已选课程(课表形式)
    void Show_course();
    //功能4:显示下一节课的时间和名称
    void Show_next_course();
};
//教师授课信息派生类
class tea_course :public course
{
private:
    string tea_account;//教师工号
    string tea_temp_course_id;//待操作授课信息的课程编号
    string tea_temp_course_week;//待操作授课信息的课程星期
    string tea_temp_course_time;//待操作授课信息的课程节次
    //友元类
    friend class admin;
    //根据待操作课程编号获得课程星期和节次
    void Get_course_week_time();
    //授课是否冲突
    bool Isconflict();
    //退课是否为存在的课程
    bool Iscourse(string course_id);
    //输出课表
    string Get_course(string course_week, string course_time);
    //功能1：添加授课信息(只可管理员访问)
    void Add_tea_course();
    //功能2：删除授课信息（只可管理员访问
    void Delete_tea_course();
public:
    //构造函数
    tea_course(string course_id, string course_name, string course_grade, string course_college, string course_profession, string course_college_open, string course_type, string course_nature, string course_belong, string course_week, string course_time, string tea_account, string tea_temp_course_id, string tea_temp_course_week, string tea_temp_course_time) :course(course_id, course_name, course_grade, course_college, course_profession, course_college_open, course_type, course_nature, course_belong, course_week, course_time), tea_account(tea_account), tea_temp_course_id(tea_temp_course_id), tea_temp_course_week(tea_temp_course_week), tea_temp_course_time(tea_temp_course_time) {};
    //功能3：显示授课课表
    void Show_tea_course();
    //功能4：显示下一节课的时间和名称
    void Show_next_course();
};

//账号密码类
class account_password
{
protected:
    string account;//账号
    string password;//密码
    string name;//姓名
public:
    //构造函数
    account_password(string account, string password, string name) :account(account), password(password), name(name) {};
};
//学生派生类
//学号（账号） 密码 姓名 年级 学院 专业 班级
class student :public account_password
{
private:
    string stu_class;//学生班级
    string stu_grade;//学生年级
    string stu_college;//学生学院
    string stu_profession;//学生专业
public:
    //构造函数
    student(string account, string password, string name, string stu_class, string stu_grade, string stu_college, string stu_profession) :account_password(account, password, name), stu_class(stu_class), stu_grade(stu_grade), stu_college(stu_college), stu_profession(stu_profession) {};
    //判断账号密码是否正确
    bool Isright();
    //从文件中读取学生信息
    void Read_stu_information();
    //登录成功并读取学生信息或者登录失败
    bool Login();
    //功能1:修改密码
    void Change_password();
    //功能2:显示学生信息
    void Show_stu_information();
    //功能3:课程信息查询
    void Course_search();
    //功能4:选课
    void Choose_course();
    //功能5:退课
    void Drop_course();
    //功能6:显示课表
    void Show_course();
    //功能7:下一节课的时间和名称
    void Show_next_course();
};
//教师派生类
//工号（账号） 密码 姓名 学院
class teacher :public account_password
{
private:
    string tea_college;//学院
public:
    //构造函数
    teacher(string account, string password, string name, string tea_college) :account_password(account, password, name), tea_college(tea_college) {};
    //判断账号密码是否正确
    bool Isright();
    //从文件中读取教师信息
    void Read_tea_information();
    //登录成功并读取教师信息或者登录失败
    bool Login();
    //根据学号获取学生名字
    string Get_stu_name(string stu_account);
    //功能1:修改密码
    void Change_password();
    //功能2:显示教师信息
    void Show_tea_information();
    //功能3:课程信息查询
    void Course_search();
    //功能4:显示课表
    void Show_course();
    //功能5:所教课程的学生名单
    void Show_stu_list();
    //功能6:下一节课的时间和名称
    void Show_next_course();
};
//管理员派生类
//账号 密码 姓名
class admin :public account_password
{
private:
    string temp_accountORcourseid_class;//待操作学生或教师的账号或课程编号
public:
    //构造函数
    admin(string account, string password, string name) :account_password(account, password, name) {};
    //判断账号密码是否正确
    bool Isright();
    //从文件中读取管理员信息
    void Read_admin_information();
    //登录成功并读取管理员信息或者登录失败
    bool Login();
    //访问教师授课信息类的私有成员选课函数
    inline void access_private_tea_course(tea_course& tea_course_temp);
    //访问教师授课信息类的私有成员退课函数
    inline void access_private_tea_course1(tea_course& tea_course_temp);
    //打开student.txt文件并判断是否存在该学生
    bool Is_stu_exist(string stu_account);
    //打开teacher.txt文件并判断是否存在该教师
    bool Is_tea_exist(string tea_account);
    //打开course.txt文件并判断是否存在该课程
    bool Is_course_exist(string course_id);
    //根据学号返回学生姓名
    string Get_stu_name(string stu_account);
    //根据工号返回教师姓名
    string Get_tea_name(string tea_account);
    //功能1:修改密码
    void Change_password();
    //功能2:显示管理员信息
    void Show_admin_information();
    //功能3:添加学生信息(按照学号从小到大)
    void Add_stu_information();
    //功能4:删除学生信息
    void Delete_stu_information();
    //功能5:修改学生密码
    void Change_stu_password();
    //功能6:添加教师信息
    void Add_tea_information();
    //功能7:删除教师信息
    void Delete_tea_information();
    //功能8:修改教师密码
    void Change_tea_password();
    //功能9:添加课程信息
    void Add_course_information();
    //功能10:删除课程信息
    void Delete_course_information();
    //功能11:查询课程信息
    void Search_course_information();
    //功能12:查询学生信息
    void Search_stu_information();
    //功能13:查询教师信息
    void Search_tea_information();
    //功能14:查询学生选课信息
    void Search_stu_course_information();
    //功能15:查询教师授课信息
    void Search_tea_course_information();
    //功能16:添加学生选课
    void Add_stu_course();
    //功能17:删除学生选课
    void Delete_stu_course();
    //功能18:添加教师授课
    void Add_tea_course();
    //功能19:删除教师授课
    void Delete_tea_course();
    //功能20:查询某课程的教师和学生名单
    void Search_course_tea_stu_information();
};

#endif
