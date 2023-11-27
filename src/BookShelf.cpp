
#include <iostream>
#include <stdexcept>
#include "BookShelf.h"


BookShelf::BookShelf() : buffer(nullptr), size(0), capacity(0) {}

BookShelf::~BookShelf() {
    delete[] buffer;
}

BookShelf::BookShelf(const BookShelf& other) : size(other.size), capacity(other.capacity) {
    buffer = new Book[capacity];
    for (int i = 0; i < size; i++) {
        buffer[i] = other.buffer[i];
    }
}

BookShelf& BookShelf::operator=(const BookShelf& other) {
    if (this != &other) {
        delete[] buffer;
        size = other.size;
        capacity = other.capacity;
        buffer = new Book[capacity];
        for (int i = 0; i < size; i++) {
            buffer[i] = other.buffer[i];
        }
    }
    return *this;
}

Book& BookShelf::at(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return buffer[index];
}

// Accessor with boundary check (const version)
const Book& BookShelf::at(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return buffer[index];
}

// Accessor with double overloading of operator[]
Book& BookShelf::operator[](int index) {
    return buffer[index];
}

// Accessor with double overloading of operator[] (const version)
const Book& BookShelf::operator[](int index) const {
    return buffer[index];
}

// Function to add an element at the end
void BookShelf::push_back(Book value) {
    if (size == capacity) {
        // Reallocate a larger buffer
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        Book* newBuffer = new Book[newCapacity];
        for (int i = 0; i < size; i++) {
            newBuffer[i] = buffer[i];
        }
        delete[] buffer;
        buffer = newBuffer;
        capacity = newCapacity;
    }
    buffer[size] = value;
    size++;
}

// Function to remove the last element
void BookShelf::pop_back() {
    if (size > 0) {
        size--;
    }
}

// Function to reserve a minimum buffer size
void BookShelf::reserve(int minCapacity) {
    if (minCapacity > capacity) {
        Book* newBuffer = new Book[minCapacity];
        for (int i = 0; i < size; i++) {
            newBuffer[i] = buffer[i];
        }
        delete[] buffer;
        buffer = newBuffer;
        capacity = minCapacity;
    }
}