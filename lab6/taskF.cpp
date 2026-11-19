include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Student {
    string lastname, firstname;
    double gpa;
};

double getGrade(string s) {
    if (s == "A+") return 4.00;
    if (s == "A")  return 3.75;
    if (s == "B+") return 3.50;
    if (s == "B")  return 3.00;
    if (s == "C+") return 2.50;
    if (s == "C")  return 2.00;
    if (s == "D+") return 1.50;
    if (s == "D")  return 1.00;
    return 0.00;
}

bool cmp(Student a, Student b) {
    if (a.gpa != b.gpa)
        return a.gpa < b.gpa;

    if (a.lastname != b.lastname)
        return a.lastname < b.lastname;

    return a.firstname < b.firstname;
}

int main() {
    int n;
    cin >> n;

    vector<Student> students(n);

    for (int i = 0; i < n; i++) {
        cin >> students[i].lastname >> students[i].firstname;

        int k;
        cin >> k;

        double sum = 0;
        int creditsSum = 0;

        for (int j = 0; j < k; j++) {
            string mark;
            int credits;

            cin >> mark >> credits;

            sum += getGrade(mark) * credits;
            creditsSum += credits;
        }

        students[i].gpa = sum / creditsSum;
    }

    sort(students.begin(), students.end(), cmp);

    cout << fixed << setprecision(3);

    for (int i = 0; i < n; i++) {
        cout << students[i].lastname << " "
             << students[i].firstname << " "
             << students[i].gpa << '\n';
    }

    return 0;
}
