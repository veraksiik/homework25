#include <iostream> 
#include <Windows.h>
#include <string>
#include <cstdlib>

using namespace std;


bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    }
    else {
        return false;
    }
}


int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int daysBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2) {
    int days = 0;

    for (int year = year1; year < year2; ++year) {
        days += isLeapYear(year) ? 366 : 365;
    }

    for (int month = month1; month <= 12; ++month) {
        if (month == month1) {
            days += daysInMonth[month - 1] - day1;
        }
        else {
            days += daysInMonth[month - 1];
        }
    }

    for (int month = 1; month < month2; ++month) {
        days += daysInMonth[month - 1];
    }

    days += day2;

    return days;
}

double average(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    return sum / (double)size; 
}

void countPosNegZero(int ar[], int siz) {
    int pos = 0, neg = 0, zero = 0;

    for (int i = 0; i < siz; ++i) {
        if (ar[i] > 0) {
            pos++;
        }
        else if (ar[i] < 0) {
            neg++;
        }
        else {
            zero++;
        }
    }

    cout << "Положительные: " << pos << ", Отрицательные: " << neg << ", Нулевые: " << zero << endl;
}

void initializeMatrix(int matrix[][3], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = i * size + j + 1; 
        }
    }
}

void printMatrix(int matrix[][3], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int maxDiagonalElement(int matrix[][3], int size) {
    int max = matrix[0][0];
    for (int i = 1; i < size; ++i) {
        if (matrix[i][i] > max) {
            max = matrix[i][i];
        }
    }
    return max;
}

int minDiagonalElement(int matrix[][3], int size) {
    int min = matrix[0][0];
    for (int i = 1; i < size; ++i) {
        if (matrix[i][i] < min) {
            min = matrix[i][i];
        }
    }
    return min;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int generateNumber() {
    srand(static_cast<unsigned int>(time(NULL)));
    return 1000 + rand() % 9000;
}

void checkNumber(int secretNumber, int guess, int& bulls, int& cows) {
    std::string secretStr = std::to_string(secretNumber);
    std::string guessStr = std::to_string(guess);

    bulls = 0;
    cows = 0;

    for (int i = 0; i < 4; i++) {
        if (secretStr[i] == guessStr[i]) {
            bulls++;
        }
        else if (secretStr.find(guessStr[i]) != std::string::npos) {
            cows++;
        }
    }
}

void playGame(int secretNumber, int attempts) {
    int guess;
    std::cout << "Угадайте четырехзначное число: ";
    std::cin >> guess;

    int bulls, cows;
    checkNumber(secretNumber, guess, bulls, cows);

    std::cout << "Быков: " << bulls << ", Коров: " << cows << std::endl;

    if (bulls == 4) {
        std::cout << "Поздравляем, вы угадали число! Количество попыток: " << attempts << std::endl;
    }
    else {
        playGame(secretNumber, attempts + 1);
    }
}





int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);    
    
    cout << "домашка 1" << endl;
    cout << "задание 1" << endl;
    int day1 = 1, month1 = 1, year1 = 2022;
    int day2 = 27, month2 = 2, year2 = 2024;

    int difference = daysBetweenDates(day1, month1, year1, day2, month2, year2);
    cout << "Разница в днях между датами: " << difference << endl;

    cout << "задание 2" << endl;
    int arr[] = { 5, 10, 15, 20, 25 };
    int size = sizeof(arr) / sizeof(arr[0]);

    double avg = average(arr, size);

    cout << "Среднее арифметическое элементов массива: " << avg << endl;

    cout << "задание 3" << endl;

    int ar[] = { 1, -2, 3, 0, -5, 0 };
    int siz = sizeof(ar) / sizeof(ar[0]);

    countPosNegZero(ar, siz);

    cout << "домашка 2" << endl;
    cout << "задание 1" << endl;
    const int si = 3;
    int matrix[si][3];

    initializeMatrix(matrix, size);
    printMatrix(matrix, size);

    cout << "Максимальный элемент на главной диагонали: " << maxDiagonalElement(matrix, size) << endl;
    cout << "Минимальный элемент на главной диагонали: " << minDiagonalElement(matrix, size) << endl;

    cout << "задание 2" << endl;
    int num1 = 48;
    int num2 = 18;

    cout << "Наибольший общий делитель чисел " << num1 << " и " << num2 << " равен: " << gcd(num1, num2) << endl;

    cout << "задание 3" << endl;
    int secretNumber = generateNumber();
    playGame(secretNumber, 1);


    system("pause");    
    return 0;
}




















