#include "ProductRules.h"


ProductRules::ProductRules(IProductRepository &repository, IBankRepository &bankRepository)
{
    this->repository = &repository;
    this->bankRepository = &bankRepository;
}
ProductRules::ProductRules()
{}
ProductRules::~ProductRules()
{}

Product ProductRules::getProduct(int id) {
    Product tmpProduct = this->repository->getProductByID(id);
    if (tmpProduct.getID() == NONE)
        throw ProductNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    else
        return tmpProduct;
}

Product ProductRules::getProductByName(std::string name)
{
    Product tmpProduct = this->repository->getProductByName(name);
    if (tmpProduct.getID() == NONE)
        throw ProductNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    else
        return tmpProduct;
}

std::vector<Product> ProductRules::getProductByRate(Prodtype ptype, float rate)
{
    if ((ptype < DEPOSIT) || (ptype > CREDIT))
        throw ProductGetErrorException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<Product> products = this->repository->getProductByRate(ptype, rate);
    return products;
}

std::vector<Product> ProductRules::getProductByBank(Prodtype ptype, int bank_id)
{
    if ((ptype < DEPOSIT) || (ptype > CREDIT))
        throw ProductGetErrorException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<Bank> banks = this->bankRepository->getAllBanks();
    int id = NONE;
    for (size_t i = 0; i < banks.size(); i++)
        if (banks[i].getID() == bank_id)
            id = banks[i].getID();
    if (id == NONE)
        throw ProductGetErrorException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<Product> products = this->repository->getProductByBank(ptype, bank_id);
    return products;
}

std::vector<Product> ProductRules::getProductBySum(Prodtype ptype, float min_sum, float max_sum)
{
    if ((min_sum < MIN_SUM) || (max_sum < MIN_SUM) || (min_sum > max_sum) || (ptype < DEPOSIT) || (ptype > CREDIT))
        throw ProductGetErrorException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<Product> products = this->repository->getProductBySum(ptype, min_sum, max_sum);
    return products;
}

std::vector<Product> ProductRules::getProductByTime(Prodtype ptype, int min_time, int max_time)
{
    if ((min_time < MIN_TIME) || (max_time < MIN_TIME) || (min_time > max_time) || (ptype < DEPOSIT) || (ptype > CREDIT))
        throw ProductGetErrorException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<Product> products = this->repository->getProductByTime(ptype, min_time, max_time);
    return products;
}

std::vector<Product> ProductRules::getProductByType(Prodtype ptype)
{
    if ((ptype < DEPOSIT) || (ptype > CREDIT))
        throw ProductGetErrorException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<Product> products = this->repository->getProductByType(ptype);
    return products;
}

std::vector<Product> ProductRules::getProductByRating(Prodtype ptype, float rating)
{
    if ((rating < 0) || (ptype < DEPOSIT) || (ptype > CREDIT))
        throw ProductGetErrorException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<Product> products = this->repository->getProductByRating(ptype, rating);
    return products;
}

std::vector<Product> ProductRules::getProductByCurrency(Prodtype ptype, Curtype currency)
{
    std::vector<Product> products = this->repository->getProductByCurrency(ptype, currency);
    return products;
}

void ProductRules::updateProduct(Product prod_el)
{
    if ((prod_el.getName().length() < 1) || (prod_el.getMinTime() < MIN_TIME) || (prod_el.getMaxTime() < MIN_TIME)
    || (prod_el.getMinTime() > prod_el.getMaxTime()) || (prod_el.getMinSum() < MIN_SUM)
    || (prod_el.getMaxSum() < MIN_SUM) || (prod_el.getMinSum() > prod_el.getMaxSum()) || (prod_el.getCountRating() < 0)
    || (prod_el.getCurrency() < ROUBLE) || (prod_el.getCurrency() > YUAN) || (prod_el.getType() < DEPOSIT)
    || (prod_el.getType() > CREDIT) || (prod_el.getSumRating() < 0))
        throw ProductUpdateErrorException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<Bank> banks = this->bankRepository->getAllBanks();
    int id = NONE;
    for (size_t i = 0; i < banks.size(); i++)
        if (banks[i].getID() == prod_el.getBankID())
            id = banks[i].getID();
    if (id == NONE)
        throw ProductUpdateErrorException(__FILE__, typeid(*this).name(), __LINE__);
    this->repository->updateEl(prod_el);
}

void ProductRules::deleteProduct(int id)
{
    Product tmpProduct = this->repository->getProductByID(id);
    if (tmpProduct.getID() > NONE)
    {
        try {
            this->repository->deleteEl(id);
            Product testProduct = this->repository->getProductByID(id);
            if (testProduct.getID() != NONE)
                throw ProductDeleteErrorException(__FILE__, typeid(*this).name(), __LINE__);
        }
        catch (ProductNotFoundException) {}
    }
    else
        throw ProductNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
}

int ProductRules::addProduct(ProductInfo inf)
{
    if ((inf.name.length() < 1) || (inf.min_time < MIN_TIME) || (inf.max_time < MIN_TIME)
        || (inf.min_time > inf.max_time) || (inf.min_sum < MIN_SUM)
        || (inf.max_sum < MIN_SUM) || (inf.min_sum > inf.max_sum) || (inf.count_rating < 0)
        || (inf.currency < ROUBLE) || (inf.currency > YUAN) || (inf.type < DEPOSIT)
        || (inf.type > CREDIT) || (inf.sum_rating < 0))
        throw ProductAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    std::vector<Bank> banks = this->bankRepository->getAllBanks();
    int id = NONE;
    for (size_t i = 0; i < banks.size(); i++)
        if (banks[i].getID() == inf.bank_id)
            id = banks[i].getID();
    if (id == NONE)
        throw ProductAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    id = this->repository->addProduct(inf);
    Product tmpProduct = this->repository->getProductByID(id);
    if (tmpProduct.getID() == NONE)
        throw ProductAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    return id;
}

std::vector<Product> ProductRules::getAllProducts()
{
    std::vector<Product> products = this->repository->getAllProducts();
    return products;
}
