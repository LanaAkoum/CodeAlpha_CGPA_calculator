#include <iostream>
#include <cstdio>

struct Course {
    double grade;
    int credits;
};

void inputCourses(Course c[], int &numCourses) {
    printf("Enter the number of courses for this semester: ");
    std::cin >> numCourses;

    for (int i = 0; i < numCourses; ++i) {
        printf("Enter grade and credits for course %d: ", i + 1);
        std::cin >> c[i].grade >> c[i].credits;
    }
}

double calculateGPA(Course c[], int numCourses) {
    double totalGradePoints = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; ++i) {
        totalGradePoints += c[i].grade * c[i].credits;
        totalCredits += c[i].credits;
    }

    return totalGradePoints / totalCredits;
}

double calculateCGPA(Course allCourses[], int totalCourses) {
    double cumulativeGradePoints = 0.0;
    int cumulativeCredits = 0;

    for (int i = 0; i < totalCourses; ++i) {
        cumulativeGradePoints += allCourses[i].grade * allCourses[i].credits;
        cumulativeCredits += allCourses[i].credits;
    }

    return cumulativeGradePoints / cumulativeCredits;
}

int calculateTotalCredits(Course c[], int numCourses) {
    int totalCredits = 0;

    for (int i = 0; i < numCourses; ++i) {
        totalCredits += c[i].credits;
    }

    return totalCredits;
}

int main() {
    const int MAX_COURSES = 100;
    Course allCourses[MAX_COURSES * 10];
    int totalCourses = 0;
    int numSemesters;

    printf("Enter the number of semesters: ");
    std::cin >> numSemesters;

    for (int t = 0; t < numSemesters; ++t) {
        Course c[MAX_COURSES];
        int numCourses;

        printf("\nEntering data for semester %d\n", t + 1);
        inputCourses(c, numCourses);

        double gpa = calculateGPA(c, numCourses);
        printf("Your GPA for semester %d is: %.2f\n", t + 1, gpa);

        for (int i = 0; i < numCourses; ++i) {
            allCourses[totalCourses++] = c[i];
        }
    }

    double cgpa = calculateCGPA(allCourses, totalCourses);
    printf("\nYour cumulative CGPA is: %.2f\n", cgpa);

    int totalCredits = calculateTotalCredits(allCourses, totalCourses);
    printf("Your total credits are: %d\n", totalCredits);


    return 0;
}
