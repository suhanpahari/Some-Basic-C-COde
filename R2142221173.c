#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
  char name[50];
  int id;
  char phone[20];
  char email[50];
  float salary;
};

struct Employee employees[MAX_EMPLOYEES];
int numEmployees = 0;

void addEmployee() {
  if (numEmployees >= MAX_EMPLOYEES) {
    printf("Error: cannot add more employees. Maximum number of employees reached.\n");
    return;
  }

  printf("Enter employee name: ");
  scanf("%s", employees[numEmployees].name);
  printf("Enter employee ID: ");
  scanf("%d", &employees[numEmployees].id);
  printf("Enter employee phone number: ");
  scanf("%s", employees[numEmployees].phone);
  printf("Enter employee email: ");
  scanf("%s", employees[numEmployees].email);
  printf("Enter employee salary: ");
  scanf("%f", &employees[numEmployees].salary);

  numEmployees++;
}

void searchEmployee() {
  int id;
  printf("Enter employee ID to search: ");
  scanf("%d", &id);

  int i;
  for (i = 0; i < numEmployees; i++) {
    if (employees[i].id == id) {
      printf("Employee name: %s\n", employees[i].name);
      printf("Employee ID: %d\n", employees[i].id);
      printf("Employee phone number: %s\n", employees[i].phone);
      printf("Employee email: %s\n", employees[i].email);
      printf("Employee salary: %.2f\n", employees[i].salary);
      return;
    }
  }

  printf("Error: employee not found.\n");
}

float totalSalary() {
  float total = 0;
  int i;
  for (i = 0; i < numEmployees; i++) {
    total += employees[i].salary;
  }
  return total;
}

void displayEmployees() {
  int i;
  for (i = 0; i < numEmployees; i++) {
    printf("Employee name: %s\n", employees[i].name);
    printf("Employee ID: %d\n", employees[i].id);
    printf("Employee phone number: %s\n", employees[i].phone);
    printf("Employee email: %s\n", employees[i].email);
    printf("Employee salary: %.2f\n", employees[i].salary);
    printf("\n");
  }
}

void deleteEmployee() {
  int id;
  printf("Enter employee ID to delete: ");
  scanf("%d", &id);

  int i;
  for (i = 0; i < numEmployees; i++) {
    if
(employees[i].id == id) {
      int j;
      for (j = i; j < numEmployees - 1; j++) {
        employees[j] = employees[j + 1];
      }
      numEmployees--;
      printf("Employee with ID %d deleted successfully.\n", id);
      return;
    }
  }

  printf("Error: employee not found.\n");
}

int main() {
  int choice;
  do {
    printf("\n");
    printf("Employee Record System\n");
    printf("1. Add employee\n");
    printf("2. Search employee\n");
    printf("3. Display total salary of all employees\n");
    printf("4. Display all employees\n");
    printf("5. Delete employee\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        addEmployee();
        break;
      case 2:
        searchEmployee();
        break;
      case 3:
        printf("Total salary of all employees: %.2f\n", totalSalary());
        break;
      case 4:
        displayEmployees();
        break;
      case 5:
        deleteEmployee();
        break;
      case 6:
        printf("Exiting program...\n");
        break;
      default:
        printf("Error: invalid choice.\n");
        break;
    }
  } while (choice != 6);

  return 0;
}