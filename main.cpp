#include<iostream>
using namespace std;

class Student {

private:
    string name;
    int id;
    int age;
    float gpa;

public:
    Student(string n="", int i=0, int a=0, float g=0.0) : name(n), id(i), age(a), gpa(g) {}
 
    // Getters
    string getName() const { return name; }
    int getId() const { return id; }
    int getAge() const { return age; }
    float getGpa() const { return gpa; }

    // Setters
    void setName(string newName) { name = newName; }
    void setId(int newId) { id = newId; }
    void setAge(int newAge) { age = newAge; }
    void setGpa(float newGpa) { gpa = newGpa; }

void inputInfo() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter GPA: ";
        cin >> gpa;
    }    

void displayInfo() const {
        cout << "Name: " << name <<endl;
        cout << " ID: " << id <<endl;
        cout<< " Age: " << age <<endl;
        cout<< " GPA: " << gpa << endl;
    }

};

const int MAX_STUDENTS = 100;
Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent(){
if(studentCount >= MAX_STUDENTS) {
    cout << "Cannot add more students, maximum limit reached." << endl;
    return;
}
Student s ;
s.inputInfo();
students[studentCount++] = s;
cout << "Student added successfully." << endl;
}
void displayAllStudents() {
    if (studentCount == 0) {
        cout << "No students to display." << endl;
        return;
    }
    for (int i = 0; i < studentCount; ++i) {
        cout << "Student " << (i + 1) << ":" << endl;
        students[i].displayInfo();
        cout << "------------------------" << endl;
    }
}

void searchStudentById(int id) {
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].getId() == id) {
            cout << "Student found:" << endl;
            students[i].displayInfo();
            return;
        }
    }
    cout << "Student with ID " << id << " not found." << endl;
}

void searchStudentByName(const string& name) {
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].getName() == name) {
            cout << "Student found:" << endl;
            students[i].displayInfo();
            return;
        }
    }
    cout << "Student with name " << name << " not found." << endl;
}

void editStudent(int id) {
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].getId() == id) {
            cout << "Editing student with ID " << id << endl;
            students[i].inputInfo();
            cout << "Student information updated." << endl;
            return;
        }
    }
    cout << "Student with ID " << id << " not found." << endl;
}

void deleteStudent(int id) {
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].getId() == id) {
            for (int j = i; j < studentCount - 1; ++j) {
                students[j] = students[j + 1];
            }
            --studentCount;
            cout << "Student with ID " << id << " deleted." << endl;
            return;
        }
    }
    cout << "Student with ID " << id << " not found." << endl;
}

int main(){
int choice;
do{
cout << "1. Add Student" << endl;
cout << "2. Display All Students" << endl;
cout << "3. Search Student by ID" << endl;
cout << "4. Search Student by Name" << endl;
cout << "5. Edit Student" << endl;
cout << "6. Delete Student" << endl;
cout << "7. Exit" << endl;
cout << "Enter your choice: ";
cin >> choice;

if(choice == 1) {
    addStudent();
} else if (choice == 2) {
    displayAllStudents();
} else if (choice == 3) {
    int id;
    cout << "Enter Student ID to search: ";
    cin >> id;
    searchStudentById(id);

}
else if (choice == 4) {
    string name;
    cout << "Enter Student Name to search: ";
    cin >> name;
    searchStudentByName(name);
} else if (choice == 5) {
    int id;
    cout << "Enter Student ID to edit: ";
    cin >> id;
    editStudent(id);
} else if (choice == 6) {
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;
    deleteStudent(id);
} else if (choice != 7) {
    cout << "Invalid choice, please try again." << endl;
}

} while(choice != 7);

cout << "Goodbye!" << endl;
return 0;
}