#ifndef PPO_CRUDREPOSITORY_H
#define PPO_CRUDREPOSITORY_H

#include <vector>

class CRUDRepository<T>{
public:
    virtual void add(T element);
    virtual void update(T element);
    virtual void delete(T element);
    virtual std::vector<T> getAll(int limit);
};

#endif //PPO_CRUDREPOSITORY_H
