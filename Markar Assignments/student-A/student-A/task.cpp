#include <iostream>
#include <string>
using namespace std;

// ############# PART-A #######################
////////  DO NOT CHANGE FUNCTION NAME AND PARAMTERS ///////
string reverse_from_special_character(string str, char special, int index = 0)
{
    if (str[index] == special)
        return "";

    return str = reverse_from_special_character(str, special, index + 1) + str[index];
}

////////  DO NOT CHANGE FUNCTION NAME AND PARAMTERS ///////
// ############# PART-B #######################
//  UNCOMMENT WHEN YOU DONE WITH PART A
int count_specific_number(string str, int num, int index = 0)
{
    if (str[index] == '\0')
        return 0;

    if (str[index] == num + '0')
        return count_specific_number(str, num, index + 1) + 1;
    else
        return count_specific_number(str, num, index + 1) + 0;
}

int main()
{
    // SAMPLE

    cout << "Output:" << reverse_from_special_character("Hello D$orothy", '$', 0) << endl;
    cout << "Output:" << count_specific_number("11112211119999912220000", 9, 0) << endl;
    return 0;
}