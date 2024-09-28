#define NOMINMAX
#include <iostream>
#include <cstdlib>
#include <string>
#include <mysql.h>
using namespace std;

void identitySelectionInterface();

void customerSelectionInterface();


bool isUsernameExist() {
	return false;
}

bool isUsenamePasswordMatch() {
	return false;
}

void customerLoginInterface() {
	cout << "欢迎光临客户登录界面！" << endl;
	cout << "请输入用户名：" << endl;
	string username;
	cin >> username;
	cout << "请输入密码：" << endl;
	string password;
	cin >> password;
	if (!isUsernameExist()) {
		cout << "用户名不存在" << endl;
		system("pause");
		system("cls");
		customerSelectionInterface();
		return;
	}
	if (!isUsenamePasswordMatch()) {
		cout << "密码错误" << endl;
		system("pause");
		system("cls");
		customerSelectionInterface();
	}
	cout << "登录成功！" << endl;
	system("pause");
	system("cls");

}

void customerRegisterInterface() {
	cout << "欢迎光临客户注册界面！" << endl;
	cout << "设置用户名：" << endl;
	string username;
	cin >> username;
	cout << "设置密码：" << endl;
	string password1;
	cin >> password1;
	cout << "确认密码：" << endl;
	string password2;
	cin >> password2;

	if (isUsernameExist()) {
		cout << "用户名已存在！请修改用户名！" << endl;
		system("pause");
		system("cls");
		customerRegisterInterface();
		return;
	}

	if (password1 != password2) {
		cout << "两次密码输入不一致！请重新设置！" << endl;
		system("pause");
		system("cls");
		customerRegisterInterface();
		return;
	}

	cout << "注册成功！返回客户选择界面" << endl;
	system("pause");
	system("cls");
	customerSelectionInterface();

}


void customerSelectionInterface() {
	cout << "欢迎光临客户选择界面！" << endl;
	cout << "1.我要登录" << endl
		<< "2.我要注册" << endl
		<< "3.返回身份选择界面" << endl
		<< "请输入选择：";
	int choose;
	bool flag = false;
	while (!flag) {
		cin >> choose;

		// ？？？？
		if (cin.fail()) {
			cout << "无效输入！请重新选择：";
			cin.clear(); // ？？？？
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ？？？？
			continue;
		}

		switch (choose) {
		case 1:
			flag = true;
			system("cls");
			customerLoginInterface();
			break;
		case 2:
			flag = true;
			system("cls");
			customerRegisterInterface();
			break;
		case 3:
			flag = true;
			system("cls");
			identitySelectionInterface();
			break;
		default:
			cout << "无效输入！请重新选择：";
			break;
		}
	}
}

void AdministratorSelectionInterface() {
	cout << "欢迎光临管理员选择界面！" << endl;
	cout << "1.我要登录" << endl
		<< "2.我要注册" << endl
		<< "3.返回身份选择界面" << endl
		<< "请输入选择：";
	int choose;
	bool flag = false;
	while (!flag) {
		cin >> choose;

		// ？？？？
		if (cin.fail()) {
			cout << "无效输入！请重新选择：";
			cin.clear(); // ？？？？
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ？？？？
			continue;
		}

		switch (choose) {
		case 1:
			cout << 1 << endl;
			flag = true;
			break;
		case 2:
			cout << 2 << endl;
			flag = true;
			break;
		case 3:
			flag = true;
			system("cls");
			identitySelectionInterface();
			break;
		default:
			cout << "无效输入！请重新选择：";
			break;
		}
	}
}

void exitInterface() {
	cout << "欢迎下次光临！" << endl;
	system("pause");
}

void identitySelectionInterface() {
	cout << "欢迎光临身份选择界面！" << endl;
	cout << "1.我是客户" << endl
		<< "2.我是管理员" << endl
		<< "3.退出" << endl
		<< "请输入选择：";
	int choose;
	bool flag = false;
	while (!flag) {
		cin >> choose;

		// ？？？？
		if (cin.fail()) {
			cout << "无效输入！请重新选择：";
			cin.clear(); // ？？？？
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ？？？？
			continue;
		}

		switch (choose) {
		case 1:
			flag = true;
			system("cls");
			customerSelectionInterface();
			break;
		case 2:
			flag = true;
			system("cls");
			AdministratorSelectionInterface();
			break;
		case 3:
			flag = true;
			system("cls");
			exitInterface();
			break;
		default:
			cout << "无效输入！请重新选择：";
			break;
		}
	}

}

const char* host = "127.0.0.1";
const char* username = "root";
const char* password = "123456";
const char* database_name = "database_test";
const int port = 3306;

int main() {

	identitySelectionInterface();

	MYSQL* conn = mysql_init(NULL);

	mysql_options(conn, MYSQL_SET_CHARSET_NAME, "GBK");

	mysql_real_connect(conn, host, username, password, database_name, port, NULL, 0);


	return 0;
}