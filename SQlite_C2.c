
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include "sqlite3.h"

struct TEA {
    char T_num[20];
    char T_name[20];
    char T_sex[20];
    char birthday[20];
    char T_address[20];
    char data[20];
    char data2[20];
    char field[20];
    char field2[20];
    int ret;
}TEACHER;
void hello(sqlite3*);
void Interface(sqlite3*);
sqlite3* Create(sqlite3*);
void Delete(sqlite3*);
void Add(sqlite3*);
void Update(sqlite3*);
void Select(sqlite3*);
void See(sqlite3* p);
void View(sqlite3* p);
void NView(sqlite3* p);;
void DView(sqlite3* p);
void initialize();

static int callback(void* NotUsed, int argc, char** argv, char** azColName);

static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void initialize()///结构体初始化
{
    TEACHER.T_num[20] = 0;
    TEACHER.T_name[20] = 0;
    TEACHER.T_sex[20] = 0;
    TEACHER.birthday[20] = 0;
    TEACHER.T_address[20] = 0;
    TEACHER.data[20] = 0;
    TEACHER.data2[20] = 0;
    TEACHER.field[20] = 0;
    TEACHER.field2[20] = 0;
    TEACHER.ret = 0;
}

void Select(sqlite3* p)///查询信息
{

    char b = 0;
    char character[20];
    char sql[300];
    char* mistake;
    int choose;
    if (p == NULL)
    {
        fprintf(stderr, "未连接数据库\n");
        Sleep(1000);
    }
    else
    {
        while (1)
        {
            system("cls");
            initialize();
            TEACHER.ret = 0;
            fflush(stdin);
            printf("\t\t*****************************************\n");
            printf("\t\t*\t\t\t\t\t*\n");
            printf("\t\t*\t     请选择查询方式：     \t*\n");
            printf("\t\t*\t\t\t\t\t*\n");
            printf("\t\t*****************************************\n");
            printf("\t\t\t  **①- 编  号 -**\n");
            printf("\t\t\t  **②- 教工号 -**\n");
            printf("\t\t\t  **③- 姓  名 -**\n");
            printf("\t\t\t  **④- 性  别 -**\n");
            printf("\t\t\t  **⑤-出生年月-**\n");
            printf("\t\t\t  **⑥-家庭住址-**\n");
            choose = getch();
            switch (choose)
            {
            case '1':strcpy(TEACHER.field, "id"); strcpy(character, "编号"); break;
            case '2':strcpy(TEACHER.field, "num"); strcpy(character, "教工号"); break;
            case '3':strcpy(TEACHER.field, "name"); strcpy(character, "姓名"); break;
            case '4':strcpy(TEACHER.field, "sex"); strcpy(character, "性别"); break;
            case '5':strcpy(TEACHER.field, "birthday"); strcpy(character, "出生年月"); break;
            case '6':strcpy(TEACHER.field, "address"); strcpy(character, "家庭住址"); break;
            }
            printf("\n\t\t请输入要查询的%s:", character);
            scanf("%s", TEACHER.data);
            sprintf(sql, "select *from teacher WHERE `%s` = '%s'", TEACHER.field, TEACHER.data);
            TEACHER.ret = sqlite3_exec(p, sql, callback, 0, &mistake);
            if (TEACHER.ret != SQLITE_OK)
            {
                printf("\t\t查询失败！\n\a");
                fprintf(stderr, "\t\t失败原因：%s\n", mistake);
                sqlite3_free(mistake);
                getch();
                continue;
            }
            else
                printf("\t\t查询成功\n");
            Sleep(2000);
            printf("\t\t是否继续查询Y/N");
            b = getch();
            if (b == 'Y' || b == 'y')
                continue;
            else
                break;
        }
    }
}

void Delete(sqlite3* p)///删除信息
{
    char b = 0;
    char character[20];
    char sql[300];
    char* mistake;
    int choose;
    if (p == NULL)
    {
        fprintf(stderr, "未连接数据库\n");
        Sleep(1000);
    }
    else
    {
        while (1)
        {
            system("cls");
            initialize();
            TEACHER.ret = 0;
            fflush(stdin);
            printf("\t\t*****************************************\n");
            printf("\t\t*\t\t\t\t\t*\n");
            printf("\t\t*\t  请选择删除的查询方式：  \t*\n");
            printf("\t\t*\t\t\t\t\t*\n");
            printf("\t\t*****************************************\n");
            printf("\t\t\t  **①- 编  号 -**\n");
            printf("\t\t\t  **②- 教工号 -**\n");
            printf("\t\t\t  **③- 姓  名 -**\n");
            printf("\t\t\t  **④- 性  别 -**\n");
            printf("\t\t\t  **⑤-出生年月-**\n");
            printf("\t\t\t  **⑥-家庭住址-**\n");
            choose = getch();
            switch (choose)
            {
            case '1':strcpy(TEACHER.field, "id"); strcpy(character, "编号"); break;
            case '2':strcpy(TEACHER.field, "num"); strcpy(character, "教工号"); break;
            case '3':strcpy(TEACHER.field, "name"); strcpy(character, "姓名"); break;
            case '4':strcpy(TEACHER.field, "sex"); strcpy(character, "性别"); break;
            case '5':strcpy(TEACHER.field, "birthday"); strcpy(character, "出生年月"); break;
            case '6':strcpy(TEACHER.field, "address"); strcpy(character, "家庭住址"); break;
            }
            printf("\n\t\t请输入要删除的%s:", character);
            scanf("%s", TEACHER.data);
            sprintf(sql, "delete from teacher WHERE `%s` = '%s'", TEACHER.field, TEACHER.data);
            TEACHER.ret = sqlite3_exec(p, sql, callback, 0, &mistake);
            if (TEACHER.ret != SQLITE_OK)
            {
                printf("\t\t删除失败！\n\a");
                fprintf(stderr, "\t\t失败原因：%s\n", mistake);
                sqlite3_free(mistake);
                getch();
                continue;
            }
            else
                printf("\t\t删除成功\n");
            Sleep(2000);
            printf("\t\t是否继续删除Y/N");
            b = getch();
            if (b == 'Y' || b == 'y')
                continue;
            else
                break;
        }
    }
}

void Add(sqlite3* p)///添加信息
{
    char b = 0;
    char sql[300];
    char* mistake;
    if (p == NULL)
    {
        fprintf(stderr, "未连接数据库\n");
        Sleep(1000);
    }
    else
    {
        while (1)
        {
            system("cls");
            initialize();
            TEACHER.ret = 0;
            fflush(stdin);
            printf("\t\t*****************************************\n");
            printf("\t\t*\t\t\t\t\t*\n");
            printf("\t\t*\t      清按照提示输入      \t*\n");
            printf("\t\t*\t\t\t\t\t*\n");
            printf("\t\t*****************************************\n");
            printf("\t\t请输入教工号：");
            scanf("%s", TEACHER.T_num);
            printf("\t\t请输入姓名：");
            scanf("%s", TEACHER.T_name);
            printf("\t\t请输入性别：");
            scanf("%s", TEACHER.T_sex);
            printf("\t\t请输入出生年月（xxxx-xx-xx）：");
            scanf("%s", TEACHER.birthday);
            printf("\t\t请输入家庭住址：");
            scanf("%s", TEACHER.T_address);
            sprintf(sql, "insert into teacher(num,name,sex,birthday,address) VALUES (%s,\"%s\",\"%s\",\"%s\",\"%s\");", TEACHER.T_num, TEACHER.T_name, TEACHER.T_sex, TEACHER.birthday, TEACHER.T_address);
            TEACHER.ret = sqlite3_exec(p, sql, callback, 0, &mistake);
            if (TEACHER.ret != SQLITE_OK)
            {
                fprintf(stderr, "错误：%s\n", mistake);
                sqlite3_free(mistake);
            }
            else
                printf("\t\t添加成功\n");
            Sleep(2000);
            printf("\t\t是否继续输入Y/N");
            b = getch();
            if (b == 'Y' || b == 'y')
                continue;
            else
                break;
        }
    }
}
void Update(sqlite3* p)
{
    char b = 0;
    char character1[20];
    char character2[20];
    char sql[300];
    char* mistake;
    int choose;
    if (p == NULL)
    {
        fprintf(stderr, "未连接数据库\n");
        Sleep(1000);
    }
    else
    {
        while (1)
        {
            system("cls");
            initialize();
            TEACHER.ret = 0;
            fflush(stdin);
            printf("\t\t*****************************************\n");
            printf("\t\t*\t\t\t\t\t*\n");
            printf("\t\t*\t  请选择要修改的信息：  \t*\n");
            printf("\t\t*\t\t\t\t\t*\n");
            printf("\t\t*****************************************\n");
            printf("\t\t\t  **①- 编  号 -**\n");
            printf("\t\t\t  **②- 教工号 -**\n");
            printf("\t\t\t  **③- 姓  名 -**\n");
            printf("\t\t\t  **④- 性  别 -**\n");
            printf("\t\t\t  **⑤-出生年月-**\n");
            printf("\t\t\t  **⑥-家庭住址-**\n");
            choose = getch();
            switch (choose)
            {
            case '1':strcpy(TEACHER.field, "id"); strcpy(character1, "编号"); break;
            case '2':strcpy(TEACHER.field, "num"); strcpy(character1, "教工号"); break;
            case '3':strcpy(TEACHER.field, "name"); strcpy(character1, "姓名"); break;
            case '4':strcpy(TEACHER.field, "sex"); strcpy(character1, "性别"); break;
            case '5':strcpy(TEACHER.field, "birthday"); strcpy(character1, "出生年月"); break;
            case '6':strcpy(TEACHER.field, "address"); strcpy(character1, "家庭住址"); break;
            }
            printf("\n\t\t请输入要修改后的%s:", character1);
            scanf("%s", TEACHER.data);
            system("cls");
            printf("\t\t*****************************************\n");
            printf("\t\t*\t\t\t\t\t*\n");
            printf("\t\t*\t  请选择要修改的条件：  \t*\n");
            printf("\t\t*\t\t\t\t\t*\n");
            printf("\t\t*****************************************\n");
            printf("\t\t\t  **①- 编  号 -**\n");
            printf("\t\t\t  **②- 教工号 -**\n");
            printf("\t\t\t  **③- 姓  名 -**\n");
            printf("\t\t\t  **④- 性  别 -**\n");
            printf("\t\t\t  **⑤-出生年月-**\n");
            printf("\t\t\t  **⑥-家庭住址-**\n");
            choose = getch();
            switch (choose)
            {
            case '1':strcpy(TEACHER.field2, "id"); strcpy(character2, "编号"); break;
            case '2':strcpy(TEACHER.field2, "num"); strcpy(character2, "教工号"); break;
            case '3':strcpy(TEACHER.field2, "name"); strcpy(character2, "姓名"); break;
            case '4':strcpy(TEACHER.field2, "sex"); strcpy(character2, "性别"); break;
            case '5':strcpy(TEACHER.field2, "birthday"); strcpy(character2, "出生年月"); break;
            case '6':strcpy(TEACHER.field2, "address"); strcpy(character2, "家庭住址"); break;
            }
            printf("\n\t\t清输入条件%s:", character2);
            scanf("%s", TEACHER.data2);
            sprintf(sql, "update teacher set %s = \"%s\" where %s = \"%s\"", TEACHER.field, TEACHER.data, TEACHER.field2, TEACHER.data2);
            TEACHER.ret = sqlite3_exec(p, sql, callback, 0, &mistake);
            if (TEACHER.ret != SQLITE_OK)
            {
                printf("\t\t修改失败！\n\a");
                fprintf(stderr, "\t\t失败原因：%s\n", mistake);
                sqlite3_free(mistake);
                getch();
                continue;
            }
            else
                printf("\t\t修改成功\n");
            Sleep(2000);
            printf("\t\t是否继续修改Y/N");
            b = getch();
            if (b == 'Y' || b == 'y')
                continue;
            else
                break;
        }
    }
}
void See(sqlite3* p)///遍历
{
    char statement[100] = "select * from teacher;";
    char* mistake;
    if (p == NULL)
    {
        fprintf(stderr, "未连接数据库\n");
        Sleep(1000);
    }
    else
    {
        TEACHER.ret = sqlite3_exec(p, statement, callback, NULL, &mistake);
        if (TEACHER.ret != SQLITE_OK)
        {
            fprintf(stderr, "错误：%s\n", mistake);
        }
        getch();
    }
}

sqlite3* Create(sqlite3* p)///创建表
{
    initialize();
    char* error = 0;
    char sql[400] = "create table teacher("  \
        "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE," \
        "num int(10) NOT NULL UNIQUE," \
        "name varchar(20) NOT NULL," \
        "sex varchar(4) NOT NULL," \
        "birthday DATETIME," \
        "address varchar(50));";
    if (p == NULL)
    {
        fprintf(stderr, "未连接数据库\n");
        Sleep(1000);///NOT NULL
    }
    else
    {

        TEACHER.ret = sqlite3_exec(p, sql, callback, NULL, &error);
        if (TEACHER.ret != SQLITE_OK)
        {
            system("cls");
            printf("\t\t*****************************************\n");
            printf("\t\t*\t\t\t\t\t*\n");
            printf("\t\t*\t      表格创建失败！      \t*\n");
            printf("\t\t*\t\t\t\t\t*\n");
            printf("\t\t*****************************************\n");
            fprintf(stderr, "\t\t  失败原因: %s\n", error);
            sqlite3_free(error);
            getch();
        }
        else
        {
            system("cls");
            printf("\t\t*****************************************\n");
            printf("\t\t*\t\t\t\t\t*\n");
            printf("\t\t*\t      表格创建成功！      \t*\n");
            printf("\t\t*\t\t\t\t\t*\n");
            printf("\t\t*****************************************\n");
            Sleep(2000);
        }
    }

    return p;
}

void Interface(sqlite3* p)///操作界面
{
    int choose;
    while (1)
    {
        system("cls");
        initialize();
        fflush(stdin);
        printf("\t\t*****************************************\n");
        printf("\t\t*\t\t\t\t\t*\n");
        printf("\t\t*\t      选择需要的操作      \t*\n");
        printf("\t\t*\t\t\t\t\t*\n");
        printf("\t\t*****************************************\n");
        printf("\t\t\t  **① -创建表- **\n");
        printf("\t\t\t  **② -表删除- **\n");
        printf("\t\t\t  **③ -表增加- **\n");
        printf("\t\t\t  **④ -表查询- **\n");
        printf("\t\t\t  **⑤ -表输出- **\n");
        printf("\t\t\t  **⑥ -表修改- **\n");
        printf("\t\t\t  **⑦ -视  图- **\n");
        choose = getch();
        switch (choose)
        {
        case '1':p = Create(p); break;
        case '2':Delete(p); break;
        case '3':Add(p); break;
        case '4':Select(p); break;
        case '5':See(p); break;
        case '6':Update(p); break;
        case '7':View(p); break;
        }
    }
}

void View(sqlite3* p)///视  图
{
    int choose;
    if (p == NULL)
    {
        fprintf(stderr, "未连接数据库\n");
        Sleep(1000);
    }
    else
    {
        while (1)
        {
            system("cls");
            fflush(stdin);
            printf("\t\t*****************************************\n");
            printf("\t\t*\t\t\t\t\t*\n");
            printf("\t\t*\t    请选择执行的操作：    \t*\n");
            printf("\t\t*\t\t\t\t\t*\n");
            printf("\t\t*****************************************\n");
            printf("\t\t\t  **①-创建视图-**\n");
            printf("\t\t\t  **②-删除视图-**\n");
            printf("\t\t\t  **③- 返  回 -**\n");
            choose = getch();
            switch (choose)
            {
            case '1':NView(p); break;
            case '2':DView(p); break;
            case '3':Interface(p); break;
            }
        }
    }
}
void DView(sqlite3* p)///添加信息
{
    TEACHER.ret = 0;
    char* mistake;
    TEACHER.ret = sqlite3_exec(p, "Drop view teacher_viers;", callback, 0, &mistake);
    if (TEACHER.ret != SQLITE_OK)
    {
        printf("\t\t删除失败！\n\a");
        fprintf(stderr, "\t\t失败原因：%s\n", mistake);
        sqlite3_free(mistake);
        getch();
    }
    else
    {
        printf("\t\t删除成功\n");
        getch();
    }
}
void NView(sqlite3* p)///添加信息
{
    char character[20];
    char sql[300];
    char* mistake;
    int choose;
    if (p == NULL)
    {
        fprintf(stderr, "未连接数据库\n");
        Sleep(1000);
    }
    else
    {
        while (1)
        {
            system("cls");
            initialize();
            TEACHER.ret = 0;
            fflush(stdin);
            printf("\t\t*****************************************\n");
            printf("\t\t*\t\t\t\t\t*\n");
            printf("\t\t*\t  请选择创建的关键词：    \t*\n");
            printf("\t\t*\t\t\t\t\t*\n");
            printf("\t\t*****************************************\n");
            printf("\t\t\t  **①- 编  号 -**\n");
            printf("\t\t\t  **②- 教工号 -**\n");
            printf("\t\t\t  **③- 姓  名 -**\n");
            printf("\t\t\t  **④- 性  别 -**\n");
            printf("\t\t\t  **⑤-出生年月-**\n");
            printf("\t\t\t  **⑥-家庭住址-**\n");
            printf("\t\t\t  **⑦- 返  回 -**\n");
            choose = getch();
            switch (choose)
            {
            case '1':strcpy(TEACHER.field, "id"); strcpy(character, "编号"); break;
            case '2':strcpy(TEACHER.field, "num"); strcpy(character, "教工号"); break;
            case '3':strcpy(TEACHER.field, "name"); strcpy(character, "姓名"); break;
            case '4':strcpy(TEACHER.field, "sex"); strcpy(character, "性别"); break;
            case '5':strcpy(TEACHER.field, "birthday"); strcpy(character, "出生年月"); break;
            case '6':strcpy(TEACHER.field, "address"); strcpy(character, "家庭住址"); break;
            case '7':View(p); break;
            }
            printf("\n\t\t请输入%s的条件:", character);
            scanf("%s", TEACHER.data);
            sprintf(sql, "create view teacher_viers as select * from teacher where %s = %s ;", TEACHER.field, TEACHER.data);
            TEACHER.ret = sqlite3_exec(p, sql, callback, 0, &mistake);
            if (TEACHER.ret != SQLITE_OK)
            {
                printf("\t\t新建失败！\n\a");
                fprintf(stderr, "\t\t失败原因：%s\n", mistake);
                sqlite3_free(mistake);
                getch();
                continue;
            }
            printf("\t\t新建成功\n");
            getch();
            break;
        }
    }
}

void hello(sqlite3* p)///欢迎界面
{
    TEACHER.ret = sqlite3_open("student.db", &p);
    if (TEACHER.ret != SQLITE_OK)
    {
        fprintf(stderr, "不能打开数据库:%s\n", sqlite3_errmsg(p));
        getch();
        exit(0);
    }
    printf("\t\t*****************************************\n");
    printf("\t\t*\t\t\t\t\t*\n");
    printf("\t\t*\t欢迎使用教师信息存储系统 \t*\n");
    printf("\t\t*\t\t\t\t\t*\n");
    printf("\t\t*****************************************\n");
    getch();
    Interface(p);
}


int main()///主函数
{
    sqlite3* p = NULL;
    hello(p);
}
