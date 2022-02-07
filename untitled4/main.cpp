#include "iostream"

using namespace std;

string my_roman_numerals_converter(int n){

    string str_romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string result = "";

    for (int i = 0; i < 13; ++i)
    {
        while(n - values[i] > -1){
            result += str_romans[i];
                n -= values[i];
           }
    }

    return result;
}

int main(){
    int n;

    cin >> n;

    cout << my_roman_numerals_converter(n) << endl;

}