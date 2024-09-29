#define NOMINMAX
#define _CRT_SECURE_NO_WARNINGS

#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <windows.h>

#include <iostream>
#include <cstdlib>
#include <string>
#include <mysql.h>
#include <fstream>
#include <crow.h>

using namespace std;

const char* host = "127.0.0.1";
const char* username = "root";
const char* password = "123456";
const int port = 3306;

void identitySelectionInterface();

void customerSelectionInterface();


bool isUsernameExist() {
	return false;
}

bool isUsenamePasswordMatch() {
	return false;
}

void customerLoginInterface() {
	MYSQL* conn = mysql_init(NULL);
	mysql_real_connect(conn, host, username, password, NULL, port, NULL, 0);
	mysql_select_db(conn, "customer_db");

	cout << "欢迎光临客户登录界面！" << endl;
	cout << "请输入用户名：" << endl;
	char customer_username[256];
	cin >> customer_username;
	cout << "请输入密码：" << endl;
	char customer_password[256];
	cin >> customer_password;
	
	char query[512];
	sprintf(query, "select count(*) from accounts where username = '%s' and password = '%s'", customer_username, customer_password);

	mysql_query(conn, query);

	MYSQL_RES* result = mysql_store_result(conn);

	MYSQL_ROW row = mysql_fetch_row(result);
	int count = atoi(row[0]);
	if (count > 0) {
		cout << "登录成功！" << endl;
	}
	else {
		cout << "用户名或密码错误，请重试！" << endl;
		customerSelectionInterface();
	}

	mysql_free_result(result);
	mysql_close(conn);

	system("pause");
	system("cls");
}

void customerRegisterInterface() {
	cout << "欢迎光临客户注册界面！" << endl;
	
	// 初始化 mysql 数据库
	MYSQL* conn = mysql_init(NULL);
	
	// 连接 mysql 数据库
	mysql_real_connect(conn, host, username, password, NULL, port, NULL, 0);

	// 选择 customer_db 数据库
	mysql_select_db(conn, "customer_db");

	cout << "设置用户名：" << endl;
	char customer_username[256];
	cin >> customer_username;
	cout << "设置密码：" << endl;
	char customer_password1[256];
	cin >> customer_password1;
	cout << "确认密码：" << endl;
	char customer_password2[256];
	cin >> customer_password2;
	
	char query[512];
	sprintf(query, "select count(*) from accounts where username = '%s'", customer_username);

	mysql_query(conn, query);

	MYSQL_RES* result = mysql_store_result(conn);

	MYSQL_ROW row = mysql_fetch_row(result);
	int count = atoi(row[0]);

	if (count > 0) {
		cout << "用户名已存在！请修改用户名！" << endl;
		system("pause");
		system("cls");
		mysql_free_result(result);
		mysql_close(conn);
		customerRegisterInterface();
		return;
	}


	if (strcmp(customer_password1, customer_password2) != 0) {
		cout << "两次密码输入不一致！请重新设置！" << endl;
		system("pause");
		system("cls");
		customerRegisterInterface();
		return;
	}

	// 创建插入 sql 语句
	char insert_sql[256];
	sprintf(insert_sql, "insert into accounts (username, password) values ('%s', '%s')", customer_username, customer_password1);
	mysql_query(conn, insert_sql);

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


int main() {

	identitySelectionInterface();

	return 0;
}