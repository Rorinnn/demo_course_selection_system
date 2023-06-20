#ifndef CONSOLE_LIST
#define CONSOLE_LIST
#ifndef CONIO
#define CONIO
#include <conio.h>
#endif
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
using namespace std;

inline void Col(int ColN);//设置自定义行的背景颜色

class List
{
private:
	bool Breakword;//用于判断是否跳出循环
	int List_max;//用于记录最大选项数
	int List_selection;//用于记录当前选项
public:
	//构造函数
	List(int List_max) :List_max(List_max), List_selection(1), Breakword(0) {}
	//函数声明
	inline bool GetBreakword();//获取是否跳出循环
	inline void SetBreakword(bool Breakword);//设置是否跳出循环
	inline int GetListSelection();//获取当前选项
	inline void SetListSelection(int List_selection);//设置当前选项
	inline int NumberCheck(int Number);//检查循环数字是否超出上限，如果是返回最大值
	void Deal_input();//处理用户操作
};

inline void Col(int ColN)//设置自定义行的背景颜色
{
	if (ColN == 0)cout << "\033[0m";//清除颜色
	else
	{
		cout << "\033[04m\033[1m\033[7m";
		if (ColN == 1)cout << "\033[31m";//红色
		else if (ColN == 2)cout << "\033[32m";//绿色
		else if (ColN == 3)cout << "\033[33m";//黄色
		else if (ColN == 4)cout << "\033[34m";//蓝色
		else if (ColN == 5)cout << "\033[35m";//紫色
		else if (ColN == 6)cout << "\033[36m";//淡蓝
		else if (ColN == 7)cout << "\033[37m";//白色
	}
}

//List类
//函数定义
inline bool List::GetBreakword()
{
	return Breakword;
}
inline void List::SetBreakword(bool Breakword)
{
	this->Breakword = Breakword;
}
inline int List::GetListSelection()
{
	return List_selection;
}
inline void List::SetListSelection(int List_selection)
{
	this->List_selection = List_selection;
}
inline int List::NumberCheck(int Number)
{
	if (Number > List_max)
	{
		Number = List_max;
		return Number;
	}
	else return Number;
}
inline void List::Deal_input()
{
	char CHOICE = _getch();
	switch (CHOICE)
	{
	case '1': List_selection = NumberCheck(1); Breakword = 1; break;
	case '2': List_selection = NumberCheck(2); Breakword = 1; break;
	case '3': List_selection = NumberCheck(3); Breakword = 1; break;
	case '4': List_selection = NumberCheck(4); Breakword = 1; break;
	case '5': List_selection = NumberCheck(5); Breakword = 1; break;
	case '6': List_selection = NumberCheck(6); Breakword = 1; break;
	case '7': List_selection = NumberCheck(7); Breakword = 1; break;
	case '8': List_selection = NumberCheck(8); Breakword = 1; break;
	case '9': List_selection = NumberCheck(9); Breakword = 1; break;
	case 72://表示小键盘的向上箭头
	case 'W':
	case 'w':
		if (List_selection == 1)
		{
			List_selection = List_max;
			break;
		}
		List_selection--;
		break;
	case 80://表示小键盘的向下箭头
	case 'S':
	case 's':
		if (List_selection == List_max)
		{
			List_selection = 1;
			break;
		}
		List_selection++;
		break;
	case '\r':
		Breakword = 1;
		break;
	}
}

#endif