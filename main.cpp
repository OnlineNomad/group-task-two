#include <iostream>

using namespace std;

int roman_to_integer(string Roman){
    int n = int(Roman.length());
    if (0 == n)
    {
        return 0;
    }
    int Answer = 0;
    for (int i = 0; i < n; i++)
    {
        switch (Roman[i])
        {
        case 'I':
            Answer += 1;
            break;
        case 'V':
            Answer += 5;
            break;
        case 'X':
            Answer += 10;
            break;
        case 'L':
            Answer += 50;
            break;
        case 'C':
            Answer += 100;
            break;
        }
    }

    for (int i = 1; i < n; i++)
    {
        if ((Roman[i] == 'V' || Roman[i] == 'X') && Roman[i - 1] == 'I')
        {
            Answer -= 1 + 1;
        }

        if ((Roman[i] == 'L' || Roman[i] == 'C') && Roman[i - 1] == 'X')
        {
            Answer -= 10 + 10;
        }

        if ((Roman[i] == 'D' || Roman[i] == 'M') && Roman[i - 1] == 'C')
        {
            Answer -= 100 + 100;
        }
    }

    return Answer;
}

int Calculation(int x, int y, char op){

    switch (op)
    {

    case '+':
        return x + y;
        break;
    case '-':
        return x - y;
        break;
    case '*':
        return x * y;
        break;
    case '/':
        if (y != 0)
            return x / y;
        else
            break;
    default:
        cout << "Enter Valid Operator ! " << endl;
        break;
    }
    return 0;
}

string convert_to_Roman(int Answer){

    string Roman = "";
    while (Answer > 0)
    {
        if (Answer >= 100)
        {
            Roman += "C";
            Answer -= 100;
        }
        else if (Answer >= 90)
        {
            Roman += "XC";
            Answer -= 90;
        }
        else if (Answer >= 50)
        {
            Roman += "L";
            Answer -= 50;
        }
        else if (Answer >= 40) {
            Roman += "XL";
            Answer -= 40;
        }
        else if (Answer >= 10)
        {
            Roman += "X";
            Answer -= 10;
        }
        else if (Answer >= 9) {
            Roman += "IX";
            Answer -= 9;
        }
        else if (Answer >= 5)
        {
            Roman += "V";
            Answer -= 5;
        }
        else if (Answer >= 4) {
            Roman += "IV";
            Answer -= 4;
        }
        else
        {
            Roman += "I";
            Answer -= 1;
        }
    }
    return Roman;
}

int main(){
    int grandResult = 0;
    char operation;
    string firstRomanNumber;
    string secondRomanNumber;
    cout << "Enter roman number (I to C): " << endl;
    cin >> firstRomanNumber;
    cout << "Enter Operation (+,-,*,/): " << endl;
    cin >> operation;
    cout << "Enter another roman number: " << endl;
    cin >> secondRomanNumber;
    grandResult += Calculation(roman_to_integer(firstRomanNumber), roman_to_integer(secondRomanNumber), operation);
    int switcher = 0;
    while (switcher == 0)
    {
        cout << "Enter Operation: " << endl;
        cin >> operation;
        cout << "Enter another roman number or type 'exit' to finish calculation " << endl;
        cin >> secondRomanNumber;
        grandResult = Calculation(grandResult, roman_to_integer(secondRomanNumber), operation);
        if (secondRomanNumber == "exit")
        {
            switcher += 1;
        }
    }
    if (grandResult > 100)
    {
        cout << "Number too high. try again... " << endl;
    }
    else
    {
        cout << "Result is: " << convert_to_Roman(grandResult) << endl;
    }
    return 0;
}

