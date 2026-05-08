#include "Library.h"
#include <iostream>

int main() {
    Library myLibrary;

    try {
        // 1. إضافة بعض الكتب للمكتبة
        myLibrary.addBook(101, "C++ Programming", "Bjarne Stroustrup");
        myLibrary.addBook(102, "Data Structures", "Mark Allen Weiss");
        myLibrary.addBook(103, "Clean Code", "Robert C. Martin");

        // 2. عرض جميع الكتب
        myLibrary.displayAll();
        std::cout << "--------------------------" << std::endl;

        // 3. البحث عن كتاب موجود (تجربة النجاح)
        std::cout << "Searching for ID 102..." << std::endl;
        myLibrary.findBook(102);
        std::cout << "--------------------------" << std::endl;

        // 4. تجربة معالجة الاستثناءات (البحث عن ID غير موجود)
        // هذا الجزء سيقوم برمي Exception كما طلب الدكتور
        std::cout << "Searching for ID 999 (Non-existent)..." << std::endl;
        myLibrary.findBook(999);

    } catch (const std::exception& e) {
        // التقاط الخطأ وطباعته (Exception Handling)
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    return 0;
}