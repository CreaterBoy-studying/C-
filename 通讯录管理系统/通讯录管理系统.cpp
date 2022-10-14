#include<iostream>
#include<string>
using namespace std;
#define MAX 1000 //�������

//��ϵ�˽ṹ��
struct Person {
	string m_Name; //����
	int m_Sex; //�Ա�
	int m_Age; //����
	string m_Phone; //�绰
	string m_Addr; //��ַ
};

//ͨѶ¼�ṹ��
struct Addressbooks {
	struct Person personArray[MAX]; //ͨѶ¼�б������ϵ������
	int m_Size; //ͨѶ¼����
};

//�˵�����
void showMean() {
	cout << "**********************" << endl;
	cout << "*****1.�����ϵ��*****" << endl;
	cout << "*****2.��ʾ��ϵ��*****" << endl;
	cout << "*****3.ɾ����ϵ��*****" << endl;
	cout << "*****4.������ϵ��*****" << endl;
	cout << "*****5.�޸���ϵ��*****" << endl;
	cout << "*****6.�����ϵ��*****" << endl;
	cout << "*****0.�˳�ͨѶ¼*****" << endl;
	cout << "**********************" << endl;
}

//1.�����ϵ�˺���
void addPerson(Addressbooks* abs) {
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_Size >= MAX) {
		cout << "ͨѶ¼��������,�޷����!" << endl;
		return;
	}
	else {
		//�������
		 
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 --Ů" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "����������������" << endl;
			}
		}

		//����
		int age = 0;
		cout << "����������" << endl;
		while (true) {
			cin >> age;
			if (age > 0 || age <= 150) {
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			else {
				cout << "���������������������" << endl;
			}
		}

		//�绰
		string phone;
		cout << "��������ϵ�绰" << endl;
		
		while (true) {
			cin >> phone;
			if(phone.length() == 11){
				abs->personArray[abs->m_Size].m_Phone = phone;
				break;
			}
			else {
				cout << "�ֻ��Ÿ�ʽ��������������" <<endl;
			}
		}

		//סַ
		string address;
		cout << "������סַ" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++; 

		cout << "��ӳɹ���" << endl;

		system("pause"); 
		system("cls"); //�����Ĺ���
	}
}

void showPerson(Addressbooks* abs) {
	if (abs->m_Size == 0) {
		cout << "��ϵ��Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex==1?"��":"Ů" )<< "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "��ַ��" << abs->personArray[i].m_Addr << endl;
		}
	
	}
	system("pause");
	system("cls"); //�����Ĺ���
}

//�����ϵ���Ƿ���ڵĺ���,������ڷ�����ϵ�������±꣬�����ڷ���-1
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			//�ҵ��˷��������±�
			return i;
		}
	}
	return -1; //���û�ҵ�����-1
}


//ɾ��ָ����ϵ��
void deletePerson(Addressbooks* abs) {
	cout << "������ɾ����ϵ������" << endl;
	string name;
	cin >> name;
	//ret == -1 ���޴���
	//ret ��=-1 �ҵ�����
	int ret = isExist(abs, name);
	if (ret != -1) {
		//�ҵ�����
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls"); //�����Ĺ���
}

//����ָ����ϵ��
void findPerson(Addressbooks* abs) {
	string name;
	cout << "������Ҫ���ҵ���ϵ������" << endl;
	cin >> name;
	//�ж�ָ����ϵ���Ƿ����
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "��ַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls"); //�����Ĺ���
}

//�޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks* abs) {
	cout << "��������Ҫ�޸ĵ���ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		//����
		cout << "��������������" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�Ա�
		cout << "�����������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 --Ů" << endl;
		int sex=0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else {
				cout << "����������" << endl;
			}
		}

		//����
		cout << "��������������" << endl;
		int age;
		while (true) {
			cin >> age;
			if (age > 0 || age <= 150) {
				abs->personArray[ret].m_Age = age;
				break;
			}
			else {
				cout << "���������������������" << endl;
			}
		}
		//�绰
		cout << "����������绰" << endl;
		string phone;
		while (true) {
			cin >> phone;
			if (phone.length() == 11) {
				abs->personArray[ret].m_Phone = phone;
				break;
			}
			else {
				cout << "�ֻ��Ÿ�ʽ��������������" << endl;
			}
		}
		//��ַ
		cout << "�����������ַ" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls"); //�����Ĺ���
}

//�����ϵ��
void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "��ϵ�������" << endl;
	system("pause");
	system("cls"); //�����Ĺ���
}

int main() {
	int select = 0; //�û�ѡ�����

	Addressbooks abs;
	abs.m_Size =0;
	while (true) {
		//�˵��ĵ���
		showMean();

		cin >> select;
		switch (select) {

		case 1: //1.�����ϵ��
			addPerson(&abs);
			break;

		case 2: //2.��ʾ��ϵ��
			showPerson(&abs);
			break;

		case 3: //3.ɾ����ϵ��
			deletePerson(&abs);
			break;

		case 4: //4.������ϵ��
			findPerson(&abs);
			break;

		case 5: //5.�޸���ϵ��
			modifyPerson(&abs);
			break;

		case 6: //6.�����ϵ��
			cleanPerson(&abs);
			break;

		case 0: //0.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}