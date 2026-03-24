# patient-management-system
# 🏥 Patient Management System (C)

A simple console-based Patient Management System written in C.  
This project allows users to manage patient records efficiently using file handling.

---

## 📌 Features

- ➕ Add new patient records  
- 📋 View all patients  
- 🔍 Search patient by ID  
- ✏️ Update patient details  
- ❌ Delete patient records  
- 💾 Save and load data using file handling  

---

## 🛠️ Technologies Used

- C Programming Language  
- File Handling (CSV format)  

---

## 📂 Project Structure

```
patient_management.c   # Main source code
patients.txt           # Data storage file
README.md              # Project documentation
```

---

## ▶️ How to Run
### 1. Compile the program
```bash
gcc patient_management.c -o app
./app
```



## 📊 How It Works

- Patient data is stored in a structured format using `struct`
- Records are saved in a file (`patients.txt`) using CSV format
- Data is automatically loaded when the program starts

---

## ⚠️ Notes

- Maximum number of patients: 100  
- File (`patients.txt`) must be in the same directory  
- IDs are auto-generated  

---

## 🚀 Future Improvements

- Search by name  
- Input validation  
- Better user interface (menu design)  
- Database integration (MySQL)  
- Web-based version  

---

## 👨‍💻 Author

- Rubanthanu

