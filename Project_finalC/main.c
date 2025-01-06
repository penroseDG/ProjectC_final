#include <stdio.h>
#include <stdlib.h>
#include "function.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main() {
    int choice;
    do {
        system("cls");
        printf("\n=== MENU QUAN LY DANH MUC ===\n");
        printf("[1] Hien thi danh sach\n");
        printf("[2] Them danh muc\n");
        printf("[3] Sua danh muc\n");
        printf("[4] Xoa danh muc\n");
        printf("[5] Tim kiem danh muc\n");
        printf("[6] Sap xep danh muc theo ten\n");
        printf("[7] Quan ly file\n");
        printf("[0] Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        InputXoaKhoangTrang();

        switch (choice) {
            case 1:
                mainScreen();
                break;
            case 2:
                addScreen();
                break;
            case 3:
                editScreen();
                break;
            case 4:
                deleteScreen();
                break;
            case 5:
                searchScreen(); 
                break;
            case 6:
                sortMenu();
                break; 
            case 7:
                fileMenu();
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }

    } while (choice != 0);
    return 0;
}
