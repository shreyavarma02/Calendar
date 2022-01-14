#include<stdio.h>
#include "head.h"

//to check if the date entered by the user is valid or not
int validity(int d,int m,int y)
{
    printf("\n");
    int max;
    int flag=0;
    int check=0;
    //to check if it's a leap year
    if (( y%400 == 0)|| (( y%4 == 0 ) &&( y%100 != 0)))
        flag=1;
    else
        flag=0;
    //find maximum number of days in the respective month
    if(m==4 || m==6 || m==9 || m==11)
        max=30;
    else if((flag==0) && (m==2))
        max=28;
    else if((flag==1) && (m==2))
        max=29;
    else
        max=31;
    if(m<1 || m>12)
        printf("Date is invalid \n");
    else if(d>max)
        printf("Date is invalid\n");
    else
    {
        printf("Date is valid\n");
        check=1;
    }
    return check;
}


//display calendar month
void calendar_month(int d,int m,int y)
{
    char mon[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int mly[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int mnly[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int a=0; //flag variable
    int num=0;
    int sum=0;
    printf("\n\t\t\t%s\n",mon[m-1]);
    printf("--------------------------------------------------");
    printf("\nS\tM\tT\tW\tT\tF\tS\n");
    printf("--------------------------------------------------\n");
    int *res1=dayy(d,m,y);
    int j=res1[1];// j stores the first day of the month
    int k=0;
    //to align the first day of the month
    if(j==0)//if first day of the month is saturday
    {
        for(int i=0;i<6;i++)
        {
            printf("\t");
        }
    }
    else
    {
        while((k<(j-1)))
        {
            printf("\t");
            k++;
        }
    }

    //check if y is leap year
    if (( y%400 == 0)|| (( y%4 == 0 ) &&( y%100 != 0)))
    {
        a=1;
    }
    //find the number of days in the month(num)
    if(a==1)
    {
        num=mly[m-1];
    }
    else
    {
        num=mnly[m-1];
    }
    for(int i=1;i<=num;i++)
    {
        printf("%d",i);
        printf("\t");
        if(j%7==0) //to check if day is Saturday to go to new line
        {
            printf("\n");
        }
        j++;

    }
    printf("\n--------------------------------------------------\n");


}
//to display the entire calendar year
void calendar_year(int d,int m,int y)
{
    int m1=1;
    while(m1<=12)
    {
        calendar_month(d,m1,y);
        m1++;
    }
}
//find the day
int* dayy(int d,int m,int y)
{
    int ly=0;
    int nly=0;
    int count=0;//range of years between 2000 and user given year
    int day;
    int yr1;
    int m1;
    int mly[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int mnly[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int sum=0;
    int ret_arr[3]={0,0,0};
    int *p=ret_arr;
    //to calculate first day of the year(yr1)
    if(y>2000)
    {
        count=y-2000-1;//both years are exclusive
        for(int i=2001;i<y;i++)
        {
            if (( i%400 == 0)|| (( i%4 == 0 ) &&( i%100 != 0)))
            {
                ly++;
            }
        }
        nly=count-ly;
        yr1=((2*(ly+1))+nly)%7;
    }
    else if(y<2000)
    {
        count=2000-y;//given year is inclusive but 2000 is exclusive
        for(int i=y;i<2000;i++)
        {
            if (( i%400 == 0)|| (( i%4 == 0 ) &&( i%100 != 0)))
            {
                ly++;
            }
        }
        nly=count-ly;
        yr1=7-(((2*ly)+nly)%7);
    }
    else
    {
        yr1=0; //First day of the year 2000 is Saturday
    }
    //to calculate the first day of the month(m1)
    if (( y%400 == 0)|| (( y%4 == 0 ) &&( y%100 != 0))) //to check if user given year is a leap year
    {
        for(int j=0;j<(m-1);j++)
        {
            sum+=mly[j];
        }
        m1=((sum%7)+yr1)%7;
    }
    //not a leap year
    else
    {
        for(int j=0;j<(m-1);j++)
        {
            sum+=mnly[j];
        }
        m1=((sum%7)+yr1)%7;
    }
    //to calculate the day
    day=(m1+(d-1)%7)%7;
    p[0]=day;
    p[1]=m1;
    p[2]=yr1;
    return p;
}

//calculate number of days in the given year and month
void count_days(int m,int y)
{
    int a=0;//flag variable
    char mon[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    // to check if given year is leap year
    if (( y%400 == 0)|| (( y%4 == 0 ) &&( y%100 != 0)))
    {
        a=1;
    }
    if(a==1)
    {
        printf("\n%d has 366 days",y);
    }
    else
    {
        printf("\n%d has 365 days",y);
    }
    if(a==1&&m==2)
    {
        printf("\nFebruary has 29 days");
    }
    else if(a==0 && m==2)
    {
        printf("\nFebruary has 28 days");
    }
    else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
    {
        printf("\n%s has 31 days",mon[m-1]);
    }
    else
    {
        printf("\n%s has 30 days",mon[m-1]);
    }
    printf("\n");
}

//to display previous or next day and date
void pn(int d, int m, int y)
{
    int c=0; //flag variable
    int ud1=d;
    int um1=m;
    int uy1=y;
    int max;
    char day[7][20]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
    int mly[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int mnly[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int *res=dayy(ud1,um1,uy1);
    int abc=res[0];
    int xyz,pqr;
    char ch;
    if (( y%400 == 0)|| (( y%4 == 0 ) &&( y%100 != 0)))
    {
        c=1;
    }
    else
    {
       c=0;
    }
    if(m==4 || m==6 || m==9 || m==11)
    {
        max=30;
    }
    else if((c==0) && (m==2))
    {
        max=28;
    }
    else if((c==1) && (m==2))
    {
        max=29;
    }
    else
    {
        max=31;
    }
    fflush(stdin);
    printf("\nEnter p(previous),n(next) or q(quit):");
    scanf("%c",&ch);
    while(ch!='q')
    {
        if(ch=='n')
        {
            xyz=(abc+1)%7;
            printf("\nThe next day is %s\n",day[xyz]);
            if(d==max && m!=12)
            {
                d=1;
                m=m+1;
                printf("Next date is: %d/%d/%d",d,m,y);
            }
            else if(d==max && m==12)
            {
                d=1;
                m=1;
                y=y+1;
                printf("Next date is: %d/%d/%d",d,m,y);
            }
            else
            {
                d=d+1;
                printf("Next date is: %d/%d/%d",d,m,y);
            }
            abc=(abc+1)%7;
            printf("\n");
        }
        else if(ch=='p')
        {
            pqr=(abc-1+7)%7;
            printf("\nThe previous day is %s\n",day[pqr]);

            if (( y%400 == 0)|| (( y%4 == 0 ) &&( y%100 != 0)))//leap year
            {
                c=1;
            }
            else
                c=0;

            if(d==1&&m==1)
            {
                y=y-1;
                m=12;
                d=31;
                printf("Previous date is: %d/%d/%d",d,m,y);
            }
            else if(d==1)
            {
                if(c==1)
                {
                    d=mly[m-2];
                    m=m-1;
                    y=y;
                    printf("Previous date is: %d/%d/%d",d,m,y);
                }
                else
                {
                    d=mnly[m-2];
                    m=m-1;
                    y=y;
                    printf("Previous date is: %d/%d/%d",d,m,y);
                }
            }
            else
            {
                d=d-1;
                m=m;
                y=y;
                printf("Previous date is: %d/%d/%d",d,m,y);

            }
             abc=(abc-1+7)%7;
             printf("\n");
        }
        fflush(stdin);
        printf("\nEnter p(previous),n(next) or q(quit):");
        scanf("%c",&ch);
    }
}
