#ifndef PPO_IPRODUCTREPOSITORY_H
#define PPO_IPRODUCTREPOSITORY_H

#include "../models/ModelProduct.h"
#include "CRUDRepository.h"

class IProductRepository : public CRUDRepository<Product> {
public:
    virtual Product getProductByID(int id);
    virtual Product getProductByName(std::string name);
    virtual std::vector<Product> getProductByRate(Prodtype type, float rate);
    virtual std::vector<Product> getProductByBank(Prodtype type, int bank_id);
    virtual std::vector<Product> getProductBySum(Prodtype type, float min_sum, float max_sum);
    virtual std::vector<Product> getProductByTime(Prodtype type, int min_time, int max_time);
    virtual std::vector<Product> getProductByType(Prodtype type);
    virtual std::vector<Product> getProductByRating(Prodtype type, float rating);
    virtual std::vector<Product> getAllProducts();

    //virtual void updateProduct(int id, int bank_id, Prodtype type, std::string name, float rate, int min_time,
                               //int max_time, float min_sum, float max_sum, Curtype currency, int sum_rating,
                               //int count_rating);
    //virtual void deleteProduct(int id);
    virtual void addProduct(ProductInfo inf);
};


#endif //PPO_IPRODUCTREPOSITORY_H
