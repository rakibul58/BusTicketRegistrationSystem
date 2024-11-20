# GammaTravels

## Overview
This is a **Bus Ticket Booking Application** developed to facilitate online ticket booking for **Gamma Travels** bus services. The application was developed during the pandemic to allow users to book tickets conveniently and maintain social distancing.

Key features include:
- User registration and login.
- Admin panel for managing users, employees, and tickets.
- Seat selection with real-time availability.
- Email notifications for payment options and seat plans.
- Comprehensive database integration using SQLite.

---

## Features

### User Features:
- **Registration**: Users can register by providing details like first name, last name, email, password, and contact number.
- **Login**: Registered users can log in to book tickets.
- **Ticket Booking**: Select journey details like destination, time, date, seat type, and bus type (AC/Non-AC).
- **View Seat Availability**: Dynamically updated seat selection interface.

### Admin Features:
- **Login**: Admin can log in to access the admin panel.
- **Manage Employees and Customers**: Admin can view and edit employee and customer data.
- **View Purchase History**: Access details of tickets purchased.
- **Seat Management**: Admin can manage journey schedules and seat availability.

---

## Technology Stack
- **Framework**: [Qt Framework](https://www.qt.io/) for the GUI application.
- **Database**: SQLite for data storage.
- **Programming Language**: C++ with Qt-specific classes.
- **IDE**: Qt Creator.

---

## Setup Instructions

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/rakibul58/GammaTravels.git
   cd GammaTravels
   ```

2. **Install Qt Framework**:
   Download and install the latest version of the Qt framework from the [official website](https://www.qt.io/download).

3. **Set Up Database**:
   - Place the SQLite database file (`Database.db`) in the appropriate directory (`F:/Gamma Project/` as per the code).
   - The database schema should include tables like `Admins`, `customer`, `employee`, and `Seats`.

4. **Open the Project**:
   - Open `GammaTravels.pro` in Qt Creator.
   - Configure the build environment.

5. **Build and Run**:
   - Build the project using `Ctrl+B`.
   - Run the application to launch the ticket booking system.

---

## Usage Instructions

### **For Users**:
1. Launch the application.
2. Register or log in using existing credentials.
3. Navigate through the user-friendly interface to book tickets.
4. Receive seat plans and payment options via email.

### **For Admins**:
1. Log in to the admin panel.
2. Manage users, employees, and tickets from the admin interface.

---

## Authors
This application is developed by:
- **Muhammed Rakibul Hasan**
- **Tanvir Hasan Sohan**
- **Md Muhtakim Safat Mishon**
- **Shajibul Alam Shihab**
- **Marwan Ibna Alam**
- **Md Nurul Absar Remon**

Contact us for support at:
- `rhrahi14@gmail.com`
- `c193069@ugrad.iiuc.ac.bd`
- `c193071@ugrad.iiuc.ac.bd`
- `c193042@ugrad.iiuc.ac.bd`
- `c193062@ugrad.iiuc.ac.bd`
- `c193050@ugrad.iiuc.ac.bd`

---

## Acknowledgements
Special thanks to the team for their dedication to making this application user-friendly and efficient.

---
