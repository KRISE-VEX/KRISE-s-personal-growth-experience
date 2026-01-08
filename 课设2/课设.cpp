#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct inf 
{
    char snumber[10],title[100],fucre[1000];
    char tyear[10];char type[10];
};
void create();
void addinf();
void deleteinf();
void modfyinf();
void searchinf();
void sta();
bool pan();
void save(struct inf app[],char *filename,int cnt);
int toshu(struct inf infor);
int main()
{
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║              毕业设计题目信息管理系统                        ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");
    while(1)
    {
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    请选择你要进行的操作:                     ║\n");
    printf("║                                                              ║\n");
    printf("║              1. 创建题目信息                                 ║\n");
    printf("║              2. 增加题目信息                                 ║\n");
    printf("║              3. 删除题目信息                                 ║\n");
    printf("║              4. 修改题目信息                                 ║\n");
    printf("║              5. 查询                                         ║\n");
    printf("║              6. 统计                                         ║\n");
    printf("║              7. 退出                                         ║\n");
    printf("║                                                              ║\n");
    printf("║            (请输入要进行操作的编号)                          ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");
    printf("  请输入您的选择: ");
    int n;scanf("%d",&n);
    switch(n)
    {
        case 1:{
            printf("请输入题目信息:(包括：题目编号、题目名称、题目功能要求、出题年份、题目类型(设计类、论文类))\n例如:\n001\n基于JSP的超市管理系统的设计与实现\n主要功能包括，前台功能模块:(1)商品分类展示(2)购物车(3)提交订单,后台管理模块:(1)订单管理(2)用户管理,测试\n2017\n设计类\n(请按照样例输入)\n");
            create();
            printf("题目信息创建成功!\n");
            break;
        }
        case 2:{
            addinf();
            break;
        }
        case 3:{
            deleteinf();
            break;
        }
        case 4:{
            modfyinf();
            break;
        }
        case 5:{
            searchinf();
            break;
        }
        case 6:{
            sta();
            break;
        }
        case 7:{
            exit(0);
        }
        default:printf("输入信息不对!\n");
    }
    }
}

bool pan(struct inf app)
{

    int len = strlen(app.snumber);
    for(int i = 0;i<len;i++)
    {
        if(!(app.snumber[i]>='0'&&app.snumber[i]<='9'))
        return false;
    }
    return true;
}
bool pan1(struct inf app)
{

    int len = strlen(app.tyear);
    for(int i = 0;i<len;i++)
    {
        if(!(app.tyear[i]>='0'&&app.tyear[i]<='9'))
        return false;
    }
    return true;
}
void create()
{
    struct inf infor[100];
    int cnt = 0;
    if(cnt>100) 
    {
         printf("输入题目数量已满\n");
         return;
    }
    printf("请输入文件名称:\n");
    while(getchar()!='\n');
    char name[100];
    fgets(name,100,stdin);name[strlen(name)-1]='\0';
    FILE *fp1;
    fp1=fopen(name, "w+");//创建文件
    char c = 'y';
    while(c=='y')
    {
   	printf("请输入题目编号:\n");
    while (1) 
	{
    fgets(infor[cnt].snumber, 100, stdin);
    infor[cnt].snumber[strlen(infor[cnt].snumber)-1] = '\0';
    if (pan(infor[cnt])) break; // 有效则退出
    printf("错误：题目编号必须是纯数字（如001），请重新输入：");
	}
    printf("请输入题目名称:");
    fgets(infor[cnt].title, sizeof(infor[cnt].title), stdin);
    infor[cnt].title[strcspn(infor[cnt].title, "\n")] = '\0'; 
   	printf("请输入题目功能要求:");
    fgets(infor[cnt].fucre,sizeof(infor[cnt].fucre),stdin);
    infor[cnt].fucre[strlen(infor[cnt].fucre)-1]='\0';
   	printf("请输入出题年份:");
    while (1) 
	{
    fgets(infor[cnt].tyear, 10, stdin);
    infor[cnt].tyear[strlen(infor[cnt].tyear)-1] = '\0';
    if (pan1(infor[cnt])) break; // 有效则退出
    printf("错误：年份必须是数字（如2017），请重新输入:");
	}
   	printf("请输入题目类型(包括：设计类、论文类):"); 
    while(1)
    {
        fgets(infor[cnt].type, 10, stdin);
        infor[cnt].type[strlen(infor[cnt].type)-1] = '\0';
        if(strcmp(infor[cnt].type,"设计类")==0||strcmp(infor[cnt].type,"论文类")==0) break;
    }
    printf("是否要继续输入(y/n)?\n");
    scanf("%c", &c);
    while(getchar()!='\n');
    cnt++;
    }
    save(infor,name,cnt);
    fclose(fp1);
    return ;
}

void addinf()
{
    printf("请输入文件名称:\n");
    while(getchar()!='\n');
    char name[100];
    fgets(name,100,stdin);name[strlen(name)-1]='\0';
    FILE *fp1;
    fp1=fopen(name, "a+");
    if(fp1==NULL)
    {
        printf("文件不存在\n");
        return;
    }
    struct inf infor[100];
    int cnt = 0;
    char c='y';
    while(c=='y')
    {
   	printf("请输入题目编号:\n");
    while (1) 
	{
    fgets(infor[cnt].snumber, 100, stdin);
    infor[cnt].snumber[strlen(infor[cnt].snumber)-1] = '\0';
    if (pan(infor[cnt])) break; // 有效则退出
    printf("错误：题目编号必须是纯数字（如001），请重新输入：");
	}
    printf("请输入题目名称:");
    fgets(infor[cnt].title, sizeof(infor[cnt].title), stdin);
    infor[cnt].title[strcspn(infor[cnt].title, "\n")] = '\0'; 
   	printf("请输入题目功能要求:");
    fgets(infor[cnt].fucre,sizeof(infor[cnt].fucre),stdin);
    infor[cnt].fucre[strlen(infor[cnt].fucre)-1]='\0';
   	printf("请输入出题年份:");
    while (1) 
	{
    fgets(infor[cnt].tyear, 10, stdin);
    infor[cnt].tyear[strlen(infor[cnt].tyear)-1] = '\0';
    if (pan1(infor[cnt])) break; // 有效则退出
    printf("错误：年份必须是数字（如2017），请重新输入:");
	}
   	printf("请输入题目类型(包括：设计类、论文类):"); 
    while(1)
    {
        fgets(infor[cnt].type, 10, stdin);
        infor[cnt].type[strlen(infor[cnt].type)-1] = '\0';
        if(strcmp(infor[cnt].type,"设计类")==0||strcmp(infor[cnt].type,"论文类")==0) break;
        printf("错误：请输入正确的项目类型:"); 
    }
    printf("是否要继续输入(y/n)?\n");
    scanf("%c", &c);
    while(getchar()!='\n');
    cnt++;
    }
    for(int i = 0;i<cnt;i++)
    fprintf(fp1,"%s %s %s %s %s\n",infor[i].snumber,infor[i].title,infor[i].fucre,infor[i].tyear,infor[i].type);
    fclose(fp1);
    
    printf("题目信息增加成功!\n");
}

void deleteinf()
{
    while(getchar()!='\n');   
    printf("请输入文件名称:\n");
    char name[100];
    fgets(name,sizeof(name),stdin);name[strlen(name)-1]='\0';
    FILE *fp1;
    fp1=fopen(name,"r+");
    if(fp1==NULL)
    {
        printf("文件不存在\n");
        return;
    }
    struct inf infor[100];
    int cnt = 0;
    while(fscanf(fp1,"%s %s %s %s %s",infor[cnt].snumber,infor[cnt].title,infor[cnt].fucre,infor[cnt].tyear,infor[cnt].type)!=EOF) cnt++;
    int found = 0;
    for(int i = 0; i<cnt; i++) {
        if(toshu(infor[i])<2023) {
            printf("%s %s %s %s %s\n",infor[i].snumber,infor[i].title,infor[i].fucre,infor[i].tyear,infor[i].type);
            found = 1;
        }
    }
    if(found!=0) printf("以上为过期题目(超过3年)：\n");
    if(!found) {
        printf("没有过期题目\n");
        return;
    }
    printf("是否要删除过期题目？(y/n): ");
    char confirm;
    scanf(" %c", &confirm);
    if(confirm == 'y') 
    {
        printf("请输入删除方式(输入操作编号):\n1.全删\n2.单独删\n");
        int n;scanf("%d",&n);
        switch(n)
        {
        case 1:{
        for(int i = 0; i<cnt; i++) {
            if(toshu(infor[i])<2023) {
                for(int j = i; j<cnt-1; j++) {
                    infor[j] = infor[j+1];
                }
                cnt--;
                i--; // 避免 2022 2022
            }
        }
        for(int i = 0; i<cnt; i++)
        printf("题目信息删除成功!\n");
        break;
    }
    case 2:{
        int found = -1;
        printf("请输入要删除的题目编号:");
        char num[20];scanf("%s",num);
            for(int i = 0; i<cnt; i++) 
            {
                if(strcmp(infor[i].snumber,num)==0&&toshu(infor[i])<2023) {
                    found = i;
                    for(int j = found; j<cnt-1; j++)
                    infor[j] = infor[j+1];
                    cnt--;
                }
            }
           if(found!=-1) 
            printf("题目信息删除成功!\n");
           else printf("删除失败,请检查输入的题目编号是否正确!\n");
           break;
        }
        default:{
            printf("输入错误!\n");
            }
        }
    } else if(confirm=='n'){
        printf("取消删除操作\n");
    }
    else {
        printf("输入错误!\n");  
    }
    fclose(fp1);
    fp1 = fopen(name,"w");
    for(int i = 0;i<cnt;i++)
    fprintf(fp1,"%s %s %s %s %s\n",infor[i].snumber,infor[i].title,infor[i].fucre,infor[i].tyear,infor[i].type);
    fclose(fp1);
}

void modfyinf()
{
    while(getchar()!='\n');
    printf("请输入文件名称\n");
    char filename[20];fgets(filename,20,stdin);
    filename[strlen(filename)-1]='\0';
    FILE *fp1;
    fp1=fopen(filename,"r+");
    int cnt = 0;
    struct inf infor[100];
    while(fscanf(fp1,"%s %s %s %s %s",infor[cnt].snumber,infor[cnt].title,infor[cnt].fucre,infor[cnt].tyear,infor[cnt].type)!=EOF) cnt++;
    printf("请输入要修改的编号:\n");
    char number[10];scanf("%s",number);
    int found = -1;
    for(int i = 0; i<cnt; i++)
    {
        if(strcmp(infor[i].snumber,number)==0)
        {
            found = i;
            printf("找到题目信息：\n");
            printf("%s %s %s %s %s\n",infor[i].snumber,infor[i].title,infor[i].fucre,infor[i].tyear,infor[i].type);
            printf("请输入要修改的题目信息(仅输入修改操作的编号，如：你要修改 题目编号，仅输入：“1”):\n");
            printf("1.题目编号\n");
            printf("2.题目名称\n");
            printf("3.题目功能要求\n");
            printf("4.出题年份\n");
            printf("5.题目类型\n");
            int n;scanf("%d",&n);
            switch(n)
            {
                case 1:{
                    printf("请输入新的题目编号：");
                    scanf("%s",infor[i].snumber);
                    break;
                }
                case 2:{
                    printf("请输入新的题目名称：");
                    scanf("%s",infor[i].title);
                    break;
                }
                case 3:{
                    printf("请输入新的题目功能要求：");
                    scanf("%s",infor[i].fucre);
                    break;
                }
                case 4:{
                    printf("请输入新的题目年份：");
                    scanf("%d",&infor[i].tyear);
                    break;
                }
                case 5:{
                    printf("请输入新的题目类型：");
                    scanf("%s",infor[i].type);
                    break;
                }
                default:printf("输入信息不对!\n");
            }
            printf("修改成功！\n");
        }
    }
    if(found==-1) printf("没有找到该题目!\n");
    fclose(fp1);
    fp1 = fopen(filename,"w");
    for(int i = 0;i<cnt;i++)
    fprintf(fp1,"%s %s %s %s %s\n",infor[i].snumber,infor[i].title,infor[i].fucre,infor[i].tyear,infor[i].type);
    fclose(fp1);
 
}
void searchinf()
{
    struct inf infor[100];
    int cnt = 0;
    printf("请输入文件名称：\n");
    while(getchar() != '\n');
    char name[100];fgets(name,sizeof(name),stdin); name[strlen(name)-1] = '\0';
    FILE *fp1 = fopen(name,"r");
    if(fp1==NULL) 
    {
    printf("没有找到该文件!\n");
    return;
    }
    while(fscanf(fp1,"%s %s %s %s %s",infor[cnt].snumber,infor[cnt].title,infor[cnt].fucre,infor[cnt].tyear,infor[cnt].type)!=EOF) cnt++;
    while(1)
    {
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    题目信息查询系统                          ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");
        printf("   请选择查询方式：\n");
        printf("   1. 按题目编号查询\n");
        printf("   2. 按题目关键字查询\n");
        printf("   3. 按题目年份查询\n");
        printf("   4. 返回主菜单\n");
        printf("   (请输入要进行查询方式的编号) ");
    int n;
    int found=-1;
    scanf("%d",&n);
    switch(n)
    {
        case 1:{ 
            printf("请输入题目编号:\n");
             found = -1;
            char num[20];scanf("%s",num);
            for(int i = 0;i<cnt;i++)
            {
                
                if(strstr(infor[i].snumber,num)!=NULL) 
                {
                found = i;
                printf("%s %s %s %s %s\n",infor[i].snumber,infor[i].title,infor[i].fucre,infor[i].tyear,infor[i].type);
                }
            }
            if(found == -1) printf("没找到\n");
            break;
        }
        case 2:{ 
            printf("请输入关键字\n");
            found = -1;
            char title[100];scanf("%s",title); 
            for(int i = 0;i<cnt;i++)
            {
                if(strstr(infor[i].title,title)!=NULL||strstr(infor[i].fucre,title)!=NULL) 
                {
                    printf("%s %s %s %s %s\n",infor[i].snumber,infor[i].title,infor[i].fucre,infor[i].tyear,infor[i].type);
                    found = i;
                }
            }
            if(found == -1) printf("没找到\n");
            break;
        }
        case 3:{ 
            printf("请输入年份:");
            int year;scanf("%d",&year);
            found = -1;
            for(int i = 0;i<cnt;i++)
            {
                if(toshu(infor[i])== year)
                {
                   printf("%s %s %s %s %s\n",infor[i].snumber,infor[i].title,infor[i].fucre,infor[i].tyear,infor[i].type); 
                   found = i;
                }
            }
            if(found == -1) printf("没找到\n");
            break; 
        }
        case 4:{
            return; 
        }
        default:printf("输入信息不对!\n");
    }
    printf("请问是否要继续查询?(y/n)\n");
    while(getchar() != '\n');
    char c;scanf("%c",&c);
    if(c == 'n') break;
    }
}
void sta()
{
    printf("请输入文件名称\n");
    while(getchar() != '\n');
    char name[100];fgets(name,100,stdin);
    name[strlen(name)-1] = '\0';
    FILE *fp = fopen(name,"r");
    if(fp == NULL)
    {
        printf("打开文件失败\n");
        return;
    }
    struct inf infor[100];
    int cnt = 0;
     while(fscanf(fp,"%s %s %s %s %s",infor[cnt].snumber,infor[cnt].title,infor[cnt].fucre,infor[cnt].tyear,infor[cnt].type)!=EOF) cnt++;
    int she = 0,lun = 0;
    for(int i = 0;i<cnt;i++)
    {
        if(strcmp(infor[i].type,"设计类")==0) she++;
        if(strcmp(infor[i].type,"论文类")==0) lun++;
    }
    printf("设计类题目有%d个\n",she);
    printf("论文类题目有%d个\n",lun);
    fclose(fp);
}
void save(struct inf app[],char *name,int cnt)
{
    FILE *fp = fopen(name,"w");
    for(int i = 0;i<cnt;i++)
    {
        fprintf(fp,"%s %s %s %s %s\n",app[i].snumber,app[i].title,app[i].fucre,app[i].tyear,app[i].type);
    }
    fclose(fp);
}
int toshu(struct inf infor)
{
	int sum = 0;
	int len = strlen(infor.tyear);
	for(int i = len-1;i>=0;i--)
	{
		sum= sum*10+(infor.tyear[i]-'0');
	}
	return sum;
}
/*
实验19毕业设计题目管理系统
毕业设计题目信息包括：题目编号、题目名称、题目功能要求、出题年份、题目类型（设
计类、论文类)
(例如：001、基于JSP的超市管理系统的设计与实现、主要功能包括，前台功能模块：(1)
商品分类展示(2)购物车(3)提交订单，后台管理模块：(1)订单管理(2)用户管理，测试、
2017、设计类)等。
系统的主要功能包括：
1.创建题目信息，根据提示输入各项信息。
2.增加题目信息，在原有题目信息基础上增加新的题目信息，并提示用户选择是否继续进
行增加操作。
3.删除题目信息，根据出题年份，检测过期题目（超过3年）删除设计题目信息，删除之
前显示题目详细信息，并提示用户选择是否继续进行删除操作。
4.修改题目信息，提示用户输入要进行修改操作的题目编号，如果有该信息存在，则将提
示用户输入该编号对应的要修改的选项，并提示用户选择是否继续进行修改操作。
5.按不同条件对题目信息进行查询操作，输出满足条件的题目信息。
(1)按题目编号查询。
(2)按题目名称查询。
(3)按出题年份查询。
6.统计各类型题目的数量。*/
