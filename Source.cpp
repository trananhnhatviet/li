#pragma warning(push)
#pragma warning(disable:6385)
#pragma warning(pop)
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <strsafe.h>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
#include <filesystem>
#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <windows.h>
#include <set>
using namespace std;

wstring StringToWString(const string& str);
string WStringToString(const wstring& wstr);
void Dang_ki();
void Display();
void Start();
void Them_sach();
void delete_line(int n);
void Xoa_sach();
void Sua_sach();
void Admin();
void Acc(string user, string ten_dang_nhap);
void Dang_nhap();
void alo();

int main()
{
    // (void)_setmode(_fileno(stdin), _O_U16TEXT);
    // (void)_setmode(_fileno(stdout), _O_U16TEXT);
    // SetConsoleTitleW(L"Trần Anh Nhật Việt đẹp trai vãi ò");
    // HANDLE hdlConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // CONSOLE_FONT_INFOEX consoleFont;
    // consoleFont.cbSize = sizeof(consoleFont);
    // GetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
    // // memcpy(consoleFont.FaceName, L"Consolas", sizeof(consoleFont.FaceName));
    // SetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
    // std::wcout << L"Tiếng Việt có dấu" << std::endl;
    // std::wstring test;
    // std::wcout << L"Hãy nhập vào một chuỗi ký tự:" << std::endl;
    // std::getline(std::wcin, test);
    // std::wcout << L"Chuỗi ký tự mà bạn vừa mới nhập:" << std::endl;
    // std::wcout << test << std::endl;
    // return 0;
    alo();
    return 0;
}

void Them_sach() {
   system("CLS");
   std::wofstream output("Book_List.txt", ios::app);
   std::wofstream output1("ID.txt", ios::app);
   std::wifstream myfile;
   myfile.open("Number_Book.txt");
   std::wstring book;
   std::wstring author;
   std::wstring name_of_book;
   int number_book;
   int year, num;
   std::wstring accept;
   bool check = true;
   (void)_setmode(_fileno(stdin), _O_U16TEXT);
    (void)_setmode(_fileno(stdout), _O_U16TEXT);
    SetConsoleTitleW(L"Trần Anh Nhật Việt đẹp trai vãi ò");
    HANDLE hdlConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX consoleFont;
    consoleFont.cbSize = sizeof(consoleFont);
    GetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
    // memcpy(consoleFont.FaceName, L"Consolas", sizeof(consoleFont.FaceName));
   while (check == true) {
       myfile >> number_book;
       myfile.open("Number_Book.txt", std::ofstream::out | std::ofstream::trunc);
       myfile.close();
       ofstream outfile("Number_Book.txt");
       std::wcout << L"Nhập tên tác giả" << std :: flush << std::endl;
       getline(wcin, author);
       fflush(stdin);
       while (author.length() < 30) {
           author = author + L' ';
       }
       author = L"                   " + author;
       cout << endl;
       std::wcout << L"Nhập tên tác phẩm " << std :: flush << std::endl;
       fflush(stdin);
       std::getline(wcin, name_of_book);
       while (name_of_book.length() < 40) {
           name_of_book = name_of_book + L' ';
       }
       std::wcout << L"Số trang " << std :: flush << std::endl;
       std::cin >> num;
       std::wcout << L"Năm ra mắt" << std :: flush << std::endl;
       std::cin >> year;
       std::string x = to_string(num);
       std::wstring xx = StringToWString(x);
       while (xx.length() < 20) {
           xx = xx + L' ';
       }
       std::string t = to_string(year);
       std::wstring tt = StringToWString(t);
       while (tt.length() < 20) {
           tt = tt + L' ';
       }
       number_book = number_book + 1;
       book = author + name_of_book + xx + tt;
       output << book << endl;
       output1 << number_book << endl;
       outfile << number_book;
       outfile.close();
       std::wcout << L"Bạn có muốn thêm sách nữa không" << std :: flush << std::endl;
       wcin >> accept;
       wcin.ignore();
       if ((accept == L"N") || (accept == L"n")) {
           check = false;
       }
       if (check == false) {
           Admin();
       }
   }
}
void delete_line(int n) {
   system("CLS");
   int max;
   fstream read_file;
   ifstream input3("Number_Book.txt");
   input3 >> max;
   input3.close();
   ofstream output("Number_Book.txt");
   ofstream output1("ID.txt");
   read_file.open("Book_List.txt");
   if (read_file.fail()) {
       cout << "Error opening file." << endl;
   }
    (void)_setmode(_fileno(stdin), _O_U16TEXT);
    (void)_setmode(_fileno(stdout), _O_U16TEXT);
    SetConsoleTitleW(L"Trần Anh Nhật Việt đẹp trai vãi ò");
    HANDLE hdlConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX consoleFont;
    consoleFont.cbSize = sizeof(consoleFont);
    GetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
    // memcpy(consoleFont.FaceName, L"Consolas", sizeof(consoleFont.FaceName));
   vector<string> lines;
   string line;
   while (getline(read_file, line))
       lines.push_back(line);
   read_file.close();
   if (n > lines.size())
   {
       std::wcout << L"Trong thư viện không có sách có ID " << n-1 << std::endl;
       std::wcout << L"Thư Viện chỉ có " << line.size()-1;
       std::wcout << L" sach." << std::endl;
   }
   ofstream write_file;
   write_file.open("Book_List.txt");
   if (write_file.fail())
   {
       cout << "Error opening file." << endl;
   }
   n--;
   for (int i = 0; i < lines.size(); i++)
       if (i != n)
           write_file << lines[i] << endl;
   write_file.close();
   max = max - 1;
   output << max;
   output.close();
   output1 << "ID" << endl;
   for (int i = 1; i <= max; i++) {
       output1 << i << endl;
   }
   output1.close();
}
void Xoa_sach() {
   system("CLS");
   (void)_setmode(_fileno(stdin), _O_U16TEXT);
    (void)_setmode(_fileno(stdout), _O_U16TEXT);
    SetConsoleTitleW(L"Trần Anh Nhật Việt đẹp trai vãi ò");
    HANDLE hdlConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX consoleFont;
    consoleFont.cbSize = sizeof(consoleFont);
    GetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
    // memcpy(consoleFont.FaceName, L"Consolas", sizeof(consoleFont.FaceName));
   ifstream input("ID.txt");
   int line;
   ifstream input2("Book_List.txt");
   if ((input2.is_open()) && (input.is_open())) {
       string outfile, outfile2;
       while (getline(input, outfile) && getline(input2, outfile2)) {
           cout << outfile << outfile2 << endl;
       }
   }
   std::wcout << L"Bạn muốn xóa sách nào ?" << std::endl;
   wcin >> line; wcin.ignore();
   line = line + 1;
   delete_line(line);
   Admin();
}
void Sua_sach() {
   system("CLS");
  (void)_setmode(_fileno(stdin), _O_U16TEXT);
    (void)_setmode(_fileno(stdout), _O_U16TEXT);
    SetConsoleTitleW(L"Trần Anh Nhật Việt đẹp trai vãi ò");
    HANDLE hdlConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX consoleFont;
    consoleFont.cbSize = sizeof(consoleFont);
    GetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
    // memcpy(consoleFont.FaceName, L"Consolas", sizeof(consoleFont.FaceName));
   int n, number_book;
   ifstream input1("ID.txt");
   ifstream input2("Book_List.txt");
   ifstream input3("Number_Book.txt");
   input3 >> number_book;
   if ((input2.is_open()) && (input1.is_open())) {
       string outfile1, outfile2;
       while (getline(input1, outfile1) && getline(input2, outfile2)) {
           cout << outfile1 << outfile2 << endl;
       }
   }
   std::wcout << L"Bạn muốn sửa sách có ID nào ?" << std::endl;
   wcin >> n; wcin.ignore();
   if (n <= number_book) {
       delete_line(n);
       Them_sach();
   }
   else {
       std::wcout << L"Không có sách có ID " << n << L" trong thư viện" << std::endl;
       std::wcout << L"Trong thư viện chỉ có " << number_book << L"sách"  << std::endl;    }
   Admin();
}
void Admin() {
   system("CLS");
   int n;
  (void)_setmode(_fileno(stdin), _O_U16TEXT);
    (void)_setmode(_fileno(stdout), _O_U16TEXT);
    SetConsoleTitleW(L"Trần Anh Nhật Việt đẹp trai vãi ò");
    HANDLE hdlConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX consoleFont;
    consoleFont.cbSize = sizeof(consoleFont);
    GetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
    // memcpy(consoleFont.FaceName, L"Consolas", sizeof(consoleFont.FaceName));
   ifstream input("Book_List.txt");
   std::wcout << L"Bạn là ADMIN !!!" << std::endl;
   std::wcout << L"1. Thêm sách vào thư viện " << std::flush << std::endl;
   std::wcout << L"2. Sửa sách trong thư viện " << std::flush << std::endl;
   std::wcout << L"3. Xóa sách khỏi thư viện " << std::flush << std::endl;
   std::wcout << L"Các phím còn lại: Thoát về trang chủ " << std::fflush << std::endl;
   wcin >> n; wcin.ignore();
   fflush(stdin);
   if ((n != 1) && (n != 2) && (n != 3)) {
       if (n == 1) {
           Them_sach();
       }
       if (n == 2) {
           Sua_sach();
       }
       if (n == 3) {
           Xoa_sach();
       }
   }
   else {
       alo();
   }
}
void Acc(string user, string ten_dang_nhap) {
   system("CLS");
   int n;
   string tdn = ten_dang_nhap;
   int line_book;
   int numberofbook;
   std::wstring user_num_book;
   std::wstring user_ID_book;
   std::wifstream input_book("Book_List.txt");
   std::wifstream input_ID("ID.txt");
   std::wifstream input_Number_Book("Number_Book.txt");
   input_Number_Book >> numberofbook;
    (void)_setmode(_fileno(stdin), _O_U16TEXT);
    (void)_setmode(_fileno(stdout), _O_U16TEXT);
    SetConsoleTitleW(L"Trần Anh Nhật Việt đẹp trai vãi ò");
    HANDLE hdlConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX consoleFont;
    consoleFont.cbSize = sizeof(consoleFont);
    GetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
    // memcpy(consoleFont.FaceName, L"Consolas", sizeof(consoleFont.FaceName));
   user = user + ".txt";
   std::wstring a;
   a = StringToWString(tdn);
   user_num_book = L"num_book_" + StringToWString(user);
   user_ID_book = L"ID_book_" + StringToWString(user);
   std::wcout << L"Xin chào bạn " << a;
   std::wcout << L" của tui" << std::endl;
   std::wcout << L"Bạn muốn làm gì thế ?" << std::endl;
   std::wcout << L"1. Mượn sách" << std::endl;
   std::wcout << L"2. Trả sách" << std::endl;
   std::wcout << L"3. Thoát về trang chủ" << std::endl;
   std::wcin >> n; wcin.ignore();
   if (n == 1) {
       if ((input_ID.is_open()) && (input_book.is_open())) {
           std::wstring outfile1, outfile2;
           while (std::getline(input_ID, outfile1) && std::getline(input_book, outfile2)) {
               std::wcout << outfile1 << outfile2 << endl;
           }
           input_ID.close();
           input_book.close();
       }
       std::wfstream read_file;
       read_file.open("Book_List.txt");
       vector<wstring> lines;
       std::wstring line;
       while (std::getline(read_file, line))
           lines.push_back(line);
       read_file.close();
       std::wcout << L"Bạn muốn mượn sách có ID nào?" << endl;
       wcin >> line_book; wcin.ignore();
       line_book = line_book + 1;
       if (line_book-1 > numberofbook) {
           std::wcout << L"Sách có ID " << line_book-1;
           std::wcout << L" không có trong thư viện" << std::endl;
           std::wcout << L"Thư viện chỉ có " << numberofbook;
           std::wcout << L" sách" << std::endl;
       }
       else {
           //wcout << "ID                  Tac Gia			  Tac Pham				  So Trang	      Nam xuat ban";
           std::wifstream inputnum(user_num_book);
           int num;
           inputnum >> num;
           inputnum.close();
           if (num == -858993460) {
               num = 0;
           }
           std::wofstream input_user(user, ios::app);
           std::wofstream input_user_ID(user_ID_book, ios::app);
           std::wofstream input_user_num_book(user_num_book);
           line_book--;
           for (int i = 0; i < lines.size(); i++)
               if (i == line_book)
                   input_user << (lines[i]) << endl;
           num = num + 1;
           input_user_num_book << num;
           input_user_ID << num << endl;
           input_user.close();
           input_user_ID.close();
           input_user_num_book.close();
           std::wcout << L"Mượn thành công !" << std::endl;
           system("pause");
           alo();
       }
   }
   if (n == 2) {
       int numbook;
       std::wfstream read_file;
       read_file.open(user);
       vector<wstring> lines;
       std::wstring line;
       while (std::getline(read_file, line))
           lines.push_back(line);
       read_file.close();
       std::wifstream input1(user_ID_book);
       std::wifstream input2(user);
       std::wifstream input3(user_num_book);
       input3 >> numbook;
       input3.close();
       int n;
       wcout << "ID                  Tac Gia			  Tac Pham				  So Trang	      Nam xuat ban" << std::endl;
       if ((input1.is_open()) && (input2.is_open())) {
           std::wstring outfile1, outfile2;
           while (std::getline(input1, outfile1) && std::getline(input2, outfile2)) {
               wcout << outfile1 << outfile2 << endl;
           }
       }
       std::wcout << L"Bạn muốn trả sách có ID " << std::endl;
       wcin >> n; wcin.ignore();
       ofstream write_file;
       ofstream output(user_num_book);
       ofstream output1(user_ID_book);
       write_file.open(user);
       n--;
       int x;
       x=lines.size();
       for (int i = 0; i < x; i++)
           if (i != n)
               write_file << WStringToString(lines[i]) << endl;
       write_file.close();
       numbook = numbook - 1;
       output << numbook;
       output.close();
       for (int i = 1; i <= numbook; i++) {
           output1 << i << endl;
       }
       output1.close();
       std::wcout << L"Trả sách thành công !" << std::endl;
       alo();
   }
   if (n == 3) {
       alo();
   }
};
void Display() {
   system("CLS");
   std::wifstream inputabc("Display.txt");
   if (inputabc.is_open()) {
       std::wstring outfile1;
       while (std::getline(inputabc, outfile1)) {
           wcout << outfile1 << endl;
       }
       inputabc.close();
   }
}
void Start() {
   int nhap;
   (void)_setmode(_fileno(stdin), _O_U16TEXT);
    (void)_setmode(_fileno(stdout), _O_U16TEXT);
    SetConsoleTitleW(L"Trần Anh Nhật Việt đẹp trai vãi ò");
    HANDLE hdlConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX consoleFont;
    consoleFont.cbSize = sizeof(consoleFont);
    GetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
    // memcpy(consoleFont.FaceName, L"Consolas", sizeof(consoleFont.FaceName));
   std::wcout << L"0. Restart " << std::endl;
   std::wcout << L"1. Đăng nhập " << std::endl;
   std::wcout << L"2. Đăng kí " << std::endl;
   std::wcout << L"3. Thoát " << std::endl;
   wcin >> nhap; wcin.ignore();
   if (nhap == 2) {
       Dang_ki();
   }
   if (nhap==1){
       Dang_nhap();
   }
   if (nhap == 0) {
       alo();
   }
   if (nhap == 4) {
       exit(0);
   }
}
void Dang_nhap() {
   system("CLS");
   std::wstring ten_dang_nhap;
   std::wstring password;
   std::wstring user;
   ifstream input("User.txt");
  (void)_setmode(_fileno(stdin), _O_U16TEXT);
    (void)_setmode(_fileno(stdout), _O_U16TEXT);
    SetConsoleTitleW(L"Trần Anh Nhật Việt đẹp trai vãi ò");
    HANDLE hdlConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX consoleFont;
    consoleFont.cbSize = sizeof(consoleFont);
    GetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
    // memcpy(consoleFont.FaceName, L"Consolas", sizeof(consoleFont.FaceName));
   int numline ;
   numline = 0;
   bool check_chua_co = true;
   std::wcout << L"Nhập tên người dùng "  << std::endl;
   std::getline(std::wcin, ten_dang_nhap);
   std::wcout << L"Mật khẩu" << std::endl;
   std::getline(std::wcin, password);
   user = ten_dang_nhap + L"(abcdefg)" + password + L"(hijklmn)";
   if (user == L"nhatviet(abcdefg)18092004(hijklmn)") {
       Admin();
       check_chua_co = true;
   }
   else {
       std::string a;
       a = WStringToString(user);
       if (input.is_open()) {
           string outfile;
           while (std::getline(input, outfile)) {
               if ((outfile) == a) {
                   check_chua_co = false;
                   break;
               }
           }
       }
       if (check_chua_co != false) {
           std::wcout << L"SAI MẬT KHẢU !" << std::endl;
           Start();
       }
       else {
           Acc(WStringToString(user), WStringToString(ten_dang_nhap));
       }
   }
   input.close();
   exit(0);
   system("C:\\Users\\Admin\\source\\repos\\Library_Project\\a.exe");
}
void Dang_ki() {
   system("CLS");
   std::wstring ten_dang_nhap;
   std::wstring password;
   std::wstring user;
   ofstream input("User.txt", ios::app);
   ifstream num("Number_User.txt");
   int number_user;
   num >> number_user;
   number_user = number_user + 1;
   num.close();
   ofstream outnum("Number_User.txt");
   outnum << number_user;
   bool check_chua_co;
   check_chua_co = true;
   std::wcout << L"Đăng kí!" << std::endl;
   std::wcout << L"Nhập tên người dùng" << std::endl;
   std::getline(std::wcin,ten_dang_nhap);
   std::wcout << L"Mật khẩu" << std::endl;
   std::getline(std::wcin,password);
   user = ten_dang_nhap + L"(abcdefg)" + password + L"(hijklmn)";
   if (!input) {
       cout << "No such file found";
   }
   else {
       std::string a;
       a = WStringToString(user);
       number_user = number_user + 1;
       input << a << endl;
       input.close();
   }
   exit(0);
   system("C:\\Users\\Admin\\source\\repos\\Library_Project\\a.exe");
   alo();
}
void alo() {
   system("CLS");
   Display();
   Start();
}
wstring StringToWString(const string& str)
{
    wstring wstr;
    size_t size;
    wstr.resize(str.length());
    mbstowcs_s(&size, &wstr[0], wstr.size() + 1, str.c_str(), str.size());
    return wstr;
}
string WStringToString(const wstring& wstr)
{
    string str;
    size_t size;
    str.resize(wstr.length());
    wcstombs_s(&size, &str[0], str.size() + 1, wstr.c_str(), wstr.size());
    return str;
}

