#include "IProductRepository.h"

Product IProductRepository::getProductByID(int id)
{}
Product IProductRepository::getProductByName(std::string name)
{}
std::vector<Product> IProductRepository::getProductByRate(Prodtype type, float rate)
{}
std::vector<Product> IProductRepository::getProductByBank(Prodtype type, int bank_id)
{}
std::vector<Product> IProductRepository::getProductBySum(Prodtype type, float min_sum, float max_sum)
{}
std::vector<Product> IProductRepository::getProductByTime(Prodtype type, int min_time, int max_time)
{}
std::vector<Product> IProductRepository::getProductByType(Prodtype type)
{}
std::vector<Product> IProductRepository::getProductByRating(Prodtype type, float rating)
{}

void IProductRepository::updateProduct(int id, int bank_id, Prodtype type, std::string name, float rate, int min_time,
                           int max_time, float min_sum, float max_sum, Curtype currency, int sum_rating,
                           int count_rating)
{}
void IProductRepository::deleteProduct(int id)
{}
void IProductRepository::addProduct(int bank_id, Prodtype type, std::string name, float rate, int min_time, int max_time,
                        float min_sum, float max_sum, Curtype currency, int sum_rating, int count_rating)
{}