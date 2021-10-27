#include <iostream>
using namespace std;

class DayOfYear{
public:
    void adjustDay(int addDay) {
        //31 28 31 30 31 30 31 31 30 31 30 31
        int sum = day + addDay;
        int totalMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  //각 달에 대한 일수를 배열로 저장.
        
        while (totalMonth[month - 1] < sum) {                                   //만약 현재 날짜와 입력받은 일수가 해당 달의 최대 일수보다 크다면??
            sum -= totalMonth[month-1];                                         //입력받은 달에 대해 일수를 day+addDay에서 빼준다.
            month++;                                                            //최대 일수보다 크기 때문에 달도 1 증가 시켜준다.
        }

        day = sum;
    }
    
    int output() {
        switch(month) {
            case 1:
                cout << "January "; break;
            case 2:
                cout << "February "; break;
            case 3:
                cout << "March "; break;
            case 4:
                cout << "April "; break;
            case 5:
                cout << "May "; break;
            case 6:
                cout << "June "; break;
            case 7:
                cout << "July "; break;
            case 8:
                cout << "August "; break;
            case 9:
                cout << "September "; break;
            case 10:
                cout << "October "; break;
            case 11:
                cout << "November "; break;
            case 12:
                cout << "December "; break;
            default:
                cout << "Error in DayOfYear::output. Contact software vendor.";
        }

        return day;

    }   //멤버함수

    int month;  //멤버변수
    int day;  //멤버변수
};

int main(){
    DayOfYear d1;
    d1.month = 8;
    d1.day = 20;
    
    d1.adjustDay(20);

    cout << "Adjusted date is " << d1.output()<<'\n';

    return 0;
}

