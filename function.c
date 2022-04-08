#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

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
            printf("����������Ҫ�Ĺ��ܰ�ť:");
        again:
            scanf("%c", &botton);
            getchar();
            if (botton == '\n')
            {
                gets(rubbish);
                goto again;
            }
            else if (botton > '3' || botton < '0')
            {
                gets(rubbish);
                printf("�������,����������\n");
            }
            else if (botton == '0' || botton == '1' || botton == '3' || botton == '2')
            {
                break;
            }
        }
        chose = botton - '0';
        switch (chose)
        {
        case 0:
            Over();
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
    system("pause");
    system("exit");
}

void LoadmenuFunction()
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
        BorrowBook();
        printf("����Ҫ������?[yes(1) ; no(0)]\n");
        scanf("%d", &againBotton);
        getchar();
        if (againBotton == 1)
        {
            goto againLoadmenuFunction;
        }
        break;
    case 2:
        ReturnBook();
        printf("����Ҫ������?[yes(1) ; no(0)]\n");
        scanf("%d", &againBotton);
        getchar();
        if (againBotton == 1)
        {
            goto againLoadmenuFunction;
        }
        break;
    default:
        printf("�������,����������\n");
        goto againLoadmenuFunction;
        break;
    }
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
    }
    else
    {
        for (int i = 0; i < usersNumber; i++)
        {
            if (strcmp(users[i].name, process.name))
            {
                printf("���û��Ѵ���,ע��ʧ��\n");
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("����������:");
            scanf("%s\n", &process.password);
            getchar();
            strcpy(users[usersNumber].name, process.name);
            strcpy(users[usersNumber].password, process.password);
            usersNumber++;
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
    }
    else
    {
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
                LoadmenuFunction();
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
        getchar();
        scanf("%s", &process.press);
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
            if (strcmp(books[i].name, process.name))
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
            getchar();
            scanf("%s", &process.press);
            strcpy(books[booksNumber].name, process.name);
            strcpy(books[booksNumber].author, process.author);
            strcpy(books[booksNumber].press, process.press);
            books[booksNumber].id = booksNumber + 1;
            booksNumber++;
        }
    }
}

void BorrowBook()
{
    if (booksNumber == 0)
    {
        printf("û���鱾\n");
    }
    else
    {
        int botton;
    BorrowBook:
        for (int i = 0; i < booksNumber; i++)
        {
            printf("%2d %-30s %-20s %-20s\n", books[i].id, books[i].name, books[i].author, books[i].press);
        }
        printf("��������Ҫ���ĵ����:");
        scanf("%d", &botton);
        getchar();
        if (botton >= 0 && botton < booksNumber)
        {
            printf("���ĳɹ�\n");
            for (int i = 0; i < booksNumber; i++)
            {
                if (i != botton)
                {
                    printf("%2d %-30s %-20s %-20s\n", books[i].id, books[i].name, books[i].author, books[i].press);
                }
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

void ReturnBook()
{
    char process[30];
    int flag = 1;
    printf("��������Ҫ�黹������:");
    scanf("%s", &process);
    getchar();
    for (int i = 0; i < booksNumber; i++)
    {
        if (!strcmp(books[i].name, process))
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        printf("�Ȿ�鲻����������\n");
    }
    else
    {
        printf("�黹�ɹ�\n");
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
            fprintf(writeUser, "%-20s%-20s\n", users[i].name, users[i].password);
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
                fscanf(readUser, "%-20s%-20s\n", users[i].name, users[i].password);
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
                fscanf(readBook, "%2d %-30s %-20s %-20s\n", books[i].id, books[i].name, books[i].author, books[i].press);
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
        int botton;
        int againAdministrator;
    againAdministrator:
        Administratormenu();
        printf("����������Ҫ�Ĺ��ܰ�ť:");
        scanf("%d", &botton);
        getchar();
        switch (botton)
        {
        case 1:
            Input_Book();
            printf("����Ҫ������?[yes(1) ; no(0)]\n");
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
            printf("����Ҫ������?[yes(1) ; no(0)]\n");
            scanf("%d", &againAdministrator);
            getchar();
            if (againAdministrator == 1)
            {
                goto againAdministrator;
            }
            break;
        case 3:
            Deletebook();
            printf("����Ҫ������?[yes(1) ; no(0)]\n");
            scanf("%d", &againAdministrator);
            getchar();
            if (againAdministrator == 1)
            {
                goto againAdministrator;
            }
            break;
        case 4:
            Register();
            printf("����Ҫ������?[yes(1) ; no(0)]\n");
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
                printf("û���û�����\n");
            }
            else
            {
                for (int i = 0; i < usersNumber; i++)
                {
                    printf("%-20s%-20s\n", users[i].name, users[i].password);
                }
            }
            printf("����Ҫ������?[yes(1) ; no(0)]\n");
            scanf("%d", &againAdministrator);
            getchar();
            if (againAdministrator == 1)
            {
                goto againAdministrator;
            }
            break;
        case 6:
            Deleteuser();
            printf("����Ҫ������?[yes(1) ; no(0)]\n");
            scanf("%d", &againAdministrator);
            getchar();
            if (againAdministrator == 1)
            {
                goto againAdministrator;
            }
            break;
        case 7:
            ReadtoText();
            printf("����Ҫ������?[yes(1) ; no(0)]\n");
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
            printf("����Ҫ������?[yes(1) ; no(0)]\n");
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
            printf("�������,����������\n");
            goto againAdministrator;
            break;
        }
    }
}

void Deletebook()
{
    char bookName[30];
    int i = 0, n;
    if (booksNumber == 0)
    {
        printf("ɾ��ʧ�ܣ�������ͼ����Ϣ��\n");
    }
    else
    {
        for (int j = 0; j < booksNumber; j++)
        {
            printf("%2d %-30s %-20s %-20s\n", books[i].id, books[i].name, books[i].author, books[i].press);
        }
        printf("������Ҫɾ����������");
        scanf("%s", &bookName);
        getchar();
        for (i = 0; i < booksNumber; i++)
        {
            if (!strcmp(books[i].name, bookName))
            {
                i = 1;
                break;
            }
        }
        if (i == 0)
        {
            printf("ɾ��ʧ�ܣ������ڸ�ͼ�飡\n");
        }
        else
        {
            int confirm;
            printf("ȷ��ɾ����(��'1',��'0')");
            scanf("%d", &confirm);
            getchar();
            if (confirm == 1)
            {
                n = i + 1;
                for (i = 0; i < booksNumber; i++)
                {
                    if (!strcmp(books[i].name, bookName))
                    {
                        break;
                    }
                }
                for (; i < n - 1; i++)
                {
                    books[i] = books[i + 1];
                }
                booksNumber--;
                printf("ɾ��ͼ����Ϣ�ɹ���\n");
            }
        }
    }
}

void Deleteuser()
{
    char userName[30];
    int i = 0, n;
    if (usersNumber == 0)
    {
        printf("ɾ��ʧ�ܣ��������û���Ϣ��\n");
    }
    else
    {
        for (int j = 0; j < usersNumber; j++)
        {
            printf("%-20s%-20s\n", users[i].name, users[i].password);
        }
        printf("������Ҫɾ�����û�����");
        scanf("%s", &userName);
        getchar();
        for (i = 0; i < usersNumber; i++)
        {
            if (!strcmp(users[i].name, userName))
            {
                i = 1;
                break;
            }
        }
        if (i == 0)
        {
            printf("ɾ��ʧ�ܣ������ڸ��û���\n");
        }
        else
        {
            int confirm;
            printf("ȷ��ɾ����(��'1',��'0')");
            scanf("%d", &confirm);
            getchar();
            if (confirm == 1)
            {
                n = i + 1;
                for (i = 0; i < usersNumber; i++)
                {
                    if (!strcmp(users[i].name, userName))
                    {
                        break;
                    }
                }
                for (; i < n - 1; i++)
                {
                    users[i] = users[i + 1];
                }
                usersNumber--;
                printf("ɾ���û���Ϣ�ɹ���\n");
            }
        }
    }
}
