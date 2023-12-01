#include "pch.h"
#include "math.h"
#include "iostream"
#include "stdio.h"
#include "conio.h"
#include "cstdlib"
#include <cstring>
#include "iomanip"
#include <stack>
#include <locale.h>
#include <fstream>
#include <TCHAR.H>
#include <map>
#include <vector>
#pragma warning(disable : 4996)
using namespace std;
bool operator<(string w1, string w2) {
	return strcmp(w1.c_str(), w2.c_str()) < 0;;
}
map <string, int>VsePredmetys;
map < int,string>VsePredmetyi;
double RasmStep[4] = {85.70,102.84,119.99,137.13};
void Nachalo() {
	char a[10], b[2];
	ifstream file("predmety.txt");
	if (file.is_open()){
		while (!file.eof()) {
			file >> a >> b;
			VsePredmetys.insert(pair<string,int>(a,atoi(b)));
			VsePredmetyi.insert(pair<int,string>(atoi(b),a));
		}
	}
}
void Konec() {
	char a[2];
	map< string,int>::iterator mapPtr;
	mapPtr = VsePredmetys.begin();
	++mapPtr;
	ofstream file("predmety.txt");
	if (file.is_open()) {
		while (mapPtr != VsePredmetys.end()) {
			itoa(mapPtr->second, a, 10);
			file << (mapPtr->first).c_str()<< " "  << a << "\n";
			++mapPtr;
		}
	}
	file.close();
}
bool strsrav(char*a, char*b) {
	int i = 0;
	 do{
		++i;
		if (a[i] != b[i])return false;
	 } while (a[i] != '\0'&&b[i] != '\0');
	return true;
}
string enter(int n) {
	char* log;
	log = new char[n+1];
	int i = 0;
	while (log[i] != '\0') {
		log[i + 1] = '8';
		log[i] = _getch();
		if (log[i] == 8 && i > 0) cout << "\b \b", --i;
		else if (log[i] != 8) {
			if (i < n) {
				if ((log[i] >= '0'&&log[i] <= '9') || (log[i] >= 'a'&&log[i] <= 'z'))cout << log[i], ++i;
			}
			else {	
				if (log[i] == 13) log[i] = '\0', cout << "\n";
			}
		}
	}
	return log;
}
string enter1(int n) {
	int i = 0;
	char* log;
	log = new char[n + 1];
	while (log[n] != '\0') {
		log[i] = _getch();
		if (log[i] == 8 && i > 0) cout << "\b \b", --i;
		else {
			if (i != n) {
				if (log[i] >= '0'&&log[i] <= '9') {
					cout << log[i];
					++i;
				}
			}
			else {
				if (log[i] == 13) log[i] = '\0', cout << "\n";
			}
		}
	}
	return log;
}
int enteri(int n) {
	int i = 0;
	char* log;
	log = new char[n + 1];
	while (log[i] != '\0') {
		log[i] = _getch();
		if (log[i] == 8 && i > 0) cout << "\b \b", --i;
		else {
			if (log[i] >= '0'&&log[i] <= '9') {
					cout << log[i];
					++i;
				}
			if (log[i] == 13) log[i] = '\0', cout << "\n";
			}
	}
	return atoi(log);
}
string enters(int n) {
	char* log;
	log = new char[n + 1];
	int i = 0;
	while (log[i] != '\0') {
		log[i + 1] = '8';
		log[i] = _getch();
		if (log[i] == 8 && i > 0) cout << "\b \b", --i;
		else if (log[i] != 8) {
			if (i < n) {
				if ((log[i] >= 'A'&&log[i] <= 'Z') || (log[i] >= 'a'&&log[i] <= 'z'))cout << log[i], ++i;
				if (log[i] == 13) log[i] = '\0', cout << "\n";
			}
		}
	}
	return log;
}
string enterf(int n1,int n2) {
	int i = 0, g=0;
	int a1, a2;
	a1 = a2 = 0;
	char* log;
	log = new char[n1+n2+2];
	while (log[i] != '\0') {
		log[i] = _getch();
		if (log[i] == 8 && i > 0) { cout << "\b \b", --i;
		if(log[i]==',')g=0;
		else {
			if (g == 0)--a1;
			else --a2;
		}
		}
		else {
			if (log[i] >= '0'&&log[i] <= '9'&&((a1<n1&&g==0)||(a2<n2)&&g==1)) {
				if (g == 0)++a1;
				else ++a2;
				cout << log[i];
				++i;
			}
			if (log[i]==','&&i!=0&&g!=1) {
				cout << log[i];
				++i;
				g = 1;
			};
			if (log[i] == 13) log[i] = '\0', cout << "\n";
		}
	}
	return log;
}
string ftoa(double n,int t) {
	char res[20],*toch;
	toch = new char[t];
	itoa(n, res, 10);
	n -= atoi(res);
	strcat(res, ",");
	for (int i = 0; i < t; ++i) {
	n *= 10;
	itoa(n,toch,10);
	strcat(res,toch);
	n -= atoi(toch);
	}
	return res;
}
string Kodir(string p) {
	char a[5];
	for (int i = 0; i < 4; ++i) {
		 a[i]=p.c_str()[i]- 5;
	}
	a[4] = '\0';
	return a;
}
string Dekodir(string p){
	char a[5];
	for (int i = 0; i < 4; ++i) {
		a[i] = p.c_str()[i] + 5;
	}
	a[4] = '\0';
	return a;
}

template <class T>
struct Status {
	T* ptr; // Указатель на объект
	int counter; // Счетчик числа ссылок на объект
};
//Класс умного указателя.
template <class T>
class SmartPointer {
	Status<T>* smartPtr;
public:
	SmartPointer(T* ptr) {
		if (!ptr) smartPtr = NULL; // Указатель на объект пустой
		else {
			smartPtr = new Status<T>;
			smartPtr->ptr = ptr; // Инициализирует объект указателем
			smartPtr->counter = 1; //Счетчик «прикрепленных» объектов инициализируем единицей
		}
	};
	SmartPointer(const SmartPointer* obj) :smartPtr((*obj).smartPtr) {
		if (smartPtr) smartPtr->counter++; // Увеличение числа ссылок
	};
	~SmartPointer() {
		if (smartPtr) {
			smartPtr->counter--; //Уменьшается число ссылок на объект
			if (smartPtr->counter <= 0) { // Если число ссылок на объект меньше либо равно нулю, то уничтожается объект
				delete smartPtr->ptr;//Ссылка на объект уничтожается
				delete smartPtr;
			}
		}
	}
	T* operator *() {
		if (smartPtr) return smartPtr->ptr;
		else return NULL;
	}
	SmartPointer& operator=(const SmartPointer& obj) {
		if (smartPtr) {
			smartPtr->counter--; // Уменьшаем счетчик «прикрепленных» объектов
			if (smartPtr->counter <= 0) { // Если объектов нет, то выполняется освобождается выделенная память
				delete smartPtr->ptr;
				delete smartPtr;
			}
		}
		smartPtr = obj.smartPtr; // Присоединение к новому указателю
		if (smartPtr) smartPtr->counter++; // Увеличить счетчик «прикрепленных» объектов
		return *this;
	}
	void showCounter() { cout << smartPtr->counter; }
};

class Student {
	string surname,firstname, secondname, lgot;
	int* bal;
	int kol;
	double sredbal;
public:
	Student(int n) { surname = firstname = secondname = lgot = " ";
	bal = new int[n];
	kol = n;
	sredbal = 0;
	}
	Student(string sur, string first, string second){
		surname = sur;
		firstname = first;
		secondname = second;
		lgot = '-';
		kol = 1;
		bal = new int[kol];
		for (int i = 0; i < kol; ++i) {
			bal[i] = 0;
		}
		sredbal = 0;
	}
	Student(string sur,string first,string second,string l, int n, int * b){
		surname = sur;
		firstname = first;
		secondname = second;
		lgot = l;
		kol = n;
		bal = new int[n];
		for (int i = 0; i < n; ++i) {
			bal[i] = b[i];
		}
		sredbal=0;
	}
	Student(string sur, string first, string second, string l, int n) {
		surname = sur;
		firstname = first;
		secondname = second;
		lgot = l;
		kol = n;
		bal = new int[n];
		for (int i = 0; i < n; ++i) {
			bal[i] = 0;
		}
		sredbal = 0;
	}
	void dobavBal(int n, int b) { bal[n] = b; };
	string dobavLgot(string l) { 
	if (lgot=="-")lgot = l;
	else lgot =ftoa(atof(lgot.c_str()) + atof(l.c_str()), 2);
	return lgot;
	}
	bool operator==(Student stud) {
		if (surname==stud.surname){
			if (firstname == stud.firstname) {
				if (secondname == stud.secondname)return true;
			}
		}
		return false;
	}
	void obnov(int n) {
		delete []bal;
		kol = n;
		bal = new int[n];
		for (int i = 0; i < n; ++i) {
			bal[i] = 0;
		}
	}
	string FIO() {
		return surname +" "+ firstname+" "+ secondname;
	}
	int showBal(int n) { return bal[n]; }
	double sred() { 
		if (sredbal == 0) {
		for (int i = 0; i < kol; ++i) { if (bal[i] > 4) sredbal += bal[i];
		else { sredbal = 0; i = kol; }
		}
		sredbal = sredbal / kol;
	}
	return sredbal;
	}
	friend ofstream& operator<<(ofstream& file, Student stud);
};
ofstream& operator<<(ofstream& file, Student stud) {
	file <<"\n"<<(stud.surname).c_str() << " " << (stud.firstname).c_str() << " " << (stud.secondname).c_str() << " " << (stud.lgot).c_str();
	for (int i = 0; i < stud.kol; ++i) {
		file << " " << stud.bal[i];
	}
	return file;
}
class Grupa {
	string number;
	vector <int> pred;
	vector<Student> students;
public:
	Grupa():number(" "){}
	Grupa(string num) {
		pred.clear();
		students.clear();
		int g=0;
		char sur[15], first[15], sec[15],lg[10];
		int *bal;
		char p[4];
		string a;
		number = num;
		num += ".txt";
		ifstream file(num);
		if (file.is_open()) {
			while (g == 0) {
				file >> p;
				a = p;
				if (a!="end")pred.push_back(atoi(p));
				else g = pred.size();
			}
			bal = new int[g];
			while (!file.eof()) {
				file >> sur >> first >> sec>>lg;
				for (int i = 0; i < g; ++i) {
					file >> bal[i];
				}
				students.push_back(Student(sur, first, sec, lg, g, bal));
			}
		}
		file.close();
	}
	~Grupa() {
		char a[3];
		ofstream file(number + ".txt");
		if (file.is_open()) {
			for (int i = 0; i < pred.size(); ++i) {
				itoa(pred[i], a, 10);
				file << a<< " ";
			}
			file << "end";
			for (int i=0;i<students.size();++i){
				file << students[i];
			}
		}
		file.close();
	}
	bool sozdPred(int a) {
		for (int i = 0; i < pred.size(); ++i) {
			if (pred[i] == a)return false;
		}
		pred.push_back(a);
		return true;
	}
	bool sozdStud(Student stud) { 
		for (int i = 0; i < students.size(); ++i) {
			if (stud == students[i])return false;
		}
		students.push_back(stud); 
		return true;
	}
	bool dobavLgot(string fio, string l) {
		for (int i = 0; i < students.size(); ++i) {
			if (fio == students[i].FIO()) { students[i].dobavLgot(l); return true; }
		}
		return false;
	};
	bool delStud(Student stud){
		vector<Student>::iterator s=students.begin();
		while (s!=students.end()) {
			if (stud.FIO() == (*s).FIO()) { students.erase(s); return true; }
			++s;
		}
		return false;
	}
	int kol() {
		return pred.size();
}
	void obnovP() { pred.clear(); }
	void obnovS() {for (int i = 0; i < students.size();++i) { students[i].obnov(pred.size()); }}
	bool ProsmBal(int n, int v){
		int b;
		for (int i = 0; i < pred.size(); ++i) {
			if (pred[i] == n||n==-1) {
				for (int j = 0; j < students.size(); ++j) {
					cout << students[j].FIO().c_str();
							if (v==1)cout << ": "<< students[j].showBal(i)<<"\n";
							if (v == 2) cout << "\n";
				}
				return true;
			}
		}
		return false;
	}
	bool VystBal(int n){
		int b;
		for (int i = 0; i < pred.size(); ++i) {
			if (pred[i] == n) {
				for (int j = 0; j < students.size(); ++j) {
					do {
						cout << students[j].FIO().c_str() << ": ";
						b = enteri(2);
						system("cls");
						if (b > 10)cout << "Ошибка!Некорректное значение!Повторите попытку!\n";
						else students[j].dobavBal(i, b);
					} while (b>10);
				}
				return true; }
		}
		return false;
	}
	string Pred(int i) {
		map<int, string>::iterator mapPtr;
		mapPtr = VsePredmetyi.find(pred[i]);
		return mapPtr->second;
	}
	void lgoty() {
		for (int i = 0; i < students.size(); ++i) {
			cout << students[i].FIO().c_str() << ": " << students[i].dobavLgot("-").c_str()<<endl;
		}
	}
	void RaschStep() {
		double * stepznach;
		stepznach = new double[students.size()];
		for (int i = 0; i < students.size(); ++i) {
			int a =students[i].sred();
			switch (a)
			{
			case 5:stepznach[i] = RasmStep[0]; break;
			case 6:case 7:stepznach[i] = RasmStep[1]; break;
			case 8:stepznach[i] = RasmStep[2]; break;
			case 9:case 10:stepznach[i] = RasmStep[3]; break;
			default:stepznach[i] = 0; break;
			}
			stepznach[i] += atof(students[i].dobavLgot("-").c_str());
			cout << students[i].FIO().c_str() << ":" << ftoa(stepznach[i], 2).c_str() <<"\n";
		}
		cout << "Хотите сохранить отчёт о рассчитанных степендиях?\nДа - 1     Нет - 2\n";
		if (_getch() == '1') { ofstream file("step" + number + ".txt");
		for (int i = 0; i < students.size(); ++i)file << students[i].FIO().c_str() << ":" << ftoa(stepznach[i], 2).c_str() << "\n";
		}
	}
};
class Acount {
public:
	virtual void change() = 0;
};
class Client : public Acount{
	string number, password;
	int access;
public:
	Client(string n) {
		number=n;
		password= " ";
		access = 0;
	}
	Client(Client* c) {
		number = c->number;
		password=c->password;
		access = c->access;}
	Client (string n, string p,int a){
		number=n;
		password= p;
		access = a;
	}
	bool set(string n) {   
		number= n;
		int g = 0;
		char a[9];
		string a1;
		ifstream file("login.txt");
		if (file.is_open()) {
			while (!file.eof() && g == 0) {
				file.getline(a, 9);
				a1 = a;
				if (a1==n)g = 1;
			}
			if (g == 1) {
				file.getline(a, 5);
				password=Dekodir(a);
				file.getline(a, 9);
				access = atoi(a);
				file.close();
				return true;
			}
		}
		file.close();
		return false;

	}
	bool reg(string p, int dost) {
		password= p;
		access = dost;
		system("cls");
		cout << "Повторите пороль:";
		int i = 0;
		string log = "12345";
		log = enter1(4);
		p= log;
		if (p!= password)return false;
		else return true;
	}
	bool vhod(string p) {
		if (p== password) return true;
		else return false;
	}
	int dost() { return access; }
	string num() { return number; }
string pass() { return password; }
	void change() {
		char a1[9];
		string a, n;
		int g = 1;
		 do {
		cout << "Введите действующий пороль: ";
		a=enter1(4);
		system("cls");
		if (password!= a) {
			cout << "Пороль не верный!\nПовторить попытку - 1\nВернуться в меню - 2\n";
			g = _getch() - '2';
		}
		}while (password!=a && g != 0);
		if (g != 0) {
			while (a!= n && g != 0) {
				system("cls");
				cout << "Новый пороль:";
				a= enter1(4);
				system("cls");
				cout << "Повторите пороль:";
				n= enter1(4);
				system("cls");
				if (a!= n)cout << "Не верно!\nПовторить попытку - 1\nВернуться в меню - 2\n", g = _getch() - '2';
			}
			if (g != 0) {
				g = 0;
				int k = 0;
				fstream file("login.txt", ios::in | ios::out);
				if (file.is_open()) {
					while (!file.eof() && g == 0) {
						file.getline(a1, 9);
						a = a1;
						if (a== number) {
							g=file.tellg();
						}
						k++;
					}
					file.seekp(g);
					password= n;
					file << Kodir (n).c_str();
				}
				file.close();
			}
		}
	}
	bool operator==(string n){return (this->number == n);}
};
bool poiskgr(string n) {
		char num[7];
		ifstream file("grup.txt");
		if (file.is_open()) {
			while (!file.eof()) {
				file >> num;
				if (n == num) { file.close();
				return true; }
			}
		}
		file.close();
		return false;
	}
class Admin:public Client {
	SmartPointer <map <string, Client>>pols=new map <string, Client>;
public:
	Admin(Client* c): Client::Client(c){
		char n[9], p[5],a[2];
		ifstream file("login.txt");
		if (file.is_open()) {
			while (!file.eof()) {
				file>>n;
				file>>p;
				file>>a;
				(**pols).insert(pair<string,Client>(n,Client(n,Dekodir( p), atoi(a))));
			}
		}
		file.close();
	}
	~Admin() {
		map<string, Client>::iterator mapPtr;
		mapPtr = (**pols).begin();
		++mapPtr;
		ofstream file("login.txt");
		if (file.is_open()) {
			while (mapPtr!=(**pols).end()) {
				file << (mapPtr->second).num().c_str() << "\n" << Kodir((mapPtr->second).pass()).c_str() << "\n"<<(mapPtr->second).dost() << "\n";
				++mapPtr;
			}
		}
		file.close();
		(**pols).clear();
	}
	bool poisk(string p){
		map<string, Client>::iterator mapPtr;
		mapPtr = (**pols).find(p);
		if (mapPtr != (**pols).end())return true;
		else return false;
	}
	void dobav(string n, string p, int a){ (**pols).insert(pair<string, Client>(n, Client(n, p, a))); }
	bool del(string n) {
		if (!poisk(n))return false;
		else { (**pols).erase(n); return true; }
	}
	void change() {
		Client::change();
		(**pols).erase(num());
		(**pols).insert(pair<string, Client>(num(), Client(num(), pass(), dost())));
	}
};


int main() {
	setlocale(LC_ALL, "Russian");
	Nachalo();
	int get;
	string log = "12344445";
	Client client(log);
	Acount* acount;
	while (true) {
		int resh = 0;
		do {system("cls");
	acount = &client;
			cout << "Вход - 1\nОкончание работы - 0\n";
			switch (_getch())
			{
			case'0': {Konec();
				system("pause");
				return 0; }
			case '1': {
				try {
			system("cls");
					int i = 0;
					cout << "Логин:";
					log= enter(8);
					if (!client.set(log))throw '1';
					cout << "Пароль:";
					i = 0;
					log= enter1(4);
					if (!client.vhod(log))throw 1 ;
					resh = 1;
				}
				catch (int) {
					system("cls"); cout << "Неверный логин или пароль, попробуйте ещё раз\n";
					system("pause");
	 }
				catch (char) {
					system("cls"); cout << "Неверный логин попробуйте ещё раз\n";
					system("pause");
				}
				break;
			}
			}
		} while (resh != 1);
		do {
			switch (client.dost())
			{
			//Админ----------------------
			case 0: {
				system("cls");
				Admin admin(&client);
				acount = &admin;
				do {
				cout << "Создать учётную запись - 1\nУдалить учётную запись - 2\nИзменить пароль - 3\nВыход из учётной записи - 0\n";
				get = _getch();
				switch (get) {
				case '1': {
					system("cls");
					int i = 0;
					cout << "Логин (не более 8 символов):";
					log= enter(8);
					char k = 0;
					resh = 0;
						system("cls"); 
					if (admin.poisk(log)) {cout << "Ошибка! Такой логин уже существует!\n";
					}
					else {
						do {
							cout << "Право доступа:\nАдминистратор - 0\nБухгалтер - 1\nПреподователь - 2\nДеканат - 3\nОтдел кадров - 4\n";
							k = _getch();
							if (k<'0' || k>'4') {
								system("cls"); cout << "Ошибка!Повторите попытку!\n";
							}
						} while (k<'0' || k>'4');
						while (resh == 0) {
							cout << "\nПароль (4 цифры):";
							i = 0;
							string p;
							p= enter1(4);
							system("cls");
							if (!admin.reg(p, k - '0')) {
								system("cls");
								cout << "Неверно!\nПовторить попытку - 1\nВернуться в начальное меню - 2\n";
								if (_getch() == '2') break;
							}
							else {
							admin.dobav(log,p,k-'0');
							resh = 1;
							system("cls");
							cout << "Учетная запись создана.\n"; }
						}
					}
					break; }
				case '2': {
					system("cls"); 
					cout << "Логин:";
					log=enter(8);
					system("cls");
					if(admin==log)cout<<"Эту учётную запись удалить нельзя!\n";
					else {
						if (admin.del(log))cout << "Запись удалена!\n";
						else cout << "Ошибка!Такой записи нет!\n";
					}
					break; }
				case '3': {
					system("cls"); 
					acount->change();
					system("cls");
					break; }
				case '0': break;
				}
			} while (get != '0');
			break; }
			//Бухгалтер------------------
			case 1: {
				system("cls");
				do {
				cout << "Расчитать степендии студетов группы - 1\nПоменять пороль - 2\nВыйти с учётной записи - 0\n";
				get = _getch();
				switch (get) {
				case '1': {
					system("cls"); cout << "Введите номер группы:";
					string g;
					g = enter1(6);
					system("cls");
					if (!poiskgr(g)) cout << "Такой группы нет!\n";
					else {
						Grupa grup(g);
						grup.RaschStep();
						system("cls");
					}
					break;
				}
				case '2': {
					system("cls"); 
					acount->change();
					system("cls"); break; }
				case'0': {break; }
				}
			} while (get != '0');
				break;
			}                 
			//Преподаватель--------------
			case 2: {
				system("cls");
				do {
					cout << "Выставить оценки группе - 1\nПросмотреть оценки группы по придмету - 2\nПоменять пороль - 3\nВыйти с учётной записи - 0\n";
					get = _getch();
					switch (get) {
					case '1': {
						system("cls"); 
						cout << "Введите номер группы:";
						string g;
						g = enter1(6);
						system("cls");
						if (!poiskgr(g)) cout << "Такой группы нет!\n";
						else{
							Grupa grup(g);
							string pred;
							cout << "Введите название предмета(аббревиатура):";
							pred = enters(10);
							system("cls");
							map<string, int>::iterator mapPtrs;
							mapPtrs = VsePredmetys.find(pred);
							if (mapPtrs != VsePredmetys.end()) {
								if (grup.VystBal(mapPtrs->second));
								else cout << "Такого предмета нет в списке группы!\n";
							}
							else cout << "Такого предмета нет!\n";
						}
						break; }
					case '2': {
						system("cls"); 
						cout << "Введите номер группы:";
						string g;
						g = enter1(6);
						system("cls");
						if (!poiskgr(g)) cout << "Такой группы нет!\n";
						else {
							Grupa grup(g);
							string pred;
							cout << "Введите название предмета(аббревиатура):";
							pred = enters(10);
							system("cls");
							map<string, int>::iterator mapPtrs;
							mapPtrs = VsePredmetys.find(pred);
							if (mapPtrs != VsePredmetys.end()) {
								if (!grup.ProsmBal(mapPtrs->second, 1))cout<<"Такого предмета нет в предметах группы!\n";
							}
							else cout << "Такого предмета нет!\n";
						}
				system("pause");
				system("cls");
						break; }
					case '3': {
						system("cls"); 
						acount->change();
						system("cls"); break; }
					case '0': {break; }
					}
				} while (get != '0');
				break;
			}
			//Деканат--------------------
			case 3: {
				system("cls");
				do {
					cout << "Выписать премию студенту - 1\nПолучить отчёт о премиях студентов группы - 2\nИзменить пороль - 3\nВыйти с учётной записи - 0\n";
					get = _getch();
					switch (get) {
					case '1': {
						system("cls"); 
						cout << "Введите номер группы студента:";
						string grup;
						grup = enter1(6);
						system("cls");
						if (!poiskgr(grup))cout << "Такой группы не существует!\n";
						else {
							Grupa grupa(grup);
							cout << "Введите ФИО студента\nФамилия:";
							string fa, na, ot;
							fa = enters(15);
							cout << "Имя:";
							na = enters(15);
							cout << "Отчество:";
							ot = enters(15);
							cout << "Введите размер премии:";
							string prem = enterf(3, 2);
							system("cls");
							if (!grupa.dobavLgot(fa + " " + na + " " + ot, prem))cout << "Такого студента нет в группе\n";
						}
						break; }
					case '2': {
						system("cls"); 
						cout << "Введите номер группы:";
						string grup;
						grup = enter1(6);
						system("cls");
						if (!poiskgr(grup))cout << "Такой группы не существует!\n";
						else {
							Grupa grupa(grup);
							grupa.lgoty();
							system("pause");
							system("cls");
						}
						break; }
					case '3': {
						system("cls");
						acount->change();
						system("cls"); break; }
					case '0': {break; }
					}
				} while (get != '0');
				break; }
			//Отдел кадров---------------
			case 4: {
					system("cls");
				do {
					cout << "Создать группу - 1\nРедактировать данные группы - 2\nПросмотреть список группы - 3\nИзменить пороль - 4\nВыйти с учётной записи - 0\n";
					get = _getch();
					switch (get) {
					case '1': {
						system("cls"); 
						cout << "Введите номер группы :";
						string g;
						g = enter1(6);
						system("cls");
						if (poiskgr(g))cout << "Такая группа уже существует!\n";
						else {
							Grupa grup(g);
							cout << "Введите количество предметов (не более 9)\n";
							int n = enteri(1);
							system("cls");
							cout << "Введите названия предметов латиницей(аббревиатуры):\n";
							for (int i = 0; i < n; ) {
								string pred;
								cout << "Предмет:";
								pred = enters(10);
								map<string, int>::iterator mapPtrs;
								mapPtrs = VsePredmetys.find(pred);
								if (mapPtrs != VsePredmetys.end()) {
									if (grup.sozdPred(mapPtrs->second))++i;
									else {
										system("cls");
										cout << "Такой предмет уже есть в предметах группы!Введите другой!\n"; }
								}
								else {
									system("cls");
									cout << "Такого предмета нет.\nЖелаете добавить?\nДа - 1   Нет - 2\n\nПо умолчанию предмет не будет добавлен!\n";
									char r = _getch();
									system("cls");
									if (r == '1'){
										map<int,string>::iterator mapPtri;
										int j = 0;
										do {
											++j;
											mapPtri = VsePredmetyi.find(j);
										} while (mapPtri != VsePredmetyi.end());
										VsePredmetys.insert(pair<string, int>(pred, j));
										VsePredmetyi.insert(pair<int, string>(j, pred));
										grup.sozdPred(j);
										++i;
									}
								}
							}
							
							int *bal;
							bal = new int[n];
							for (int i = 0; i < n; ++i) {
								bal[i] = 0;
							}
							system("cls");
							cout << "Введите количество студентов (не более 35)\n";
							int n1 = 0;
							do {n1 = enteri(2);
							system("cls");
							if (n1 < 1 || n1>35)cout << "Неверное количество студентов!Повторите попытку:";
							} while (n1<1||n1>35);
							cout << "Введите ФИО студентов латиницей:\n";
							for (int i = 0; i < n1; ) {
								string fa,na,ot;
								cout <<i+1 << ").Фамилия:";
								fa = enters(15);
								cout << "Имя:";
								na = enters(15);
								cout << "Отчество:";
								ot = enters(15);
								Student stud(fa, na, ot, "-",n, bal);
								if (!grup.sozdStud(stud))cout<<"\nТакой студент уже есть в группе!\n";
								else ++i;
							}
							ofstream f("grup.txt", ios::app);
							f << g.c_str()<<"\n";
							system("cls");
							cout << "Группа создана!\n";
						}
						break; }
					case '2': {
						char ge;
						system("cls");
						do {
						cout << "Добавить студента - 1\nУдалить студента - 2\nИзменить список предметов - 3\nНазад - 0\n";
						ge = _getch();
						switch (ge) {
						case '1': {
							system("cls"); 
							cout << "Введите номер группы студента:";
							string grup;
							grup = enter1(6);
							system("cls");
							if (!poiskgr(grup))cout << "Такой группы не существует!\n";
							else {
								Grupa grupa(grup);
								cout << "Введите данные студента\nФамилия:";
								string fa, na, ot;
								fa = enters(15);
								cout << "Имя:";
								na = enters(15);
								cout << "Отчество:";
								ot = enters(15);
								Student stud(fa, na, ot, "-", grupa.kol());
								system("cls");
								cout << "Введите оценки по предметам:\n";
								int o;
								for (int i = 0; i < grupa.kol(); ++i) {
									do {
										cout << grupa.Pred(i).c_str() << ":";
										o = enteri(2);
										if (o > 10) {
											system("cls"); cout << "Ошибка!Некорректное значение!Повторите попытку!\n";
										}
									} while (o > 10);
									stud.dobavBal(i, o);
								}
								system("cls");
								if (!grupa.sozdStud(stud))cout << "Такой студент уже есть в группе!\n";
							}
							ge = '0';
							break;
						}
						case '2': {
							system("cls"); 
							cout << "Введите номер группы студента:";
							string grup;
							grup = enter1(6);
							system("cls"); 
							if (!poiskgr(grup))cout << "Такой группы не существует!\n";
							else {
								Grupa grupa(grup);
								cout << "Введите ФИО студента\nФамилия:";
								string fa, na, ot;
								fa = enters(15);
								cout << "Имя:";
								na = enters(15);
								cout << "Отчество:";
								int bal[1] = { 0 };
								ot = enters(15);
								Student stud(fa, na, ot);
								system("cls");
								if (!grupa.delStud(stud))cout << "Такого студента нет в группе!\n";
								else cout << "Студент удалён\n";
							}
							ge = '0';
							break; }
						case '3': {
							system("cls"); 
							cout << "Введите номер группы:";
							string g;
							g = enter1(6);
							system("cls");
							if (!poiskgr(g))cout << "Такой группы не существует!\n";
							else {
								Grupa grup(g);
								grup.obnovP();
								cout << "Введите количество предметов (не более 9)\n";
								int n = enteri(1);
								system("cls");
								cout << "Введите названия предметов латиницей(Аббревиатуры):\n";
								for (int i = 0; i < n; ) {
									string pred;
									cout << "Предмет:";
									pred = enters(10);
									map<string, int>::iterator mapPtrs;
									mapPtrs = VsePredmetys.find(pred);
									if (mapPtrs != VsePredmetys.end()) {
										if (grup.sozdPred(mapPtrs->second))++i;
										else {
											system("cls");
											cout << "Такой предмет уже есть в предметах группы!Введите другой!\n";
										}
									}
									else {
										system("cls");
										cout << "Такого предмета нет.\nЖелаете добавить?\nДа - 1   Нет - 2\n\nПо умолчанию предмет не будет добавлен!\n";
										char r = _getch();
										if (r == '1') {
											map<int, string>::iterator mapPtri;
											int j = 0;
											do {
												++j;
												mapPtri = VsePredmetyi.find(j);
											} while (mapPtri != VsePredmetyi.end());
											VsePredmetys.insert(pair<string, int>(pred, j));
											VsePredmetyi.insert(pair<int, string>(j, pred));
											grup.sozdPred(j);
											++i;
										}
									}
								}
								grup.obnovS();
								system("cls");
							}
							ge = '0';
							break;
						}
						case '0': {system("cls"); break; }
						}
					} while (ge != '0');
					break; }
					case '3': {
							system("cls");
							cout << "Введите номер группы студента:";
							string grup;
							grup = enter1(6);
							system("cls");
							if (!poiskgr(grup))cout << "Такой группы не существует!\n";
							else {
								Grupa grupa(grup);
								grupa.ProsmBal(-1, 2);
							}
								system("pause"); 
								system("cls");
							break; }
					case '4': {
						system("cls");
						acount->change();
						system("cls"); break; }
					case '0': {break; }
					}
				} while (get != '0');
				break;
			}
			}
		} while (get != '0');
	}
}