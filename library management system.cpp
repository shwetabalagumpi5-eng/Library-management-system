#include <iostream>
#include <fstream>
using namespace std;

class MediaItem {
public:
    int id;
    string title;

    MediaItem(int i, string t) {
        id = i;
        title = t;
    }

    virtual void display() {
        cout << id << " " << title << endl;
    }

    void checkout() {
        cout << title << " is issued." << endl;
    }

    void returnItem(int days) {
        cout << "Fine = Rs." << days * 2 << endl;
    }
};

class Book : public MediaItem {
public:
    Book(int i, string t) : MediaItem(i, t) {}

    void display() {
        cout << "Book: " << id << " " << title << endl;
    }
};

class Journal : public MediaItem {
public:
    Journal(int i, string t) : MediaItem(i, t) {}

    void display() {
        cout << "Journal: " << id << " " << title << endl;
    }
};

int main() {
    Book b(1, "C++");
    Journal j(2, "Science");

    b.display();
    j.display();

    b.checkout();
    b.returnItem(3);

    ofstream file("library.txt");
    file << "C++\nScience";
    file.close();

    return 0;
}

