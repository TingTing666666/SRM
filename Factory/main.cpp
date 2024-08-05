#include "Factory.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Program started" << endl;
    FactoryManager& manager = FactoryManager::getInstance();

    // ������ƷA��ָ�����Ȳ���
    unique_ptr<Product> productA = manager.createProduct("ProductA");
    if (productA) {
        manager.assignStrategy(productA.get(), "Heating");
        productA->process();
    }

    // ������ƷB��ָ����ȴ����
    unique_ptr<Product> productB = manager.createProduct("ProductB");
    if (productB) {
        manager.assignStrategy(productB.get(), "Cooling");
        productB->process();
    }

    // ������ƷC��ָ����ϲ���
    unique_ptr<Product> productC = manager.createProduct("ProductC");
    if (productC) {
        manager.assignStrategy(productC.get(), "Mixing");
        productC->process();
    }

    cout << "Program ended" << endl;

    // �ȴ��û������Ա��ֿ���̨���ڴ�
    cout << "Press Enter to exit...";
    cin.get();

    return 0;
}
