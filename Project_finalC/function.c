#include "function.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
int n = 4;
struct Category categories[10] = {
    {"1", "Do Gia Dung"},
    {"2", "Dien thoai"},
    {"3", "Trang Suc"},
    {"4", "Quan Ao"}
};

// Ham xoa khoang trang khi input  
void InputXoaKhoangTrang() {
    while (getchar() != '\n');
}
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
void mainScreen(){
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
        printf("Danh sach danh muc da day, khong the them moi.\n");
        return;
    }
    struct Category newCategory;
    printf("Nhap ID danh muc: ");
    scanf("%s", newCategory.id);
    InputXoaKhoangTrang();
//    // Kiem tra ID
//    if(!validateID(newCategory.id)) {
//        printf("ID khong hop le.\n");
//        return;
//    } else if (!checkID(newCategory.id)) {
//        printf("ID da ton tai.\n");
//        return;
//    }
//    printf("Nhap ten danh muc: ");
//    fgets(newCategory.name, sizeof(newCategory.name), stdin);
//    newCategory.name[strcspn(newCategory.name, "\n")] = '\0';
//    // Ktra ten danh muc
//    if (!validateName(newCategory.name)) {
//        printf("Them danh muc that bai. Ten danh muc khong hop le.\n");
//        return;
//    }
//    // ktra ten bi trung lap
//    if (!checkName(newCategory.name)) {
//        printf("Ten da ton tai.\n");
//        return;
//    
// Ktra ten danh muc
//    if (!validateName(newCategory.name)) {
//        printf("Them danh muc that bai. Ten danh muc khong hop le.\n");
//        return;
//    }
//// ktra ten bi trung lap
//    if (!checkName(newCategory.name)) {
//        printf("Ten da ton tai.\n");
//        return;
//    }
// Kiem tra ID
    if(!validateID(newCategory.id)) {
        return;
    } 
    else if (!checkID(newCategory.id)) {
        return;
    }
    printf("Nhap ten danh muc: ");
    fgets(newCategory.name, sizeof(newCategory.name), stdin);
    newCategory.name[strcspn(newCategory.name, "\n")] = '\0';
//Ktra Ten  
     if(!validateName(newCategory.name)) {
        return;
    } 
    else if (!checkName(newCategory.name)) {
        return;
    }
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
//// ktra do dai id  
//int validateID(char* id) {
//    if (strlen(id) == 0 || strlen(id) > 9) {
//        printf("ID khong hop le (do dai toi da 9 ky tu).\n");
//        return 0;  
//    }
//    return 1;
//}
//
//// ktra do dai ten  
//int validateName(char* name) {
//    if (strlen(name) == 0 || strlen(name) > 19) {
//        printf("Ten khong hop le (do dai toi da 20 ki tu).\n");
//        return 0; 
//    }
//    return 1;     
//}
//
//// Ktra ID trung lap  
//int checkID(char*id) {
//    for (int i = 0; i < n; i++) {
//        if (strcmp(categories[i].id, id) == 0) {
//            printf("ID danh muc da ton tai.\n");
//            return 0;
//        }
//    }
//    return 1;
//}
//// ktra ten bi trung  
//int checkName(char*name) {
//    for (int i = 0; i < n; i++) {
//        if (strcmp(categories[i].name,name) == 0) {
//            printf("Ten danh muc da ton tai.\n");
//            return 0;
//        }
//    }
//    return 1;
//}
//// Doc danh muc tu file
//void readFile(const char *filename) {
//    FILE *file = fopen(filename, "r");
//    if (file == NULL) {
//        printf("Khong the mo file de doc.\n");
//        return;
//    }
//    // Doc tung danh muc tu file
//    n = 0;
//    while (fscanf(file, "%[^,],%[^\n]\n", categories[n].id, categories[n].name) == 2) {
//        n++;
//        if (n >= 10) break;
//    }
//    // Dong file sau khi doc
//    fclose(file);
//    printf("Doc danh muc tu file '%s' thanh cong.\n", filename);
//}
int validateID(char* id) {
    if (strlen(id) == 0 || strlen(id) > 9) {
        printf("ID khong hop le (do dai toi da 9 ky tu).\n");
        return 0;  
    }
    return 1;      
}
int validateName(char* name) {
    if (strlen(name) == 0 || strlen(name) > 19) {
        printf("Ten khong hop le (do dai toi da 20 ki tu).\n");
        return 0;  
    }
    return 1;      
}
int checkID(char* id) {
    for (int i = 0; i < n; i++) {
        if (strcmp(categories[i].id, id) == 0) {
            printf("ID danh muc da ton tai.\n");
            return 0; 
        }
    }
    return 1;    
}
int checkName(char* name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(categories[i].name, name) == 0) {
            printf("Ten danh muc da ton tai.\n");
            return 0;
        }
    }
    return 1;
}
// ham doc file  
void readFile(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Khong the mo file '%s' de doc.\n", filename);
        return;
    }
    n = 0; 
    while (fscanf(f, "%[^,],%[^\n]\n", categories[n].id, categories[n].name) == 2) {
        n++;
        if (n >= 10)
	 break; 
    }
    fclose(f);
    printf("Doc danh muc tu file '%s' thanh cong.\n", filename);
}
// ham viet file  
void writeFile(const char *filename) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Khong the mo file '%s' de ghi.\n", filename);
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(f, "%s,%s\n", categories[i].id, categories[i].name);
    }
    fclose(f);
    printf("Ghi danh muc vao file '%s' thanh cong.\n", filename);
}
void fileMenu() {
    int choice;
    do {
        system("cls");
        printf("\n=== QUAN LY FILE DANH MUC ===\n");
        printf("[1] Doc du lieu tu file\n");
        printf("[2] Ghi du lieu ra file\n");
        printf("[555] Quay lai menu chinh\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        InputXoaKhoangTrang();	

        switch (choice) {
            case 1:
                readFile("category.bin"); 
                printf("Nhan phim bat ki de tiep tuc...\n");
                getchar();
                break;
            case 2:
                writeFile("category.bin");
                printf("Nhan phim bat ki de tiep tuc...\n");
                getchar();
                break;
            case 555:
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
                printf("Nhan phim bat ki de tiep tuc...\n");
                getchar();
        }
    } while (choice != 555);
}
