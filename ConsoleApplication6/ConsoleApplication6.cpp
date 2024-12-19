#include <iostream>
#include "HashTable.h"
#include <cassert>

using namespace std; 
// Тестирование
void runTests() {
    HashTable<string, string> table;

    // Тест 1: Размер новой коллекции равен нулю
    assert(table.size() == 0);

    // Тест 2: Добавление новых элементов
    table.add("2024-12-08", "solar eclipse");
    assert(table.size() == 1);
    table.add("2024-12-08", "solar eclipse"); // Повторное добавление не увеличивает размер
    assert(table.size() == 1);

    // Тест 3: Удаление элемента
    table.add("2025-01-15", "lunar eclipse");
    assert(table.size() == 2);
    table.remove("2025-01-15");
    assert(table.size() == 1);

    // Тест 4: Очистка коллекции
    table.clear();
    assert(table.size() == 0);

    // Тест 5: Пересечение коллекций
    HashTable<string, string> table1;
    HashTable<string, string> table2;
    table1.add("2024-12-08", "solar eclipse");
    table1.add("2025-01-15", "lunar eclipse");
    table2.add("2025-01-15", "lunar eclipse");
    table2.add("2025-02-20", "meteor shower");
    auto intersection = table1 && table2;
    assert(intersection.size() == 1);
    assert(intersection.contains("2025-01-15"));

    cout << "All tests have been successfully passed!" << endl;
}

int main() {
    // Тестирование класса
    runTests();

    // Пример использования HashTable
    cout << "\nExample of using HashTable:" << endl;

    // Создаем экземпляр хеш-таблицы
    HashTable<string, string> table;

    // Добавляем элементы
    table.add("2024-12-08", "solar eclipse");
    table.add("2025-01-15", "lunar eclipse");
    table.add("2025-02-20", "meteor shower");

    cout << "added elements\n";
    cout << "2024-12-08: " << table["2024-12-08"] << "\n";
    cout << "2025-01-15: " << table["2025-01-15"] << "\n";
    cout << "2025-02-20: " << table["2025-02-20"] << "\n";

    // Проверяем наличие ключа
    cout << "\nChecking the availability of the key '2024-12-08': "
        << (table.contains("2024-12-08") ? "exist" : "no") << endl;
    cout << "Checking the availability of the key '2025-05-10': "
        << (table.contains("2025-05-10") ? "exist" : "no") << endl;

    // Удаляем элемент
    table.remove("2025-01-15");
    cout << "The key element was deleted '2025-01-15'. Current size: " << table.size() << endl;

    // Сохраняем в файл
    string fileName = "example_table.txt";
    table.saveToFile(fileName);
    cout << "Saved to a file: " << fileName << endl;

    // Загружаем из файла
    HashTable<string, string> loadedTable;
    loadedTable.loadFromFile(fileName);
    cout << "The table is loaded from the file. Content:\n";
    for (const auto& key : { "2024-12-08", "2025-02-20" }) {
        cout << key << ": " << loadedTable[key] << "\n";
    }

    // Демонстрация пересечения
    HashTable<string, string> anotherTable;
    anotherTable.add("2025-02-20", "meteor shower");
    anotherTable.add("2026-08-10", "Comet event");

    auto intersection = table && anotherTable;
    cout << "\nIntersection of tables" << endl;
    for (const auto& key : { "2024-12-08", "2025-02-20", "2026-08-10" }) {
        if (intersection.contains(key)) {
            cout << key << ": " << intersection[key] << "\n";
        }
    }

    return 0;
}