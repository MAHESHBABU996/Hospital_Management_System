# Hospital_Management_System

🏥 Hospital Management System


📌 Project Overview

The Hospital Management System (HMS) is a fully functional C-based console application designed to manage hospital operations such as:

Patient record management

Doctor record management

Appointment scheduling

Updating & deleting records

Permanent data storage using files

This project is beginner-friendly but covers essential concepts like structures, file handling, CRUD operations, searching, updating in-place, and modular programming.

🚀 Key Features
🧑‍⚕️ 1. Patient Management

✔ Add new patient
✔ View all patients
✔ Search patient by ID
✔ Update patient details
✔ Delete patient record
✔ Auto-generated unique patient ID

👨‍⚕️ 2. Doctor Management

✔ Add doctor
✔ View doctors
✔ Search doctor by ID
✔ Store specialization
✔ Unique doctor ID generation

📅 3. Appointment Management

✔ Book appointments
✔ Record patient & doctor IDs
✔ Save appointment dates
✔ View all appointments

💾 4. Permanent Data Storage

All data is saved automatically in:

patients.dat
doctors.dat
appointments.dat


Even after the program closes, the data remains.

🛠️ Technologies Used
Component	Description
Language	C Language
Paradigm	Procedural Programming
Storage	Binary Files (.dat)
Concepts	File Handling, Structures, CRUD, Menu System
📂 Project Structure
Hospital-Management-System/
│
├── hospital.c           -> Main program source file
├── patients.dat         -> Auto-created patient database
├── doctors.dat          -> Auto-created doctor database
├── appointments.dat     -> Appointment records
└── README.md            -> Documentation

👨‍💻 How to Run the Project
1️⃣ Save the File

Save the provided code in hospital.c

2️⃣ Compile

Using GCC:

gcc hospital.c -o hospital

3️⃣ Run
./hospital


(Windows: hospital.exe)

🧠 Concepts You Will Learn

This project helps you master:

File handling (fwrite, fread, fseek, remove, rename)

Structures in C

CRUD operations

Updating binary records

Searching data

Menu-driven programming

Data persistence

📊 Sample Output
===============================
     HOSPITAL MANAGEMENT
===============================
1. Add Patient
2. View Patients
3. Search Patient
4. Update Patient
5. Delete Patient
6. Add Doctor
7. View Doctors
8. Search Doctor
9. Book Appointment
10. View Appointments
11. Exit
Enter your choice:


🏁 Conclusion

The Hospital Management System is an excellent project to understand real-life database management workflows in C.
It is suitable for:

✔ Mini Project
✔ Major Project
✔ Internship evaluation
✔ Academic submissions
✔ GitHub portfolio


Author  :  Mahesh Babu Baswani
