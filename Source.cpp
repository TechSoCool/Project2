#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};
void getData(ifstream& inFile, studentType sList[], int listSize);
void calculateGrade(studentType sList[], int listSize);
int highestScore(const studentType sList[], int listSize);
void printResult(const studentType sList[], int listSize);
int main() {
    ifstream in;
    in.open("text.txt");
    if (in.fail()) {
        cout << "file did not open please check it\n";
        system("pause");
        return ;    //use return instead of system("exit"), it terminates the execution even when called from IDE
    }
    studentType sList[20];
    getData(in, sList, 20);
    calculateGrade(sList, 20);
    printResult(sList, 20);
    in.close();
    return 0;
}

void getData(ifstream& inFile, studentType sList[], int listSize) {
    int n = 0;
    while (n < listSize) {
        inFile >> sList[n].studentLName >> sList[n].studentFName >> sList[n].testScore;
        n++;
    }
}
void calculateGrade(studentType sList[], int listSize) {
    int i;
    for (i = 0; i < listSize; i++) {
        if (sList[i].testScore < 60)
            sList[i].grade = 'F';
        else if (sList[i].testScore < 70)
            sList[i].grade = 'D';
        else if (sList[i].testScore < 80)
            sList[i].grade = 'C';
        else if (sList[i].testScore < 90)
            sList[i].grade = 'B';
        else
            sList[i].grade = 'A';
    }
}
int highestScore(const studentType sList[], int listSize) {
    int high = 0, i;
    for (i = 0; i < listSize; i++)
        if (high < sList[i].testScore)
            high = sList[i].testScore;
    return high;
}

void printResult(const studentType sList[], int listSize) {
    ofstream myfile("CH9_EX2Out.txt");
    if (myfile.is_open()) {
        cout << left << setw(30) << "Student Name" << right << setw(10) << "TestScore" << right << setw(7) << "Grade" << endl;
        myfile << left << setw(30) << "Student Name" << right << setw(10) << "TestScore" << right << setw(7) << "Grade" << endl;
        string name;
        int high, i;
        for (i = 0; i < listSize; i++) {
            name = sList[i].studentLName + ", " + sList[i].studentFName;
            cout << left << setw(30) << name << right << setw(10) << sList[i].testScore << right << setw(7) << sList[i].grade << endl;
            myfile << left << setw(30) << name << right << setw(10) << sList[i].testScore << right << setw(7) << sList[i].grade << endl;
        }
        cout << endl;
        high = highestScore(sList, listSize);
        cout << "Highest Test Score: " << high << endl;
        myfile << "Highest Test Score: " << high << endl;
        cout << "Students having the highest test score: " << endl;
        myfile << "Students having the highest test score: " << endl;
        for (int i = 0; i < listSize; i++)
            if (sList[i].testScore == high) {
                myfile << sList[i].studentLName << ", " << sList[i].studentFName << endl;
                cout << sList[i].studentLName << ", " << sList[i].studentFName << endl;
            }
        myfile.close();
        cout << "Output also present in CH9_EX2Out.txt" << endl;
    }
    else {
        cout << "Error Occurred, while creating file" << endl;
    }
}

