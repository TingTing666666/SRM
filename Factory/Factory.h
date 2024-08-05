#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Forward declaration
class ProcessingStrategy;

class Product {
public:
    virtual ~Product() = default;
    virtual void process() = 0;
    void setStrategy(shared_ptr<ProcessingStrategy> strategy);

protected:
    shared_ptr<ProcessingStrategy> strategy;
};

class ProductA : public Product {
public:
    void process() override;
};

class ProductB : public Product {
public:
    void process() override;
};

class ProductC : public Product {
public:
    void process() override;
};

class ProcessingStrategy {
public:
    virtual ~ProcessingStrategy() = default;
    virtual void process() = 0;
};

class HeatingStrategy : public ProcessingStrategy {
public:
    void process() override;
};

class CoolingStrategy : public ProcessingStrategy {
public:
    void process() override;
};

class MixingStrategy : public ProcessingStrategy {
public:
    void process() override;
};

class StrategyFactory {
public:
    static shared_ptr<ProcessingStrategy> createStrategy(const string& strategyType);
};

class FactoryManager {
public:
    static FactoryManager& getInstance();
    unique_ptr<Product> createProduct(const string& productType);
    void assignStrategy(Product* product, const string& strategyType);

private:
    FactoryManager() = default;
    ~FactoryManager() = default;
    FactoryManager(const FactoryManager&) = delete;
    FactoryManager& operator=(const FactoryManager&) = delete;
};

#endif // FACTORY_H
