# Clinic Management System

A console-based clinic scheduling assistant written in C. Admins can register
patients and manage appointment slots; patients can look up their own record
and next appointment by ID.

> Nicknamed **NEMO** in the app's welcome banner — "Your Clinic Schedule
> Assistant."

## Features

**Admin mode** (password-protected, 3 login attempts)
- Add a new patient record
- Edit an existing patient's name/age
- Reserve one of 5 daily appointment slots (2:00–5:00 PM) for a patient
- Cancel a patient's slot reservation

**User mode**
- Look up your own record by Patient ID
- View your name, age, medical record, and next appointment (clinic, date, time)

Patient records are stored as a fixed array seeded with 10 sample patients,
extended with a singly linked list (`Patient.NEXT`) for records added at
runtime.

## Project Structure

```
Clinic-Management-System/
├── APP/
│   ├── Clinic.c          # main() — welcome banner, admin/user mode selection
│   ├── Models.c           # patient/admin data + seed data
│   ├── Models.h           # Patient/Appointment/Admin struct definitions
│   └── STD_TYPES.h         # fixed-width type aliases (u8, u16, s32, ...)
├── ADMIN/
│   ├── Admin_Program.c     # admin login + menu (add/edit/reserve/cancel)
│   └── Admin_Interface.h   # slot data + AdminMode() declaration
├── USER/
│   ├── User_Program.c      # patient lookup flow
│   └── User_Interface.h    # UserMode() declaration
└── Makefile
```

## Building

Requires `gcc` (native build) and, optionally, a MinGW cross-compiler if
you want to produce a Windows `.exe` from Linux/macOS.

```bash
make            # build with the host compiler → bin/clinic
make windows    # cross-compile a Windows .exe with MinGW → bin/clinic.exe
make run        # build (if needed) and run
make clean      # remove build artifacts
```

On native Linux/macOS, `Sleep()` is mapped to `usleep()` via a small
compatibility shim in `Clinic.c`; on Windows it uses the real `Sleep()`
from `<windows.h>`.

## Running

```bash
./bin/clinic
```

You'll be asked whether you're an **Admin** (`1`) or a **User** (`2`).

- Admin password: `1234`
- Sample patient IDs to try in User mode: `2026001`–`2026010`
  (e.g. `2026001` is "Mohannad", a Dentistry patient)

## Known Limitations

- `Patient.ID` is a `u16` (max 65,535), but sample IDs are 7 digits
  (`2026001`, etc.), so they silently overflow to smaller values internally.
  Functionally consistent within the app (lookups still work, since the
  same overflowed value is stored and searched), but the *displayed*
  numbers aren't the same width they were entered as. Widening `ID` to
  `u32` (and the matching `scanf` format strings) would fix this properly.
- The admin password is hardcoded (`"1234"`) in `Admin_Program.c`; the
  `admin.password` field in `Models.c` is seeded but not actually checked.
- Patients added at runtime are `malloc`'d and never freed.
- No persistence — all data is in-memory and resets on exit.

## Credits

Made by Mohannad El-Shahiedy.