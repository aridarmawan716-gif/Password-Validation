#include <iostream>
#include <string>
#include <cctype> // Untuk fungsi isdigit()

using namespace std;

int main() {
    string password;
    
    // 1. Input string password
    if (!(cin >> password)) return 0;

    int numCount = 0;
    int specialCount = 0;
    string specialChars = "!@#$%&*";

    // 2. Cek panjang password (Syarat: Minimal 7)
    if (password.length() < 7) {
        cout << "Weak" << endl;
        return 0;
    }

    // 3. Iterasi setiap karakter untuk menghitung angka dan karakter spesial
    for (char c : password) {
        // Cek jika karakter adalah angka
        if (isdigit(c)) {
            numCount++;
        } 
        // Cek jika karakter ada di dalam daftar karakter spesial yang ditentukan
        else if (specialChars.find(c) != string::npos) {
            specialCount++;
        }
    }

    // 4. Evaluasi akhir
    if (numCount >= 2 && specialCount >= 2) {
        cout << "Strong" << endl;
    } else {
        cout << "Weak" << endl;
    }

    return 0;
}
