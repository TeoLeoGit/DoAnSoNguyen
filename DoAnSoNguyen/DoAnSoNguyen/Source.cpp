#include <fstream>
#include "Convert.h"

int main(int argc, char* argv[])
{
	int counter;
	//chỉ có file exe
	if (argc == 1)
		cout << "\nNo Extra Command Line Argument Passed Other Than Program Name";
	//chỉ có 2 file
	if (argc == 2)
		cout << "\nOnly exercute file and input file";
	//có file exe, input, output
	if (argc == 3)
	{
		cout << "\nNumber Of Arguments Passed: %d" << argc;
		cout << "\n----Following Are The Command Line Arguments Passed----" << endl;
		for (counter = 0;counter < argc;counter++)
			cout << "argument[" << counter << "]:   " << argv[counter];
		//phần đọc input file và ghi output file, argv[1] = input.txt, argv[2] = output.txt

		fstream InputFile(argv[1], ios::in);
		ofstream OutputFile(argv[2], ios::out);
		if (!InputFile)
		{
			cout << "Khong tim thay file Input." << endl;
			return 0;
		}
		if (!OutputFile)
		{
			cout << "Khong mo duoc file Output." << endl;
			return 0;
		}
		
		//Xử lý dữ liệu
		QInt BinResult;
		string InputBase, Str1, Str2, Result;
		char Ch;
		while (InputFile.get(Ch))
		{
			getline(InputFile, InputBase, ' ');
			getline(InputFile, Str1, ' ');
			getline(InputFile, Str2, ' ');
			//xét phần tử getline được ở lần getline thứ 3 trước để giải quyết trg hợp là phép toán thường
			if (Str2 == "+")
			{
				string Str3;
				QInt Numb2;
				getline(InputFile, Str3, '\n');
				if (InputBase == "10")
				{
					BinResult = Convert::StrDectoQInt(Str1);
					Numb2 = Convert::StrDectoQInt(Str3);
				}
				else
					if (InputBase == "16")
					{
						BinResult = Convert::StrHextoQInt(Str1);
						Numb2 = Convert::StrHextoQInt(Str3);
					}
				BinResult = BinResult + Numb2;
				Result = Convert::QInttoDecStr(BinResult);
				goto finishedStr1;
			}
			if (Str2 == "-")
			{
				string Str3;
				QInt Numb2;
				getline(InputFile, Str3, '\n');
				if (InputBase == "10")
				{
					BinResult = Convert::StrDectoQInt(Str1);
					Numb2 = Convert::StrDectoQInt(Str3);
				}
				else
					if (InputBase == "16")
					{
						BinResult = Convert::StrHextoQInt(Str1);
						Numb2 = Convert::StrHextoQInt(Str3);
					}
				BinResult = BinResult - Numb2;
				Result = Convert::QInttoDecStr(BinResult);
				goto finishedStr1;
			}
			if (Str2 == "*")
			{
				string Str3;
				QInt Numb2;
				getline(InputFile, Str3, '\n');
				if (InputBase == "10")
				{
					BinResult = Convert::StrDectoQInt(Str1);
					Numb2 = Convert::StrDectoQInt(Str3);
				}
				else
					if (InputBase == "16")
					{
						BinResult = Convert::StrHextoQInt(Str1);
						Numb2 = Convert::StrHextoQInt(Str3);
					}
				BinResult = BinResult * Numb2;
				Result = Convert::QInttoDecStr(BinResult);
				goto finishedStr1;
			}
			if (Str2 == "/")
			{
				string Str3;
				QInt Numb2;
				getline(InputFile, Str3, '\n');
				if (InputBase == "10")
				{
					BinResult = Convert::StrDectoQInt(Str1);
					Numb2 = Convert::StrDectoQInt(Str3);
				}
				else
					if (InputBase == "16")
					{
						BinResult = Convert::StrHextoQInt(Str1);
						Numb2 = Convert::StrHextoQInt(Str3);
					}
				BinResult = BinResult / Numb2;
				Result = Convert::QInttoDecStr(BinResult);
				goto finishedStr1;
			}
			if (Str2 == "^")
			{
				string Str3;
				QInt Numb2;
				getline(InputFile, Str3, '\n');
				if (InputBase == "10")
				{
					BinResult = Convert::StrDectoQInt(Str1);
					Numb2 = Convert::StrDectoQInt(Str3);
				}
				else
					if (InputBase == "16")
					{
						BinResult = Convert::StrHextoQInt(Str1);
						Numb2 = Convert::StrHextoQInt(Str3);
					}
				BinResult = BinResult ^ Numb2;
				Result = Convert::QInttoDecStr(BinResult);
				goto finishedStr1;
			}
			if (Str2 == "|")
			{
				string Str3;
				QInt Numb2;
				getline(InputFile, Str3, '\n');
				if (InputBase == "10")
				{
					BinResult = Convert::StrDectoQInt(Str1);
					Numb2 = Convert::StrDectoQInt(Str3);
				}
				else
					if (InputBase == "16")
					{
						BinResult = Convert::StrHextoQInt(Str1);
						Numb2 = Convert::StrHextoQInt(Str3);
					}
				BinResult = BinResult | Numb2;
				Result = Convert::QInttoDecStr(BinResult);
				goto finishedStr1;
			}
			if (Str2 == "&")
			{
				string Str3;
				QInt Numb2;
				getline(InputFile, Str3, '\n');
				if (InputBase == "10")
				{
					BinResult = Convert::StrDectoQInt(Str1);
					Numb2 = Convert::StrDectoQInt(Str3);
				}
				else
					if (InputBase == "16")
					{
						BinResult = Convert::StrHextoQInt(Str1);
						Numb2 = Convert::StrHextoQInt(Str3);
					}
				BinResult = BinResult & Numb2;
				Result = Convert::QInttoDecStr(BinResult);
				goto finishedStr1;
			}
			if (Str2 == ">>")
			{
				//work
				goto finishedStr1;
			}
			if (Str2 == "<<")
			{
				//work
				goto finishedStr1;
			}

			//Xét getline ở lần getline thứ 2
			if (Str1 == "16")
			{
				//đổi hệ
				goto finishedStr1;
			}
			if (Str1 == "10")
			{
				//đổi hệ
				goto finishedStr1;
			}
			if (Str1 == "2")
			{
				//đổi hệ
				goto finishedStr1;
			}
			if (Str1 == "rol")
			{
				//đổi hệ và xoay trái rồi trả về tương ứng
				goto finishedStr1;
			}
			if (Str1 == "ror")
			{
				//đổi hệ xoay phải rồi trả về tương ưng
				goto finishedStr1;
			}
			if (Str1 == "~")
			{
				//đổi hệ và not rồi trả về tương ứng
				goto finishedStr1;
			}

		finishedStr1: //trả kết quả vào file output
			OutputFile << Result;
		}
		InputFile.close();
		OutputFile.close();
	}
	system("pause");
	return 0;
}

