#include<iostream>
#include<string>
using namespace std;
#define MAX 1000 //最大人数

//联系人结构体
struct Person {
	string m_Name; //姓名
	int m_Sex; //性别
	int m_Age; //年龄
	string m_Phone; //电话
	string m_Addr; //地址
};

//通讯录结构体
struct Addressbooks {
	struct Person personArray[MAX]; //通讯录中保存的联系人数组
	int m_Size; //通讯录人数
};

//菜单函数
void showMean() {
	cout << "**********************" << endl;
	cout << "*****1.添加联系人*****" << endl;
	cout << "*****2.显示联系人*****" << endl;
	cout << "*****3.删除联系人*****" << endl;
	cout << "*****4.查找联系人*****" << endl;
	cout << "*****5.修改联系人*****" << endl;
	cout << "*****6.清空联系人*****" << endl;
	cout << "*****0.退出通讯录*****" << endl;
	cout << "**********************" << endl;
}

//1.添加联系人函数
void addPerson(Addressbooks* abs) {
	//判断通讯录是否已满
	if (abs->m_Size >= MAX) {
		cout << "通讯录人数已满,无法添加!" << endl;
		return;
	}
	else {
		//添加数据
		 
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 --女" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "输入有误重新输入" << endl;
			}
		}

		//年龄
		int age = 0;
		cout << "请输入年龄" << endl;
		while (true) {
			cin >> age;
			if (age > 0 || age <= 150) {
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			else {
				cout << "年龄输入错误请重新输入" << endl;
			}
		}

		//电话
		string phone;
		cout << "请输入联系电话" << endl;
		
		while (true) {
			cin >> phone;
			if(phone.length() == 11){
				abs->personArray[abs->m_Size].m_Phone = phone;
				break;
			}
			else {
				cout << "手机号格式错误请重新输入" <<endl;
			}
		}

		//住址
		string address;
		cout << "请输入住址" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++; 

		cout << "添加成功！" << endl;

		system("pause"); 
		system("cls"); //清屏的功能
	}
}

void showPerson(Addressbooks* abs) {
	if (abs->m_Size == 0) {
		cout << "联系人为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex==1?"男":"女" )<< "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "地址：" << abs->personArray[i].m_Addr << endl;
		}
	
	}
	system("pause");
	system("cls"); //清屏的功能
}

//检测联系人是否存在的函数,如果存在返回联系人数组下标，不存在返回-1
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			//找到了返回数组下标
			return i;
		}
	}
	return -1; //如果没找到返回-1
}


//删除指定联系人
void deletePerson(Addressbooks* abs) {
	cout << "请输入删除联系人姓名" << endl;
	string name;
	cin >> name;
	//ret == -1 查无此人
	//ret ！=-1 找到此人
	int ret = isExist(abs, name);
	if (ret != -1) {
		//找到此人
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls"); //清屏的功能
}

//查找指定联系人
void findPerson(Addressbooks* abs) {
	string name;
	cout << "请输入要查找的联系人姓名" << endl;
	cin >> name;
	//判断指定联系人是否存在
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "地址：" << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls"); //清屏的功能
}

//修改指定联系人信息
void modifyPerson(Addressbooks* abs) {
	cout << "请输入想要修改的联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		//姓名
		cout << "请重新输入姓名" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		cout << "请重新输入性别" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 --女" << endl;
		int sex=0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else {
				cout << "请重新输入" << endl;
			}
		}

		//年龄
		cout << "请重新输入年龄" << endl;
		int age;
		while (true) {
			cin >> age;
			if (age > 0 || age <= 150) {
				abs->personArray[ret].m_Age = age;
				break;
			}
			else {
				cout << "年龄输入错误请重新输入" << endl;
			}
		}
		//电话
		cout << "请重新输入电话" << endl;
		string phone;
		while (true) {
			cin >> phone;
			if (phone.length() == 11) {
				abs->personArray[ret].m_Phone = phone;
				break;
			}
			else {
				cout << "手机号格式错误请重新输入" << endl;
			}
		}
		//地址
		cout << "请重新输入地址" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls"); //清屏的功能
}

//清空联系人
void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "联系人已清空" << endl;
	system("pause");
	system("cls"); //清屏的功能
}

int main() {
	int select = 0; //用户选择变量

	Addressbooks abs;
	abs.m_Size =0;
	while (true) {
		//菜单的调用
		showMean();

		cin >> select;
		switch (select) {

		case 1: //1.添加联系人
			addPerson(&abs);
			break;

		case 2: //2.显示联系人
			showPerson(&abs);
			break;

		case 3: //3.删除联系人
			deletePerson(&abs);
			break;

		case 4: //4.查找联系人
			findPerson(&abs);
			break;

		case 5: //5.修改联系人
			modifyPerson(&abs);
			break;

		case 6: //6.清空联系人
			cleanPerson(&abs);
			break;

		case 0: //0.退出通讯录
			cout << "欢迎下次使用" << endl;
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