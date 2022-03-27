#include "reader.h"
#include "book.h"
#include "statistic.h"

int main()
{
	int nDG = 3;//Số lượng độc giả
	int DG_MaDocGia[1000]; // Số thứ tự của độc giả
	char DG_HoTen[1000][51]; // Họ và tên tối đa 50 ký tự
	int DG_CMND[1000];
	char DG_NgaySinh[1000][11]; // Tối đa 10 ký tự, dạng dd-mm-yyyy
	bool DG_GioiTinh[1000]; //Nữ là 0, Nam là 1
	char DG_Email[1000][51]; // Địa chỉ email tối đa 50 ký tự
	char DG_DiaChi[1000][51]; // Địa chỉ nơi sinh sống tối đa 50 ký tự
	char DG_NgayLapThe[1000][11]; // Tối đa 10 ký tự, dạng dd-mm-yyyy
	char DG_NgayHetHan[1000][11]; // Tối đa 10 ký tự, dạng dd-mm-yyyy

	DG_MaDocGia[0] = 1;
	strcpy_s(DG_HoTen[0], "Le Nghi");
	DG_CMND[0] = 203845619;
	strcpy_s(DG_NgaySinh[0], "02-02-2001");
	DG_GioiTinh[0] = 0;
	strcpy_s(DG_Email[0], "nghi@gmail.com");
	strcpy_s(DG_DiaChi[0], "Phuong 4, Quan 5");
	strcpy_s(DG_NgayLapThe[0], "03-04-2019");
	strcpy_s(DG_NgayHetHan[0], "03-04-2023");

	DG_MaDocGia[1] = 2;
	strcpy_s(DG_HoTen[1], "Tran Khanh");
	DG_CMND[1] = 203355623;
	strcpy_s(DG_NgaySinh[1], "02-12-2001");
	DG_GioiTinh[1] = 1;
	strcpy_s(DG_Email[1], "khanh@gmail.com");
	strcpy_s(DG_DiaChi[1], "Phuong 10, Quan 11");
	strcpy_s(DG_NgayLapThe[1], "10-05-2019");
	strcpy_s(DG_NgayHetHan[1], "10-05-2023");

	DG_MaDocGia[2] = 3;
	strcpy_s(DG_HoTen[2], "Truong Thi Hoa");
	DG_CMND[2] = 203398531;
	strcpy_s(DG_NgaySinh[2], "23-07-1998");
	DG_GioiTinh[2] = 1;
	strcpy_s(DG_Email[2], "hoa@gmail.com");
	strcpy_s(DG_DiaChi[2], "Phuong 6, Quan 3");
	strcpy_s(DG_NgayLapThe[2], "17-10-2020");
	strcpy_s(DG_NgayHetHan[2], "17-10-2024");
	
	int S_SoLuong = 5;//Số lượng sách trong thư viện, tối đa 2000 quyển
	char S_ISBN[2000][18];//Mã ISBN của sách, tối đa 17 ký tự
	char S_TenSach[2000][101];// Tên sách, tối đa 100 ký tự
	char S_TacGia[2000][51];// Tên tác giả, tối đa 50 ký tự
	char S_NXB[2000][51];//Tên nhà xuất bản, tối đa 50 ký tự
	int S_NamXB[2000];//Năm xuất bản sách
	char S_TheLoai[2000][51];//Thể loại của sách, gồm Văn học Việt Nam và Văn học nước ngoài
	int S_GiaSach[2000];//Giá của sách

	strcpy_s(S_ISBN[0], "978-604-1-00475-7");
	strcpy_s(S_TenSach[0], "Cho toi xin mot ve di tuoi tho");
	strcpy_s(S_TacGia[0], "Nguyen Nhat Anh");
	strcpy_s(S_NXB[0], "NXB Tre");
	S_NamXB[0] = 2016;
	strcpy_s(S_TheLoai[0], "Van hoc Viet Nam");
	S_GiaSach[0] = 80000;

	strcpy_s(S_ISBN[1], "978-604-2-03660-3");
	strcpy_s(S_TenSach[1], "De Men phieu luu ky");
	strcpy_s(S_TacGia[1], "To Hoai");
	strcpy_s(S_NXB[1], "NXB Kim Dong");
	S_NamXB[1] = 2016;
	strcpy_s(S_TheLoai[1], "Van hoc Viet Nam");
	S_GiaSach[1] = 150000;

	strcpy_s(S_ISBN[2], "978-604-69-8344-6");
	strcpy_s(S_TenSach[2], "Nhat ky trong tu");
	strcpy_s(S_TacGia[2], "Ho Chi Minh");
	strcpy_s(S_NXB[2], "NXB Van hoc");
	S_NamXB[2] = 2016;
	strcpy_s(S_TheLoai[2], "Van hoc Viet Nam");
	S_GiaSach[2] = 68000;

	strcpy_s(S_ISBN[3], "978-604-69-8279-1");
	strcpy_s(S_TenSach[3], "Khong gia dinh");
	strcpy_s(S_TacGia[3], "Hector Malot");
	strcpy_s(S_NXB[3], "NXB Van hoc");
	S_NamXB[3] = 2017;
	strcpy_s(S_TheLoai[3], "Van hoc nuoc ngoai");
	S_GiaSach[3] = 119000;

	strcpy_s(S_ISBN[4], "978-604-58-7102-7");
	strcpy_s(S_TenSach[4], "Dac nhan tam");
	strcpy_s(S_TacGia[4], "Dale Carnegie");
	strcpy_s(S_NXB[4], "NXB Tong Hop TPHCM");
	S_NamXB[4] = 2018;
	strcpy_s(S_TheLoai[4], "Van hoc nuoc ngoai");
	S_GiaSach[4] = 76000;

	int PM = 0;//Số lượng phiếu mượn, tối đa 1000 phiếu
	int PM_MaDocGia[1000];//Mã độc giả
	char PM_NgayMuon[1000][11];//Tối đa 10 ký tự, dạng dd-mm-yyyy
	char PM_NgayTraDuKien[1000][11];//Tối đa 10 ký tự, dạng dd-mm-yyyy
	char PM_NgayTraThucTe[1000][11];//Tối đa 10 ký tự, dạng dd-mm-yyyy
	int PM_SoLuongSach[1000];//Số lượng sách người dùng mượn
	int PM_ISBN[1000][10];//Vị trí của sách được mượn, tối đa 10 cuốn

	cout << "Chuong trinh quan ly thu vien" << endl;
	while (true)
	{
		cout << "1.Quan ly doc gia" << endl;
		cout << "2.Quan ly sach" << endl;
		cout << "3.Lap phieu muon sach" << endl;
		cout << "4.Lap phieu tra sach" << endl;
		cout << "5.Cac thong ke co ban" << endl;
		cout << "0.Ket thuc chuong trinh" << endl;
		cout << "Chon chuc nang: ";

		int choice, choice1, choice2, choice5;
		cin >> choice;

		switch (choice)
		{
			case 1:
			{
				cout << "Chuc nang quan li doc gia" << endl;
				do
				{
					cout << "	1.Xem danh sach doc gia" << endl;
					cout << "	2.Them doc gia" << endl;
					cout << "	3.Chinh sua thong tin mot doc gia" << endl;
					cout << "	4.Xoa thong tin mot doc gia" << endl;
					cout << "	5.Tim kiem doc gia theo CMND" << endl;
					cout << "	6.Tim kiem doc gia theo ten" << endl;
					cout << "	0.Quay lai" << endl;
					cout << "	Chon chuc nang: ";

					cin >> choice1;
					switch (choice1)
					{
					case 1:
					{
						cout << "	Chuc nang xem danh sach doc gia" << endl;
						for (int i = 0; i < nDG; i++)
						{
							outputReader(i, DG_MaDocGia, DG_HoTen, DG_CMND, DG_NgaySinh, DG_GioiTinh, DG_Email, DG_DiaChi, DG_NgayLapThe, DG_NgayHetHan);
						}
					}
					break;
					case 2:
					{
						cout << "	Chuc nang them doc gia" << endl;
						inputReader(nDG, DG_MaDocGia, DG_HoTen, DG_CMND, DG_NgaySinh, DG_GioiTinh, DG_Email, DG_DiaChi, DG_NgayLapThe, DG_NgayHetHan);
						cout << "	Them thanh cong:" << endl;
						outputReader(nDG, DG_MaDocGia, DG_HoTen, DG_CMND, DG_NgaySinh, DG_GioiTinh, DG_Email, DG_DiaChi, DG_NgayLapThe, DG_NgayHetHan);
						nDG++;
					}
					break;
					case 3:
					{
						cout << "	Chuc nang chinh sua thong tin mot doc gia" << endl;
						cout << "		Nhap ma so cua doc gia can chinh sua: ";
						int pos;
						cin >> pos;
						if (pos > nDG && pos < 0)
							cout << "	Khong tim thay doc gia nay" << endl;
						else
						{
							cout << "	Xac nhan chinh sua thong tin doc gia nay ?" << endl;
							outputReader(pos - 1, DG_MaDocGia, DG_HoTen, DG_CMND, DG_NgaySinh, DG_GioiTinh, DG_Email, DG_DiaChi, DG_NgayLapThe, DG_NgayHetHan);
							cout << "	1: Yes, 0: No ";
							bool check;
							cin >> check;
							if (check)
								editReader(pos - 1, DG_MaDocGia, DG_HoTen, DG_CMND, DG_NgaySinh, DG_GioiTinh, DG_Email, DG_DiaChi, DG_NgayLapThe, DG_NgayHetHan);
						}
					}
					break;
					case 4:
					{
						cout << "	Chuc nang xoa thong tin mot doc gia" << endl;
						cout << "		Nhap ma so cua doc gia can xoa: ";
						int pos;
						cin >> pos;
						if (pos > nDG && pos < 1)
							cout << "	Khong tim thay doc gia nay" << endl;
						else
						{
							cout << "	Xac nhan xoa thong tin doc gia nay ?" << endl;
							outputReader(pos - 1, DG_MaDocGia, DG_HoTen, DG_CMND, DG_NgaySinh, DG_GioiTinh, DG_Email, DG_DiaChi, DG_NgayLapThe, DG_NgayHetHan);
							cout << "	1: Yes, 0: No ";
							bool check;
							cin >> check;
							if (check)
							{
								if (pos < nDG)
									deleteReader(pos, nDG, DG_MaDocGia, DG_HoTen, DG_CMND, DG_NgaySinh, DG_GioiTinh, DG_Email, DG_DiaChi, DG_NgayLapThe, DG_NgayHetHan);
								nDG--;
								cout << "	Xoa thanh cong" << endl;
							}
						}
					}
					cout << endl;
					break;
					case 5:
					{
						cout << "	Chuc nang tim kiem doc gia theo CMND" << endl;
						cout << "		Nhap CMND: ";
						int x;
						cin >> x;
						if (findReaderWithCMND(nDG, DG_CMND, x) == -1)
							cout << "		Khong tim thay doc gia" << endl;
						else
						{
							x = findReaderWithCMND(nDG, DG_CMND, x);
							cout << "			Doc gia can tim:" << endl;
							outputReader(x, DG_MaDocGia, DG_HoTen, DG_CMND, DG_NgaySinh, DG_GioiTinh, DG_Email, DG_DiaChi, DG_NgayLapThe, DG_NgayHetHan);
						}
					}
					break;
					case 6:
					{
						cout << "	Chuc nang tim kiem doc gia theo ten" << endl;
						cout << "		Nhap ten: ";
						char name[51];
						cin.ignore();
						gets_s(name);
						int x;
						int count = 0;
						for (int i = 0; i < nDG; i++)
						{
							x = findReaderWithFirstName(i, DG_HoTen, name);
							if (x != -1)
							{
								outputReader(x, DG_MaDocGia, DG_HoTen, DG_CMND, DG_NgaySinh, DG_GioiTinh, DG_Email, DG_DiaChi, DG_NgayLapThe, DG_NgayHetHan);
								count++;
							}
						}
						if (count == 0)
						{
							cout << "		Khong tim thay doc gia nay" << endl;
						}
					}
					break;
					default:
					{
						if (choice1 != 0)
							cout << "Khong co chuc nang nay" << endl;
					}
					break;
					}
				} while (choice1 != 0);
			}
				break;
			case 2:
			{
				cout << "Chuc nang quan li sach" << endl;
				do
				{
					cout << "	1.Xem danh sach cac sach" << endl;
					cout << "	2.Them sach" << endl;
					cout << "	3.Chinh sua thong tin mot quyen sach" << endl;
					cout << "	4.Xoa thong tin sach" << endl;
					cout << "	5.Tim kiem sach theo ISBN" << endl;
					cout << "	6.Tim kiem sach theo ten sach" << endl;
					cout << "	0.Quay lai" << endl;
					cout << "	Chon chuc nang: ";

					cin >> choice2;
					switch (choice2)
					{
					case 1:
					{
						cout << "	Chuc nang xem danh sach cac sach" << endl;
						cout << "Danh sach gom " << S_SoLuong << " sach" << endl;
						for (int i = 0; i < S_SoLuong; i++)
						{
							outputBook(i, S_ISBN, S_TenSach, S_TacGia, S_NXB, S_NamXB, S_TheLoai, S_GiaSach);
						}
					}
					break;
					case 2:
					{
						cout << "	Chuc nang them sach" << endl;
						inputBook(S_SoLuong, S_ISBN, S_TenSach, S_TacGia, S_NXB, S_NamXB, S_TheLoai, S_GiaSach);
						cout << "	Them thanh cong:" << endl;
						outputBook(S_SoLuong, S_ISBN, S_TenSach, S_TacGia, S_NXB, S_NamXB, S_TheLoai, S_GiaSach);
						S_SoLuong++;
					}
					break;
					case 3:
					{
						cout << "	Chuc nang chinh sua thong tin sach" << endl;
						cout << "		Nhap vi tri cua sach can chinh sua: ";
						int pos;
						cin >> pos;
						if (pos > S_SoLuong && pos < 0)
							cout << "Khong tim thay sach" << endl;
						else
						{
							cout << "Xac nhan chinh sua thong tin sach ?" << endl;
							outputBook(pos - 1, S_ISBN, S_TenSach, S_TacGia, S_NXB, S_NamXB, S_TheLoai, S_GiaSach);
							cout << "1: Yes, 0: No ";
							bool check;
							cin >> check;
							if (check)
								editBook(pos - 1, S_ISBN, S_TenSach, S_TacGia, S_NXB, S_NamXB, S_TheLoai, S_GiaSach);
						}
					}
					break;
					case 4:
					{
						cout << "	Chuc nang xoa thong tin sach" << endl;
						cout << "		Nhap ma so cua sach can xoa: ";
						int pos;
						cin >> pos;
						if (pos > S_SoLuong && pos < 1)
							cout << "Khong tim thay sach" << endl;
						else
						{
							cout << "Xac nhan xoa thong tin sach ?" << endl;
							outputBook(pos - 1, S_ISBN, S_TenSach, S_TacGia, S_NXB, S_NamXB, S_TheLoai, S_GiaSach);
							cout << "1: Yes, 0: No ";
							bool check;
							cin >> check;
							if (check)
							{
								if (pos < S_SoLuong)
									deleteBook(pos, S_SoLuong, S_ISBN, S_TenSach, S_TacGia, S_NXB, S_NamXB, S_TheLoai, S_GiaSach);
								S_SoLuong--;
								cout << "Xoa thanh cong" << endl;
							}
						}
					}
					break;
					case 5:
					{
						cout << "	Chuc nang tim kiem sach theo ma ISBN" << endl;
						cout << "		Nhap ma ISBN cua sach can tim: ";
						char isbn[18];
						cin >> isbn;
						int pos = findBookWithISBN(S_SoLuong, S_ISBN, isbn);
						if (pos == -1)
							cout << "		Khong tim thay sach" << endl;
						else
							outputBook(pos, S_ISBN, S_TenSach, S_TacGia, S_NXB, S_NamXB, S_TheLoai, S_GiaSach);
					}
					break;
					case 6:
					{
						cout << "	Chuc nang tim kiem sach theo ten sach" << endl;
						cout << "		Nhap ten: ";
						char name[101];
						cin.ignore();
						gets_s(name);
						int x;
						int count = 0;
						for (int i = 0; i < S_SoLuong; i++)
						{
							x = checkBookName(i, S_TenSach, name);
							if (x != -1)
							{
								outputBook(x, S_ISBN, S_TenSach, S_TacGia, S_NXB, S_NamXB, S_TheLoai, S_GiaSach); 
								count++;
							}
						}
						if (count == 0)
						{
							cout << "		Khong tim thay sach" << endl;
						}
					}
					default:
					{
						if (choice2 != 0)
							cout << "	Khong co chuc nang nay" << endl;
					}
					break;
					}
				} while (choice2 != 0);
			}
				break;
			case 3:
			{
				cout << "Chuc nang lap phieu muon sach" << endl;
				borrowCard(S_SoLuong, PM_SoLuongSach, PM, PM_MaDocGia, PM_NgayMuon, PM_NgayTraDuKien, PM_ISBN, S_ISBN);
				cout << "	Tao phieu muon thanh cong" << endl;
				outputBorrowCard(PM_SoLuongSach, PM, PM_MaDocGia, PM_NgayMuon, PM_NgayTraDuKien, PM_ISBN, S_ISBN);
				PM++;
			}
				break;
			case 4:
			{
				cout << "Chuc nang lap phieu tra sach" << endl;
				returnCard(PM, PM_SoLuongSach, PM_MaDocGia, PM_NgayMuon, PM_NgayTraDuKien, PM_NgayTraThucTe, PM_ISBN, S_ISBN);
			}
				break;
			case 5:
			{
				cout << "Chuc nang thong ke" << endl;
				do
				{
					cout << "	1.Thong ke so luong sach trong thu vien" << endl;
					cout << "	2.Thong ke so luong sach theo the loai" << endl;
					cout << "	3.Thong ke so luong doc gia" << endl;
					cout << "	4.Thong ke so luong doc gia theo gioi tinh" << endl;
					cout << "	5.Thong ke so sach dang duoc muon" << endl;
					cout << "	0.Quay lai" << endl;
					cout << "	Chon chuc nang: ";

					cin >> choice5;
					switch (choice5)
					{
					case 1:
					{
						cout << "	Chuc nang thong ke so luong sach trong thu vien" << endl;
						cout << "		Thu vien hien co " << S_SoLuong << " quyen sach" << endl;
					}
						break;
					case 2:
					{
						cout << "	Chuc nang thong ke so luong sach theo the loai" << endl;
						bookStatisticByCategory(S_SoLuong, S_TheLoai);
					}
						break;
					case 3:
					{
						cout << "	Chuc nang thong ke so luong doc gia" << endl;
						cout << "		Thu vien hien co " << nDG << " doc gia" << endl;
					}
						break;
					case 4:
					{
						cout << "	Chuc nang thong ke so luong doc gia theo gioi tinh" << endl;
						readerStatisticBySex(nDG, DG_GioiTinh);
					}
						break;
					case 5:
					{
						cout << "	Chuc nang thong ke so sach duoc muon" << endl;
						int s = 0;
						for (int i = 0; i < PM; i++)
						{
							s += PM_SoLuongSach[i];
						}
						cout << "		So sach dang duoc muon la: " << s << endl;
					}
						break;
					default:
					{
						if (choice5 != 0)
							cout << "	Khong co chuc nang nay" << endl;
					}
						break;
					}
				} while (choice5 != 0);
			}
				break;
			case 0:
			{
				cout << "Chuong trinh da ket thuc" << endl;
			}
				return 0;
			default:
			{
				cout << "Khong co chuc nang nay" << endl;
			}
				break;
		}
	}
	return 0;
}