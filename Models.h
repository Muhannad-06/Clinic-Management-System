#ifndef MODELS_H
#define MODELS_H
#endif

#include "STD_TYPES.h"

#define MAX_PATIENTS_NAME 50
#define MAX_APPOINTMENTS 5
#define MAX_CLINIC_NAME_LENGTH 30
#define MAX_NUMBER_OF_PATIENTS 15
#define USERNAME_LENGTH 10
#define PASSWORD_LENGTH 15
#define MEDICAL_RECORD_LENGTH 200

struct Patient
{
    u16 ID;
    u8 Name[MAX_PATIENTS_NAME];
    u16 Age;
    u8 ClinicName[MAX_CLINIC_NAME_LENGTH];
    u8 NextAppointmentDate;
    u8 MedicalRecord[MEDICAL_RECORD_LENGTH];

    struct Patients* NEXT;
};


/* Admin */
struct Admin
{
    u8 userName[USERNAME_LENGTH];
    u8 password[PASSWORD_LENGTH];
};

struct Admin admin = {.userName = "admin", .password = "admin123"};
struct Patient DefaultPatient[MAX_NUMBER_OF_PATIENTS];

/* Pointer to the last patient in the linked list */
struct Patient* TAILPTR = NULL;


/* Intialize Some Patients */
void IntializePatients(){
    DefaultPatient[0] = (struct Patient){.ID = 2026001, .Name = "Mohannad", .Age = 20, .ClinicName = "Dentistry", .NextAppointment = 1, .MedicalRecord = "No chronic conditions", .NEXT = &DefaultPatient[1]};
    DefaultPatient[1] = (struct Patient){.ID = 2026002, .Name = "Ahmed", .Age = 25, .ClinicName = "Pediatrics", .NextAppointment = 2, .MedicalRecord = "Allergic to Penicillin", .NEXT = &DefaultPatient[2]};
    DefaultPatient[2] = (struct Patient){.ID = 2026003, .Name = "Sarah", .Age = 31, .ClinicName = "Cardiology", .NextAppointment = 0, .MedicalRecord = "Hypertension history", .NEXT = &DefaultPatient[3]};
    DefaultPatient[3] = (struct Patient){.ID = 2026004, .Name = "Fatma", .Age = 45, .ClinicName = "Orthopedics", .NextAppointment = 1, .MedicalRecord = "Recovering from knee surgery", .NEXT = &DefaultPatient[4]};
    DefaultPatient[4] = (struct Patient){.ID = 2026005, .Name = "Omar", .Age = 12, .ClinicName = "Pediatrics", .NextAppointment = 3, .MedicalRecord = "Routine checkup", .NEXT = &DefaultPatient[5]};
    DefaultPatient[5] = (struct Patient){.ID = 2026006, .Name = "Youssef", .Age = 29, .ClinicName = "Dermatology", .NextAppointment = 0, .MedicalRecord = "Eczema treatment", .NEXT = &DefaultPatient[6]};
    DefaultPatient[6] = (struct Patient){.ID = 2026007, .Name = "Nour", .Age = 38, .ClinicName = "General Clinic", .NextAppointment = 2, .MedicalRecord = "Annual blood work clean", .NEXT = &DefaultPatient[7]};
    DefaultPatient[7] = (struct Patient){.ID = 2026008, .Name = "Mariam", .Age = 50, .ClinicName = "Ophthalmology", .NextAppointment = 1, .MedicalRecord = "Prescription glasses updated", .NEXT = &DefaultPatient[8]};
    DefaultPatient[8] = (struct Patient){.ID = 2026009, .Name = "Ali", .Age = 63, .ClinicName = "Neurology", .NextAppointment = 4, .MedicalRecord = "Migraine follow-up", .NEXT = &DefaultPatient[9]};
    DefaultPatient[9] = (struct Patient){.ID = 2026010, .Name = "Khaled", .Age = 22, .ClinicName = "General Clinic", .NextAppointment = 0, .MedicalRecord = "Flu symptoms resolved", .NEXT = TAILPTR};
}

/* Holds the latest ID */
u16 lastID = 2026010;

