#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATIENT_FILE "patients.dat"
#define DOCTOR_FILE "doctors.dat"
#define APPOINT_FILE "appointments.dat"

// ========== STRUCTURES ==========
struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
};

struct Doctor {
    int id;
    char name[50];
    char specialization[50];
};

struct Appointment {
    int patient_id;
    int doctor_id;
    char date[20];
};

// ========== FUNCTION DECLARATIONS ==========
void addPatient();
void viewPatients();
void searchPatient();
void updatePatient();
void deletePatient();

void addDoctor();
void viewDoctors();
void searchDoctor();

void bookAppointment();
void viewAppointments();

int generateID(char *filename, int size);

// ==========================================
int main() {
    int choice;

    while (1) {
        printf("\n===============================\n");
        printf("      HOSPITAL MANAGEMENT\n");
        printf("===============================\n");
        printf("1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Search Patient\n");
        printf("4. Update Patient\n");
        printf("5. Delete Patient\n");
        printf("6. Add Doctor\n");
        printf("7. View Doctors\n");
        printf("8. Search Doctor\n");
        printf("9. Book Appointment\n");
        printf("10. View Appointments\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: searchPatient(); break;
            case 4: updatePatient(); break;
            case 5: deletePatient(); break;
            case 6: addDoctor(); break;
            case 7: viewDoctors(); break;
            case 8: searchDoctor(); break;
            case 9: bookAppointment(); break;
            case 10: viewAppointments(); break;
            case 11: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}

// ========== GENERATE UNIQUE ID ==========
int generateID(char *filename, int size) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return 1;

    int maxID = 0;
    void *record = malloc(size);

    while (fread(record, size, 1, fp))
        maxID++;

    free(record);
    fclose(fp);

    return maxID + 1;
}

// ========== PATIENT FUNCTIONS ==========
void addPatient() {
    struct Patient p;
    FILE *fp = fopen(PATIENT_FILE, "ab");

    p.id = generateID(PATIENT_FILE, sizeof(struct Patient));

    printf("Enter Name: ");
    fgets(p.name, 50, stdin);
    p.name[strcspn(p.name, "\n")] = 0;

    printf("Enter Age: ");
    scanf("%d", &p.age);
    getchar();

    printf("Enter Disease: ");
    fgets(p.disease, 50, stdin);
    p.disease[strcspn(p.disease, "\n")] = 0;

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);

    printf("Patient added successfully! ID: %d\n", p.id);
}

void viewPatients() {
    FILE *fp = fopen(PATIENT_FILE, "rb");
    struct Patient p;

    if (!fp) {
        printf("No patient records found.\n");
        return;
    }

    printf("\n---- Patient List ----\n");
    while (fread(&p, sizeof(p), 1, fp)) {
        printf("\nID : %d\n", p.id);
        printf("Name : %s\n", p.name);
        printf("Age : %d\n", p.age);
        printf("Disease : %s\n", p.disease);
    }
    fclose(fp);
}

void searchPatient() {
    FILE *fp = fopen(PATIENT_FILE, "rb");
    struct Patient p;
    int id, found = 0;

    if (!fp) {
        printf("No patient records.\n");
        return;
    }

    printf("Enter Patient ID: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            printf("\n---- Patient Found ----\n");
            printf("ID: %d\n", p.id);
            printf("Name: %s\n", p.name);
            printf("Age: %d\n", p.age);
            printf("Disease: %s\n", p.disease);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found) printf("Patient Not Found.\n");
}

void updatePatient() {
    FILE *fp = fopen(PATIENT_FILE, "rb+");
    struct Patient p;
    int id, found = 0;

    if (!fp) {
        printf("No data.\n");
        return;
    }

    printf("Enter Patient ID to Update: ");
    scanf("%d", &id);
    getchar();

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            found = 1;

            printf("Enter New Name: ");
            fgets(p.name, 50, stdin);
            p.name[strcspn(p.name, "\n")] = 0;

            printf("Enter New Age: ");
            scanf("%d", &p.age);
            getchar();

            printf("Enter New Disease: ");
            fgets(p.disease, 50, stdin);
            p.disease[strcspn(p.disease, "\n")] = 0;

            fseek(fp, -sizeof(p), SEEK_CUR);
            fwrite(&p, sizeof(p), 1, fp);

            printf("Updated Successfully!\n");
            break;
        }
    }

    fclose(fp);
    if (!found) printf("Patient Not Found.\n");
}

void deletePatient() {
    FILE *fp = fopen(PATIENT_FILE, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct Patient p;
    int id, found = 0;

    if (!fp) {
        printf("No patient data.\n");
        return;
    }

    printf("Enter Patient ID to Delete: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id != id) {
            fwrite(&p, sizeof(p), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove(PATIENT_FILE);
    rename("temp.dat", PATIENT_FILE);

    if (found) printf("Patient Deleted.\n");
    else printf("Patient Not Found.\n");
}

// ========== DOCTOR FUNCTIONS ==========
void addDoctor() {
    struct Doctor d;
    FILE *fp = fopen(DOCTOR_FILE, "ab");

    d.id = generateID(DOCTOR_FILE, sizeof(struct Doctor));

    printf("Enter Doctor Name: ");
    fgets(d.name, 50, stdin);
    d.name[strcspn(d.name, "\n")] = 0;

    printf("Enter Specialization: ");
    fgets(d.specialization, 50, stdin);
    d.specialization[strcspn(d.specialization, "\n")] = 0;

    fwrite(&d, sizeof(d), 1, fp);
    fclose(fp);

    printf("Doctor added successfully! ID: %d\n", d.id);
}

void viewDoctors() {
    FILE *fp = fopen(DOCTOR_FILE, "rb");
    struct Doctor d;

    if (!fp) {
        printf("No doctor data.\n");
        return;
    }

    printf("\n---- Doctor List ----\n");
    while (fread(&d, sizeof(d), 1, fp)) {
        printf("\nID : %d\n", d.id);
        printf("Name : %s\n", d.name);
        printf("Specialization : %s\n", d.specialization);
    }
    fclose(fp);
}

void searchDoctor() {
    FILE *fp = fopen(DOCTOR_FILE, "rb");
    struct Doctor d;
    int id, found = 0;

    if (!fp) {
        printf("No doctors found.\n");
        return;
    }

    printf("Enter Doctor ID: ");
    scanf("%d", &id);

    while (fread(&d, sizeof(d), 1, fp)) {
        if (d.id == id) {
            printf("\n---- Doctor Found ----\n");
            printf("ID: %d\n", d.id);
            printf("Name: %s\n", d.name);
            printf("Specialization: %s\n", d.specialization);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) printf("Doctor Not Found.\n");
}

// ========== APPOINTMENTS ==========
void bookAppointment() {
    struct Appointment a;
    FILE *fp = fopen(APPOINT_FILE, "ab");

    printf("Enter Patient ID: ");
    scanf("%d", &a.patient_id);

    printf("Enter Doctor ID: ");
    scanf("%d", &a.doctor_id);
    getchar();

    printf("Enter Appointment Date (DD-MM-YYYY): ");
    fgets(a.date, 20, stdin);
    a.date[strcspn(a.date, "\n")] = 0;

    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);

    printf("Appointment Booked Successfully!\n");
}

void viewAppointments() {
    struct Appointment a;
    FILE *fp = fopen(APPOINT_FILE, "rb");

    if (!fp) {
        printf("No appointments found.\n");
        return;
    }

    printf("\n---- Appointments ----\n");
    while (fread(&a, sizeof(a), 1, fp)) {
        printf("\nPatient ID : %d\n", a.patient_id);
        printf("Doctor ID  : %d\n", a.doctor_id);
        printf("Date       : %s\n", a.date);
    }

    fclose(fp);
}
