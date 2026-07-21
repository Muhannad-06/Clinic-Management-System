#include "STD_TYPES.h"
#include "Models.h"

struct Admin admin = {.userName = "admin", .password = "admin123"};
struct Patient DefaultPatient[MAX_NUMBER_OF_PATIENTS];

/* Pointer to the last patient in the linked list hayfedni fe el searching */
struct Patient* TAILPTR = NULL;

/* Holds the latest ID */
u16 lastID = 2026010;

/* Intialize Some Patients */
void IntializePatients(){
    DefaultPatient[0] = (struct Patient){.ID = 2026001, .Name = "Mohannad", .Age = 20, .ClinicName = "Dentistry", .nxtAPP = {.clinicName = "Dentisry", .patientID = 2026001, .day = 25, .month = 7, .Time = 16}, .MedicalRecord = "No chronic conditions", .NEXT = &DefaultPatient[1]};
    DefaultPatient[1] = (struct Patient){.ID = 2026002, .Name = "Ahmed", .Age = 25, .ClinicName = "Pediatrics", .nxtAPP = {.clinicName = "Dentisry", .patientID = 2026001, .day = 25, .month = 7, .Time = 16}, .MedicalRecord = "Allergic to Penicillin", .NEXT = &DefaultPatient[2]};
    DefaultPatient[2] = (struct Patient){.ID = 2026003, .Name = "Sarah", .Age = 31, .ClinicName = "Cardiology", .nxtAPP = {.clinicName = "Cardiology", .patientID = 2026003, .day = 15, .month = 8, .Time = 14}, .MedicalRecord = "Hypertension history", .NEXT = &DefaultPatient[3]};
    DefaultPatient[3] = (struct Patient){.ID = 2026004, .Name = "Fatma", .Age = 45, .ClinicName = "Orthopedics", .nxtAPP = {.clinicName = "Orthopedics", .patientID = 2026004, .day = 10, .month = 9, .Time = 11}, .MedicalRecord = "Recovering from knee surgery", .NEXT = &DefaultPatient[4]};
    DefaultPatient[4] = (struct Patient){.ID = 2026005, .Name = "Omar", .Age = 12, .ClinicName = "Pediatrics", .nxtAPP = {.clinicName = "Pediatrics", .patientID = 2026005, .day = 5, .month = 10, .Time = 13}, .MedicalRecord = "Routine checkup", .NEXT = &DefaultPatient[5]};
    DefaultPatient[5] = (struct Patient){.ID = 2026006, .Name = "Layla", .Age = 28, .ClinicName = "Dermatology", .nxtAPP = {.clinicName = "Dermatology", .patientID = 2026006, .day = 12, .month = 11, .Time = 10}, .MedicalRecord = "Skin allergy treatment", .NEXT = &DefaultPatient[6]};
    DefaultPatient[6] = (struct Patient){.ID = 2026007, .Name = "Youssef", .Age = 35, .ClinicName = "Neurology", .nxtAPP = {.clinicName = "Neurology", .patientID = 2026007, .day = 20, .month = 12, .Time = 15}, .MedicalRecord = "Migraine management", .NEXT = &DefaultPatient[7]};
    DefaultPatient[7] = (struct Patient){.ID = 2026008, .Name = "Mariam", .Age = 22, .ClinicName = "Gynecology", .nxtAPP = {.clinicName = "Gynecology", .patientID = 2026008, .day = 18, .month = 1, .Time = 9}, .MedicalRecord = "Pregnancy checkup", .NEXT = &DefaultPatient[8]};
    DefaultPatient[8] = (struct Patient){.ID = 2026009, .Name = "Khaled", .Age = 40, .ClinicName = "Cardiology", .nxtAPP = {.clinicName = "Cardiology", .patientID = 2026009, .day = 22, .month = 2, .Time = 14}, .MedicalRecord = "Heart disease follow-up", .NEXT = &DefaultPatient[9]};
    DefaultPatient[9] = (struct Patient){.ID = 2026010, .Name = "Aisha", .Age = 30, .ClinicName = "Endocrinology", .nxtAPP = {.clinicName = "Endocrinology", .patientID = 2026010, .day = 28, .month = 3, .Time = 11}, .MedicalRecord = "Diabetes management", .NEXT = TAILPTR};
}
