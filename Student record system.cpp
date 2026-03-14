#include <iostream>
#include <iomanip>  // for setw
using namespace std;

class Student {
private:
    string names[70];
    int rollNumbers[70];
    int ages[70];
    float marks[70];
    int count = 0;

public:
    void insertStudent() {
        char more;
        do {
            if (count >= 70) {
                cout << "Cannot insert more records. Maximum limit (70) reached!\n";
                return;
            }

            cout << "\nEnter name: ";
            cin.ignore();
            getline(cin, names[count]);

            cout << "Enter roll number: ";
            cin >> rollNumbers[count];
            if (!cin) {
                cout << " Invalid input! Roll number must be a number.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                return;
            }

            cout << "Enter age: ";
            cin >> ages[count];
            if (!cin || ages[count] <= 0) {
                cout << " Invalid input! Please enter a valid age.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                return;
            }

           cout << "Enter marks (0-100): ";

            cin >> marks[count];
            if (!cin || marks[count] < 0 || marks[count] > 100) {
                cout << " Invalid marks! Enter between 0 and 100.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                return;
            }

            count++;
            cout << "? Student record inserted successfully!\n";

            cout << "\nDo you want to add another student? (y/n): ";
            cin >> more;
        } while (tolower(more) == 'y');
    }

    void displayStudents() {
        if (count == 0) {
            cout << "No student records found!\n";
            return;
        }

        cout << "\n--- All Student Records ---\n";
        cout << left << setw(5) << "No"
             << setw(20) << "Name"
             << setw(15) << "Roll Number"
             << setw(10) << "Age"
             << setw(10) << "Marks" << endl;
        cout << string(60, '-') << endl;

        for (int i = 0; i < count; i++) {
            cout << left << setw(5) << i + 1
                 << setw(20) << names[i]
                 << setw(15) << rollNumbers[i]
                 << setw(10) << ages[i]
                 << setw(10) << marks[i] << endl;
        }

        cout << "\nTotal Students: " << count << "/70" << endl;
    }

    void searchStudent() {
        if (count == 0) {
            cout << "No student records to search.\n";
            return;
        }

        int roll;
        cout << "Enter roll number to search: ";
        cin >> roll;

        if (!cin) {
            cout << " Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }

        for (int i = 0; i < count; i++) {
            if (rollNumbers[i] == roll) {
                cout << "\n? Record found:\n";
                cout << "Name: " << names[i]
                     << ", Roll Number: " << rollNumbers[i]
                     << ", Age: " << ages[i]
                     << ", Marks: " << marks[i] << endl;
                return;
            }
        }

        cout << "? Record not found.\n";
    }

    void deleteStudent() {
        if (count == 0) {
            cout << "No student records to delete.\n";
            return;
        }

        int roll;
        cout << "Enter roll number to delete: ";
        cin >> roll;

        if (!cin) {
            cout << " Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }

        for (int i = 0; i < count; i++) {
            if (rollNumbers[i] == roll) {
                for (int j = i; j < count - 1; j++) {
                    names[j] = names[j + 1];
                    rollNumbers[j] = rollNumbers[j + 1];
                    ages[j] = ages[j + 1];
                    marks[j] = marks[j + 1];
                }
                count--;
                cout << "? Record deleted successfully.\n";
                return;
            }
        }

        cout << "? Record not found.\n";
    }

    void updateStudent() {
        if (count == 0) {
            cout << "No student records to update.\n";
            return;
        }

        int roll;
        cout << "Enter roll number to update: ";
        cin >> roll;

        if (!cin) {
            cout << " Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }

        for (int i = 0; i < count; i++) {
            if (rollNumbers[i] == roll) {
                cout << "\nExisting Record:\n";
                cout << "Name: " << names[i]
                     << ", Age: " << ages[i]
                     << ", Marks: " << marks[i] << endl;

                cin.ignore();
                cout << "\nEnter new name: ";
                getline(cin, names[i]);

                cout << "Enter new age: ";
                cin >> ages[i];
                if (!cin || ages[i] <= 0) {
                    cout << " Invalid age! Try again.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    return;
                }

                cout << "Enter new marks (0–100): ";
                cin >> marks[i];
                if (!cin || marks[i] < 0 || marks[i] > 100) {
                    cout << " Invalid marks! Try again.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    return;
                }

                cout << "? Record updated successfully.\n";
                return;
            }
        }

        cout << "? Record not found.\n";
    }

    void findTopper() {
        if (count == 0) {
            cout << "No student records found!\n";
            return;
        }

        int topperIndex = 0;
        float highest = marks[0];
        for (int i = 1; i < count; i++) {
            if (marks[i] > highest) {
                highest = marks[i];
                topperIndex = i;
            }
        }

        cout << "\n?? Topper Student ---\n";
        cout << "Name: " << names[topperIndex]
             << ", Roll Number: " << rollNumbers[topperIndex]
             << ", Age: " << ages[topperIndex]
             << ", Marks: " << marks[topperIndex] << endl;
    }
};

int main() {
    Student s;
    int choice;

    do {
        cout << "\n--- Student Record System Menu ---\n";
        cout << "1. Insert Student\n";
        cout << "2. Display All Records\n";
        cout << "3. Search by Roll Number\n";
        cout << "4. Delete by Roll Number\n";
        cout << "5. Update Student by Roll Number\n";
        cout << "6. Find Topper Student\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (!cin) {
            cout << " Invalid input! Please enter a number between 1 and 7.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1: s.insertStudent(); break;
            case 2: s.displayStudents(); break;
            case 3: s.searchStudent(); break;
            case 4: s.deleteStudent(); break;
            case 5: s.updateStudent(); break;
            case 6: s.findTopper(); break;
            case 7: cout << "?? Exiting program...\n"; break;
            default: cout << " Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}

