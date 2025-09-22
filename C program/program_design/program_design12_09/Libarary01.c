#include <stdio.h>
#include <string.h>

typedef struct {
    char borrowerID[12], name[20];
    int count;
} BorrowerInfo;

typedef struct {
    char bookID[12], title[80], author[80];
    int count;
} BookInfo;

typedef struct {
    int year, month, day;
} DateInfo;

typedef struct {
    BorrowerInfo *borrower;
    BookInfo *book;
    DateInfo borrowDate, dueDate, returnDate;
} CirculateInfo;

int main()
{
    int command;
    BookInfo book[50];
    BorrowerInfo borrower[20];
    CirculateInfo record[200];
    int bookTotal = 0, borrowerTotal = 0, recordTotal = 0; int recordi=0, find;
    while(1)
    {
        char tmpBrID[12], tmpBkID[12];
        
        printf("Menu of NTOU CSE Library Circulation System\n 1. Borrow a book.\n 2. Return a book.\n 3. Print all the borrowers.\n 4. Print all the books.\n 5. Print all the circulation records.\n 6. Add a new borrower.\n 7. Add a new book.\n 0. Exit.\nPlease choose one action: ");
        scanf("%d", &command); if (getchar() == '\r') getchar();
        if( command == 0 ) break;
        switch (command)
        {
        case 1: //borrow book
            printf("\nInput the borrower ID: ");
            fgets(tmpBrID, sizeof(tmpBrID), stdin); strtok(tmpBrID, "\r\n");
            for(int i = 0 ; i < borrowerTotal ; i++)
            {
                if(!strcmp(tmpBrID, borrower[i].borrowerID))
                    record[recordi].borrower = &borrower[i]; //
            }
            printf("Input the boook ID: ");
            fgets(tmpBkID, sizeof(tmpBkID), stdin); strtok(tmpBkID, "\r\n");
            for(int i = 0 ; i < bookTotal ; i++)
            {
                if(!strcmp(tmpBkID, book[i].bookID))
                    record[recordi].book = &book[i];
            }
            printf("Input the borrowing date (year/month/day): ");
            scanf("%d/%d/%d", &record[recordi].borrowDate.year, &record[recordi].borrowDate.month, &record[recordi].borrowDate.day); if (getchar() == '\r') getchar();
            printf("Input the due date (year/month/day): ");
            scanf("%d/%d/%d", &record[recordi].dueDate.year, &record[recordi].dueDate.month, &record[recordi].dueDate.day); if (getchar() == '\r') getchar();
            printf("A circulation record has been created.\n");
            printf("\n");
            recordi++;
            recordTotal++;
            record[recordi].returnDate.year = 0;
            record[recordi].returnDate.month = 0;
            record[recordi].returnDate.day = 0;
            break;
        case 2: //return book
            printf("\nInput the borrower ID: ");
            fgets(tmpBrID, sizeof(tmpBrID), stdin); strtok(tmpBrID, "\r\n");
            for(int i = 0 ; i < borrowerTotal ; i++)
            {
                if(!strcmp(tmpBrID, borrower[i].borrowerID))
                    record[recordi].borrower = &borrower[i]; //
            }
            printf("Input the boook ID: ");
            fgets(tmpBkID, sizeof(tmpBkID), stdin); strtok(tmpBkID, "\r\n");
            for(int i = 0 ; i < bookTotal ; i++)
            {
                for(int j = 0 ; j<recordi ; j++)
                if(!strcmp(tmpBkID, book[i].bookID))
                {
                    record[j].book = &book[i];
                    find=j;
                }
                    
            }
            printf("Input the returning date (year/month/day): ");
            scanf("%d/%d/%d", &record[find].returnDate.year, &record[find].returnDate.month, &record[find].returnDate.day); if (getchar() == '\r') getchar();
            printf("A book has been returned.\n");
            printf("\n");
            break;
        case 3:
            printf("\nData of all borrowers:\n");
            for(int i = 0 ; i < borrowerTotal ; i++)
                printf("Borrower ID: %s, Name: %s\n", borrower[i].borrowerID, borrower[i].name);
            printf("\n");
            break;
        case 4:
            printf("\nData of all books:\n");
            for(int i = 0 ; i < bookTotal ; i++)
            {
                printf("Book ID: %s\n", book[i].bookID);
                printf("  title: %s\n", book[i].title);
                printf("  authors: %s\n", book[i].author);
            }
            printf("\n");
            break;
        case 5: //Print records.
            printf("\nData of all circulation records:");
            for(int i = 0 ; i < recordi ; i++)
                printf("\n%s\t%s\t%d/%d/%d\t%d/%d/%d\t%d/%d/%d\t\n", 
                record[i].borrower[i].borrowerID, record[i].book[i].bookID, 
                record[i].borrowDate.year, record[i].borrowDate.month, record[i].borrowDate.day, 
                record[i].dueDate.year, record[i].dueDate.month, record[i].dueDate.day, 
                record[i].returnDate.year, record[i].returnDate.month, record[i].returnDate.day);
            printf("\n");
            break;
        case 6: //add new borrower
            printf("\nBorrower ID: ");
            fgets(borrower[borrowerTotal].borrowerID, sizeof(borrower[borrowerTotal].borrowerID), stdin); strtok(borrower[borrowerTotal].borrowerID, "\r\n");
            printf("Borrower Name: ");
            fgets(borrower[borrowerTotal].name, sizeof(borrower[borrowerTotal].name), stdin); strtok(borrower[borrowerTotal].name, "\r\n");
            borrowerTotal++;
            printf("\n");
            break;
        case 7:
            printf("\nBook ID: ");
            fgets(book[bookTotal].bookID, sizeof(book[bookTotal].bookID), stdin); strtok(book[bookTotal].bookID, "\r\n");
            printf("Book title: ");
            fgets(book[bookTotal].title, sizeof(book[bookTotal].title), stdin); strtok(book[bookTotal].title, "\r\n");
            printf("Authors: ");
            fgets(book[bookTotal].author, sizeof(book[bookTotal].author), stdin); strtok(book[bookTotal].author, "\r\n");
            bookTotal++;
            printf("\n");
            break;
        case 8:
            printf("\nWhich year? ");
            printf("\nData of all books:");
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        default:
            printf("\ninput a number from \"0\" to \"7\" you asshole !!\n\n");
            break;
        }
    }
    printf("\nThanks for using NTOU CSE Library Circulation System!!\n");
}