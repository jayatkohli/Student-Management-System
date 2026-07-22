#include <iostream>
#include <string>

using namespace std;

string names[50];
int roll_no[50];
float marks[50];
int totalStudent = 0;

void addStudent(){
    if(totalStudent==5)
    {
        cout<<"Database Full!\n";
        return;
    }

    cout << "===== Adding Student ====="<<endl;
    cout << "Enter name : ";
    cin.ignore();
    getline(cin,names[totalStudent]);
    cout << "Enter roll number : ";
    cin >> roll_no[totalStudent];
    cout << "Enter marks : ";
    cin >> marks[totalStudent] ;
    totalStudent++;
    cout << "Details have been added"<<endl;
    cout << "--------------------------" << endl;
}

void searchStudent()
{
    int y,i;
    cout << "===== Searching Student ====="<<endl;
    cout << "Enter Roll number to search : ";
    cin >> y ;
    for (i = 0; i < totalStudent; i++)
    {
        if (y == roll_no[i])
        {
            cout << "Name of student : "<< names[i]<<endl;
            cout << "Marks : "<< marks[i]<<endl;
            cout << "Roll number : "<< roll_no[i]<<endl;
            break;
        }
    }
    if (i == totalStudent)
    {
        cout << "Student not found!\n";
        return;
    }
    cout << "--------------------------" << endl;
}

void viewStudents()
{
    if (totalStudent == 0)
    {
        cout << "No students found.\n";
        return;
    }

    cout << "\n===== STUDENT DETAILS =====\n";

    for (int i = 0; i < totalStudent; i++)
    {
        cout << "Student " << i + 1 << endl;
        cout << "Name : " << names[i] << endl;
        cout << "Roll No : " << roll_no[i] << endl;
        cout << "Marks : " << marks[i] << endl;
        cout << "--------------------------" << endl;
    }
}

void updateStudent()
{
    int z,i,y;
    cout << "===== Updating Student Info ====="<<endl;
    cout << "Enter Roll number to update : ";
    cin >> y ;
    for (i = 0; i < totalStudent; i++)
    {
        if (y == roll_no[i])
        {
            cout << "Name of student : "<< names[i]<<endl;
            cout << "Marks : "<< marks[i]<<endl;
            cout << "Roll number : "<< roll_no[i]<<endl;
            break;
        }
    }
    if (i == totalStudent)
    {
        cout << "Student not found!\n";
        return;
    }
    cout << "Enter which detail to change : (1-3) " << endl;
    cout << "1. Name  2. Marks   3. Roll no" << endl;
    cin >> z;
    if (z == 1)
    {
        cout << "Enter new name : ";
        cin >> names[i];
    }
    
    else if (z == 2)
    {
        cout << "Enter new marks : ";
        cin >> marks[i];
    }
    else if (z == 3)
    {
        cout << "Enter new roll number : ";
        cin >> roll_no[i];
    }
    else
    {
        cout << "Enter a valid choice !!";
    }
    cout << "Details have been Updated"<<endl;
    cout << "--------------------------" << endl;
}

void studentDelete()
{
    int d,i,j;
    cout << "===== Deleting Student Info =====" << endl;
    cout << "Enter which roll number to delete : ";
    cin >> d;
    for (i = 0; i < totalStudent; i++)
    {
        if (d == roll_no[i])
        {
            for ( j = i; j < totalStudent - 1; j++)
            {
                names[j] = names[j + 1];
                marks[j] = marks[j + 1];
                roll_no[j] = roll_no[j + 1];
            }
        }
        else
        {
            continue;
        }
    }
    totalStudent --;
    cout << "The Student info has been deleted "<<endl;
    cout << "--------------------------" << endl;

}


void avgMarks()
{
    cout << "===== Average Marks ====="<<endl;
    int i;
    float avg;
    float sum = 0;

    if(totalStudent==0)
    {
        cout<<"No students found.";
        return;
    }

    for ( i = 0; i < totalStudent; i++)
    {
        sum = sum + marks[i];
    }
    avg = sum/totalStudent;
    cout << "Average marks = " << avg <<endl;
    cout << "--------------------------" << endl;
}


void Topper()
{
    cout << "===== Class Topper ====="<<endl;
    float high = 0;
    int i,roll;
    string name;
    if(totalStudent==0)
    {
        cout<<"No students found.";
        return;
    }

    for (i = 0; i < totalStudent; i++)
    {
        if(marks[i] > high)
        {
            high = marks[i];
            name = names[i];
            roll = roll_no[i];
        }
        else
        {
            continue;
        }
    }
    
    cout << "The Topper of the class is " << name << "Roll number : "<< roll <<endl;
    cout << "Scoring the maximum marks : " << high << endl ;
    cout << "--------------------------" << endl;

}



int main()
{
    int x;
    int z;
    while (true)
    {
        cout << "===== STUDENT MANAGEMENT SYSTEM =====" << endl;
        cout << "1. View All Students " << endl;
        cout << "2. Search Students " << endl;
        cout << "3. Update Student Info " << endl;
        cout << "4. Delete Student Info " << endl;
        cout << "5. Calculate Average Marks " << endl;
        cout << "6. Display Topper " << endl;
        cout << "7. Add Student " << endl;
        cout << "8. Exit " << endl;

        cout << "Enter your choice (1-8) : ";
        cin >> x;

        if (x == 1)
        {
            viewStudents();
        }

        else if (x == 2)
        {
            searchStudent();
        }

        else if (x == 3)
        {
            updateStudent();   
        }

        else if (x == 4)
        {
            studentDelete();
        }

        else if (x == 5)
        {
            avgMarks();
        }

        else if (x == 6)
        {
            Topper();
        }

        else if (x == 7)
        {
            addStudent();
        }

        else if (x == 8)
        {
            cout << "BYE BYE !!";
            break;
        }

        else
        {
            cout << "Enter a valid choice from 1 to 8 ";
        }

    }
    return 0 ;
}
