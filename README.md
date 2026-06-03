# 🏥 Hospital Management System

Hospital Management System is a C terminal application that simulates basic hospital operations. It supports two types of users — Admin and Patient — each with their own login credentials and menu. Patient data and appointments are stored persistently using text files, allowing records to survive between sessions.

This project demonstrates core C programming concepts including structures, file I/O, string handling, and modular function design.

---

## 🗂️ Project Structure

```
Hospital_Project/
│
├── main.c                        # Full source code
├── Admin_Login_Password.txt      # Admin credentials file
├── Patient_Login_Password.txt    # Patient credentials file
├── patients.txt                  # Stores patient records (auto-created)
└── appointments.txt              # Stores appointment records (auto-created)
```

---

## 🔐 Default Login Credentials

| Role    | Username  | Password |
|---------|-----------|----------|
| Admin   | `admin`   | `123`    |
| Patient | `patient` | `123`    |

> Credentials are stored in plain text files. Make sure both login files exist before running.

### Admin_Login_Password.txt
```
admin 123
```

### Patient_Login_Password.txt
```
patient 123
```

---

## ⚙️ Features

### 👨‍💼 Admin Panel
- Add new patient (with duplicate ID check)
- View all patients
- Search patient by ID
- View all appointments
- Remove a patient by ID
- Cancel an appointment by Patient ID

### 🧑‍⚕️ Patient Panel
- Book an appointment (with duplicate ID check)
- View all appointments

### 🔒 Login System
- Separate login for Admin and Patient
- Credentials verified against text files
- Invalid login rejected with error message

---

## 🚀 How to Compile and Run

### Prerequisites
- GCC compiler installed
- Terminal / Command Prompt / PowerShell

### Steps

```bash
# Step 1 — Compile
gcc main.c -o hospital

# Step 2 — Run
hospital.exe        # Windows
```

---

## 🎮 How to Use

```
#### Dashboard #####
1. Admin Login
2. Patient Login
3. Exit

Enter your choice: 1
Enter username: admin
Enter password: 123

--- Admin Menu ---
1. Add Patient
2. View All Patients
3. Search Patients
4. View Appointments
5. Remove Patient
6. Cancel Appointments
7. Logout
```

### Adding a Patient (Admin)
```
Enter ID Name Age PhoneNumber: 101 John 30 9876543210
----- Patient Added Successfully.-----
```

### Booking an Appointment (Patient)
```
Enter Patient ID: 101
Enter Doctor Name: DrSharma
----- Appointment Booked Successfully.-----
```

---

## 🗃️ Data Files

| File | Purpose |
|---|---|
| `Admin_Login_Password.txt` | Stores admin username and password |
| `Patient_Login_Password.txt` | Stores patient username and password |
| `patients.txt` | Stores patient records (ID, Name, Age, Phone) |
| `appointments.txt` | Stores appointments (Patient ID, Doctor Name) |

> `patients.txt` and `appointments.txt` are created automatically when records are first added.

---

## 🧱 C Concepts Used

| Concept | Where Used |
|---|---|
| Structures (`struct`) | `Patient`, `Appointment`, `Login` |
| File Handling | `fopen`, `fscanf`, `fprintf`, `fclose`, `rewind` |
| String Functions | `strcmp` for login verification |
| Loops & Conditionals | Duplicate ID checks, menu navigation |
| Functions | Modular design — one function per feature |
| Temp File Trick | Used in remove/cancel to rewrite files |

---

## 🛠️ Future Improvements

- Add password hashing for secure login
- Support multiple admin and patient accounts
- Add date and time to appointments
- Validate phone number format
- Build a GUI using GTK or a web frontend

---

## 👨‍💻 Author

Developed as a C programming Fundamentl and file handling project.  
Language: **C**  
Concepts: **Structures, File I/O, Modular Programming**

