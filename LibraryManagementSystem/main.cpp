#define NOMINMAX
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <string>
#include <mysql.h>
#include <fstream>
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

	cout << "��ӭ���ٿͻ���¼���棡" << endl;
	cout << "�������û�����" << endl;
	char customer_username[256];
	cin >> customer_username;
	cout << "���������룺" << endl;
	char customer_password[256];
	cin >> customer_password;
	
	char query[512];
	sprintf(query, "select count(*) from accounts where username = '%s' and password = '%s'", customer_username, customer_password);

	mysql_query(conn, query);

	MYSQL_RES* result = mysql_store_result(conn);

	MYSQL_ROW row = mysql_fetch_row(result);
	int count = atoi(row[0]);
	if (count > 0) {
		cout << "��¼�ɹ���" << endl;
	}
	else {
		cout << "�û�����������������ԣ�" << endl;
		customerSelectionInterface();
	}

	mysql_free_result(result);
	mysql_close(conn);

	system("pause");
	system("cls");
}

void customerRegisterInterface() {
	cout << "��ӭ���ٿͻ�ע����棡" << endl;
	
	// ��ʼ�� mysql ���ݿ�
	MYSQL* conn = mysql_init(NULL);
	
	// ���� mysql ���ݿ�
	mysql_real_connect(conn, host, username, password, NULL, port, NULL, 0);

	// ѡ�� customer_db ���ݿ�
	mysql_select_db(conn, "customer_db");

	cout << "�����û�����" << endl;
	char customer_username[256];
	cin >> customer_username;
	cout << "�������룺" << endl;
	char customer_password1[256];
	cin >> customer_password1;
	cout << "ȷ�����룺" << endl;
	char customer_password2[256];
	cin >> customer_password2;
	
	char query[512];
	sprintf(query, "select count(*) from accounts where username = '%s'", customer_username);

	mysql_query(conn, query);

	MYSQL_RES* result = mysql_store_result(conn);

	MYSQL_ROW row = mysql_fetch_row(result);
	int count = atoi(row[0]);

	if (count > 0) {
		cout << "�û����Ѵ��ڣ����޸��û�����" << endl;
		system("pause");
		system("cls");
		mysql_free_result(result);
		mysql_close(conn);
		customerRegisterInterface();
		return;
	}


	if (strcmp(customer_password1, customer_password2) != 0) {
		cout << "�����������벻һ�£����������ã�" << endl;
		system("pause");
		system("cls");
		customerRegisterInterface();
		return;
	}

	// �������� sql ���
	char insert_sql[256];
	sprintf(insert_sql, "insert into accounts (username, password) values ('%s', '%s')", customer_username, customer_password1);
	mysql_query(conn, insert_sql);

	cout << "ע��ɹ������ؿͻ�ѡ�����" << endl;
	system("pause");
	system("cls");
	customerSelectionInterface();

}


void customerSelectionInterface() {
	cout << "��ӭ���ٿͻ�ѡ����棡" << endl;
	cout << "1.��Ҫ��¼" << endl
		<< "2.��Ҫע��" << endl
		<< "3.�������ѡ�����" << endl
		<< "������ѡ��";
	int choose;
	bool flag = false;
	while (!flag) {
		cin >> choose;

		// ��������
		if (cin.fail()) {
			cout << "��Ч���룡������ѡ��";
			cin.clear(); // ��������
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ��������
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
			cout << "��Ч���룡������ѡ��";
			break;
		}
	}
}

void AdministratorSelectionInterface() {
	cout << "��ӭ���ٹ���Աѡ����棡" << endl;
	cout << "1.��Ҫ��¼" << endl
		<< "2.��Ҫע��" << endl
		<< "3.�������ѡ�����" << endl
		<< "������ѡ��";
	int choose;
	bool flag = false;
	while (!flag) {
		cin >> choose;

		// ��������
		if (cin.fail()) {
			cout << "��Ч���룡������ѡ��";
			cin.clear(); // ��������
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ��������
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
			cout << "��Ч���룡������ѡ��";
			break;
		}
	}
}

void exitInterface() {
	cout << "��ӭ�´ι��٣�" << endl;
	system("pause");
}

void identitySelectionInterface() {
	cout << "��ӭ�������ѡ����棡" << endl;
	cout << "1.���ǿͻ�" << endl
		<< "2.���ǹ���Ա" << endl
		<< "3.�˳�" << endl
		<< "������ѡ��";
	int choose;
	bool flag = false;
	while (!flag) {
		cin >> choose;

		// ��������
		if (cin.fail()) {
			cout << "��Ч���룡������ѡ��";
			cin.clear(); // ��������
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ��������
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
			cout << "��Ч���룡������ѡ��";
			break;
		}
	}

}


int main() {

	identitySelectionInterface();

	/*
	// ��ʼ�� mysql ����
	MYSQL* conn = mysql_init(NULL);
	if (conn == NULL) {
		cerr << "mysql_init() failed" << endl;
		return EXIT_FAILURE;
	}
	cout << "mysql_init() succeeded" << endl;

	// ���ӵ� mysql ������
	if (mysql_real_connect(conn, host, username, password, NULL, port, NULL, 0) == NULL) {
		cerr << "mysql_real_connect failed:" << mysql_error(conn) << endl;
		mysql_close(conn);
		return EXIT_FAILURE;
	}
	cout << "mysql_real_connect succeeded:" << endl;

	// ѡ�����ݿ�
	if (mysql_select_db(conn, "customer_db")) {
		cerr << "mysql_select_db() failed:" << mysql_error(conn) << endl;
		mysql_close(conn);
		return EXIT_FAILURE;
	}
	cout << "select db succeeded" << endl;

	// ����ͻ��˻���Ϣʾ��
	char customer_username[256];
	char customer_password[256];
	cout << "�������û�����";
	cin >> customer_username;
	cout << "���������룺";
	cin >> customer_password;

	char insert_sql[256];
	sprintf(insert_sql, "INSERT INTO accounts (username, password) VALUES ('%s', '%s')", customer_username, customer_password);
	
	if (mysql_query(conn, insert_sql)) {
		cerr << "insert failed:" << mysql_error(conn) << endl;
		mysql_close(conn);
		return EXIT_FAILURE;
	}
	cout << "customer account inerted successfully." << endl;

	// �ر� mysql ����
	mysql_close(conn);
	cout << "mysql connection closed." << endl;

	*/
	return 0;
}