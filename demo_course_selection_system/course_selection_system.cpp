#include <windows.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include "course_selection_system.h"
using namespace std;

//课程信息类
//编号 名称 年级 学院 专业 开课学院 课程类别 课程性质 课程归属 上课星期 上课节次
//功能函数定义
void course::Search_course_information()
{
    cout << "请依次输入筛选条件:" << endl << "(严格按照以下格式输入,不进行筛选的条件请输入0)" << endl;
    cout << "(编号 名称 年级 学院 专业 开课学院 课程类别 课程性质 课程归属 上课星期 上课节次)" << endl;
    string course_id;
    string course_name;
    string course_grade;
    string course_college;
    string course_profession;
    string course_college_open;
    string course_type;
    string course_nature;
    string course_belong;
    string course_week;
    string course_time;
    cin >> course_id >> course_name >> course_grade >> course_college >> course_profession >> course_college_open >> course_type >> course_nature >> course_belong >> course_week >> course_time;
    course temp_course(course_id, course_name, course_grade, course_college, course_profession, course_college_open, course_type, course_nature, course_belong, course_week, course_time);
    //打开文件
    fstream course_file("course.txt", ios::in);
    if (!course_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    system("cls");
    //不读取第一行作为信息
    string temp;
    getline(course_file, temp);
    //读取文件并筛选
    course_file >> course_id >> course_name >> course_grade >> course_college >> course_profession >> course_college_open >> course_type >> course_nature >> course_belong >> course_week >> course_time;
    while (!course_file.eof())
    {
        if ((course_id == temp_course.course_id || temp_course.course_id == "0") && (course_name == temp_course.course_name || temp_course.course_name == "0") && (course_grade == temp_course.course_grade || temp_course.course_grade == "0") && (course_college == temp_course.course_college || temp_course.course_college == "0") && (course_profession == temp_course.course_profession || temp_course.course_profession == "0") && (course_college_open == temp_course.course_college_open || temp_course.course_college_open == "0") && (course_type == temp_course.course_type || temp_course.course_type == "0") && (course_nature == temp_course.course_nature || temp_course.course_nature == "0") && (course_belong == temp_course.course_belong || temp_course.course_belong == "0") && (course_week == temp_course.course_week || temp_course.course_week == "0") && (course_time == temp_course.course_time || temp_course.course_time == "0"))
        {
            cout << "以下课程符合筛选条件:" << endl;
            cout << course_id << " " << course_name << " " << course_grade << " " << course_college << " " << course_profession << " " << course_college_open << " " << course_type << " " << course_nature << " " << course_belong << " " << course_week << " " << course_time << endl;
        }
        course_file >> course_id >> course_name >> course_grade >> course_college >> course_profession >> course_college_open >> course_type >> course_nature >> course_belong >> course_week >> course_time;
    }
    course_file.close();
    cout << "查询完毕" << endl;
}
//学生选课信息派生类
//函数定义
void stu_course::Get_course_week_time()
{
    //打开course.txt文件并定位到该课程
    fstream course_file("course.txt", ios::in);
    if (!course_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    string temp_course_id;
    string temp;
    while (course_file >> temp_course_id)
    {
        if (temp_course_id == stu_temp_course_id)
        {
            break;
        }
        getline(course_file, temp);
    }
    //读取课程星期和节次
    course_file >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> stu_temp_course_week >> stu_temp_course_time;
    course_file.close();
}
bool stu_course::Isconflict()
{
    cout << "请输入要选的课程编号:" << endl;
    cin >> stu_temp_course_id;
    //获得待操作课程星期和节次
    Get_course_week_time();
    //打开文件并判断是否冲突
    fstream stu_course_file("./stu_course/" + stu_account + ".txt", ios::in);
    if (!stu_course_file)
    {
        //如果文件不存在则新建文件
        stu_course_file.open("./stu_course/" + stu_account + ".txt", ios::out);
        stu_course_file.close();
        stu_course_file.open("./stu_course/" + stu_account + ".txt", ios::in);
        if (!stu_course_file)
        {
            cout << "文件打开失败" << endl;
            exit(1);
        }
    }
    string temp_course_id;
    string temp;
    string temp_course_week;
    string temp_course_time;
    while (stu_course_file >> temp_course_id >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp_course_week >> temp_course_time)
    {
        if (temp_course_id == stu_temp_course_id || (temp_course_week == stu_temp_course_week && temp_course_time == stu_temp_course_time))
        {
            stu_course_file.close();
            return true;
        }
    }
    stu_course_file.close();
    return false;
}
bool stu_course::Iscourse(string course_id)
{
    //打开文件
    fstream stu_course_file("./stu_course/" + stu_account + ".txt", ios::in);
    if (!stu_course_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //遍历一遍学生选课信息，如果有相同的课程编号则返回true
    string temp_course_id;
    string temp;
    while (stu_course_file >> temp_course_id)
    {
        if (temp_course_id == course_id)
        {
            stu_course_file.close();
            return true;
            break;
        }
        getline(stu_course_file, temp);
    }
    stu_course_file.close();
    return false;
}
string stu_course::Get_course(string course_week, string course_time)
{
    //打开文件
    fstream stu_course_file("./stu_course/" + stu_account + ".txt", ios::in);
    if (!stu_course_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //遍历一遍学生选课信息，如果有相同的星期和节次则return课程名字
    string temp_course_week;
    string temp_course_time;
    string temp_course_name;
    string temp;
    while (stu_course_file >> temp >> temp_course_name >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp_course_week >> temp_course_time)
    {
        if (temp_course_week == course_week && temp_course_time == course_time)
        {
            return temp_course_name;
            break;
        }
    }
    stu_course_file.close();
    return "";
}
//功能函数定义
void stu_course::Choose_course()
{
    //判断stu_course文件夹是否已经创建
    fstream test1("./stu_course/test.txt", ios::out);
    if (!test1)
    {
        CreateDirectory(_T("./stu_course"), NULL);
    }
    else {
        test1.close();
        remove("./stu_course/test.txt");
    }
    //打开stu_course文件夹下的以学号为命名的选课情况文件
    fstream stu_course_file("./stu_course/" + stu_account + ".txt", ios::in | ios::out | ios::app);
    if (!stu_course_file)
    {
        //如果文件不存在则新建文件
        stu_course_file.open("./stu_course/" + stu_account + ".txt", ios::out);
        stu_course_file.close();
        stu_course_file.open("./stu_course/" + stu_account + ".txt", ios::in | ios::out | ios::app);
        if (!stu_course_file)
        {
            cout << "文件打开失败" << endl;
            exit(1);
        }
    }
    //是否冲突，不同结果进行不同操作
    if (!Isconflict())
    {
        //不冲突则从course.txt匹配对应课程并写入文件
        //打开course.txt
        fstream course_file("course.txt", ios::in);
        if (!course_file)
        {
            cout << "文件打开失败" << endl;
            exit(1);
        }
        //定位到该课程
        string temp_course_id;
        string temp;
        while (course_file >> temp_course_id)
        {
            if (temp_course_id == stu_temp_course_id)
            {
                break;
            }
            getline(course_file, temp);
        }
        //写入文件
        getline(course_file, temp);
        stu_course_file << temp_course_id << temp << endl;
        course_file.close();
        system("cls");
        cout << "选课成功" << endl;
        //判断course_student_list文件夹是否已经创建
        fstream test2("./course_student_list/test.txt", ios::out);
        if (!test2)
        {
            CreateDirectory(_T("./course_student_list"), NULL);
        }
        else {
            test2.close();
            remove("./course_student_list/test.txt");
        }
        //向course_student_list文件夹下的课程学生名单中写入学号
        //打开文件
        fstream course_student_list_file("./course_student_list/" + stu_temp_course_id + ".txt", ios::out | ios::app);
        if (!course_student_list_file)
        {
            cout << "文件打开失败" << endl;
            exit(1);
        }
        //写入学号
        course_student_list_file << stu_account << endl;
        course_student_list_file.close();
    }
    else {
        system("cls");
        cout << "选课失败，可能原因为选课重复或时间冲突" << endl;
    }
}
void stu_course::Drop_course()
{
    //判断stu_course文件夹是否已经创建
    fstream test1("./stu_course/test.txt", ios::out);
    if (!test1)
    {
        CreateDirectory(_T("./stu_course"), NULL);
    }
    else {
        test1.close();
        remove("./stu_course/test.txt");
    }
    cout << "请输入要退的课程编号:" << endl;
    cin >> stu_temp_course_id;
    //是否为已选的课程，不同结果进行不同操作
    if (!Iscourse(stu_temp_course_id))
    {
        system("cls");
        cout << "退课失败，可能原因为未选该课程" << endl;
        return;
    }
    //打开文件
    fstream stu_course_file("./stu_course/" + stu_account + ".txt", ios::in | ios::out);
    if (!stu_course_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //新建一个stu_course_temp.txt用于临时保存数据
    fstream stu_course_temp_file("./stu_course/" + stu_account + "_temp.txt", ios::out);
    if (!stu_course_temp_file)
    {
        cout << "临时文件创建失败" << endl;
        exit(1);
    }
    //定位到该课程并向stu_course_temp.txt中持续写入数据,跳过写入该课程数据
    string temp_course_id;
    string temp;
    while (stu_course_file >> temp_course_id)
    {
        if (temp_course_id != stu_temp_course_id)
        {
            stu_course_temp_file << temp_course_id;
            getline(stu_course_file, temp);
            stu_course_temp_file << temp << endl;
        }
        else
        {
            getline(stu_course_file, temp);
        }
    }
    stu_course_file.close();
    stu_course_temp_file.close();
    //删除原文件
    remove(("./stu_course/" + stu_account + ".txt").c_str());
    //重命名文件
    rename(("./stu_course/" + stu_account + "_temp.txt").c_str(), ("./stu_course/" + stu_account + ".txt").c_str());
    system("cls");
    cout << "退课成功" << endl;
    //判断course_student_list文件夹是否已经创建
    fstream test2("./course_student_list/test.txt", ios::out);
    if (!test2)
    {
        CreateDirectory(_T("./course_student_list"), NULL);
    }
    else {
        test2.close();
        remove("./course_student_list/test.txt");
    }
    //删除course_student_list文件夹下的课程学生名单中的学号
    //打开文件
    fstream course_student_list_file("./course_student_list/" + stu_temp_course_id + ".txt", ios::in);
    if (!course_student_list_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //新建一个temp文本用于临时保存数据
    fstream course_student_list_temp_file("./course_student_list/" + stu_temp_course_id + "_temp.txt", ios::out);
    if (!course_student_list_temp_file)
    {
        cout << "临时文件创建失败" << endl;
        exit(1);
    }
    //定位到该课程并向course_student_list_temp.txt中持续写入数据,跳过写入该学号数据
    string temp_stu_account;
    while (course_student_list_file >> temp_stu_account)
    {
        if (temp_stu_account != stu_account)
        {
            course_student_list_temp_file << temp_stu_account << endl;
        }
    }
    course_student_list_file.close();
    course_student_list_temp_file.close();
    //删除原文件
    remove(("./course_student_list/" + stu_temp_course_id + ".txt").c_str());
    //重命名文件
    rename(("./course_student_list/" + stu_temp_course_id + "_temp.txt").c_str(), ("./course_student_list/" + stu_temp_course_id + ".txt").c_str());
}
void stu_course::Show_course()
{
    //打开文件
    fstream stu_course_file("./stu_course/" + stu_account + ".txt", ios::in);
    if (!stu_course_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //显示课表

    stu_course_file.close();
}
void stu_course::Show_next_course()
{
    //获取当前时间
    time_t now_time = time(NULL);
    //转换为本地时间
    tm local_time;
    localtime_s(&local_time, &now_time);
    //string类型存储当前时间
    string week;
    string time;
    if (local_time.tm_hour < 8)
    {
        time = "1和2";
    }
    else if (local_time.tm_hour < 10)
    {
        time = "3和4";
    }
    else if (local_time.tm_hour < 14)
    {
        time = "5和6";
    }
    else if (local_time.tm_hour < 16)
    {
        time = "7和8";
    }
    else if (local_time.tm_hour < 19)
    {
        time = "9和10和11";
    }
    else
    {
        cout << "今天已经没有课了，睡个好觉吧" << endl;
        return;
    }
    switch (local_time.tm_wday)
    {
    case 0:
        week = "星期日";
        break;
    case 1:
        week = "星期一";
        break;
    case 2:
        week = "星期二";
        break;
    case 3:
        week = "星期三";
        break;
    case 4:
        week = "星期四";
        break;
    case 5:
        week = "星期五";
        break;
    case 6:
        week = "星期六";
        break;
    }
    //调用函数获得课程名字
    string name = Get_course(week, time);
    //输出下一节课的时间和名称
    cout << "下一节课为:" << name << endl;
    cout << "时间为:";
    if (time == "1和2")
    {
        cout << "8:00-9:40" << endl;
    }
    else if (time == "3和4")
    {
        cout << "10:00-11:40" << endl;
    }
    else if (time == "5和6")
    {
        cout << "14:00-15:40" << endl;
    }
    else if (time == "7和8")
    {
        cout << "16:00-17:40" << endl;
    }
    else if (time == "9和10和11")
    {
        cout << "19:00-21:35" << endl;
    }
}
//教师授课信息派生类
//函数定义
void tea_course::Get_course_week_time()
{
    //打开course.txt文件并定位到该课程
    fstream course_file("course.txt", ios::in);
    if (!course_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    string temp_course_id;
    string temp;
    while (course_file >> temp_course_id)
    {
        if (temp_course_id == tea_temp_course_id)
        {
            break;
        }
        getline(course_file, temp);
    }
    //读取课程星期和节次
    course_file >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> tea_temp_course_week >> tea_temp_course_time;
    course_file.close();
}
bool tea_course::Isconflict()
{
    cout << "请输入要添加授课的课程编号:" << endl;
    cin >> tea_temp_course_id;
    //获得待操作课程星期和节次
    Get_course_week_time();
    //打开文件并判断是否冲突
    fstream tea_course_file("./tea_course/" + tea_account + ".txt", ios::in);
    if (!tea_course_file)
    {
        //如果文件不存在则新建文件
        tea_course_file.open("./tea_course/" + tea_account + ".txt", ios::out);
        tea_course_file.close();
        tea_course_file.open("./tea_course/" + tea_account + ".txt", ios::in);
        if (!tea_course_file)
        {
            cout << "文件打开失败" << endl;
            exit(1);
        }
    }
    string temp_course_id;
    string temp;
    string temp_course_week;
    string temp_course_time;
    while (tea_course_file >> temp_course_id >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp_course_week >> temp_course_time)
    {
        if (temp_course_id == tea_temp_course_id || (temp_course_week == tea_temp_course_week && temp_course_time == tea_temp_course_time))
        {
            tea_course_file.close();
            return true;
        }
    }
    tea_course_file.close();
    return false;
}
bool tea_course::Iscourse(string course_id)
{
    //打开文件
    fstream tea_course_file("./tea_course/" + tea_account + ".txt", ios::in);
    if (!tea_course_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //遍历一遍教师授课信息，如果有相同的课程编号则返回true
    string temp_course_id;
    string temp;
    while (tea_course_file >> temp_course_id)
    {
        if (temp_course_id == course_id)
        {
            tea_course_file.close();
            return true;
            break;
        }
        getline(tea_course_file, temp);
    }
    tea_course_file.close();
    return false;
}
string tea_course::Get_course(string course_week, string course_time)
{
    //打开文件
    fstream tea_course_file("./tea_course/" + tea_account + ".txt", ios::in);
    if (!tea_course_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //遍历一遍教师授课信息，如果有相同的星期和节次则return课程名字
    string temp_course_week;
    string temp_course_time;
    string temp_course_name;
    string temp;
    while (tea_course_file >> temp >> temp_course_name >> temp >> temp >> temp >> temp >> temp >> temp >> temp >> temp_course_week >> temp_course_time)
    {
        if (temp_course_week == course_week && temp_course_time == course_time)
        {
            return temp_course_name;
            break;
        }
    }
    tea_course_file.close();
    return "";
}
//功能函数定义
void tea_course::Add_tea_course()
{
    //判断tea_course文件夹是否已经创建
    fstream test1("./tea_course/test.txt", ios::out);
    if (!test1)
    {
        CreateDirectory(_T("./tea_course"), NULL);
    }
    else {
        test1.close();
        remove("./tea_course/test.txt");
    }
    //打开tea_course文件夹下的以学号为命名的选课情况文件
    fstream tea_course_file("./tea_course/" + tea_account + ".txt", ios::in | ios::out | ios::app);
    if (!tea_course_file)
    {
        //如果文件不存在则新建文件
        tea_course_file.open("./tea_course/" + tea_account + ".txt", ios::out);
        tea_course_file.close();
        tea_course_file.open("./tea_course/" + tea_account + ".txt", ios::in | ios::out | ios::app);
        if (!tea_course_file)
        {
            cout << "文件打开失败" << endl;
            exit(1);
        }
    }
    //是否冲突，不同结果进行不同操作
    if (!Isconflict())
    {
        //不冲突则从course.txt匹配对应课程并写入文件
        //打开course.txt
        fstream course_file("course.txt", ios::in);
        if (!course_file)
        {
            cout << "文件打开失败" << endl;
            exit(1);
        }
        //定位到该课程
        string temp_course_id;
        string temp;
        while (course_file >> temp_course_id)
        {
            if (temp_course_id == tea_temp_course_id)
            {
                break;
            }
            getline(course_file, temp);
        }
        //写入文件
        getline(course_file, temp);
        tea_course_file << temp_course_id << temp << endl;
        course_file.close();
        system("cls");
        cout << "添加课程成功" << endl;
        //判断course_teacher_list文件夹是否已经创建
        fstream test2("./course_teacher_list/test.txt", ios::out);
        if (!test2)
        {
            CreateDirectory(_T("./course_teacher_list"), NULL);
        }
        else {
            test2.close();
            remove("./course_teacher_list/test.txt");
        }
        //向course_teacher_list文件夹下的课程学生名单中写入工号
        //打开文件
        fstream course_teacher_list_file("./course_teacher_list/" + tea_temp_course_id + ".txt", ios::out | ios::app);
        if (!course_teacher_list_file)
        {
            cout << "文件打开失败" << endl;
            exit(1);
        }
        //写入工号
        course_teacher_list_file << tea_account << endl;
        course_teacher_list_file.close();
    }
    else {
        system("cls");
        cout << "添加课程失败，可能原因为课程重复或时间冲突" << endl;
    }
}
void tea_course::Delete_tea_course()
{
    //判断tea_course文件夹是否已经创建
    fstream test1("./tea_course/test.txt", ios::out);
    if (!test1)
    {
        CreateDirectory(_T("./tea_course"), NULL);
    }
    else {
        test1.close();
        remove("./tea_course/test.txt");
    }
    cout << "请输入要退的课程编号:" << endl;
    cin >> tea_temp_course_id;
    //是否为存在的课程，不同结果进行不同操作
    if (!Iscourse(tea_temp_course_id))
    {
        system("cls");
        cout << "退课失败，可能原因为未选该课程" << endl;
        return;
    }
    //打开文件
    fstream tea_course_file("./tea_course/" + tea_account + ".txt", ios::in | ios::out);
    if (!tea_course_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //新建一个tea_course_temp.txt用于临时保存数据
    fstream tea_course_temp_file("./tea_course/" + tea_account + "_temp.txt", ios::out);
    if (!tea_course_temp_file)
    {
        cout << "临时文件创建失败" << endl;
        exit(1);
    }
    //定位到该课程并向tea_course_temp.txt中持续写入数据,跳过写入该课程数据
    string temp_course_id;
    string temp;
    while (tea_course_file >> temp_course_id)
    {
        if (temp_course_id != tea_temp_course_id)
        {
            tea_course_temp_file << temp_course_id;
            getline(tea_course_file, temp);
            tea_course_temp_file << temp << endl;
        }
        else
        {
            getline(tea_course_file, temp);
        }
    }
    tea_course_file.close();
    tea_course_temp_file.close();
    //删除原文件
    remove(("./tea_course/" + tea_account + ".txt").c_str());
    //重命名文件
    rename(("./tea_course/" + tea_account + "_temp.txt").c_str(), ("./tea_course/" + tea_account + ".txt").c_str());
    system("cls");
    cout << "退课成功" << endl;
    //判断course_teacher_list文件夹是否已经创建
    fstream test2("./course_teacher_list/test.txt", ios::out);
    if (!test2)
    {
        CreateDirectory(_T("./course_teacher_list"), NULL);
    }
    else {
        test2.close();
        remove("./course_teacher_list/test.txt");
    }
    //删除course_teacher_list文件夹下的课程学生名单中的工号
    //打开文件
    fstream course_teacher_list_file("./course_teacher_list/" + tea_temp_course_id + ".txt", ios::in);
    if (!course_teacher_list_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //新建一个temp文本用于临时保存数据
    fstream course_teacher_list_temp_file("./course_teacher_list/" + tea_temp_course_id + "_temp.txt", ios::out);
    if (!course_teacher_list_temp_file)
    {
        cout << "临时文件创建失败" << endl;
        exit(1);
    }
    //定位到该课程并向course_teacher_list_temp.txt中持续写入数据,跳过写入该工号数据
    string temp_tea_account;
    while (course_teacher_list_file >> temp_tea_account)
    {
        if (temp_tea_account != tea_account)
        {
            course_teacher_list_temp_file << temp_tea_account << endl;
        }
    }
    course_teacher_list_file.close();
    course_teacher_list_temp_file.close();
    //删除原文件
    remove(("./course_teacher_list/" + tea_temp_course_id + ".txt").c_str());
    //重命名文件
    rename(("./course_teacher_list/" + tea_temp_course_id + "_temp.txt").c_str(), ("./course_teacher_list/" + tea_temp_course_id + ".txt").c_str());
}
void tea_course::Show_tea_course()
{
    //打开文件
    fstream tea_course_file("./tea_course/" + tea_account + ".txt", ios::in);
    if (!tea_course_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //显示课表

    tea_course_file.close();
}
void tea_course::Show_next_course()
{
    //获取当前时间
    time_t now_time = time(NULL);
    //转换为本地时间
    tm local_time;
    localtime_s(&local_time, &now_time);
    //string类型存储当前时间
    string week;
    string time;
    if (local_time.tm_hour < 8)
    {
        time = "1和2";
    }
    else if (local_time.tm_hour < 10)
    {
        time = "3和4";
    }
    else if (local_time.tm_hour < 14)
    {
        time = "5和6";
    }
    else if (local_time.tm_hour < 16)
    {
        time = "7和8";
    }
    else if (local_time.tm_hour < 19)
    {
        time = "9和10和11";
    }
    else
    {
        cout << "今天已经没有课了，睡个好觉吧" << endl;
        return;
    }
    switch (local_time.tm_wday)
    {
    case 0:
        week = "星期日";
        break;
    case 1:
        week = "星期一";
        break;
    case 2:
        week = "星期二";
        break;
    case 3:
        week = "星期三";
        break;
    case 4:
        week = "星期四";
        break;
    case 5:
        week = "星期五";
        break;
    case 6:
        week = "星期六";
        break;
    }
    //调用函数获得课程名字
    string name = Get_course(week, time);
    //输出下一节课的时间和名称
    cout << "下一节课为:" << name << endl;
    cout << "时间为:";
    if (time == "1和2")
    {
        cout << "8:00-9:40" << endl;
    }
    else if (time == "3和4")
    {
        cout << "10:00-11:40" << endl;
    }
    else if (time == "5和6")
    {
        cout << "14:00-15:40" << endl;
    }
    else if (time == "7和8")
    {
        cout << "16:00-17:40" << endl;
    }
    else if (time == "9和10和11")
    {
        cout << "19:00-21:35" << endl;
    }
}

//学生派生类
//学号（账号） 密码 姓名 年级 学院 专业 班级
//函数定义
bool student::Isright()
{
    //打开文件
    fstream stu_file("student.txt", ios::in);
    if (!stu_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    string account;
    string password;
    //不读取第一行作为信息
    string temp;
    getline(stu_file, temp);
    //读取账号密码并判断
    while (stu_file >> account >> password)
    {
        getline(stu_file, temp);//除了账号和密码以外的信息都去除
        if (account == this->account && password == this->password)
        {
            stu_file.close();
            return true;
        }
    }
    stu_file.close();
    return false;
}
void student::Read_stu_information()
{
    //打开文件
    fstream stu_file("student.txt", ios::in);
    if (!stu_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //不读取第一行作为信息
    string temp;
    getline(stu_file, temp);
    //定位到该学生
    string account;
    while (stu_file >> account)
    {
        if (account == this->account)
        {
            break;
        }
        getline(stu_file, temp);
    }
    //从文本中读取信息到对象中
    stu_file >> this->password >> this->name >> this->stu_class >> this->stu_grade >> this->stu_college >> this->stu_profession;
    stu_file.close();
}
bool student::Login()
{
    if (this->Isright())
    {
        system("cls");
        cout << "登录成功" << endl;
        this->Read_stu_information();
        return true;
    }
    else
    {
        system("cls");
        cout << "账号或密码错误，请重新输入" << endl;
        return false;
    }
}
//功能函数定义
void student::Change_password()
{
    cout << "请输入新密码:" << endl;
    string new_password;
    cin >> new_password;
    //打开文件
    fstream stu_file("student.txt", ios::in | ios::out);
    if (!stu_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //不读取第一行作为信息
    string temp;
    getline(stu_file, temp);
    //新建一个stu_temp.txt用于临时保存数据
    fstream stu_temp_file("stu_temp.txt", ios::out);
    if (!stu_temp_file)
    {
        cout << "临时文件创建失败" << endl;
        exit(1);
    }
    //提取第一行到stu_temp.txt中
    stu_temp_file << temp << endl;
    //定位到该学生并向stu_temp.txt中持续写入数据,覆写该学生的密码
    string temp_account;
    while (stu_file >> temp_account)
    {
        if (temp_account != account)
        {
            stu_temp_file << temp_account;
            getline(stu_file, temp);
            stu_temp_file << temp << endl;
        }
        else
        {
            //覆写密码
            stu_temp_file << temp_account << " " << new_password << " ";
            getline(stu_file, temp, ' ');
            getline(stu_file, temp, ' ');
            getline(stu_file, temp);
            stu_temp_file << temp << endl;
        }
    }
    stu_file.close();
    stu_temp_file.close();
    //删除原文件
    remove("student.txt");
    //重命名文件
    rename("stu_temp.txt", "student.txt");
    system("cls");
    cout << "修改成功" << endl;
}
void student::Show_stu_information()
{
    cout << "学号:" << this->account << endl;//学号不可修改
    cout << "姓名:" << this->name << endl;
    cout << "年级:" << this->stu_grade << endl;
    cout << "学院:" << this->stu_college << endl;
    cout << "专业:" << this->stu_profession << endl;
    cout << "班级:" << this->stu_class << endl;
    cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl;
    system("pause");
}
void student::Course_search()
{
    course::Search_course_information();
    cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl;
    system("pause");
}
void student::Choose_course()
{
    //创建一个临时对象用于选课
    stu_course stu_course_temp("", "", "", "", "", "", "", "", "", "", "", account, "", "", "");
    stu_course_temp.Choose_course();
}
void student::Drop_course()
{
    //创建一个临时对象用于退课
    stu_course stu_course_temp("", "", "", "", "", "", "", "", "", "", "", account, "", "", "");
    stu_course_temp.Drop_course();
}
void student::Show_course()
{
    //创建一个临时对象用于显示课表
    stu_course stu_course_temp("", "", "", "", "", "", "", "", "", "", "", account, "", "", "");
    stu_course_temp.Show_course();
    cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl;
    system("pause");
}
void student::Show_next_course()
{
    //创建一个临时对象用于显示下一节课的时间和名称
    stu_course stu_course_temp("", "", "", "", "", "", "", "", "", "", "", account, "", "", "");
    stu_course_temp.Show_next_course();
    cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl;
    system("pause");
}
//教师派生类
//工号（账号） 密码 姓名 学院
//函数定义
bool teacher::Isright()
{
    //打开文件
    fstream tea_file("teacher.txt", ios::in);
    if (!tea_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    string account;
    string password;
    //不读取第一行作为信息
    string temp;
    getline(tea_file, temp);
    //读取账号密码并判断
    while (tea_file >> account >> password)
    {
        getline(tea_file, temp);//除了账号和密码以外的信息都去除
        if (account == this->account && password == this->password)
        {
            tea_file.close();
            return true;
        }
    }
    tea_file.close();
    return false;
}
void teacher::Read_tea_information()
{
    //打开文件
    fstream tea_file("teacher.txt", ios::in);
    if (!tea_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //不读取第一行作为信息
    string temp;
    getline(tea_file, temp);
    //定位到该教师
    string account;
    while (tea_file >> account)
    {
        if (account == this->account)
        {
            break;
        }
        getline(tea_file, temp);
    }
    //从文本中读取信息到对象中
    tea_file >> this->password >> this->name >> this->tea_college;
    tea_file.close();
}
bool teacher::Login()
{
    if (this->Isright())
    {
        system("cls");
        cout << "登录成功" << endl;
        this->Read_tea_information();
        return true;
    }
    else
    {
        system("cls");
        cout << "账号或密码错误，请重新登录" << endl;
        return false;
    }
}
string teacher::Get_stu_name(string stu_account)
{
    //打开文件
    fstream stu_file("student.txt", ios::in);
    if (!stu_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //定位到该学生
    string account;
    string name;
    while (stu_file >> account >> name)
    {
        if (account == stu_account)
        {
            break;
        }
        getline(stu_file, name);
    }
    stu_file.close();
    return name;
}
//功能函数定义
void teacher::Change_password()
{
    cout << "请输入新密码:" << endl;
    string new_password;
    cin >> new_password;
    //打开文件
    fstream tea_file("teacher.txt", ios::in | ios::out);
    if (!tea_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //不读取第一行作为信息
    string temp;
    getline(tea_file, temp);
    //新建一个tea_temp.txt用于临时保存数据
    fstream tea_temp_file("tea_temp.txt", ios::out);
    if (!tea_temp_file)
    {
        cout << "临时文件创建失败" << endl;
        exit(1);
    }
    //提取第一行到tea_temp.txt中
    tea_temp_file << temp << endl;
    //定位到该教师并向tea_temp.txt中持续写入数据,覆写该教师的密码
    string temp_account;
    while (tea_file >> temp_account)
    {
        if (temp_account != account)
        {
            tea_temp_file << temp_account;
            getline(tea_file, temp);
            tea_temp_file << temp << endl;
        }
        else
        {
            //覆写密码
            tea_temp_file << temp_account << " " << new_password << " ";
            getline(tea_file, temp, ' ');
            getline(tea_file, temp, ' ');
            getline(tea_file, temp);
            tea_temp_file << temp << endl;
        }
    }
    tea_file.close();
    tea_temp_file.close();
    //删除原文件
    remove("teacher.txt");
    //重命名文件
    rename("tea_temp.txt", "teacher.txt");
    system("cls");
    cout << "修改成功" << endl;
}
void teacher::Show_tea_information()
{
    cout << "工号:" << this->account << endl;//工号不可修改
    cout << "姓名:" << this->name << endl;
    cout << "学院:" << this->tea_college << endl;
    cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl;
    system("pause");
}
void teacher::Course_search()
{
    course::Search_course_information();
    cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl;
    system("pause");
}
void teacher::Show_course()
{
    //创建一个临时对象用于显示课表
    tea_course tea_course_temp("", "", "", "", "", "", "", "", "", "", "", account, "", "", "");
    tea_course_temp.Show_tea_course();
    cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl;
    system("pause");
}
void teacher::Show_stu_list()
{
    //打开tea_course文件夹下的以工号为命名的选课情况文件
    fstream tea_course_file("./tea_course/" + account + ".txt", ios::in);
    if (!tea_course_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //显示所授课课程和学生名单
    string temp_course_id;
    string temp_course_name;
    string temp;
    while (tea_course_file >> temp_course_id >> temp_course_name)
    {
        //删除多余信息
        getline(tea_course_file, temp);
        //打开course_student_list文件夹下的课程学生名单
        fstream course_student_list_file("./course_student_list/" + temp_course_id + ".txt", ios::in);
        if (!course_student_list_file)
        {
            cout << "文件打开失败" << endl;
            exit(1);
        }
        //显示课程编号和名字
        cout << "课程编号:" << temp_course_id << "\t";
        cout << "课程名字:" << temp_course_name << endl;
        //显示学生名单
        while (getline(course_student_list_file, temp))
        {
            cout << "学生学号:" << temp << "\t";
            cout << "学生姓名:" << Get_stu_name(temp) << endl;
        }
        course_student_list_file.close();
    }
    tea_course_file.close();
    cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl;
    system("pause");
}
void teacher::Show_next_course()
{
    //创建一个临时对象用于显示下一节课的时间和名称
    tea_course tea_course_temp("", "", "", "", "", "", "", "", "", "", "", account, "", "", "");
    tea_course_temp.Show_next_course();
    cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl;
    system("pause");
}
//管理员派生类
//账号 密码 姓名
//函数定义
bool admin::Isright()
{
    //打开文件
    fstream admin_file("admin.txt", ios::in);
    if (!admin_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    string account;
    string password;
    //不读取第一行作为信息
    string temp;
    getline(admin_file, temp);
    //读取账号密码并判断
    while (admin_file >> account >> password)
    {
        getline(admin_file, temp);//除了账号和密码以外的信息都去除
        if (account == this->account && password == this->password)
        {
            admin_file.close();
            return true;
        }
    }
    admin_file.close();
    return false;
}
void admin::Read_admin_information()
{
    //打开文件
    fstream admin_file("admin.txt", ios::in);
    if (!admin_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //不读取第一行作为信息
    string temp;
    getline(admin_file, temp);
    //定位到该管理员
    string account;
    while (admin_file >> account)
    {
        if (account == this->account)
        {
            break;
        }
        getline(admin_file, temp);
    }
    //从文本中读取信息到对象中
    admin_file >> this->password >> this->name;
    admin_file.close();
}
bool admin::Login()
{
    if (this->Isright())
    {
        system("cls");
        cout << "登录成功" << endl;
        this->Read_admin_information();
        return true;
    }
    else
    {
        system("cls");
        cout << "账号或密码错误" << endl;
        return false;
    }
}
void admin::access_private_tea_course(tea_course& tea_course_temp)
{
    tea_course_temp.Add_tea_course();
}
void admin::access_private_tea_course1(tea_course& tea_course_temp)
{
    tea_course_temp.Delete_tea_course();
}
bool admin::Is_stu_exist(string stu_account)
{
    //打开文件
    fstream stu_file("student.txt", ios::in);
    if (!stu_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    string account;
    //不读取第一行作为信息
    string temp;
    getline(stu_file, temp);
    //读取账号并判断
    while (stu_file >> account)
    {
        getline(stu_file, temp);//除了账号以外的信息都去除
        if (account == stu_account)
        {
            stu_file.close();
            return true;
        }
    }
    stu_file.close();
    return false;
}
bool admin::Is_tea_exist(string tea_account)
{
    //打开文件
    fstream tea_file("teacher.txt", ios::in);
    if (!tea_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    string account;
    //不读取第一行作为信息
    string temp;
    getline(tea_file, temp);
    //读取账号并判断
    while (tea_file >> account)
    {
        getline(tea_file, temp);//除了账号以外的信息都去除
        if (account == tea_account)
        {
            tea_file.close();
            return true;
        }
    }
    tea_file.close();
    return false;
}
bool admin::Is_course_exist(string course_id)
{
    //打开文件
    fstream course_file("course.txt", ios::in);
    if (!course_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    string temp_course_id;
    //不读取第一行作为信息
    string temp;
    getline(course_file, temp);
    //读取课程编号并判断
    while (course_file >> temp_course_id)
    {
        getline(course_file, temp);//除了课程编号以外的信息都去除
        if (temp_course_id == course_id)
        {
            course_file.close();
            return true;
        }
    }
    course_file.close();
    return false;
}
string admin::Get_stu_name(string stu_account)
{
    //打开文件
    fstream stu_file("student.txt", ios::in);
    if (!stu_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    string account;
    string name;
    //不读取第一行作为信息
    string temp;
    getline(stu_file, temp);
    //读取账号并判断
    while (stu_file >> account >> temp >> name)
    {
        getline(stu_file, temp);//除了账号和姓名以外的信息都去除
        if (account == stu_account)
        {
            stu_file.close();
            return name;
        }
    }
    stu_file.close();
    return "";
}
string admin::Get_tea_name(string tea_account)
{
    //打开文件
    fstream tea_file("teacher.txt", ios::in);
    if (!tea_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    string account;
    string name;
    //不读取第一行作为信息
    string temp;
    getline(tea_file, temp);
    //读取账号并判断
    while (tea_file >> account >> temp >> name)
    {
        getline(tea_file, temp);//除了账号和姓名以外的信息都去除
        if (account == tea_account)
        {
            tea_file.close();
            return name;
        }
    }
    tea_file.close();
    return "";
}
//功能函数定义
void admin::Change_password()
{
    cout << "请输入您的新密码:" << endl;
    string new_password;
    cin >> new_password;
    //打开文件
    fstream admin_file("admin.txt", ios::in | ios::out);
    if (!admin_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //不读取第一行作为信息
    string temp;
    getline(admin_file, temp);
    //新建一个admin_temp.txt用于临时保存数据
    fstream admin_temp_file("admin_temp.txt", ios::out);
    if (!admin_temp_file)
    {
        cout << "临时文件创建失败" << endl;
        exit(1);
    }
    //提取第一行到admin_temp.txt中
    admin_temp_file << temp << endl;
    //定位到该管理员并向admin_temp.txt中持续写入数据,覆写该管理员的密码
    string temp_account;
    while (admin_file >> temp_account)
    {
        if (temp_account != account)
        {
            admin_temp_file << temp_account;
            getline(admin_file, temp);
            admin_temp_file << temp << endl;
        }
        else
        {
            //覆写密码
            admin_temp_file << temp_account << " " << new_password << " ";
            getline(admin_file, temp, ' ');
            getline(admin_file, temp, ' ');
            getline(admin_file, temp);
            admin_temp_file << temp << endl;
        }
    }
    admin_file.close();
    admin_temp_file.close();
    //删除原文件
    remove("admin.txt");
    //重命名文件
    rename("admin_temp.txt", "admin.txt");
    system("cls");
    cout << "修改成功" << endl;
}
void admin::Show_admin_information()
{
    cout << "账号:" << this->account << endl;//账号不可修改
    cout << "姓名:" << this->name << endl;
    cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl;
    system("pause");
}
void admin::Add_stu_information()
{
    cout << "请输入学生信息:" << endl;
    cout << "(默认密码为123456)" << endl;
    cout << "学号:" << endl;
    cin >> temp_accountORcourseid_class;
    //判断学号是否已经重复
    if (Is_stu_exist(temp_accountORcourseid_class))
    {
        system("cls");
        cout << "添加失败，学号重复" << endl;
        return;
    }
    //重命名student.txt为stu_temp.txt
    rename("student.txt", "stu_temp.txt");
    //新建一个student.txt用于保存数据
    fstream stu_file("student.txt", ios::out);
    if (!stu_file)
    {
        cout << "文件创建失败" << endl;
        exit(1);
    }
    //读取stu_temp.txt中的数据
    fstream stu_temp_file("stu_temp.txt", ios::in);
    if (!stu_temp_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //不读取第一行作为信息
    string temp;
    getline(stu_temp_file, temp);
    //写入第一行到student.txt中
    stu_file << temp << endl;
    //持续读取stu_temp.txt的数据如果学号小于temp_account_class则直接写入student.txt中
    string temp_account;
    while (stu_temp_file >> temp_account)
    {
        if (temp_account < temp_accountORcourseid_class)
        {
            stu_file << temp_account;
            getline(stu_temp_file, temp);
            stu_file << temp << endl;
        }
        else
        {
            stu_temp_file.seekg(-static_cast<int>(temp_account.length()), ios::cur);
            break;
        }
    }
    //写入新添加的学生信息
    cout << "姓名:" << endl;
    string name;
    cin >> name;
    cout << "年级:" << endl;
    string stu_grade;
    cin >> stu_grade;
    cout << "学院:" << endl;
    string stu_college;
    cin >> stu_college;
    cout << "专业:" << endl;
    string stu_profession;
    cin >> stu_profession;
    cout << "班级:" << endl;
    string stu_class;
    cin >> stu_class;
    //写入文件
    stu_file << temp_accountORcourseid_class << " 123456 " << name << " " << stu_class << " " << stu_grade << " " << stu_college << " " << stu_profession << endl;
    //继续添加剩余的学生信息
    while (stu_temp_file >> temp_account)
    {
        stu_file << temp_account;
        getline(stu_temp_file, temp);
        stu_file << temp << endl;
    }
    stu_file.close();
    stu_temp_file.close();
    //删除stu_temp.txt
    remove("stu_temp.txt");
    system("cls");
    cout << "添加成功" << endl;
}
void admin::Delete_stu_information()
{
    cout << "请输入要删除的学生学号:" << endl;
    cin >> temp_accountORcourseid_class;
    //判断学生是否存在
    if (!Is_stu_exist(temp_accountORcourseid_class))
    {
        system("cls");
        cout << "删除失败，该学号不存在" << endl;
        return;
    }
    //打开文件
    fstream stu_file("student.txt", ios::in | ios::out);
    if (!stu_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //不读取第一行作为信息
    string temp;
    getline(stu_file, temp);
    //新建一个stu_temp.txt用于临时保存数据
    fstream stu_temp_file("stu_temp.txt", ios::out);
    if (!stu_temp_file)
    {
        cout << "临时文件创建失败" << endl;
        exit(1);
    }
    //提取第一行到stu_temp.txt中
    stu_temp_file << temp << endl;
    //定位到该学生并向stu_temp.txt中持续写入数据,跳过写入该学生数据
    string temp_account;
    while (stu_file >> temp_account)
    {
        if (temp_account != temp_accountORcourseid_class)
        {
            stu_temp_file << temp_account;
            getline(stu_file, temp);
            stu_temp_file << temp << endl;
        }
        else
        {
            getline(stu_file, temp);
        }
    }
    stu_file.close();
    stu_temp_file.close();
    //删除原文件
    remove("student.txt");
    //重命名文件
    rename("stu_temp.txt", "student.txt");
    system("cls");
    cout << "删除成功" << endl;
}
void admin::Change_stu_password()
{
    cout << "请输入要修改密码的学生学号:" << endl;
    cin >> temp_accountORcourseid_class;
    //判断学生是否存在
    if (!Is_stu_exist(temp_accountORcourseid_class))
    {
        system("cls");
        cout << "修改失败，该学号不存在" << endl;
        return;
    }
    student stu(temp_accountORcourseid_class, "", "", "", "", "", "");
    stu.Change_password();
}
void admin::Add_tea_information()
{
    cout << "请输入教师信息:" << endl;
    cout << "(默认密码为123456)" << endl;
    cout << "工号:" << endl;
    cin >> temp_accountORcourseid_class;
    //判断工号是否已经重复
    if (Is_tea_exist(temp_accountORcourseid_class))
    {
        system("cls");
        cout << "添加失败，工号重复" << endl;
        return;
    }
    //重命名teacher.txt为tea_temp.txt
    rename("teacher.txt", "tea_temp.txt");
    //新建一个teacher.txt用于保存数据
    fstream tea_file("teacher.txt", ios::out);
    if (!tea_file)
    {
        cout << "文件创建失败" << endl;
        exit(1);
    }
    //读取tea_temp.txt中的数据
    fstream tea_temp_file("tea_temp.txt", ios::in);
    if (!tea_temp_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //不读取第一行作为信息
    string temp;
    getline(tea_temp_file, temp);
    //写入第一行到teacher.txt中
    tea_file << temp << endl;
    //持续读取tea_temp.txt的数据如果工号小于temp_account_class则直接写入teacher.txt中
    string temp_account;
    while (tea_temp_file >> temp_account)
    {
        if (temp_account < temp_accountORcourseid_class)
        {
            tea_file << temp_account;
            getline(tea_temp_file, temp);
            tea_file << temp << endl;
        }
        else
        {
            tea_temp_file.seekg(-static_cast<int>(temp_account.length()), ios::cur);
            break;
        }
    }
    //写入新添加的教师信息
    cout << "姓名:" << endl;
    string name;
    cin >> name;
    cout << "学院:" << endl;
    string tea_college;
    cin >> tea_college;
    //写入文件
    tea_file << temp_accountORcourseid_class << " 123456 " << name << " " << tea_college << endl;
    //继续添加剩余的教师信息
    while (tea_temp_file >> temp_account)
    {
        tea_file << temp_account;
        getline(tea_temp_file, temp);
        tea_file << temp << endl;
    }
    tea_file.close();
    tea_temp_file.close();
    //删除tea_temp.txt
    remove("tea_temp.txt");
    system("cls");
    cout << "添加成功" << endl;
}
void admin::Delete_tea_information()
{
    cout << "请输入要删除的教师工号:" << endl;
    cin >> temp_accountORcourseid_class;
    //判断教师是否存在
    if (!Is_tea_exist(temp_accountORcourseid_class))
    {
        system("cls");
        cout << "删除失败，该工号不存在" << endl;
        return;
    }
    //打开文件
    fstream tea_file("teacher.txt", ios::in | ios::out);
    if (!tea_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //不读取第一行作为信息
    string temp;
    getline(tea_file, temp);
    //新建一个tea_temp.txt用于临时保存数据
    fstream tea_temp_file("tea_temp.txt", ios::out);
    if (!tea_temp_file)
    {
        cout << "临时文件创建失败" << endl;
        exit(1);
    }
    //提取第一行到tea_temp.txt中
    tea_temp_file << temp << endl;
    //定位到该教师并向tea_temp.txt中持续写入数据,跳过写入该教师数据
    string temp_account;
    while (tea_file >> temp_account)
    {
        if (temp_account != temp_accountORcourseid_class)
        {
            tea_temp_file << temp_account;
            getline(tea_file, temp);
            tea_temp_file << temp << endl;
        }
        else
        {
            getline(tea_file, temp);
        }
    }
    tea_file.close();
    tea_temp_file.close();
    //删除原文件
    remove("teacher.txt");
    //重命名文件
    rename("tea_temp.txt", "teacher.txt");
    system("cls");
    cout << "删除成功" << endl;
}
void admin::Change_tea_password()
{
    cout << "请输入要修改密码的教师工号:" << endl;
    cin >> temp_accountORcourseid_class;
    //判断教师是否存在
    if (!Is_tea_exist(temp_accountORcourseid_class))
    {
        system("cls");
        cout << "修改失败，该工号不存在" << endl;
        return;
    }
    teacher tea(temp_accountORcourseid_class, "", "", "");
    tea.Change_password();
}
void admin::Add_course_information()
{
    cout << "请输入课程信息:" << endl;
    cout << "课程编号:" << endl;
    cin >> temp_accountORcourseid_class;
    //判断课程是否已经重复
    if (Is_course_exist(temp_accountORcourseid_class))
    {
        system("cls");
        cout << "添加失败，课程编号重复" << endl;
        return;
    }
    //重命名course.txt为course_temp.txt
    rename("course.txt", "course_temp.txt");
    //新建一个course.txt用于保存数据
    fstream course_file("course.txt", ios::out);
    if (!course_file)
    {
        cout << "文件创建失败" << endl;
        exit(1);
    }
    //读取course_temp.txt中的数据
    fstream course_temp_file("course_temp.txt", ios::in);
    if (!course_temp_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //不读取第一行作为信息
    string temp;
    getline(course_temp_file, temp);
    //写入第一行到course.txt中
    course_file << temp << endl;
    //持续读取course_temp.txt的数据如果课程编号小于temp_account_class则直接写入course.txt中
    string temp_course_id;
    while (course_temp_file >> temp_course_id)
    {
        if (temp_course_id < temp_accountORcourseid_class)
        {
            course_file << temp_course_id;
            getline(course_temp_file, temp);
            course_file << temp << endl;
        }
        else
        {
            course_temp_file.seekg(-static_cast<int>(temp_course_id.length()), ios::cur);
            break;
        }
    }
    //写入新添加的课程信息
    cout << "课程名称:" << endl;
    string course_name;
    cin >> course_name;
    cout << "年级:" << endl;
    string course_grade;
    cin >> course_grade;
    cout << "学院:" << endl;
    string course_college;
    cin >> course_college;
    cout << "专业:" << endl;
    string course_profession;
    cin >> course_profession;
    cout << "开课学院:" << endl;
    string course_college_open;
    cin >> course_college_open;
    cout << "课程类别:" << endl;
    string course_type;
    cin >> course_type;
    cout << "课程性质:" << endl;
    string course_nature;
    cin >> course_nature;
    cout << "课程归属:" << endl;
    string course_belong;
    cin >> course_belong;
    cout << "上课星期:" << endl;
    string course_week;
    cin >> course_week;
    cout << "上课节次:" << endl;
    string course_time;
    cin >> course_time;
    //写入文件
    course_file << temp_accountORcourseid_class << " " << course_name << " " << course_grade << " " << course_college << " " << course_profession << " " << course_college_open << " " << course_type << " " << course_nature << " " << course_belong << " " << course_week << " " << course_time << endl;
    //继续添加剩余的课程信息
    while (course_temp_file >> temp_course_id)
    {
        course_file << temp_course_id;
        getline(course_temp_file, temp);
        course_file << temp << endl;
    }
    course_file.close();
    course_temp_file.close();
    //删除course_temp.txt
    remove("course_temp.txt");
    system("cls");
    cout << "添加成功" << endl;
}
void admin::Delete_course_information()
{
    cout << "请输入要删除的课程编号:" << endl;
    cin >> temp_accountORcourseid_class;
    //判断课程是否存在
    if (!Is_course_exist(temp_accountORcourseid_class))
    {
        system("cls");
        cout << "删除失败，该课程编号不存在" << endl;
        return;
    }
    //打开文件
    fstream course_file("course.txt", ios::in | ios::out);
    if (!course_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //不读取第一行作为信息
    string temp;
    getline(course_file, temp);
    //新建一个course_temp.txt用于临时保存数据
    fstream course_temp_file("course_temp.txt", ios::out);
    if (!course_temp_file)
    {
        cout << "临时文件创建失败" << endl;
        exit(1);
    }
    //提取第一行到course_temp.txt中
    course_temp_file << temp << endl;
    //定位到该课程并向course_temp.txt中持续写入数据,跳过写入该课程数据
    string temp_course_id;
    while (course_file >> temp_course_id)
    {
        if (temp_course_id != temp_accountORcourseid_class)
        {
            course_temp_file << temp_course_id;
            getline(course_file, temp);
            course_temp_file << temp << endl;
        }
        else
        {
            getline(course_file, temp);
        }
    }
    course_file.close();
    course_temp_file.close();
    //删除原文件
    remove("course.txt");
    //重命名文件
    rename("course_temp.txt", "course.txt");
    system("cls");
    cout << "删除成功" << endl;
}
void admin::Search_course_information()
{
    course::Search_course_information();
    cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl;
    system("pause");
}
void admin::Search_stu_information()
{
    cout << "请输入要查询的学生学号:" << endl;
    cin >> temp_accountORcourseid_class;
    //判断学生是否存在
    if (!Is_stu_exist(temp_accountORcourseid_class))
    {
        system("cls");
        cout << "查询失败，该学号不存在" << endl;
        return;
    }
    //打开文件
    fstream stu_file("student.txt", ios::in);
    if (!stu_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //不读取第一行作为信息
    string temp;
    getline(stu_file, temp);
    //定位到该学生
    string temp_account;
    while (stu_file >> temp_account)
    {
        if (temp_account == temp_accountORcourseid_class)
        {
            break;
        }
        getline(stu_file, temp);
    }
    //从文本中读取信息到对象中
    string password;
    string name;
    string stu_class;
    string stu_grade;
    string stu_college;
    string stu_profession;
    stu_file >> password >> name >> stu_class >> stu_grade >> stu_college >> stu_profession;
    stu_file.close();
    system("cls");
    cout << "查询成功:" << endl;
    //创建一个临时对象用于显示学生信息
    student stu(temp_accountORcourseid_class, password, name, stu_class, stu_grade, stu_college, stu_profession);
    stu.Show_stu_information();
}
void admin::Search_tea_information()
{
    cout << "请输入要查询的教师工号:" << endl;
    cin >> temp_accountORcourseid_class;
    //判断教师是否存在
    if (!Is_tea_exist(temp_accountORcourseid_class))
    {
        system("cls");
        cout << "查询失败，该工号不存在" << endl;
        return;
    }
    //打开文件
    fstream tea_file("teacher.txt", ios::in);
    if (!tea_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //不读取第一行作为信息
    string temp;
    getline(tea_file, temp);
    //定位到该教师
    string temp_account;
    while (tea_file >> temp_account)
    {
        if (temp_account == temp_accountORcourseid_class)
        {
            break;
        }
        getline(tea_file, temp);
    }
    //从文本中读取信息到对象中
    string password;
    string name;
    string tea_college;
    tea_file >> password >> name >> tea_college;
    tea_file.close();
    system("cls");
    cout << "查询成功:" << endl;
    //创建一个临时对象用于显示教师信息
    teacher tea(temp_accountORcourseid_class, password, name, tea_college);
    tea.Show_tea_information();
}
void admin::Search_stu_course_information()
{
    cout << "请输入要查询的学生学号:" << endl;
    cin >> temp_accountORcourseid_class;
    //判断学生是否存在
    if (!Is_stu_exist(temp_accountORcourseid_class))
    {
        system("cls");
        cout << "查询失败，该学号不存在" << endl;
        return;
    }
    system("cls");
    cout << "查询成功:" << endl;
    //创建一个临时对象用于显示课表
    stu_course stu_course_temp("", "", "", "", "", "", "", "", "", "", "", temp_accountORcourseid_class, "", "", "");
    stu_course_temp.Show_course();
}
void admin::Search_tea_course_information()
{
    cout << "请输入要查询的教师工号:" << endl;
    cin >> temp_accountORcourseid_class;
    //判断教师是否存在
    if (!Is_tea_exist(temp_accountORcourseid_class))
    {
        system("cls");
        cout << "查询失败，该工号不存在" << endl;
        return;
    }
    system("cls");
    cout << "查询成功:" << endl;
    //创建一个临时对象用于显示课表
    tea_course tea_course_temp("", "", "", "", "", "", "", "", "", "", "", temp_accountORcourseid_class, "", "", "");
    tea_course_temp.Show_tea_course();
}
void admin::Add_stu_course()
{
    cout << "请输入要添加课程的学生学号:" << endl;
    cin >> temp_accountORcourseid_class;
    //判断学生是否存在
    if (!Is_stu_exist(temp_accountORcourseid_class))
    {
        system("cls");
        cout << "添加失败，该学号不存在" << endl;
        return;
    }
    //创建一个临时对象用于选课
    stu_course stu_course_temp("", "", "", "", "", "", "", "", "", "", "", temp_accountORcourseid_class, "", "", "");
    stu_course_temp.Choose_course();
}
void admin::Delete_stu_course()
{
    cout << "请输入要删除课程的学生学号:" << endl;
    cin >> temp_accountORcourseid_class;
    //判断学生是否存在
    if (!Is_stu_exist(temp_accountORcourseid_class))
    {
        system("cls");
        cout << "删除失败，该学号不存在" << endl;
        return;
    }
    //创建一个临时对象用于退课
    stu_course stu_course_temp("", "", "", "", "", "", "", "", "", "", "", temp_accountORcourseid_class, "", "", "");
    stu_course_temp.Drop_course();
}
void admin::Add_tea_course()
{
    cout << "请输入要添加课程的教师工号:" << endl;
    cin >> temp_accountORcourseid_class;
    //判断教师是否存在
    if (!Is_tea_exist(temp_accountORcourseid_class))
    {
        system("cls");
        cout << "添加失败，该工号不存在" << endl;
        return;
    }
    //创建一个临时对象用于添加课程
    tea_course tea_course_temp("", "", "", "", "", "", "", "", "", "", "", temp_accountORcourseid_class, "", "", "");
    access_private_tea_course(tea_course_temp);
}
void admin::Delete_tea_course()
{
    cout << "请输入要删除课程的教师工号:" << endl;
    cin >> temp_accountORcourseid_class;
    //判断教师是否存在
    if (!Is_tea_exist(temp_accountORcourseid_class))
    {
        system("cls");
        cout << "删除失败，该工号不存在" << endl;
        return;
    }
    //创建一个临时对象用于删除课程
    tea_course tea_course_temp("", "", "", "", "", "", "", "", "", "", "", temp_accountORcourseid_class, "", "", "");
    access_private_tea_course1(tea_course_temp);
}
void admin::Search_course_tea_stu_information()
{
    cout << "请输入要查询的课程编号:" << endl;
    cin >> temp_accountORcourseid_class;
    //判断课程是否存在
    if (!Is_course_exist(temp_accountORcourseid_class))
    {
        system("cls");
        cout << "查询失败，该课程编号不存在" << endl;
        return;
    }
    //打开course_teacher_list文件夹下的课程文件
    fstream course_tea_list_file("./course_teacher_list/" + temp_accountORcourseid_class + ".txt", ios::in);
    //打开course_student_list文件夹下的课程文件
    fstream course_stu_list_file("./course_student_list/" + temp_accountORcourseid_class + ".txt", ios::in);
    string temp;
    //读取教师名单
    cout << "教师名单:" << endl;
    while (getline(course_tea_list_file, temp))
    {
        cout << "工号:" << temp << "\t";
        cout << "姓名:" << Get_tea_name(temp) << endl;
    }
    //读取学生名单
    cout << "学生名单:" << endl;
    while (getline(course_stu_list_file, temp))
    {
        cout << "学号:" << temp << "\t";
        cout << "姓名:" << Get_stu_name(temp) << endl;
    }
    course_tea_list_file.close();
    course_stu_list_file.close();
    cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl;
    system("pause");
}
