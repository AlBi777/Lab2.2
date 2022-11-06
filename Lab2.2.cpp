#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
using namespace std;

class camera{
private:
	int main_camera;
	int front_camera;
public:
	camera();
	camera(int main_camer);
	camera(int main, int front);
	~camera();
	void input();
	void print();


};
camera::camera(){}
camera::camera(int main)
{
	this->main_camera = main;
}
camera::camera(int main,int front){
	this->main_camera = main;
	this->main_camera = main;
}
camera::~camera() = default;
void camera::input(){
	cout<<"Камера(Мп)"<< endl <<"Введите разрешение главной камеры: ";
	cin >> main_camera;
	cout<<"Введите разрешение фронтальной камеры: ";
	cin>>front_camera;
}
void camera::print() {
	cout << "Разрешение гл. камеры - " << main_camera << " Мп, фронтальной - " << front_camera << " Мп.\n";
}

class battery
{
public:
	int capacity;
	string type;
	string types[3] = { "Li-Ion","NIMH", "NiCd" };

	battery();
	battery(int v);
	battery(int v, string type);
	~battery();

	void input();
	void print();

};
battery::battery(){}
battery::battery(int v)
{
	this->capacity = v;
}
battery::battery(int v, string t) {
	this->capacity = v;
	this->type = t;
}
battery::~battery() = default;
void battery::input() {
	cout << "Батарея(мАч)" << endl << "Введите емкость батареи: ";
	cin >> capacity;
	cout << "Введите тип батареи: ";
	cin >> type;
}
void battery::print() {
	cout << "Емкость батареи - " << capacity << " мАч, тип батареи - " << type << "." << endl;
}

class memory
{
private:
	int ram;
	int rom;
public:
	memory();
	memory(int rom);
	memory(int ram,int rom);
	~memory();
	void input();
	void print();
};
memory::memory(){}
memory::memory(int rom) { this->rom = rom; }
memory::memory(int ram, int rom) { this->ram = ram; this->rom = rom; }
memory::~memory() = default;
void memory::input() {
	cout << "Память(Гб)" << endl << "Введите объем основной памяти: ";
	cin >> rom;
	cout << "Введите объем оперативной памяти: ";
	cin >> ram;
}
void memory::print() {
	cout << "Объем основной памяти - " << ram << " Гб, объем основной памяти - " << rom << " Гб." << endl;
}

class screen {
public:
	float diagonal;
	string type;
	string types[3] = { "IPS","AMOLED","OLED"};

	screen();
	screen(float dia);
	screen(float dia,string type);
	~screen();
	void input();
	void print();
};
screen::screen(){}
screen::screen(float dia) {
	this->diagonal = dia;
}
screen::screen(float dia, string type) {
	this->diagonal = dia;
	this->type = type;
}
screen::~screen() = default;
void screen::input() {
	cout << "Экран" << endl << "Введите диагональ экрана(Дм): ";
	cin >> diagonal;
	cout << "Введите тип экрана: ";
	cin >> type;
}
void screen::print() {
	cout << "Диагональ экрана - " << diagonal << " Дм, тип экрана - " << type << "." << endl;
}

class systema
{
private:
	string name;
	int version;
public:
	systema();
	systema(string name);
	systema(string name, int version);
	~systema();
	void input();
	void print();
};
systema::systema(){}
systema::systema(string name) { this->name = name; }
systema::systema(string name, int version) {
	this->name = name;
	this->version = version;
}
systema::~systema() = default;
void systema::input() {
	cout << "Операционая система" << endl << "Введите название системы: ";
	cin >> name;
	cout << "Введите версию о.системы: ";
	cin >> version;
}
void systema::print() {
	cout << "ОС - " << name << ", версия - " << version << "." << endl;
}

class smartphone {
private:
	camera camera_get;
	battery battery_get;
	memory memory_get;
	screen screen_get;
	systema system_get;
public:
	smartphone();
	smartphone(systema system_get);
	smartphone(camera camera_get, battery battery_get, memory memory_get, screen screen_get, systema system_get);
	~smartphone();
	void input();
	void print();

	void battery_status(smartphone s);
	void check(smartphone s);
};

smartphone::smartphone(){}
smartphone::smartphone(systema system_get) {
	this->system_get = system_get;
}
smartphone::smartphone(camera camera_get, battery battery_get, memory memory_get, screen screen_get, systema system_get) {
	this->camera_get = camera_get;
	this->battery_get = battery_get;
	this->memory_get = memory_get;
	this->screen_get = screen_get;
	this->system_get = system_get;
}
smartphone::~smartphone() = default;
void smartphone::input() {
	cout << "Введите данные!" << endl;
	camera_get.input();
	battery_get.input();
	memory_get.input();
	screen_get.input();
	system_get.input();
}
void smartphone::print() {
	camera_get.print();
	battery_get.print();
	memory_get.print();
	screen_get.print();
	system_get.print();
}
void smartphone::battery_status(smartphone s) {
	int month;
	cout << "\nПроверка емкости батареи."<< endl<<" Сколько месяцев прошло с покупки: ";
	cin >> month;
	cout <<"Примерная емкость батареи - " << (s.battery_get.capacity - (s.battery_get.capacity / 100 * month));
}
void smartphone::check(smartphone s) {
	printf("\nПроверка."); int choice;
	if (s.battery_get.type == s.battery_get.types[0] || s.battery_get.type == s.battery_get.types[1] || s.battery_get.type == s.battery_get.types[2]) {
	}
	else {
		cout <<"Тип батареи не соответствует Li-Ion, NiCd, NIMH.\n Оставить(0) или изменить(1) тип: ";
		cin >> choice;
		if (choice) {
			cout << "Введите тип батареи:";
			cin >> this->battery_get.type;
		}
	}
	if (s.screen_get.type == s.screen_get.types[0] || s.screen_get.type == s.screen_get.types[1] || s.screen_get.type == s.screen_get.types[2]) {}
	else {
		cout << "Тип экрана не соответствует IPS, AMOLED, OLED."<< endl <<" Оставить(0) или изменить(1) тип: ";
		cin >> choice;
		if (choice) {
			cout << "Введите тип экрана:";
			cin >> this->screen_get.type;
		}
	}
	printf("Проверка завершена!\n");
}


int main() {
	setlocale(LC_ALL, "ru");
	camera _camera = camera(0, 0);
	battery _battery = battery(0, "");
	memory _memory = memory(0, 0);
	screen _screen = screen(0, "");
	systema _system = systema("", 0);
	cout << "Инициализация прошла успешно."<< endl;
	smartphone* sp = new smartphone[2];
	smartphone *d = new smartphone;
	sp[0] = smartphone(_camera,_battery,_memory,_screen,_system);
	sp[0].input();
	sp->check(*sp);
	sp[0].print();
	sp->battery_status(*sp);
	delete d;
	delete[]sp;
}


