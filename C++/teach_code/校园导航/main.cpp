#include"mg.cpp"
#include<string>
#include<stdlib.h>
#include <iostream>
using namespace std;

	
void map()
{
	cout << "\t\t\t��-----------------------------���չ�ҵ��ѧУ԰ƽ��ͼ--------------------------   ��\n";
	cout << "\t\t\t��                                                                                ��\n";
	cout << "\t\t\t��                          10�w0------------------�w8--------------------�w7     ��\n";
	cout << "\t\t\t��                            ��                    ��                    ��      ��\n";
	cout << "\t\t\t��                            ��                    ��                    ��      ��\n";
	cout << "\t\t\t��                      ��    ��                    ��                    ��  ��  ��\n";
	cout << "\t\t\t��        ѧУ������    ��    ��                                          ��  ��  ��\n";
	cout << "\t\t\t��                      ��    ��                  ��������                ��  ¥  ��\n";
	cout << "\t\t\t��                      ��    ��                                          ��      ��\n";
	cout << "\t\t\t��                      Ԣ    ��                    ��                    ����������\n";
	cout << "\t\t\t���������ﾶ����            �������������������������������� �� ����    ������������\n";
	cout << "\t\t\t������������������������������������������������������������ �� ����    ������������\n";
	cout << "\t\t\t������������������������������������                ��       ¥    ������ ��      ��\n";
	cout << "\t\t\t����            ������������������    AB����      ������    A ��        ��      ��\n";
	cout << "\t\t\t��    ��ѧD¥                 ��                    ��������    ��        ��  ұ  ��\n";
	cout << "\t\t\t����            ������������11�w------------------�w9 ------------------26�w  ��  ��\n";
	cout << "\t\t\t��      12�w--------------------                                          ��  ¥  ��\n";
	cout << "\t\t\t��        ��                  ��                ��ͼ���                ��      ��\n";
	cout << "\t\t\t��        ��                  ��                                          ��      ��\n";
	cout << "\t\t\t��        ��                  ��                                          ��      ��\n";
	cout << "\t\t\t��        ��                  ��                                          ��      ��\n";
	cout << "\t\t\t��        ��                  ��                                          ��      ��\n";
	cout << "\t\t\t��        ��                  ��                                          ��  ��  ��\n";
	cout << "\t\t\t��    ��  ��            ��  14�w                                         5�w  ��  ��\n";
	cout << "\t\t\t��    ��  �w13          е    ��              ����¥B                     ��  ��  ��\n";
	cout << "\t\t\t��    ¥  ��            ¥    ��                                          ��  ��  ��\n";
	cout << "\t\t\t��        ��                  ��                                          ��  ��  ��\n";
	cout << "\t\t\t��        ��                  ��                                          ��      ��\n";
	cout << "\t\t\t��        ��                  ��                                          ��      ��\n";
	cout << "\t\t\t��        ��                  ��                                          ��      ��\n";
	cout << "\t\t\t��        ��                  ��                                          ��      ��\n";
	cout << "\t\t\t�����Ļ�԰��             ��   ��                ��  ��  ��                ��  ��  ��\n";
	cout << "\t\t\t��        ��             ��   �w16                                      13�w  ��  ��\n";
	cout << "\t\t\t��        ��             ¥   ��------------------12�w----------------------  ¥  ��\n";
	cout << "\t\t\t��      15�w                                                                      ��\n";
	cout << "\t\t\t��                              ---------------- ѧУ���� ------------------�w8   ��\n";
	cout << "\t\t\t��      �ݷ�¥                                                                    ��\n";
	cout << "\t\t\t��                                                                        �׽�    ��\n";
	cout << "\t\t\t��-----------------------------------------------------------------------------   ��\n";
	cout << endl;

}/*map*/

	string a[7]={"ѧУ������","�������","��ͼ���","�׽�", "����¥","ұ��¥","L2��"};
    mg<string> a1(a,7,10);
void menu()
{
	int n, x, y, len,z,c,v;
	int a;string b;
	system("cls");
	
	cout << "\n\n\n";
	cout << " ����������������������������������������������������\n";
	cout << " ��                                                ��\n";
	cout << " ���� ӭ ʹ �� �� �� �� ҵ �� ѧ У ԰ �� �� ϵ ͳ ��\n";
	cout << " ��                                                ��\n";
	cout << " ����������������������������������������������������\n";
	cout << "\n\n\n";
	cout << "   1����ѯУ԰���еص㣻      2����ѯ�ص����ƽ��ͼ��" << endl;
	cout << "   3����ѯ�������ص��ľ��룻4���޸����ص���룻" << endl;
	cout << "   5����ѯ���ص�����·��;   6��������ص㿪ʼ����" << endl;
	cout << "   7���޸ĵص�����;           8���˳�У԰����ϵͳ; " << endl;
	cout << "\n\n\n";
	cout << "��������Ҫָ����ţ�";
	cin >> n;
	switch (n) {
	case 1:
		a1.putoutvertex();
		cout << "\n\n���س�������������ϵͳ����\n\n";
		getchar(); getchar();
		menu();
		break;
	case 2:
		map();
		cout << "\n\n���س�������������ϵͳ����\n\n";
		getchar(); getchar();
		menu();
		break;
	case 3:
		a1.putoutarc();
		cout << "\n\n���س�������������ϵͳ����\n\n";
		getchar(); getchar();
		menu();
		break;
	case 4:
		a1.putoutvertex();
		cout<<endl;
		cout << "���������ص�Ĵ��ż��޸�ֵ��";
		cin >> x >> y >> len;
		a1.setarc(x, y, len);
		a1.putoutarc();
		cout << "\n\n���س�������������ϵͳ����\n\n";
		getchar(); getchar();
		menu();
		break;

	case 5:
		a1.putoutvertex();
		cout<<endl;
		cout<<"���������ص�Ĵ��ţ�"; 
		cin>>c>>v;
		a1.Floyd(c,v);
		cout << "\n\n���س�������������ϵͳ����\n\n";
		getchar(); getchar();
		menu();
		break;
	case 6:
			a1.putoutvertex();
		cout<<endl;
		cout<<"������������Ĵ��ţ�"<<endl;
		cin>>z;
	a1.DFSTravese(z-1);
	a1.setzero();
		cout << "\n\n���س�������������ϵͳ����\n\n";
		getchar(); getchar();
		menu();
		break;
    case 7:
	 		a1.putoutvertex();
	 		cout<<endl;
	 	cout<<"�޸ĵڼ������㣺"<<endl;
		 cin>>a;
		  cout<<"�޸�Ϊ��"<<endl;
		  cin>>b; 
	 a1.setvertex(a,b);
	 cout << "�޸ĳɹ���" << endl;	
	 	cout << "\n\n���س�������������ϵͳ����\n\n";
		getchar(); getchar();
		menu();
		break;
	case 8:
	 	cout<<"��ӭ�´�ʹ��!";
	 	return ;
  	}
	
}

int main()
{

	menu();
	return 0;
}
