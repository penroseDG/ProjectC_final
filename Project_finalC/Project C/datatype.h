#include<stdbool.h> 

struct Category {
    char id[10];
    char name[20];
};

// Mang danh muc
struct Category categories[10] = {
    {"1", "Do Gia Dung"},
    {"2", "Dien thoai"},
    {"3", "Trang Suc"},
    {"4", "Quan Ao"}
};
