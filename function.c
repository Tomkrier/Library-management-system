#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include "function.h"

int booksNumber = 0;
int usersNumber = 0;

Book books[NUM];
User users[NUM];

void HeadmenuFunction()
{
    char botton;
    char rubbish[NUM];
    int chose;
    while (1)
    {
        while (1)
        {
            Headmenu();
            printf("请输入您需要的功能按钮:");
        again:
            scanf("%c", &botton);
            getchar();
            if (botton == '\n')
            {
                gets(rubbish);
                goto again;
            }
            else if (botton >= '0' && botton <= '9')
            {
                if (botton > '3')
                {
                    printf("输入错误,请重新输入\n");
                }
                else if (botton == '0' || botton == '1' || botton == '3' || botton == '2')
                {
                    break;
                }
            }
            else
            {
                gets(rubbish);
                printf("输入错误,请重新输入\n");
            }
        }
        chose = botton - '0';
        switch (chose)
        {
        case 0:
            printf("*= ================================================  =*\n");
            printf("||                       谢谢使用                    ||\n");
            printf("*= ================================================  =*\n");
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
    printf("                             <<图书数据>>\n");
    for (int j = 0; j < booksNumber; j++)
    {
        printf("%2d %-30s %-20s %-20s\n", j + 1, books[j].name, books[j].author, books[j].press);
    }
    printf("                             <<用户数据>>\n");
    for (int j = 0; j < usersNumber; j++)
    {
        printf("%-20s%-20s\n", users[j].name, users[j].password);
    }
    system("pause");
    system("exit");
}

void LoadmenuFunction(int text)
{
    int botton;
    int againBotton;
againLoadmenuFunction:
    Loadmenu();
    scanf("%d", &botton);
    getchar();
    switch (botton)
    {
    case 1:
        BorrowBook(text);
        printf("还需要继续吗?[yes(1) ; no(0)]\n");
        scanf("%d", &againBotton);
        getchar();
        if (againBotton == 1)
        {
            goto againLoadmenuFunction;
        }
        break;
    case 2:
        ReturnBook(text);
        printf("还需要继续吗?[yes(1) ; no(0)]\n");
        scanf("%d", &againBotton);
        getchar();
        if (againBotton == 1)
        {
            goto againLoadmenuFunction;
        }
        break;
    default:
        printf("输入错误,请重新输入\n");
        goto againLoadmenuFunction;
        break;
    }
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
    }
    else
    {
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
        int botton;
    BorrowBook:
        for (int i = 0; i < booksNumber; i++)
        {
            printf("%2d %-30s %-20s %-20s\n", books[i].id, books[i].name, books[i].author, books[i].press);
        }
        printf("请输入需要借阅的书号:");
        scanf("%d", &botton);
        getchar();
        if (botton >= 0 && botton < booksNumber + 1)
        {
            printf("借阅成功\n");
            int vec;
            for (int i = 0; i < booksNumber; i++)
            {
                if (i != botton - 1)
                {
                    printf("%2d %-30s %-20s %-20s\n", books[i].id, books[i].name, books[i].author, books[i].press);
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
            printf("%2d %-30s %-20s %-20s\n",
                   users[text].borrowmenu[i].id,
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

void Administrator()
{
    if (!Administratorload())
    {
        char a[4] = {"\0"};
        char botton;
        int againAdministrator;
        char rubbish[NUM];
        int chose;
    againAdministrator:

        while (1)
        {
        again1:
            Administratormenu();
            printf("请输入您需要的功能按钮:");
            scanf("%c", &botton);
            getchar();
            if (botton == '\n')
            {
                gets(rubbish);
                goto again1;
            }
            else if (botton >= '0' && botton <= '9')
            {
                if (botton == '9')
                {
                    printf("输入错误,请重新输入\n");
                }
                else
                {
                    break;
                }
            }
            else
            {
                gets(rubbish);
                printf("输入错误,请重新输入\n");
            }
        }
        chose = botton - '0';
        int i_i = 0, n_i, t_i = 0;
        int bookName;
        switch (chose)
        {
        case 1:
            Input_Book();
            printf("还需要继续吗?[yes(1) ; no(0)]\n");
            scanf("%d", &againAdministrator);
            getchar();
            if (againAdministrator == 1)
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
            printf("还需要继续吗?[yes(1) ; no(0)]\n");
            scanf("%d", &againAdministrator);
            getchar();
            if (againAdministrator == 1)
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
                        for (int i = booksNumber - 1; i > bookName; i--)
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
            printf("还需要继续吗?[yes(1) ; no(0)]\n");
            scanf("%d", &againAdministrator);
            getchar();
            if (againAdministrator == 1)
            {
                goto againAdministrator;
            }
            break;
        case 4:
            Register();
            printf("还需要继续吗?[yes(1) ; no(0)]\n");
            scanf("%d", &againAdministrator);
            getchar();
            if (againAdministrator == 1)
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
            printf("还需要继续吗?[yes(1) ; no(0)]\n");
            scanf("%d", &againAdministrator);
            getchar();
            if (againAdministrator == 1)
            {
                goto againAdministrator;
            }
            break;
        case 6:
            Deleteuser();
            printf("还需要继续吗?[yes(1) ; no(0)]\n");
            scanf("%d", &againAdministrator);
            getchar();
            if (againAdministrator == 1)
            {
                goto againAdministrator;
            }
            break;
        case 7:
            ReadtoText();
            printf("还需要继续吗?[yes(1) ; no(0)]\n");
            scanf("%d", &againAdministrator);
            getchar();
            if (againAdministrator == 1)
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
            printf("还需要继续吗?[yes(1) ; no(0)]\n");
            scanf("%d", &againAdministrator);
            getchar();
            if (againAdministrator == 1)
            {
                goto againAdministrator;
            }
            break;
        case 0:
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
            printf("%-20s%-20s\n", users[i].name, users[i].password);
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
                for (int i = usersNumber - 1; i > userName; i--)
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
