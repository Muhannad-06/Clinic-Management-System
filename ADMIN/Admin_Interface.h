#ifndef ADMIN_INTERFACE_H_
#define ADMIN_INTERFACE_H_

/* ONLY 5 APPS a Day 0 = Available Otherwise holds the Patient ID */
extern u16 dailySlots[5];

/* The text representations of our 5 slots */
extern const char* slotTimes[5];

void AdminMode();

#endif /* ADMIN_INTERFACE_H_ */