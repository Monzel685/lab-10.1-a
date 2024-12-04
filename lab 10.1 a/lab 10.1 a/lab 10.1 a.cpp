#include <iostream>
#include <string>
#include <iomanip>
#include "Windows.h"
using namespace std;

// Перелік спеціальностей
enum Specialty { ComputerScience, Informatics, MathEconomics, PhysicsInformatics, LaborTraining };

// Структура студента
struct Student {
    string surname;
    int course;
    Specialty specialty;
    int physicsGrade;
    int mathGrade;
    int informaticsGrade;
};

// Функція для вводу студентів
void inputStudents(Student* students, int count) {
    for (int i = 0; i < count; ++i) {
        cout << "Введіть прізвище студента: ";
        cin >> students[i].surname;
        cout << "Введіть курс студента (1-5): ";
        cin >> students[i].course;
        cout << "Введіть спеціальність (0 - Computer Science, 1 - Informatics, 2 - Math and Economics, 3 - Physics and Informatics, 4 - Labor Training): ";
        int spec;
        cin >> spec;
        students[i].specialty = static_cast<Specialty>(spec);
        cout << "Введіть оцінку з фізики: ";
        cin >> students[i].physicsGrade;
        cout << "Введіть оцінку з математики: ";
        cin >> students[i].mathGrade;
        cout << "Введіть оцінку з інформатики: ";
        cin >> students[i].informaticsGrade;
    }
}

// Функція для виводу студентів
void printStudents(const Student* students, int count) {
    cout << "===============================================================================================" << endl;
    cout << "| №   | Прізвище          | Курс | Спеціальність          | Фізика | Математика | Інформатика |" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < count; ++i) {
        string specName;
        switch (students[i].specialty) {
        case ComputerScience: specName = "Computer Science"; break;
        case Informatics: specName = "Informatics"; break;
        case MathEconomics: specName = "Math & Economics"; break;
        case PhysicsInformatics: specName = "Physics & Informatics"; break;
        case LaborTraining: specName = "Labor Training"; break;
        }
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(18) << left << students[i].surname;
        cout << "| " << setw(4) << students[i].course << " ";
        cout << "| " << setw(23) << left << specName;
        cout << "| " << setw(6) << students[i].physicsGrade << " ";
        cout << "| " << setw(10) << students[i].mathGrade << " ";
        cout << "| " << setw(11) << students[i].informaticsGrade << " |" << endl;
    }
    cout << "===============================================================================================" << endl;
}

// Завдання 1: Підрахунок оцінок "задовільно"
void countSatisfactory(const Student* students, int count) {
    int physicsCount = 0, mathCount = 0, informaticsCount = 0;
    for (int i = 0; i < count; ++i) {
        if (students[i].physicsGrade == 3) physicsCount++;
        if (students[i].mathGrade == 3) mathCount++;
        if (students[i].informaticsGrade == 3) informaticsCount++;
    }
    cout << "Оцінок \"задовільно\":\n";
    cout << "Фізика: " << physicsCount << ", Математика: " << mathCount << ", Інформатика: " << informaticsCount << "\n";
}

// Завдання 2: Вивід студентів з оцінками 4 або 5 з фізики та математики
void printHighPerformingStudents(const Student* students, int count) {
    cout << "Студенти з оцінками 4 або 5 з фізики і математики:\n";
    for (int i = 0; i < count; ++i) {
        if ((students[i].physicsGrade == 4 || students[i].physicsGrade == 5) &&
            (students[i].mathGrade == 4 || students[i].mathGrade == 5)) {
            cout << students[i].surname << "\n";
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int studentCount;
    cout << "Введіть кількість студентів: ";
    cin >> studentCount;

    // Динамічний масив студентів
    Student* students = new Student[studentCount];

    inputStudents(students, studentCount);
    printStudents(students, studentCount);

    countSatisfactory(students, studentCount);
    printHighPerformingStudents(students, studentCount);

    // Видалення динамічного масиву
    delete[] students;

    return 0;
}
