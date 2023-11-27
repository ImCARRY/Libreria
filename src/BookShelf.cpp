/**
 * Implementation of BookShelf class
 * @author Federico Borsati
 * @matricola 2046106
 * @gruppo JFK
*/
#include <iostream>
#include <stdexcept>
#include "BookShelf.h"


BookShelf::BookShelf() : buffer_(nullptr), size_(0), capacity_(0) {}

BookShelf::~BookShelf() {
    delete[] buffer_;
}

BookShelf::BookShelf(const BookShelf& other) : size_(other.size_), capacity_(other.capacity_) {
    buffer_ = new Book[capacity_];
    for (int i = 0; i < size_; i++) {
        buffer_[i] = other.buffer_[i];
    }
}

BookShelf& BookShelf::operator=(const BookShelf& other) {
    if (this != &other) {
        delete[] buffer_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        buffer_ = new Book[capacity_];
        for (int i = 0; i < size_; i++) {
            buffer_[i] = other.buffer_[i];
        }
    }
    return *this;
}

Book& BookShelf::at(int index) {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return buffer_[index];
}

// Accessor with boundary check (const version)
const Book& BookShelf::at(int index) const {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return buffer_[index];
}

// Accessor with double overloading of operator[]
Book& BookShelf::operator[](int index) {
    return buffer_[index];
}

// Accessor with double overloading of operator[] (const version)
const Book& BookShelf::operator[](int index) const {
    return buffer_[index];
}

// Function to add an element at the end
void BookShelf::push_back(Book value) {
    if (size_ == capacity_) {
        // Reallocate a larger buffer
        int newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2;
        Book* newBuffer = new Book[newCapacity];
        for (int i = 0; i < size_; i++) {
            newBuffer[i] = buffer_[i];
        }
        delete[] buffer_;
        buffer_ = newBuffer;
        capacity_ = newCapacity;
    }
    buffer_[size_] = value;
    size_++;
}

// Function to remove the last element
void BookShelf::pop_back() {
    if (size_ > 0) {
        size_--;
    }
}

// Function to reserve a minimum buffer size
void BookShelf::reserve(int minCapacity) {
    if (minCapacity > capacity_) {
        Book* newBuffer = new Book[minCapacity];
        for (int i = 0; i < size_; i++) {
            newBuffer[i] = buffer_[i];
        }
        delete[] buffer_;
        buffer_ = newBuffer;
        capacity_ = minCapacity;
    }
}