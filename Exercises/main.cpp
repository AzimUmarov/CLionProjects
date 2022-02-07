#include <iostream>

using namespace std;

bool checkE(string str, char letter){
    for(int i =0; i < str.length();i++)
        if(str[i] == letter)
            return 1;

    return 0;
}

string my_union(string param_1, string param_2)
{
     string result;
     param_1 += param_2;
     for(int i = 0; i < param_1.length() ; i++)
         if (!checkE(result, param_1[i]))
             result += param_1[i];

     return result;

}



int main() {
    cout << my_union("zpadinton", "paqefwtdjetyiytjneytjoeyjnejeyj");
    return 0;
}
