#include <stdio.h>
#include <windows.h>
#include "STD_TYPES.h"
#include "Models.h"

#define SLEEP_T 0*(0.75 * 1000)

/*Proto Types*/
void INTRO();
u8 Mode_Selection();


int main(){

    INTRO();   

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
    scanf("%u", &ModeSelected);
    printf("======================\n");
    switch (ModeSelected)
    {
    case 1:
        return ModeSelected;
        break;
    case 2:
        return ModeSelected;
        break;
    default:
        printf(">>Please Select Between 1~2\n\n");
        Mode_Selection();
    }
}

/*User Mode*/
void UserMode(){
    u16 ID;
    printf("\n");
    printf("Welcome Mr/Mrs \n Please Enter Your Patient ID > ");
    scanf("%lu", &ID);

}

