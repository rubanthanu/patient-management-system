#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define NAME_LENGTH 50
#define ADDRESS_LENGTH 100
#define HISTORY_LENGTH 200

// Structure for a patient record
typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
    char gender;
    char address[ADDRESS_LENGTH];
    char contact[15];
    char medicalHistory[HISTORY_LENGTH];
} Patient;

// Function prototypes
void addPatient(Patient patients[], int *count);
void viewPatients(const Patient patients[], int count);
void searchPatient(const Patient patients[], int count);
void updatePatient(Patient patients[], int count);
void deletePatient(Patient patients[], int *count);
void saveToFile(const Patient patients[], int count, const char *filename);
void loadFromFile(Patient patients[], int *count, const char *filename);

int main() {
    Patient patients[MAX_PATIENTS];
    int patientCount = 0;
    int choice;
    const char *filename = "patients.txt";

    // Load existing records
    loadFromFile(patients, &patientCount, filename);

    do {
        printf("\n--- Patient Management System ---\n");
        printf("1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Search Patient\n");
        printf("4. Update Patient\n");
        printf("5. Delete Patient\n");
        printf("6. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPatient(patients, &patientCount); break;
            case 2: viewPatients(patients, patientCount); break;
            case 3: searchPatient(patients, patientCount); break;
            case 4: updatePatient(patients, patientCount); break;
            case 5: deletePatient(patients, &patientCount); break;
            case 6: saveToFile(patients, patientCount, filename); printf("Data saved. Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to add a patient record
void addPatient(Patient patients[], int *count) {
    if (*count >= MAX_PATIENTS) {
        printf("Cannot add more patients. Maximum limit reached.\n");
        return;
    }
    Patient *p = &patients[*count];
    p->id = *count + 1;
    printf("Enter name: ");
    scanf(" %[^\n]", p->name);
    printf("Enter age: ");
    scanf("%d", &p->age);
    printf("Enter gender (M/F): ");
    scanf(" %c", &p->gender);
    printf("Enter address: ");
    scanf(" %[^\n]", p->address);
    printf("Enter contact: ");
    scanf(" %s", p->contact);
    printf("Enter medical history: ");
    scanf(" %[^\n]", p->medicalHistory);

    (*count)++;
    printf("Patient added successfully with ID %d.\n", p->id);
}

// Function to view all patients
void viewPatients(const Patient patients[], int count) {
    if (count == 0) {
        printf("No records available.\n");
        return;
    }
    printf("\n--- Patient Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Age: %d, Gender: %c, Contact: %s\n",
               patients[i].id, patients[i].name, patients[i].age,
               patients[i].gender, patients[i].contact);
    }
}

// Function to search for a patient
void searchPatient(const Patient patients[], int count) {
    int id;
    printf("Enter patient ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (patients[i].id == id) {
            printf("ID: %d, Name: %s, Age: %d, Gender: %c, Address: %s, Contact: %s, Medical History: %s\n",
                   patients[i].id, patients[i].name, patients[i].age, patients[i].gender,
                   patients[i].address, patients[i].contact, patients[i].medicalHistory);
            return;
        }
    }
    printf("Patient not found.\n");
}

// Function to update patient details
void updatePatient(Patient patients[], int count) {
    int id;
    printf("Enter patient ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (patients[i].id == id) {
            printf("Enter new address: ");
            scanf(" %[^\n]", patients[i].address);
            printf("Enter new contact: ");
            scanf(" %s", patients[i].contact);
            printf("Record updated successfully.\n");
            return;
        }
    }
    printf("Patient not found.\n");
}

// Function to delete a patient record
void deletePatient(Patient patients[], int *count) {
    int id, i;
    printf("Enter patient ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < *count; i++) {
        if (patients[i].id == id) {
            break;
        }
    }
    if (i == *count) {
        printf("Patient not found.\n");
        return;
    }

    for (int j = i; j < *count - 1; j++) {
        patients[j] = patients[j + 1];
    }
    (*count)--;
    printf("Patient deleted successfully.\n");
}

// File handling functions
void saveToFile(const Patient patients[], int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%d,%c,%s,%s,%s\n",
                patients[i].id, patients[i].name, patients[i].age, patients[i].gender,
                patients[i].address, patients[i].contact, patients[i].medicalHistory);
    }
    fclose(file);
}

void loadFromFile(Patient patients[], int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("No existing file found. Starting fresh.\n");
        return;
    }
    *count = 0;
    while (fscanf(file, "%d,%[^,],%d,%c,%[^,],%[^,],%[^\n]\n",
                  &patients[*count].id, patients[*count].name, &patients[*count].age,
                  &patients[*count].gender, patients[*count].address, patients[*count].contact,
                  patients[*count].medicalHistory) == 7) {
        (*count)++;
    }
    fclose(file);
}
