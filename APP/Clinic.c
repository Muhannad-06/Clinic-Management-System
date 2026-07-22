#include <stdio.h>
#include <windows.h> /* For Sleep */

#include "../APP/STD_TYPES.h"
#include "../Models/Models_Interface.h"
#include "../ADMIN/Admin_Interface.h"
#include "../USER/User_Interface.h"

#define SLEEP_T (0.75 * 1000)

/* Proto Types */
void INTRO();
u8 Mode_Selection();

int main() {
    INTRO();
    IntializePatients();

    /* Wrap the main menu in a loop so the program doesn't terminate immediately */
    while (1) {
        u8 mode = Mode_Selection();
        
        if (mode == 1) {
            AdminMode();
        } else if (mode == 2) {
            UserMode();
        }
    }

    return 0;
}

/* Welcoming & Credit */
void INTRO() {
    printf("\t***********************************************\n");
    printf("\t*      Welcome To NEMO (o_O)                  *\n");
    Sleep(SLEEP_T);
    printf("\t*          YOUR Clinic Schedule Assistant     *\n");
    Sleep(SLEEP_T);
    printf("\t*  Made By : Mohannad El-Shahiedy \\(^o^)/     *\n");
    Sleep(SLEEP_T);
    printf("\t***********************************************\n\n");
}

/* Admin Or User Menu */
u8 Mode_Selection() {
    u8 ModeSelected;
    u16 temp;
    
    printf("======================\n");
    printf("||   Who Are You ?  ||\n");
    printf("|| 1 -> Admin       ||\n");
    printf("|| 2 -> User        ||\n");
    printf("======================\n");
    printf("Choice: ");
    
    scanf("%hu", &temp);

    /* El Compiler ms rady yeshof el %huu */
    ModeSelected = (u8)temp;
    
    switch (ModeSelected) {
        case 1:
        case 2:
            return ModeSelected;
        default:
            printf("\n>> Error: Please Select Between 1 and 2.\n\n");
            return Mode_Selection(); /* Recursive call until valid input */
    }
}