#include "reader.h"

//Xuất ra màn hình thông tin của độc giả
//(vị trí của độc giả, mã độc giả, tên, CMND, ngày sinh, giới tính, email, địa chỉ, ngày lập thẻ, ngày hết hạn của thẻ)
void outputReader(int i, int id[], char name[][51], int cmnd[], char bday[][11], bool sex[], char email[][51], char add[][51], char since[][11], char end[][11])
{
		cout << "		Ma doc gia: " << id[i] << endl;
		cout << "		Ten doc gia: " << name[i] << endl;
		cout << "		CMND: " << cmnd[i] << endl;
		cout << "		Ngay thang nam sinh: " << bday[i] << endl;
		cout << "		Gioi tinh: ";
		if (sex[i])
			cout << "Nam";
		else cout << "Nu";
		cout << endl;
		cout << "		Email: " << email[i] << endl;
		cout << "		Dia chi: " << add[i] << endl;
		cout << "		Ngay lap the: " << since[i] << endl;
		cout << "		Ngay het han cua the: " << end[i] << endl;
		cout << endl;
}

//Nhập vào thông tin của độc giả mới
//(tổng số độc giả, mã độc giả, tên, CMND, ngày sinh, giới tính, email, địa chỉ, ngày lập thẻ, ngày hết hạn của thẻ)
void inputReader(int n, int id[], char name[][51], int cmnd[], char bday[][11], bool sex[], char email[][51], char add[][51], char since[][11], char end[][11])
{
	id[n] = n + 1;
	cout << "		Nhap ten doc gia: ";
	cin.ignore();
	gets_s(name[n]);
	
	cout << "		Nhap CMND: ";
	cin >> cmnd[n];
	
	cout << "		Nhap ngay thang nam sinh (dd-mm-yyyy): ";
	cin.ignore();
	gets_s(bday[n]);
	
	cout << "		Nhap gioi tinh (1: Nam, 0: Nu): ";
	cin >> sex[n];
	
	cout << "		Nhap email: ";
	cin.ignore();
	gets_s(email[n]);
	
	cout << "		Nhap dia chi: ";
	gets_s(add[n]);
	
	cout << "		Nhap ngay lap the (dd-mm-yyyy): ";
	gets_s(since[n]);
	
	cout << "		Nhap ngay het han cua the (dd-mm-yyyy): ";
	gets_s(end[n]);
}

//Hàm xuất ra menu các trường thông tin của độc giả có thể chỉnh sửa để người dùng lựa chọn, sau đó xuất ra thông tin độc giả đã chỉnh sửa
//(thông tin cần chỉnh sửa, vị trí của độc giả, mã độc giả, tên, CMND, ngày sinh, giới tính, email, địa chỉ, ngày lập thẻ, ngày hết hạn của thẻ)
void editInfo(int inf, int pos, int id[], char name[][51], int cmnd[], char bday[][11], bool sex[], char email[][51], char add[][51], char since[][11], char end[][11])
{
	switch (inf)
	{
	case 1:
		cout << "		Nhap ten doc gia: ";
		cin.ignore();
		gets_s(name[pos]);
		break;
	case 2:
		cout << "		Nhap so CMND: ";
		cin >> cmnd[pos];
		break;
	case 3:
		cout << "		Nhap ngay thang nam sinh: ";
		cin.ignore();
		gets_s(bday[pos]);
		break;
	case 4:
		cout << "		Nhap gioi tinh (1: Nam, 0: Nu): ";
		cin >> sex[pos];
		break;
	case 5:
		cout << "		Nhap email: ";
		cin.ignore();
		gets_s(email[pos]);
		break;
	case 6:
		cout << "		Nhap dia chi: ";
		cin.ignore();
		gets_s(add[pos]);
		break;
	case 7:
		cout << "		Nhap ngay lap the: ";
		cin.ignore();
		gets_s(since[pos]);
		break;
	case 8:
		cout << "		Nhap ngay het han cua the: ";
		cin.ignore();
		gets_s(end[pos]);
		break;
	}
}

//Hàm chỉnh sửa thông tin độc giả
//(vị trí của độc giả, mã độc giả, tên, CMND, ngày sinh, giới tính, email, địa chỉ, ngày lập thẻ, ngày hết hạn của thẻ)
void editReader(int pos, int id[], char name[][51], int cmnd[], char bday[][11], bool sex[], char email[][51], char add[][51], char since[][11], char end[][11])
{
	cout << "		1. Ho va ten" << endl;
	cout << "		2. CMND" << endl;
	cout << "		3. Ngay thang nam sinh" << endl;
	cout << "		4. Gioi tinh" << endl;
	cout << "		5. Email" << endl;
	cout << "		6. Dia chi" << endl;
	cout << "		7. Ngay lap the" << endl;
	cout << "		8. Ngay het han cua the" << endl;
	cout << "	Chon thong tin can chinh sua: ";
	int inf;
	cin >> inf;
	editInfo(inf, pos, id, name, cmnd, bday, sex, email, add, since, end);
	cout << "	Thong tin da duoc thay doi" << endl;
	outputReader(pos, id, name, cmnd, bday, sex, email, add, since, end);
}

//Xóa 1 trường thông tin của độc giả đã chọn (chỉ dùng để xóa các trường có định dạng char[][51])
//(mảng ký tự có định dạng [][51], vị trí trong mảng của trường cần xóa)
void deleteItemChar(char a[][51], int pos)
{
	for (int i = 0; i < 51; i++)
	{
		a[pos][i] = a[pos + 1][i];
		if (a[pos + 1][i] == '\0')
			break;
	}
}

//Hàm xóa 1 độc giả
//(vị trí của độc giả, tổng số độc giả, mã độc giả, tên, CMND, ngày sinh, giới tính, email, địa chỉ, ngày lập thẻ, ngày hết hạn của thẻ)
void deleteReader(int pos, int n, int id[], char name[][51], int cmnd[], char bday[][11], bool sex[], char email[][51], char add[][51], char since[][11], char end[][11])
{
	pos--;
	for (int j = pos; j < n; j++)
	{
		cmnd[j] = cmnd[j + 1];
		sex[j] = sex[j + 1];
		deleteItemChar(name, j);
		deleteItemChar(email, j);
		deleteItemChar(add, j);
		for (int i = 0; i < 11; i++)
		{
			bday[j][i] = bday[j + 1][i];
			since[j][i] = since[j + 1][i];
			end[j][i] = end[j + 1][i];
		}
	}
}

//Hàm tìm sách bằng số CMND (tổng số độc giả, số CMND của độc giả, số CMND do người dùng nhập)
// Nếu tìm thấy độc giả có CMND khớp với số người dùng nhập, hàm sẽ trả về vị trí của độc giả, nếu không có kết quả nào khớp thì trả về -1
int findReaderWithCMND(int n, int cmnd[], int x)
{
	for (int i = 0; i < n; i++)
		if (cmnd[i] == x)
			return i;
	return -1;
}

//Hàm chuyển các ký tự hoa trong mảng về ký tự thường (mảng chứa các ký tự cần chuyển)
void lowercaseName(char name[])
{
	for (int i = 0; i < 101; i++)
	{
		if (name[i] == '\0')
			break;
		if ((name[i] >= 'A') && (name[i] <= 'Z'))
			name[i] += 32;
	}
}

//Hàm tách và trả về tên của độc giả từ họ và tên 
//(họ và tên, tên riêng)
void firstName(char fullname[], char firstname[])
{
	int j = 0;
	for (int i = strlen(fullname); i > 0; i--)
	{
		firstname[j] = fullname[i - 1];
		if (fullname[i - 1] == ' ')
		{
			firstname[j] = '\0';
			break;
		}
		j++;
	}
}

//Hàm tìm độc giả bằng tên 
//Nếu tìm thấy kết quả khớp với tên người dùng nhập thì trả về vị trí của độc giả tìm được, nếu không có kết quả nào khớp thì trả về -1
//(Vị trí của độc giả được duyệt, họ và tên độc giả, tên người dùng nhập)
int findReaderWithFirstName(int i, char name[][51], char x[])
{
	char fullname[51], firstname[11];
	for (int j = 0; j < 51; j++)
	{
		fullname[j] = name[i][j];
		if (name[i][j] == '\0')
			break;
	}
	if (strlen(x) > strlen(fullname))
		return -1;
	int lth = strlen(x);
	for (int i = 0; i < lth; i++)
	{
		char firstname2[11];
		if (x[i] == ' ')
		{
			firstName(x, firstname2);
			lth = strlen(firstname2);
			for (int j = 0; j < lth; j++)
			{
				x[j] = firstname2[lth - j - 1];
			}
			x[lth] = '\0';
			break;
		}
	}
	firstName(fullname, firstname);
	lowercaseName(firstname);
	lowercaseName(x);
	if (strlen(firstname) != strlen(x))
		return -1;
	else
	{
		lth = strlen(firstname);
		int count = 0;

		for (int j = 0; j < lth; j++)
		{
			if (firstname[j] != x[lth - j - 1])
			{
				count++;
				break;
			}
		}
		if (count == 0)
			return i;
		else return -1;
	}
}


