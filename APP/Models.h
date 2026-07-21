#ifndef MODELS_H
#define MODELS_H

#include "STD_TYPES.h"

#define MAX_PATIENTS_NAME 50
#define MAX_APPOINTMENTS 5
#define MAX_CLINIC_NAME_LENGTH 30
#define MAX_NUMBER_OF_PATIENTS 15
#define USERNAME_LENGTH 10
#define PASSWORD_LENGTH 15
#define MEDICAL_RECORD_LENGTH 200

struct Appointment
{
    u8 clinicName[MAX_CLINIC_NAME_LENGTH];
    u16 patientID;
    u8 day;
    u8 month;
    u8 Time; /*24-hour format*/
};

struct Patient
{
    u16 ID;
    u8 Name[MAX_PATIENTS_NAME];
    u16 Age;
    u8 ClinicName[MAX_CLINIC_NAME_LENGTH];
    u8 MedicalRecord[MEDICAL_RECORD_LENGTH];
    struct Appointment nxtAPP;
    struct Patient* NEXT;
};


/* Admin */
struct Admin
{
    u8 userName[USERNAME_LENGTH];
    u8 password[PASSWORD_LENGTH];
};
/*  Will Be Used Out This File */
extern struct Admin admin;
extern struct Patient DefaultPatient[MAX_NUMBER_OF_PATIENTS];
extern struct Patient* TAILPTR;
extern u16 lastID;

void IntializePatients(void);

#endif