#include <iostream>
#include "bstree.cpp" // Включите ваш файл с определением класса BSTree

int main() {
    // Создание экземпляра класса BSTree с помощью конструктора по умолчанию
    BSTree tree;

    // Добавление элементов в дерево
    tree.add_element(10);
    tree.add_element(5);
    tree.add_element(15);
    tree.add_element(3);
    tree.add_element(7);

    // Вывод дерева в консоль
    std::cout << "Tree after adding elements: ";
    tree.print();

    // Поиск элемента
    if (tree.find_element(7)) {
        std::cout << "Element 7 found in the tree." << std::endl;
    } else {
        std::cout << "Element 7 not found in the tree." << std::endl;
    }

    // Удаление элемента
    tree.delete_element(5);
    std::cout << "Tree after deleting element 5: ";
    tree.print();

    // Сохранение дерева в файл
    if (tree.save_to_file("tree.txt")) {
        std::cout << "Tree saved to file 'tree.txt'." << std::endl;
    } else {
        std::cout << "Failed to save tree to file." << std::endl;
    }

    // Создание нового экземпляра класса BSTree и загрузка дерева из файла
    BSTree new_tree;
    if (new_tree.load_from_file("tree.txt")) {
        std::cout << "Tree loaded from file 'tree.txt': ";
        new_tree.print();
    } else {
        std::cout << "Failed to load tree from file." << std::endl;
    }

    return 0;
}