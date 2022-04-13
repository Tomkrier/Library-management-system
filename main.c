#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include "function.h"

int main()
{
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

void Loadmenu()
{
    printf("*= ================================================  =*\n");
    printf("|| *******------------------------------------****** ||\n");
    printf("|| *  1.借书                                       * ||\n");
    printf("|| *  2.还书                                       * ||\n");
    printf("|| *******---------~~~~~~~~~~~~~~~~~~--------******* ||\n");
    printf("*= ================================================  =*\n");
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
