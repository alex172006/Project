#include <stdio.h>
struct Employee
{
    int employeeID;
    char name[50];
    float salary;
};

int main()
{
    struct Employee employee1, employee2, employee3;

    printf("Input details for Employee 1:\n");
    printf("Employee ID: ");
    scanf("%d", &employee1.employeeID);
    printf("Name: ");
    scanf("%s", employee1.name);
    printf("Salary: ");
    scanf("%f", &employee1.salary);

    printf("\nInput details for Employee 2:\n");
    printf("Employee ID: ");
    scanf("%d", &employee2.employeeID);
    printf("Name: ");
    scanf("%s", employee2.name);
    printf("Salary: ");
    scanf("%f", &employee2.salary);

    printf("\nInput details for Employee 3:\n");
    printf("Employee ID: ");
    scanf("%d", &employee3.employeeID);
    printf("Name: ");
    scanf("%s", employee3.name);
    printf("Salary: ");
    scanf("%f", &employee3.salary);
    struct Employee highestSalaryEmployee;
    if (employee1.salary >= employee2.salary && employee1.salary >= employee3.salary)
    {
        highestSalaryEmployee = employee1;
    }
    else if (employee2.salary >= employee1.salary && employee2.salary >= employee3.salary)
    {
        highestSalaryEmployee = employee2;
    }
    else
    {
        highestSalaryEmployee = employee3;
    }
    printf("\nEmployee with the Highest Salary:\n");
    printf("Employee ID: %d\n", highestSalaryEmployee.employeeID);
    printf("Name: %s\n", highestSalaryEmployee.name);
    printf("Salary: %.2f\n", highestSalaryEmployee.salary);

    return 0;
}
