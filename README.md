# Clinic Management System

A console-based clinic scheduling assistant written in C. Admins can register
patients and manage appointment slots; patients can look up their own record
and next appointment by ID.

> Nicknamed **NEMO** in the app's welcome banner — "Your Clinic Schedule
> Assistant."

## Features

**Admin mode** (password-protected against `admin.SecurityPassCode`, 3 login attempts)
- Add a new patient record (rejects duplicate IDs)
- Edit an existing patient's medical record, and optionally their name or age
- Reserve one of 10 daily appointment slots (10:00 AM–12:30 PM and
  2:00–5:00 PM, in 30-minute increments) for a patient
- Cancel a patient's slot reservation (also frees the appointment's memory)

**User mode**
- Look up your own record by Patient ID
- View your name, age, medical record, and next appointment (clinic, time)

After finishing an Admin or User session, the app loops back to the
Admin/User selection menu instead of exiting.

Patient records are stored as a fixed array seeded with 10 sample patients,
extended with a singly linked list (`Patient.NEXT`) for records added at
runtime. Each patient's next appointment (`Patient.nxtAPP`) is a heap-allocated
`Appointment*`, so it can be `NULL` when nothing is booked.

## Project Structure

```
Clinic-Management-System/
├── APP/
│   ├── Clinic.c            # main() — welcome banner, admin/user mode selection
│   └── STD_TYPES.h         # fixed-width type aliases (u8, u16, s32, ...)
├── Models/
│   ├── Models.c             # patient/admin data + seed data
│   └── Models_Interface.h   # Patient/Appointment/Admin struct definitions
├── ADMIN/
│   ├── Admin_Program.c     # admin login + menu (add/edit/reserve/cancel)
│   └── Admin_Interface.h   # slot-times table + AdminMode() declaration
├── USER/
│   ├── User_Program.c      # patient lookup flow
│   └── User_Interface.h    # UserMode() declaration
└── Makefile
```

(`Models` moved out from under `APP/` into its own top-level folder, and
`Models.h` was renamed to `Models_Interface.h`, matching the naming
convention already used by `ADMIN` and `USER`.)

## Building

Requires a MinGW cross-compiler (`x86_64-w64-mingw32-gcc`). `Clinic.c` now
includes `<windows.h>` unconditionally for `Sleep()`, with no Linux/macOS
fallback, so **`make` on native Linux/macOS gcc will fail** with
`windows.h: No such file or directory`. Use `make windows` regardless of host OS.

```bash
make windows    # cross-compile a Windows .exe with MinGW → bin/clinic.exe
make clean      # remove build artifacts
```

`make` / `make run` (host-compiler targets) are still defined in the
Makefile but are currently broken for the reason above, until a portability
shim is restored in `Clinic.c`.

## Running

```bash
./bin/clinic.exe
```

You'll be asked whether you're an **Admin** (`1`) or a **User** (`2`), and
returned to this menu after each session.

- Admin password: `admin123` (checked against the seeded `admin` record —
  no longer hardcoded)
- Sample patient IDs to try in User mode: `2026001`–`2026010`
  (e.g. `2026001` is "Mohannad", a Dentistry patient)

## Known Limitations

- **Native build is broken.** `Clinic.c` includes `<windows.h>` directly;
  the previous `usleep()`-based portability shim for Linux/macOS was
  removed. Only `make windows` (MinGW) currently builds the project.
- User mode's "not registered" error prints the `u32` patient ID with a
  `%hu` format specifier (`User_Program.c`), a type mismatch that can print
  a garbage value on some platforms/compilers.
- Patients added at runtime (`malloc`'d in Admin mode) are never freed, and
  an appointment booked via "Reserve a Slot" is only freed if that
  reservation is later cancelled — otherwise it still leaks.
- No persistence — all data is in-memory and resets on exit.

Fixed since the previous version of this README: `Patient.ID` is now a
`u32` (no more overflow on 7-digit IDs), and the admin password is now
actually checked against `Models.c` instead of being hardcoded.

## Credits

Made by Mohannad El-Shahiedy.