#include "ProductManager.h"

ProductManager::ProductManager(ProductRules &pController)
{
    this->productController = pController;
    this->printer = ProductPrinter();
    this->getter = ProductGetter();
}

ProductManager::ProductManager(){}

void ProductManager::viewAllProducts()
{
    std::vector<Product> products = this->productController.getAllProducts();
    for (size_t i = 0; i < products.size(); i++)
    {
        this->printer.printProduct(products[i]);
    }
}

void ProductManager::addProduct()
{
    this->printer.printInputBankID();
    int bank_id = this->getter.getInt();

    this->printer.printInputType();
    Prodtype ptype = this->getter.getInt();

    this->printer.printInputName();
    std::string name = this->getter.getString();

    this->printer.printInputRate();
    float rate = this->getter.getFloat();

    this->printer.printInputMinTime();
    int min_time = this->getter.getInt();

    this->printer.printInputMaxTime();
    int max_time = this->getter.getInt();

    this->printer.printInputMinSum();
    int min_sum = this->getter.getFloat();

    this->printer.printInputMaxSum();
    int max_sum = this->getter.getFloat();

    this->printer.printInputCurrency();
    Curtype currency = this->getter.getInt();

    try
    {
        this->productController.addProduct({.bank_id=bank_id, .type=type, .name=name, .rate=rate, .min_time=min_time,
        .max_time=max_time, .min_sum=min_sum, .max_sum=max_sum, .currency= currency, .sum_rating=0, .count_rating=0});
        this->printer.printAddSuccess();
    }
    catch (const std::exception &e)
    {
        this->printer.printException(e);
    }
}

void ProductManager::changeProduct()
{
    this->printer.printInputID();
    int tmpID = this->getter.getInt();

    try
    {
        Product tmpProduct = this->productController.getProduct(tmpID);
        if (tmpProduct.getID() != NONE)
        {

            this->printer.printInputType();
            Prodtype ptype = this->getter.getInt();

            if ((ptype != DEPOSIT) ||(ptype != CREDIT))
            {
                tmpProduct.setType(ptype);
            }

            this->printer.printInputName();
            std::string name = this->getter.getString();

            if (!name.empty())
            {
                tmpProduct.setName(name);
            }

            this->printer.printInputRate();
            float rate = this->getter.getFloat();

            if (rate > -100)
            {
                tmpProduct.setRate(rate);
            }

            this->printer.printInputMinTime();
            int min_time = this->getter.getInt();

            if (min_time > 0)
            {
                tmpProduct.setMinTime(min_time);
            }

            this->printer.printInputMaxTime();
            int max_time = this->getter.getInt();

            if (max_time > 0)
            {
                tmpProduct.setMaxTime(max_time);
            }

            this->printer.printInputMinSum();
            int min_sum = this->getter.getFloat();

            if (min_sum > 0)
            {
                tmpProduct.setMinSum(min_sum);
            }

            this->printer.printInputMaxSum();
            int max_sum = this->getter.getFloat();

            if (max_sum > 0)
            {
                tmpProduct.setMaxSum(max_sum);
            }

            this->printer.printInputCurrency();
            int cur = this->getter.getInt();

            if ((cur >= 0) || (currency <= 3))
            {
                Curtype currency = cur;
                tmpProduct.setCurrency(currency);
            }

            this->productController.updateProduct(tmpProduct);
        }
    }
    catch (const std::exception &e)
    {
        this->printer.printException(e);
    }
}