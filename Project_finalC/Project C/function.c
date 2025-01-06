#include "function.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
int n = 4;

// Ham xoa khoang trang khi input  
void InputXoaKhoangTrang() {
    while (getchar() != '\n');
}

// Ham hien thi danh muc
void Categories() {
    printf("\n+-------+--------------------+\n");
    printf("|  ID   |      Ten Danh Muc  |\n");
    printf("+-------+--------------------+\n");
    if (n == 0) {
        printf("|   --  | Khong co danh muc  |\n");
    } else {
        for (int i = 0; i < n; i++) {
            printf("| %-5s | %-18s |\n",categories[i].id , categories[i].name);
        }
    }
    printf("+-------+--------------------+\n");
}
// Man hinh hien thi danh sach
void mainScreen() {
    int choice;
    do {
        system("cls");
        printf("\n=== MAN HINH HIEN THI DANH SACH ===\n");
        Categories();
        printf("\nNhan phim:\n");
        printf("[555] Quay lai menu chinh\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        InputXoaKhoangTrang();

    } while (choice != 555);
}

// Ham them danh muc
void addCategory() {
    if (n >= 10) {
        printf("Da du danh muc, khong the them.\n");
        return;
    }
    struct Category newCategory;
    printf("Nhap ID danh muc: ");
    scanf("%s", newCategory.id);
    InputXoaKhoangTrang();

    printf("Nhap ten danh muc: ");
    fgets(newCategory.name, sizeof(newCategory.name), stdin);
    newCategory.name[strcspn(newCategory.name, "\n")] = '\0';

    categories[n++] = newCategory;
    printf("Them danh muc thanh cong.\n");
}
// Man hinh them danh muc
void addScreen() {
    int choice;
    do {
        system("cls");
        printf("\n=== MAN HINH THEM DANH MUC ===\n");
        addCategory();
        printf("\nNhan phim:\n");
        printf("[1] Tiep tuc them\n");
        printf("[555] Quay lai menu chinh\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        InputXoaKhoangTrang();

    } while (choice == 1);
}

// Ham sua danh muc
void editCategory() {
    char idEdit[10];
    printf("Nhap ID danh muc muon sua: ");
    scanf("%s", idEdit);
    InputXoaKhoangTrang();

    for (int i = 0; i < n; i++) {
        if (strcmp(categories[i].id, idEdit) == 0) {
            printf("Nhap ten moi cho danh muc: ");
            fgets(categories[i].name, sizeof(categories[i].name), stdin);
            categories[i].name[strcspn(categories[i].name, "\n")] = '\0';
            printf("Sua danh muc thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay danh muc voi ID da nhap.\n");
}
// Man hinh sua danh muc
void editScreen() {
    int choice ;
    do {
        system("cls");
        printf("\n=== MAN HINH SUA DANH MUC ===\n");
        editCategory();
        printf("\nNhan phim:\n");
        printf("[1] Tiep tuc sua\n");
        printf("[555] Quay lai menu chinh\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        InputXoaKhoangTrang();
    } while (choice == 1);
}

// Ham xoa danh muc
void deleteCategory() {
    char idDelete[10];
    printf("Nhap ID danh muc muon xoa: ");
    scanf("%s", idDelete);
    InputXoaKhoangTrang();

    for (int i = 0; i < n ; i++) {
        if (strcmp(categories[i].id, idDelete) == 0) {
            for (int j = i; j < n - 1; j++) {
                categories[j] = categories[j + 1];
            }
            n--;
            printf("Xoa danh muc thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay danh muc voi ID da nhap.\n");
}

// Man hinh xoa danh muc
void deleteScreen() {
    int choice;
    do {
        system("cls");
        printf("\n=== MAN HINH XOA DANH MUC ===\n");
        deleteCategory();
        printf("\nNhan phim:\n");
        printf("[1] Tiep tuc xoa\n");
        printf("[555] Quay lai menu chinh\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        InputXoaKhoangTrang();
    } while (choice == 1);
}


// Ham sap xep danh muc theo ten
void sortByName(int  sort) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int compare = strcmp(categories[i].name, categories[j].name);
            if ((sort && compare > 0) || (!sort && compare < 0)) {
                struct Category temp = categories[i];
                categories[i] = categories[j];
                categories[j] = temp;
            }
        }
    }
}

// Menu sap xep
void sortMenu() {
    int choice;
    do {
        printf("\n=== MENU SAP XEP DANH MUC THEO TEN ===\n");
        printf("[1] Tang dan\n");
        printf("[2] Giam dan\n");
        printf("[555] Quay lai menu chinh\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        InputXoaKhoangTrang();

        if (choice == 1) {
            sortByName(1); 
            printf("Da sap xep tang dan.\n");
            Categories();
            printf("Nhan phim bat ki de tiep tuc...\n");
            getchar(); 
        } else if (choice == 2) {
            sortByName(0); 
            printf("Da sap xep giam dan.\n");
            Categories();
            printf("Nhan phim bat ki de tiep tuc...\n");
            getchar(); 
        } else if (choice != 555) {
            printf("Lua chon khong hop le.\n");
            printf("Nhan phim bat ki de tiep tuc...\n");
            getchar(); 
        }
    } while (choice != 555);
}


// Ham tim kiem danh muc
void searchCategory() {
    char key[20];
    printf("Nhap tu khoa tim kiem: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    int found = 0;
    printf("\n+-------+--------------------+\n");
    printf("|  ID   |      Ten Danh Muc  |\n");
    printf("+-------+--------------------+\n");
    for (int i = 0; i < n; i++) {
        if (strstr(categories[i].name, key) != NULL) {
            printf("| %-5s | %-18s |\n",
                   categories[i].id,
                   categories[i].name);
            found = 1;
        }
    }
    printf("+-------+--------------------+\n");
    if (!found) {
        printf("Khong tim thay danh muc phu hop.\n");
    }
}

// Man hinh tim kiem danh muc
void searchScreen() {
    int choice;
    do {
        system("cls");
        printf("\n=== MAN HINH TIM KIEM DANH MUC ===\n");
        searchCategory();
        printf("\nNhan phim:\n");
        printf("[1] Tiep tuc tim kiem\n");
        printf("[555] Quay lai menu chinh\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        InputXoaKhoangTrang();

    } while (choice == 1);
}
  
