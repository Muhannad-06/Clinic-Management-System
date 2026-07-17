#include "STD_TYPES.h"

struct Patients
{
    u16 ID;
    u8 Name[20];
    u16 Age;
    u8 ClinicName[20];
    u16 NextAppointment;
    
    u8* NEXT;
} Patient;


/* Admin */
struct Admin
{
    u8 userName[20];
    u8 password[40];
};
