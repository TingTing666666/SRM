#include "Factory.h"

void Product::setStrategy(shared_ptr<ProcessingStrategy> strategy) {
    this->strategy = strategy;
}

void ProductA::process() {
    cout << "ProductA is being processed. ";
    if (strategy) {
        strategy->process();
    }
}

void ProductB::process() {
    cout << "ProductB is being processed. ";
    if (strategy) {
        strategy->process();
    }
}

void ProductC::process() {
    cout << "ProductC is being processed. ";
    if (strategy) {
        strategy->process();
    }
}

void HeatingStrategy::process() {
    cout << "Heating process applied." << endl;
}

void CoolingStrategy::process() {
    cout << "Cooling process applied." << endl;
}

void MixingStrategy::process() {
    cout << "Mixing process applied." << endl;
}

shared_ptr<ProcessingStrategy> StrategyFactory::createStrategy(const string& strategyType) {
    if (strategyType == "Heating") {
        return make_shared<HeatingStrategy>();
    } else if (strategyType == "Cooling") {
        return make_shared<CoolingStrategy>();
    } else if (strategyType == "Mixing") {
        return make_shared<MixingStrategy>();
    }
    return nullptr;
}

FactoryManager& FactoryManager::getInstance() {
    static FactoryManager instance;
    return instance;
}

unique_ptr<Product> FactoryManager::createProduct(const string& productType) {
    if (productType == "ProductA") {
        return make_unique<ProductA>();
    } else if (productType == "ProductB") {
        return make_unique<ProductB>();
    } else if (productType == "ProductC") {
        return make_unique<ProductC>();
    }
    return nullptr;
}

void FactoryManager::assignStrategy(Product* product, const string& strategyType) {
    auto strategy = StrategyFactory::createStrategy(strategyType);
    if (product && strategy) {
        product->setStrategy(strategy);
    } else {
        cerr << "Failed to assign strategy: product or strategy is null" << endl;
    }
}
