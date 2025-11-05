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

// Function to add a single student
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
    cout << "\n Student added successfully!\n";
}

// ✅ Function to add multiple students at once
void addMultipleStudents() {
    int count;
    cout << "\nHow many students do you want to add? ";
    cin >> count;
    cin.ignore();

    for (int i = 1; i <= count; i++) {
        cout << "\n--- Enter details for Student " << i << " ---\n";
        addStudent();
    }
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

            cout << "\n Student details updated successfully!\n";
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
        cout << "1. Add Single Student\n";
        cout << "2. Add Multiple Students\n"; // ✅ New Option
        cout << "3. Show All Students\n";
        cout << "4. Search Student\n";
        cout << "5. Update Student\n";
        cout << "6. Delete Student\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addStudent(); break;
            case 2: addMultipleStudents(); break; // ✅ New Case
            case 3: showStudents(); break;
            case 4: searchStudent(); break;
            case 5: updateStudent(); break;
            case 6: deleteStudent(); break;
            case 7: cout << "\n👋 Exiting... Thank you!\n"; break;
            default: cout << "\n❌ Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
