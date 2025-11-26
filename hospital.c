#include <stdio.h>
#include <string.h>
#define MAX_PATIENTS 100
#define MAX_DOCTORS 50
#define MAX_APPOINTMENTS 100
#define MAX_BILLS 100
#define MAX_SERVICES 10

struct Patient
{
    int id;
    char name[50];
    int age;
    char disease[50];
    float billAmount;
};

struct Doctor
{
    int id;
    char name[50];
    char specialty[50];
};

struct Appointment
{
    int patientId;
    int doctorId;
    char date[20];
};

struct Service
{
    char name[50];
    float cost;
};

struct Bill
{
    int patientId;
    struct Service services[MAX_SERVICES];
    int serviceCount;
    float totalAmount;
    float amountPaid;
};

struct Patient patients[MAX_PATIENTS];
struct Doctor doctors[MAX_DOCTORS];
struct Appointment appointments[MAX_APPOINTMENTS];
struct Bill bills[MAX_BILLS];
struct Service services[] =
{
    {"Consultation", 100.0},
    {"Room Charge", 200.0},
    {"Medicine", 50.0},
    {"Surgery", 500.0}
};
void addPatient();
void displayPatients();
void deletePatient();
void addDoctor();
void displayDoctors();
void deleteDoctor();
void bookAppointment();
void displayAppointments();
void cancelAppointment();
void addBill();
void viewBill();
void generateReports();

int main()
{
    int choice;

    while (1)
    {
        printf("\n----- Hospital Management System -----\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Delete Patient\n");
        printf("4. Add Doctor\n");
        printf("5. Display Doctors\n");
        printf("6. Delete Doctor\n");
        printf("7. Book Appointment\n");
        printf("8. Display Appointments\n");
        printf("9. Cancel Appointment\n");
        printf("10. Add Bill\n");
        printf("11. View Bill\n");
        printf("12. Generate Reports\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            addPatient();
            break;
        case 2:
            displayPatients();
            break;
        case 3:
            deletePatient();
            break;
        case 4:
            addDoctor();
            break;
        case 5:
            displayDoctors();
            break;
        case 6:
            deleteDoctor();
            break;
        case 7:
            bookAppointment();
            break;
        case 8:
            displayAppointments();
            break;
        case 9:
            cancelAppointment();
            break;
        case 10:
            addBill();
            break;
        case 11:
            viewBill();
            break;
        case 12:
            generateReports();
            break;
        case 13:
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void addPatient()
{
    static int patientId = 1;
    printf("Enter patient name: ");
    scanf("%s", patients[patientId].name);
    printf("Enter patient age: ");
    scanf("%d", &patients[patientId].age);
    printf("Enter patient's disease: ");
    scanf("%s", patients[patientId].disease);
    patients[patientId].id = patientId;
    patients[patientId].billAmount = 0;

    printf("Patient added successfully with ID %d.\n", patientId);
    patientId++;
}
void displayPatients()
{
    printf("\n--- Patient List ---\n");
    for (int i = 1; i < MAX_PATIENTS && patients[i].id != 0; i++)
    {
        printf("ID: %d, Name: %s, Age: %d, Disease: %s, Bill Amount: %.2f\n",
               patients[i].id, patients[i].name, patients[i].age, patients[i].disease, patients[i].billAmount);
    }
}

void deletePatient()
{
    int id;
    printf("Enter patient ID to delete: ");
    scanf("%d", &id);
    if (patients[id].id != 0)
    {
        patients[id].id = 0;
        printf("Patient record deleted.\n");
    }
    else
    {
        printf("Patient not found.\n");
    }
}

void addDoctor()
{
    static int doctorId = 1;
    printf("Enter doctor name: ");
    scanf("%s", doctors[doctorId].name);
    printf("Enter doctor specialty: ");
    scanf("%s", doctors[doctorId].specialty);
    doctors[doctorId].id = doctorId;

    printf("Doctor added successfully with ID %d.\n", doctorId);
    doctorId++;
}

void displayDoctors()
{
    printf("\n--- Doctor List ---\n");
    for (int i = 1; i < MAX_DOCTORS && doctors[i].id != 0; i++)
    {
        printf("ID: %d, Name: %s, Specialty: %s\n",
               doctors[i].id, doctors[i].name, doctors[i].specialty);
    }
}
void deleteDoctor()
{
    int id;
    printf("Enter doctor ID to delete: ");
    scanf("%d", &id);
    if (doctors[id].id != 0)
    {
        doctors[id].id = 0;
        printf("Doctor record deleted.\n");
    }
    else
    {
        printf("Doctor not found.\n");
    }
}

void bookAppointment()
{
    int patientId, doctorId;
    char date[20];
    printf("Enter patient ID: ");
    scanf("%d", &patientId);
    printf("Enter doctor ID: ");
    scanf("%d", &doctorId);
    printf("Enter appointment date (DD/MM/YYYY): ");
    scanf("%s", date);

    appointments[patientId].patientId = patientId;
    appointments[patientId].doctorId = doctorId;
    strcpy(appointments[patientId].date, date);

    printf("Appointment booked for patient %d with doctor %d on %s.\n", patientId, doctorId, date);
}

void displayAppointments()
{
    printf("\n--- Appointment List ---\n");
    for (int i = 0; i < MAX_APPOINTMENTS; i++)
    {
        if (appointments[i].patientId != 0)
        {
            printf("Patient ID: %d, Doctor ID: %d, Date: %s\n",
                   appointments[i].patientId, appointments[i].doctorId, appointments[i].date);
        }
    }
}

void cancelAppointment()
{
    int patientId;
    printf("Enter patient ID to cancel appointment: ");
    scanf("%d", &patientId);
    if (appointments[patientId].patientId != 0)
    {
        appointments[patientId].patientId = 0;
        printf("Appointment cancelled for patient %d.\n", patientId);
    }
    else
    {
        printf("No appointment found for this patient.\n");
    }
}

void addBill()
{
    int patientId;
    printf("Enter patient ID to generate bill: ");
    scanf("%d", &patientId);

    if (patients[patientId].id == 0)
    {
        printf("Patient not found!\n");
        return;
    }

    struct Bill *bill = &bills[patientId];
    bill->patientId = patientId;
    bill->serviceCount = 0;
    bill->totalAmount = 0;
    bill->amountPaid = 0;

    printf("Select services for the bill:\n");
    for (int i = 0; i < sizeof(services)/sizeof(services[0]); i++)
    {
        printf("%d. %s (%.2f)\n", i + 1, services[i].name, services[i].cost);
    }

    int serviceChoice;
    while (1)
    {
        printf("Enter service number to add (0 to stop): ");
        scanf("%d", &serviceChoice);
        if (serviceChoice == 0) break;
        if (serviceChoice < 1 || serviceChoice > sizeof(services)/sizeof(services[0]))
        {
            printf("Invalid service. Try again.\n");
            continue;
        }

        bill->services[bill->serviceCount] = services[serviceChoice - 1];
        bill->totalAmount += services[serviceChoice - 1].cost;
        bill->serviceCount++;
    }

    patients[patientId].billAmount = bill->totalAmount;
    printf("Bill generated with total amount: %.2f\n", bill->totalAmount);
}

void viewBill()
{
    int patientId;
    printf("Enter patient ID to view bill: ");
    scanf("%d", &patientId);

    if (bills[patientId].patientId == 0)
    {
        printf("No bill found for this patient.\n");
        return;
    }

    struct Bill *bill = &bills[patientId];
    printf("\n--- Bill for Patient %d ---\n", patientId);
    for (int i = 0; i < bill->serviceCount; i++)
    {
        printf("Service: %s, Cost: %.2f\n", bill->services[i].name, bill->services[i].cost);
    }
    printf("Total Amount: %.2f\n", bill->totalAmount);
    printf("Amount Paid: %.2f\n", bill->amountPaid);
    printf("Outstanding Amount: %.2f\n", bill->totalAmount - bill->amountPaid);
}


void generateReports()
{
    printf("\n--- Generating Reports ---\n");
    displayPatients();
    displayDoctors();
    displayAppointments();
    printf("\n--- Bills Report ---\n");
    for (int i = 0; i < MAX_BILLS; i++)
    {
        if (bills[i].patientId != 0)
        {
            printf("Patient ID: %d, Total Bill: %.2f, Amount Paid: %.2f\n",
                   bills[i].patientId, bills[i].totalAmount, bills[i].amountPaid);
        }
    }
}
