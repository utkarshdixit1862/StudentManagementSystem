#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    string className;
    string address;
    string phone;
};

vector<Student> students;

// Function to add a new student
void addStudent() {
    Student s;
    cout << "\nEnter Student ID: ";
    cin >> s.id;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Class: ";
    getline(cin, s.className);

    cout << "Enter Address: ";
    getline(cin, s.address);

    cout << "Enter Phone Number: ";
    getline(cin, s.phone);

    students.push_back(s);
    cout << "\n✅ Student added successfully!\n";
}

// Function to display all students
void showStudents() {
    if (students.empty()) {
        cout << "\nNo student records available.\n";
        return;
    }

    cout << "\n--- Student Details ---\n";
    for (auto &s : students) {
        cout << "ID: " << s.id << "\n";
        cout << "Name: " << s.name << "\n";
        cout << "Class: " << s.className << "\n";
        cout << "Address: " << s.address << "\n";
        cout << "Phone: " << s.phone << "\n";
        cout << "----------------------\n";
    }
}

// Function to update student details
void updateStudent() {
    int id;
    cout << "\nEnter Student ID to Update: ";
    cin >> id;
    cin.ignore();

    for (auto &s : students) {
        if (s.id == id) {
            cout << "\nEnter new details:\n";
            cout << "Enter Name: ";
            getline(cin, s.name);
            cout << "Enter Class: ";
            getline(cin, s.className);
            cout << "Enter Address: ";
            getline(cin, s.address);
            cout << "Enter Phone: ";
            getline(cin, s.phone);

            cout << "\n✅ Student details updated successfully!\n";
            return;
        }
    }
    cout << "\n❌ Student with ID " << id << " not found.\n";
}

// Function to delete a student
void deleteStudent() {
    int id;
    cout << "\nEnter Student ID to Delete: ";
    cin >> id;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            cout << "\n🗑️ Student deleted successfully!\n";
            return;
        }
    }
    cout << "\n❌ Student with ID " << id << " not found.\n";
}

// Function to search a student
void searchStudent() {
    int id;
    cout << "\nEnter Student ID to Search: ";
    cin >> id;

    for (auto &s : students) {
        if (s.id == id) {
            cout << "\n--- Student Found ---\n";
            cout << "ID: " << s.id << "\n";
            cout << "Name: " << s.name << "\n";
            cout << "Class: " << s.className << "\n";
            cout << "Address: " << s.address << "\n";
            cout << "Phone: " << s.phone << "\n";
            return;
        }
    }
    cout << "\n❌ Student with ID " << id << " not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Show All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addStudent(); break;
            case 2: showStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: cout << "\n👋 Exiting... Thank you!\n"; break;
            default: cout << "\n❌ Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
