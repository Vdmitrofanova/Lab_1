#include<iostream>
#include<vector>
#include <random>
#include <ctime>

//Заполнение массива от пользователя
// template <typename T> 
//void Fill(std::vector<T>& arr, int size) { // Заполняем массив
//	std::cout << "Enter values for your massive: " << std::endl;
//	for (int i = 0; i < size; i++) {
//		T value;
//		std::cin >> value;
//		arr.push_back(value); //Присоединяем копию value в конец вектора
//	}
//}

template <typename T>
void Fill(std::vector<T>& arr, int size) { //Заполняем массив данными 
	std::random_device rd; 
	std::mt19937 gen(rd()); 
	for (int i = 0; i < size; i++) {
		arr.push_back(gen() % 100); //Вводим рандомные числа в массив
	}
}

template <typename T>
void Show(std::vector<T>& arr, int size) { // Выводим массив чисел пользователю
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
int Separation(std::vector<T>& arr, int begin, int end) {
	T pivot = arr[end]; //Закладываем в pivot рандомный индекс массива
	int j = begin;
	for (int i = begin; i < end; ++i) {
		if (arr[i] < pivot) {
			std::swap(arr[i], arr[j]);
			++j;
		}
	}
	std::swap(arr[j], arr[end]);
	return j;
}

template <typename T>
int RandomPivot(std::vector<T>& arr, int begin, int end) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(begin, end);
	int pivotIndex = dist(gen); //Выбираемм случайный индекс для pivotIndex
	std::swap(arr[pivotIndex], arr[end]);//Меняем местами случайное число и конечное число
	return Separation(arr, begin, end);
}

template <typename T>
void Quicksort(std::vector<T>& arr, int begin, int end) {
	if (begin < end) {
		int p = Separation(arr, begin, end); 
		Quicksort(arr, begin, p - 1);
		Quicksort(arr, p + 1, end);
	} 
}

template <typename T>
void Release(std::vector<T>& arr) {
	arr.clear(); //Удаляем все элементы (контейнер остается пустым)
}

int main() {
	setlocale(LC_ALL, "rus");
	std::cout << "Быстрая Сортировка: " << std::endl;

	int size;
	std::cout << "Please, enter the number of items in your massive: " << std::endl; //Пользователь вводит кол-во элементов в массиве
    std:: cin >> size;

	std::vector<int> arr; //Создание пустого вектора
	arr.reserve(size); //Резервирование памяти для введенного кол-во элементов

	Fill(arr, size); 
	std::cout << "Massive before sorting: " << std::endl;
	Show(arr, size);

	clock_t start_time = clock(); //Замерка времени перед сортировкой
	Quicksort(arr, 0, size - 1);
	std::cout << std::endl;
	std::cout << "Massive after sorting: " << std::endl;
	Show(arr, size);

	clock_t end_time = clock();//Замерка времени после сортировки
	double search_time = double(end_time - start_time); //Разница времени

	std::cout << "Time taken: " << ((search_time)/1000) << " seconds" << std::endl; //Показ времени в секундах
	Release(arr);

	return 0;
}