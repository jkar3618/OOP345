#include <iostream>

void myStrcpy(char* dest, const char* src) {
    
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
}

int main() {
    const char* original = "Copy this string";
    char copy[50];

    myStrcpy(copy, original);

    std::cout << "Copied: " << copy << std::endl;

    return 0;
}