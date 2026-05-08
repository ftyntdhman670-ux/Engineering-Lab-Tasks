#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <memory>

// تعريف صنف الكتاب
class Book {
private:
    int id;
    std::string title;
    std::string author;

public:
    // المشيد (Constructor)
    Book(int id, std::string title, std::string author) 
        : id(id), title(title), author(author) {}

    // دالة للحصول على المعرف (ID)
    int getId() const { return id; }

    // تحميل عامل التشغيل == للمقارنة بين كتابين عن طريق الـ ID (مطلوب في الوظيفة)
    bool operator==(const Book& other) const {
        return this->id == other.id;
    }

    // تحميل عامل التشغيل << لطباعة بيانات الكتاب بسهولة (مطلوب في الوظيفة)
    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << "ID: " << book.id << " | Title: " << book.title << " | Author: " << book.author;
        return os;
    }
};

#endif