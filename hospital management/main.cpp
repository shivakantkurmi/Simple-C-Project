#include <bits/stdc++.h>
using namespace std;

class Person {
public:
    string name, address, phone;
    Person(string name, string address, string phone) : name(name), address(address), phone(phone) {}

    virtual void displayInfo() = 0;
};

class Doctor : public Person {
private:
    string specialty;
    vector<string> patientList;
    int id;

public:
    Doctor(int id, string name, string address, string phone, string specialty)
        : Person(name, address, phone), id(id), specialty(specialty) {}

    void addPatient(string patientName) {
        patientList.push_back(patientName);
    }

    void displayInfo() override {
        system("cls");
        cout << "Doctor Information:" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Specialty: " << specialty << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
        cout << "Patients:" << endl;
        for (const string& patient : patientList) {
            cout << "- " << patient << endl;
        }
        system("pause");
    }

    int getId() const {
        return id;
    }

    string getSpecialty() const {
        return specialty;
    }

    vector<string> getPatients() const {
        return patientList;
    }
};

class Patient : public Person {
private:
    string doctorName;
    double billAmount;
    int id;

public:
    Patient(int id, string name, string address, string phone, string doctorName)
        : Person(name, address, phone), doctorName(doctorName), billAmount(0.0), id(id) {}

    void setBillAmount(double amount) {
        billAmount = amount;
    }

    double getBillAmount() const {
        return billAmount;
    }

    void displayInfo() override {
        system("cls");
        cout << "Patient Information:" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Doctor: " << doctorName << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
        cout << "Bill Amount: $" << billAmount << endl;
        system("pause");
    }

    int getId() const {
        return id;
    }

    string getDoctorName() const {
        return doctorName;
    }
};

class Hospital {
private:
    string hospitalName;
    vector<Doctor> doctors;
    vector<Patient> patients;
    const string dataFile = "hospital_data.txt";

public:
    Hospital(string name) : hospitalName(name) {
        loadData();
    }

    ~Hospital() {
        saveData();
    }

    void addDoctor(const Doctor& doctor) {
        doctors.push_back(doctor);
    }

    void addPatient(const Patient& patient) {
        patients.push_back(patient);
    }

    void loadData() {
        fstream file(dataFile, ios::in | ios::out | ios::app);  // Open the file for both input and output, and append if necessary

        if (!file) {
            // File doesn't exist, create it
            cout << "Creating new data file for the hospital: " << hospitalName << endl;
            saveData();
            return;
        }

        string fileHospitalName;
        getline(file, fileHospitalName);

        // Check if hospital name matches
        if (fileHospitalName != hospitalName) {
            cerr << "The hospital name in the file does not match the input hospital name!" << endl;
            file.close();
            return;
        }

        string line;
        string section;
        while (getline(file, line)) {
            if (line == "[Doctors]") {
                section = "Doctors";
            } else if (line == "[Patients]") {
                section = "Patients";
            } else if (section == "Doctors") {
                stringstream ss(line);
                string idStr, name, address, phone, specialty;
                getline(ss, idStr, '|');
                getline(ss, name, '|');
                getline(ss, address, '|');
                getline(ss, phone, '|');
                getline(ss, specialty, '|');
                int id = stoi(idStr);
                Doctor doctor(id, name, address, phone, specialty);
                doctors.push_back(doctor);
            } else if (section == "Patients") {
                stringstream ss(line);
                string idStr, name, address, phone, doctorName, billStr;
                getline(ss, idStr, '|');
                getline(ss, name, '|');
                getline(ss, address, '|');
                getline(ss, phone, '|');
                getline(ss, doctorName, '|');
                getline(ss, billStr, '|');
                int id = stoi(idStr);
                double bill = stod(billStr);
                Patient patient(id, name, address, phone, doctorName);
                patient.setBillAmount(bill);
                patients.push_back(patient);
            }
        }

        file.close();
    }

    void saveData() {
        // Open the file for reading and writing (create if doesn't exist)
        fstream file(dataFile, ios::in | ios::out | ios::app);

        if (!file) {
            cerr << "Error: Unable to open file for saving data." << endl;
            return;
        }

        // Move to the beginning of the file and rewrite the hospital name
        file.seekp(0, ios::beg);
        file << hospitalName << endl;

        // Write Doctors data
        file << "[Doctors]" << endl;
        for (const auto& doctor : doctors) {
            file << doctor.getId() << "|" << doctor.name << "|" << doctor.address << "|"
                 << doctor.phone << "|" << doctor.getSpecialty() << endl;
        }

        // Write Patients data
        file << "[Patients]" << endl;
        for (const auto& patient : patients) {
            file << patient.getId() << "|" << patient.name << "|" << patient.address << "|"
                 << patient.phone << "|" << patient.getDoctorName() << "|" << patient.getBillAmount() << endl;
        }

        file.close();
    }

    void displayMenu() {
        int choice;
        while (true) {
            system("cls");
            cout << "Hospital Management System - " << hospitalName << endl;
            cout << "1. Add Doctor" << endl;
            cout << "2. Add Patient" << endl;
            cout << "3. Display Doctor Information" << endl;
            cout << "4. Display Patient Information" << endl;
            cout << "5. Change Hospital Name" << endl;  // New option for changing hospital name
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            try {
                if (cin.fail()) {
                    throw invalid_argument("Invalid input. Please enter a number.");
                }
                switch (choice) {
                    case 1: {
                        int id;
                        string name, address, phone, specialty;
                        cout << "Enter doctor's ID: ";
                        cin >> id;
                        cin.ignore();  // To clear the newline character from the buffer
                        cout << "Enter doctor's name: ";
                        getline(cin, name);
                        cout << "Enter doctor's address: ";
                        getline(cin, address);
                        cout << "Enter doctor's phone: ";
                        cin >> phone;
                        cin.ignore();  // To clear the newline character from the buffer
                        cout << "Enter doctor's specialty: ";
                        getline(cin, specialty);
                        Doctor doctor(id, name, address, phone, specialty);
                        addDoctor(doctor);
                        break;
                    }
                    case 2: {
                        int id;
                        string name, address, phone, doctorName;
                        cout << "Enter patient's ID: ";
                        cin >> id;
                        cin.ignore();  // To clear the newline character from the buffer
                        cout << "Enter patient's name: ";
                        getline(cin, name);
                        cout << "Enter patient's address: ";
                        getline(cin, address);
                        cout << "Enter patient's phone: ";
                        cin >> phone;
                        cin.ignore();  // To clear the newline character from the buffer
                        cout << "Enter patient's doctor's name: ";
                        getline(cin, doctorName);
                        Patient patient(id, name, address, phone, doctorName);
                        addPatient(patient);
                        break;
                    }
                    case 3: {
                        int id;
                        cout << "Enter doctor's ID: ";
                        cin >> id;
                        bool found = false;
                        for (Doctor& doctor : doctors) {
                            if (doctor.getId() == id) {
                                doctor.displayInfo();
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            cout << "Doctor not found." << endl;
                            system("pause");
                        }
                        break;
                    }
                    case 4: {
                        int id;
                        cout << "Enter patient's ID: ";
                        cin >> id;
                        bool found = false;
                        for (Patient& patient : patients) {
                            if (patient.getId() == id) {
                                patient.displayInfo();
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            cout << "Patient not found." << endl;
                            system("pause");
                        }
                        break;
                    }
                    case 5: { // Change hospital name logic
                        cout << "Enter new hospital name: ";
                        cin.ignore();
                        getline(cin, hospitalName);
                        loadData();  // Reload data from the file for the new hospital name
                        break;
                    }
                    case 6:
                        return;
                    default:
                        cout << "Invalid choice, please try again." << endl;
                        break;
                }
            } catch (const invalid_argument& e) {
                cin.clear();  // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << e.what() << endl;
                system("pause");
            }
        }
    }
};

int main() {
    string hospitalName;
    cout << "Enter hospital name: ";
    getline(cin, hospitalName);
    Hospital hospital(hospitalName);
    hospital.displayMenu();

    return 0;
}
