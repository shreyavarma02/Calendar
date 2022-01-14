#include<stdio.h>
#include "head.h"
int main()
{
    char opt;
    DMY s;
    //input date
    printf("Enter the date(dd-mm-yyyy or dd/mm/yyyy): ");
    scanf("%d%c%d%c%d",&s.ud,&s.junk1,&s.um,&s.junk2,&s.uy);
    int result=validity(s.ud,s.um,s.uy);
    //input another date if above date is invalid(result=0)
    while(result==0)
    {
        printf("Enter the date(dd-mm-yyyy or dd/mm/yyyy): ");
        scanf("%d%c%d%c%d",&s.ud,&s.junk1,&s.um,&s.junk2,&s.uy);
        result=validity(s.ud,s.um,s.uy);
    }
    fflush(stdin);
    printf("Do you want to display the entire calendar year(y) or calendar month(m): ");
    scanf("%c",&opt);
    if(opt=='y')
    {
        //displaying the entire calendar year
        calendar_year(s.ud,s.um,s.uy);
    }
    else
    {
        //displaying calendar for user given month
        calendar_month(s.ud,s.um,s.uy);
    }
    //displaying day
    int *res=dayy(s.ud,s.um,s.uy); //res[0] stores the day and res[1] stores the first day of the month
    int a=res[0];
    printf("\n");
    switch(a)
    {
        case 0:printf("The day is Saturday");
               break;
        case 1:printf("The day is Sunday");
              break;
        case 2:printf("The day is Monday");
            break;
        case 3:printf("The day is Tuesday");
            break;
        case 4:printf("The day is Wednesday");
            break;
        case 5:printf("The day is Thursday");
            break;
        case 6:printf("The day is Friday");
            break;
        default: printf("Something went wrong");
    }
    printf("\n");
    count_days(s.um,s.uy);
    pn(s.ud,s.um,s.uy);

    return 0;
}
