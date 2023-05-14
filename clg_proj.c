#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Book structure
typedef struct
{
    char title[50];
    char author[50];
    int id;
    int available;
} Book;

// Library structure
typedef struct
{
    Book books[MAX_BOOKS];
    int num_books;
} Library;

// Function to add a book to the library
void add_book(Library *lib)
{
    Book book;
    printf("Enter book title: ");
    scanf("%s", book.title);
    printf("Enter book author: ");
    scanf("%s", book.author);
    printf("Enter book ID: ");
    scanf("%d", &book.id);
    printf("Enter number of available copies: ");
    scanf("%d", &book.available);
    lib->books[lib->num_books++] = book;
    printf("Book added successfully!\n");
}

// Function to display all books in the library
void display_books(Library *lib)
{
    printf("Books in library:\n");
    for (int i = 0; i < lib->num_books; i++)
    {
        printf("%d. %s by %s (ID: %d, available: %d)\n",
               i + 1, lib->books[i].title, lib->books[i].author,
               lib->books[i].id, lib->books[i].available);
    }
}

// Function to find a book by its ID
int find_book_by_id(Library *lib, int id)
{
    for (int i = 0; i < lib->num_books; i++)
    {
        if (lib->books[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

// Function to borrow a book
void borrow_book(Library *lib)
{
    int id;
    printf("Enter book ID: ");
    scanf("%d", &id);
    int book_idx = find_book_by_id(lib, id);
    if (book_idx == -1)
    {
        printf("Book not found!\n");
        return;
    }
    if (lib->books[book_idx].available == 0)
    {
        printf("No copies available for borrowing!\n");
        return;
    }
    lib->books[book_idx].available--;
    printf("Book borrowed successfully!\n");
}

// Function to return a book
void return_book(Library *lib)
{
    int id;
    printf("Enter book ID: ");
    scanf("%d", &id);
    int book_idx = find_book_by_id(lib, id);
    if (book_idx == -1)
    {
        printf("Book not found!\n");
        return;
    }
    lib->books[book_idx].available++;
    printf("Book returned successfully!\n");
}

// Main function
int main()
{
    Library lib;
    lib.num_books = 0;
    int choice;
    do
    {
        printf("\n");
        printf("1. Add book\n");
        printf("2. Display books\n");
        printf("3. Borrow book\n");
        printf("4. Return book\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_book(&lib);
            break;
        case 2:
            display_books(&lib);
            break;
        case 3:
            borrow_book(&lib);
            break;
        case 4:
            return_book(&lib);
            break;
        case 0:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    } while (choice != 0);
    return 0;
}
