#include "../APP/STD_TYPES.h"
#include "../Models/Models_Interface.h"
#include "Admin_Interface.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

u16 dailySlots[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/* The text representations of our 5 slots */
const u8* slotTimes[10] = {
    "10:00 AM to 10:30 AM",
    "10:30 AM to 11:00 AM",
    "11:00 AM to 11:30 AM",
    "11:30 AM to 12:00 PM",
    "12:00 PM to 12:30 PM",
    " 2:00 PM to  2:30 PM",
    " 2:30 PM to  3:00 PM",
    " 3:00 PM to  3:30 PM",
    " 4:00 PM to  4:30 PM",
    " 4:30 PM to  5:00 PM"
};

/* Helper function to check if an ID already exists */
struct Patient* SearchPatient(u16 targetID) {
    struct Patient* current = &DefaultPatient[0];
    while (current != NULL) {
        if (current->ID == targetID) {
            return current;
        }
        current = current->NEXT;
    }
    return NULL;
}

void AdminMode() {
    u8 password[15];
    u8 trials = 0;
    u8 authenticated = 0;
    u8 choice;
    
    printf("\n========================================\n");
    printf("               ADMIN LOGIN              \n");
    printf("========================================\n");

    while (trials < 3) {
        printf("Enter Password: ");
        scanf("%14s", password);
        
        if (strcmp((u8*)password, admin.SecurityPassCode) == 0) {
            authenticated = 1;
            break;
        }
        
        trials++;
        printf(">> Incorrect password. %d trials left.\n\n", 3 - trials);
    }
    
    if (authenticated == 0) {
        printf(">> Maximum trials reached. System closing.\n");
        exit(1);
    }

    /* Admin Menu Loop */
    while (1) {
        printf("\n========================================\n");
        printf("               ADMIN MENU               \n");
        printf("========================================\n");
        printf(" 1 -> Add New Patient Record\n");
        printf(" 2 -> Edit Patient Record\n");
        printf(" 3 -> Reserve a Slot with the Doctor\n");
        printf(" 4 -> Cancel Reservation\n");
        printf(" 5 -> Exit Admin Mode\n");
        printf("----------------------------------------\n");
        printf("Choice: ");
        scanf("%hu", &choice);

        switch (choice) {
            case 1: {
                /* Feature 1: Add New Patient */
                u16 newID;
                printf("\n[ADD PATIENT]\nEnter New Patient ID: ");
                scanf("%hu", &newID);
                
                if (SearchPatient(newID) != NULL) {
                    printf(">> Error: ID %hu already exists. Entry rejected.\n", newID);
                } else {
                    /* Allocate new memory for the patient */
                    struct Patient* newP = (struct Patient*)malloc(sizeof(struct Patient));
                    newP->ID = newID;
                    
                    printf("Enter Name: ");
                    scanf(" %49[^\n]", newP->Name);
                    printf("Enter Age: ");
                    scanf("%hu", &newP->Age);
                    
                    newP->NEXT = NULL;
                    
                    /* Append to the end of the linked list */
                    struct Patient* current = &DefaultPatient[0];
                    while (current->NEXT != NULL) {
                        current = current->NEXT;
                    }
                    current->NEXT = newP;
                    printf(">> Patient added successfully!\n");
                }
                break;
            }
            case 2: {
                /* Feature 2: Edit Patient */
                u16 targetID;
                printf("\n[EDIT PATIENT]\nEnter Patient ID to edit: ");
                scanf("%hu", &targetID);
                
                struct Patient* p = SearchPatient(targetID);
                if (p == NULL) {
                    printf(">> Error: Incorrect ID. Patient not found.\n");
                } else {
                    printf("Editing Patient: %s\n", p->Name);
                    printf("Enter New Name: ");
                    scanf(" %49[^\n]", p->Name);
                    printf("Enter New Age: ");
                    scanf("%hu", &p->Age);
                    printf(">> Record updated successfully!\n");
                }
                break;
            }
            case 3: {
                /* Feature 3: Reserve a Slot */
                u16 patID;
                u16 slotChoice;
                
                printf("\n[RESERVE SLOT]\nAvailable Slots:\n");
                for (int i = 0; i < 5; i++) {
                    if (dailySlots[i] == 0) {
                        printf(" %d -> %s\n", i + 1, slotTimes[i]);
                    }
                }
                
                printf("\nEnter Patient ID: ");
                scanf("%hu", &patID);
                
                if (SearchPatient(patID) == NULL) {
                    printf(">> Error: Patient ID %hu does not exist.\n", patID);
                    break;
                }
                
                printf("Enter Slot Number (1-5): ");
                scanf("%hu", &slotChoice);
                
                if (slotChoice < 1 || slotChoice > 5) {
                    printf(">> Error: Invalid slot number.\n");
                } else if (dailySlots[slotChoice - 1] != 0) {
                    printf(">> Error: That slot is already reserved.\n");
                } else {
                    dailySlots[slotChoice - 1] = patID;
                    printf(">> Slot successfully reserved for ID %hu!\n", patID);
                }
                break;
            }
            case 4: {
                /* Feature 4: Cancel Reservation */
                u16 patID;
                u8 found = 0;
                
                printf("\n[CANCEL RESERVATION]\nEnter Patient ID: ");
                scanf("%hu", &patID);
                
                /* Search through the dailySlots array to find this ID's reservation */
                for (int i = 0; i < 5; i++) {
                    if (dailySlots[i] == patID) {
                        dailySlots[i] = 0; /* Free the slot */
                        found = 1;
                        printf(">> Reservation for %s cancelled. Slot is now available.\n", slotTimes[i]);
                    }
                }
                
                if (found == 0) {
                    printf(">> Error: No reservations found for Patient ID %hu.\n", patID);
                }
                break;
            }
            case 5:
                printf("\nExiting Admin Mode...\n");
                return;
            default:
                printf(">> Invalid choice. Please try again.\n");
        }
    }
}