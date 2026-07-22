#include <stdio.h>
#include "../APP/STD_TYPES.h"
#include "../Models/Models_Interface.h"
#include "User_Interface.h"

void UserMode(){
    u16 ID;
    u8 found = 0; 
    
    struct Patient* currentPatient = &DefaultPatient[0]; 

    printf("\n");
    printf("Welcome!\nPlease Enter Your Patient ID > ");
    
    scanf("%hu", &ID); 

    while (currentPatient != NULL) 
    {
        if (currentPatient->ID == ID) 
        {
            found = 1;
            printf("\n========================================\n");
            printf("          PATIENT RECORD FOUND          \n");
            printf("========================================\n");
            printf(" Name           : %s\n", currentPatient->Name);
            printf(" Age            : %d\n", currentPatient->Age);
            printf(" Medical Record : %s\n", currentPatient->MedicalRecord);
            printf("----------------------------------------\n");
            printf("          NEXT APPOINTMENT              \n");
            printf("----------------------------------------\n");
            printf(" Clinic : %s\n", currentPatient->nxtAPP.clinicName);
            printf(" Time   : %02d:00 (24-hour format)\n", currentPatient->nxtAPP.Time);
            printf("----------------------------------------\n");
            printf("              APPOINTMENTs              \n");
            printf("----------------------------------------\n");
            printf("Date");
            printf("========================================\n\n");
            
            break;
        }
        
        currentPatient = currentPatient->NEXT; 
    }

    if (found == 0) 
    {
        printf("\n>> Error: Patient ID %hu is not registered in our system.\n\n", ID);
    }
}