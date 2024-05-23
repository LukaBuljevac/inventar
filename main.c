#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"

void displayMenu() {
    printf("1. Unos proizvoda\n");
    printf("2. Ispis proizvoda\n");
    printf("3. Brisanje proizvoda\n");
    printf("4. Uredjivanje proizvoda\n");
    printf("5. Sortiranje proizvoda po cijeni (uzlazno)\n");
    printf("6. Sortiranje proizvoda po cijeni (silazno)\n");
    printf("7. Pretraga po tipu\n");
    printf("8. Pretraga po proizvodacu\n");
    printf("9. Pretraga po ID-u\n");
    printf("10. Brisanje proizvoda po ID-u\n");
    printf("11. Brisanje svih proizvoda\n");
    printf("12. Izlaz\n");
    printf("13. Brisanje datoteke\n");
    printf("14. Preimenovanje datoteke\n\n");
}

int main() {
    loadProducts(); // Ucitaj proizvode iz datoteke
    int choice;
    do {
        displayMenu(); // Prikazi izbornik
        choice = getValidInt("Unesite svoj izbor: ");
        switch (choice) {
        case 1:
            insertProduct();
            break;
        case 2:
            printProducts();
            break;
        case 3:
            deleteProduct();
            break;
        case 4:
            editProduct();
            break;
        case 5:
            sortProductsByPriceAscending();
            printProducts();  // Prikaz sortiranih proizvoda nakon sortiranja
            break;
        case 6:
            sortProductsByPriceDescending();
            printProducts();  // Prikaz sortiranih proizvoda nakon sortiranja
            break;
        case 7:
            searchByType();
            break;
        case 8:
            searchByManufacturer();
            break;
        case 9:
            searchByID();
            break;
        case 10:
            deleteProductByID();
            break;
        case 11:
            deleteAllProducts();
            break;
        case 12:
            printf("Izlaz...\n\n");
            break;
        case 13:
            deleteInventoryFile();
            break;
        case 14:
            renameInventoryFile();
            break;
        default:
            printf("Neispravan izbor. Molimo pokusajte ponovno.\n\n");
        }
    } while (choice != 12);

    if (inventory != NULL) {
        free(inventory); // Oslobadjanje memorije prije izlaska
        inventory = NULL; // Anuliranje pokazivača kako bi se spriječilo double free
    }

    return 0;
}
