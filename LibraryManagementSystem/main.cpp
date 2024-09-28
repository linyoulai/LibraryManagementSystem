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
	cout << "��ӭ���ٿͻ���¼���棡" << endl;
	cout << "�������û�����" << endl;
	string username;
	cin >> username;
	cout << "���������룺" << endl;
	string password;
	cin >> password;
	if (!isUsernameExist()) {
		cout << "�û���������" << endl;
		system("pause");
		system("cls");
		customerSelectionInterface();
		return;
	}
	if (!isUsenamePasswordMatch()) {
		cout << "�������" << endl;
		system("pause");
		system("cls");
		customerSelectionInterface();
	}
	cout << "��¼�ɹ���" << endl;
	system("pause");
	system("cls");

}

void customerRegisterInterface() {
	cout << "��ӭ���ٿͻ�ע����棡" << endl;
	cout << "�����û�����" << endl;
	string username;
	cin >> username;
	cout << "�������룺" << endl;
	string password1;
	cin >> password1;
	cout << "ȷ�����룺" << endl;
	string password2;
	cin >> password2;

	if (isUsernameExist()) {
		cout << "�û����Ѵ��ڣ����޸��û�����" << endl;
		system("pause");
		system("cls");
		customerRegisterInterface();
		return;
	}

	if (password1 != password2) {
		cout << "�����������벻һ�£����������ã�" << endl;
		system("pause");
		system("cls");
		customerRegisterInterface();
		return;
	}

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