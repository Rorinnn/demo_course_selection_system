#include <windows.h>
#include <iostream>
#include "course_selection_system.h"
using namespace std;

//学生页面
void stu_menu()
{
    while (true)
    {
        system("cls");
        cout << "请输入您的账号:" << endl;
        string account;
        cin >> account;
        cout << "请输入您的密码:" << endl;
        string password;
        cin >> password;
        student stu(account, password, "", "", "", "", "");
        if (stu.Login())
        {
            while (true)
            {
                Sleep(1000);
                system("cls");
                cout << "请选择您的操作:" << endl;
                cout << "1.修改密码" << endl;
                cout << "2.显示个人信息" << endl;
                cout << "3.查询课程信息" << endl;
                cout << "4.选课" << endl;
                cout << "5.退课" << endl;
                cout << "6.显示课表" << endl;
                cout << "7.下一节课" << endl;
                cout << "0.退出登录" << endl;
                int choose;
                cin >> choose;
                system("cls");
                switch (choose)
                {
                case 1: {stu.Change_password(); break; }
                case 2: {stu.Show_stu_information(); break; }
                case 3: {stu.Course_search(); break; }
                case 4: {stu.Choose_course(); break; }
                case 5: {stu.Drop_course(); break; }
                case 6: {stu.Show_course(); break; }
                case 7: {stu.Show_next_course(); break; }
                case 0: {return; }
                }
            }
        }
        Sleep(1000);
    }
}

//教师页面
void tea_menu()
{
    while (true)
    {
        system("cls");
        cout << "请输入您的账号:" << endl;
        string account;
        cin >> account;
        cout << "请输入您的密码:" << endl;
        string password;
        cin >> password;
        teacher tea(account, password, "", "");
        if (tea.Login())
        {
            while (true)
            {
                Sleep(1000);
                system("cls");
                cout << "请选择您的操作:" << endl;
                cout << "1.修改密码" << endl;
                cout << "2.显示个人信息" << endl;
                cout << "3.查询课程信息" << endl;
                cout << "4.显示课表" << endl;
                cout << "5.显示所教课程的学生名单" << endl;
                cout << "6.下一节课" << endl;
                cout << "0.退出登录" << endl;
                int choose;
                cin >> choose;
                system("cls");
                switch (choose)
                {
                case 1: {tea.Change_password(); break; }
                case 2: {tea.Show_tea_information(); break; }
                case 3: {tea.Course_search(); break; }
                case 4: {tea.Show_course(); break; }
                case 5: {tea.Show_stu_list(); break; }
                case 6: {tea.Show_next_course(); break; }
                case 0: {return; break; }
                }
            }
        }
        Sleep(1000);
    }
}

//管理员页面
void admin_menu()
{
    while (true)
    {
        system("cls");
        cout << "请输入您的账号:" << endl;
        string account;
        cin >> account;
        cout << "请输入您的密码:" << endl;
        string password;
        cin >> password;
        admin admin(account, password, "");
        if (admin.Login())
        {
            while (true)
            {
                Sleep(1000);
                system("cls");
                cout << "请选择您的操作:" << endl;
                cout << "1.修改密码" << endl;
                cout << "2.显示个人信息" << endl;
                cout << "3.添加学生信息" << endl;
                cout << "4.删除学生信息" << endl;
                cout << "5.修改学生密码" << endl;
                cout << "6.添加教师信息" << endl;
                cout << "7.删除教师信息" << endl;
                cout << "8.修改教师密码" << endl;
                cout << "9.添加课程信息" << endl;
                cout << "10.删除课程信息" << endl;
                cout << "11.查询课程信息" << endl;
                cout << "12.查询学生信息" << endl;
                cout << "13.查询教师信息" << endl;
                cout << "14.查询学生选课信息" << endl;
                cout << "15.查询教师授课信息" << endl;
                cout << "16.添加学生选课" << endl;
                cout << "17.删除学生选课" << endl;
                cout << "18.添加教师授课" << endl;
                cout << "19.删除教师授课" << endl;
                cout << "20.查询某课程的教师和学生名单" << endl;
                cout << "0.退出登录" << endl;
                int choose;
                cin >> choose;
                system("cls");
                switch (choose)
                {
                case 1: {admin.Change_password(); break; }
                case 2: {admin.Show_admin_information(); break; }
                case 3: {admin.Add_stu_information(); break; }
                case 4: {admin.Delete_stu_information(); break; }
                case 5: {admin.Change_stu_password(); break; }
                case 6: {admin.Add_tea_information(); break; }
                case 7: {admin.Delete_tea_information(); break; }
                case 8: {admin.Change_tea_password(); break; }
                case 9: {admin.Add_course_information(); break; }
                case 10: {admin.Delete_course_information(); break; }
                case 11: {admin.Search_course_information(); break; }
                case 12: {admin.Search_stu_information(); break; }
                case 13: {admin.Search_tea_information(); break; }
                case 14: {admin.Search_stu_course_information(); break; }
                case 15: {admin.Search_tea_course_information(); break; }
                case 16: {admin.Add_stu_course(); break; }
                case 17: {admin.Delete_stu_course(); break; }
                case 18: {admin.Add_tea_course(); break; }
                case 19: {admin.Delete_tea_course(); break; }
                case 20: {admin.Search_course_tea_stu_information(); break; }
                case 0: {return; break; }
                }
            }
        }
        Sleep(1000);
    }
}

//主页面
void menu()
{
    while (true)
    {
        cout << "欢迎来到大学生选课系统" << endl;
        cout << "请选择您的身份:" << endl;
        cout << "1.学生" << endl;
        cout << "2.教师" << endl;
        cout << "3.管理员" << endl;
        int identity;
        cin >> identity;
        system("cls");
        switch (identity)
        {
        case 1: {stu_menu(); break; }
        case 2: {tea_menu(); break; }
        case 3: {admin_menu(); break; }
        }
    }
}

int main() {
    menu();
    return 0;
}