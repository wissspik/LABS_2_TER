#include <cmath>
#include <iostream>
#include <math.h>
using namespace std;
class labs_1{
public:
    int max;//  поля класса
    float function_value;
    void fib_number(int max); // методы класса
    void sin_function(float function_value);

};
int found_fib(int count) { // нахожу значения числа фибоначи по count
    if(count == 0) {
        return 0;
    }
    else if (count == 1 || count == 2) {
        return 1;
    }
    else {
        return found_fib(count - 1) + found_fib(count- 2);
    }
}
void labs_1::sin_function(float function_value) {
    if (function_value <= 0 || function_value > 4) { // тест на число
        cout<<"Invalid Input"<<endl;
    }
    else {
        int counter = 0;
        double sm = 0;
        double function = sin(function_value) / (function_value);
        while(counter != 10) {
            sm = sm + (function / 10);
            counter++;
            cout<<counter<<")"<<sm<<endl;
        }
    }

}



void labs_1::fib_number(int max) { // 1 stage
    if (max < 1) {
        cout <<"enter a number starting from 1 :)" << endl;
    }
    else{
        int sum_fib = 0;
        int count_fib = 0;
        while (sum_fib <= max) { // прибавляю к канту,пока < max
            sum_fib = sum_fib + found_fib(count_fib); // нахожу фибоначи по каунту
            count_fib++;
        }
        cout << "the sum of all the numbers: " << sum_fib - found_fib(count_fib - 1) << " | the number of all numbers: " <<count_fib - 1 <<  endl;
    }
}






using namespace std;
int main() {
    int number;
    float function_value;
    cout << "enter the values for max: "; // 1 stage
    cin >> number;
    labs_1 obj(number);
    obj.fib_number(number);
    cout << "enter a value for x (0,4]:  "; // 2 stage
    cin >> function_value;
    obj.sin_function(function_value);
}
//  0 1 1 2 3 5 8 13
// 2 / 10