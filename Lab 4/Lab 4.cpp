#include <stdio.h>

int main() {
    int employeesid = 0;
    int workinghrs = 0;
    int Salaryamounthr = 0;
    printf("Enter your Employees_ID: ");
    scanf("%d", &employeesid);
    printf("Enter your the working hrs: ");
    scanf("%d", &workinghrs);
    printf("Enter Salary amount/hr:");
    scanf("%d", &Salaryamounthr);
    printf("Salary amount/hr: %d\n", workinghrs*Salaryamounthr);
    return 0; 
}
