# Practical 12 - Library Management System

A small console app for a library.

## Features
- Add books (id + title)
- List all books with their status
- Issue and return books
- Saves to `books.txt` when you exit and loads it again on the next start
- Handles errors: wrong book id, issuing an already issued book, wrong menu choice

## Concepts used
- Classes and inheritance (`Item` -> `Book`) with a virtual `show()`
- STL `vector` to store the books
- Exceptions (`throw` / `catch`)
- File handling (`ofstream` / `ifstream`)

## Run
```
g++ -std=c++17 library.cpp -o library
./library
```

## Class diagram
```
Item (abstract)          Library
- id, title              - books : vector<Book>
+ show()                 + add() list() issue()
  |                      + giveBack() save() load()
Book
- issued
+ show()
```
