#include "statistic.h"

//Thống kê sách theo thể loại sau đó trả về số lượng sách theo từng thể loại
//(Số sách trong thư viện, thể loại của sách)
void bookStatisticByCategory(int n, char type[][51])
{
	int vn = 0, fr = 0;
	for (int i = 0; i < n; i++)
	{
		char type1[51];
		int lth = 0;
		for (int j = 0; j < 20; j++)
		{
			type1[j] = type[i][j];
			if (type[i][j] == '\0')
			{
				lth = j;
				break;
			}
		}
		if (lth == 16)
			vn++;
		if (lth == 18)
			fr++;
	}
	cout << "		Van hoc Viet Nam: " << vn << " quyen" << endl;
	cout << "		Van hoc nuoc ngoai: " << fr << " quyen" << endl;
}

//Thống kê số độc giả theo từng giới tính 
//(Số độc giả trong thư viện, giới tính từng người)
void readerStatisticBySex(int n, bool sex[])
{
	int f = 0, m = 0;
	for (int i = 0; i < n; i++)
	{
		if (sex[i])
			m++;
		else f++;
	}
	cout << "		So luong doc gia nam: " << m << endl;
	cout << "		So luong doc gia nu: " << f << endl;
}
