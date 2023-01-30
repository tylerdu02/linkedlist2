/*
 * Tyler Du
 * 1/29/21
 * Linked lists part 2. Based off student list, but using a peer's code. Cannot use vectors.
 */

#include "Node.h"
#include "Student.h"
#include <cstring>
#include <iostream>

using namespace std;

void addStudent(Node* head, Node* newNode);
void print(Node* head);
void deleteStudent(int id, Node* head);
void average(float total, int numOfStudents, Node* head);

int main() {
  Node* head = NULL;
  char input[10];
  bool running = true;

  while (running == true) {
    cout << "Add, Print, Delete, Average, Quit." << endl;

    cin.get(input, 10);
    cin.ignore(1, '\n');

    if (input[1] == 'D' || input[1] == 'd') {
      char firstName[20];
      char lastName[20];
      int studentID = 0;
      float gpa = 0.0;
      Student* newStudent = new Student(firstName, lastName, studentID, gpa);
      
      // reads first name
      cout << "First Name: " << endl;
      cin.get(firstName, 20);
      cin.ignore(1, '\n');
      newStudent->set_first_name(firstName);

      // reads last name
      cout << "Last Name: " << endl;
      cin.get(lastName, 20);
      cin.ignore(1, '\n');
      newStudent->set_last_name(lastName);

      // reads student id
      cout << "Student ID: " << endl;
      cin >> studentID;
      cin.ignore();
      newStudent->set_id(studentID);

      // reads gpa
      cout << "GPA: " << endl;
      cin >> gpa;
      cin.ignore();
      newStudent->set_gpa(gpa);

      Node* newNode = new Node(newStudent);

      if (head == NULL) { 
        head = newNode;
        newNode->setNext(NULL);
      }
      else if (newNode->getStudent()->get_id() < head->getStudent()->get_id()) { 
        newNode->setNext(head);
        head = newNode;
      }
      else {
        addStudent(head, newNode);
      }
    }
    else if (input[1] == 'R' || input[1] == 'r') { 
      print(head);
    }
    else if (input[2] == 'L' || input[2] == 'l') { 
      int id;

      cout << "Enter student's ID you want to delete" << endl;
      cin >> id;
      cin.ignore(1, '\n');

      deleteStudent(id, head);
    }
    else if (input[1] == 'V' || input[1] == 'v') { 
      float total = 0.0;
      int numOfStudents = 0;

      total += head->getStudent()->get_gpa();
      numOfStudents++;
      average(total, numOfStudents, head);
    }
    else if (input[0] == 'Q' || input[0] == 'q') { 
      running = false;
    }
    else {
      cout << "Not Sure What You're Trying To Do" << endl;
    }
  }  
  return 0;
}
  
