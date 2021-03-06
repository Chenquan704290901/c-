#include"Commodity类.h"
#include<iomanip>

//定义预测需求的成员函数 
void Commodity_p::forecast_demand()
{
	system("color F4");
	system("cls");
	Commodity* t = first;
	Commodity* p = first;
	while (p->next)
	{
		t = first;
		while (t->next)
		{
			if (t->next->search_volume+ 2*t->next->shopping >
				t->search_volume+t->shopping)
			{
				t->swap();
			}
			t = t->next;
		}
		p = p->next;
	}
	cout << "\n\t\t\t\t\t\t\t  <<<------预测需求榜------>>>" << endl;
	cout << "\t\t\t\t\t\t\t  ============================" << endl;
	cout << "\t\t\t\t\t\t\t  序号  " << "       名称" << "  预测需求量 " << endl;
	cout << "\t\t\t\t\t\t\t  ============================" << endl;
	t = first;
	int i = 1;
	while (t)
	{
		if(int(t->search_volume * 0.3 + t->shopping * 0.6) >0)
		{
			cout << setiosflags(ios::fixed) << resetiosflags(ios::left) << setprecision(1);
			cout <<"\t\t\t\t\t\t\t  " << setw(3) << i << "  " << setw(15) << t->product_name << "      "
				<< int(t->search_volume * 0.3 + t->shopping * 0.6) << endl;
			cout << "\t\t\t\t\t\t\t  ---------------------------" << endl;
		}
		

		if (t->next == NULL)
		{
			int h;
			while (1)
			{
				cout << "\t\t\t\t\t\t\t   ********操作菜单********" << endl;
				cout << "\t\t\t\t\t\t\t   *                      *" << endl;
				cout << "\t\t\t\t\t\t\t   *   1--返回主菜单      *" << endl;
				cout << "\t\t\t\t\t\t\t   *   2--退出系统.  按   *\n";
				cout << "\t\t\t\t\t\t\t   *                      *" << endl;
				cout << "\t\t\t\t\t\t\t   ************************" << endl;
				cout << "\t\t\t\t\t\t\t     "; cin >> h;
				if (h == 1 || h == 2) break;
				else cout << "\t\t\t\t\t\t\t  操作错误！重新操作" << endl;
			}
			if (h == 1) break;
			else exit(1);
		}
		t = t->next;
		i++;
	}
}