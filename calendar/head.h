typedef struct dmy
{
    int ud,um,uy;
    char junk1,junk2;
    int yr1,m1,day;
}DMY;
int validity(int,int,int);
void calendar_month(int,int,int);
void calendar_year(int,int,int);
int* dayy(int,int,int);
void count_days(int,int);
void pn(int,int,int);
