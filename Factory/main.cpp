#include "Factory.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Program started" << endl;
    FactoryManager& manager = FactoryManager::getInstance();

    // 创建产品A并指定加热策略
    unique_ptr<Product> productA = manager.createProduct("ProductA");
    if (productA) {
        manager.assignStrategy(productA.get(), "Heating");
        productA->process();
    }

    // 创建产品B并指定冷却策略
    unique_ptr<Product> productB = manager.createProduct("ProductB");
    if (productB) {
        manager.assignStrategy(productB.get(), "Cooling");
        productB->process();
    }

    // 创建产品C并指定混合策略
    unique_ptr<Product> productC = manager.createProduct("ProductC");
    if (productC) {
        manager.assignStrategy(productC.get(), "Mixing");
        productC->process();
    }

    cout << "Program ended" << endl;

    // 等待用户输入以保持控制台窗口打开
    cout << "Press Enter to exit...";
    cin.get();

    return 0;
}
