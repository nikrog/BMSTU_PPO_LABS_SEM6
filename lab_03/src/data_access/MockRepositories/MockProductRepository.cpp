#include "MockProductRepository.h"

Product MockProductRepository::getProductByID(int id)
{
    Product tmpProduct = Product(id, 1, DEPOSIT, "first", 7.5, 180, 750,
                                 50000, 1000000, ROUBLE, 0, 0);
    return tmpProduct;
}
Product MockProductRepository::getProductByName(std::string name)
{
    Product tmpProduct = Product(1, 1, DEPOSIT, name, 7.5, 180, 750,
                                 50000, 1000000, ROUBLE, 0, 0);
    return tmpProduct;
}
std::vector<Product> MockProductRepository::getProductByRate(Prodtype type, float rate)
{
    Product tmpProduct = Product(1, 1, type, "first", rate, 180, 750,
                                 50000, 1000000, ROUBLE, 0, 0);
    std::vector<Product> products = std::vector<Product>();
    products.push_back(tmpProduct);
    tmpProduct = Product(2, 1, type, "second", rate + 1, 180, 750,
            50000, 1000000, ROUBLE, 0, 0);
    products.push_back(tmpProduct);
    return products;
}
std::vector<Product> MockProductRepository::getProductByBank(Prodtype type, int bank_id)
{
    Product tmpProduct = Product(1, bank_id, type, "first", 7.5, 180, 750,
                                 50000, 1000000, ROUBLE, 0, 0);
    std::vector<Product> products = std::vector<Product>();
    products.push_back(tmpProduct);
    tmpProduct = Product(2, bank_id, type, "second", 6.7, 180, 750,
                         50000, 1000000, ROUBLE, 0, 0);
    products.push_back(tmpProduct);
    return products;
}

std::vector<Product> MockProductRepository::getProductBySum(Prodtype type, float min_sum, float max_sum)
{
    Product tmpProduct = Product(1,1, type, "first", 7.5, 180, 750,
                                 min_sum, max_sum, ROUBLE, 0, 0);
    std::vector<Product> products = std::vector<Product>();
    products.push_back(tmpProduct);
    tmpProduct = Product(2, 2, type, "second", 6.7, 180, 750,
                         min_sum, max_sum, ROUBLE, 0, 0);
    products.push_back(tmpProduct);
    return products;
}
std::vector<Product> MockProductRepository::getProductByTime(Prodtype type, int min_time, int max_time)
{
    Product tmpProduct = Product(1, 1, type, "first", 7.5, min_time, max_time,
                                 50000, 1000000, ROUBLE, 0, 0);
    std::vector<Product> products = std::vector<Product>();
    products.push_back(tmpProduct);
    tmpProduct = Product(2, 2, type, "second", 6.7, min_time, max_time,
                         50000, 1000000, ROUBLE, 0, 0);
    products.push_back(tmpProduct);
    return products;
}
std::vector<Product> MockProductRepository::getProductByType(Prodtype type)
{
    Product tmpProduct = Product(1, 1, type, "first", 7.5, 180, 750,
                                 50000, 1000000, ROUBLE, 0, 0);
    std::vector<Product> products = std::vector<Product>();
    products.push_back(tmpProduct);
    tmpProduct = Product(2, 2, type, "second", 6.7, 180, 750,
                         50000, 1000000, ROUBLE, 0, 0);
    products.push_back(tmpProduct);
    return products;
}
std::vector<Product> MockProductRepository::getProductByRating(Prodtype type, float rating)
{
    Product tmpProduct = Product(1, 1, type, "first", 7.5, 180, 750,
                                 50000, 1000000, ROUBLE, 5, 1);
    std::vector<Product> products = std::vector<Product>();
    products.push_back(tmpProduct);
    tmpProduct = Product(2, 2, type, "second", 6.7, 180, 750,
                         50000, 1000000, ROUBLE, 5, 1);
    products.push_back(tmpProduct);
    return products;
}
std::vector<Product> MockProductRepository::getAllProducts()
{
    Product tmpProduct = Product(1, 1, DEPOSIT, "first", 7.5, 180, 750,
                                 50000, 1000000, ROUBLE, 0, 0);
    std::vector<Product> products = std::vector<Product>();
    products.push_back(tmpProduct);
    tmpProduct = Product(2, 2, CREDIT, "second", 6.7, 180, 750,
                         50000, 1000000, ROUBLE, 0, 0);
    products.push_back(tmpProduct);
    return products;
}
void MockProductRepository::updateEl(Product prod_el)
{
    return;
}
void MockProductRepository::deleteEl(int id)
{
    return;
}
int MockProductRepository::addProduct(ProductInfo inf)
{
    return 1;
}