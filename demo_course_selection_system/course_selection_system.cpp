#include <windows.h>
#include <tchar.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "course_selection_system.h"
#include "console_list.h"
using namespace std;

//课程信息类
//编号 名称 年级 学院 专业 开课学院 课程类别 课程性质 课程归属 上课星期 上课节次
//功能函数定义
void course::Search_course_information()
{
    system("cls");
    Col(3); cout << "请依次输入筛选条件:" << endl << "(不进行筛选的条件请输入0或不选择)" << endl;
    cout << "编号:"; 
    string course_id;
    Col(7); cin >> course_id;
    Col(3); cout << "名称:";
    string course_name;
    Col(7); cin >> course_name;
    Col(3); cout << "年级:";
    string course_grade;
    Col(7); cin >> course_grade;
    Col(3); cout << "学院:(请选择)"; Col(0);
    cout << endl << endl << endl;
    system("pause");
    string course_college;
    course_college = course_college_menu();
    system("cls");
    Col(3); cout << "请依次输入筛选条件:" << endl << "(不进行筛选的条件请输入0或不选择)" << endl;
    cout << "编号:" << course_id << endl;
    cout << "名称:" << course_name << endl;
    cout << "年级:" << course_grade << endl;
    cout << "学院:" << course_college << endl; Col(0);
    string course_profession;
    if (course_college != "0")
    {
        Col(3); cout << "专业:(请选择)"; Col(0);
        cout << endl << endl << endl;
        system("pause");
        if (course_college == "药学院") {
            course_profession = course1_profession_menu();
        }
        else if (course_college == "医学院") {
            course_profession = course2_profession_menu();
        }
        else if (course_college == "法学院") {
            course_profession = course3_profession_menu();
        }
        else if (course_college == "文学院") {
            course_profession = course4_profession_menu();
        }
        else if (course_college == "财经学院") {
            course_profession = course5_profession_menu();
        }
        else if (course_college == "管理学院") {
            course_profession = course6_profession_menu();
        }
        else if (course_college == "艺术学院") {
            course_profession = course7_profession_menu();
        }
        else if (course_college == "外国语学院") {
            course_profession = course8_profession_menu();
        }
        else if (course_college == "知识产权学院") {
            course_profession = course9_profession_menu();
        }
        else if (course_college == "化学化工学院") {
            course_profession = course10_profession_menu();
        }
        else if (course_college == "机械工程学院") {
            course_profession = course11_profession_menu();
        }
        else if (course_college == "农业工程学院") {
            course_profession = course12_profession_menu();
        }
        else if (course_college == "教师教育学院") {
            course_profession = course13_profession_menu();
        }
        else if (course_college == "生命科学学院") {
            course_profession = course14_profession_menu();
        }
        else if (course_college == "数学科学学院") {
            course_profession = course15_profession_menu();
        }
        else if (course_college == "马克思主义学院") {
            course_profession = course16_profession_menu();
        }
        else if (course_college == "电气信息工程学院") {
            course_profession = course17_profession_menu();
        }
        else if (course_college == "能源与动力工程学院") {
            course_profession = course18_profession_menu();
        }
        else if (course_college == "汽车与交通工程学院") {
            course_profession = course19_profession_menu();
        }
        else if (course_college == "食品与生物工程学院") {
            course_profession = course20_profession_menu();
        }
        else if (course_college == "土木工程与力学学院") {
            course_profession = course21_profession_menu();
        }
        else if (course_college == "物理与电子工程学院") {
            course_profession = course22_profession_menu();
        }
        else if (course_college == "材料科学与工程学院") {
            course_profession = course23_profession_menu();
        }
        else if (course_college == "环境与安全工程学院") {
            course_profession = course24_profession_menu();
        }
        else if (course_college == "计算机科学与通信工程学院") {
            course_profession = course25_profession_menu();
        }
    }
    else {
        course_profession = "0";
    }
    system("cls");
    Col(3); cout << "请依次输入筛选条件:" << endl << "(不进行筛选的条件请输入0或不选择)" << endl;
    cout << "编号:" << course_id << endl;
    cout << "名称:" << course_name << endl;
    cout << "年级:" << course_grade << endl;
    cout << "学院:" << course_college << endl;
    cout << "专业:" << course_profession << endl; Col(0);
    Col(3); cout << "开课学院:(请选择)"; Col(0);
    cout << endl << endl << endl;
    system("pause");
    string course_college_open;
    course_college_open = course_college_menu();
    system("cls");
    Col(3); cout << "请依次输入筛选条件:" << endl << "(不进行筛选的条件请输入0或不选择)" << endl;
    cout << "编号:" << course_id << endl;
    cout << "名称:" << course_name << endl;
    cout << "年级:" << course_grade << endl;
    cout << "学院:" << course_college << endl;
    cout << "专业:" << course_profession << endl;
    cout << "开课学院:" << course_college_open << endl; Col(0);
    Col(3); cout << "课程类别:(请选择)"; Col(0);
    cout << endl << endl << endl;
    system("pause");
    string course_type;
    course_type = course_type_menu();
    system("cls");
    Col(3); cout << "请依次输入筛选条件:" << endl << "(不进行筛选的条件请输入0或不选择)" << endl;
    cout << "编号:" << course_id << endl;
    cout << "名称:" << course_name << endl;
    cout << "年级:" << course_grade << endl;
    cout << "学院:" << course_college << endl;
    cout << "专业:" << course_profession << endl;
    cout << "开课学院:" << course_college_open << endl;
    cout << "课程类别:" << course_type << endl; Col(0);
    Col(3); cout << "课程性质:(请选择)"; Col(0);
    cout << endl << endl << endl;
    system("pause");
    string course_nature;
    course_nature = course_nature_menu();
    system("cls");
    Col(3); cout << "请依次输入筛选条件:" << endl << "(不进行筛选的条件请输入0或不选择)" << endl;
    cout << "编号:" << course_id << endl;
    cout << "名称:" << course_name << endl;
    cout << "年级:" << course_grade << endl;
    cout << "学院:" << course_college << endl;
    cout << "专业:" << course_profession << endl;
    cout << "开课学院:" << course_college_open << endl;
    cout << "课程类别:" << course_type << endl;
    cout << "课程性质:" << course_nature << endl; Col(0);
    Col(3); cout << "课程归属:(请选择)"; Col(0);
    cout << endl << endl << endl;
    system("pause");
    string course_belong;
    course_belong = course_belong_menu();
    system("cls");
    Col(3); cout << "请依次输入筛选条件:" << endl << "(不进行筛选的条件请输入0或不选择)" << endl;
    cout << "编号:" << course_id << endl;
    cout << "名称:" << course_name << endl;
    cout << "年级:" << course_grade << endl;
    cout << "学院:" << course_college << endl;
    cout << "专业:" << course_profession << endl;
    cout << "开课学院:" << course_college_open << endl;
    cout << "课程类别:" << course_type << endl;
    cout << "课程性质:" << course_nature << endl;
    cout << "课程归属:" << course_belong << endl; Col(0);
    Col(3); cout << "课程星期:(请选择)"; Col(0);
    cout << endl << endl << endl;
    system("pause");
    string course_week;
    course_week = course_week_menu();
    system("cls");
    Col(3); cout << "请依次输入筛选条件:" << endl << "(不进行筛选的条件请输入0或不选择)" << endl;
    cout << "编号:" << course_id << endl;
    cout << "名称:" << course_name << endl;
    cout << "年级:" << course_grade << endl;
    cout << "学院:" << course_college << endl;
    cout << "专业:" << course_profession << endl;
    cout << "开课学院:" << course_college_open << endl;
    cout << "课程类别:" << course_type << endl;
    cout << "课程性质:" << course_nature << endl;
    cout << "课程归属:" << course_belong << endl;
    cout << "课程星期:" << course_week << endl; Col(0);
    Col(3); cout << "课程节次:(请选择)"; Col(0);
    cout << endl << endl << endl;
    system("pause");
    string course_time;
    course_time = course_time_menu();
    system("cls");
    Col(3); cout << "请依次输入筛选条件:" << endl << "(不进行筛选的条件请输入0或不选择)" << endl;
    cout << "编号:" << course_id << endl;
    cout << "名称:" << course_name << endl;
    cout << "年级:" << course_grade << endl;
    cout << "学院:" << course_college << endl;
    cout << "专业:" << course_profession << endl;
    cout << "开课学院:" << course_college_open << endl;
    cout << "课程类别:" << course_type << endl;
    cout << "课程性质:" << course_nature << endl;
    cout << "课程归属:" << course_belong << endl;
    cout << "课程星期:" << course_week << endl;
    cout << "课程节次:" << course_time << endl; Col(0);
    Col(2); cout << endl << endl << endl << "查询中..." << endl; Col(0);
    Sleep(1000);
    course temp_course(course_id, course_name, course_grade, course_college, course_profession, course_college_open, course_type, course_nature, course_belong, course_week, course_time);
    //打开文件
    fstream course_file("course.txt", ios::in);
    if (!course_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    system("cls");
    Col(2); cout << "以下课程符合筛选条件:" << endl; Col(0);
    Col(3); cout << left << setw(4) << "编号";
    Col(6); cout << left << setw(34) << "名称";
    Col(3); cout << left << setw(4) << "年级";
    Col(6); cout << left << setw(24) << "学院";
    Col(3); cout << left << setw(28) << "专业";
    Col(6); cout << left << setw(24) << "开课学院";
    Col(3); cout << left << setw(12) << "课程类别";
    Col(6); cout << left << setw(8) << "课程性质";
    Col(3); cout << left << setw(12) << "课程归属";
    Col(6); cout << left << setw(6) << "星期";
    Col(3); cout << left << setw(9) << "课程节次" << endl;
    //不读取第一行作为信息
    string temp;
    getline(course_file, temp);
    //读取文件并筛选
    course_file >> course_id >> course_name >> course_grade >> course_college >> course_profession >> course_college_open >> course_type >> course_nature >> course_belong >> course_week >> course_time;
    while (!course_file.eof())
    {
        if ((course_id == temp_course.course_id || temp_course.course_id == "0") && (course_name == temp_course.course_name || temp_course.course_name == "0") && (course_grade == temp_course.course_grade || temp_course.course_grade == "0") && (course_college == temp_course.course_college || temp_course.course_college == "0") && (course_profession == temp_course.course_profession || temp_course.course_profession == "0") && (course_college_open == temp_course.course_college_open || temp_course.course_college_open == "0") && (course_type == temp_course.course_type || temp_course.course_type == "0") && (course_nature == temp_course.course_nature || temp_course.course_nature == "0") && (course_belong == temp_course.course_belong || temp_course.course_belong == "0") && (course_week == temp_course.course_week || temp_course.course_week == "0") && (course_time == temp_course.course_time || temp_course.course_time == "0"))
        {
            Col(3); cout << left << setw(4) << course_id;
            Col(6); cout << left << setw(34) << course_name;
            Col(3); cout << left << setw(4) << course_grade;
            Col(6); cout << left << setw(24) << course_college;
            Col(3); cout << left << setw(28) << course_profession;
            Col(6); cout << left << setw(24) << course_college_open;
            Col(3); cout << left << setw(12) << course_type;
            Col(6); cout << left << setw(8) << course_nature;
            Col(3); cout << left << setw(12) << course_belong;
            Col(6); cout << left << setw(6) << course_week;
            Col(3); cout << left << setw(9) << course_time << endl;
            Col(0);
        }
        course_file >> course_id >> course_name >> course_grade >> course_college >> course_profession >> course_college_open >> course_type >> course_nature >> course_belong >> course_week >> course_time;
    }
    course_file.close();
}
bool course::Iscourse_exist(string temp_course_id)
{
    //打开文件
    fstream course_file("course.txt", ios::in);
    if (!course_file)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    //遍历一遍课程信息，如果有相同的课程编号则返回true
    string course_id;
    string temp;
    while (course_file >> course_id)
    {
        if (course_id == temp_course_id)
        {
            course_file.close();
            return true;
            break;
        }
        getline(course_file, temp);
    }
    course_file.close();
    return false;
}
string course::course_college_menu()
{
    List course_college_menu_list(26);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "                                                     学院列表                                                      " << endl; cout << "  ";
        if (course_college_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(13) << "1.不选择"; Col(3); cout <<setw(100)<< "  "; 
        cout << endl; cout << "  ";
        if (course_college_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(13) << "2.药学院"; Col(3); cout << "    ";
        if (course_college_menu_list.GetListSelection() == 7) Col(7);
        else Col(6);
        cout << left << setw(16) << "7.管理学院"; Col(3); cout << "    ";
        if (course_college_menu_list.GetListSelection() == 12) Col(7);
        else Col(6);
        cout << left << setw(16) << "12.机械工程学院"; Col(3); cout << "    ";
        if (course_college_menu_list.GetListSelection() == 17) Col(7);
        else Col(6);
        cout << left << setw(22) << "17.马克思主义学院"; Col(3); cout << "    ";
        if (course_college_menu_list.GetListSelection() == 22) Col(7);
        else Col(6);
        cout << left << setw(28) << "22.土木工程与力学学院"; Col(3); cout << "  ";
        cout << endl; Col(3); cout << "  ";
        if (course_college_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(13) << "3.医学院"; Col(3); cout << "    ";
        if (course_college_menu_list.GetListSelection() == 8) Col(7);
        else Col(6);
        cout << left << setw(16) << "8.艺术学院"; Col(3); cout << "    ";
        if (course_college_menu_list.GetListSelection() == 13) Col(7);
        else Col(6);
        cout << left << setw(16) << "13.农业工程学院"; Col(3); cout << "    ";
        if (course_college_menu_list.GetListSelection() == 18) Col(7);
        else Col(6);
        cout << left << setw(22) << "18.电气信息工程学院"; Col(3); cout << "    ";
        if (course_college_menu_list.GetListSelection() == 23) Col(7);
        else Col(6);
        cout << left << setw(28) << "23.物理与电子工程学院"; Col(3); cout << "  ";
        cout << endl; Col(3); cout << "  ";
        if (course_college_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(13) << "4.法学院"; Col(3); cout << "    ";
        if (course_college_menu_list.GetListSelection() == 9) Col(7);
        else Col(6);
        cout << left << setw(16) << "9.外国语学院"; Col(3); cout << "    ";
        if (course_college_menu_list.GetListSelection() == 14) Col(7);
        else Col(6);
        cout << left << setw(16) << "14.教师教育学院"; Col(3); cout << "    ";
        if (course_college_menu_list.GetListSelection() == 19) Col(7);
        else Col(6);
        cout << left << setw(22) << "19.能源与动力工程学院"; Col(3); cout << "    ";
        if (course_college_menu_list.GetListSelection() == 24) Col(7);
        else Col(6);
        cout << left << setw(28) << "24.材料科学与工程学院"; Col(3); cout << "  ";
        cout << endl; Col(3); cout << "  ";
        if (course_college_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(13) << "5.文学院"; Col(3); cout << "    ";
        if (course_college_menu_list.GetListSelection() == 10) Col(7);
        else Col(6);
        cout << left << setw(16) << "10.知识产权学院"; Col(3); cout << "    ";
        if (course_college_menu_list.GetListSelection() == 15) Col(7);
        else Col(6);
        cout << left << setw(16) << "15.生命科学学院"; Col(3); cout << "    ";
        if (course_college_menu_list.GetListSelection() == 20) Col(7);
        else Col(6);
        cout << left << setw(22) << "20.汽车与交通工程学院"; Col(3); cout << "    ";
        if (course_college_menu_list.GetListSelection() == 25) Col(7);
        else Col(6);
        cout << left << setw(28) << "25.环境与安全工程学院"; Col(3); cout << "  ";
        cout << endl; Col(3); cout << "  ";
        if (course_college_menu_list.GetListSelection() == 6) Col(7);
        else Col(6);
        cout << left << setw(13) << "6.财经学院"; Col(3); cout << "    ";
        if (course_college_menu_list.GetListSelection() == 11) Col(7);
        else Col(6);
        cout << left << setw(16) << "11.化学化工学院"; Col(3); cout << "    ";
        if (course_college_menu_list.GetListSelection() == 16) Col(7);
        else Col(6);
        cout << left << setw(16) << "16.数学科学学院"; Col(3); cout << "    ";
        if (course_college_menu_list.GetListSelection() == 21) Col(7);
        else Col(6);
        cout << left << setw(22) << "21.食品与生物工程学院"; Col(3); cout << "    ";
        if (course_college_menu_list.GetListSelection() == 26) Col(7);
        else Col(6);
        cout << left << setw(28) << "26.计算机科学与通信工程学院"; Col(3); cout << "  ";
        cout << endl; Col(3); cout << "  ";
        cout << setw(113) <<" " << endl; Col(0);
        course_college_menu_list.Deal_input();
        if (course_college_menu_list.GetBreakword())
        {
            course_college_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course_college_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "药学院"; break; }
    case 3: {return "医学院"; break; }
    case 4: {return "法学院"; break; }
    case 5: {return "文学院"; break; }
    case 6: {return "财经学院"; break; }
    case 7: {return "管理学院"; break; }
    case 8: {return "艺术学院"; break; }
    case 9: {return "外国语学院"; break; }
    case 10: {return "知识产权学院"; break; }
    case 11: {return "化学化工学院"; break; }
    case 12: {return "机械工程学院"; break; }
    case 13: {return "农业工程学院"; break; }
    case 14: {return "教师教育学院"; break; }
    case 15: {return "生命科学学院"; break; }
    case 16: {return "数学科学学院"; break; }
    case 17: {return "马克思主义学院"; break; }
    case 18: {return "电气信息工程学院"; break; }
    case 19: {return "能源与动力工程学院"; break; }
    case 20: {return "汽车与交通工程学院"; break; }
    case 21: {return "食品与生物工程学院"; break; }
    case 22: {return "土木工程与力学学院"; break; }
    case 23: {return "物理与电子工程学院"; break; }
    case 24: {return "材料科学与工程学院"; break; }
    case 25: {return "环境与安全工程学院"; break; }
    case 26: {return "计算机科学与通信工程学院"; break; }
    }
}
string course::course1_profession_menu()
{
    List course1_profession_menu_list(5);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "         药学院          " << endl;Col(3); cout << "   ";
        if (course1_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择"; Col(3); cout << "  ";cout << endl; cout << "   ";
        if (course1_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.药物制剂"; Col(3); cout << "  ";cout << endl;cout << "   ";
        if (course1_profession_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(20) << "3.制药工程"; Col(3); cout << "  ";cout << endl;cout << "   ";
        if (course1_profession_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(20) << "4.药学类"; Col(3); cout << "  ";cout << endl;cout << "   ";
        if (course1_profession_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(20) << "5.药学"; Col(3); cout << "  ";cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course1_profession_menu_list.Deal_input();
        if (course1_profession_menu_list.GetBreakword())
        {
            course1_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course1_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "药学制剂"; break; }
    case 3: {return "制药工程"; break; }
    case 4: {return "药学类"; break; }
    case 5: {return "药学"; break; }
    }
}
string course::course2_profession_menu()
{
    List course2_profession_menu_list(7);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "         医学院          " << endl; Col(3); cout << "   ";
        if (course2_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course2_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.卫生检验与检疫"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course2_profession_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(20) << "3.医学检验技术"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course2_profession_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(20) << "4.医学影像学"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course2_profession_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(20) << "5.临床医学"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course2_profession_menu_list.GetListSelection() == 6) Col(7);
        else Col(6);
        cout << left << setw(20) << "6.预防医学"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course2_profession_menu_list.GetListSelection() == 7) Col(7);
        else Col(6);
        cout << left << setw(20) << "7.护理学"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course2_profession_menu_list.Deal_input();
        if (course2_profession_menu_list.GetBreakword())
        {
            course2_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course2_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "卫生检验与检疫"; break; }
    case 3: {return "医学检验技术"; break; }
    case 4: {return "医学影像学"; break; }
    case 5: {return "临床医学"; break; }
    case 6: {return "预防医学"; break; }
    case 7: {return "护理学"; break; }
    }
}
string course::course3_profession_menu()
{
    List course3_profession_menu_list(2);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "         法学院          " << endl; Col(3); cout << "   ";
        if (course3_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course3_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.法学"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course3_profession_menu_list.Deal_input();
        if (course3_profession_menu_list.GetBreakword())
        {
            course3_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course3_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "法学"; break; }
    }
}
string course::course4_profession_menu()
{
    List course4_profession_menu_list(3);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "         文学院          " << endl; Col(3); cout << "   ";
        if (course4_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course4_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.汉语国际教育"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course4_profession_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(20) << "3.汉语言文学"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course4_profession_menu_list.Deal_input();
        if (course4_profession_menu_list.GetBreakword())
        {
            course4_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course4_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "汉语国际教育"; break; }
    case 3: {return "汉语言文学"; break; }
    }
}
string course::course5_profession_menu()
{
    List course5_profession_menu_list(8);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "        财经学院         " << endl; Col(3); cout << "   ";
        if (course5_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course5_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.国际经济与贸易"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course5_profession_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(20) << "3.财务管理"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course5_profession_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(20) << "4.能源经济"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course5_profession_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(20) << "5.保险学"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course5_profession_menu_list.GetListSelection() == 6) Col(7);
        else Col(6);
        cout << left << setw(20) << "6.会计学"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course5_profession_menu_list.GetListSelection() == 7) Col(7);
        else Col(6);
        cout << left << setw(20) << "7.金融学"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course5_profession_menu_list.GetListSelection() == 8) Col(7);
        else Col(6);
        cout << left << setw(20) << "8.统计学"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course5_profession_menu_list.Deal_input();
        if (course5_profession_menu_list.GetBreakword())
        {
            course5_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course5_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "国际经济与贸易"; break; }
    case 3: {return "财务管理"; break; }
    case 4: {return "能源经济"; break; }
    case 5: {return "保险学"; break; }
    case 6: {return "会计学"; break; }
    case 7: {return "金融学"; break; }
    case 8: {return "统计学"; break; }
    }
}
string course::course6_profession_menu()
{
    List course6_profession_menu_list(9);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "        管理学院         " << endl; Col(3); cout << "   ";
        if (course6_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course6_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.信息管理与信息系统"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course6_profession_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(20) << "3.公共事业管理"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course6_profession_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(20) << "4.人力资源管理"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course6_profession_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(20) << "5.电子商务"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course6_profession_menu_list.GetListSelection() == 6) Col(7);
        else Col(6);
        cout << left << setw(20) << "6.工商管理"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course6_profession_menu_list.GetListSelection() == 7) Col(7);
        else Col(6);
        cout << left << setw(20) << "7.工业工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course6_profession_menu_list.GetListSelection() == 8) Col(7);
        else Col(6);
        cout << left << setw(20) << "8.市场营销"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course6_profession_menu_list.GetListSelection() == 9) Col(7);
        else Col(6);
        cout << left << setw(20) << "9.物流管理"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course6_profession_menu_list.Deal_input();
        if (course6_profession_menu_list.GetBreakword())
        {
            course6_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course6_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "信息管理与信息系统"; break; }
    case 3: {return "公共事业管理"; break; }
    case 4: {return "人力资源管理"; break; }
    case 5: {return "电子商务"; break; }
    case 6: {return "工商管理"; break; }
    case 7: {return "工业工程"; break; }
    case 8: {return "市场营销"; break; }
    case 9: {return "物流管理"; break; }
    }
}
string course::course7_profession_menu()
{
    List course7_profession_menu_list(9);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "        艺术学院         " << endl; Col(3); cout << "   ";
        if (course7_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course7_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.数字媒体艺术"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course7_profession_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(20) << "3.视觉传达设计"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course7_profession_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(20) << "4.产品设计"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course7_profession_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(20) << "5.公共艺术"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course7_profession_menu_list.GetListSelection() == 6) Col(7);
        else Col(6);
        cout << left << setw(20) << "6.工业设计"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course7_profession_menu_list.GetListSelection() == 7) Col(7);
        else Col(6);
        cout << left << setw(20) << "7.环境设计"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course7_profession_menu_list.GetListSelection() == 8) Col(7);
        else Col(6);
        cout << left << setw(20) << "8.美术学"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course7_profession_menu_list.GetListSelection() == 9) Col(7);
        else Col(6);
        cout << left << setw(20) << "9.动画"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course7_profession_menu_list.Deal_input();
        if (course7_profession_menu_list.GetBreakword())
        {
            course7_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course7_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "数字媒体艺术"; break; }
    case 3: {return "视觉传达设计"; break; }
    case 4: {return "产品设计"; break; }
    case 5: {return "公共艺术"; break; }
    case 6: {return "工业设计"; break; }
    case 7: {return "环境设计"; break; }
    case 8: {return "美术学"; break; }
    case 9: {return "动画"; break; }
    }
}
string course::course8_profession_menu()
{
    List course8_profession_menu_list(3);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "       外国语学院        " << endl; Col(3); cout << "   ";
        if (course8_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course8_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.日语"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course8_profession_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(20) << "3.英语"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course8_profession_menu_list.Deal_input();
        if (course8_profession_menu_list.GetBreakword())
        {
            course8_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course8_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "日语"; break; }
    case 3: {return "英语"; break; }
    }
}
string course::course9_profession_menu()
{
    List course9_profession_menu_list(2);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "       知识产权学院      " << endl; Col(3); cout << "   ";
        if (course9_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course9_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.知识产权"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course9_profession_menu_list.Deal_input();
        if (course9_profession_menu_list.GetBreakword())
        {
            course9_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course9_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "知识产权"; break; }
    }
}
string course::course10_profession_menu()
{
    List course10_profession_menu_list(5);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "       化学化工学院      " << endl; Col(3); cout << "   ";
        if (course10_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course10_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.化学工程与工艺"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course10_profession_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(20) << "3.应用化学"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course10_profession_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(20) << "4.化学类"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course10_profession_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(20) << "5.化学"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course10_profession_menu_list.Deal_input();
        if (course10_profession_menu_list.GetBreakword())
        {
            course10_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course10_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "化学工程与工艺"; break; }
    case 3: {return "应用化学"; break; }
    case 4: {return "化学类"; break; }
    case 5: {return "化学"; break; }
    }
}
string course::course11_profession_menu()
{
    List course11_profession_menu_list(6);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "        机械工程学院          " << endl; Col(3); cout << "   ";
        if (course11_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(25) << "1.不选择"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course11_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(25) << "2.机械设计制造及其自动化"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course11_profession_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(25) << "3.光电信息科学与工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course11_profession_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(25) << "4.测控技术与仪器"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course11_profession_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(25) << "5.智能制造工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course11_profession_menu_list.GetListSelection() == 6) Col(7);
        else Col(6);
        cout << left << setw(25) << "6.机械电子工程"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(30) << " " << endl; Col(0);
        course11_profession_menu_list.Deal_input();
        if (course11_profession_menu_list.GetBreakword())
        {
            course11_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course11_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "机械设计制造及其自动化"; break; }
    case 3: {return "光电信息科学与工程"; break; }
    case 4: {return "测控技术与仪器"; break; }
    case 5: {return "智能制造工程"; break; }
    case 6: {return "机械电子工程"; break; }
    }
}
string course::course12_profession_menu()
{
    List course12_profession_menu_list(4);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "         农业工程学院         " << endl; Col(3); cout << "   ";
        if (course12_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(25) << "1.不选择"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course12_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(25) << "2.农业机械化及其自动化"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course12_profession_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(25) << "3.设施农业科学与工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course12_profession_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(25) << "4.农业智能装备工程"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(30) << " " << endl; Col(0);
        course12_profession_menu_list.Deal_input();
        if (course12_profession_menu_list.GetBreakword())
        {
            course12_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course12_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "农业机械化及其自动化"; break; }
    case 3: {return "设施农业科学与工程"; break; }
    case 4: {return "农业智能装备工程"; break; }
    }
}
string course::course13_profession_menu()
{
    List course13_profession_menu_list(2);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "       教师教育学院      " << endl; Col(3); cout << "   ";
        if (course13_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择";
        Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course13_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.教育技术学"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course13_profession_menu_list.Deal_input();
        if (course13_profession_menu_list.GetBreakword())
        {
            course13_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course13_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "教育技术学"; break; }
    }
}
string course::course14_profession_menu()
{
    List course14_profession_menu_list(2);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "       生命科学学院      " << endl; Col(3); cout << "   ";
        if (course14_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择";
        Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course14_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.生物科学"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course14_profession_menu_list.Deal_input();
        if (course14_profession_menu_list.GetBreakword())
        {
            course14_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course14_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "生物科学"; break; }
    }
}
string course::course15_profession_menu()
{
    List course15_profession_menu_list(3);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "       数学科学学院      " << endl; Col(3); cout << "   ";
        if (course15_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择";
        Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course15_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.数据计算及应用"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course15_profession_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(20) << "3.数学与应用数学"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course15_profession_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(20) << "4.金融数学"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course15_profession_menu_list.Deal_input();
        if (course15_profession_menu_list.GetBreakword())
        {
            course15_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course15_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "数据计算及应用"; break; }
    case 3: {return "数学与应用数学"; break; }
    case 4: {return "金融数学"; break; }
    }
}
string course::course16_profession_menu()
{
    List course16_profession_menu_list(2);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "       马克思主义学院    " << endl; Col(3); cout << "   ";
        if (course16_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择";
        Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course16_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.思想政治教育"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course16_profession_menu_list.Deal_input();
        if (course16_profession_menu_list.GetBreakword())
        {
            course16_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course16_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "思想政治教育"; break; }
    }
}
string course::course17_profession_menu()
{
    List course17_profession_menu_list(7);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "     电气信息工程学院    " << endl; Col(3); cout << "   ";
        if (course17_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择";
        Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course17_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.电气工程及其自动化"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course17_profession_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(20) << "3.电子信息工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course17_profession_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(20) << "4.生物医学工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course17_profession_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(20) << "5.机器人工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course17_profession_menu_list.GetListSelection() == 6) Col(7);
        else Col(6);
        cout << left << setw(20) << "6.农业电气化"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course17_profession_menu_list.GetListSelection() == 7) Col(7);
        else Col(6);
        cout << left << setw(20) << "7.自动化"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course17_profession_menu_list.Deal_input();
        if (course17_profession_menu_list.GetBreakword())
        {
            course17_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course17_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "电气工程及其自动化"; break; }
    case 3: {return "电子信息工程"; break; }
    case 4: {return "生物医学工程"; break; }
    case 5: {return "机器人工程"; break; }
    case 6: {return "农业电气化"; break; }
    case 7: {return "自动化"; break; }
    }
}
string course::course18_profession_menu()
{
    List course18_profession_menu_list(5);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "       能源与动力工程学院     " << endl; Col(3); cout << "   ";
        if (course18_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(25) << "1.不选择";
        Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course18_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(25) << "2.建筑环境与能源应用工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course18_profession_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(25) << "3.新能源科学与工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course18_profession_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(25) << "4.储能科学与工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course18_profession_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(25) << "5.能源与动力工程"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(30) << " " << endl; Col(0);
        course18_profession_menu_list.Deal_input();
        if (course18_profession_menu_list.GetBreakword())
        {
            course18_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course18_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "建筑环境与能源应用工程"; break; }
    case 3: {return "新能源科学与工程"; break; }
    case 4: {return "储能科学与工程"; break; }
    case 5: {return "能源与动力工程"; break; }
    }
}
string course::course19_profession_menu()
{
    List course19_profession_menu_list(6);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "   汽车与交通工程学院    " << endl; Col(3); cout << "   ";
        if (course19_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择";
        Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course19_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.能源与动力工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course19_profession_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(20) << "3.新能源汽车工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course19_profession_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(20) << "4.车辆工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course19_profession_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(20) << "5.交通工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course19_profession_menu_list.GetListSelection() == 6) Col(7);
        else Col(6);
        cout << left << setw(20) << "6.交通运输"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course19_profession_menu_list.Deal_input();
        if (course19_profession_menu_list.GetBreakword())
        {
            course19_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course19_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "能源与动力工程"; break; }
    case 3: {return "新能源汽车工程"; break; }
    case 4: {return "车辆工程"; break; }
    case 5: {return "交通工程"; break; }
    case 6: {return "交通运输"; break; }
    }
}
string course::course20_profession_menu()
{
    List course20_profession_menu_list(7);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "   食品与生物工程学院    " << endl; Col(3); cout << "   ";
        if (course20_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择";
        Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course20_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.食品科学与工程类"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course20_profession_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(20) << "3.食品科学与工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course20_profession_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(20) << "4.食品营养与健康"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course20_profession_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(20) << "5.食品质量与安全"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course20_profession_menu_list.GetListSelection() == 6) Col(7);
        else Col(6);
        cout << left << setw(20) << "6.生物工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course20_profession_menu_list.GetListSelection() == 7) Col(7);
        else Col(6);
        cout << left << setw(20) << "7.生物技术"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course20_profession_menu_list.Deal_input();
        if (course20_profession_menu_list.GetBreakword())
        {
            course20_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course20_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "食品科学与工程类"; break; }
    case 3: {return "食品科学与工程"; break; }
    case 4: {return "食品营养与健康"; break; }
    case 5: {return "食品质量与安全"; break; }
    case 6: {return "生物工程"; break; }
    case 7: {return "生物技术"; break; }
    }
}
string course::course21_profession_menu()
{
    List course21_profession_menu_list(4);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "   土木工程与力学学院    " << endl; Col(3); cout << "   ";
        if (course21_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择";
        Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course21_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.工程管理"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course21_profession_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(20) << "3.工程力学"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course21_profession_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(20) << "4.土木工程"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course21_profession_menu_list.Deal_input();
        if (course21_profession_menu_list.GetBreakword())
        {
            course21_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course21_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "工程管理"; break; }
    case 3: {return "工程力学"; break; }
    case 4: {return "土木工程"; break; }
    }
}
string course::course22_profession_menu()
{
    List course22_profession_menu_list(3);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "   物理与电子工程学院    " << endl; Col(3); cout << "   ";
        if (course22_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择";
        Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course22_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.微电子科学与工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course22_profession_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(20) << "3.物理学"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course22_profession_menu_list.Deal_input();
        if (course22_profession_menu_list.GetBreakword())
        {
            course22_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course22_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "微电子科学与工程"; break; }
    case 3: {return "物理学"; break; }
    }
}
string course::course23_profession_menu()
{
    List course23_profession_menu_list(9);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "      材料科学与工程学院      " << endl; Col(3); cout << "   ";
        if (course23_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(25) << "1.不选择";
        Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course23_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(25) << "2.材料成型及控制工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course23_profession_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(25) << "3.无机非金属材料工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course23_profession_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(25) << "4.高分子材料与工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course23_profession_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(25) << "5.材料科学与工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course23_profession_menu_list.GetListSelection() == 6) Col(7);
        else Col(6);
        cout << left << setw(25) << "6.复合材料与工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course23_profession_menu_list.GetListSelection() == 7) Col(7);
        else Col(6);
        cout << left << setw(25) << "7.金属材料工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course23_profession_menu_list.GetListSelection() == 8) Col(7);
        else Col(6);
        cout << left << setw(25) << "8.冶金工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course23_profession_menu_list.GetListSelection() == 9) Col(7);
        else Col(6);
        cout << left << setw(25) << "9.材料类"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(30) << " " << endl; Col(0);
        course23_profession_menu_list.Deal_input();
        if (course23_profession_menu_list.GetBreakword())
        {
            course23_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course23_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "材料成型及控制工程"; break; }
    case 3: {return "无机非金属材料工程"; break; }
    case 4: {return "高分子材料与工程"; break; }
    case 5: {return "材料科学与工程"; break; }
    case 6: {return "复合材料与工程"; break; }
    case 7: {return "金属材料工程"; break; }
    case 8: {return "冶金工程"; break; }
    case 9: {return "材料类"; break; }
    }
}
string course::course24_profession_menu()
{
    List course24_profession_menu_list(5);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "      环境与安全工程学院      " << endl; Col(3); cout << "   ";
        if (course24_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(25) << "1.不选择";
        Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course24_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(25) << "2.应急技术与管理"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course24_profession_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(25) << "3.环保设备工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course24_profession_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(25) << "4.安全工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course24_profession_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(25) << "5.环境工程"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(30) << " " << endl; Col(0);
        course24_profession_menu_list.Deal_input();
        if (course24_profession_menu_list.GetBreakword())
        {
            course24_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course24_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "应急技术与管理"; break; }
    case 3: {return "环保设备工程"; break; }
    case 4: {return "安全工程"; break; }
    case 5: {return "环境工程"; break; }
    }
}
string course::course25_profession_menu()
{
    List course25_profession_menu_list(8);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "   计算机科学与通信工程学院   " << endl; Col(3); cout << "   ";
        if (course25_profession_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(25) << "1.不选择";
        Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course25_profession_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(25) << "2.计算机科学与技术"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course25_profession_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(25) << "3.智能科学与技术"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course25_profession_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(25) << "4.物联网工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course25_profession_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(25) << "5.软件工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course25_profession_menu_list.GetListSelection() == 6) Col(7);
        else Col(6);
        cout << left << setw(25) << "6.通信工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course25_profession_menu_list.GetListSelection() == 7) Col(7);
        else Col(6);
        cout << left << setw(25) << "7.网络工程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course25_profession_menu_list.GetListSelection() == 8) Col(7);
        else Col(6);
        cout << left << setw(25) << "8.信息安全"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(30) << " " << endl; Col(0);
        course25_profession_menu_list.Deal_input();
        if (course25_profession_menu_list.GetBreakword())
        {
            course25_profession_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course25_profession_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "计算机科学与技术"; break; }
    case 3: {return "智能科学与技术"; break; }
    case 4: {return "物联网工程"; break; }
    case 5: {return "软件工程"; break; }
    case 6: {return "通信工程"; break; }
    case 7: {return "网络工程"; break; }
    case 8: {return "信息安全"; break; }
    }
}
string course::course_type_menu()
{
    List course_type_menu_list(9);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "         课程类别        " << endl; Col(3); cout << "   ";
        if (course_type_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择";
        Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_type_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.通识教育必修"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_type_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(20) << "3.通识教育选修"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_type_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(20) << "4.专业基础必修"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_type_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(20) << "5.专业基础选修"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_type_menu_list.GetListSelection() == 6) Col(7);
        else Col(6);
        cout << left << setw(20) << "6.专业方向必修"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_type_menu_list.GetListSelection() == 7) Col(7);
        else Col(6);
        cout << left << setw(20) << "7.专业方向选修"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_type_menu_list.GetListSelection() == 8) Col(7);
        else Col(6);
        cout << left << setw(20) << "8.实践环节"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_type_menu_list.GetListSelection() == 9) Col(7);
        else Col(6);
        cout << left << setw(20) << "9.自主研学"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course_type_menu_list.Deal_input();
        if (course_type_menu_list.GetBreakword())
        {
            course_type_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course_type_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "通识教育必修"; break; }
    case 3: {return "通识教育选修"; break; }
    case 4: {return "专业基础必修"; break; }
    case 5: {return "专业基础选修"; break; }
    case 6: {return "专业方向必修"; break; }
    case 7: {return "专业方向选修"; break; }
    case 8: {return "实践环节"; break; }
    case 9: {return "自主研学"; break; }
    }
}
string course::course_nature_menu()
{
    List course_nature_menu_list(5);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "         课程性质        " << endl; Col(3); cout << "   ";
        if (course_nature_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(20) << "1.不选择";
        Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_nature_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(20) << "2.必修课"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_nature_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(20) << "3.选修课"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_nature_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(20) << "4.限选课"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_nature_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(20) << "5.校选修课"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(25) << " " << endl; Col(0);
        course_nature_menu_list.Deal_input();
        if (course_nature_menu_list.GetBreakword())
        {
            course_nature_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course_nature_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "必修课"; break; }
    case 3: {return "选修课"; break; }
    case 4: {return "限选课"; break; }
    case 5: {return "校选修课"; break; }
    }
}
string course::course_belong_menu()
{
    List course_belong_menu_list(10);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "           课程归属           " << endl; Col(3); cout << "   ";
        if (course_belong_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(25) << "1.不选择";
        Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_belong_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(25) << "2.经济管理类"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_belong_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(25) << "3.艺术鉴赏类"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_belong_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(25) << "4.自然科学类"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_belong_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(25) << "5.综合教育类"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_belong_menu_list.GetListSelection() == 6) Col(7);
        else Col(6);
        cout << left << setw(25) << "6.工程技术类"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_belong_menu_list.GetListSelection() == 7) Col(7);
        else Col(6);
        cout << left << setw(25) << "7.创新创业类"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_belong_menu_list.GetListSelection() == 8) Col(7);
        else Col(6);
        cout << left << setw(25) << "8.大国三农类"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_belong_menu_list.GetListSelection() == 9) Col(7);
        else Col(6);
        cout << left << setw(25) << "9.自主研学课程"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_belong_menu_list.GetListSelection() == 10) Col(7);
        else Col(6);
        cout << left << setw(25) << "10.劳动教育与实践"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(30) << " " << endl; Col(0);
        course_belong_menu_list.Deal_input();
        if (course_belong_menu_list.GetBreakword())
        {
            course_belong_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course_belong_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "经济管理类"; break; }
    case 3: {return "艺术鉴赏类"; break; }
    case 4: {return "自然科学类"; break; }
    case 5: {return "综合教育类"; break; }
    case 6: {return "工程技术类"; break; }
    case 7: {return "创新创业类"; break; }
    case 8: {return "大国三农类"; break; }
    case 9: {return "自主研学课程"; break; }
    case 10: {return "劳动教育与实践"; break; }
    }
}
string course::course_week_menu()
{
    List course_week_menu_list(6);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "   上课星期    " << endl; Col(3); cout << "   ";
        if (course_week_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(10) << "1.不选择";
        Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_week_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(10) << "2.星期一"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_week_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(10) << "3.星期二"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_week_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(10) << "4.星期三"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_week_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(10) << "5.星期四"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_week_menu_list.GetListSelection() == 6) Col(7);
        else Col(6);
        cout << left << setw(10) << "6.星期五"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(15) << " " << endl; Col(0);
        course_week_menu_list.Deal_input();
        if (course_week_menu_list.GetBreakword())
        {
            course_week_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course_week_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "星期一"; break; }
    case 3: {return "星期二"; break; }
    case 4: {return "星期三"; break; }
    case 5: {return "星期四"; break; }
    case 6: {return "星期五"; break; }
    }
}
string course::course_week2_menu()
{
    List course_week2_menu_list(5);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "   上课星期    " << endl; Col(3); cout << "   ";
        if (course_week2_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(10) << "1.星期一";
        Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_week2_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(10) << "2.星期二"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_week2_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(10) << "3.星期三"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_week2_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(10) << "4.星期四"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_week2_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(10) << "5.星期五"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(15) << " " << endl; Col(0);
        course_week2_menu_list.Deal_input();
        if (course_week2_menu_list.GetBreakword())
        {
            course_week2_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course_week2_menu_list.GetListSelection())
    {
    case 1: {return "星期一"; break; }
    case 2: {return "星期二"; break; }
    case 3: {return "星期三"; break; }
    case 4: {return "星期四"; break; }
    case 5: {return "星期五"; break; }
    }
}
string course::course_time_menu()
{
    List course_time_menu_list(6);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "      上课节次     " << endl; Col(3); cout << "   ";
        if (course_time_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(14) << "1.不选择";
        Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_time_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(14) << "2.一和二"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_time_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(14) << "3.三和四"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_time_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(14) << "4.五和六"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_time_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(14) << "5.七和八"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_time_menu_list.GetListSelection() == 6) Col(7);
        else Col(6);
        cout << left << setw(14) << "6.九和十和十一"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(19) << " " << endl; Col(0);
        course_time_menu_list.Deal_input();
        if (course_time_menu_list.GetBreakword())
        {
            course_time_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course_time_menu_list.GetListSelection())
    {
    case 1: {return "0"; break; }
    case 2: {return "1和2"; break; }
    case 3: {return "3和4"; break; }
    case 4: {return "5和6"; break; }
    case 5: {return "7和8"; break; }
    case 6: {return "9和10和11"; break; }
    }
}
string course::course_time2_menu()
{
    List course_time2_menu_list(5);
    system("cls");
    while (true)
    {
        system("cls");
        Col(3); cout << "     上课节次      " << endl; Col(3); cout << "   ";
        if (course_time2_menu_list.GetListSelection() == 1) Col(7);
        else Col(2);
        cout << left << setw(14) << "1.一和二";
        Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_time2_menu_list.GetListSelection() == 2) Col(7);
        else Col(6);
        cout << left << setw(14) << "2.三和四"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_time2_menu_list.GetListSelection() == 3) Col(7);
        else Col(6);
        cout << left << setw(14) << "3.五和六"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_time2_menu_list.GetListSelection() == 4) Col(7);
        else Col(6);
        cout << left << setw(14) << "4.七和八"; Col(3); cout << "  "; cout << endl; cout << "   ";
        if (course_time2_menu_list.GetListSelection() == 5) Col(7);
        else Col(6);
        cout << left << setw(14) << "5.九和十和十一"; Col(3); cout << "  "; cout << endl;
        Col(3); cout << setw(19) << " " << endl; Col(0);
        course_time2_menu_list.Deal_input();
        if (course_time2_menu_list.GetBreakword())
        {
            course_time2_menu_list.SetBreakword(0);
            break;
        }
    }
    switch (course_time2_menu_list.GetListSelection())
    {
    case 1: {return "1和2"; break; }
    case 2: {return "3和4"; break; }
    case 3: {return "5和6"; break; }
    case 4: {return "7和8"; break; }
    case 5: {return "9和10和11"; break; }
    }
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
    system("cls");
    Col(3); cout << "请输入要选的课程编号:" << endl; Col(0);
    Col(7); cin >> stu_temp_course_id; Col(0);
    //判断课程是否存在
    if (!Iscourse_exist(stu_temp_course_id))
    {
        system("cls");
        Col(3); cout << "选课失败，该课程不存在" << endl; Col(0);
        Sleep(1000);
        return;
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
        Col(3); cout << "选课成功" << endl; Col(0);
        Sleep(1000);
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
        Col(3); cout << "选课失败，可能原因为选课重复或时间冲突" << endl; Col(0);
        Sleep(1000);
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
    system("cls");
    Col(3); cout << "请输入要退的课程编号:" << endl; Col(0);
    Col(7); cin >> stu_temp_course_id; Col(0);
    //是否为已选的课程，不同结果进行不同操作
    if (!Iscourse(stu_temp_course_id))
    {
        system("cls");
        Col(3); cout << "退课失败，可能原因为未选该课程" << endl; Col(0);
        Sleep(1000);
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
    Col(3); cout << "退课成功" << endl; Col(0);
    Sleep(1000);
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
        system("cls");
        Col(3); cout << "暂无选课信息" << endl; Col(0);
        return;
    }
    system("cls");
    //显示课表
    Col(3); cout << left << setw(12) << " ";
    Col(6); cout << left << setw(30) << "星期一";
    Col(3); cout << left << setw(30) << "星期二";
    Col(6); cout << left << setw(30) << "星期三";
    Col(3); cout << left << setw(30) << "星期四";
    Col(6); cout << left << setw(30) << "星期五";
    cout << endl;
    Col(6); cout << left << setw(12) << "一.二节";
    Col(3); cout << left << setw(30) << Get_course("星期一", "1和2");
    Col(6); cout << left << setw(30) << Get_course("星期二", "1和2");
    Col(3); cout << left << setw(30) << Get_course("星期三", "1和2");
    Col(6); cout << left << setw(30) << Get_course("星期四", "1和2");
    Col(3); cout << left << setw(30) << Get_course("星期五", "1和2");
    cout << endl;
    Col(3); cout << left << setw(12) << "三.四节";
    Col(6); cout << left << setw(30) << Get_course("星期一", "3和4");
    Col(3); cout << left << setw(30) << Get_course("星期二", "3和4");
    Col(6); cout << left << setw(30) << Get_course("星期三", "3和4");
    Col(3); cout << left << setw(30) << Get_course("星期四", "3和4");
    Col(6); cout << left << setw(30) << Get_course("星期五", "3和4");
    cout << endl;
    Col(6); cout << left << setw(12) << "五.六节";
    Col(3); cout << left << setw(30) << Get_course("星期一", "5和6");
    Col(6); cout << left << setw(30) << Get_course("星期二", "5和6");
    Col(3); cout << left << setw(30) << Get_course("星期三", "5和6");
    Col(6); cout << left << setw(30) << Get_course("星期四", "5和6");
    Col(3); cout << left << setw(30) << Get_course("星期五", "5和6");
    cout << endl;
    Col(3); cout << left << setw(12) << "七.八节";
    Col(6); cout << left << setw(30) << Get_course("星期一", "7和8");
    Col(3); cout << left << setw(30) << Get_course("星期二", "7和8");
    Col(6); cout << left << setw(30) << Get_course("星期三", "7和8");
    Col(3); cout << left << setw(30) << Get_course("星期四", "7和8");
    Col(6); cout << left << setw(30) << Get_course("星期五", "7和8");
    cout << endl;
    Col(6); cout << left << setw(12) << "九.十.十一节";
    Col(3); cout << left << setw(30) << Get_course("星期一", "9和10和11");
    Col(6); cout << left << setw(30) << Get_course("星期二", "9和10和11");
    Col(3); cout << left << setw(30) << Get_course("星期三", "9和10和11");
    Col(6); cout << left << setw(30) << Get_course("星期四", "9和10和11");
    Col(3); cout << left << setw(30) << Get_course("星期五", "9和10和11");
    Col(0); cout << endl;
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
        Col(3); cout << "今天已经没有课了，睡个好觉吧" << endl; Col(0);
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
    system("cls");
    if (name != "")
    {
        Col(3); cout << "下一节课为:" << name << endl; Col(0);
        Col(3); cout << "时间为:"; Col(0);
        if (time == "1和2")
        {
            Col(3); cout << "8:00-9:40" << endl; Col(0);
        }
        else if (time == "3和4")
        {
            Col(3); cout << "10:00-11:40" << endl; Col(0);
        }
        else if (time == "5和6")
        {
            Col(3); cout << "14:00-15:40" << endl; Col(0);
        }
        else if (time == "7和8")
        {
            Col(3); cout << "16:00-17:40" << endl; Col(0);
        }
        else if (time == "9和10和11")
        {
            Col(3); cout << "19:00-21:35" << endl; Col(0);
        }
    }
    else {
        Col(3); cout << "先休息100分钟再来看下一节课吧" << endl; Col(0);
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
    Col(3); cout << "请输入要添加授课的课程编号:" << endl; Col(0);
    Col(7); cin >> tea_temp_course_id; Col(0);
    //判断课程是否存在
    if (!Iscourse_exist(tea_temp_course_id))
    {
        system("cls");
        Col(3); cout << "添加课程失败，该课程不存在" << endl; Col(0);
        Sleep(1000);
        return;
    }
    //是否冲突，不同结果进行不同操作
    if (!Isconflict())
    {
        //判断课程是否已经存在

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
        Col(3); cout << "添加课程成功" << endl; Col(0);
        Sleep(1000);
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
        Col(3); cout << "添加课程失败，可能原因为课程重复或时间冲突" << endl; Col(0);
        Sleep(1000);
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
    Col(3); cout << "请输入要退的课程编号:" << endl; Col(0);
    Col(7); cin >> tea_temp_course_id; Col(0);
    //是否为存在的课程，不同结果进行不同操作
    if (!Iscourse(tea_temp_course_id))
    {
        system("cls");
        Col(3); cout << "退课失败，可能原因为未选该课程" << endl; Col(0);
        Sleep(1000);
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
    Col(3); cout << "退课成功" << endl; Col(0);
    Sleep(1000);
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
        system("cls");
        Col(3); cout << "暂无选课信息" << endl; Col(0);
        return;
    }
    system("cls");
    //显示课表
    Col(3); cout << left << setw(12) << " ";
    Col(6); cout << left << setw(30) << "星期一";
    Col(3); cout << left << setw(30) << "星期二";
    Col(6); cout << left << setw(30) << "星期三";
    Col(3); cout << left << setw(30) << "星期四";
    Col(6); cout << left << setw(30) << "星期五";
    cout << endl;
    Col(6); cout << left << setw(12) << "一.二节";
    Col(3); cout << left << setw(30) << Get_course("星期一", "1和2");
    Col(6); cout << left << setw(30) << Get_course("星期二", "1和2");
    Col(3); cout << left << setw(30) << Get_course("星期三", "1和2");
    Col(6); cout << left << setw(30) << Get_course("星期四", "1和2");
    Col(3); cout << left << setw(30) << Get_course("星期五", "1和2");
    cout << endl;
    Col(3); cout << left << setw(12) << "三.四节";
    Col(6); cout << left << setw(30) << Get_course("星期一", "3和4");
    Col(3); cout << left << setw(30) << Get_course("星期二", "3和4");
    Col(6); cout << left << setw(30) << Get_course("星期三", "3和4");
    Col(3); cout << left << setw(30) << Get_course("星期四", "3和4");
    Col(6); cout << left << setw(30) << Get_course("星期五", "3和4");
    cout << endl;
    Col(6); cout << left << setw(12) << "五.六节";
    Col(3); cout << left << setw(30) << Get_course("星期一", "5和6");
    Col(6); cout << left << setw(30) << Get_course("星期二", "5和6");
    Col(3); cout << left << setw(30) << Get_course("星期三", "5和6");
    Col(6); cout << left << setw(30) << Get_course("星期四", "5和6");
    Col(3); cout << left << setw(30) << Get_course("星期五", "5和6");
    cout << endl;
    Col(3); cout << left << setw(12) << "七.八节";
    Col(6); cout << left << setw(30) << Get_course("星期一", "7和8");
    Col(3); cout << left << setw(30) << Get_course("星期二", "7和8");
    Col(6); cout << left << setw(30) << Get_course("星期三", "7和8");
    Col(3); cout << left << setw(30) << Get_course("星期四", "7和8");
    Col(6); cout << left << setw(30) << Get_course("星期五", "7和8");
    cout << endl;
    Col(6); cout << left << setw(12) << "九.十.十一节";
    Col(3); cout << left << setw(30) << Get_course("星期一", "9和10和11");
    Col(6); cout << left << setw(30) << Get_course("星期二", "9和10和11");
    Col(3); cout << left << setw(30) << Get_course("星期三", "9和10和11");
    Col(6); cout << left << setw(30) << Get_course("星期四", "9和10和11");
    Col(3); cout << left << setw(30) << Get_course("星期五", "9和10和11");
    Col(0); cout << endl;
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
        Col(3); cout << "今天已经没有课了，睡个好觉吧" << endl; Col(0);
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
    system("cls");
    if (name != "")
    {
        Col(3); cout << "下一节课为:" << name << endl; Col(0);
        Col(3); cout << "时间为:"; Col(0);
        if (time == "1和2")
        {
            Col(3); cout << "8:00-9:40" << endl; Col(0);
        }
        else if (time == "3和4")
        {
            Col(3); cout << "10:00-11:40" << endl; Col(0);
        }
        else if (time == "5和6")
        {
            Col(3); cout << "14:00-15:40" << endl; Col(0);
        }
        else if (time == "7和8")
        {
            Col(3); cout << "16:00-17:40" << endl; Col(0);
        }
        else if (time == "9和10和11")
        {
            Col(3); cout << "19:00-21:35" << endl; Col(0);
        }
    }
    else {
        Col(3); cout << "先休息100分钟再来看下一节课吧" << endl; Col(0);
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
        Col(3); cout << "登录成功" << endl; Col(0);
        this->Read_stu_information();
        Sleep(1000);
        return true;
    }
    else
    {
        system("cls");
        Col(3); cout << "账号或密码错误，请重新输入" << endl; Col(0);
        Sleep(1000);
        return false;
    }
}
//功能函数定义
void student::Change_password()
{
    system("cls");
    Col(3); cout << "请输入新密码:" << endl; Col(0);
    string new_password;
    Col(7); cin >> new_password; Col(0);
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
    Col(3); cout << "修改成功" << endl; Col(0);
    Sleep(1000);
}
void student::Show_stu_information()
{
    system("cls");
    Col(3); cout << "学号:" << this->account << endl; Col(0);//学号不可修改
    Col(3); cout << "姓名:" << this->name << endl; Col(0);
    Col(3); cout << "年级:" << this->stu_grade << endl; Col(0);
    Col(3); cout << "学院:" << this->stu_college << endl; Col(0);
    Col(3); cout << "专业:" << this->stu_profession << endl; Col(0);
    Col(3); cout << "班级:" << this->stu_class << endl; Col(0);
    Col(3); cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl; Col(0);
    system("pause");
}
void student::Course_search()
{
    course::Search_course_information();
    Col(3); cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl; Col(0);
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
    ///
    Col(3); cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl; Col(0);
    system("pause");
}
void student::Show_next_course()
{
    //创建一个临时对象用于显示下一节课的时间和名称
    stu_course stu_course_temp("", "", "", "", "", "", "", "", "", "", "", account, "", "", "");
    stu_course_temp.Show_next_course();
    Col(3); cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl; Col(0);
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
        Col(3); cout << "登录成功" << endl; Col(0);
        this->Read_tea_information();
        Sleep(1000);
        return true;
    }
    else
    {
        system("cls");
        Col(3); cout << "账号或密码错误，请重新输入" << endl; Col(0);
        Sleep(1000);
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
    system("cls");
    Col(3); cout << "请输入新密码:" << endl; Col(0);
    string new_password;
    Col(7); cin >> new_password; Col(0);
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
    Col(3); cout << "修改成功" << endl; Col(0);
    Sleep(1000);
}
void teacher::Show_tea_information()
{
    system("cls");
    Col(3); cout << "工号:" << this->account << endl; Col(0);//工号不可修改
    Col(3); cout << "姓名:" << this->name << endl; Col(0);
    Col(3); cout << "学院:" << this->tea_college << endl; Col(0);
    Col(3); cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl; Col(0);
    system("pause");
}
void teacher::Course_search()
{
    course::Search_course_information();
    Col(3); cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl; Col(0);
    system("pause");
}
void teacher::Show_course()
{
    //创建一个临时对象用于显示课表
    tea_course tea_course_temp("", "", "", "", "", "", "", "", "", "", "", account, "", "", "");
    tea_course_temp.Show_tea_course();
    Col(3); cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl; Col(0);
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
    system("cls");
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
        Col(2); cout << "课程编号:" << left << setw(6) << temp_course_id; Col(0);
        Col(3); cout << "课程名字:" << left << setw(26) << temp_course_name << endl; Col(0);
        //显示学生名单
        while (getline(course_student_list_file, temp))
        {
            Col(3); cout <<left<<setw(10)<< "学生学号:";
            Col(6); cout << left << setw(10) << temp;
            Col(3); cout <<left<<setw(10)<< "学生姓名:";
            Col(6); cout << left << setw(10) << Get_stu_name(temp);
            Col(0); cout << endl;
        }
        course_student_list_file.close();
    }
    tea_course_file.close();
    Col(3); cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl; Col(0);
    system("pause");
}
void teacher::Show_next_course()
{
    //创建一个临时对象用于显示下一节课的时间和名称
    tea_course tea_course_temp("", "", "", "", "", "", "", "", "", "", "", account, "", "", "");
    tea_course_temp.Show_next_course();
    Col(3); cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl; Col(0);
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
        Col(3); cout << "登录成功" << endl; Col(0);
        this->Read_admin_information();
        Sleep(1000);
        return true;
    }
    else
    {
        system("cls");
        Col(3); cout << "账号或密码错误，请重新输入" << endl; Col(0);
        Sleep(1000);
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
    system("cls");
    Col(3); cout << "请输入您的新密码:" << endl; Col(0);
    string new_password;
    Col(7); cin >> new_password; Col(0);
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
    Col(3); cout << "修改成功" << endl; Col(0);
    Sleep(1000);
}
void admin::Show_admin_information()
{
    system("cls");
    Col(3); cout << "账号:" << this->account << endl; Col(0);//账号不可修改
    Col(3); cout << "姓名:" << this->name << endl; Col(0);
    Col(3); cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl; Col(0);
    system("pause");
}
void admin::Add_stu_information()
{
    system("cls");
    Col(3); 
    cout << "请输入学生信息:" << endl;
    cout << "(默认密码为123456)" << endl;
    cout << "学号:";
    Col(7); cin >> temp_accountORcourseid_class; 
    Col(0);
    //判断学号是否已经重复
    if (Is_stu_exist(temp_accountORcourseid_class))
    {
        system("cls");
        Col(3); cout << "添加失败，学号重复" << endl; Col(0);
        Sleep(1000);
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
    Col(3); cout << "姓名:";
    string name;
    Col(7); cin >> name;
    Col(3); cout << "年级:";
    string stu_grade;
    Col(7); cin >> stu_grade;
    Col(3); cout << "学院:(请选择)"; Col(0);
    string stu_college;
    cout << endl << endl << endl;
    system("pause");
    stu_college = course::course_college_menu();
    system("cls");
    Col(3);
    cout << "请输入学生信息:" << endl;
    cout << "(默认密码为123456)" << endl;
    cout << "学号:" << temp_accountORcourseid_class << endl;
    cout << "姓名:" << name << endl;
    cout << "年级:" << stu_grade << endl;
    cout << "学院:" << stu_college << endl;
    Col(0);
    string stu_profession;
    if (stu_college != "0")
    {
        Col(3); cout << "专业:(请选择)"; Col(0);
        cout << endl << endl << endl;
        system("pause");
        if (stu_college == "药学院") {
            stu_profession = course::course1_profession_menu();
        }
        else if (stu_college == "医学院") {
            stu_profession = course::course2_profession_menu();
        }
        else if (stu_college == "法学院") {
            stu_profession = course::course3_profession_menu();
        }
        else if (stu_college == "文学院") {
            stu_profession = course::course4_profession_menu();
        }
        else if (stu_college == "财经学院") {
            stu_profession = course::course5_profession_menu();
        }
        else if (stu_college == "管理学院") {
            stu_profession = course::course6_profession_menu();
        }
        else if (stu_college == "艺术学院") {
            stu_profession = course::course7_profession_menu();
        }
        else if (stu_college == "外国语学院") {
            stu_profession = course::course8_profession_menu();
        }
        else if (stu_college == "知识产权学院") {
            stu_profession = course::course9_profession_menu();
        }
        else if (stu_college == "化学化工学院") {
            stu_profession = course::course10_profession_menu();
        }
        else if (stu_college == "机械工程学院") {
            stu_profession = course::course11_profession_menu();
        }
        else if (stu_college == "农业工程学院") {
            stu_profession = course::course12_profession_menu();
        }
        else if (stu_college == "教师教育学院") {
            stu_profession = course::course13_profession_menu();
        }
        else if (stu_college == "生命科学学院") {
            stu_profession = course::course14_profession_menu();
        }
        else if (stu_college == "数学科学学院") {
            stu_profession = course::course15_profession_menu();
        }
        else if (stu_college == "马克思主义学院") {
            stu_profession = course::course16_profession_menu();
        }
        else if (stu_college == "电气信息工程学院") {
            stu_profession = course::course17_profession_menu();
        }
        else if (stu_college == "能源与动力工程学院") {
            stu_profession = course::course18_profession_menu();
        }
        else if (stu_college == "汽车与交通工程学院") {
            stu_profession = course::course19_profession_menu();
        }
        else if (stu_college == "食品与生物工程学院") {
            stu_profession = course::course20_profession_menu();
        }
        else if (stu_college == "土木工程与力学学院") {
            stu_profession = course::course21_profession_menu();
        }
        else if (stu_college == "物理与电子工程学院") {
            stu_profession = course::course22_profession_menu();
        }
        else if (stu_college == "材料科学与工程学院") {
            stu_profession = course::course23_profession_menu();
        }
        else if (stu_college == "环境与安全工程学院") {
            stu_profession = course::course24_profession_menu();
        }
        else if (stu_college == "计算机科学与通信工程学院") {
            stu_profession = course::course25_profession_menu();
        }
    }
    else {
        stu_profession = "0";
    }
    system("cls");
    Col(3); cout << "请输入学生信息:" << endl;
    cout << "(默认密码为123456)" << endl;
    cout << "学号:" << temp_accountORcourseid_class << endl;
    cout << "姓名:" << name << endl;
    cout << "年级:" << stu_grade << endl;
    cout << "学院:" << stu_college << endl;
    cout << "专业:" << stu_profession << endl;
    Col(0);
    Col(3); cout << "班级:";
    string stu_class;
    Col(7); cin >> stu_class; Col(0);
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
    Col(3); cout << "添加成功" << endl; Col(0);
    Sleep(1000);
}
void admin::Delete_stu_information()
{
    system("cls");
    Col(3); cout << "请输入要删除的学生学号:" << endl; Col(0);
    Col(7); cin >> temp_accountORcourseid_class; Col(0);
    //判断学生是否存在
    if (!Is_stu_exist(temp_accountORcourseid_class))
    {
        system("cls");
        Col(3); cout << "删除失败，该学号不存在" << endl; Col(0);
        Sleep(1000);
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
    Col(3); cout << "删除成功" << endl; Col(0);
    Sleep(1000);
}
void admin::Change_stu_password()
{
    system("cls");
    Col(3); cout << "请输入要修改密码的学生学号:" << endl; Col(0);
    Col(7); cin >> temp_accountORcourseid_class; Col(0);
    //判断学生是否存在
    if (!Is_stu_exist(temp_accountORcourseid_class))
    {
        system("cls");
        Col(3); cout << "修改失败，该学号不存在" << endl; Col(0);
        Sleep(1000);
        return;
    }
    student stu(temp_accountORcourseid_class, "", "", "", "", "", "");
    stu.Change_password();
}
void admin::Add_tea_information()
{
    system("cls");
    Col(3);
    cout << "请输入教师信息:" << endl;
    cout << "(默认密码为123456)" << endl;
    cout << "工号:";
    Col(7); cin >> temp_accountORcourseid_class; Col(0);
    //判断工号是否已经重复
    if (Is_tea_exist(temp_accountORcourseid_class))
    {
        system("cls");
        Col(3); cout << "添加失败，工号重复" << endl; Col(0);
        Sleep(1000);
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
    Col(3); cout << "姓名:";
    string name;
    Col(7); cin >> name; Col(0);
    Col(3); cout << "学院:(请选择)"; Col(0);
    string tea_college;
    cout << endl << endl << endl;
    system("pause");
    tea_college = course::course_college_menu();
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
    Col(3); cout << "添加成功" << endl; Col(0);
    Sleep(1000);
}
void admin::Delete_tea_information()
{
    system("cls");
    Col(3); cout << "请输入要删除的教师工号:" << endl; Col(0);
    Col(7); cin >> temp_accountORcourseid_class; Col(0);
    //判断教师是否存在
    if (!Is_tea_exist(temp_accountORcourseid_class))
    {
        system("cls");
        Col(3); cout << "删除失败，该工号不存在" << endl; Col(0);
        Sleep(1000);
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
    Col(3); cout << "删除成功" << endl; Col(0);
    Sleep(1000);
}
void admin::Change_tea_password()
{
    system("cls");
    Col(3); cout << "请输入要修改密码的教师工号:" << endl; Col(0);
    Col(7); cin >> temp_accountORcourseid_class; Col(0);
    //判断教师是否存在
    if (!Is_tea_exist(temp_accountORcourseid_class))
    {
        system("cls");
        Col(3); cout << "修改失败，该工号不存在" << endl; Col(0);
        Sleep(1000);
        return;
    }
    teacher tea(temp_accountORcourseid_class, "", "", "");
    tea.Change_password();
}
void admin::Add_course_information()
{
    system("cls");
    Col(3); cout << "请输入课程信息:" << endl; Col(0);
    Col(3); cout << "课程编号:"; Col(0);
    Col(7); cin >> temp_accountORcourseid_class; Col(0);
    //判断课程是否已经重复
    if (Is_course_exist(temp_accountORcourseid_class))
    {
        system("cls");
        Col(3); cout << "添加失败，课程编号重复" << endl; Col(0);
        Sleep(1000);
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
    Col(3); cout << "课程名称:"; Col(0);
    string course_name;
    Col(7); cin >> course_name; Col(0);
    Col(3); cout << "年级:"; Col(0);
    string course_grade;
    Col(7); cin >> course_grade; Col(0);
    Col(3); cout << "学院:(请选择)"; Col(0);
    string course_college;
    cout << endl << endl << endl;
    system("pause");
    course_college = course::course_college_menu();
    system("cls");
    Col(3); cout << "请输入课程信息:" << endl;
    cout << "课程编号:" << temp_accountORcourseid_class << endl;
    cout << "课程名称:" << course_name << endl;
    cout << "年级:" << course_grade << endl;
    cout << "学院:" << course_college << endl;
    Col(0);
    string course_profession;
    if (course_college != "0")
    {
        Col(3); cout << "专业:(请选择)"; Col(0);
        cout << endl << endl << endl;
        system("pause");
        if (course_college == "药学院") {
            course_profession = course::course1_profession_menu();
        }
        else if (course_college == "医学院") {
            course_profession = course::course2_profession_menu();
        }
        else if (course_college == "法学院") {
            course_profession = course::course3_profession_menu();
        }
        else if (course_college == "文学院") {
            course_profession = course::course4_profession_menu();
        }
        else if (course_college == "财经学院") {
            course_profession = course::course5_profession_menu();
        }
        else if (course_college == "管理学院") {
            course_profession = course::course6_profession_menu();
        }
        else if (course_college == "艺术学院") {
            course_profession = course::course7_profession_menu();
        }
        else if (course_college == "外国语学院") {
            course_profession = course::course8_profession_menu();
        }
        else if (course_college == "知识产权学院") {
            course_profession = course::course9_profession_menu();
        }
        else if (course_college == "化学化工学院") {
            course_profession = course::course10_profession_menu();
        }
        else if (course_college == "机械工程学院") {
            course_profession = course::course11_profession_menu();
        }
        else if (course_college == "农业工程学院") {
            course_profession = course::course12_profession_menu();
        }
        else if (course_college == "教师教育学院") {
            course_profession = course::course13_profession_menu();
        }
        else if (course_college == "生命科学学院") {
            course_profession = course::course14_profession_menu();
        }
        else if (course_college == "数学科学学院") {
            course_profession = course::course15_profession_menu();
        }
        else if (course_college == "马克思主义学院") {
            course_profession = course::course16_profession_menu();
        }
        else if (course_college == "电气信息工程学院") {
            course_profession = course::course17_profession_menu();
        }
        else if (course_college == "能源与动力工程学院") {
            course_profession = course::course18_profession_menu();
        }
        else if (course_college == "汽车与交通工程学院") {
            course_profession = course::course19_profession_menu();
        }
        else if (course_college == "食品与生物工程学院") {
            course_profession = course::course20_profession_menu();
        }
        else if (course_college == "土木工程与力学学院") {
            course_profession = course::course21_profession_menu();
        }
        else if (course_college == "物理与电子工程学院") {
            course_profession = course::course22_profession_menu();
        }
        else if (course_college == "材料科学与工程学院") {
            course_profession = course::course23_profession_menu();
        }
        else if (course_college == "环境与安全工程学院") {
            course_profession = course::course24_profession_menu();
        }
        else if (course_college == "计算机科学与通信工程学院") {
            course_profession = course::course25_profession_menu();
        }
    }
    else {
        course_profession = "0";
    }
    system("cls");
    Col(3); cout << "请输入课程信息:" << endl;
    cout << "课程编号:" << temp_accountORcourseid_class << endl;
    cout << "课程名称:" << course_name << endl;
    cout << "年级:" << course_grade << endl;
    cout << "学院:" << course_college << endl;
    cout << "专业:" << course_profession << endl;
    Col(0);
    Col(3); cout << "开课学院:(请选择)"; Col(0);
    string course_college_open;
    cout << endl << endl << endl;
    system("pause");
    course_college_open = course::course_college_menu();
    system("cls");
    Col(3); cout << "请输入课程信息:" << endl;
    cout << "课程编号:" << temp_accountORcourseid_class << endl;
    cout << "课程名称:" << course_name << endl;
    cout << "年级:" << course_grade << endl;
    cout << "学院:" << course_college << endl;
    cout << "专业:" << course_profession << endl;
    cout << "开课学院:" << course_college_open << endl;
    Col(0);
    Col(3); cout << "课程类别:(请选择)"; Col(0);
    string course_type;
    cout << endl << endl << endl;
    system("pause");
    course_type = course::course_type_menu();
    system("cls");
    Col(3); cout << "请输入课程信息:" << endl;
    cout << "课程编号:" << temp_accountORcourseid_class << endl;
    cout << "课程名称:" << course_name << endl;
    cout << "年级:" << course_grade << endl;
    cout << "学院:" << course_college << endl;
    cout << "专业:" << course_profession << endl;
    cout << "开课学院:" << course_college_open << endl;
    cout << "课程类别:" << course_type << endl;
    Col(0);
    Col(3); cout << "课程性质:(请选择)"; Col(0);
    string course_nature;
    cout << endl << endl << endl;
    system("pause");
    course_nature = course::course_nature_menu();
    system("cls");
    Col(3); cout << "请输入课程信息:" << endl;
    cout << "课程编号:" << temp_accountORcourseid_class << endl;
    cout << "课程名称:" << course_name << endl;
    cout << "年级:" << course_grade << endl;
    cout << "学院:" << course_college << endl;
    cout << "专业:" << course_profession << endl;
    cout << "开课学院:" << course_college_open << endl;
    cout << "课程类别:" << course_type << endl;
    cout << "课程性质:" << course_nature << endl;
    Col(0);
    Col(3); cout << "课程归属:(请选择)"; Col(0);
    string course_belong;
    cout << endl << endl << endl;
    system("pause");
    course_belong = course::course_belong_menu();
    system("cls");
    Col(3); cout << "请输入课程信息:" << endl;
    cout << "课程编号:" << temp_accountORcourseid_class << endl;
    cout << "课程名称:" << course_name << endl;
    cout << "年级:" << course_grade << endl;
    cout << "学院:" << course_college << endl;
    cout << "专业:" << course_profession << endl;
    cout << "开课学院:" << course_college_open << endl;
    cout << "课程类别:" << course_type << endl;
    cout << "课程性质:" << course_nature << endl;
    cout << "课程归属:" << course_belong << endl;
    Col(0);
    Col(3); cout << "上课星期:(请选择)"; Col(0);
    string course_week;
    cout << endl << endl << endl;
    system("pause");
    course_week = course::course_week2_menu();
    system("cls");
    Col(3); cout << "请输入课程信息:" << endl;
    cout << "课程编号:" << temp_accountORcourseid_class << endl;
    cout << "课程名称:" << course_name << endl;
    cout << "年级:" << course_grade << endl;
    cout << "学院:" << course_college << endl;
    cout << "专业:" << course_profession << endl;
    cout << "开课学院:" << course_college_open << endl;
    cout << "课程类别:" << course_type << endl;
    cout << "课程性质:" << course_nature << endl;
    cout << "课程归属:" << course_belong << endl;
    cout << "上课星期:" << course_week << endl;
    Col(0);
    Col(3); cout << "上课节次:(请选择)"; Col(0);
    string course_time;
    cout << endl << endl << endl;
    system("pause");
    course_time = course::course_time2_menu();
    system("cls");
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
    Col(3); cout << "添加成功" << endl; Col(0);
    Sleep(1000);
}
void admin::Delete_course_information()
{
    system("cls");
    Col(3); cout << "请输入要删除的课程编号:" << endl; Col(0);
    Col(7); cin >> temp_accountORcourseid_class; Col(0);
    //判断课程是否存在
    if (!Is_course_exist(temp_accountORcourseid_class))
    {
        system("cls");
        Col(3); cout << "删除失败，该课程编号不存在" << endl; Col(0);
        Sleep(1000);
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
    //删除course_student_list文件夹下学生选课信息
    remove(("course_student_list\\" + temp_accountORcourseid_class + ".txt").c_str());
    //删除course_teacher_list文件夹下教师选课信息
    remove(("course_teacher_list\\" + temp_accountORcourseid_class + ".txt").c_str());
    system("cls");
    Col(3); cout << "删除成功" << endl; Col(0);
    Sleep(1000);
}
void admin::Search_course_information()
{
    course::Search_course_information();
    Col(3); cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl; Col(0);
    system("pause");
}
void admin::Search_stu_information()
{
    system("cls");
    Col(3); cout << "请输入要查询的学生学号:" << endl; Col(0);
    Col(7); cin >> temp_accountORcourseid_class; Col(0);
    //判断学生是否存在
    if (!Is_stu_exist(temp_accountORcourseid_class))
    {
        system("cls");
        Col(3); cout << "查询失败，该学号不存在" << endl; Col(0);
        Sleep(1000);
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
    Col(3); cout << "查询成功:" << endl; Col(0);
    //创建一个临时对象用于显示学生信息
    student stu(temp_accountORcourseid_class, password, name, stu_class, stu_grade, stu_college, stu_profession);
    stu.Show_stu_information();
}
void admin::Search_tea_information()
{
    system("cls");
    Col(3); cout << "请输入要查询的教师工号:" << endl; Col(0);
    Col(7); cin >> temp_accountORcourseid_class; Col(0);
    //判断教师是否存在
    if (!Is_tea_exist(temp_accountORcourseid_class))
    {
        system("cls");
        Col(3); cout << "查询失败，该工号不存在" << endl; Col(0);
        Sleep(1000);
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
    Col(3); cout << "查询成功:" << endl; Col(0);
    //创建一个临时对象用于显示教师信息
    teacher tea(temp_accountORcourseid_class, password, name, tea_college);
    tea.Show_tea_information();
}
void admin::Search_stu_course_information()
{
    system("cls");
    Col(3); cout << "请输入要查询的学生学号:" << endl; Col(0);
    Col(7); cin >> temp_accountORcourseid_class; Col(0);
    //判断学生是否存在
    if (!Is_stu_exist(temp_accountORcourseid_class))
    {
        system("cls");
        Col(3); cout << "查询失败，该学号不存在" << endl; Col(0);
        Sleep(1000);
        return;
    }
    system("cls");
    Col(3); cout << "查询成功:" << endl; Col(0);
    //创建一个临时对象用于显示课表
    stu_course stu_course_temp("", "", "", "", "", "", "", "", "", "", "", temp_accountORcourseid_class, "", "", "");
    stu_course_temp.Show_course();
    Col(3); cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl; Col(0);
    system("pause");
}
void admin::Search_tea_course_information()
{
    system("cls");
    Col(3); cout << "请输入要查询的教师工号:" << endl; Col(0);
    Col(7); cin >> temp_accountORcourseid_class; Col(0);
    //判断教师是否存在
    if (!Is_tea_exist(temp_accountORcourseid_class))
    {
        system("cls");
        Col(3); cout << "查询失败，该工号不存在" << endl; Col(0);
        Sleep(1000);
        return;
    }
    system("cls");
    Col(3); cout << "查询成功:" << endl; Col(0);
    //创建一个临时对象用于显示课表
    tea_course tea_course_temp("", "", "", "", "", "", "", "", "", "", "", temp_accountORcourseid_class, "", "", "");
    tea_course_temp.Show_tea_course();
    Col(3); cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl; Col(0);
    system("pause");
}
void admin::Add_stu_course()
{
    system("cls");
    Col(3); cout << "请输入要添加课程的学生学号:" << endl; Col(0);
    Col(7); cin >> temp_accountORcourseid_class; Col(0);
    //判断学生是否存在
    if (!Is_stu_exist(temp_accountORcourseid_class))
    {
        system("cls");
        Col(3); cout << "添加失败，该学号不存在" << endl; Col(0);
        Sleep(1000);
        return;
    }
    //创建一个临时对象用于选课
    stu_course stu_course_temp("", "", "", "", "", "", "", "", "", "", "", temp_accountORcourseid_class, "", "", "");
    stu_course_temp.Choose_course();
}
void admin::Delete_stu_course()
{
    system("cls");
    Col(3); cout << "请输入要删除课程的学生学号:" << endl; Col(0);
    Col(7); cin >> temp_accountORcourseid_class; Col(0);
    //判断学生是否存在
    if (!Is_stu_exist(temp_accountORcourseid_class))
    {
        system("cls");
        Col(3); cout << "删除失败，该学号不存在" << endl; Col(0);
        Sleep(1000);
        return;
    }
    //创建一个临时对象用于退课
    stu_course stu_course_temp("", "", "", "", "", "", "", "", "", "", "", temp_accountORcourseid_class, "", "", "");
    stu_course_temp.Drop_course();
}
void admin::Add_tea_course()
{
    system("cls");
    Col(3); cout << "请输入要添加课程的教师工号:" << endl; Col(0);
    Col(7); cin >> temp_accountORcourseid_class; Col(0);
    //判断教师是否存在
    if (!Is_tea_exist(temp_accountORcourseid_class))
    {
        system("cls");
        Col(3); cout << "添加失败，该工号不存在" << endl; Col(0);
        Sleep(1000);
        return;
    }
    //创建一个临时对象用于添加课程
    tea_course tea_course_temp("", "", "", "", "", "", "", "", "", "", "", temp_accountORcourseid_class, "", "", "");
    access_private_tea_course(tea_course_temp);
}
void admin::Delete_tea_course()
{
    system("cls");
    Col(3); cout << "请输入要删除课程的教师工号:" << endl; Col(0);
    Col(7); cin >> temp_accountORcourseid_class; Col(0);
    //判断教师是否存在
    if (!Is_tea_exist(temp_accountORcourseid_class))
    {
        system("cls");
        Col(3); cout << "删除失败，该工号不存在" << endl; Col(0);
        Sleep(1000);
        return;
    }
    //创建一个临时对象用于删除课程
    tea_course tea_course_temp("", "", "", "", "", "", "", "", "", "", "", temp_accountORcourseid_class, "", "", "");
    access_private_tea_course1(tea_course_temp);
}
void admin::Search_course_tea_stu_information()
{
    system("cls");
    Col(3); cout << "请输入要查询的课程编号:" << endl; Col(0);
    Col(7); cin >> temp_accountORcourseid_class; Col(0);
    if (!Is_course_exist(temp_accountORcourseid_class))
    {
        system("cls");
        Col(3); cout << "查询失败，该课程编号不存在" << endl; Col(0);
        Sleep(1000);
        return;
    }
    //打开course_teacher_list文件夹下的课程文件
    fstream course_tea_list_file("./course_teacher_list/" + temp_accountORcourseid_class + ".txt", ios::in);
    //打开course_student_list文件夹下的课程文件
    fstream course_stu_list_file("./course_student_list/" + temp_accountORcourseid_class + ".txt", ios::in);
    string temp;
    //读取教师名单
    Col(2); cout << "教师名单:" << endl; Col(0);
    while (getline(course_tea_list_file, temp))
    {
        Col(3); cout << left << setw(5) << "工号:";
        Col(6); cout << left << setw(10) << temp;
        Col(3); cout << left << setw(5) << "姓名:";
        Col(6); cout << left << setw(10) << Get_tea_name(temp);
        Col(0); cout << endl;
    }
    //读取学生名单
    Col(2); cout << "学生名单:" << endl; Col(0);
    while (getline(course_stu_list_file, temp))
    {
        Col(3); cout << left << setw(5) << "学号:";
        Col(6); cout << left << setw(10) << temp;
        Col(3); cout << left << setw(5) << "姓名:";
        Col(6); cout << left << setw(10) << Get_stu_name(temp);
        Col(0); cout << endl;
    }
    course_tea_list_file.close();
    course_stu_list_file.close();
    Col(3); cout << endl << endl << endl << "按下任意键返回上一菜单..." << endl; Col(0);
    system("pause");
}
