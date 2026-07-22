#include "../APP/STD_TYPES.h"
#include "Models_Interface.h"
#include <stdlib.h>
#include <string.h>

/* DEFINE EXTERN VARIABLES */
struct Patient DefaultPatient[MAX_NUMBER_OF_PATIENTS];
struct Admin admin = {.userName = "admin", .SecurityPassCode = "admin123"};
u32 lastID = 2026010;
struct Patient* TAILPTR = NULL;
extern u32 dailySlots[10];


/* Initialize Some Patients */
void IntializePatients()
{
    /* Initialize basic patient data. nxtAPP is set to NULL for now to avoid dangling pointers. */
    DefaultPatient[0] = (struct Patient){.ID = 2026001, .Name = "Mohannad", .Age = 20, .nxtAPP = NULL, .MedicalRecord = "No chronic conditions", .NEXT = &DefaultPatient[1]};
    DefaultPatient[1] = (struct Patient){.ID = 2026002, .Name = "Ahmed",    .Age = 25, .nxtAPP = NULL, .MedicalRecord = "Allergic to Penicillin", .NEXT = &DefaultPatient[2]};
    DefaultPatient[2] = (struct Patient){.ID = 2026003, .Name = "Sarah",    .Age = 31, .nxtAPP = NULL, .MedicalRecord = "Hypertension history", .NEXT = &DefaultPatient[3]};
    DefaultPatient[3] = (struct Patient){.ID = 2026004, .Name = "Fatma",    .Age = 45, .nxtAPP = NULL, .MedicalRecord = "Recovering from knee surgery", .NEXT = &DefaultPatient[4]};
    DefaultPatient[4] = (struct Patient){.ID = 2026005, .Name = "Omar",     .Age = 12, .nxtAPP = NULL, .MedicalRecord = "Routine checkup", .NEXT = &DefaultPatient[5]};
    DefaultPatient[5] = (struct Patient){.ID = 2026006, .Name = "Layla",    .Age = 28, .nxtAPP = NULL, .MedicalRecord = "Skin allergy treatment", .NEXT = &DefaultPatient[6]};
    DefaultPatient[6] = (struct Patient){.ID = 2026007, .Name = "Youssef",  .Age = 35, .nxtAPP = NULL, .MedicalRecord = "Migraine management", .NEXT = &DefaultPatient[7]};
    DefaultPatient[7] = (struct Patient){.ID = 2026008, .Name = "Mariam",   .Age = 22, .nxtAPP = NULL, .MedicalRecord = "Pregnancy checkup", .NEXT = &DefaultPatient[8]};
    DefaultPatient[8] = (struct Patient){.ID = 2026009, .Name = "Khaled",   .Age = 40, .nxtAPP = NULL, .MedicalRecord = "Heart disease follow-up", .NEXT = &DefaultPatient[9]};
    DefaultPatient[9] = (struct Patient){.ID = 2026010, .Name = "Aisha",    .Age = 30, .nxtAPP = NULL, .MedicalRecord = "Diabetes management", .NEXT = NULL};

    /* Update TAILPTR to point to the actual last element in the list */
    TAILPTR = &DefaultPatient[9];

    /* Safely attach appointments to the heap */
    IntializedAppointmentsImplementation();
}

/* Helper function to keep the appointment initialization clean */
void AddDefaultAppointment(struct Patient* p, const char* clinic, u8 time, u8 slotIndex)
{
   p->nxtAPP = (struct Appointment*)malloc(sizeof(struct Appointment));
    strcpy((char*)p->nxtAPP->clinicName, clinic);
    p->nxtAPP->patientID = p->ID;
    p->nxtAPP->Time = time;
    
    /* Automatically claim the slot in the Admin's array */
    if (slotIndex < 10) {
        dailySlots[slotIndex] = p->ID;
    }
}

void IntializedAppointmentsImplementation()
{
    /* Synced exactly with your dailySlots initialization */
    AddDefaultAppointment(&DefaultPatient[0], "Dentistry",     10, 0); /* Mohannad -> Slot 1 */
    AddDefaultAppointment(&DefaultPatient[5], "Dermatology",   11, 2); /* Layla    -> Slot 3 */
    AddDefaultAppointment(&DefaultPatient[9], "Endocrinology", 11, 3); /* Aisha    -> Slot 4 */
    AddDefaultAppointment(&DefaultPatient[7], "Gynecology",    12, 4); /* Mariam   -> Slot 5 */
    AddDefaultAppointment(&DefaultPatient[3], "Orthopedics",   14, 5); /* Fatma    -> Slot 6 */
}