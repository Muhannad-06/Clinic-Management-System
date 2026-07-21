#include <stdio.h>
#define Sleep(ms) usleep((ms) * 1000)
#include "STD_TYPES.h"
#include "Models.h"
#include "../ADMIN/Admin_Interface.h"
#include "../USER/User_Interface.h"

#define SLEEP_T 0*(0.75 * 1000)

/*Proto Types*/
void INTRO();
u8 Mode_Selection();


int main(){

    INTRO();
    IntializePatients();

    u8 mode = Mode_Selection();
    if (mode == 1) {
        AdminMode();
    } else if (mode == 2) {
        UserMode();
    }

    return 0;
}

/*Welcoming & Credit*/
void INTRO(){
    printf("\t***********************************************\n");
    printf("\t*      Welcome To NEMO (o_O)                  *\n");
    Sleep(SLEEP_T);
    printf("\t*          YOUR Clinic Schedule Assistant     *\n");
    Sleep(SLEEP_T);
    printf("\t*  Made By : Mohannad El-Shahiedy \\(^o^)/     *\n");
    Sleep(SLEEP_T);
    printf("\t***********************************************\n");
    
}

/*Admin Or User Menu*/
u8 Mode_Selection(){
    u8 ModeSelected;
    printf("======================\n");
    printf("||   Who Are You ?  ||\n");
    printf("|| 1 -> Admin       ||\n");
    printf("|| 2 -> User        ||\n");
    printf("|| Choice : ");
    scanf("%hhu", &ModeSelected);
    printf("======================\n");
    switch (ModeSelected)
    {
    case 1:
        return ModeSelected;
    case 2:
        return ModeSelected;
    default:
        printf(">>Please Select Between 1~2\n\n");
        return Mode_Selection();
    }
}

