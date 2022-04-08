#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char name[20];     //�û���
    char password[20]; //�û�����
} User;

void Headmenu();          //��ʼĿ¼UI
void HeadmenuFunction();  //��ʼĿ¼
void LoadmenuFunction();  //��½Ŀ¼
void Loadmenu();          //��½Ŀ¼UI
void Register();          //ע�ắ��
void BorrowBook();        //���麯��
void ReturnBook();        //���麯��
void load();              //��½����
void Input_Book();        //�鱾¼��
void ReadtoText();        //�ļ���ȡ
void WritetoText();       //�ļ����
void Administrator();     //����Աϵͳ
void Administratormenu(); //����ԱUI
int Administratorload();  //����Ա��½����(�ɹ�0 �� ʧ��1)
void Deletebook();        //ɾ��
void Deleteuser();        //ɾ���û�
void Over();              //����ر�UI
