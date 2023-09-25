#include <iostream>
#include <stdlib.h>
#include "Geometric_Curves.h"
#include <vector>
#include<algorithm>
bool  CompareR(const Geometric_Curves* left, const Geometric_Curves* right) {
	return left->a > right->a;
}
int main() {
	
	setlocale(LC_ALL, "Russian");
	int num, f=1;
	double x0, y0, a, b;
	std::vector<Geometric_Curves*> container1;
	std::vector<Geometric_Curves*> container2;
	while (f!=0) {
		std::cout << "введите номер операции" << std::endl << "1.Добавить фигуру" << std::endl << "2.Показать координаты точек и производные всех кривых в контейнере при t=PI/4." << std::endl << "3.Заполнить второй контейнер, который будет содержать только круги из первого контейнера." << std::endl << "4.Отсортировать второй контейнер по возрастанию радиусов кругов" << std::endl << "5.Вычислить общую сумму радиусов всех кривых во втором контейнере." << std::endl << "6.Вывести параметры всех фигур во втором контейнере";
		std::cin >> f;
		switch (f) {
		case 0: {
			break;
		}
			  break;
		case 1: {
			std::cout << "введите номер фигуры 1.Окружность 2.Эллепс 3.Спираль" << std::endl;
			num = 1 + rand() % 4;
			num = 1;
			switch (num)
			{
			case 1: {
				
				
				a = 0 + rand() % ((1000 + 1));
				
				x0 = -1000 + rand() % ((1000 + 1) + 1000);
				
				
				y0 = -1000 + rand() % ((1000 + 1) + 1000);
				
				
				container1.push_back(new Circle(x0, y0, a));
				std::cout << "Circle" << std::endl;
				std::cout << "r = " << a <<"; " << "x0,y0 = " << x0 << "," << y0 << std::endl;
			}
				  break;
			case 2: {
				
				a = 0 + rand() % ((1000 + 1));
				
				b = 0 + rand() % ((1000 + 1));
				
				x0 = -1000 + rand() % ((1000 + 1) + 1000);
				
				y0 = -1000 + rand() % ((1000 + 1) + 1000);
				Ellipse ellipse(x0, y0, a, b);
				container1.push_back(new Ellipse(x0, y0, a, b));
				std::cout << "Ellipse" << std::endl;
				std::cout << "rmin = " << a << "; " <<"rmax = " << b << "; " <<"x0,y0 = " << x0 << "," << y0 << std::endl;
			}
				  break;

			case 3: {
				
				a = 0 + rand() % ((1000 + 1));
				
				b = 0 + rand() % ((1000 + 1));
				
				x0 = -1000 + rand() % ((1000 + 1) + 1000);
				
				y0 = -1000 + rand() % ((1000 + 1) + 1000);
				container1.push_back(new Helix(x0, y0, a, b));
				std::cout << "Helex" << std::endl;
				std::cout << "r = " << a << "; " <<"step = "<< b << "; " <<"x0,y0 = " << x0 << "," << y0 << std::endl;
			}
				  break;
			}

			break;
		case 2: {
			for (int i = 0; i < container1.size(); i++) {
				std::cout << "-----------------point" << i << "-----------------" << std::endl;
				std::cout << container1.at(i)->Get_Point(3.141592653589793 / 4).x << " ";
				std::cout << container1.at(i)->Get_Point(3.141592653589793 / 4).y << " ";
				std::cout << container1.at(i)->Get_Point(3.141592653589793 / 4).z << std::endl;
				std::cout << "-----------------vector" << i << "-----------------" << std::endl;
				std::cout << container1.at(i)->Get_vector(3.141592653589793 / 4).x << " ";
				std::cout << container1.at(i)->Get_vector(3.141592653589793 / 4).y << " ";
				std::cout << container1.at(i)->Get_vector(3.141592653589793 / 4).z << std::endl;

			}

		}
			  break;
		case 3: {
			for (int i = 0; i < container1.size(); i++) {
				float g = container1[i]->get_b();
				if (container1.at(i)->b == 0) {
					container2.push_back(container1.at(i));
					std::cout << &container2[0] << "\n";
					std::cout << &container1[0];
				}
			}
			container1.clear();
		}
			  break;
		case 4: {

			std::sort(container2.begin(), container2.end(), CompareR);
		}
			  break;
		case 5: {
			float summR = 0;
			#pragma omp parallel for // omp = OpenMP, parallel = запустить потоки, for = распределить по ним индексы этого цикла
			for (int i = 0; i < container2.size(); ++i) {
			#pragma omp critical
				summR += container2.at(i)->a;
			}
			std::cout << summR << std::endl;
		}
			  break;
		case 6: {
			for (int i = 0; i < container2.size(); i++) {
				std::cout << container2.at(i)->x0 << " ";
				std::cout << container2.at(i)->y0 << " ";
				std::cout << container2.at(i)->a << std::endl;
			}
		}
			  break;

		}
		}
	}
	std::for_each(container2.begin(), container2.end(), std::default_delete<Geometric_Curves>());
	std::for_each(container1.begin(), container1.end(), std::default_delete<Geometric_Curves>());
	_CrtDumpMemoryLeaks();

			  return 0;
	
}