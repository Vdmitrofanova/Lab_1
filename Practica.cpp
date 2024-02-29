#include <iostream>
#include <vector>
#include <random>
#include <ctime>

//Заполнение массива от пользователя
// template <typename T>
//void Fill(std::vector<T>& arr, int size) { //Заполняем массив данными
//	std::cout << "Enter values for your massive: " << std::endl;
//	for (int i = 0; i < size; i++)  {
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
void Show(std::vector<T>& arr, int size) { //Показываем какой массив чисел получился
	std::cout << "Here you can see elements of ypur massive: " << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl; 
}

template <typename T>
void Bubble(std::vector<T>& arr, int begin, int end) {
	for (int i = 0; i < end; i++) {
		bool flag = true;
		for (int j = 0; j < end - (i + 1); j++) { //Каждый раз проходим по внутреннему циклу уменьшеному на 1, чтобы лишний раз не сранивать
			if (arr[j] > arr[j+1]) {
				flag = false;
				std::swap(arr[j], arr[j+1]);
			}
		}
		if (flag) { //Значит отсортирован полностью - выходим
			break;
		}
	}
	std::cout << std::endl;
	std::cout << "Sorted massive: " << std::endl; //Показываем отсортированный массив
	for (int i = 0; i < end; i++) {
		std::cout << arr[i] << " ";
	}
}

template <typename T>
void Release(std::vector<T>& arr) {
	arr.clear(); //Удаляем все элементы (контейнер остается пустым
}

int main() {
	setlocale(LC_ALL, "rus");
	std::cout << "Сортировка Пузырьком: " << std::endl;

	int size;
	std::cout << "Please, enter the number of items in your massive: " << std::endl; //Пользователь вводит кол-во элементов в массиве
	std::cin >> size;

	std::vector<int> arr; //Создание пустого вектора
	arr.reserve(size); //Резервирование памяти для введенного кол-во элементов

	Fill(arr, size); 
	Show(arr, size); 
	clock_t start_time = clock();  //Замерка времени перед сортировкой
	Bubble(arr, 0, size);
	clock_t end_time = clock();//Замерка времени после сортировки
	double search_time = double(end_time - start_time); //разница времени
	std::cout << std::endl;
	std::cout << "Time taken: " << ((search_time)/1000) << " seconds" << std::endl; //В секундах
	Release(arr);

	return 0;
}