#ifndef MODELS_H
#define MODELS_H

#include "../APP/STD_TYPES.h"

#define MAX_PATIENTS_NAME 100
#define MAX_APPOINTMENTS 5
#define MAX_CLINIC_NAME_LENGTH 30
#define MAX_NUMBER_OF_PATIENTS 15
#define USERNAME_LENGTH 10
#define PASSWORD_LENGTH 15
#define MEDICAL_RECORD_LENGTH 200

struct Appointment
{
    u8 clinicName[MAX_CLINIC_NAME_LENGTH];
    u32 patientID; /* u32 to hold 2026001 without overflowing */
    u8 Time;       /* 24-hour format */
};

struct Patient
{
    u32 ID;        /* u32 to hold 2026001 without overflowing */
    u8 Name[MAX_PATIENTS_NAME];
    u16 Age;
    u8 MedicalRecord[MEDICAL_RECORD_LENGTH];
    struct Appointment* nxtAPP; /* Pointer to accept NULL */
    struct Patient* NEXT;
};

/* Admin */
struct Admin
{
    u8 userName[USERNAME_LENGTH];
    u8 SecurityPassCode[PASSWORD_LENGTH];
};

/* Extern declarations */
extern struct Admin admin; 
extern struct Patient DefaultPatient[MAX_NUMBER_OF_PATIENTS];
extern struct Patient* TAILPTR;
extern u32 lastID; 

/* The Appointment Times Choices*/
extern const u8* slotTimes[10];

void IntializePatients();
void IntializedAppointmentsImplementation();

#endif