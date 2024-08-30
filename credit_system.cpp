#include <iostream>

using namespace std;

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    string courseNames[numCourses];
    int creditHours[numCourses];
    double grades[numCourses];

    for (int i = 0; i < numCourses; ++i) {
        cout << "Enter details for course " << i + 1 << ":\n";
        cout << "Course Name: ";
        cin >> ws; // To ignore any leading whitespace
        getline(cin, courseNames[i]);
        cout << "Credit Hours: ";
        cin >> creditHours[i];
        
        // Validate grade input
        do {
            cout << "Grade (on a 10.0 scale): ";
            cin >> grades[i];
            if (grades[i] < 0 || grades[i] > 10) {
                cout << "Invalid input. Please enter a grade between 0 and 10.\n";
            }
        } while (grades[i] < 0 || grades[i] > 10);
    }

    double totalGradePoints = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; ++i) {
        totalGradePoints += grades[i] * creditHours[i];
        totalCredits += creditHours[i];
    }

    double gpa = totalGradePoints / totalCredits;

    cout << "\nIndividual Course Grades:\n";
    for (int i = 0; i < numCourses; ++i) {
        cout << "Course: " << courseNames[i]
             << " | Credits: " << creditHours[i]
             << " | Grade: " << grades[i] << "\n";
    }

    cout << "\nTotal Credits Earned: " << totalCredits << "\n";
    cout << "Semester GPA: " << gpa << "\n";
    cout << "Cumulative GPA (CGPA): " << gpa << "\n";

    return 0;
}