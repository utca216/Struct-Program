#include <bits/stdc++.h>
using namespace std;
int dayvs[12]={31,60,91,121,152,182,213,244,274,305,335,366};
int daynvs[12]={31,59,90,120,151,181,212,243,273,304,334,365};
struct Date{
    int day, month, year;
    
    bool isValidDate(){
        if(day>0&&day<31&&month>0&&month<12){
            if(year%4==0){
                if(month==2&&day>29)
                    return false;
            }
            else
                if(month==2&&day>28)
                    return false;
        return true;    
        }
        else
        return false;
    }
    
    void newDate(int a, int b, int c){
        day=a;
        month=b;
        year=c;
        if(day>0&&day<31&&month>0&&month<12){
            if(year%4==0){
                if(month==2&&day>29)
                    cout<<"error!";
            }
            else
                if(month==2&&day>28)
                    cout<<"error!";
        cout<<"succesful!";    
        }
        else
        cout<<"error!";
    };
    
    string getDayOfWeek(){
        int dayb;
        int diff=abs(2024-year);
        if(year>=2024){
            dayb=diff/4;
            if(dayb>0)
                dayb++;
            if(year%4==0&&month!=1)
                dayb+=dayvs[month-2];
            if(year%4!=0&&month!=1)
                dayb+=daynvs[month-2];
            dayb+=day;
            dayb+=365*diff;
            dayb=dayb%7;
        }
        else{
              dayb=diff/4;
            if(year%4==0&&month!=1)
                dayb-=dayvs[month-2];
            if(year%4!=0&&month!=1)
                dayb-=daynvs[month-2];
            dayb-=day;
            dayb+=diff*365;
            dayb=dayb*-1;
            while(dayb<0)
                dayb+=7;
            dayb=dayb%7;
        }
        switch(dayb){
            case 0:
                return "Saturday";
            break;
            case 1:
                return "Monday";
            break; 
            case 2:
                return "Tuesday";
            break; 
            case 3:
                return "Wednesday";
            break; 
            case 4:
                return "Thursday";
            break;
            case 5:
                return "Friday";
            break;
            case 6:
                return "Sunday";
            break;
        }
    return 0;    
    };
    
    int calculateDifference(int day1, int month1,int year1){
        int dayb=0, dayb1=0;
        if(year>=year1){
            if(year%4==0&&month!=1)
                dayb+=dayvs[month-2];
            if(year%4!=0&&month!=1)
                dayb+=daynvs[month-2];
            if(year1%4==0&&month1!=1)
                dayb1+=dayvs[month1-2];
            if(year1%4!=0&&month1!=1)
                dayb1+=daynvs[month1-2];
        return (day-day1+dayb-dayb1+abs(year-year1)*365)+2;    
        }
        else{
            if(year%4==0&&month!=1)
                dayb+=dayvs[month-2];
            if(year%4!=0&&month!=1)
                dayb+=daynvs[month-2];
            if(year1%4==0&&month1!=1)
                dayb1+=dayvs[month1-2];
            if(year1%4!=0&&month1!=1)
                dayb1+=daynvs[month1-2];
        return (day1-day+dayb1-dayb+abs(year-year1)*365)+2; 
        }
            
    };
    
    void printDate(){
        switch(month){
        case 1:
            cout<<"January "<<day<<", "<<year<<endl;
            break;
        case 2:
            cout<<"Febrary "<<day<<", "<<year<<endl;
            break;
        case 3:
            cout<<"March "<<day<<", "<<year<<endl;
            break;
        case 4:
            cout<<"April "<<day<<", "<<year<<endl;
            break;
        case 5:
            cout<<"May "<<day<<", "<<year<<endl;
            break;
        case 6:
            cout<<"June "<<day<<", "<<year<<endl;
            break;
        case 7:
            cout<<"July "<<day<<", "<<year<<endl;
            break;
        case 8:
            cout<<"August "<<day<<", "<<year<<endl;
            break;
        case 9:
            cout<<"September "<<day<<", "<<year<<endl;
            break;
        case 10:
            cout<<"October "<<day<<", "<<year<<endl;
            break;
        case 11:
            cout<<"November "<<day<<", "<<year<<endl;
            break;
        case 12:
            cout<<"December "<<day<<", "<<year<<endl;
            break;
        }    
    }
    
};

bool operator==(Date &BirthDate,Date &Fs){
    return Fs.day==BirthDate.day&&Fs.month==BirthDate.month&&Fs.year==BirthDate.year;
}
bool operator<(Date BirthDate,Date Fs){
    if(Fs.year>BirthDate.year)
    return true;
    else if(Fs.year<BirthDate.year)
    return false;
    if(Fs.month>BirthDate.month)
    return true;
    else if(Fs.month<BirthDate.month)
    return false;
    if(Fs.day>BirthDate.day)
    return true;
    else
    return false;
}
bool operator>(Date Fs,Date BirthDate){
    if(Fs.year>BirthDate.year)
    return true;
    else if(Fs.year<BirthDate.year)
    return false;
    if(Fs.month>BirthDate.month)
    return true;
    else if(Fs.month<BirthDate.month)
    return false;
    if(Fs.day>BirthDate.day)
    return true;
    else
    return false;
}

int main()
{
    Date BirthDate;
    Date Fs;
    vector<Date> dates;
    int n, day, month, year;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>day>>month>>year;
        if(day>0&&day<31&&month>0&&month<12){
            if(year%4==0){
                if(month==2&&day>29){
                    cout<<"error!";
                    break;
                }
            else
                if(month==2&&day>28){
                    cout<<"error!";
                    break;
                }
        }
        dates.push_back({day,month,year});    
        cout<<"succesful!"<<endl;
        }    
        else
            cout<<"error!";
        
    }
    sort(dates.begin(), dates.end());
    
    for(int i=0; i<n; i++)
    {
        dates[i].printDate();
        cout<<dates[i].getDayOfWeek()<<endl;
        if(i!=0)
        cout<<dates[i].calculateDifference(dates[i-1].day, dates[i-1].month, dates[i-1].year)<<" days between"<<endl;
        
        cout<<endl;
    }
    //BirthDate.newDate(20,12,2005);
    //Fs.newDate(30,12,2005);
    //cout<<BirthDate.calculateDifference(11,04,2001);
    //BirthDate.printDate();
    //bool aboba=BirthDate>Fs;
    //cout<<aboba;
    return 0;
}
