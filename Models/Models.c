#include "../APP/STD_TYPES.h"
#include "Models_Interface.h"

/* DEFINE EXTERN VARIABLES */
struct Patient DefaultPatient[MAX_NUMBER_OF_PATIENTS];
struct Admin admin = {.userName = "admin", .SecurityPassCode = "admin123"};
u32 lastID = 2026010;
struct Patient* TAILPTR = NULL;

/* Initialize Some Patients */
void IntializePatients()
{
    DefaultPatient[0] = (struct Patient){.ID = 2026001, .Name = "Mohannad", .Age = 20, 
        .nxtAPP = &(struct Appointment){.clinicName = "Dentistry", .patientID = 2026001, .Time = 10}, 
        .MedicalRecord = "No chronic conditions", .NEXT = &DefaultPatient[1]};
        
    DefaultPatient[1] = (struct Patient){.ID = 2026002, .Name = "Ahmed", .Age = 25, 
        .nxtAPP = NULL, 
        .MedicalRecord = "Allergic to Penicillin", .NEXT = &DefaultPatient[2]};
        
    DefaultPatient[2] = (struct Patient){.ID = 2026003, .Name = "Sarah", .Age = 31, 
        .nxtAPP = &(struct Appointment){.clinicName = "Cardiology", .patientID = 2026003, .Time = 14}, 
        .MedicalRecord = "Hypertension history", .NEXT = &DefaultPatient[3]};
        
    DefaultPatient[3] = (struct Patient){.ID = 2026004, .Name = "Fatma", .Age = 45, 
        .nxtAPP = NULL, 
        .MedicalRecord = "Recovering from knee surgery", .NEXT = &DefaultPatient[4]};
        
    DefaultPatient[4] = (struct Patient){.ID = 2026005, .Name = "Omar", .Age = 12, 
        .nxtAPP = NULL, 
        .MedicalRecord = "Routine checkup", .NEXT = &DefaultPatient[5]};
        
    DefaultPatient[5] = (struct Patient){.ID = 2026006, .Name = "Layla", .Age = 28, 
        .nxtAPP = &(struct Appointment){.clinicName = "Dermatology", .patientID = 2026006, .Time = 10}, 
        .MedicalRecord = "Skin allergy treatment", .NEXT = &DefaultPatient[6]};
        
    DefaultPatient[6] = (struct Patient){.ID = 2026007, .Name = "Youssef", .Age = 35, 
        .nxtAPP = NULL, 
        .MedicalRecord = "Migraine management", .NEXT = &DefaultPatient[7]};
        
    DefaultPatient[7] = (struct Patient){.ID = 2026008, .Name = "Mariam", .Age = 22, 
        .nxtAPP = &(struct Appointment){.clinicName = "Gynecology", .patientID = 2026008, .Time = 12}, 
        .MedicalRecord = "Pregnancy checkup", .NEXT = &DefaultPatient[8]};
        
    DefaultPatient[8] = (struct Patient){.ID = 2026009, .Name = "Khaled", .Age = 40, 
        .nxtAPP = NULL, 
        .MedicalRecord = "Heart disease follow-up", .NEXT = &DefaultPatient[9]};
        
    DefaultPatient[9] = (struct Patient){.ID = 2026010, .Name = "Aisha", .Age = 30, 
        .nxtAPP = &(struct Appointment){.clinicName = "Endocrinology", .patientID = 2026010, .Time = 11}, 
        .MedicalRecord = "Diabetes management", .NEXT = NULL};

    /* Update TAILPTR to point to the actual last element in the list */
    TAILPTR = &DefaultPatient[9];
}