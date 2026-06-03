#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient
{ // Patient Structure
    int id;
    char name[30];
    int age;
    char phone[10];
};

struct Appointment
{
    int pid;
    char doctor[30];
};

struct Login
{
    char username[30];
    char password[30];
};

// Files used: Admin_Login_Password.txt, Patient_Login_Password.txt, patients.txt, appointments.txt

void bookAppointment()
{ // Patient Department.

    FILE *fp, *fp1; // File pointer for writing and reading appointments.

    struct Appointment a; // Appointment structure variable.
    struct Appointment a1;

    fp = fopen("appointments.txt", "a"); // Open file for appending new appointments.
    rewind(fp);                          // Reset the file pointer to the beginning of the file for reading existing appointments.

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Patient ID: ");
    scanf("%d", &a.pid); // Get patient ID from user input.
    printf("Enter Doctor Name: ");
    scanf("%s", a.doctor);

    while (1)
    { // Loop to check if the entered patient ID already has an appointment booked.
        int fleg = 0;

        while (fscanf(fp, "%d %s", &a1.pid, a1.doctor) != EOF)
        {

            if (a1.pid == a.pid)
            { // If patient ID already exists in the appointments file, prompt user to enter a new ID and doctor name.
                printf("!!!!!!! Id Already Exist. Please Try Again With New Id.!!!!!!!\n");

                printf("Enter Patient ID: ");
                scanf("%d", &a.pid);
                printf("Enter Doctor Name: ");
                scanf("%s", a.doctor);
                fleg = 1;   //
                rewind(fp); // Reset the file pointer to the beginning of the file for the next iteration of checking.
                break;
            }
        }

        if (fleg == 0)
        {
            break; // If patient ID does not exist in the appointments file, exit the loop and proceed to book the appointment.
        }
    }

    fprintf(fp, "%d %s\n", a.pid, a.doctor); // Write the new appointment details to the file.
    fclose(fp);

    printf("\n----- Appointment Booked Successfully.-----\n");
}

void viewAppointments()
{

    FILE *fp;
    struct Appointment a;

    fp = fopen("appointments.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("\n--- Appointments ---\n");

    while (fscanf(fp, "%d %s", &a.pid, a.doctor) != EOF)
    { // Read each appointment from the file and display it.
        printf("Patient ID:%d   Doctor:%s\n", a.pid, a.doctor);
    }

    fclose(fp);
}

void patientMenu()
{
    int ch;

    while (1)
    {
        printf("\n--- Patient Menu ---\n");
        printf("1. Book Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Logout\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            bookAppointment();
            break;
        case 2:
            viewAppointments();
            break;
        case 3:
            return;
        default:
            printf("Invalid\n");
        }
    }
}

// Admin Department.

void cancelAppointments()
{
    FILE *fp, *tempfp;
    struct Appointment a;

    fp = fopen("appointments.txt", "r");
    tempfp = fopen("tempappointments.txt", "w");

    if (fp == NULL || tempfp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    int askId;
    printf("Enter Patient Id : ");
    scanf("%d", &askId);

    while (fscanf(fp, "%d %s", &a.pid, a.doctor) != EOF)
    {
        if (askId != a.pid)
        { // If the patient ID does not match the ID to be canceled, write the appointment details to the temporary file. This effectively removes the appointment with the specified patient ID from the appointments file.
            fprintf(tempfp, "%d %s\n", a.pid, a.doctor);
        }
    }

    fclose(fp);
    fclose(tempfp);

    remove("appointments.txt");
    rename("tempappointments.txt", "appointments.txt");

    printf("\n----- Appointment Canceld Successfully.-----\n");
}

void removePatients()
{
    FILE *fp, *tempfp;
    struct Patient p;

    fp = fopen("patients.txt", "r");
    tempfp = fopen("temppatients.txt", "w");

    if (fp == NULL || tempfp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    int askId;
    printf("Enter Patient Id : ");
    scanf("%d", &askId);

    while (fscanf(fp, "%d %s %d %s", &p.id, p.name, &p.age, p.phone) != EOF)
    {
        if (askId != p.id)
        { // If the patient ID does not match the ID to be removed, write the patient details to the temporary file. This effectively removes the patient with the specified ID from the patients file.
            fprintf(tempfp, "%d %s %d %s\n", p.id, p.name, p.age, p.phone);
        }
    }

    fclose(fp);
    fclose(tempfp);

    remove("patients.txt");
    rename("temppatients.txt", "patients.txt");

    printf("\n----- Patient removed Successfully.-----\n");
}

void searchPatient()
{
    FILE *fp;
    struct Patient p;

    fp = fopen("patients.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    int askId;
    printf("Enter Patient Id : ");
    scanf("%d", &askId);

    printf("\n--- Patients ---\n");

    int fleg = 0;
    while (fscanf(fp, "%d %s %d %s", &p.id, p.name, &p.age, p.phone) != EOF)
    {
        if (askId == p.id)
        { // If the patient ID matches the ID being searched for, display the patient details and set the flag to indicate that a match was found.
            printf("ID:%d   Name:%s   Age:%d   PhoneNumber:%s\n", p.id, p.name, p.age, p.phone);
            fleg = 1;
            break;
        }
    }

    if (fleg == 0)
        printf("!!!!!! Invalied Patient Id.!!!!!!\n"); // If no match was found after reading through the entire file, display a message indicating that the patient ID is invalid.

    fclose(fp);
}

void viewPatients()
{
    FILE *fp;
    struct Patient p;

    fp = fopen("patients.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("\n--- Patients ---\n");

    while (fscanf(fp, "%d %s %d %s", &p.id, p.name, &p.age, p.phone) != EOF)
    {
        printf("ID:%d   Name:%s   Age:%d   PhoneNumber:%s\n---------------------------------------------------\n", p.id, p.name, p.age, p.phone);
    }

    fclose(fp);
}

void addPatient()
{
    FILE *fp, *fp1;
    struct Patient p;
    struct Patient p1;

    fp = fopen("patients.txt", "a");
    fp1 = fopen("patients.txt", "r");

    if (fp == NULL || fp1 == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter ID Name Age PhoneNumber: "); // Prompt the user to enter the patient's ID, name, age, and phone number.
    scanf("%d %s %d %s", &p.id, p.name, &p.age, p.phone);

    while (1)
    {
        int fleg = 0;

        while (fscanf(fp1, "%d %s %d %s", &p1.id, p1.name, &p1.age, p1.phone) != EOF)
        {

            if (p1.id == p.id)
            { // If the entered patient ID already exists in the patients file, prompt the user to enter a new ID and patient details, and set the flag to indicate that a duplicate ID was found.
                printf("!!!!! Warning Id Alredady Exist Please Try Again With new Id !!!!! \n");
                printf("Enter ID Name Age PhoneNumber: ");
                scanf("%d %s %d %s", &p.id, p.name, &p.age, p.phone);
                fleg = 1;
                break;
            }
        }
        if (fleg == 0)
            break; // If no duplicate ID was found after reading through the entire file, exit the loop and proceed to add the new patient details to the file.
        rewind(fp1);
    }

    fprintf(fp, "%d %s %d %s\n", p.id, p.name, p.age, p.phone); // Write the new patient details to the patients file.

    fclose(fp);
    fclose(fp1);

    printf("\n----- Patient Added Successfully.-----\n");
}

void adminMenu()
{
    int ch;

    while (1)
    {
        printf("\n--- Admin Menu ---\n");
        printf("1. Add Patient\n");
        printf("2. View All Patients\n");
        printf("3. Search Patients\n");
        printf("4. View Appointments\n");
        printf("5. Remove Patient\n");
        printf("6. Cancel Appointments\n");
        printf("7. Logout\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            addPatient();
            break;
        case 2:
            viewPatients();
            break;
        case 3:
            searchPatient();
            break;
        case 4:
            viewAppointments();
            break;
        case 5:
            removePatients();
            break;
        case 6:
            cancelAppointments();
            break;
        case 7:
            return;
        default:
            printf("Invalid\n");
        }
    }
}

int LoginPermision(char user[30], char pass[30], char filename[30])
{

    FILE *fp;
    struct Login l;

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 0;
    }

    while (fscanf(fp, "%s %s", l.username, l.password) != EOF)
    {
        if (strcmp(user, l.username) == 0 && strcmp(pass, l.password) == 0)
        { // If the entered username and password match a record in the specified login file, return 1 to indicate successful login.
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    return 0;
}

int main()
{
    int choice;
    int r;
    while (1)
    {
        printf("\n#### Dashboard #####\n");
        printf("1. Admin Login\n");
        printf("2. Patient Login\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
        {
            char user[30], pass[30];

            printf("Enter username: ");
            scanf("%s", user);
            printf("Enter password: ");
            scanf("%s", pass);

            r = LoginPermision(user, pass, "Admin_Login_Password.txt"); // Check if the entered admin username and password are valid by calling the LoginPermision function with the admin login file.

            if (r == 1)
            {
                adminMenu();
            }
            else
                printf("\n !!!! Invalied AdminName or Password\n");
            break;
        }

        case 2:
        {
            char us[30], pa[30];

            printf("Enter username: ");
            scanf("%s", us);
            printf("Enter password: ");
            scanf("%s", pa);
            
            int r = LoginPermision(us, pa, "Patient_Login_Password.txt");

            if (r == 1)
            {
                patientMenu();
            }
            else
                printf("\n !!!! Invalied PatientName or Password\n");
            break;
        }
        case 3:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}