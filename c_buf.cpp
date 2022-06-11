#include <iostream>
#include "c_buf.h"

template<typename T> circular_buff<T>::circular_buff(int buf_size) {
    size = buf_size;
    array = new T[size];
}

template<typename T> void circular_buff<T>::push_end(T elem) {
    if (counter == size) {
        tail = ++tail % size;
    }
    else {
        counter++;
    }
    array[head] = elem;
    head = ++head % size;
}

template<typename T> void circular_buff<T>::push_begin(T elem) {
    if (tail == 0) {
        tail = size - 1;
    }
    else {
        tail--;
    }
    array[tail] = elem;
    if (counter != size) {
        counter++;
    }
    else {
        head = tail;
    }
}

template<typename T> T circular_buff<T>::pop_begin() {
    unsigned temp = tail;
    tail = ++tail % size;
    counter--;
    return array[temp];
}

template<typename T> T circular_buff<T>::access_begin() {
    return array[tail];
}

template<typename T> T circular_buff<T>::pop_end() {
    if (head == 0) {
        head = size - 1;
    }
    else {
        head--;
    }
    counter--;
    return array[head];
}

template<typename T> T circular_buff<T>::access_end() {
    if (head == 0) {
        return array[size - 1];
    }
    return array[head - 1];
}

template<typename T> T & circular_buff<T>::operator[] (unsigned int index) {
    if (index <= counter) {
        return array[(head + index) % size];
    }
    else
        return NULL;
}

template<typename T> void circular_buff<T>::add_iterator(int elementh) {
    if (iter_index <= counter) {
        iter_index++;
        array[iter_index] = elementh;
    }
    else {
        std::cout << "Неправильный индекс" << std::endl;
        std::cout << "The wrong index:" << std::endl;
    }
    if (iter_index > counter) {
        iter_index = head;
    }
}

template<typename T> void circular_buff<T>::pop_iterator() {
    if (iter_index <= counter) {
        array[iter_index] = 0;
        if (iter_index > 0) {
            iter_index--;
        }
        else {
            iter_index = tail;
        }
    }
    else {
        std::cout << "Неправильный индекс" << std::endl;
        std::cout << "The wrong index:" << std::endl;
    }
}

template<typename T> void circular_buff<T>::print_buffer() {
    if (counter == 0) {
        std::cout << "Буффер пуст!" << std::endl;
        std::cout << "The buffer is empty:" << std::endl;
    }
    else {
        std::cout << array[tail] << " ";
        unsigned int tmp = (tail + 1) % size;
        while (tmp != head) {
            std::cout << array[tmp] << " ";
            tmp = ++tmp % size;
        }
        std::cout << std::endl;
    }
}


template<typename T> void circular_buff<T>::change_capacity(unsigned int new_size) {
    T *new_buffer = new T [new_size];
    for (int i = 0; i < size or i < new_size; i++) {
        new_buffer[i] = array[i];
    }
//    count = min(count, new_size);
    counter = minimum(counter, new_size);
    size = new_size;
    array = new_buffer;
    tail %= size;
    head %= size;
}

template<typename T> Iterator<T>::Iterator(T* pos, T* arr, unsigned int arr_size, T* begin, T* finish) {
    index_position = pos;
    array = arr;
    start = begin;
    end = finish;
    size = arr_size;
}

template<typename T> Iterator<T> circular_buff<T>::begin() {
    return Iterator<T> (array + tail, array, size, array + tail, array + head - 1);
}

template<typename T> Iterator<T> circular_buff<T>::end() {
    return Iterator<T> (array + head, array, size, array + tail, array + head - 1);
}

template<typename T> Iterator<T>::Iterator(T* pos) {
    index_position = pos;
}
