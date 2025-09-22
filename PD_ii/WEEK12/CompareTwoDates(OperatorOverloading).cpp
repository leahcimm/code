#include <iostream>

using namespace std;

class Date2023
{
private:
    char* month_name[13] = {"","January","February","March","April","May","June","July","August","September","October","November","December"};
    char* week[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    int mday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    int month, day;
    Date2023(int mm, int dd){
        month = mm;
        day = dd;
    }
    void print(){
        int number = 0;
        if(month < 1 || month > 12 || day < 1 || mday[month] < day) {
            cout << "a date not in 2023";
            return;//跳出函式
        }
        for(int i = 0; i < month; i++){
            number = number + mday[i];
        }
        number = number + day;
        number = (number + 6) % 7;
        cout << week[number] << ", " << month_name[month] << " " << day << ", " << "2023";
    }
    bool operator==( Date2023 t ){
        return month==t.month&&day==t.day;
    }
    bool operator> (Date2023 t){
        return month > t.month || (month==t.month&&day>t.day);
    }
    bool operator< (Date2023 t){
        return month < t.month || (month==t.month&&day<t.day);
    }
};

int main(){
    int rptimes, m1, d1, m2, d2;
    cin >> rptimes; 
    for(int i=0; i<rptimes; i++){
        cin >> m1 >> d1 >> m2 >> d2;
        Date2023 da(m1,d1), db(m2,d2);
        if( da == db ) cout << "=\n";
        if( da > db ) cout << ">\n";
        if( da < db ) cout << "<\n";
    }
}