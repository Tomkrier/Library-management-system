#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM 10

typedef struct
{
    int id;          //���
    char name[30];   //����
    char author[20]; //����
    char press[50];  //��������
} Book;

typedef struct
{
    char name[20];        //�û���
    char password[20];    //�û�����
    Book returnmenu[NUM]; //�ɽ�������
    int returnnumber;     //�ɽ�������
    Book borrowmenu[NUM]; //�ɻ�������
    int borrownumber;     //�ɻ�������
} User;

Book books[NUM];
User users[NUM];
int booksNumber = 0;
int usersNumber = 0;

int year, month, day, hour, miniute, second;
int overyear, overmonth, overday, overhour, overminiute, oversecond;

void HeadmenuFunction();         //��ʼĿ¼
void LoadmenuFunction(int text); //��½Ŀ¼
void Register();                 //ע�ắ��
void BorrowBook(int text);       //���麯��
void ReturnBook(int text);       //���麯��
void load();                     //��½����
void Input_Book();               //�鱾¼��
void ReadtoText();               //�ļ���ȡ
void WritetoText();              //�ļ����
void Administrator();            //����Աϵͳ
int Administratorload();         //����Ա��½����(�ɹ�0 �� ʧ��1)
void Deleteuser();               //ɾ���û�

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
    printf("||             ��ӭʹ�ø��ݴ�ѧ����ѧԺͼ�����ϵͳ               ||\n");
    printf("||                                                                ||\n");
    printf("||                    �����Ǳ���ʱ�䣺%d-%02d-%02d %02d:%02d:%02d         ||\n",
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
            printf("|| *******��ӭʹ�ø��ݴ�ѧ����ѧԺͼ�����ϵͳ****** ||\n");
            printf("||    1.��½                                         ||\n");
            printf("||    2.ע��                                         ||\n");
            printf("||    3.����Աϵͳ                                   ||\n");
            printf("||    0.�˳�                                         ||\n");
            printf("|| *******---------~~~~~~~~~~~~~~~~~~--------******* ||\n");
            printf("*= ================================================  =*\n");
            printf("����������Ҫ�Ĺ��ܰ�ť:");
        again:
            gets(key);
            text = strlen(key);
            if (text == 0)
            {
                goto again;
            }
            else if (text > 1)
            {
                printf("�������,����������\n");
            }
            else
            {
                botton = key[0];
                if (botton != '0' && botton != '1' && botton != '2' && botton != '3')
                {
                    printf("�������,����������\n");
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
    printf("||                    �����Ǳ���ʱ�䣺%d-%02d-%02d %02d:%02d:%02d         ||\n",
           overyear, overmonth, overday, overhour, overminiute, oversecond);
    printf("||                                                                ||\n");
    printf("*= =============================================================  =*\n");
    system("pause");
    WritetoText();
    system("cls");
    printf("����ʹ�õ���������:\n");
    if (booksNumber == 0 && usersNumber == 0)
    {
        printf("��\n");
    }
    else
    {
        printf("                             <<ͼ������>>\n");
        if (booksNumber == 0)
        {
            printf("��\n");
        }
        else
        {
            for (int j = 0; j < booksNumber; j++)
            {
                printf("%2d %-30s %-20s %-20s\n", j + 1, books[j].name, books[j].author, books[j].press);
            }
        };
        printf("                             <<�û�����>>\n");
        if (usersNumber == 0)
        {
            printf("��\n");
        }
        else
        {
            for (int j = 0; j < usersNumber; j++)
            {
                printf("%-20s%-20s\n", users[j].name, users[j].password);
            }
        }
    }
    printf("<<�˴θ��ݴ�ѧ����ѧԺͼ�����ϵͳ����ʱ��>>\n");
    printf("��ʼʱ��:%d-%d-%d %d:%d:%d\n", year, month, day, hour, miniute, second);
    printf("����ʱ��:%d-%d-%d %d:%d:%d\n", overyear, overmonth, overday, overhour, overminiute, oversecond);
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
        printf("|| *  1.����                                       * ||\n");
        printf("|| *  2.����                                       * ||\n");
        printf("|| *  3.�޸�����                                   * ||\n");
        printf("|| *  0.�˳�                                       * ||\n");
        printf("|| *******---------~~~~~~~~~~~~~~~~~~--------******* ||\n");
        printf("*= ================================================  =*\n");
        printf("����������Ҫ�Ĺ��ܰ�ť:");
    again1:
        gets(key);
        txt = strlen(key);
        if (txt == 0)
        {
            goto again1;
        }
        else if (txt > 1)
        {
            printf("�������,����������\n");
        }
        else
        {
            botton = key[0];
            if (botton != '1' && botton != '2' && botton != '3' && botton != '0')
            {
                printf("�������,����������\n");
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
            printf("ȷ���˳����ݴ�ѧ����ѧԺͼ�����ϵͳ�û�����?(��'1' ; ��'0')\n");
        againagain_0:
            gets(again_key);
            again_txt = strlen(again_key);
            if (again_txt == 0)
            {
                goto againagain_0;
            }
            else if (again_txt > 1)
            {
                printf("�������,����������\n");
            }
            else
            {
                again_botton = again_key[0];
                if (again_botton != '0' && again_botton != '1')
                {
                    printf("�������,����������\n");
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
            printf("����Ҫ������?[yes(1) ; no(0)]\n");
        againagain_1:
            gets(again_key);
            again_txt = strlen(again_key);
            if (again_txt == 0)
            {
                goto againagain_1;
            }
            else if (again_txt > 1)
            {
                printf("�������,����������\n");
            }
            else
            {
                again_botton = again_key[0];
                if (again_botton != '0' && again_botton != '1')
                {
                    printf("�������,����������\n");
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
            printf("����Ҫ������?[yes(1) ; no(0)]\n");
        againagain_2:
            gets(again_key);
            again_txt = strlen(again_key);
            if (again_txt == 0)
            {
                goto againagain_2;
            }
            else if (again_txt > 1)
            {
                printf("�������,����������\n");
            }
            else
            {
                again_botton = again_key[0];
                if (again_botton != '0' && again_botton != '1')
                {
                    printf("�������,����������\n");
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
        printf("������������:");
        scanf("%s", &newPassword);
        getchar();
        strcpy(users[text].password, newPassword);
        while (1)
        {
            printf("����Ҫ������?[yes(1) ; no(0)]\n");
        againagain_3:
            gets(again_key);
            again_txt = strlen(again_key);
            if (again_txt == 0)
            {
                goto againagain_3;
            }
            else if (again_txt > 1)
            {
                printf("�������,����������\n");
            }
            else
            {
                again_botton = again_key[0];
                if (again_botton != '0' && again_botton != '1')
                {
                    printf("�������,����������\n");
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
        printf("�������,����������\n");
        goto againLoadmenuFunction;
        break;
    }
    system("cls");
}

void Register()
{
    User process;
    int flag = 0;
    printf("�������û���:");
    scanf("%s", &process.name);
    getchar();
    if (usersNumber == 0)
    {
        printf("����������:");
        scanf("%s", &process.password);
        getchar();
        strcpy(users[usersNumber].name, process.name);
        strcpy(users[usersNumber].password, process.password);
        usersNumber++;
        printf("ע��ɹ�\n");
    }
    else
    {
        for (int i = 0; i < usersNumber; i++)
        {
            if (!strcmp(users[i].name, process.name))
            {
                printf("���û��Ѵ���,ע��ʧ��\n");
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("����������:");
            scanf("%s", &process.password);
            getchar();
            strcpy(users[usersNumber].name, process.name);
            strcpy(users[usersNumber].password, process.password);
            users[usersNumber].borrownumber = 0;
            users[usersNumber].returnnumber = 0;
            usersNumber++;
            printf("ע��ɹ�\n");
        }
    }
}

void load()
{
    User process;
    int flag = 1, i;
    if (usersNumber == 0)
    {
        printf("����ʧ��!�������û���Ϣ!\n");
        printf("�������ע��\n");
        Register();
        goto load_1;
    }
    else
    {
    load_1:
        printf("�������˺�:");
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
            printf("����������:");
            scanf("%s", &process.password);
            getchar();
            if (!strcmp(users[i].password, process.password))
            {
                printf("��½�ɹ�\n");
                if (users[i].borrownumber == 0)
                {
                    for (int m = 0; m < booksNumber; m++)
                    {
                        strcpy(users[i].borrowmenu[m].author, books[m].author);
                        strcpy(users[i].borrowmenu[m].name, books[m].name);
                        strcpy(users[i].borrowmenu[m].press, books[m].press);
                    }
                    users[i].borrownumber = booksNumber;
                }
                LoadmenuFunction(i);
            }
            else
            {
                printf("�������,��½ʧ��\n");
            }
        }
        else
        {
            printf("���޴��û�\n");
        }
    }
}

void Input_Book()
{
    Book process;
    int flag = 0;
    printf("����������:");
    scanf("%s", &process.name);
    getchar();
    if (booksNumber == 0)
    {
        printf("����������:");
        scanf("%s", &process.author);
        getchar();
        printf("�������������:");
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
                printf("���鱾�Ѵ���,ע��ʧ��\n");
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("����������:");
            scanf("%s", &process.author);
            getchar();
            printf("�������������:");
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
    if (users[text].borrownumber == 0)
    {
        printf("û���鱾\n");
    }
    else
    {
        if (users[text].returnnumber == 5)
        {
            printf("���ѽ���5����,��黹���ٽ��н���\n");
        }
        else
        {
            int botton;
        BorrowBook:
            printf("-------------------���Ŀ¼-------------------------\n");
            for (int i = 0; i < users[text].borrownumber; i++)
            {
                printf("%2d %-30s %-20s %-20s\n", i, users[text].borrowmenu[i].name, users[text].borrowmenu[i].author, users[text].borrowmenu[i].press);
            }
            printf("��������Ҫ���ĵ����:");
            scanf("%d", &botton);
            getchar();
            if (botton >= 0 && botton < users[text].borrownumber)
            {
                printf("���ĳɹ�\n");
                strcpy(users[text].returnmenu[users[text].returnnumber].author, users[text].borrowmenu[botton].author);
                strcpy(users[text].returnmenu[users[text].returnnumber].name, users[text].borrowmenu[botton].name);
                strcpy(users[text].returnmenu[users[text].returnnumber].press, users[text].borrowmenu[botton].press);
                users[text].returnnumber++;
                for (int i = botton + 1; i < users[text].borrownumber; i++)
                {
                    strcpy(users[text].borrowmenu[i - 1].author, users[text].borrowmenu[i].author);
                    strcpy(users[text].borrowmenu[i - 1].name, users[text].borrowmenu[i].name);
                    strcpy(users[text].borrowmenu[i - 1].press, users[text].borrowmenu[i].press);
                }
                users[text].borrownumber--;
                for (int i = 0; i < users[text].borrownumber; i++)
                {
                    printf("%2d %-30s %-20s %-20s\n", i, users[text].borrowmenu[i].name, users[text].borrowmenu[i].author, users[text].borrowmenu[i].press);
                }
                printf("��ʾ���\n");
            }
            else
            {
                printf("�������,����������\n");
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
        printf("����δ����\n");
    }
    else
    {
        for (int i = 0; i < users[text].returnnumber; i++)
        {
            printf("%d %-30s %-20s %-20s\n", i, users[text].returnmenu[i].name, users[text].returnmenu[i].author, users[text].returnmenu[i].press);
        }
        printf("��������Ҫ�黹������:");
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
            printf("��δ���Ȿ��\n");
        }
        else
        {
            printf("�黹�ɹ�\n");
            strcpy(users[text].borrowmenu[users[text].borrownumber].author, users[text].returnmenu[i].author);
            strcpy(users[text].borrowmenu[users[text].borrownumber].name, users[text].returnmenu[i].name);
            strcpy(users[text].borrowmenu[users[text].borrownumber].press, users[text].returnmenu[i].press);
            users[text].borrownumber++;
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
        printf("���ļ�ʧ��!\n");
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
        printf("���ļ�ʧ��!\n");
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
    printf("�ɹ�����¼д���ļ���\n");
}

void ReadtoText()
{
    int flag = 0;
    if ((usersNumber == 0) || (booksNumber == 0))
    {
        FILE *readUser;
        if ((readUser = fopen("user.txt", "r")) == NULL)
        {
            printf("�û����ļ�ʧ�ܣ�\n");
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
            printf("ͼ����ļ�ʧ�ܣ�\n");
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
            printf("�ɹ����ļ��������ݣ�\n");
        }
    }
    else
    {
        printf("��������,�޷����ļ�����\n");
    }
}

int Administratorload()
{
    char id[] = {"���ݴ�ѧ����ѧԺ"};
    char password[] = {"123456"};
    char process[20];
    printf("���������Ա�˺�:");
    scanf("%s", &process);
    getchar();
    if (!strcmp(id, process))
    {
        printf("���������Ա����:");
        scanf("%s", &process);
        getchar();
        if (!strcmp(password, process))
        {
            printf("��½�ɹ�\n");
            return 0;
        }
        else
        {
            printf("�������\n");
            printf("��½ʧ��\n");
        }
    }
    else
    {
        printf("�˺Ŵ���\n");
        printf("��½ʧ��\n");
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
            printf("||  == **** * ��ӭ����ͼ�����ϵͳ�����  *  **** == ||\n");
            printf("||  == 1.�鱾¼��                                 == ||\n");
            printf("||  == 2.�鱾��ѯ                                 == ||\n");
            printf("||  == 3.�¼��鱾                                 == ||\n");
            printf("||  == 4.�û�¼��                                 == ||\n");
            printf("||  == 5.�û���ѯ                                 == ||\n");
            printf("||  == 6.�û�ɾ��                                 == ||\n");
            printf("||  == 7.���ݵ���                                 == ||\n");
            printf("||  == 8.��ʽ�����ݿ�                             == ||\n");
            printf("||  == 0.�˳�����ϵͳ                             == ||\n");
            printf("|| *******---------~~~~~~~~~~~~~~~~~~--------******* ||\n");
            printf("*= ================================================  =*\n");
            printf("����������Ҫ�Ĺ��ܰ�ť:");
        again1:
            gets(key);
            text = strlen(key);
            if (text == 0)
            {
                goto again1;
            }
            else if (text > 1)
            {
                printf("�������,����������\n");
            }
            else
            {
                botton = key[0];
                if (botton == '9')
                {
                    printf("�������,����������\n");
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
                printf("����Ҫ������?[yes(1) ; no(0)]\n");
            againagain_a1:
                gets(again_key);
                again_txt = strlen(again_key);
                if (again_txt == 0)
                {
                    goto againagain_a1;
                }
                else if (again_txt > 1)
                {
                    printf("�������,����������\n");
                }
                else
                {
                    again_botton = again_key[0];
                    if (again_botton != '0' && again_botton != '1')
                    {
                        printf("�������,����������\n");
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
                printf("�������ͼ��\n");
            }
            else
            {
                for (int i = 0; i < booksNumber; i++)
                {
                    printf("%2d %-30s %-20s %-20s\n", books[i].id, books[i].name, books[i].author, books[i].press);
                }
                printf("��ʾ���\n");
            }
            while (1)
            {
                printf("����Ҫ������?[yes(1) ; no(0)]\n");
            againagain_a2:
                gets(again_key);
                again_txt = strlen(again_key);
                if (again_txt == 0)
                {
                    goto againagain_a2;
                }
                else if (again_txt > 1)
                {
                    printf("�������,����������\n");
                }
                else
                {
                    again_botton = again_key[0];
                    if (again_botton != '0' && again_botton != '1')
                    {
                        printf("�������,����������\n");
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
                printf("ɾ��ʧ�ܣ�������ͼ����Ϣ��\n");
            }
            else
            {
                for (int j = 0; j < booksNumber; j++)
                {
                    printf("%2d %-30s %-20s %-20s\n", j + 1, books[j].name, books[j].author, books[j].press);
                }
                printf("������Ҫɾ������ţ�");
                scanf("%d", &bookName);
                getchar();
                if (bookName > 0 && bookName <= booksNumber)
                {
                    int confirm;
                    int flagN = 0;
                    printf("ȷ��ɾ����(��'1',��'0')");
                    scanf("%d", &confirm);
                    getchar();
                    if (confirm == 1)
                    {
                        printf("ɾ��ͼ����Ϣ�ɹ���\n");
                        bookName = bookName - 1;
                        for (int i = bookName + 1; i < booksNumber; i++)
                        {
                            books[i - 1] = books[i];
                        }
                        booksNumber--;
                    }
                    else
                    {
                        printf("ɾ��ʧ��\n");
                    }
                }
                else
                {
                    printf("û���Ȿͼ��,�޷�ɾ��\n");
                }
            }
            while (1)
            {
                printf("����Ҫ������?[yes(1) ; no(0)]\n");
            againagain_a3:
                gets(again_key);
                again_txt = strlen(again_key);
                if (again_txt == 0)
                {
                    goto againagain_a3;
                }
                else if (again_txt > 1)
                {
                    printf("�������,����������\n");
                }
                else
                {
                    again_botton = again_key[0];
                    if (again_botton != '0' && again_botton != '1')
                    {
                        printf("�������,����������\n");
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
                printf("����Ҫ������?[yes(1) ; no(0)]\n");
            againagain_a4:
                gets(again_key);
                again_txt = strlen(again_key);
                if (again_txt == 0)
                {
                    goto againagain_a4;
                }
                else if (again_txt > 1)
                {
                    printf("�������,����������\n");
                }
                else
                {
                    again_botton = again_key[0];
                    if (again_botton != '0' && again_botton != '1')
                    {
                        printf("�������,����������\n");
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
                printf("û���û�����\n");
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
                printf("����Ҫ������?[yes(1) ; no(0)]\n");
            againagain_a5:
                gets(again_key);
                again_txt = strlen(again_key);
                if (again_txt == 0)
                {
                    goto againagain_a5;
                }
                else if (again_txt > 1)
                {
                    printf("�������,����������\n");
                }
                else
                {
                    again_botton = again_key[0];
                    if (again_botton != '0' && again_botton != '1')
                    {
                        printf("�������,����������\n");
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
                printf("����Ҫ������?[yes(1) ; no(0)]\n");
            againagain_a6:
                gets(again_key);
                again_txt = strlen(again_key);
                if (again_txt == 0)
                {
                    goto againagain_a6;
                }
                else if (again_txt > 1)
                {
                    printf("�������,����������\n");
                }
                else
                {
                    again_botton = again_key[0];
                    if (again_botton != '0' && again_botton != '1')
                    {
                        printf("�������,����������\n");
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
                printf("����Ҫ������?[yes(1) ; no(0)]\n");
            againagain_a7:
                gets(again_key);
                again_txt = strlen(again_key);
                if (again_txt == 0)
                {
                    goto againagain_a7;
                }
                else if (again_txt > 1)
                {
                    printf("�������,����������\n");
                }
                else
                {
                    again_botton = again_key[0];
                    if (again_botton != '0' && again_botton != '1')
                    {
                        printf("�������,����������\n");
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
                printf("����Ҫ������?[yes(1) ; no(0)]\n");
            againagain_a8:
                gets(again_key);
                again_txt = strlen(again_key);
                if (again_txt == 0)
                {
                    goto againagain_a8;
                }
                else if (again_txt > 1)
                {
                    printf("�������,����������\n");
                }
                else
                {
                    again_botton = again_key[0];
                    if (again_botton != '0' && again_botton != '1')
                    {
                        printf("�������,����������\n");
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
            printf("���ѳɹ��˳����ݴ�ѧ����ѧԺͼ�����ϵͳ����Ա��\n");
            system("pause");
            system("cls");
            break;
        default:
            printf("�������,����������\n");
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
        printf("ɾ��ʧ�ܣ��������û���Ϣ��\n");
    }
    else
    {
        for (int j = 0; j < usersNumber; j++)
        {
            printf("%d  %-20s%-20s\n", j, users[j].name, users[j].password);
        }
        printf("������Ҫɾ�����û���ţ�");
        scanf("%d", &userName);
        getchar();
        if (userName > 0 && userName <= usersNumber)
        {
            int confirm;
            int flagN = 0;
            printf("ȷ��ɾ����(��'1',��'0')");
            scanf("%d", &confirm);
            getchar();
            if (confirm == 1)
            {
                printf("ɾ���û���Ϣ�ɹ���\n");
                userName = userName - 1;
                for (int i = userName + 1; i < usersNumber; i++)
                {
                    users[i - 1] = users[i];
                }
                usersNumber--;
            }
            else
            {
                printf("ɾ��ʧ��\n");
            }
        }
        else
        {
            printf("ɾ��ʧ�ܣ������ڴ��û���Ϣ!\n");
        }
    }
}