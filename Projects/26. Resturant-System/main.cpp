#include <iostream>

using namespace std;

int main()
{
    cout << "\t\t|\t          GOOD Evening!!    \t\t    |" << endl;
    cout << "\t\t|\t    WELCOME TO OUR RESTAURANT \t\t    |" << endl;
    cout << "\t\t|\t     PLEASED TO MEET YOU SIR  \t\t    |" << endl;
    cout << "\t\t|\t     OUR MENU IS GIVEN BELOW  \t\t    |" << endl;
    cout << "\t\t|---------------------------------------------------|" << endl;
    cout << "\t\t\t\t -----:MENU:-----" << endl;
    char order;
    int check = 0, quantity;
    long long password;
    int total = 0, total1 = 0, total2 = 0, total3 = 0, total4 = 0, total5 = 0;
    char choice;
    int menuQty[15] = {20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20};
    string username;
    string menuavail[20] = {"CHICKEN FAJITA", "CHICKEN TIKKA", "SPECIAL      ", "ZINGER", "CHICKEN", "BEEF", "HOT & SPICY", "SALTED     ", "SIMPLE     ", "FRUIT", "RUSSIAN", "GREEN", "COKE", "SPRITE", "FANTA"};
    const char pizza[3][100] = {"CHICKEN FAJITA", "CHICKEN TIKKA", "SPECIAL PIZZA"};
    const char burg[3][100] = {"ZINGER BURGER", "CHICKEN BURGER", "BEEF BURGER"};
    const char wing[3][100] = {"HOT & SPICY WINGS", "SALTED WINGS", "SIMPLE WINGS"};
    const char salad[3][100] = {"FRUIT SALAD", "RUSSIAN SALAD", "GREEN SALAD"};
    const char drink[3][100] = {"COKE", "SPRITE", "FANTA"};
    int flavour{};
    int burger{};
    int wings{}, salads{}, drinks{};
    cout << "\t\t|----------------  ** PIZZA'S  **  -----------------|" << endl;
    cout << "\t\t|----------------  ** BURGER'S **  -----------------|" << endl;
    cout << "\t\t|----------------  **  WING'S  **  -----------------|" << endl;
    cout << "\t\t|----------------  ** SALAD'S  **  -----------------|" << endl;
    cout << "\t\t|----------------  ** DRINK'S  **  -----------------|" << endl;
    cout << "\t\t \\\\\\\\\\\\\\PRESS 'A' FOR ADMIN ACCESS DETAIL'S/////////" << endl;
    cout << endl;
    cout << "ENTER 'A' FOR ADMIN STOCK" << endl;
    cout << "ENTER 'O' TO START ORDER" << endl;
order:
    cout << "Enter your choice ('A' & 'a' FOR ADMIN) & ('o' & 'O' FOR ORDER): " << endl;
    cin >> choice;
    if (choice == 'A' || choice == 'a')
    {
        cout << "ENTER RESTAURANT USERNAME & PASSWORD" << endl;
        cout << "\t\tUSERNAME: ";
        cin >> username;
        cout << "\t\tPASSWORD: ";
        cin >> password;
        if (username == "imran" || username == "IMRAN" && password == 1234)
        {
            cout << "ACCESSED FOR STOCK!!" << endl;
            cout << "-------------------------------------------------------" << endl;
            cout << "PIZZA'S:" << endl;
            for (int i = 0; i <= 2; i++)
            {
                cout << menuavail[i] << "\t\t\t" << menuQty[i] << " " << endl;
            }
            cout << "-------------------------------------------------------" << endl;
            cout << "BURGER'S: " << endl;
            for (int i = 3; i <= 5; i++)
            {
                cout << menuavail[i] << "\t\t\t\t" << menuQty[i] << " " << endl;
            }
            cout << "-------------------------------------------------------" << endl;
            cout << "WING'S: " << endl;
            for (int i = 6; i <= 8; i++)
            {
                cout << menuavail[i] << "\t\t\t" << menuQty[i] << " " << endl;
            }
            cout << "-------------------------------------------------------" << endl;
            for (int i = 9; i <= 11; i++)
            {
                cout << menuavail[i] << "\t\t\t\t" << menuQty[i] << " " << endl;
            }
            cout << "-------------------------------------------------------" << endl;
            for (int i = 12; i <= 14; i++)
            {
                cout << menuavail[i] << "\t\t\t\t" << menuQty[i] << " " << endl;
            }
            cout << "-------------------------------------------------------" << endl;
        }
        else
        {
            cout << "ACCESS DENIED!!" << endl;
            goto order;
        }
    }
    else
        (choice == 'O' || choice == 'o');
    {
        cout << "-----------------------------------------------------------------------------------------" << endl;
        cout << "START ORDER: " << endl;
        cout << "('p': PIZZA, 'b' : BURGER, 'w' : WINGS, 's' : SALAD, 'd' : DRINK, '0' : ORDER COMPLETE): " << endl;
        cout << "ENTER KEYWORDS (p, b, w, s, d, '0') TO GET QUIERIES ABOUT MENU" << endl;
        cin >> (order);
        switch (order)
        {
        case '0':
        {
            break;
        }
        case 'p':
        {
            cout << "CHOOSE YOUR DESIRED PIZZA: " << endl;
            cout << " ITEMS: \t\t\t      PRICE:" << endl;
            cout << "1. CHICKEN FAJITA\t         --- Rs. 1200" << endl;
            cout << "2. CHICKEN TIKKA\t         --- Rs. 1300" << endl;
            cout << "3. SPECIAL\t                 --- Rs. 1500" << endl;
            cout << "0.  DONE" << endl;
            cout << "Enter flavour(1, 2, 3, 0)" << endl;
            cin >> flavour;

            switch (flavour)
            {

            case 0:
            {
                break;
            }
            case 1:
            {
                cout << "How many chicken fajita would you like: ";
                cin >> quantity;
                total1 = total1 + (quantity * 1200);
                cout << "" << endl;
                cout << "|---------------------SELECTED CART------------------|" << endl;
                cout << "| ITEM:                     QTY:             PRICE:  |" << endl;
                cout << "|                                                    |" << endl;
                cout << "| " << pizza[0] << "             " << quantity << "            Rs. " << total1 << "   |" << endl;
                cout << "|                                                    |" << endl;
                cout << "|----------------------------------------------------|" << endl;
                cout << "|  GRAND TOTAL :                          Rs. " << total1 << "   |" << endl;
                cout << "||" << endl;
                break;
                menuQty[0]--;
            }
            case 2:
            {

                cout << "How many chicken tikka would you like: ";
                cin >> quantity;
                total1 = total1 + (quantity * 1300);
                cout << "" << endl;
                cout << "|---------------------SELECTED CART------------------|" << endl;
                cout << "| ITEM:                     QTY:             PRICE:  |" << endl;
                cout << "|                                                    |" << endl;
                cout << "| " << pizza[1] << "              " << quantity << "            Rs. " << total1 << "   |" << endl;
                cout << "|                                                    |" << endl;
                cout << "|----------------------------------------------------|" << endl;
                cout << "|  GRAND TOTAL :                          Rs. " << total1 << "   |" << endl;
                cout << "||" << endl;
                menuQty[1] = menuQty[1] - quantity;
                break;
            }
            case 3:
            {
                cout << "How many special pizza would you like: ";
                cin >> quantity;
                total1 = total1 + (quantity * 1500);
                cout << "|" << endl;
                cout << "|---------------------SELECTED CART-------------------|" << endl;
                cout << "| ITEM:                     QTY:             PRICE:   |" << endl;
                cout << "|                                                     |" << endl;
                cout << "| " << pizza[2] << "              " << quantity << "             Rs. " << total1 << "   |" << endl;
                cout << "|                                                     |" << endl;
                cout << "|-----------------------------------------------------|" << endl;
                cout << "|  GRAND TOTAL :                           Rs. " << total1 << "   |" << endl;
                cout << "|_|" << endl;
                menuQty[2] = menuQty[2] - quantity;
                ;
                break;
            }
            }
            goto order;
            break;
        }
        case 'b':
        {

            cout << "CHOOSE YOUR DESIRED BURGER: " << endl;
            cout << "1. ZINGER BURGER\t                --- Rs. 300" << endl;
            cout << "2. CHICKEN BURGER\t                --- Rs. 200" << endl;
            cout << "3. BEEF BURGER\t                        --- Rs. 700" << endl;
            cout << "0.    DONE" << endl;
            cout << "Enter Burger(1, 2, 3, 0)" << endl;
            cin >> burger;

            switch (burger)
            {
            case 0:
                break;
            case 1:

                cout << "How many Zinger would you like: " << endl;
                cin >> quantity;
                total2 = total2 + (quantity * 300);
                cout << "" << endl;
                cout << "|---------------------SELECTED CART------------------|" << endl;
                cout << "| ITEM:                     QTY:             PRICE:  |" << endl;
                cout << "|                                                    |" << endl;
                cout << "| " << burg[0] << "              " << quantity << "             Rs. " << total2 << "   |" << endl;
                cout << "|                                                    |" << endl;
                cout << "|----------------------------------------------------|" << endl;
                cout << "|  GRAND TOTAL :                           Rs. " << total2 << "   |" << endl;
                cout << "||" << endl;
                menuQty[3] = menuQty[3] - quantity;
                break;

            case 2:
                cout << "How many Chicken burger would you like: " << endl;
                cin >> quantity;
                total2 = total2 + (200 * quantity);
                cout << "" << endl;
                cout << "|---------------------SELECTED CART------------------|" << endl;
                cout << "| ITEM:                     QTY:             PRICE:  |" << endl;
                cout << "|                                                    |" << endl;
                cout << "| " << burg[1] << "              " << quantity << "           Rs. " << total2 << "   |" << endl;
                cout << "|                                                    |" << endl;
                cout << "|----------------------------------------------------|" << endl;
                cout << "|  GRAND TOTAL :                          Rs. " << total2 << "   |" << endl;
                cout << "||" << endl;
                break;
                menuQty[4]--;
            case 3:
            {
                cout << "How many Beef burger would you like: " << endl;
                cin >> quantity;
                total2 = total2 + (700 * quantity);
                cout << "" << endl;
                cout << "|---------------------SELECTED CART------------------|" << endl;
                cout << "| ITEM:                     QTY:             PRICE:  |" << endl;
                cout << "|                                                    |" << endl;
                cout << "| " << burg[2] << "                " << quantity << "            Rs. " << total2 << "   |" << endl;
                cout << "|                                                    |" << endl;
                cout << "|----------------------------------------------------|" << endl;
                cout << "|  GRAND TOTAL :                          Rs. " << total2 << "   |" << endl;
                cout << "||" << endl;
                menuQty[5] = menuQty[5] - quantity;
                break;
            }
            }
            goto order;
            break;
        }

        case 'w':
        {
            cout << "CHOOSE YOUR YOUR DESIRED WINGS" << endl;
            cout << "1. HOT & SPICY WINGS (6 - pieces)\t--- Rs. 400" << endl;
            cout << "2. SALTED WINGS      (6 - pieces)\t--- Rs. 300" << endl;
            cout << "3. SIMPLE WINGS      (6 - pieces)\t--- Rs. 200" << endl;
            cout << "0.     DONE" << endl;
            cout << "ENTER WINGS(1, 2, 3, 0)" << endl;
            cin >> wings;
            switch (wings)
            {
            case 0:
            {
                break;
            }
            case 1:
            {
                cout << "How many Hot & Spicy wings would you like to order: " << endl;
                cin >> quantity;
                total3 = total3 + (quantity * 400);
                cout << "" << endl;
                cout << "|---------------------SELECTED CART------------------|" << endl;
                cout << "| ITEM:                     QTY:             PRICE:  |" << endl;
                cout << "|                                                    |" << endl;
                cout << "| " << wing[0] << "          " << quantity << "            Rs. " << total3 << "   |" << endl;
                cout << "|                                                    |" << endl;
                cout << "|----------------------------------------------------|" << endl;
                cout << "|  GRAND TOTAL :                          Rs. " << total3 << "   |" << endl;
                cout << "||" << endl;
                break;
                menuQty[6] = menuQty[6] - quantity;
            }
            case 2:
            {
                cout << "How many Salted wings would you like to order: " << endl;
                cin >> quantity;
                total3 = total3 + (quantity * 300);
                cout << "" << endl;
                cout << "|---------------------SELECTED CART------------------|" << endl;
                cout << "| ITEM:                     QTY:             PRICE:  |" << endl;
                cout << "|                                                    |" << endl;
                cout << "| " << wing[1] << "               " << quantity << "            Rs. " << total3 << "   |" << endl;
                cout << "|                                                    |" << endl;
                cout << "|----------------------------------------------------|" << endl;
                cout << "|  GRAND TOTAL :                          Rs. " << total3 << "   |" << endl;
                cout << "||" << endl;
                menuQty[7] = menuQty[7] - quantity;
                break;
            }
            case 3:
            {
                cout << "How many Simple wings would you like to order: " << endl;
                cin >> quantity;
                total3 = total3 + (quantity * 500);
                cout << "" << endl;
                cout << "|---------------------SELECTED CART------------------|" << endl;
                cout << "| ITEM:                     QTY:             PRICE:  |" << endl;
                cout << "|                                                    |" << endl;
                cout << "| " << wing[2] << "               " << quantity << "            Rs. " << total3 << "   |" << endl;
                cout << "|                                                    |" << endl;
                cout << "|----------------------------------------------------|" << endl;
                cout << "|  GRAND TOTAL :                          Rs. " << total3 << "   |" << endl;
                cout << "||" << endl;
                menuQty[8] = menuQty[8] - quantity;
                break;
            }
            }
            goto order;
            break;
        }
        case 's':
        {
            cout << "CHOOSE YOUR DESIRED SALAD" << endl;
            cout << "1. FRUIT SALAD   ( FULL PLATE )\t        --- Rs. 200" << endl;
            cout << "2. RUSSIAN SALAD ( FULL PLATE )\t        --- Rs. 500" << endl;
            cout << "3. GREEN SALAD   ( FULL SALAD )\t        --- Rs. 400" << endl;
            cout << "0.    DONE" << endl;
            cout << "ENTER SALAD ( 1, 2, 3, 0)" << endl;
            cin >> salads;
            switch (salads)
            {
            case 0:
            {
                break;
            }
            case 1:
            {
                cout << "How many Plates of Fruit Salad would you like to order: " << endl;
                cin >> quantity;
                total4 = total4 + (quantity * 200);
                cout << "" << endl;
                cout << "|---------------------SELECTED CART------------------|" << endl;
                cout << "| ITEM:                     QTY:             PRICE:  |" << endl;
                cout << "|                                                    |" << endl;
                cout << "| " << salad[0] << "                " << quantity << "             Rs. " << total4 << "   |" << endl;
                cout << "|                                                    |" << endl;
                cout << "|----------------------------------------------------|" << endl;
                cout << "|  GRAND TOTAL :                           Rs. " << total4 << "   |" << endl;
                cout << "||" << endl;
                menuQty[9] = menuQty[9] - quantity;
                break;
            }
            case 2:
            {
                cout << "How many Plates of Russian Salad would you like to order: " << endl;
                cin >> quantity;
                total4 = total4 + (quantity * 500);
                cout << "" << endl;
                cout << "|---------------------SELECTED CART------------------|" << endl;
                cout << "| ITEM:                     QTY:             PRICE:  |" << endl;
                cout << "|                                                    |" << endl;
                cout << "| " << salad[1] << "              " << quantity << "            Rs. " << total4 << "   |" << endl;
                cout << "|                                                    |" << endl;
                cout << "|----------------------------------------------------|" << endl;
                cout << "|  GRAND TOTAL :                          Rs. " << total4 << "   |" << endl;
                cout << "||" << endl;
                menuQty[10] = menuQty[10] - quantity;
                break;
            }
            case 3:
            {
                cout << "How many Plates of Green salad would you like to order: " << endl;
                cin >> quantity;
                total4 = total4 + (quantity * 400);
                cout << "" << endl;
                cout << "|---------------------SELECTED CART------------------|" << endl;
                cout << "| ITEM:                     QTY:             PRICE:  |" << endl;
                cout << "|                                                    |" << endl;
                cout << "| " << salad[2] << "                " << quantity << "            Rs. " << total4 << "   |" << endl;
                cout << "|                                                    |" << endl;
                cout << "|----------------------------------------------------|" << endl;
                cout << "|  GRAND TOTAL :                          Rs. " << total4 << "   |" << endl;
                cout << "||" << endl;
                menuQty[11] = menuQty[11] - quantity;

                break;
            }
            }
            goto order;
            break;
        }
        case 'd':
        {
            cout << "CHOOSE YOUR DESIRED DRINK" << endl;
            cout << "1. COKE    ( 500 ml )\t                --- Rs. 80" << endl;
            cout << "2. SPRITE  ( 500 ml )\t                --- Rs. 80" << endl;
            cout << "3. FANTA   ( 500 ml )\t                --- Rs. 80" << endl;
            cout << "0.  DONE" << endl;
            cout << "ENTER DRINK ( 1, 2, 3, 0 )" << endl;
            cin >> drinks;
            switch (drinks)
            {
            case 0:
            {
                break;
            }
            case 1:
            {
                cout << "How many Coke would you like to order: " << endl;
                cin >> quantity;
                total5 = total5 + (quantity * 80);
                cout << "" << endl;
                cout << "|---------------------SELECTED CART------------------|" << endl;
                cout << "| ITEM:                     QTY:             PRICE:  |" << endl;
                cout << "|                                                    |" << endl;
                cout << "| " << drink[0] << "                        " << quantity << "            Rs. " << total5 << "   |" << endl;
                cout << "|                                                    |" << endl;
                cout << "|----------------------------------------------------|" << endl;
                cout << "|  GRAND TOTAL :                           Rs. " << total5 << "   |" << endl;
                cout << "||" << endl;
                menuQty[12] = menuQty[12] - quantity;

                break;
            }
            case 2:
            {
                cout << "How many Sprite would tou like to order: " << endl;
                cin >> quantity;
                total5 = total5 + (quantity * 80);
                cout << "" << endl;
                cout << "|---------------------SELECTED CART------------------|" << endl;
                cout << "| ITEM:                     QTY:             PRICE:  |" << endl;
                cout << "|                                                    |" << endl;
                cout << "| " << drink[1] << "                      " << quantity << "            Rs. " << total5 << "   |" << endl;
                cout << "|                                                    |" << endl;
                cout << "|----------------------------------------------------|" << endl;
                cout << "|  GRAND TOTAL :                           Rs. " << total5 << "   |" << endl;
                cout << "||" << endl;
                menuQty[13] = menuQty[13] - quantity;
                break;
            }
            case 3:
            {
                cout << "How many Fanta would you lke to order: " << endl;
                cin >> quantity;
                total5 = total5 + (quantity * 80);
                cout << "" << endl;
                cout << "|---------------------SELECTED CART------------------|" << endl;
                cout << "| ITEM:                     QTY:             PRICE:  |" << endl;
                cout << "|                                                    |" << endl;
                cout << "| " << drink[2] << "                       " << quantity << "            Rs. " << total5 << "   |" << endl;
                cout << "|                                                    |" << endl;
                cout << "|----------------------------------------------------|" << endl;
                cout << "|  GRAND TOTAL :                           Rs. " << total5 << "   |" << endl;
                cout << "||" << endl;
                menuQty[14] = menuQty[14] - quantity;
                break;
            }
            }
            goto order;
            break;
        }
        }
        {
            total = total1 + total2 + total3 + total4 + total5;
            cout << "|////////////////////////////////////////////|" << endl;
            cout << "|                 SALES INVOICE              |" << endl;
            cout << "|////////////////////////////////////////////|" << endl;
            cout << "|  ITEM:                          PRICE:     |" << endl;
            cout << "|--> PIZZA                       Rs. " << total1 << "       |" << endl;
            cout << "|--> BURGER                      Rs. " << total2 << "       |" << endl;
            cout << "|--> WINGS                       Rs. " << total3 << "       |" << endl;
            cout << "|--> SALAD                       Rs. " << total4 << "       |" << endl;
            cout << "|--> DRINK                       Rs. " << total5 << "       |" << endl;
            cout << "||" << endl;
            cout << "| GROSS TOTAL:                   Rs. " << total << "       |" << endl;
            cout << "||" << endl;
            cout << "|    TOTAL:                      Rs. " << total << "       |" << endl;
            cout << "|////////////////////////////////////////////|" << endl;
        }
    }
    system("pause");
    return 0;
}
