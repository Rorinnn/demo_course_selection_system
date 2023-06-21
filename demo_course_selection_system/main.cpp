#include "console_list.h"
#include "course_selection_system.h"
using namespace std;

void main_menu();
void main_menu_work(int Option_selection);
void stu_menu();
void tea_menu();
void admin_menu();
void admin_stu_menu(admin& ad);
void admin_tea_menu(admin& ad);
void admin_admin_menu(admin& ad);
void admin_course_menu(admin& ad);

int main()
{
	main_menu();
	return 0;
}

//主菜单
void main_menu()
{
	List main_menu_list(4);
	while (true)
	{
		while (true)
		{
			system("cls");
			Col(1); cout << "                                                                \n"; Col(0);
			Col(1); cout << " ";
			Col(3); cout << "                      欢迎来到学生选课系统                    "; Col(0); Col(1); cout << " \n"; Col(0);
			Col(1); cout << " ";
			Col(3); cout << "请选择您的登录方式：                                          "; Col(0); Col(1); cout << " \n"; Col(0);
			Col(1); cout << " ";
			if (main_menu_list.GetListSelection() == 1) Col(7);
			else Col(3);
			cout << "                         学生登录                             "; Col(0); Col(1); cout << " \n"; Col(0);
			Col(1); cout << " ";
			Col(3); cout << "                                                              "; Col(0); Col(1); cout << " \n"; Col(0);
			Col(1); cout << " ";
			if (main_menu_list.GetListSelection() == 2) Col(7);
			else Col(3);
			cout << "                         教师登录                             "; Col(0); Col(1); cout << " \n"; Col(0);
			Col(1); cout << " ";
			Col(3); cout << "                                                              "; Col(0); Col(1); cout << " \n"; Col(0);
			Col(1); cout << " ";
			if (main_menu_list.GetListSelection() == 3) Col(7);
			else Col(3);
			cout << "                         管理员登录                           "; Col(0); Col(1); cout << " \n"; Col(0);
			Col(1); cout << " ";
			Col(3); cout << "                                                              "; Col(0); Col(1); cout << " \n"; Col(0);
			Col(1); cout << " ";
			if (main_menu_list.GetListSelection() == 4) Col(7);
			else Col(3);
			cout << "                         退出系统                             "; Col(0); Col(1); cout << " \n"; Col(0);
			Col(1); cout << "                                                                \n"; Col(0);
			main_menu_list.Deal_input();
			if (main_menu_list.GetBreakword())
			{
				main_menu_list.SetBreakword(0);
				break;
			}
		}
		main_menu_work(main_menu_list.GetListSelection());
	}
}
void main_menu_work(int Option_selection)
{
	switch (Option_selection)
	{
	case 1:stu_menu(); break;
	case 2:tea_menu(); break;
	case 3:admin_menu(); break;
	case 4:exit(0); break;
	}
}

//学生菜单
void stu_menu()
{
	List stu_menu_list(8);
	system("cls");
	Col(3); cout << "请输入您的账号:" << endl; Col(0);
	string account;
	Col(7); cin >> account; Col(0);
	Col(3); cout << "请输入您的密码:" << endl; Col(0);
	string password;
	Col(7); cin >> password; Col(0);
	student stu(account, password, "", "", "", "", "");
	if (stu.Login()) 
	{
		while (true)
		{
			while (true)
			{
				system("cls");
				Col(3); cout << "                   学生菜单               " << endl; cout << "  ";
				if (stu_menu_list.GetListSelection() == 1) Col(7);
				else Col(6);
				cout << "               1.修改密码             "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
				Col(3); cout << " ";
				if (stu_menu_list.GetListSelection() == 2) Col(7);
				else Col(6);
				cout << "             2.显示个人信息           "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
				Col(3); cout << " ";
				if (stu_menu_list.GetListSelection() == 3) Col(7);
				else Col(6);
				cout << "             3.查询课程信息           "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
				Col(3); cout << " ";
				if (stu_menu_list.GetListSelection() == 4) Col(7);
				else Col(6);
				cout << "                 4.选课               "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
				Col(3); cout << " ";
				if (stu_menu_list.GetListSelection() == 5) Col(7);
				else Col(6);
				cout << "                 5.退课               "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
				Col(3); cout << " ";
				if (stu_menu_list.GetListSelection() == 6) Col(7);
				else Col(6);
				cout << "               6.显示课表             "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
				Col(3); cout << " ";
				if (stu_menu_list.GetListSelection() == 7) Col(7);
				else Col(6);
				cout << "               7.下一节课             "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
				Col(3); cout << " ";
				if (stu_menu_list.GetListSelection() == 8) Col(7);
				else Col(6);
				cout << "               8.返回主页             "; Col(3); cout << "  "; Col(0); cout << endl;
				Col(3); cout << "                                          " << endl; Col(0);
				if (stu_menu_list.GetListSelection() == -1) { cout << "此页面没有上一页"; stu_menu_list.SetListSelection(1); }
				if (stu_menu_list.GetListSelection() == -2) { cout << "此页面没有下一页"; stu_menu_list.SetListSelection(1); }
				stu_menu_list.Deal_input();
				if (stu_menu_list.GetBreakword())
				{
					stu_menu_list.SetBreakword(0);
					break;
				}
			}
			switch (stu_menu_list.GetListSelection())
			{
				case 1: {stu.Change_password(); break; }
				case 2: {stu.Show_stu_information(); break; }
				case 3: {stu.Course_search(); break; }
				case 4: {stu.Choose_course(); break; }
				case 5: {stu.Drop_course(); break; }
				case 6: {stu.Show_course(); break; }
				case 7: {stu.Show_next_course(); break; }
				case 8: {stu_menu_list.SetBreakword(1); break; }
			}
			if (stu_menu_list.GetBreakword())
			{
				stu_menu_list.SetBreakword(0);
				break;
			}
		}
	}
}

//教师菜单
void tea_menu()
{
	List tea_menu_list(7);
	system("cls");
	Col(3); cout << "请输入您的账号:" << endl; Col(0);
	string account;
	Col(7); cin >> account; Col(0);
	Col(3); cout << "请输入您的密码:" << endl; Col(0);
	string password;
	Col(7); cin >> password; Col(0);
	teacher tea(account, password, "", "");
	if (tea.Login())
	{
		while (true)
		{
			while (true)
			{
				system("cls");
				Col(3); cout << "                   教师菜单                 " << endl; cout << "  ";
				if (tea_menu_list.GetListSelection() == 1) Col(7);
				else Col(6);
				cout << "               1.修改密码               "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
				Col(3); cout << " ";
				if (tea_menu_list.GetListSelection() == 2) Col(7);
				else Col(6);
				cout << "             2.显示个人信息             "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
				Col(3); cout << " ";
				if (tea_menu_list.GetListSelection() == 3) Col(7);
				else Col(6);
				cout << "             3.查询课程信息             "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
				Col(3); cout << " ";
				if (tea_menu_list.GetListSelection() == 4) Col(7);
				else Col(6);
				cout << "               4.显示课表               "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
				Col(3); cout << " ";
				if (tea_menu_list.GetListSelection() == 5) Col(7);
				else Col(6);
				cout << "         5.显示所教课程的学生名单       "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
				Col(3); cout << " ";
				if (tea_menu_list.GetListSelection() == 6) Col(7);
				else Col(6);
				cout << "               6.下一节课               "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
				Col(3); cout << " ";
				if (tea_menu_list.GetListSelection() == 7) Col(7);
				else Col(6);
				cout << "               7.返回主页               "; Col(3); cout << "  "; Col(0); cout << endl;
				Col(3); cout << "                                            " << endl; Col(0);
				tea_menu_list.Deal_input();
				if (tea_menu_list.GetBreakword())
				{
					tea_menu_list.SetBreakword(0);
					break;
				}
			}
			switch (tea_menu_list.GetListSelection())
			{
			case 1: {tea.Change_password(); break; }
			case 2: {tea.Show_tea_information(); break; }
			case 3: {tea.Course_search(); break; }
			case 4: {tea.Show_course(); break; }
			case 5: {tea.Show_stu_list(); break; }
			case 6: {tea.Show_next_course(); break; }
			case 7: {tea_menu_list.SetBreakword(1); break; }
			}
			if (tea_menu_list.GetBreakword())
			{
				tea_menu_list.SetBreakword(0);
				break;
			}
		}
	}
}

//管理员菜单
void admin_menu()
{
	List admin_menu_list(5);
	system("cls");
	Col(3); cout << "请输入您的账号:" << endl; Col(0);
	string account;
	Col(7); cin >> account; Col(0);
	Col(3); cout << "请输入您的密码:" << endl; Col(0);
	string password;
	Col(7); cin >> password; Col(0);
	admin ad(account, password, "");
	if (ad.Login())
	{
		while (true)
		{
			while (true)
			{
				system("cls");
				Col(3); cout << "             管理员--菜单               " << endl; cout << "  ";
				if (admin_menu_list.GetListSelection() == 1) Col(7);
				else Col(6);
				cout << "           1.对学生操作             "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
				Col(3); cout << " ";
				if (admin_menu_list.GetListSelection() == 2) Col(7);
				else Col(6);
				cout << "           2.对教师操作             "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
				Col(3); cout << " ";
				if (admin_menu_list.GetListSelection() == 3) Col(7);
				else Col(6);
				cout << "           3.对管理员操作           "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
				Col(3); cout << " ";
				if (admin_menu_list.GetListSelection() == 4) Col(7);
				else Col(6);
				cout << "           4.对课程操作             "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
				Col(3); cout << " ";
				if (admin_menu_list.GetListSelection() == 5) Col(7);
				else Col(6);
				cout << "           5.返回主页               "; Col(3); cout << "  "; Col(0); cout << endl;
				Col(3); cout << "                                        " << endl; Col(0);
				admin_menu_list.Deal_input();
				if (admin_menu_list.GetBreakword())
				{
					admin_menu_list.SetBreakword(0);
					break;
				}
			}
			switch (admin_menu_list.GetListSelection())
			{
			case 1: {admin_stu_menu(ad); break; }
			case 2: {admin_tea_menu(ad); break; }
			case 3: {admin_admin_menu(ad); break; }
			case 4: {admin_course_menu(ad); break; }
			case 5: {admin_menu_list.SetBreakword(1); break; }
			}
			if (admin_menu_list.GetBreakword())
			{
				admin_menu_list.SetBreakword(0);
				break;
			}
		}
	}
}

//管理员--学生操作菜单
void admin_stu_menu(admin& ad)
{
	List admin_stu_menu_list(8);
	while (true)
	{
		while (true)
		{
			system("cls");
			Col(3); cout << "             管理员--菜单               " << endl; cout << "  ";
			if (admin_stu_menu_list.GetListSelection() == 1) Col(7);
			else Col(6);
			cout << "           1.添加学生信息           "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
			Col(3); cout << " ";
			if (admin_stu_menu_list.GetListSelection() == 2) Col(7);
			else Col(6);
			cout << "           2.删除学生信息           "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
			Col(3); cout << " ";
			if (admin_stu_menu_list.GetListSelection() == 3) Col(7);
			else Col(6);
			cout << "           3.修改学生密码           "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
			Col(3); cout << " ";
			if (admin_stu_menu_list.GetListSelection() == 4) Col(7);
			else Col(6);
			cout << "           4.查询学生信息           "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
			Col(3); cout << " ";
			if (admin_stu_menu_list.GetListSelection() == 5) Col(7);
			else Col(6);
			cout << "           5.查询学生选课信息       "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
			Col(3); cout << " ";
			if (admin_stu_menu_list.GetListSelection() == 6) Col(7);
			else Col(6);
			cout << "           6.添加学生选课           "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
			Col(3); cout << " ";
			if (admin_stu_menu_list.GetListSelection() == 7) Col(7);
			else Col(6);
			cout << "           7.删除学生选课           "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
			Col(3); cout << " ";
			if (admin_stu_menu_list.GetListSelection() == 8) Col(7);
			else Col(6);
			cout << "           8.返回上一页             "; Col(3); cout << "  "; Col(0); cout << endl;
			Col(3); cout << "                                        " << endl; Col(0);
			admin_stu_menu_list.Deal_input();
			if (admin_stu_menu_list.GetBreakword())
			{
				admin_stu_menu_list.SetBreakword(0);
				break;
			}
		}
		switch (admin_stu_menu_list.GetListSelection())
		{
			case 1: {ad.Add_stu_information(); break; }
			case 2: {ad.Delete_stu_information(); break; }
			case 3: {ad.Change_stu_password(); break; }
			case 4: {ad.Search_stu_information(); break; }
			case 5: {ad.Search_stu_course_information(); break; }
			case 6: {ad.Add_stu_course(); break; }
			case 7: {ad.Delete_stu_course(); break; }
			case 8: {admin_stu_menu_list.SetBreakword(1); break; }
		}
		if (admin_stu_menu_list.GetBreakword())
		{
			admin_stu_menu_list.SetBreakword(0);
			break;
		}
	}
}

//管理员--教师操作菜单
void admin_tea_menu(admin& ad)
{
	List admin_tea_menu_list(8);
	while (true)
	{
		while (true)
		{
			system("cls");
			Col(3); cout << "             管理员--菜单               " << endl; cout << "  ";
			if (admin_tea_menu_list.GetListSelection() == 1) Col(7);
			else Col(6);
			cout << "           1.添加教师信息           "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
			Col(3); cout << " ";
			if (admin_tea_menu_list.GetListSelection() == 2) Col(7);
			else Col(6);
			cout << "           2.删除教师信息           "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
			Col(3); cout << " ";
			if (admin_tea_menu_list.GetListSelection() == 3) Col(7);
			else Col(6);
			cout << "           3.修改教师密码           "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
			Col(3); cout << " ";
			if (admin_tea_menu_list.GetListSelection() == 4) Col(7);
			else Col(6);
			cout << "           4.查询教师信息           "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
			Col(3); cout << " ";
			if (admin_tea_menu_list.GetListSelection() == 5) Col(7);
			else Col(6);
			cout << "           5.查询教师授课信息       "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
			Col(3); cout << " ";
			if (admin_tea_menu_list.GetListSelection() == 6) Col(7);
			else Col(6);
			cout << "           6.添加教师授课           "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
			Col(3); cout << " ";
			if (admin_tea_menu_list.GetListSelection() == 7) Col(7);
			else Col(6);
			cout << "           7.删除教师授课           "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
			Col(3); cout << " ";
			if (admin_tea_menu_list.GetListSelection() == 8) Col(7);
			else Col(6);
			cout << "           8.返回上一页             "; Col(3); cout << "  "; Col(0); cout << endl;
			Col(3); cout << "                                        " << endl; Col(0);
			admin_tea_menu_list.Deal_input();
			if (admin_tea_menu_list.GetBreakword())
			{
				admin_tea_menu_list.SetBreakword(0);
				break;
			}
		}
		switch (admin_tea_menu_list.GetListSelection())
		{
			case 1: {ad.Add_tea_information(); break; }
			case 2: {ad.Delete_tea_information(); break; }
			case 3: {ad.Change_tea_password(); break; }
			case 4: {ad.Search_tea_information(); break; }
			case 5: {ad.Search_tea_course_information(); break; }
			case 6: {ad.Add_tea_course(); break; }
			case 7: {ad.Delete_tea_course(); break; }
			case 8: {admin_tea_menu_list.SetBreakword(1); break; }
		}
		if (admin_tea_menu_list.GetBreakword())
		{
			admin_tea_menu_list.SetBreakword(0);
			break;
		}
	}
}

//管理员--管理员操作菜单
void admin_admin_menu(admin &ad)
{
	List admin_admin_menu_list(3);
	while (true)
	{
		while (true)
		{
			system("cls");
			Col(3); cout << "                 管理员--菜单                " << endl; cout << "  ";
			if (admin_admin_menu_list.GetListSelection() == 1) Col(7);
			else Col(6);
			cout << "               1.修改密码                "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
			Col(3); cout << " ";
			if (admin_admin_menu_list.GetListSelection() == 2) Col(7);
			else Col(6);
			cout << "               2.显示个人信息            "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
			Col(3); cout << " ";
			if (admin_admin_menu_list.GetListSelection() == 3) Col(7);
			else Col(6);
			cout << "               3.返回上一页              "; Col(3); cout << "  "; Col(0); cout << endl;
			Col(3); cout << "                                             " << endl; Col(0);
			admin_admin_menu_list.Deal_input();
			if (admin_admin_menu_list.GetBreakword())
			{
				admin_admin_menu_list.SetBreakword(0);
				break;
			}
		}
		switch (admin_admin_menu_list.GetListSelection())
		{
			case 1: {ad.Change_password(); break; }
			case 2: {ad.Show_admin_information(); break; }
			case 3: {admin_admin_menu_list.SetBreakword(1); break; }
		}
		if (admin_admin_menu_list.GetBreakword())
		{
			admin_admin_menu_list.SetBreakword(0);
			break;
		}
	}
}

//管理员--课程操作菜单
void admin_course_menu(admin& ad)
{
	List admin_course_menu_list(5);
	while (true)
	{
		while (true)
		{
			system("cls");
			Col(3); cout << "                   管理员--菜单                    " << endl; cout << "  ";
			if (admin_course_menu_list.GetListSelection() == 1) Col(7);
			else Col(6);
			cout << "              1.添加课程信息                   "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
			Col(3); cout << " ";
			if (admin_course_menu_list.GetListSelection() == 2) Col(7);
			else Col(6);
			cout << "              2.删除课程信息                   "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
			Col(3); cout << " ";
			if (admin_course_menu_list.GetListSelection() == 3) Col(7);
			else Col(6);
			cout << "              3.查询课程信息                   "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
			Col(3); cout << " ";
			if (admin_course_menu_list.GetListSelection() == 4) Col(7);
			else Col(6);
			cout << "              4.查询某课程的教师和学生名单     "; Col(3); cout << "  "; Col(0); cout << endl; Col(3); cout << " ";
			Col(3); cout << " ";
			if (admin_course_menu_list.GetListSelection() == 5) Col(7);
			else Col(6);
			cout << "              5.返回上一页                     "; Col(3); cout << "  "; Col(0); cout << endl;
			Col(3); cout << "                                                   " << endl; Col(0);
			admin_course_menu_list.Deal_input();
			if (admin_course_menu_list.GetBreakword())
			{
				admin_course_menu_list.SetBreakword(0);
				break;
			}
		}
		switch (admin_course_menu_list.GetListSelection())
		{
			case 1: {ad.Add_course_information(); break; }
			case 2: {ad.Delete_course_information(); break; }
			case 3: {ad.Search_course_information(); break; }
			case 4: {ad.Search_course_tea_stu_information(); break; }
			case 5: {admin_course_menu_list.SetBreakword(1); break; }
		}
		if (admin_course_menu_list.GetBreakword())
		{
			admin_course_menu_list.SetBreakword(0);
			break;
		}
	}
}