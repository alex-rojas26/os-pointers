// compile: g++ -std=c++14 -o pointers pointers.cpp
#include <iostream>
#include <string>

typedef struct Student {
    int id;
    char *f_name[128];
    char *l_name[128];
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;
    char first[128];
    char last[128]; 

    // Sequence of user input -> store in fields of `student`
    student.id = promptInt("Please enter the student's id number: ", 0, 999999);
    std::cin.ignore();

    std::cout << "Please enter the student's first name: ";
    std::cin >> first;
    student.f_name[0] = first;

    std::cout << "Please enter the student's last name: ";
    std::cin >> last;
    student.l_name[0] = last;

    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 1, 134217728);

    // Call `CalculateStudentAverage(???, ???)`
    // Output `average`
    // average = calculateStudentAverage(student.grades, average);

    std::cout << student.f_name[0] << " " << student.l_name[0] << " [" << student.id << "]" << std::endl;
    // std::cout << "  Average grade: " << average/student.n_assignments;

    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    int value = min - 1;
    while (value < min || value > max) {
        std::cout << message;
        std::cin >> value;

        if (value < min || value > max) {
            std::cout << "Sorry, I cannot understand your answer" << std::endl;
            // std::cin.ignore();
        }
        std::cin.ignore();
    }

    return value;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
    double val = min - 1;
    while (val < min || val > max) {
        std::cout << message;
        std::cin >> val;

        if (val < min || val > max) {
            std::cout << "Sorry, I cannot understand your answer" << std::endl;
            // std::cin.ignore();
        }
        std::cin.ignore();
    }

    return val;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
    promptDouble("Please enter grade for assignment of " + 1, 0.000001, 1000.00);
}
