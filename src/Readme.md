# 🧡 PES Version Control System (Orange Problem)

## 📌 Overview

This project implements a **mini Version Control System (VCS)** similar to Git as part of the Operating Systems Lab.
It demonstrates how files are stored, tracked, and committed using **object storage, trees, and indexing**.

---

## 🎯 Objectives

* Implement **object storage (blob, tree, commit)**
* Build an **index (staging area)**
* Create **tree structures**
* Implement **commit functionality**
* Understand internal working of version control systems

---

## ⚙️ Technologies Used

* C Programming
* Linux / Ubuntu Terminal
* File Handling
* SHA-256 Hashing

---

## 📂 Project Structure

```
os-u4-orange-problem/
│── src/
│   ├── object.c
│   ├── tree.c
│   ├── index.c
│   ├── commit.c
│── report/
│   └── PES_VCS_Report.pdf
│── screenshots/
│   ├── phase1.png
│   ├── phase2.png
│   ├── phase3.png
│   ├── phase4.png
│── README.md
│── Makefile
```

---

## 🚀 How to Run

### 🔹 Compile

```
make clean
make all
```

### 🔹 Initialize Repository

```
./pes init
```

### 🔹 Add Files

```
echo "Hello World" > file1.txt
echo "Test file" > file2.txt

./pes add file1.txt file2.txt
```

### 🔹 Check Status

```
./pes status
```

### 🔹 Commit Changes

```
./pes commit -m "First commit"
```

### 🔹 View Log

```
./pes log
```

---

## 📸 Screenshots

### Phase 1 – Object Storage

![Phase 1](screenshots/phase1.png)

### Phase 2 – Tree Objects

![Phase 2](screenshots/phase2.png)

### Phase 3 – Indexing & Staging

![Phase 3](screenshots/phase3.png)

### Phase 4 – Commit & Log

![Phase 4](screenshots/phase4.png)

---

## 📄 Report

Full report available in:

```
report/PES_VCS_Report.pdf
```

---

## ✨ Features

* Content-addressable storage
* Tree-based directory structure
* Staging area (index)
* Commit history tracking
* Hash-based integrity

---

## ⚠️ Notes

* Hash values differ across systems
* Implemented for educational purposes
* Tested on Ubuntu

---

## 👤 Author

**AMITHBA**
SRN: PESU1UG24AM032

---

## ⭐ Conclusion

This project provides practical understanding of how systems like Git internally manage files, commits, and history using hashing and structured storage.

---
