# 🏥 Hospital Management System using Qt (C++)

## 📌 Project Overview

The Hospital Management System is a desktop application developed using **Qt Widgets Framework and C++** to simplify hospital administration tasks. The application provides an easy-to-use graphical interface for managing patient records, appointments, room allocation, billing, and data storage.

This project demonstrates the use of **Object-Oriented Programming (OOP)**, **Qt GUI Development**, **File Handling**, and **Data Management using QVector**.

---

## 🚀 Features

### 👤 Patient Management

* Add new patient records
* Search patient details using Patient ID
* Modify existing patient information
* Delete patient records

### 📅 Appointment Management

* Book appointments for patients
* Store appointment dates

### 🏥 Room Allocation

* Allocate rooms to patients
* Update room assignments dynamically

### 💰 Billing Management

* Generate patient bills
* Store billing information

### 💾 Data Persistence

* Save patient records to a text file
* Load saved records from file
* Maintain records even after application restart

### 📊 Patient Records Table

Displays:

* Patient ID
* Name
* Age
* Gender
* Blood Group
* Doctor
* Disease
* Room Number
* Bill Amount

---

## 🛠 Technologies Used

* **Language:** C++
* **Framework:** Qt Widgets
* **IDE:** Qt Creator
* **Concepts:** OOP, File Handling, GUI Programming
* **Data Structure:** QVector

---

## 📂 Project Structure

```text
HospitalManagementSystem/
│
├── main.cpp
├── mainwindow.h
├── mainwindow.cpp
├── mainwindow.ui
│
├── patient.h
├── patient.cpp
│
├── filemanager.h
├── filemanager.cpp
│
└── patients.txt
```

### Module Description

#### Patient Module

Stores patient information such as:

* Patient ID
* Name
* Age
* Gender
* Blood Group
* Contact Details
* Address
* Doctor Name
* Disease
* Room Number
* Appointment Date
* Bill Amount
* Remarks

#### File Manager Module

Responsible for:

* Saving patient data
* Loading patient data
* Managing persistent storage using text files

#### Main Window Module

Handles:

* User Interface
* Button Events
* Table Widget Updates
* Patient Operations

---

## 📋 Functionalities Implemented

### Add Patient

Creates a new patient record and displays it in the table.

### Search Patient

Finds a patient using Patient ID and displays all stored details.

### Modify Patient

Updates existing patient information and refreshes the table.

### Delete Patient

Removes patient records from both the application and table.

### Save Data

Stores all patient records into a text file.

### Load Data

Retrieves saved patient records and displays them in the application.

### Book Appointment

Schedules appointments for registered patients.

### Allocate Room

Assigns room numbers to patients.

### Generate Bill

Manages patient billing information.

---

## 🎯 Learning Outcomes

Through this project, I gained practical experience in:

* Qt Widget-based GUI development
* Event-driven programming
* Object-Oriented Programming in C++
* File handling using QFile and QTextStream
* Data management using QVector
* Designing modular software architecture
* Building desktop applications with Qt

---

## 🔮 Future Enhancements

* Database integration using SQLite/MySQL
* Doctor Management Module
* Staff Management Module
* Authentication/Login System
* Advanced Billing System
* PDF Report Generation
* Dashboard and Analytics

---

## 👩‍💻 Author

**Srivalli Gandham**
Qt Development

---

## ⭐ Project Highlights

* Developed using Qt Widgets and C++
* Modular design with separate Patient and FileManager classes
* Supports complete CRUD operations
* Implements file-based data persistence
* User-friendly GUI for hospital administration
