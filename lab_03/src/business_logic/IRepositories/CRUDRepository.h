#ifndef PPO_CRUDREPOSITORY_H
#define PPO_CRUDREPOSITORY_H

#include <vector>

template<typename T>
class CRUDRepository {
public:
    virtual void addEl(T element);
    virtual void updateEl(T element);
    virtual void deleteEl(int id);
    virtual std::vector<T> getAll(int limit);
};

#endif //PPO_CRUDREPOSITORY_H
