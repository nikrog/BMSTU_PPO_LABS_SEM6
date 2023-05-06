#ifndef PPO_GUIPRODUCTMANAGER_H
#define PPO_GUIPRODUCTMANAGER_H

#include "../../business_logic/rules/ProductRules.h"

class GUIProductManager {
private:
    ProductRules productController;

public:
    GUIProductManager(ProductRules &pController);
    GUIProductManager();
    ~GUIProductManager() = default;
    std::vector<Product> viewAllProducts();
    void addProduct(ProductInfo inf);
    void changeProduct(int id, ProductInfo inf);
};


#endif //PPO_GUIPRODUCTMANAGER_H
