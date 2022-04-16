#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    Book borrowmenu[NUM];
    int borrownumber;
} User;

int booksNumber = 0;
int usersNumber = 0;

Book books[NUM];
User users[NUM];

int year, month, day, hour, miniute, second;
int overyear, overmonth, overday, overhour, overminiute, oversecond;

void Headmenu();                 //起始目录UI
void HeadmenuFunction();         //起始目录
void LoadmenuFunction(int text); //登陆目录
void Loadmenu();                 //登陆目录UI
void Register();                 //注册函数
void BorrowBook(int text);       //借书函数
void ReturnBook(int text);       //还书函数
void load();                     //登陆函数
void Input_Book();               //书本录入
void ReadtoText();               //文件读取
void WritetoText();              //文件输出
void Administrator();            //管理员系统
void Administratormenu();        //管理员UI
int Administratorload();         //管理员登陆函数(成功0 ； 失败1)
void Deleteuser();               //删除用户
void Over();

int main()
{
    time_t timep;
    struct tm *p;
    time(&timep);
    p = gmtime(&timep);
    year = 1900 + p->tm_year;
    month = 1 + p->tm_mon;
    day = p->tm_mday;
    hour = 8 + p->tm_hour;
    miniute = p->tm_min;
    second = p->tm_sec;
    if (hour > 23)
    {
        day++;
        hour = hour - 24;
    }
    printf("*= =============================================================  =*\n");
    printf("||                                                                ||\n");
    printf("||             欢迎使用福州大学至诚学院图书管理系统               ||\n");
    printf("||                                                                ||\n");
    printf("||                    现在是北京时间：%d-%02d-%02d-%02d-%02d-%02d         ||\n",
           year, month, day, hour, miniute, second);
    printf("*= =============================================================  =*\n");
    system("pause");
    system("cls");
    HeadmenuFunction();
    return 0;
}

void Headmenu()
{
    printf("*= ================================================  =*\n");
    printf("|| *******欢迎使用福州大学至诚学院图书管理系统****** ||\n");
    printf("||    1.登陆                                         ||\n");
    printf("||    2.注册                                         ||\n");
    printf("||    3.管理员系统                                   ||\n");
    printf("||    0.退出                                         ||\n");
    printf("|| *******---------~~~~~~~~~~~~~~~~~~--------******* ||\n");
    printf("*= ================================================  =*\n");
}

void HeadmenuFunction()
{
    char botton, key[3];
    int chose, text;
    while (1)
    {
        while (1)
        {
            Headmenu();
            printf("请输入您需要的功能按钮:");
        again:
            gets(key);
            text = strlen(key);
            if (text == 0)
            {
                goto again;
            }
            else if (text > 1)
            {
                printf("输入错误,请重新输入\n");
            }
            else
            {
                botton = key[0];
                if (botton != '0' && botton != '1' && botton != '2' && botton != '3')
                {
                    printf("输入错误,请重新输入\n");
                }
                else
                {
                    break;
                }
            }
        }
        chose = botton - '0';
        switch (chose)
        {
        case 0:
            system("cls");
            Over();
            system("pause");
            WritetoText();
            goto out;
            break;
        case 1:
            load();
            break;
        case 2:
            Register();
            break;
        case 3:
            Administrator();
            break;
        }
    }
out:
    system("cls");
    printf("本次使用的数据如下:\n");
    if (booksNumber == 0 && usersNumber == 0)
    {
        printf("空\n");
    }
    else
    {
        printf("                             <<图书数据>>\n");
        if (booksNumber == 0)
        {
            printf("空\n");
        }
        else
        {
            for (int j = 0; j < booksNumber; j++)
            {
                printf("%2d %-30s %-20s %-20s\n", j + 1, books[j].name, books[j].author, books[j].press);
            }
        };
        printf("                             <<用户数据>>\n");
        if (usersNumber == 0)
        {
            printf("空\n");
        }
        else
        {
            for (int j = 0; j < usersNumber; j++)
            {
                printf("%-20s%-20s\n", users[j].name, users[j].password);
            }
        }
    }
    printf("<<此次福州大学至诚学院图书管理系统运行时间>>\n");
    printf("开始时间:%d-%d-%d-%d-%d-%d\n",year,month,day,hour,miniute,second);
    printf("结束时间:%d-%d-%d-%d-%d-%d\n",overyear,overmonth,overday,overhour,overminiute,oversecond);
    system("pause");
    system("exit");
}

void Over()
{
    time_t timep;
    struct tm *p;
    time(&timep);
    p = gmtime(&timep);
    overyear = 1900 + p->tm_year;
    overmonth = 1 + p->tm_mon;
    overday = p->tm_mday;
    overhour = 8 + p->tm_hour;
    overminiute = p->tm_min;
    oversecond = p->tm_sec;
    if (overhour > 23)
    {
        overday++;
        overhour = overhour - 24;
    }
    printf("*= =============================================================  =*\n");
    printf("||                                                                ||\n");
    printf("||                       Thanks for using it                      ||\n");
    printf("||                                                                ||\n");
    printf("||                    现在是北京时间：%d-%02d-%02d-%02d-%02d-%02d         ||\n",
           overyear, overmonth, overday, overhour, overminiute, oversecond);
    printf("||                                                                ||\n");
    printf("*= =============================================================  =*\n");
}

void Loadmenu()
{
    printf("*= ================================================  =*\n");
    printf("|| *******------------------------------------****** ||\n");
    printf("|| *  1.借书                                       * ||\n");
    printf("|| *  2.还书                                       * ||\n");
    printf("|| *  3.修改密码                                   * ||\n");
    printf("|| *  0.退出                                       * ||\n");
    printf("|| *******---------~~~~~~~~~~~~~~~~~~--------******* ||\n");
    printf("*= ================================================  =*\n");
}

void LoadmenuFunction(int text)
{
    char botton, key[3];
    int chose, txt;
againLoadmenuFunction:
    while (1)
    {
        Loadmenu();
        printf("请输入您需要的功能按钮:");
    again1:
        gets(key);
        txt = strlen(key);
        if (txt == 0)
        {
            goto again1;
        }
        else if (txt > 1)
        {
            printf("输入错误,请重新输入\n");
        }
        else
        {
            botton = key[0];
            if (botton != '1' && botton != '2' && botton != '3' && botton != '0')
            {
                printf("输入错误,请重新输入\n");
            }
            else
            {
                break;
            }
        }
    }
    chose = botton - '0';
    char newPassword[20];
    char again_key[3], again_botton;
    int again_txt;
    switch (chose)
    {
    case 0:
        while (1)
        {
            printf("确认退出福州大学至诚学院图书管理系统用户端吗?(是'1' ; 否'0')\n");
        againagain_0:
            gets(again_key);
            again_txt = strlen(again_key);
            if (again_txt == 0)
            {
                goto againagain_0;
            }
            else if (again_txt > 1)
            {
                printf("输入错误,请重新输入\n");
            }
            else
            {
                again_botton = again_key[0];
                if (again_botton != '0' && again_botton != '1')
                {
                    printf("输入错误,请重新输入\n");
                }
                else
                {
                    break;
                }
            }
        }
        if (again_botton == '1')
        {
            break;
        }
        else
        {
            goto againLoadmenuFunction;
        }
        break;
    case 1:
        BorrowBook(text);
        while (1)
        {
            printf("还需要继续吗?[yes(1) ; no(0)]\n");
        againagain_1:
            gets(again_key);
            again_txt = strlen(again_key);
            if (again_txt == 0)
            {
                goto againagain_1;
            }
            else if (again_txt > 1)
            {
                printf("输入错误,请重新输入\n");
            }
            else
            {
                again_botton = again_key[0];
                if (again_botton != '0' && again_botton != '1')
                {
                    printf("输入错误,请重新输入\n");
                }
                else
                {
                    break;
                }
            }
        }
        if (again_botton == '1')
        {
            goto againLoadmenuFunction;
        }
        break;
    case 2:
        ReturnBook(text);
        while (1)
        {
            printf("还需要继续吗?[yes(1) ; no(0)]\n");
        againagain_2:
            gets(again_key);
            again_txt = strlen(again_key);
            if (again_txt == 0)
            {
                goto againagain_2;
            }
            else if (again_txt > 1)
            {
                printf("输入错误,请重新输入\n");
            }
            else
            {
                again_botton = again_key[0];
                if (again_botton != '0' && again_botton != '1')
                {
                    printf("输入错误,请重新输入\n");
                }
                else
                {
                    break;
                }
            }
        }
        if (again_botton == '1')
        {
            goto againLoadmenuFunction;
        }
        break;
    case 3:
        printf("请输入新密码:");
        scanf("%s", &newPassword);
        getchar();
        strcpy(users[text].password, newPassword);
        while (1)
        {
            printf("还需要继续吗?[yes(1) ; no(0)]\n");
        againagain_3:
            gets(again_key);
            again_txt = strlen(again_key);
            if (again_txt == 0)
            {
                goto againagain_3;
            }
            else if (again_txt > 1)
            {
                printf("输入错误,请重新输入\n");
            }
            else
            {
                again_botton = again_key[0];
                if (again_botton != '0' && again_botton != '1')
                {
                    printf("输入错误,请重新输入\n");
                }
                else
                {
                    break;
                }
            }
        }
        if (again_botton == '1')
        {
            goto againLoadmenuFunction;
        }
        break;
    default:
        printf("输入错误,请重新输入\n");
        goto againLoadmenuFunction;
        break;
    }
    system("cls");
}

void Register()
{
    User process;
    int flag = 0;
    printf("请输入用户名:");
    scanf("%s", &process.name);
    getchar();
    if (usersNumber == 0)
    {
        printf("请输入密码:");
        scanf("%s", &process.password);
        getchar();
        strcpy(users[usersNumber].name, process.name);
        strcpy(users[usersNumber].password, process.password);
        usersNumber++;
        printf("注册成功\n");
    }
    else
    {
        for (int i = 0; i < usersNumber; i++)
        {
            if (!strcmp(users[i].name, process.name))
            {
                printf("该用户已存在,注册失败\n");
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("请输入密码:");
            scanf("%s", &process.password);
            getchar();
            strcpy(users[usersNumber].name, process.name);
            strcpy(users[usersNumber].password, process.password);
            users[usersNumber].borrownumber = 0;
            usersNumber++;
            printf("注册成功\n");
        }
    }
}

void load()
{
    User process;
    int flag = 1, i;
    if (usersNumber == 0)
    {
        printf("查找失败!不存在用户信息!\n");
        printf("请先完成注册\n");
        Register();
        goto load_1;
    }
    else
    {
    load_1:
        printf("请输入账号:");
        scanf("%s", &process.name);
        getchar();
        for (i = 0; i < usersNumber; i++)
        {
            if (!strcmp(users[i].name, process.name))
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
        {
            printf("请输入密码:");
            scanf("%s", &process.password);
            getchar();
            if (!strcmp(users[i].password, process.password))
            {
                printf("登陆成功\n");
                LoadmenuFunction(i);
            }
            else
            {
                printf("密码错误,登陆失败\n");
            }
        }
        else
        {
            printf("查无此用户\n");
        }
    }
}

void Input_Book()
{
    Book process;
    int flag = 0;
    printf("请输入书名:");
    scanf("%s", &process.name);
    getchar();
    if (booksNumber == 0)
    {
        printf("请输入作者:");
        scanf("%s", &process.author);
        getchar();
        printf("请输入出版社名:");
        scanf("%s", &process.press);
        getchar();
        strcpy(books[booksNumber].name, process.name);
        strcpy(books[booksNumber].author, process.author);
        strcpy(books[booksNumber].press, process.press);
        books[booksNumber].id = booksNumber + 1;
        booksNumber++;
    }
    else
    {
        for (int i = 0; i < booksNumber; i++)
        {
            if (!strcmp(books[i].name, process.name))
            {
                printf("该书本已存在,注册失败\n");
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("请输入作者:");
            scanf("%s", &process.author);
            getchar();
            printf("请输入出版社名:");
            scanf("%s", &process.press);
            getchar();
            strcpy(books[booksNumber].name, process.name);
            strcpy(books[booksNumber].author, process.author);
            strcpy(books[booksNumber].press, process.press);
            books[booksNumber].id = booksNumber + 1;
            booksNumber++;
        }
    }
}

void BorrowBook(int text)
{
    if (booksNumber == 0)
    {
        printf("没有书本\n");
    }
    else
    {
        if (users[text].borrownumber == 5)
        {
            printf("您已借阅5本书,请归还后再进行借阅\n");
        }
        else
        {
            int botton;
        BorrowBook:
            for (int i = 0; i < booksNumber; i++)
            {
                printf("%2d %-30s %-20s %-20s\n", i, books[i].name, books[i].author, books[i].press);
            }
            printf("请输入需要借阅的序号:");
            scanf("%d", &botton);
            getchar();
            if (botton >= 0 && botton < booksNumber)
            {
                printf("借阅成功\n");
                int vec;
                for (int i = 0; i < booksNumber; i++)
                {
                    if (i != botton - 1)
                    {
                        printf("%2d %-30s %-20s %-20s\n", i, books[i].name, books[i].author, books[i].press);
                    }
                    else
                    {
                        vec = users[text].borrownumber;
                        users[text].borrowmenu[vec].id = books[i].id;
                        strcpy(users[text].borrowmenu[vec].name, books[i].name);
                        strcpy(users[text].borrowmenu[vec].author, books[i].author);
                        strcpy(users[text].borrowmenu[vec].press, books[i].press);
                        users[text].borrownumber++;
                    }
                }
                printf("显示完成\n");
            }
            else
            {
                printf("输入错误,请重新输入\n");
                goto BorrowBook;
            }
        }
    }
}

void ReturnBook(int text)
{
    char process[30];
    int flag = 1;
    if (users[text].borrownumber == 0)
    {
        printf("您还未借书\n");
    }
    else
    {
        for (int i = 0; i < users[text].borrownumber; i++)
        {
            printf("%d %-30s %-20s %-20s\n", i,
                   users[text].borrowmenu[i].name,
                   users[text].borrowmenu[i].author,
                   users[text].borrowmenu[i].press);
        }
        printf("请输入需要归还的书名:");
        scanf("%s", &process);
        getchar();
        int i;
        for (i = 0; i < users[text].borrownumber; i++)
        {
            if (!strcmp(users[text].borrowmenu[i].name, process))
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            printf("您未借这本书\n");
        }
        else
        {
            printf("归还成功\n");
            for (int j = users[text].borrownumber - 1; j > i; j--)
            {
                users[text].borrowmenu[j - 1] = users[text].borrowmenu[j];
            }
            users[text].borrownumber--;
        }
    }
}

void WritetoText()
{
    FILE *writeUser;
    if ((writeUser = fopen("user.txt", "w")) == NULL)
    {
        printf("打开文件失败!\n");
    }
    else
    {
        fprintf(writeUser, "%d\n", usersNumber);
        for (int i = 0; i < usersNumber; i++)
        {
            fprintf(writeUser, "%-20s%-20s\n", users[i].name, users[i].password);
        }
        fclose(writeUser);
    }
    FILE *writeBook;
    if ((writeBook = fopen("book.txt", "w")) == NULL)
    {
        printf("打开文件失败!\n");
    }
    else
    {
        fprintf(writeBook, "%d\n", booksNumber);
        for (int i = 0; i < booksNumber; i++)
        {
            fprintf(writeBook, "%2d %-30s %-20s %-20s\n", books[i].id, books[i].name, books[i].author, books[i].press);
        }
        fclose(writeBook);
    }
    printf("成功将记录写到文件！\n");
}

void ReadtoText()
{
    int flag = 0;
    if ((usersNumber == 0) || (booksNumber == 0))
    {
        FILE *readUser;
        if ((readUser = fopen("user.txt", "r")) == NULL)
        {
            printf("用户打开文件失败！\n");
        }
        else
        {
            fscanf(readUser, "%d", &usersNumber);
            for (int i = 0; i < usersNumber; i++)
            {
                fscanf(readUser, "%-20s%-20s\n", users[i].name, users[i].password);
            }
            fclose(readUser);
            flag++;
        }
        FILE *readBook;
        if ((readBook = fopen("book.txt", "r")) == NULL)
        {
            printf("图书打开文件失败！\n");
        }
        else
        {
            fscanf(readBook, "%d", &booksNumber);
            for (int i = 0; i < booksNumber; i++)
            {
                fscanf(readBook, "%2d %-30s %-20s %-20s\n", books[i].id, books[i].name, books[i].author, books[i].press);
            }
            fclose(readBook);
            flag++;
        }
        if (flag == 2)
        {
            printf("成功从文件输入数据！\n");
        }
    }
    else
    {
        printf("已有数据,无法从文件导入\n");
    }
}

int Administratorload()
{
    char id[] = {"福州大学至诚学院"};
    char password[] = {"123456"};
    char process[20];
    printf("请输入管理员账号:");
    scanf("%s", &process);
    getchar();
    if (!strcmp(id, process))
    {
        printf("请输入管理员密码:");
        scanf("%s", &process);
        getchar();
        if (!strcmp(password, process))
        {
            printf("登陆成功\n");
            return 0;
        }
        else
        {
            printf("密码错误\n");
            printf("登陆失败\n");
        }
    }
    else
    {
        printf("账号错误\n");
        printf("登陆失败\n");
    }
    return 1;
}

void Administratormenu()
{
    printf("*= ================================================  =*\n");
    printf("|| *******---------~~~~~~~~~~~~~~~~~~--------******* ||\n");
    printf("||  == **** * 欢迎进入图书管理系统管理端  *  **** == ||\n");
    printf("||  == 1.书本录入                                 == ||\n");
    printf("||  == 2.书本查询                                 == ||\n");
    printf("||  == 3.下架书本                                 == ||\n");
    printf("||  == 4.用户录入                                 == ||\n");
    printf("||  == 5.用户查询                                 == ||\n");
    printf("||  == 6.用户删除                                 == ||\n");
    printf("||  == 7.数据导入                                 == ||\n");
    printf("||  == 8.格式化数据库                             == ||\n");
    printf("||  == 0.退出管理系统                             == ||\n");
    printf("|| *******---------~~~~~~~~~~~~~~~~~~--------******* ||\n");
    printf("*= ================================================  =*\n");
}

void Administrator()
{
    if (!Administratorload())
    {
        char a[4] = {"\0"};
        char botton, key[3];
        int chose, text;
    againAdministrator:
        while (1)
        {
            Administratormenu();
            printf("请输入您需要的功能按钮:");
        again1:
            gets(key);
            text = strlen(key);
            if (text == 0)
            {
                goto again1;
            }
            else if (text > 1)
            {
                printf("输入错误,请重新输入\n");
            }
            else
            {
                botton = key[0];
                if (botton == '9')
                {
                    printf("输入错误,请重新输入\n");
                }
                else
                {
                    break;
                }
            }
        }
        chose = botton - '0';
        int bookName;
        char again_key[3], again_botton;
        int again_txt;
        switch (chose)
        {
        case 1:
            Input_Book();
            while (1)
            {
                printf("还需要继续吗?[yes(1) ; no(0)]\n");
            againagain_a1:
                gets(again_key);
                again_txt = strlen(again_key);
                if (again_txt == 0)
                {
                    goto againagain_a1;
                }
                else if (again_txt > 1)
                {
                    printf("输入错误,请重新输入\n");
                }
                else
                {
                    again_botton = again_key[0];
                    if (again_botton != '0' && again_botton != '1')
                    {
                        printf("输入错误,请重新输入\n");
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (again_botton == '1')
            {
                goto againAdministrator;
            }
            break;
        case 2:
            if (booksNumber == 0)
            {
                printf("此书库无图书\n");
            }
            else
            {
                for (int i = 0; i < booksNumber; i++)
                {
                    printf("%2d %-30s %-20s %-20s\n", books[i].id, books[i].name, books[i].author, books[i].press);
                }
                printf("显示完毕\n");
            }
            while (1)
            {
                printf("还需要继续吗?[yes(1) ; no(0)]\n");
            againagain_a2:
                gets(again_key);
                again_txt = strlen(again_key);
                if (again_txt == 0)
                {
                    goto againagain_a2;
                }
                else if (again_txt > 1)
                {
                    printf("输入错误,请重新输入\n");
                }
                else
                {
                    again_botton = again_key[0];
                    if (again_botton != '0' && again_botton != '1')
                    {
                        printf("输入错误,请重新输入\n");
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (again_botton == '1')
            {
                goto againAdministrator;
            }
            break;
        case 3:
            if (booksNumber == 0)
            {
                printf("删除失败！不存在图书信息！\n");
            }
            else
            {
                for (int j = 0; j < booksNumber; j++)
                {
                    printf("%2d %-30s %-20s %-20s\n", j + 1, books[j].name, books[j].author, books[j].press);
                }
                printf("请输入要删除的序号：");
                scanf("%d", &bookName);
                getchar();
                if (bookName > 0 && bookName <= booksNumber)
                {
                    int confirm;
                    int flagN = 0;
                    printf("确认删除吗(是'1',否'0')");
                    scanf("%d", &confirm);
                    getchar();
                    if (confirm == 1)
                    {
                        printf("删除图书信息成功！\n");
                        bookName = bookName - 1;
                        for (int i = bookName + 1; i < booksNumber; i++)
                        {
                            books[i - 1] = books[i];
                        }
                        booksNumber--;
                    }
                    else
                    {
                        printf("删除失败\n");
                    }
                }
                else
                {
                    printf("没有这本图书,无法删除\n");
                }
            }
            while (1)
            {
                printf("还需要继续吗?[yes(1) ; no(0)]\n");
            againagain_a3:
                gets(again_key);
                again_txt = strlen(again_key);
                if (again_txt == 0)
                {
                    goto againagain_a3;
                }
                else if (again_txt > 1)
                {
                    printf("输入错误,请重新输入\n");
                }
                else
                {
                    again_botton = again_key[0];
                    if (again_botton != '0' && again_botton != '1')
                    {
                        printf("输入错误,请重新输入\n");
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (again_botton == '1')
            {
                goto againAdministrator;
            }
            break;
        case 4:
            Register();
            while (1)
            {
                printf("还需要继续吗?[yes(1) ; no(0)]\n");
            againagain_a4:
                gets(again_key);
                again_txt = strlen(again_key);
                if (again_txt == 0)
                {
                    goto againagain_a4;
                }
                else if (again_txt > 1)
                {
                    printf("输入错误,请重新输入\n");
                }
                else
                {
                    again_botton = again_key[0];
                    if (again_botton != '0' && again_botton != '1')
                    {
                        printf("输入错误,请重新输入\n");
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (again_botton == '1')
            {
                goto againAdministrator;
            }
            break;
        case 5:
            if (usersNumber == 0)
            {
                printf("没有用户数据\n");
            }
            else
            {
                for (int i = 0; i < usersNumber; i++)
                {
                    printf("%-20s%-20s\n", users[i].name, users[i].password);
                }
            }
            while (1)
            {
                printf("还需要继续吗?[yes(1) ; no(0)]\n");
            againagain_a5:
                gets(again_key);
                again_txt = strlen(again_key);
                if (again_txt == 0)
                {
                    goto againagain_a5;
                }
                else if (again_txt > 1)
                {
                    printf("输入错误,请重新输入\n");
                }
                else
                {
                    again_botton = again_key[0];
                    if (again_botton != '0' && again_botton != '1')
                    {
                        printf("输入错误,请重新输入\n");
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (again_botton == '1')
            {
                goto againAdministrator;
            }
            break;
        case 6:
            Deleteuser();
            while (1)
            {
                printf("还需要继续吗?[yes(1) ; no(0)]\n");
            againagain_a6:
                gets(again_key);
                again_txt = strlen(again_key);
                if (again_txt == 0)
                {
                    goto againagain_a6;
                }
                else if (again_txt > 1)
                {
                    printf("输入错误,请重新输入\n");
                }
                else
                {
                    again_botton = again_key[0];
                    if (again_botton != '0' && again_botton != '1')
                    {
                        printf("输入错误,请重新输入\n");
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (again_botton == '1')
            {
                goto againAdministrator;
            }
            break;
        case 7:
            ReadtoText();
            while (1)
            {
                printf("还需要继续吗?[yes(1) ; no(0)]\n");
            againagain_a7:
                gets(again_key);
                again_txt = strlen(again_key);
                if (again_txt == 0)
                {
                    goto againagain_a7;
                }
                else if (again_txt > 1)
                {
                    printf("输入错误,请重新输入\n");
                }
                else
                {
                    again_botton = again_key[0];
                    if (again_botton != '0' && again_botton != '1')
                    {
                        printf("输入错误,请重新输入\n");
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (again_botton == '1')
            {
                goto againAdministrator;
            }
            break;
        case 8:
            for (int i = 0; i < booksNumber; i++)
            {
                strcpy(books[i].author, a);
                books[i].id = 0;
                strcpy(books[i].name, a);
                strcpy(books[i].press, a);
            }
            booksNumber = 0;
            for (int i = 0; i < usersNumber; i++)
            {
                strcpy(users[i].name, a);
                strcpy(users[i].password, a);
            }
            usersNumber = 0;
            while (1)
            {
                printf("还需要继续吗?[yes(1) ; no(0)]\n");
            againagain_a8:
                gets(again_key);
                again_txt = strlen(again_key);
                if (again_txt == 0)
                {
                    goto againagain_a8;
                }
                else if (again_txt > 1)
                {
                    printf("输入错误,请重新输入\n");
                }
                else
                {
                    again_botton = again_key[0];
                    if (again_botton != '0' && again_botton != '1')
                    {
                        printf("输入错误,请重新输入\n");
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (again_botton == '1')
            {
                goto againAdministrator;
            }
            break;
        case 0:
            printf("您已成功退出福州大学至诚学院图书管理系统管理员端\n");
            system("pause");
            system("cls");
            break;
        default:
            printf("输入错误,请重新输入\n");
            goto againAdministrator;
            break;
        }
    }
}

void Deleteuser()
{
    int userName;
    int i = 0, n;
    if (usersNumber == 0)
    {
        printf("删除失败！不存在用户信息！\n");
    }
    else
    {
        for (int j = 0; j < usersNumber; j++)
        {
            printf("%d  %-20s%-20s\n", j, users[j].name, users[j].password);
        }
        printf("请输入要删除的用户序号：");
        scanf("%d", &userName);
        getchar();
        if (userName > 0 && userName <= usersNumber)
        {
            int confirm;
            int flagN = 0;
            printf("确认删除吗(是'1',否'0')");
            scanf("%d", &confirm);
            getchar();
            if (confirm == 1)
            {
                printf("删除用户信息成功！\n");
                userName = userName - 1;
                for (int i = userName + 1; i < usersNumber; i++)
                {
                    users[i - 1] = users[i];
                }
                usersNumber--;
            }
            else
            {
                printf("删除失败\n");
            }
        }
        else
        {
            printf("删除失败！不存在此用户信息!\n");
        }
    }
}
