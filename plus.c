#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

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
    char name[20];        //用户名
    char password[20];    //用户密码
    char phone[30];       //联系方式
    Book returnmenu[NUM]; //可还书数据
    int returnnumber;     //可还书数量
} User;

Book books[NUM];
User users[NUM];
Book booksMenu[NUM];
int booksNumber = 0;
int usersNumber = 0;
int sunBooksnumber = 0;
int year, month, day, hour, miniute, second;
int overyear, overmonth, overday, overhour, overminiute, oversecond;

void HeadmenuFunction();         //起始目录
void LoadmenuFunction(int text); //登陆目录
void Register();                 //注册函数
void BorrowBook(int text);       //借书函数
void ReturnBook(int text);       //还书函数
void load();                     //登陆函数
void Input_Book();               //书本录入
void ReadtoText();               //文件读取
void WritetoText();              //文件输出
void Administrator();            //管理员系统
int Administratorload();         //管理员登陆函数(成功0 ； 失败1)
void Deleteuser();               //删除用户

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
    printf("||                    现在是北京时间：%d-%02d-%02d %02d:%02d:%02d         ||\n",
           year, month, day, hour, miniute, second);
    printf("*= =============================================================  =*\n");
    system("pause");
    system("cls");
    HeadmenuFunction();
    return 0;
}

void HeadmenuFunction()
{
    char botton, key[3];
    int chose, text;
    while (1)
    {
        while (1)
        {
            printf("*= ================================================  =*\n");
            printf("|| *******欢迎使用福州大学至诚学院图书管理系统****** ||\n");
            printf("||    1.登陆                                         ||\n");
            printf("||    2.注册                                         ||\n");
            printf("||    3.管理员系统                                   ||\n");
            printf("||    0.退出                                         ||\n");
            printf("|| *******---------~~~~~~~~~~~~~~~~~~--------******* ||\n");
            printf("*= ================================================  =*\n");
            printf("请输入您需要的功能按钮:");
        again:
            scanf("%s", &key);
            getchar();
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
    printf("||                    现在是北京时间：%d-%02d-%02d %02d:%02d:%02d         ||\n",
           overyear, overmonth, overday, overhour, overminiute, oversecond);
    printf("||                                                                ||\n");
    printf("*= =============================================================  =*\n");
    system("pause");
    WritetoText();
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
    printf("开始时间:%d-%d-%d %d:%d:%d\n", year, month, day, hour, miniute, second);
    printf("结束时间:%d-%d-%d %d:%d:%d\n", overyear, overmonth, overday, overhour, overminiute, oversecond);
    system("pause");
    system("exit");
}

void LoadmenuFunction(int text)
{
    char botton, key[3];
    int chose, txt;
againLoadmenuFunction:
    while (1)
    {
        printf("*= ================================================  =*\n");
        printf("|| *******------------------------------------****** ||\n");
        printf("|| *  1.借书                                       * ||\n");
        printf("|| *  2.还书                                       * ||\n");
        printf("|| *  3.修改密码                                   * ||\n");
        printf("|| *  0.退出                                       * ||\n");
        printf("|| *******---------~~~~~~~~~~~~~~~~~~--------******* ||\n");
        printf("*= ================================================  =*\n");
        printf("请输入您需要的功能按钮:");
    again1:
        scanf("%s", &key);
        getchar();
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
    char newPassword[20], i_o_p[20];
    char again_key[3], again_botton;
    int again_txt, i_j_n;
    switch (chose)
    {
    case 0:
        while (1)
        {
            printf("确认退出福州大学至诚学院图书管理系统用户端吗?(是'1' ; 否'0')\n");
        againagain_0:
            scanf("%s", &again_key);
            getchar();
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
        if (booksNumber == 0)
        {
            printf("此书库还没有书本\n");
        }
        else
        {
        o_k_m:
            printf("请输入需要借阅的书本数量(最多借6本):");
            scanf("%s", &i_o_p);
            getchar();
            i_j_n = strlen(i_o_p);
            if (i_j_n != 1)
            {
                printf("输入错误,请重新输入\n");
                goto o_k_m;
            }
            if (i_o_p[0] <= '0' || i_o_p[0] >= '6')
            {
                printf("输入错误,请重新输入\n");
                goto o_k_m;
            }
            for (int i = 0; i < i_j_n; i++)
            {
                BorrowBook(text);
                if (booksNumber != 0)
                {
                    printf("第%d本借书完成\n", i + 1);
                }
            }
            printf("全部借书完成\n");
        }
        while (1)
        {
            printf("还需要继续吗?[yes(1) ; no(0)]\n");
        againagain_1:
            scanf("%s", &again_key);
            getchar();
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
        else
        {
            system("cls");
        }
        break;
    case 2:
        if (users[text].returnnumber == 0)
        {
            printf("此用户还未借书,不需要归还\n");
        }
        else
        {
        o_k_s:
            printf("请输入需要归还的书本数量(最多还6本):");
            scanf("%s", &i_o_p);
            getchar();
            i_j_n = strlen(i_o_p);
            if (i_j_n != 1)
            {
                printf("输入错误,请重新输入\n");
                goto o_k_s;
            }
            if (i_o_p[0] <= '0' || i_o_p[0] >= '6')
            {
                printf("输入错误,请重新输入\n");
                goto o_k_s;
            }
            for (int i = 0; i < i_j_n; i++)
            {
                ReturnBook(text);
                if (users[text].returnnumber != 0)
                {
                    printf("第%d本还书完成\n", i + 1);
                }
            }
            printf("全部还书完成\n");
        }
        while (1)
        {
            printf("还需要继续吗?[yes(1) ; no(0)]\n");
        againagain_2:
            scanf("%s", &again_key);
            getchar();
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
        else
        {
            system("cls");
        }
        break;
    case 3:
    q_s_c:
        printf("请输入新密码:");
        scanf("%s", &newPassword);
        getchar();
        if (!strcmp(users[text].password, newPassword))
        {
            printf("新密码不能与旧密码一致\n");
            printf("请重新输入\n");
            goto q_s_c;
        }
        strcpy(users[text].password, newPassword);
        printf("重置密码成功\n");
        while (1)
        {
            printf("还需要继续吗?[yes(1) ; no(0)]\n");
        againagain_3:
            scanf("%s", &again_key);
            getchar();
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
        else
        {
            system("cls");
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
    User process={0};
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
        printf("请输入联系方式:");
        scanf("%s", &process.phone);
        strcpy(users[usersNumber].phone, process.phone);
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
            users[usersNumber].returnnumber = 0;
            printf("请输入联系方式:");
            scanf("%s", &process.phone);
            strcpy(users[usersNumber].phone, process.phone);
            usersNumber++;
            printf("注册成功\n");
        }
    }
}

void load()
{
    User process={0};
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
    Book process={0};
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
        strcpy(booksMenu[sunBooksnumber].name, process.name);
        strcpy(booksMenu[sunBooksnumber].author, process.author);
        strcpy(booksMenu[sunBooksnumber].press, process.press);
        booksMenu[sunBooksnumber].id = sunBooksnumber + 1;
        sunBooksnumber++;
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
            strcpy(booksMenu[sunBooksnumber].name, process.name);
            strcpy(booksMenu[sunBooksnumber].author, process.author);
            strcpy(booksMenu[sunBooksnumber].press, process.press);
            booksMenu[sunBooksnumber].id = sunBooksnumber + 1;
            sunBooksnumber++;
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
        if (users[text].returnnumber == 6)
        {
            printf("您已借阅6本书,请归还后再进行借阅\n");
        }
        else
        {
            char lock[20];
            int botton = 0, t_num;
        BorrowBook:
            printf("-------------------书库目录-------------------------\n");
            for (int i = 0; i < booksNumber; i++)
            {
                printf("%2d %-30s %-20s %-20s\n", i, books[i].name, books[i].author, books[i].press);
            }
            printf("请输入需要借阅的序号:");
            scanf("%s", &lock);
            getchar();
            t_num = strlen(lock);
            for (int i_q = 0; i_q < t_num; i_q++)
            {
                if (lock[i_q] < '0' || lock[i_q] > '9')
                {
                    printf("输入错误,请重新输入\n");
                    goto BorrowBook;
                }
            }
            for (int i_q = 0; i_q < t_num; i_q++)
            {
                botton = (botton * 10) + lock[i_q] - '0';
            }
            if (botton >= 0 && botton < booksNumber)
            {
                printf("借阅成功\n");
                strcpy(users[text].returnmenu[users[text].returnnumber].author, books[botton].author);
                strcpy(users[text].returnmenu[users[text].returnnumber].name, books[botton].name);
                strcpy(users[text].returnmenu[users[text].returnnumber].press, books[botton].press);
                users[text].returnnumber++;
                for (int i = botton + 1; i < booksNumber; i++)
                {
                    strcpy(books[i - 1].author, books[i].author);
                    strcpy(books[i - 1].name, books[i].name);
                    strcpy(books[i - 1].press, books[i].press);
                }
                booksNumber--;
                for (int i = 0; i < booksNumber; i++)
                {
                    printf("%2d %-30s %-20s %-20s\n", i, books[i].name, books[i].author, books[i].press);
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
    if (users[text].returnnumber == 0)
    {
        printf("您还未借书\n");
    }
    else
    {
        for (int i = 0; i < users[text].returnnumber; i++)
        {
            printf("%d %-30s %-20s %-20s\n", i, users[text].returnmenu[i].name, users[text].returnmenu[i].author, users[text].returnmenu[i].press);
        }
        printf("请输入需要归还的书名:");
        scanf("%s", &process);
        getchar();
        int i;
        for (i = 0; i < users[text].returnnumber; i++)
        {
            if (!strcmp(users[text].returnmenu[i].name, process))
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
            strcpy(books[booksNumber].author, users[text].returnmenu[i].author);
            strcpy(books[booksNumber].name, users[text].returnmenu[i].name);
            strcpy(books[booksNumber].press, users[text].returnmenu[i].press);
            booksNumber++;
            for (int j = users[text].returnnumber - 1; j > i; j--)
            {
                strcpy(users[text].returnmenu[j - 1].author, users[text].returnmenu[j].author);
                strcpy(users[text].returnmenu[j - 1].name, users[text].returnmenu[j].name);
                strcpy(users[text].returnmenu[j - 1].press, users[text].returnmenu[j].press);
            }
            users[text].returnnumber--;
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
            fprintf(writeUser, "%-20s %-20s\n", users[i].name, users[i].password);
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
                fscanf(readUser, "%20s %20s\n", &users[i].name, &users[i].password);
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
                fscanf(readBook, "%2d %30s %20s %20s\n", &books[i].id, &books[i].name, &books[i].author, &books[i].press);
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
            printf("请输入您需要的功能按钮:");
        again1:
            scanf("%s", &key);
            getchar();
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
        int again_txt, t_num, t_g_b = 0;
        char lock[20];
        switch (chose)
        {
        case 1:
            Input_Book();
            while (1)
            {
                printf("还需要继续吗?[yes(1) ; no(0)]\n");
            againagain_a1:
                scanf("%s", &again_key);
                getchar();
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
            else
            {
                system("cls");
            }
            break;
        case 2:
            if (booksNumber == 0)
            {
                printf("此书库无图书\n");
            }
            else
            {
                for (int i = 0; i < sunBooksnumber; i++)
                {
                    for (int j = 0; j < booksNumber; j++)
                    {
                        if (!strcmp(booksMenu[i].name, books[j].name))
                        {
                            t_g_b = 1;
                            break;
                        }
                    }
                    if (t_g_b == 1)
                    {
                        printf("%2d %-30s %-20s %-20s  可借阅\n", i, booksMenu[i].name, booksMenu[i].author, booksMenu[i].press);
                    }
                    else
                    {
                        printf("%2d %-30s %-20s %-20s  已借阅\n", i, booksMenu[i].name, booksMenu[i].author, booksMenu[i].press);
                    }
                    t_g_b = 0;
                }
                printf("显示完毕\n");
            }
            while (1)
            {
                printf("还需要继续吗?[yes(1) ; no(0)]\n");
            againagain_a2:
                scanf("%s", &again_key);
                getchar();
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
            else
            {
                system("cls");
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
            j_y_l:
                printf("请输入要删除的序号：");
                scanf("%s", lock);
                getchar();
                t_num = strlen(lock);
                for (int i_q = 0; i_q < t_num; i_q++)
                {
                    if (lock[i_q] < '0' || lock[i_q] > '9')
                    {
                        printf("输入错误,请重新输入\n");
                        goto j_y_l;
                    }
                }
                for (int i_q = 0; i_q < t_num; i_q++)
                {
                    bookName = (bookName * 10) + lock[i_q] - '0';
                }
                if (bookName > 0 && bookName <= booksNumber)
                {
                    int confirm;
                    int flagN = 0;
                i_i_i:
                    printf("确认删除吗(是'1',否'0')");
                    scanf("%s", &lock);
                    getchar();
                    t_num = strlen(lock);
                    if (t_num != 1)
                    {
                        printf("输入错误,请重新输入\n");
                        goto i_i_i;
                    }
                    confirm = lock[0] - '0';
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
                scanf("%s", &again_key);
                getchar();
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
            else
            {
                system("cls");
            }
            break;
        case 4:
            Register();
            while (1)
            {
                printf("还需要继续吗?[yes(1) ; no(0)]\n");
            againagain_a4:
                scanf("%s", &again_key);
                getchar();
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
            else
            {
                system("cls");
            }
            break;
        case 5:
            if (usersNumber == 0)
            {
                printf("没有用户数据\n");
            }
            else
            {
                printf("-------------------------------------------------------------------------\n");
                for (int i = 0; i < usersNumber; i++)
                {
                    printf("%2d %-20s%-20s%-30s\n", i + 1, users[i].name, users[i].password, users[i].phone);
                }
                printf("-------------------------------------------------------------------------\n");
            }
            while (1)
            {
                printf("还需要继续吗?[yes(1) ; no(0)]\n");
            againagain_a5:
                scanf("%s", &again_key);
                getchar();
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
            else
            {
                system("cls");
            }
            break;
        case 6:
            Deleteuser();
            while (1)
            {
                printf("还需要继续吗?[yes(1) ; no(0)]\n");
            againagain_a6:
                scanf("%s", &again_key);
                getchar();
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
            else
            {
                system("cls");
            }
            break;
        case 7:
            ReadtoText();
            while (1)
            {
                printf("还需要继续吗?[yes(1) ; no(0)]\n");
            againagain_a7:
                scanf("%s", &again_key);
                getchar();
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
            else
            {
                system("cls");
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
                scanf("%s", &again_key);
                getchar();
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
            else
            {
                system("cls");
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
    int userName = 0;
    int i = 0, n;
    if (usersNumber == 0)
    {
        printf("删除失败！不存在用户信息！\n");
    }
    else
    {
        char lock[20];
        int t_num;
        printf("-------------------------------------------------------------\n");
        for (int j = 0; j < usersNumber; j++)
        {
            printf("%d  %-20s%-20s\n", j + 1, users[j].name, users[j].password);
        }
        printf("-------------------------------------------------------------\n");
    a:
        printf("请输入要删除的用户序号：");
        scanf("%s", &lock);
        getchar();
        t_num = strlen(lock);
        for (int i_q = 0; i_q < t_num; i_q++)
        {
            if (lock[i] < '0' || lock[i] > '9')
            {
                printf("输入错误,请重新输入\n");
                goto a;
            }
        }
        for (int i_q = 0; i_q < t_num; i_q++)
        {
            userName = (userName * 10) + lock[i_q] - '0';
        }
        if (userName > 0 && userName <= usersNumber)
        {
            if (users[userName - 1].returnnumber != 0)
            {
                printf("此用户还有未归还的图书,无法删除\n");
            }
            else
            {
                int confirm;
                int flagN = 0;
            b:
                printf("确认删除吗(是'1',否'0')");
                scanf("%s", &lock);
                getchar();
                t_num = strlen(lock);
                if (t_num != 1)
                {
                    printf("输入错误,请重新输入\n");
                    goto b;
                }
                if (lock[0] < '0' || lock[0] > '9')
                {
                    printf("输入错误,请重新输入\n");
                    goto b;
                }
                confirm = lock[0] - '0';
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
        }
        else
        {
            printf("删除失败！不存在此用户信息!\n");
        }
    }
}
