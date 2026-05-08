#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <map>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Library {
private:
    // تخزين الكتب باستخدام map حيث المفتاح هو الـ ID والقيمة مؤشر ذكي للكتاب
    // (مطلوب استخدام map و shared_ptr في الوظيفة)
    std::map<int, std::shared_ptr<Book>> books;

public:
    // إضافة كتاب جديد للمكتبة
    void addBook(int id, std::string title, std::string author) {
        if (books.find(id) != books.end()) {
            throw std::runtime_error("Error: Book with this ID already exists!");
        }
        books[id] = std::make_shared<Book>(id, title, author);
    }

    // البحث عن كتاب بواسطة الـ ID
    void findBook(int id) const {
        auto it = books.find(id);
        if (it != books.end()) {
            std::cout << "Found: " << *(it->second) << std::endl;
        } else {
            // معالجة الاستثناء في حال عدم وجود الكتاب (مطلوب Exception Handling)
            throw std::invalid_argument("Error: Book ID not found.");
        }
    }

    // عرض جميع الكتب باستخدام STL Algorithms
    void displayAll() const {
        if (books.empty()) {
            std::cout << "Library is empty." << std::endl;
            return;
        }
        std::cout << "--- Library Inventory ---" << std::endl;
        for (const auto& pair : books) {
            std::cout << *(pair.second) << std::endl;
        }
    }
};

#endif