#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 10

typedef struct
{
    int id;          //书号
    char name[30];   //书名
    char author[20]; //作者
    char press[50];  //出版社名
} Book;

typedef struct
{
    char name[20];     //用户名
    char password[20]; //用户密码
} User;

void Headmenu();          //起始目录UI
void HeadmenuFunction();  //起始目录
void LoadmenuFunction();  //登陆目录
void Loadmenu();          //登陆目录UI
void Register();          //注册函数
void BorrowBook();        //借书函数
void ReturnBook();        //还书函数
void load();              //登陆函数
void Input_Book();        //书本录入
void ReadtoText();        //文件读取
void WritetoText();       //文件输出
void Administrator();     //管理员系统
void Administratormenu(); //管理员UI
int Administratorload();  //管理员登陆函数(成功0 ； 失败1)
void Deletebook();        //删书
void Deleteuser();        //删除用户
void Over();              //程序关闭UI
