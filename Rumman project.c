#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

int head()
{
    printf("\n\t\t\t================================================================\n");
    printf("\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("\t\t\t>>>>>>>>>WELLCOME TO NATIONAL ELECTION VOTING SYSTEM<<<<<<<<<<<<\n");
    printf("\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("\t\t\t===============Choose Your Favorite Party For Vote==============");
}

int main()
{
    system("color 1f");
    head();
    home();
    return 0;
}
struct nid
{

    char id_num[100];

};
struct nid n_id;

int store()
{
    FILE *fptr;
    fptr=fopen("nid data.txt","a");
    if(fptr==NULL)
    {
        printf("error");
        exit(1);
    }
    printf("\n\nEnter NID Number To Save : ");
    scanf("%s",&n_id.id_num);
    fwrite(&n_id,sizeof(n_id),1, fptr);
    printf("NID Number Successfully Saved");
    Sleep(1000);
    fclose(fptr);
    system("cls");
    head();
    int a;
    printf("\n\n\n\t\t\t##ENTER[1]TO SAVE ANOTHER NID NUMBER");
    printf("\n\t\t\t##ENTER[2]TO BACK HOME PAGE");
    printf("\n\t\t\t##ENTER[3]TO EXIT\n");
    printf("\n\t\t\t##SELECT A OPTION:>:");
    fflush(stdin);
    while(scanf("%d",&a))
    {
        if(a==1 || a==2 || a==3)
        {
         if(a==1)
         {
             head();
             system("cls");
             head();
             store();
             break;
         }
         if(a==2)
         {
             head();
             system("cls");
             head();
             home();
             break;
         }
         if(a==3)
         {
             ext();
             Sleep(1500);
             break;
         }

        }
        printf("  INVALID INPUT READ OPTION CAREFULLY: ");
        fflush(stdin);
    }

    return 0;
}

int search()
{
FILE *fptr2;
fptr2=fopen("nid data.txt","r");
if(fptr2==NULL)
    {
        printf("error");
        exit(1);
    }
char id[20];
printf("\n\nEnter NID number for Matching:\n\n");
scanf("%s",&id);
while(fread(&n_id, sizeof(n_id), 1,fptr2))
{
    if(strcmp(id,n_id.id_num)==0)
    {
        printf("NID Found\n\n");
        delet();
        printf("NID Matching Please wait");
        Sleep(1000);
         printf("~~~~~~~~~");
        Sleep(500);
        printf("~~~~~~~~~~");
        Sleep(500);
        printf("~~~~~~~~~");
        Sleep(500);
        system("cls");
        head();
        save();
        break;
    }
}
if(strcmp(id,n_id.id_num)!=0)

{
    printf("Invalid,NID not found\n");
    search();
}
return 0;
}
int save()
 {
   int v;
   char c0[20]={"NA VOTE"};
   char c1[20]={"BNP"};
   char c2[20]={"AWAMILEAGUE"};
   char c3[20]={"JATIYA PARTY"};
   char c4[20]={"JAMAT ISLAMI PARTY"};
   printf("\n\n\t\t\t::>>CHOOSE A OPTION FOR WHICH YOU WANT TO VOTE<<::");
   Sleep(500);
   printf("\n\n\n\t\t\t\tpress [0] for NA VOTE\n");
   Sleep(500);
   printf("\t\t\t\tPress [1] to vote BNP \n");
   Sleep(500);
   printf("\t\t\t\tPress [2] to vote AWAMILEAGUE \n");
   Sleep(500);
   printf("\t\t\t\tpress [3] to vote JATIYA PARTY \n");
   Sleep(500);
   printf("\t\t\t\tpress [4] to vote JAMAT ISLAMI PARTY \n");
   Sleep(500);
   printf("CHOOSE A OPTION=|>  ");
   while(scanf("%d",&v))
   {
       if(v==0 || v==1 || v==2 || v==3 || v==4)
       {
           if(v==0)
           {
             FILE *fp;
             fp=fopen("Na vote.txt","a");
             fwrite(&c0,sizeof(c0), 1, fp);
             printf("\nYOU SUCCESSFULLY VOTED 'NA VOTE'\n\n");
             fclose(fp);
             break;
           }
           if(v==1)
           {
               FILE *fp;
             fp=fopen("BNP vote.txt","a");
             fwrite(&c1,sizeof(c1), 1, fp);
             printf("\nYOU SUCCESSFULLY VOTED BNP\n\n");
             fclose(fp);
             break;
           }
           if(v==2)
           {
               FILE *fp;
             fp=fopen("awm vote.txt","a");
            fwrite(&c2,sizeof(c2), 1, fp);
            printf("\nYOU SUCCESSFULLY VOTED AWAMILEAGUE\n\n");
            fclose(fp);
            break;
           }
           if(v==3)
           {
               FILE *fp;
             fp=fopen("jtya party vote.txt","a");
             fwrite(&c3,sizeof(c3), 1, fp);
             printf("\nYOU SUCCESSFULLY VOTED JATIYA PARTY\n\n");
             fclose(fp);
             break;
           }
           if(v==4)
           {
               FILE *fp;
             fp=fopen("jamat vote.txt","a");
             fwrite(&c4,sizeof(c4), 1, fp);
             printf("\nYOU SUCCESSFULLY VOTED JAMAT ISLAMI PARTY\n\n");
             fclose(fp);
             break;
           }
       }
       else
       printf("\nINVALID INPUT Press 1 OR 2 OR 3 OR 4\n");
       fflush(stdin);

   }

return 0;
 }

 int count()
 {
     int a=0;
     char c0[20];
     FILE *count;
     count=fopen("Na vote.txt","r");
     while (fread(&c0,sizeof(c0), 1, count))
     {
     a=a+1;
     }
     Sleep(500);
     printf("\t\t\tTotal No vote vote is :%d\n\n",a);


     fclose(count);
     return 0;

 }
 int count1()
 {

     int b=0;
     char c1[20];
     FILE *count1;
     count1=fopen("BNP vote.txt","r");
     while (fread(&c1,sizeof(c1), 1, count1))
     {
     b=b+1;
     }
     Sleep(500);
     printf("\t\t\tTotal BNP vote is :%d\n\n",b);

     fclose(count1);
 }
 int count2()
 {

     int c=0;
     char c2[20];
     FILE *count2;
     count2=fopen("awm vote.txt","r");
     while (fread(&c2,sizeof(c2), 1, count2))
     {
     c=c+1;
     }
     Sleep(500);
     printf("\t\t\tTotal Awamilegue vote is :%d\n\n",c);

     fclose(count2);
 }
 int count3()
 {

     int d=0;
     char c3[20];
     FILE *count3;
     count3=fopen("jtya party vote.txt","r");
     while (fread(&c3,sizeof(c3), 1, count3))
     {
     d=d+1;
     }
     Sleep(500);
     printf("\t\t\tTotal Jatiya party vote is :%d\n\n",d);

     fclose(count3);
 }
 int count4()
 {

     int e=0;
     char c4[20];
     FILE *count4;
     count4=fopen("jamat vote.txt","r");
     while (fread(&c4,sizeof(c4), 1, count4))
     {
     e=e+1;
     }
     Sleep(500);
     printf("\t\t\tTotal Jamat islami party vote is :%d\n\n",e);

     fclose(count4);

 }
int delet()
{

    FILE *fp1,*fp2;
    struct nid n_id;
    int found=0, count=0;
    char nm[30];
    fp1=fopen("nid data.txt","r");
    fp2=fopen("Temp.txt","w");
    fflush(stdin);
    printf("Enter NID number again for Cornfirm:\n");
    scanf("%s",&nm);
    while(1)
    {
        fread(&n_id, sizeof(n_id), 1, fp1);
        if(feof(fp1))
        {
            break;
        }
        if(strcmp(nm,n_id.id_num)==0)
        {
            found=1;
        }
        else
        {
            fwrite(&n_id, sizeof(n_id), 1, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        printf("Sorry, NID not matching\n\n");
        delet();
    }
    else
    {
        fp1=fopen("nid data.txt","w");
        fp2=fopen("Temp.txt","r");
        while(1)
        {
            fread(&n_id,sizeof(n_id), 1, fp2);
            if(feof(fp2))
            {
                break;
            }
            fwrite(&n_id, sizeof(n_id), 1, fp1);
        }
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
int home()
{
    int f;
    printf("\n\n\n\t\t\t\t=>1.ADMIN PANEL");
    printf("\n\t\t\t\t=>2.FOR VOTERS");
    printf("\n\t\t\t\t=>3.SEE TOTAL COUNT OF VOTES");
    printf("\n\t\t\t\t=>4.EXIT");
    printf("\n\nChoose Your Option: ");
    while(scanf("%d",&f))

    {
        if(f==1 || f==2 || f==3 || f==4)
        {
            if(f==1)
            {
                A_pass_c();
                head();
                system("cls");
                head();
               break;
            }
            if(f==2)
            {
                head();
             system("cls");
             head();
              search();
              opt();
              break;
            }
            if(f==3)
            {
                system("cls");
                head();
                printf("\n\n\t\t\t====TOTAL COUNT OF VOTES====\n\n");
               count();
               count1();
               count2();
               count3();
               count4();
               opt();
               break;
            }
            if(f==4)
            {
                system("cls");
                head();
                ext();
                Sleep(1500);
            }
        }
        else
        {
            printf("invalid input");
        }
        }
    return 0;
}
int opt()
{
    int o;
    printf("\n##press 1 to go home");
    printf("\n##press 2 to exit");
    printf("\n\nChoose Your Option: ");
    while(scanf("%d",&o))
    {
        if(o==1 || o==2)
        {
            if(o==1)
            {
                head();
                system("cls");
                head();
               home();
               break;
            }
            if(o==2)
            {
                system("cls");
                head();
              ext();
              Sleep(1500);
              break;
            }
        }
        else
        {
            printf("invalid input");
        }
    }
    return 0;
}

int ext()
{
    int et;
    printf("\n  ##ENTER[1]TO CANCEL EXIT\n");
    printf("  ##ENTER[2]TO MAKE SURE EXIT\n");
    printf("\n\nChoose Your Option: ");
    fflush(stdin);
    while(scanf("%d",&et))
    {
        if(et==1 || et==2)
        {
           if(et==1)
           {
               system("cls");
               main();
               break;
           }
           if(et==2)
           {
               printf("\n  {THANKS}\n");
               printf("\n  {PRESS ANY KEY TO EXIT SUCCESS}\n");
               exit(EXIT_SUCCESS);
               Sleep(1500);
               break;
           }
        }
        printf("  INVALID INPUT READ OPTION CAREFULLY: ");
        fflush(stdin);
    }
    return 0;
}

int A_pass_c()
{
    char pasword[10],usrname[10], ch;
    char chek[10]={'a','d','m','i','n','1','2','3'};

    int i,valid=0;
    fflush(stdin);
    printf("\n\t\t  Enter Admin Password : ");

    for(i=0;i<8;i++)
    {
     ch = getch();
     pasword[i] = ch;
     ch = '*' ;
     printf("%c",ch);
   }
   for(i=0;i<8;i++)
   {
     if(pasword[i]==chek[i])
     {
      valid=valid+1;
     }
   }
    if(valid==8)
    {
        Sleep(500);
        printf("\n\n\t\t\t\tLogging In\n\n");
        Sleep(500);
        printf("\t\t\t~~~~~~~~~");
        Sleep(500);
        printf("~~~~~~~~~~");
        Sleep(500);
        printf("~~~~~~~~~");
        Sleep(500);
        printf("\n\nSuccessfully Logged In");
        Sleep(1000);
        system("cls");
        head();
     store();
    }
    else
    {
      printf("\n\t\t  !!!Wrong Password Try Again!!!\n");
      A_pass_c();
    }

    return 0;
}
