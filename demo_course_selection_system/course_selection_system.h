#ifndef COURSE_SELECTION_SYSTEM
#define COURSE_SELECTION_SYSTEM
#ifndef STRING
#define STRING
#include <string>
#endif
using namespace std;

//维护
void maintenance();

//课程节点
class course_node
{
private:
    string course_id;//课程编号
    string course_name;//课程名称
    string course_grade;//年级
    string course_college;//学院
    string course_profession;//专业
    string course_college_open;//开课学院
    string course_type;//课程类别
    string course_nature;//课程性质
    string course_belong;//课程归属
    string course_week;//上课星期
    string course_time;//上课节次
    course_node* next;//指向下一个节点的指针
public:
    //构造函数
    course_node(string course_id, string course_name, string course_grade, string course_college, string course_profession, string course_college_open, string course_type, string course_nature, string course_belong, string course_week, string course_time) :course_id(course_id), course_name(course_name), course_grade(course_grade), course_college(course_college), course_profession(course_profession), course_college_open(course_college_open), course_type(course_type), course_nature(course_nature), course_belong(course_belong), course_week(course_week), course_time(course_time), next(NULL) {};
    //析构函数
    ~course_node() {};
    //获取课程编号
    string Get_course_id(){ return course_id;}
    //获取课程名称
    string Get_course_name(){ return course_name;}
    //获取年级
    string Get_course_grade(){ return course_grade;}
    //获取学院
    string Get_course_college(){ return course_college;}
    //获取专业
    string Get_course_profession(){ return course_profession;}
    //获取开课学院
    string Get_course_college_open(){ return course_college_open;}
    //获取课程类别
    string Get_course_type(){ return course_type;}
    //获取课程性质
    string Get_course_nature(){ return course_nature;}
    //获取课程归属
    string Get_course_belong(){ return course_belong;}
    //获取上课星期
    string Get_course_week(){ return course_week;}
    //获取上课节次
    string Get_course_time(){ return course_time;}
    //获取下一个节点的指针
    course_node* Get_next(){ return next;}
    //设置课程编号
    void Set_course_id(string course_id){ this->course_id = course_id;}
    //设置课程名称
    void Set_course_name(string course_name){ this->course_name = course_name;}
    //设置年级
    void Set_course_grade(string course_grade){ this->course_grade = course_grade;}
    //设置学院
    void Set_course_college(string course_college){ this->course_college = course_college;}
    //设置专业
    void Set_course_profession(string course_profession){ this->course_profession = course_profession;}
    //设置开课学院
    void Set_course_college_open(string course_college_open){ this->course_college_open = course_college_open;}
    //设置课程类别
    void Set_course_type(string course_type){ this->course_type = course_type;}
    //设置课程性质
    void Set_course_nature(string course_nature){ this->course_nature = course_nature;}
    //设置课程归属
    void Set_course_belong(string course_belong){ this->course_belong = course_belong;}
    //设置上课星期
    void Set_course_week(string course_week){ this->course_week = course_week;}
    //设置上课节次
    void Set_course_time(string course_time){ this->course_time = course_time;}
    //设置下一个节点的指针
    void Set_next(course_node* next){ this->next = next;}
};
//课程链表
class course_list
{
private:
    course_node* head;//头节点
public:
    //构造函数
    course_list() :head(NULL) {};
    //析构函数
    ~course_list()
    {
        course_node* temp = head;
        while (temp != NULL)
        {
            head = temp->Get_next();
            delete temp;
            temp = head;
        }
    }
    //从course.txt文件中读取课程信息
    void Read_course_information();
    //根据关键词从course.txt文件中读取课程信息
    void Read_course_information_by_keyword(string keyword);
    //从stu_course.txt文件中读取学生选课信息
    void Read_stu_course_information(string account);
    //从tea_course.txt文件中读取教师授课信息
    void Read_tea_course_information(string account);
    //根据课程编号大小插入新节点
    void Insert_course_node(string course_id, string course_name, string course_grade, string course_college, string course_profession, string course_college_open, string course_type, string course_nature, string course_belong, string course_week, string course_time);
    //插入新节点
    void Insert_course_node(course_node* node);
    //根据课程编号删除节点
    void Delete_course_node(string course_id);
    //根据课程编号查找节点
    course_node* Search_course_node(string course_id);
    //根据关键字查找节点
    course_node* Search_course_node_by_keyword(string keyword);
    //遍历所有节点，输出课程信息到course.txt文件
    void Write_course_information();
    //遍历所有节点，输出学生选课信息到stu_course文件夹下的txt文件
    void Write_stu_course_information(string account);
    //遍历所有节点，输出教师授课信息到tea_course文件夹下的txt文件
    void Write_tea_course_information(string account);
    //友元类
    friend class student;
    friend class teacher;
    friend class admin;
};

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
    //基础功能:
    //查询课程信息
    static void Search_course_information();
    //查询课程是否存在
    static bool Iscourse_exist(string temp_course_id);
    //选学院菜单
    static string course_college_menu();
    //学院1-专业菜单
    static string course1_profession_menu();
    //学院2-专业菜单
    static string course2_profession_menu();
    //学院3-专业菜单
    static string course3_profession_menu();
    //学院4-专业菜单
    static string course4_profession_menu();
    //学院5-专业菜单
    static string course5_profession_menu();
    //学院6-专业菜单
    static string course6_profession_menu();
    //学院7-专业菜单
    static string course7_profession_menu();
    //学院8-专业菜单
    static string course8_profession_menu();
    //学院9-专业菜单
    static string course9_profession_menu();
    //学院10-专业菜单
    static string course10_profession_menu();
    //学院11-专业菜单
    static string course11_profession_menu();
    //学院12-专业菜单
    static string course12_profession_menu();
    //学院13-专业菜单
    static string course13_profession_menu();
    //学院14-专业菜单
    static string course14_profession_menu();
    //学院15-专业菜单
    static string course15_profession_menu();
    //学院16-专业菜单
    static string course16_profession_menu();
    //学院17-专业菜单
    static string course17_profession_menu();
    //学院18-专业菜单
    static string course18_profession_menu();
    //学院19-专业菜单
    static string course19_profession_menu();
    //学院20-专业菜单
    static string course20_profession_menu();
    //学院21-专业菜单
    static string course21_profession_menu();
    //学院22-专业菜单
    static string course22_profession_menu();
    //学院23-专业菜单
    static string course23_profession_menu();
    //学院24-专业菜单
    static string course24_profession_menu();
    //学院25-专业菜单
    static string course25_profession_menu();
    //课程类别菜单
    static string course_type_menu();
    //课程性质菜单
    static string course_nature_menu();
    //课程归属菜单
    static string course_belong_menu();
    //课程时间菜单
    static string course_week_menu();
    //必须选择一个的week菜单
    static string course_week2_menu();
    //课程节次菜单
    static string course_time_menu();
    //必须选择一个的time菜单
    static string course_time2_menu();
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
    // //功能:显示下一节课的时间和名称
    // void Show_next_course();
};

//教师授课信息派生类
class tea_course :public course
{
private:
    string tea_account;//教师工号
    string tea_temp_course_id;//待操作授课信息的课程编号
    string tea_temp_course_week;//待操作授课信息的课程星期
    string tea_temp_course_time;//待操作授课信息的课程节次
public:
    //构造函数
    tea_course(string course_id, string course_name, string course_grade, string course_college, string course_profession, string course_college_open, string course_type, string course_nature, string course_belong, string course_week, string course_time, string tea_account, string tea_temp_course_id, string tea_temp_course_week, string tea_temp_course_time) :course(course_id, course_name, course_grade, course_college, course_profession, course_college_open, course_type, course_nature, course_belong, course_week, course_time), tea_account(tea_account), tea_temp_course_id(tea_temp_course_id), tea_temp_course_week(tea_temp_course_week), tea_temp_course_time(tea_temp_course_time) {};
    //根据待操作课程编号获得课程星期和节次
    void Get_course_week_time();
    //授课是否冲突
    bool Isconflict();
    //退课是否为存在的课程
    bool Iscourse(string course_id);
    //输出课表
    string Get_course(string course_week, string course_time);
    //功能1：添加授课信息
    void Add_tea_course();
    //功能2：删除授课信息
    void Delete_tea_course();
    //功能3：显示授课课表
    void Show_tea_course();
    // //功能：显示下一节课的时间和名称
    // void Show_next_course();
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
    bool stu_isoneclick=0;//是否一键选课
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
    //功能7:根据专业和年级一键选课
    void one_click_choose_course();
    //功能8:选课（新版）
    void Choose_course_new();
    //功能9:退课（新版）
    void Drop_course_new();
    // //功能:下一节课的时间和名称
    // void Show_next_course();
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
    //功能4:添加授课信息
    void Choose_course();
    //功能5:删除授课信息
    void Drop_course();
    //功能6:显示课表
    void Show_course();
    //功能7:所教课程的学生名单
    void Show_stu_list();
    // //功能:下一节课的时间和名称
    // void Show_next_course();
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
