#include  <iostream>
#include  <cstdlib>
#include  <iomanip>
#include  <cmath>
#include  <string>

using  namespace  std;

int main()
{
char date[20];
cout<<"Enter the date in format DD.MM.YYYY: ";
cin>>date;

int day = 0;
int month = 0;
int year = 0;

int counter = 0;

int dotCheck = 0;

while(date[counter] != '\0')
    {
        counter++;//counter now holds the length of the input
        if (date[counter] == '.')dotCheck++;
    }

if(dotCheck!=2)
{
    cout<<"Invalid date! Please correct your input"<<endl<<endl<<endl<<endl<<endl;;
    return main();
}

int dayCheck = 0;

while(date[dayCheck]!='.')
{
    dayCheck++;
}


//dayCheck holds the number of digits the day has


//the following if-checks consider the input of a single-digit day (i.e., 5) or double-digit day (i.e., 05, 17, etc.)
if(dayCheck == 1)
{
    day = date[0] - '0';
}

else if(dayCheck == 2)
{
    day = ((date[0] - '0')*10) + (date[1] - '0');
}




int dotCounter = 0;//counts how many dots have been encountered

//we use the following loop to find the numbers between the two dots, in our case the month, again checking if it is a single- or double-digit



while(dotCounter!=2)
{
    for(int i=0; i<counter; i++)
    {
        if(date[i]=='.')
        {
            dotCounter++;
            if(date[i+2]=='.')
            {
                month = date[i+1] - '0';
            }

            else if(date[i+3]=='.')
            {
                month = ((date[i+1] - '0')*10) + (date[i+2] - '0');
            }
        }
    }
}



int afterSecondDot = 0;//this integer will let us know when we have reached the second dot



for(int j=0;j<counter;j++)
{

        if(date[j]=='.')
        {
            afterSecondDot++;
        }

//now, once we have reached the second dot, we will check for the terminating null, considering the year contains from one to four-digits
        if(date[j]=='.' && afterSecondDot==2)
        {
            int yearArray[20];//our yearArray will hold only the digits of the year
            int yearCounter = 0;//this will hold the length of the year
            int tempJ = j + 1;//the dot is at position 'j'
            while(date[tempJ]!='\0')
            {
                yearArray[yearCounter] = (date[tempJ] - '0');
                year = year*10 + yearArray[yearCounter];
                yearCounter++;
                tempJ++;
            }
        }
}




bool highYear = 0;

bool correctInput = 1;//this will let us know if the input was correct

if(year%4==0 &&  year%100!=0)highYear = 1;
if(year%400==0)highYear = 1;

if(day>31 || day<1 || month>12 || month<1 || year<1)correctInput=0;

if((month==2 && day>28 && highYear==0) || (month==2 && highYear == 1 && day>29) )correctInput=0;

if(correctInput==0)
{
    cout<<"Invalid date! Please correct your input"<<endl<<endl<<endl<<endl<<endl;;
    return main();
}

else{

long long int daysPassed = 0;

cout<<"Between 1.1.1 and "<<day<<"."<<month<<"."<<year<<" ";

int tempYear = year;//just so we don't modify our year

for(;tempYear>1;tempYear--)
{
    if(tempYear%4==0 && tempYear%100!=0)daysPassed = daysPassed + 366;
    else if(tempYear%400==0)daysPassed = daysPassed + 366;
    else daysPassed = daysPassed + 365;
}

if(month<3 && ((year%4==0 && year%100!=0) || year%400==0) )daysPassed-=1;//if we enter a high year that still has not reached the 29th of February

daysPassed = daysPassed + day - 1;

month-=1;//since we have only 12 months, we use only the days of the month that has been entered

for(;month>=1;month--)
{
    if(month==3 || month==5 || month==7 || month==8 || month==10 || month==12)daysPassed = daysPassed + 31;
    else if(month==4 || month==6 || month==9 || month==11)daysPassed = daysPassed + 30;
    else if(month==2)daysPassed = daysPassed + 28;
    else if(month==1)daysPassed = daysPassed + 31;
}


cout<<daysPassed<<" days have passed."<<endl;



}



return 0;
}
