#include <iostream>
#include <vector>


class A {
public:
	virtual void foo(std::vector<int>& vec) = 0;
	~A(){} // добавили виртуальный диструктор
};
class B : public A {
public:
	void foo(std::vector<int>& vec) override {
		std::cout << "foo function" << std::endl;
		vec.erase(vec.begin());
		std::cout << vec[0] << vec[1] << std::endl; // добавил, чтобы вывести вектор в консоль
	}
};




int main() {

	A* b = new B();
	std::vector<int> v = { 1,2,3 };
	b->foo(v);
	std::cout << v[0] << v[1] << std::endl; // тоже добавил, чтобы показать что после вызова функции происходит
	//при этом, если вектор передаем не по ссылке, а по значению, то удаления у вектора не будет, так как в функции мы работаем с копией
	delete b; //удаление, для предотвращения утечки памяти

}