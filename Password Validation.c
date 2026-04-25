#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int numCount = 0;
    int specialCount = 0;
    char specialChars[] = "!@#$%&*";

    // 1. Mengambil input password (menggunakan %s karena password biasanya tidak mengandung spasi)
    if (scanf("%s", password) != 1) return 0;

    // 2. Cek syarat panjang minimal (Minimal 7 karakter)
    int length = strlen(password);
    if (length < 7) {
        printf("Weak\n");
        return 0;
    }

    // 3. Iterasi untuk menghitung jumlah angka dan karakter spesial
    for (int i = 0; i < length; i++) {
        // Cek apakah karakter adalah angka
        if (isdigit(password[i])) {
            numCount++;
        } 
        // Cek apakah karakter termasuk salah satu dari simbol spesial yang ditentukan
        else {
            for (int j = 0; j < strlen(specialChars); j++) {
                if (password[i] == specialChars[j]) {
                    specialCount++;
                    break;
                }
            }
        }
    }

    // 4. Evaluasi akhir berdasarkan syarat minimal
    if (numCount >= 2 && specialCount >= 2) {
        printf("Strong\n");
    } else {
        printf("Weak\n");
    }

    return 0;
}
