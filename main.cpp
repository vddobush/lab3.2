#include <iostream>
#include <algorithm>
#include "c_buf.h"
#include "c_buf.cpp"

int main() {
    setlocale(LC_ALL, "Russian");
    circular_buff<int> MyBuffer(10); //создаем буффер
    // Добавляем элементы в буффер
    MyBuffer.push_end(10);
    MyBuffer.push_end(-41);
    MyBuffer.push_end(327);
    MyBuffer.push_end(-983);
    MyBuffer.push_end(9);
    MyBuffer.push_end(-1);
    MyBuffer.push_end(15);
    // Выводим буффер
    MyBuffer.print_buffer();
    //Используем стандартную сортировку
    std::cout << "Сортируем буффер std сортом:" << std::endl;
    std::cout << "Sort buffer by std sort:" << std::endl;
    std::sort(MyBuffer.begin(), MyBuffer.end());
    MyBuffer.print_buffer();
    // Переполняем (здесь у нас элемент добавляется в конец -> буффер смещается на 1 элемент влево)
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Переполнение:" << std::endl;
    std::cout << "Overflow:" << std::endl;
    for (int i = 0; i < 14; i++) {
        MyBuffer.push_end(1 + i*5);
        MyBuffer.print_buffer();
    }
    std::cout << "---------------------------------------" << std::endl;
    // Проверка вставки в начало
    std::cout << "Проверка вставки в начало:" << std::endl;
    std::cout << "Cheking insertion into beginning:" << std::endl;
    MyBuffer.push_begin(999);
    MyBuffer.print_buffer();
    std::cout << "---------------------------------------" << std::endl;
    // Удаление из начала
    std::cout << "Удаление из начала:" << std::endl;
    std::cout << "Removing from beginning:" << std::endl;
    MyBuffer.pop_begin();
    MyBuffer.print_buffer();
    std::cout << "---------------------------------------" << std::endl;
    // Доступ в начало
    std::cout << "Первый элемент буффера:" << std::endl;
    std::cout << "First element of the buffer:" << std::endl;
    std::cout << MyBuffer.access_begin() << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    //Удаление из конца
    std::cout << "Удаление из конца:" << std::endl;
    std::cout << "Removing from the end:" << std::endl;
    MyBuffer.pop_end();
    MyBuffer.print_buffer();
    std::cout << "---------------------------------------" << std::endl;
    //Доступ в конец (последний элемент буффера)
    std::cout << "Последний элемент буффера:" << std::endl;
    std::cout << "The last element of the buffer:" << std::endl;
    std::cout << MyBuffer.access_end() << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    //Доступ по итератору
    std::cout << "Доступ по итератору в рандомное место:" << std::endl;
    std::cout << "Acces by iterator in random place:" << std::endl;
    MyBuffer.add_iterator(555);
    MyBuffer.print_buffer();
    MyBuffer.add_iterator(777);
    MyBuffer.print_buffer();
    MyBuffer.add_iterator(999);
    MyBuffer.print_buffer();
    MyBuffer.add_iterator(12345);
    MyBuffer.print_buffer();
    MyBuffer.pop_iterator();
    MyBuffer.print_buffer();
    MyBuffer.pop_iterator();
    MyBuffer.print_buffer();
    MyBuffer.add_iterator(987);
    MyBuffer.print_buffer();
    std::cout << "---------------------------------------" << std::endl;
    //Изменяем размер
    std::cout << "Меняем размер:" << std::endl;
    std::cout << "Changing size:" << std::endl;
    MyBuffer.change_capacity(12);
    for (int i = 8; i < 12; i++) {
        MyBuffer.push_end(i);
    }
    MyBuffer.print_buffer();
    std::cout << "Пытаемся добавить элементы в буффер сверх его размера:" << std::endl;
    std::cout << "Try to add elements into buffer over it's size:" << std::endl;
    MyBuffer.push_end(12);
    MyBuffer.print_buffer();
    MyBuffer.push_end(13);
    MyBuffer.print_buffer();
    MyBuffer.push_end(14);
    MyBuffer.print_buffer();
    MyBuffer.push_end(15);
    MyBuffer.print_buffer();
}
