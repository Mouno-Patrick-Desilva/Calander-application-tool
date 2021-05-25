#include <stdio.h>
#include <stdlib.h>

int calendar();
int get_1st_weekday(int year){

  int d;
  d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
  return d;
}

void show_event()
{
    system("Color 3F") ;
    printf("\n\n\n");
    FILE *file2 = fopen("event.txt", "r");
    char files;
    do{
        files = getc(file2);
        printf("%c",files);
    }
    while(files!=EOF);
    printf("\n\n\n\n\n");
    fclose(file2);
    main();
}

int main()
{
    int x;
    system("Color 3F") ;
    printf("\n\n");
    printf("\n\t\t\t\t\t\t*******WELCOME*******");
    printf("\n\n\t\t\t\t\t\tEnter 1 to See Calendar.\n\t\t\t\t\t\tEnter 2 to Create Event.\n\t\t\t\t\t\tEnter 3 to See Event List.\n\t\t\t\t\t\tEnter 4 to Exit.\n\n\t\t\t\t\t\tEnter Your Choice:  ");

    scanf("%d", &x);
    if(x==1) calendar();
    else if(x==2) event();
    else if(x==3) show_event();
    else if(x==4) exit(0);


    return 0;
}

void event()
{
    system("Color 3F") ;
    FILE *file = fopen("event.txt", "a");
    int day, month, year;
    char event_name[20];
    printf("\t\t\t\t\t\tEnter day : ");
    scanf("%d",&day);
    if(day>0 && day<32)
    {
        printf("\t\t\t\t\t\tEnter month : ");
        scanf("%d",&month);
        if(month>0 && month<13)
        {
            printf("\t\t\t\t\t\tEnter year : ");
            scanf("%d",&year);
            getchar();
            printf("\t\t\t\t\t\tEnter event name \(Maximum 20 characters)\ :  ");
            fgets (event_name, 20, stdin);
            fprintf(file, "\t\t\t\t\t\t%d-%d-%d\t%s\n", day, month, year, event_name);
            fclose(file);
        }else{
      printf("\n \t\t\t\t\t\t\"Error! Please enter a valid number\" ");
    }
    }else{
      printf("\n \t\t\t\t\t\t\"Error! Please enter a valid number\" ");
    }
    main();
}

int calendar() {
    system("Color 3F") ;
    int year,month,day,daysInMonth,weekDay=0,startingDay;
    printf("\n\t\t\t\t\t\tEnter your desired year : ");
    scanf("%d", &year);
    char *months[ ]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int monthDay[ ]={31,28,31,30,31,30,31,31,30,31,30,31};

    if((year%4==0&&year%100!=0)|| year%400==0)
        monthDay[1]=29;

   startingDay=get_1st_weekday(year);

    for (month=0 ; month<12;month++) {

        daysInMonth=monthDay[month];
        printf("\n\n\t\t\t\t\t---------------%s----------------\n",months[month]);
        printf("\n\t\t\t\t\t  Sun  Mon  Tues  Wed Thurs Fri Sat\n");
        printf("\n\t\t\t\t\t");

        for(weekDay=0;weekDay<startingDay;weekDay++){
            printf("     ");
        }

        for(day=1;day<=daysInMonth;day++){
            printf("%5d",day);


            if(++weekDay>6) {
                printf("\n");
                printf("\t\t\t\t\t");

                weekDay=0;
            }
            startingDay=weekDay;
        }
    }
    main();
}
