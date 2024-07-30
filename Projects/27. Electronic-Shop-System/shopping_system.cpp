#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Product
{
private:
    string name;
    float price;

public:
    Product(string n, float p) : name(n), price(p) {}

    string getName() const
    {
        return name;
    }

    float getPrice() const
    {
        return price;
    }
};

class Category
{
private:
    string categoryName;
    vector<Product> products;

public:
    Category(string name) : categoryName(name) {}

    void addProduct(const Product &product)
    {
        products.push_back(product);
    }

    void showProducts() const
    {
        cout << "_______" << categoryName << " Details________" << endl;
        for (size_t i = 0; i < products.size(); ++i)
        {
            cout << i + 1 << ") " << products[i].getName() << " => Price: " << products[i].getPrice() << " |" << endl;
        }
    }

    float getProductPrice(int index) const
    {
        if (index >= 0 && index < products.size())
        {
            return products[index].getPrice();
        }
        return 0;
    }
};

class Shop
{
private:
    vector<Category> categories;

public:
    Shop()
    {
        // Initialize categories and products
        Category refrigerators("Refrigerator");
        refrigerators.addProduct(Product("Whirlpool", 40000));
        refrigerators.addProduct(Product("Samsung", 25000));
        refrigerators.addProduct(Product("Haier", 20000));
        refrigerators.addProduct(Product("Voltas", 18000));
        refrigerators.addProduct(Product("Godrej", 30000));
        refrigerators.addProduct(Product("Panasonic", 35000));

        Category washingMachines("Washing Machine");
        washingMachines.addProduct(Product("Whirlpool", 40000));
        washingMachines.addProduct(Product("Samsung", 25000));
        washingMachines.addProduct(Product("Haier", 20000));
        washingMachines.addProduct(Product("Voltas", 18000));
        washingMachines.addProduct(Product("Godrej", 30000));
        washingMachines.addProduct(Product("Panasonic", 35000));

        Category televisions("Television");
        televisions.addProduct(Product("Whirlpool", 40000));
        televisions.addProduct(Product("Samsung", 25000));
        televisions.addProduct(Product("Haier", 20000));
        televisions.addProduct(Product("Voltas", 18000));
        televisions.addProduct(Product("Godrej", 30000));
        televisions.addProduct(Product("Panasonic", 35000));

        Category microwaves("Microwave");
        microwaves.addProduct(Product("Whirlpool", 40000));
        microwaves.addProduct(Product("Samsung", 25000));
        microwaves.addProduct(Product("Haier", 20000));
        microwaves.addProduct(Product("Voltas", 18000));
        microwaves.addProduct(Product("Godrej", 30000));
        microwaves.addProduct(Product("Panasonic", 35000));

        Category airConditioners("Air Conditioner");
        airConditioners.addProduct(Product("Whirlpool", 40000));
        airConditioners.addProduct(Product("Samsung", 25000));
        airConditioners.addProduct(Product("Haier", 20000));
        airConditioners.addProduct(Product("Voltas", 18000));
        airConditioners.addProduct(Product("Godrej", 30000));
        airConditioners.addProduct(Product("Panasonic", 35000));

        categories.push_back(refrigerators);
        categories.push_back(washingMachines);
        categories.push_back(televisions);
        categories.push_back(microwaves);
        categories.push_back(airConditioners);
    }

    float shop()
    {
        char choice;
        int categoryIndex, productIndex, quantity;
        float bill = 0;

        while (true)
        {
            cout << "*******Welcome*******" << endl;
            cout << "Please follow the instructions_" << endl;
            for (size_t i = 0; i < categories.size(); ++i)
            {
                cout << i + 1 << ") Please enter " << char('r' + i) << " to order " << categories[i].getCategoryName() << endl;
            }

            cin >> choice;
            categoryIndex = choice - 'r'; // Calculate category index from choice
            if (categoryIndex >= 0 && categoryIndex < categories.size())
            {
                categories[categoryIndex].showProducts();
                cin >> productIndex;
                if (productIndex > 0 && productIndex <= categories[categoryIndex].getProductCount())
                {
                    cout << "Please enter the quantity of the product: ";
                    cin >> quantity;
                    bill += quantity * categories[categoryIndex].getProductPrice(productIndex - 1);
                }
                else
                {
                    cout << "You entered the wrong option. Please try again!" << endl;
                }
            }
            else
            {
                cout << "You entered a wrong choice. Please try again!" << endl;
            }

            return bill;
        }
    }

    void applyDiscount(float &total) const
    {
        if (total > 50000 && total <= 100000)
        {
            total -= (0.05 * total);
            cout << "Total discount: 5%" << endl;
        }
        else if (total > 100000 && total <= 125000)
        {
            total -= (0.1 * total);
            cout << "Total discount: 10%" << endl;
        }
        else if (total > 125000 && total <= 150000)
        {
            total -= (0.25 * total);
            cout << "Total discount: 25%" << endl;
        }
        else if (total > 150000)
        {
            total -= (0.5 * total);
            cout << "Total discount: 50%" << endl;
        }
    }
};

int main()
{
    Shop shop;
    char start;
    float total;
    char choice;

    while (true)
    {
        cout << "Please press H to start shopping for Home appliances: " << endl;
        cin >> start;

        if (start == 'h' || start == 'H')
        {
            total = shop.shop();
            time_t t = time(NULL);
            tm *tPtr = localtime(&t);

            cout << "Bill Date: ";
            cout << tPtr->tm_mday << "/";
            cout << 1 + tPtr->tm_mon << "/";
            cout << 1900 + tPtr->tm_year << endl;

            cout << "Bill time: " << tPtr->tm_hour << ":" << tPtr->tm_min << ":" << tPtr->tm_sec << endl;
            cout << "Total Bill Amount: " << total << endl;

            shop.applyDiscount(total);
            cout << "Total bill amount after discount: " << total << endl;

            cout << "Do you want to shop again? Enter y or n" << endl;
            cin >> choice;
            if (choice == 'n' || choice == 'N')
            {
                cout << "Thanks for shopping!" << endl;
                break;
            }
            else if (choice != 'y' && choice != 'Y')
            {
                cout << "You have entered the wrong option. Exiting..." << endl;
                break;
            }
        }
        else
        {
            cout << "You have entered the wrong option, please press H to start again" << endl;
        }
    }

    return 0;
}
