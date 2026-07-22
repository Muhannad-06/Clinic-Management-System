#ifndef ADMIN_INTERFACE_H_
#define ADMIN_INTERFACE_H_

/* 10 APPS a Day -> 0 = Available Otherwise holds the Patient ID */
extern u32 dailySlots[10];

/* The Appointment Times Choices*/
extern const u8* slotTimes[10];

void AdminMode();

#endif /* ADMIN_INTERFACE_H_ */