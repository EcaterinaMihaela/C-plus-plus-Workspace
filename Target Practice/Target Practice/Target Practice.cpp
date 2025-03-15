#include <stdio.h>

int calculeaza_puncte(int x, int y) {
    // Calculăm distanța față de centrul țintei (5, 5) și returnăm punctul corespunzător.
    int dist = (x - 5) * (x - 5) + (y - 5) * (y - 5);
    if (dist <= 1) return 5;  // În interiorul cercului de puncte 5
    if (dist <= 4) return 4;  // În interiorul cercului de puncte 4
    if (dist <= 9) return 3;  // În interiorul cercului de puncte 3
    if (dist <= 16) return 2; // În interiorul cercului de puncte 2
    return 1;  // În interiorul cercului de puncte 1
}

int main() {
    FILE* f;
    // Deschidem fișierul folosind fopen_s
    errno_t err = fopen_s(&f, "input.txt", "r");

    if (err != 0) {
        printf("Nu s-a putut deschide fișierul.\n");
        return 1;
    }

    int t;
    fscanf_s(f, "%d", &t);  // Citim numărul de test case-uri
    while (t--) {
        int total_puncte = 0;
        char tinta[10][10];

        // Citim ținta pentru testul curent
        for (int i = 0; i < 10; i++) {
            fscanf_s(f, "%s", tinta[i]);  // Citim o linie de 10 caractere din fișier
        }

        // Parcurgem ținta și calculăm punctele pentru fiecare săgeată
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (tinta[i][j] == 'X') {
                    total_puncte += calculeaza_puncte(i, j);
                }
            }
        }

        // Afișăm rezultatul pentru testul curent
        printf("%d\n", total_puncte);
    }

    fclose(f);  // Închidem fișierul după procesare
    return 0;
}
