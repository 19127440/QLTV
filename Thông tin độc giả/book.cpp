#include "book.h"


//Hàm xuất ra thông tin của sách
//(Vị trí của sách, mã ISBN, tên sách, tác giả, nhà xuất bản, năm xuất bản, thể loại, giá sách)
void outputBook(int i, char isbn[][18], char name[][101], char tg[][51], char nxb[][51], int year[], char type[][51], int price[])
{
	cout << "		Ma so: " << i + 1 << endl;
	cout << "		ISBN: " << isbn[i] << endl;
	cout << "		Ten sach: " << name[i] << endl;
	cout << "		Tac gia: " << tg[i] << endl;
	cout << "		Nha xuat ban: " << nxb[i] << endl;
	cout << "		Nam xuat ban: " << year[i] << endl;
	cout << "		The loai: " << type[i] << endl;
	cout << "		Gia sach: " << price[i] << endl;
	cout << endl;
}

//Hàm nhập vào thông tin của sách mới
//(Tổng số sách, mã ISBN, tên sách, tác giả, nhà xuất bản, năm xuất bản, thể loại, giá sách)
void inputBook(int n, char isbn[][18], char name[][101], char tg[][51], char nxb[][51], int year[], char type[][51], int price[])
{
	cout << "		Nhap ISBN: ";
	cin.ignore();
	cin >> isbn[n];

	cout << "		Nhap ten sach: ";
	cin.ignore();
	gets_s(name[n]);

	cout << "		Nhap ten tac gia: ";
	gets_s(tg[n]);

	cout << "		Nhap ten nha xuat ban: ";
	gets_s(nxb[n]);

	cout << "		Nhap nam xuat ban: ";
	cin >> year[n];

	cout << "		Nhap the loai: ";
	cin.ignore();
	gets_s(type[n]);

	cout << "		Nhap gia sach: ";
	cin >> price[n];
}

//Hàm chỉnh sửa từng trường thông tin của sách 
//(thông tin cần chỉnh sửa, vị trí của sách cần chỉnh sửa, mã ISBN, tên sách, tác giả, nhà xuất bản, năm xuất bản, thể loại, giá sách)
void editInfo(int inf, int pos, char isbn[][18], char name[][101], char tg[][51], char nxb[][51], int year[], char type[][51], int price[])
{
	switch (inf)
	{
	case 1:
	{
		cout << "		Nhap ISBN: ";
		cin.ignore();
		cin >> isbn[pos];
	}
	break;
	case 2:
	{
		cout << "		Nhap ten sach: ";
		cin.ignore();
		gets_s(name[pos]);
	}
	break;
	case 3:
	{
		cout << "		Nhap ten tac gia: ";
		cin.ignore();
		gets_s(tg[pos]);
	}
	break;
	case 4:
	{
		cout << "		Nhap ten nha xuat ban: ";
		cin.ignore();
		gets_s(nxb[pos]);
	}
	break;
	case 5:
	{
		cout << "		Nhap nam xuat ban: ";
		cin >> year[pos];
	}
	break;
	case 6:
	{
		cout << "		Nhap the loai: ";
		cin.ignore();
		gets_s(type[pos]);
	}
	break;
	case 7:
	{
		cout << "		Nhap gia sach: ";
		cin >> price[pos];
	}
		break;
	}
}

//Hàm xuất ra menu các trường thông tin của sách có thể chỉnh sửa để người dùng lựa chọn sau đó xuất ra thông tin sách đã chỉnh sửa
//(vị trí của sách cần chỉnh sửa, mã ISBN, tên sách, tác giả, nhà xuất bản, năm xuất bản, thể loại, giá sách)
void editBook(int pos, char isbn[][18], char name[][101], char tg[][51], char nxb[][51], int year[], char type[][51], int price[])
{
	cout << "	1. ISBN" << endl;
	cout << "	2. Ten sach" << endl;
	cout << "	3. Tac gia" << endl;
	cout << "	4. Nha xuat ban" << endl;
	cout << "	5. Nam xuat ban" << endl;
	cout << "	6. The loai" << endl;
	cout << "	7. Gia sach" << endl;
	cout << "Chon thong tin can chinh sua: ";
	int inf;
	cin >> inf;
	editInfo(inf, pos, isbn, name, tg, nxb, year, type, price);
	cout << "Thong tin da duoc thay doi" << endl;
	outputBook(pos, isbn, name, tg, nxb, year, type, price);
}

//Xóa 1 trường thông tin của sách đã chọn (chỉ dùng để xóa các trường có định dạng char[][101])
//(mảng ký tự có định dạng [][101], vị trí trong mảng của trường cần xóa)
void deleteItemChar1(char a[][101], int pos)
{
	for (int i = 0; i < 101; i++)
	{
		a[pos][i] = a[pos + 1][i];
		if (a[pos + 1][i] == '\0')
			break;
	}
}

//Hàm xóa thông tin 1 quyển sách 
//(Vị trí của sách cần xóa, tổng số sách, mã ISBN, tên sách, tác giả, nhà xuất bản, năm xuất bản, thể loại, giá sách)
void deleteBook(int pos, int n, char isbn[][18], char name[][101], char tg[][51], char nxb[][51], int year[], char type[][51], int price[])
{
	pos--;
	for (int j = pos; j < n; j++)
	{
		year[j] = year[j + 1];//Xóa năm xuất bản
		price[j] = price[j + 1];//Xóa giá sách
		deleteItemChar(tg, j);//Xóa tác giả
		deleteItemChar(nxb, j);//Xóa nhà xuất bản
		deleteItemChar1(name, j);//Xóa tên sách
		deleteItemChar(type, j);//Xóa thể loại
		for (int i = j; i < 18; i++)
			isbn[pos][i] = isbn[pos + 1][i];//Xóa mã ISBN
	}
}

//Hàm tìm sách bằng mã ISBN (tổng số sách, mã ISBN của sách, mã ISBN do người dùng nhập)
// Nếu tìm thấy sách có mã ISBN khớp với mã người dùng nhập, hàm sẽ trả về vị trí của sách, nếu không có kết quả nào khớp thì trả về -1
int findBookWithISBN(int n, char isbn[][18], char x[])
{
	int check;
	for (int i = 0; i < n; i++)
	{
		check = 0;
		for (int j = 0; j < 18; j++)
			if (isbn[i][j] != x[j])
			{
				check++;
				break;
			}
		if (check == 0)
		{
			return i;
		}
	}
	return -1;
}

//Hàm kiểm tra xem tên sách có khớp với tên người dùng nhập hay không
//Nếu tìm thấy sách có tên khớp với tên người dùng nhập, hàm sẽ trả về vị trí của sách, nếu không có kết quả nào khớp thì trả về -1
//(vị trí của sách được duyệt, tên sách, tên người dùng nhập)
int checkBookName(int i, char name[][101], char x[])
{
	char bookname[101];
	for (int j = 0; j < 51; j++)
	{
		bookname[j] = name[i][j];
		if (name[i][j] == '\0')
			break;
	}
	if (strlen(x) > strlen(bookname))
		return -1;
	else
	{
		lowercaseName(bookname);
		lowercaseName(x);
		int count = 0;
		int lth = strlen(x);
		for (int j = 0; j < lth; j++)
		{
			if (bookname[j] != x[j])
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

//Hàm tìm kiếm vị trí của các sách thông qua mã ISBN do người dùng nhập sau đó lưu vào mảng chứa các vị trí của sách
//(số lượng sách trong thư viện, số lượng sách người dùng mượn, vị trí của sách, mã ISBN của sách)
void listOfBorrowedBook(int nb, int n[], int i, int isbn[][10], char ISBN[][18])
{
	char id[18];
	for (int j = 0; j < n[i]; j++)
	{
		cout << "		Nhap ISBN: ";
		cin.ignore();
		cin >> id;
		isbn[i][j] = findBookWithISBN(nb, ISBN, id);
		cout << endl;
	}
}

//Tạo phiếu mượn sách 
//(số lượng sách trong thư viện, số sách người dùng mượn, mã của người dùng, ngày mượn, ngày trả dự kiến, vị trí các sách mượn, mã ISBN của sách)
void borrowCard(int nb, int n[], int i, int id[], char borrow[][11], char expect[][11], int isbn[][10], char ISBN[][18])
{
	cout << "	Nhap ma doc gia: ";
	cin >> id[i];
	cout << "	Nhap ngay muon: ";
	cin.ignore();
	gets_s(borrow[i]);
	cout << "	Nhap ngay tra du kien: ";
	gets_s(expect[i]);
	cout << "	Nhap so luong sach can muon: ";
	cin >> n[i];
	listOfBorrowedBook(nb, n, i, isbn, ISBN);
}

//Xuất ra màn hình phiếu mượn sao khi tạo 
//(số sách người dùng mượn, vị trí của phiếu, mã của người dùng, ngày mượn, ngày trả dự kiến, vị trí các sách mượn, mã ISBN của sách)
void outputBorrowCard(int n[], int i, int id[], char borrow[][11], char expect[][11], int isbn[][10], char ISBN[][18])
{
	cout << "	Ma doc gia: " << id[i] << endl;
	cout << "	Ngay muon: " << borrow[i] << endl;
	cout << "	Ngay tra du kien: " << expect[i] << endl;
	cout << "	Danh sach ISBN: " << endl;
	for (int j = 0; j < n[i]; j++)
	{
		cout << "		" << ISBN[isbn[i][j]] << endl;
	}
}

//Tạo phiếu trả sách
//(vị trí của phiếu, số sách người dùng mượn, mã của người dùng, ngày mượn, ngày trả dự kiến, ngày trả thực tế, vị trí các sách mượn, mã ISBN của sách)
void returnCard(int pm, int n[], int id[], char borrow[][11], char expect[][11], char reality[][11], int isbn[][10], char ISBN[][18])
{
	int a;
	cout << "	Nhap ma doc gia: ";
	cin >> a;
	for (int i = 0; i < pm; i++)
		if (a == id[i])
			outputBorrowCard(n, a, id, borrow, expect, isbn, ISBN);
	cout << "	Nhap ngay tra thuc te: ";
	cin.ignore();
	gets_s(reality[a]);
}
