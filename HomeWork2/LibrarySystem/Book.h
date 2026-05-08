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
// 1. تطبيق هرمية Shape (مطلب: abstract base + derived مع unique_ptr)
class Shape {
public:
    virtual void draw() const = 0; // دالة افتراضية بحتة تجعل الصنف مجرداً
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Circle for the Library Logo!" << std::endl;
    }
};

// 2. تطبيق Class Template (مطلب: Stack<T> مخصصة)
template <typename T>
class Stack {
private:
    std::vector<T> elements;
public:
    void push(T const& elem) { elements.push_back(elem); }
    void pop() { if (!elements.empty()) elements.pop_back(); }
    T top() const { return elements.back(); }
};

#endif