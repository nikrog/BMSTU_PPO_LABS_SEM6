#ifndef PPO_MOCKPRODUCTREPOSITORY_H
#define PPO_MOCKPRODUCTREPOSITORY_H

#include "../../business_logic/models/ModelProduct.h"
#include "../../business_logic/IRepositories/IProductRepository.h"

class MockProductRepository : public IProductRepository {
public:
    Product getProductByID(int id);
    Product getProductByName(std::string name);
    std::vector<Product> getProductByRate(Prodtype type, float rate);
    std::vector<Product> getProductByBank(Prodtype type, int bank_id);
    std::vector<Product> getProductBySum(Prodtype type, float min_sum, float max_sum);
    std::vector<Product> getProductByTime(Prodtype type, int min_time, int max_time);
    std::vector<Product> getProductByType(Prodtype type);
    std::vector<Product> getProductByRating(Prodtype type, float rating);
    std::vector<Product> getAllProducts();
    void updateEl(Product prod_el);
    void deleteEl(int id);
    int addProduct(ProductInfo inf);
};


#endif //PPO_MOCKPRODUCTREPOSITORY_H
