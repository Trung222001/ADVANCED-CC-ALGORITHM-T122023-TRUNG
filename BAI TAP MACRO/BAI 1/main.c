#include <stdio.h>

// Hành động 1: In thông điệp lỗi
void printError(const char *message) {
   printf("Error: %s\n", message);
}

// Hành động 2: In thông điệp cảnh báo
void printWarning(const char *message) {
   printf("Warning: %s\n", message);
}

//Bổ sung nội dung vào

// Hành động 3: In thông điệp thông tin
void printInfo(const char *message) {
    printf("Info: %s\n", message);
}

// Hành động 4: In thông điệp gỡ lỗi
void printDebug(const char *message) {
    printf("Debug: %s\n", message);
}

// Hành động 5: In thông điệp khẩn cấp
void printCritical(const char *message) {
    printf("Critical: %s\n", message);
}

// Hành động 6: In thông điệp thành công
void printSuccess(const char *message) {
    printf("Success: %s\n", message);
}


// Macro xử lý lỗi
#define HANDLE_ERROR(condition, action, message) do { \
   if(condition){\
        action(message);\
   }\
} while(0)

int main() {
   int x = 0;

   // Sử dụng HANDLE_ERROR với các hành động khác nhau
   HANDLE_ERROR(x == 10, printError, "x is not equal to 10");
   HANDLE_ERROR(5 < x && x < 10, printWarning, "x is less than 10 and more than 5");
   HANDLE_ERROR(x > 10, printInfo, "x is more than 10");
    HANDLE_ERROR(x == 5, printDebug, "x is equal to  5");
    HANDLE_ERROR(0 < x &&  x < 5 , printCritical, "x is more than 0 and less than 5");
    HANDLE_ERROR(x == 0, printSuccess, "x is not equal to 0");
   return 0;
}