// ConsoleApplication1.cpp : Konsol uygulamasý için giriþ noktasýný tanýmlar.
// ConsoleApplication1.cpp : Konsol uygulamasý için giriþ noktasýný tanýmlar.
// ConsoleApplication1.cpp : Konsol uygulamasý için giriþ noktasýný tanýmlar.

#include <iostream>		// for cout,cin etc. 
#include <conio.h>		// for "getch();" function
#include <fstream>		// for filing processes
#include <string>		// for string type
#include <windows.h>	// to color the command screen
#include <clocale>		// for Turkish character
#include <iomanip>		//for setw()
#include <stdio.h>
#include <typeinfo>



using namespace std;
string telephone_number();
string tc_no();

string tc_no()
{
	//if(typeid(identity).name() == "String") //tip kontrol
	string identity;
	do {
		printf("Lütfen 11 Haneli TC Kimlik Numaranýzý Girin: ");
		cin >> identity;
	} while (identity.length() != 11);


	return identity;
}

string telephone_number()
{
	string areaCode;
	string number;

	do {
		printf("Lütfen 3 Haneli Alan Kodunu Girin: ");
		cin >> areaCode;
	} while (areaCode.length() != 3);


	do {
		printf("Lütfen Geriye Kalan 7 Haneli Numarayý Girin: ");
		cin >> number;
	} while (number.length() != 7);

	return areaCode + "-" + number;
}

void ReadPatient(fstream& DRead)
{
	int patientAge;
	string TcNo, Telephone;
	char patientName[30], patientSurname[20], patientGender[15];
	while (DRead >> TcNo >> patientName >> patientSurname >> patientAge >> Telephone >> patientGender) // The loop continues for the number of data.
	{
		cout << "=======================================\n";
		cout << "TC Kimlik No :" << TcNo << endl;
		cout << "Adý :" << patientName << endl;
		cout << "Soyadý :" << patientSurname << endl;
		cout << "Yaþý :" << patientAge << endl;
		cout << "Telefonu :" << Telephone << endl;
		cout << "Cinsiyeti:" << patientGender << endl;
		cout << "=======================================\n";
	}
}

void PatientQueries(fstream& DRead, string HSorgu)
{
	int counter = 0;
	int patientAge;
	string TcNo, Telephone;
	char patientName[30], patientSurname[20], patientGender[15];
	while (DRead >> TcNo >> patientName >> patientSurname >> patientAge >> Telephone >> patientGender) // The loop continues for the number of data.
	{
		if (HSorgu == TcNo)
		{
			counter++;
			cout << "=======================================\n";
			cout << "TC Kimlik No :" << TcNo << endl;
			cout << "Adý :" << patientName << endl;
			cout << "Soyadý :" << patientSurname << endl;
			cout << "Yaþý :" << patientAge << endl;
			cout << "Telefonu :" << Telephone << endl;
			cout << "Cinsiyeti:" << patientGender << endl;
			cout << "=======================================\n";
		}
	}

	if (counter == 0) { cout << "Bu Tc Kimliðe Sahip Bir Hasta Bulunmuyor! \n";}
}

void PatientUpdate(fstream& DRead, string HUpdate)
{
	fstream DWrite;
	int patientAge;
	string TcNo, Telephone;
	char patientName[30], patientSurname[20], patientGender[15];

	DWrite.open("Bos.txt", ios::out); // creating temporary file

	while (DRead >> TcNo >> patientName >> patientSurname >> patientAge >> Telephone >> patientGender) // The loop continues for the number of data.
	{
		if (HUpdate == TcNo)
		{
			cout << "=======================================\n";

			cout << "Sistemde Görünen Ad: " << patientName << endl;
			cout << "Yeni Ad: ";
			cin >> patientName;
			cout << "=======================================\n";

			cout << "Sistemde Görünen SoyAd: " << patientSurname << endl;
			cout << "Yeni SoyAd: ";
			cin >> patientSurname;
			cout << "=======================================\n";

			cout << "Sistemde Görünen Yaþ: " << patientAge << endl;
			cout << "Yeni Yaþ: ";
			cin >> patientAge;
			cout << "=======================================\n";

			cout << "Sistemde Görünen Telefon Numarasý: " << Telephone << endl;
			cout << "Yeni Telefon: ";
			Telephone = telephone_number();
			cout << "=======================================\n";

			cout << "Sistemde Görünen Cinsiyet: " << patientGender << endl;
			cout << "Yeni Cinsiyet: ";
			cin >> patientGender;
			cout << "=======================================\n";

			DWrite << TcNo << " " << patientName << " " << patientSurname << " " << patientAge << " " << Telephone << " " << patientGender << " " << "\n";
			//break;
		}
		else { DWrite << TcNo << " " << patientName << " " << patientSurname << " " << patientAge << " " << Telephone << " " << patientGender << " " << "\n"; }
	}
	DRead.close();
	DWrite.close();
	system("del Hasta.txt"); // delete old file
	rename("Bos.txt", "Hasta.txt"); // rename temporary file
}

void UpdateAppointment(fstream& DRead, string HUpdate)
{
	fstream DWrite;
	int patientAge;
	string TcNo, Telephone;
	double Fee;
	char patientName[30], patientSurname[20], patientGender[15], Date[30], DoctorName[30], Diagnosis[20];

	DWrite.open("Bos.txt", ios::out); // creating temporary file

	while (DRead >> TcNo >> patientName >> patientSurname >> patientAge >> Telephone >> patientGender >> Date >> DoctorName >> Diagnosis >> Fee) // girilen kayit sayisi kadar don
	{
		if (HUpdate == TcNo) 
		{
			cout << "\n ********** Hasta Bilgileri ********** \n";
			cout << "===========================================\n";
			cout << "Hasta Adi: " << patientName << endl;
			cout << "Hasta SoyAdi: " << patientSurname << endl;
			cout << "Yaþ: " << patientAge << endl;
			cout << "Telefon Numarasý: " << Telephone << endl;
			cout << "Cinsiyet: " << patientGender << endl;
			cout << "===========================================\n";

			cout << "\n ********** Randevu Bilgileri ********** \n";
			cout << "===========================================\n";
			cout << "Randevu Tarihi: " << Date << endl;
			cout << "Doktor: " << DoctorName << endl;
			cout << "Teþhis: " << Diagnosis << endl;
			cout << "Muayene Ücreti: " << Fee << endl;
			cout << "===========================================\n";


			char choose;
			cout << "\n Deðiþtirilecek Randevu Bilgisi (R = Randevu Datei, D = Doktor, T = Teþhis, U = Ücret, H= Bütün Randevu Bilgileri Günceller): ";
			cin >> choose;
			switch (choose)
			{
				case 'R':
				{
					cout << "Randevu Tarihi: " << Date << endl;
					cout << "Yeni Randevu Tarihi: ";
					cin >> Date;

					DWrite << TcNo << " " << patientName << ' ' << patientSurname << ' ' << patientAge << ' ' << Telephone << ' ' << patientGender << ' ' << Date << ' ' << DoctorName << ' ' << Diagnosis << ' ' << Fee << "\n";
					break;
				}
				case 'D':
				{
					cout << "Doktor: " << DoctorName << endl;
					cout << "Yeni Doktor: ";
					cin >> DoctorName;

					DWrite << TcNo << " " << patientName << ' ' << patientSurname << ' ' << patientAge << ' ' << Telephone << ' ' << patientGender << ' ' << Date << ' ' << DoctorName << ' ' << Diagnosis << ' ' << Fee << "\n";
					break;
				}
				case 'T':
				{
					cout << "Teþhis: " << Diagnosis << endl;
					cout << "Yeni Teþhis: ";
					cin >> Diagnosis;

					DWrite << TcNo << " " << patientName << ' ' << patientSurname << ' ' << patientAge << ' ' << Telephone << ' ' << patientGender << ' ' << Date << ' ' << DoctorName << ' ' << Diagnosis << ' ' << Fee << "\n";
					break;
				}
				case 'U':
				{
					cout << "Ücret: " << Fee << endl;
					cout << "Yeni Ücret: ";
					cin >> Fee;

					DWrite << TcNo << " " << patientName << ' ' << patientSurname << ' ' << patientAge << ' ' << Telephone << ' ' << patientGender << ' ' << Date << ' ' << DoctorName << ' ' << Diagnosis << ' ' << Fee << "\n";
					break;
				}
				case 'H':
				{
					cout << "Randevu Tarihi: " << Date << endl;
					cout << "Yeni Randevu Tarihi: ";
					cin >> Date;

					cout << "Doktor: " << DoctorName << endl;
					cout << "Yeni Doktor: ";
					cin >> DoctorName;

					cout << "Teþhis: " << Diagnosis << endl;
					cout << "Yeni Teþhis: ";
					cin >> Diagnosis;

					cout << "Ücret: " << Fee << endl;
					cout << "Yeni Ücret: ";
					cin >> Fee;

					DWrite << TcNo << " " << patientName << ' ' << patientSurname << ' ' << patientAge << ' ' << Telephone << ' ' << patientGender << ' ' << Date << ' ' << DoctorName << ' ' << Diagnosis << ' ' << Fee << "\n";
					break;
				}
				default:
				{
					DWrite << TcNo << " " << patientName << ' ' << patientSurname << ' ' << patientAge << ' ' << Telephone << ' ' << patientGender << ' ' << Date << ' ' << DoctorName << ' ' << Diagnosis << ' ' << Fee << "\n";
					break;
				}
			}			
		}
		else { DWrite << TcNo << " " << patientName << ' ' << patientSurname << ' ' << patientAge << ' ' << Telephone << ' ' << patientGender << ' ' << Date << ' ' << DoctorName << ' ' << Diagnosis << ' ' << Fee << "\n"; }
	}
	DRead.close();
	DWrite.close();
	system("del RandevuAl.txt"); // delete old file
	rename("Bos.txt", "RandevuAl.txt"); // rename temporary file
}

void InspectionInquiry(fstream& DRead, string HSorgu)
{
	int counter = 0;
	int patientAge;
	string TcNo, Telephone;
	double Fee;
	char patientName[30], patientSurname[20], patientGender[15], Date[30], DoctorName[30], Diagnosis[20];
	while (DRead >> TcNo >> patientName >> patientSurname >> patientAge >> Telephone >> patientGender >> Date >> DoctorName >> Diagnosis >> Fee) // girilen kayit sayisi kadar don
	{
		if (HSorgu == TcNo)
		{
			counter++;
			cout << "====================================================\n";
			cout << "Hastanýn TC Kimlik Numarasý: " << TcNo << endl;
			cout << "====================================================\n";

			cout << "\n           ********** Hasta Bilgileri ********** \n";
			cout << "\n====================================================\n";
			cout << "Hasta Adý :" << patientName << endl;
			cout << "Hasta Soyadý :" << patientSurname << endl;
			cout << "Hasta Yaþý :" << patientAge << endl;
			cout << "Telefonu :" << Telephone << endl;
			cout << "Cinsiyeti:" << patientGender << endl;
			cout << "\n====================================================\n";

			cout << "\n           ********** Randevu Bilgileri ********** \n";
			cout << "\n====================================================\n";
			cout << "\n Tarih: " << Date;
			cout << "\n Doktor Adý: " << DoctorName;
			cout << "\n Teþhis: " << Diagnosis;
			cout << "\n Muayene Ücreti: " << Fee << " TL" << endl;
			cout << "====================================================\n";
			break;
		}
	}
	if (counter == 0)
	{
		cout << "Ýlgili Hastanýn Muayene Kaydý Mevuct Deðil! \n";
	}
}

int main()
{
	system("color 4B"); //coloring command screen
	setlocale(LC_ALL, "turkish"); //adding Turkish character

	int choose;
	string patientName;
	string patientSurname;
	string TcNo;
	string identity;
	string areaCode;
	string number;
	string Telephone;


	int KayitNo;
	int patientAge;
	string patientGender;
	char transaction;
	string TC;

	fstream DRead;

	string Date;
	string DoctorName;
	string Diagnosis;
	string Medicine;
	string Hour;
	string Assay;
	double Fee;
	char Answer;

	do {
		system("cls");
		cout << "	***Hastane Otomasyonu Yazýlýmýna Hoþgeldiniz!*** " << "\n";
		cout << "Lütfen Yapýlacak Ýþlemi Seçin...." << "\n";
		cout << "**************************************************" << "\n";
		cout << "1- Sisteme Hasta Kayýt Etme" << endl; //Menümüz
		cout << "2- Sistemdeki Hasta Kaydýný Güncelleme" << endl;
		cout << "3- Hasta Kaydý Silme (ÇALIÞMIYOR!!!)" << endl;
		cout << "4- Hastanýn Sistemde Olup Olmadýðýný Sorgulama" << endl;
		cout << "5- Sistemdeki Hasta Listesi" << endl;
		cout << "6- Randevu Alma" << endl;
		cout << "7- Randevu Silme (ÇALIÞMIYOR!!!)" << endl;
		cout << "8- Randevu Güncelleme" << endl;
		cout << "9- Hasta Muayene Kaydý" << endl;
		cout << "10- Otomasyondan Çýkýþ" << endl;
		cout << "**************************************************" << "\n";
		cout << "Yapmak istediginiz islemi seciniz (1,2,3,4 vb.): ";
		cin >> choose;
		system("cls");
		switch (choose) //Seçim yapýyoruz
		{
		case 1:
		{
			cout << "1- Sisteme Hasta Kayýt Etme" << endl; //Menüden number seçerken önce kayýt ekleme yapýyoruz

			ofstream DosyaYaz;
			DosyaYaz.open("Hasta.txt", ios::app);
			do
			{
				cout << "\n Hasta TC :"; TcNo = tc_no();
				cout << "\n Hasta Adi :"; cin >> patientName;
				cout << "\n Hasta Soyadi :"; cin >> patientSurname;
				cout << "\n Hasta Yasi :"; cin >> patientAge;
				cout << "\n Telefonu :"; Telephone = telephone_number();
				cout << "\n Cinsiyeti :"; cin >> patientGender;

				DosyaYaz << TcNo << " " << patientName << ' ' << patientSurname << ' ' << patientAge << ' ' << Telephone << ' ' << patientGender << endl;
				cout << "Dosyaya yazim tamamlandi." << endl;

				cout << "\n Baska kayit yapacak misiniz?(e/E: Yeni Kayýt Ekler!) (h/H: Kayýdý Tamamlar!) "; cin >> Answer;
				system("cls");
				cout << "1- Sisteme Hasta Kayýt Etme \n";

			} while (Answer == 'e' || Answer == 'E');

			DosyaYaz.close();
			cout << "Dosyaya yazim tamamlandi." << endl;

			break;
		}
		case 2:
		{
			cout << "\n Sistemdeki Hasta Kaydýný Güncelleme \n";
			DRead.open("Hasta.txt", ios::in);
			cout << "\n Güncellenecek Hastanýn TC identity No' su= ";
			cin >> TcNo;
			PatientUpdate(DRead, TcNo);
			DRead.close();
			system("pause"); break;
		}
		case 3:
		{
			/*cout<<"3- Hasta silme"<<endl;
			ifstream DosyaOku;
			DosyaOku.open("Hasta.txt");
			cout<<"TC no:";
			cin>>TC;
			if(TC==TcNo)
			{
			remove("Hasta.txt");
			}
			break;*/ cout << "Çalýþmýyor!!!" << endl; break;
		}
		case 4:
		{
			cout << "4- Hastanýn Sistemde Olup Olmadýðýný Sorgulama" << endl;
			DRead.open("Hasta.txt", ios::in);
			cout << "\nSorgulanacak Kiþinin Tc Kimlik No 'sunu Giriniz: ";
			cin >> TcNo;
			PatientQueries(DRead, TcNo);
			DRead.close();
			system("pause"); break;

		}
		case 5:
		{
			cout << "5- Sistemdeki Hasta Listesi" << endl;
			DRead.open("Hasta.txt", ios::in);
			ReadPatient(DRead);
			DRead.close();
			system("pause"); break;
		}
		case 6:
		{
			cout << "6- Randevu Alma" << endl;

			cout << " Randevu Alýnacak Hastanýn Tc Kimlik Numarasý? :"; cin >> TC;

			ifstream DosyaOku("Hasta.txt");
			while (!DosyaOku.eof())
			{
				DosyaOku >> TcNo >> patientName >> patientSurname >> patientAge >> Telephone >> patientGender;
				if (TC == TcNo)
				{
					cout << "\n=========================================" << endl;
					cout << " ******** Hasta Bilgileri ******** \n";
					cout << "TC no :" << TcNo << endl;
					cout << "Adý :" << patientName << endl;
					cout << "Soyadý :" << patientSurname << endl;
					cout << "Yasý :" << patientAge << endl;
					cout << "Telefonu :" << Telephone << endl;
					cout << "Cinsiyeti:" << patientGender << endl;
					cout << "=========================================" << endl;
					cout << "Randevu istiyor mu? (e/h): ";
					cin >> Answer;
					if (Answer == 'e' || Answer == 'E')
					{
						DosyaOku.close();
						ofstream DosyaYaz;
						DosyaYaz.open("RandevuAl.txt", ios::app);
						cout << "=========================================" << endl;
						cout << "******** Randevu Bilgileri ******** \n";
						cout << "Tarih :"; cin >> Date;
						cout << "Doktor Adi :"; cin >> DoctorName;
						cout << "Teshis :"; cin >> Diagnosis;
						cout << "Muayene Ucreti :"; cin >> Fee;
						cout << "\n=========================================" << endl;
						cout << "Randevu Alýndý." << endl;
						DosyaYaz << TcNo << " " << patientName << ' ' << patientSurname << ' ' << patientAge << ' ' << Telephone << ' ' << patientGender << ' ' << Date << ' ' << DoctorName << ' ' << Diagnosis << ' ' << Fee << "\n";
						DosyaYaz.close();
						system("cls");
						cout << "Randevu sisteme Kaydedildi." << endl;
					}
				}
			} break;
		}
		case 7:
		{
			/*cout<<"7- Randevu silme"<<endl;
			break;*/cout << "Çalýþmýyor!!!" << endl; break;
		}
		case 8:
		{
			cout << "\n 8- Randevu güncelleme \n";
			DRead.open("RandevuAl.txt", ios::in);
			cout << "\n Güncellenecek Hastanýn TC Kimlik No' su= ";
			cin >> TcNo;
			UpdateAppointment(DRead, TcNo);
			DRead.close();
			system("pause"); break;
		}
		case 9:
		{
			cout << "9- Hasta Muayene Kaydý Görüntüleme" << endl;
			DRead.open("RandevuAl.txt", ios::in);
			cout << "\nSorgulanacak Kiþinin Tc Kimlik No 'sunu Giriniz: ";
			cin >> TcNo;
			InspectionInquiry(DRead, TcNo);
			DRead.close();
			system("pause"); break;
		}
		case 10:
		{
			system("cls");
			cout << "Programý Kullandýðýnýz için Teþekkürler!!!" << "\n";
			cout << "Programdan Çýkmak Ýstediniz" << "\n";
			cout << "Çýkmak için Herhangi Bir Tuþa Basýn....." << "";
			_getch();
			exit(0);
			break;
		}
		}
		cout << "Ýþlem yapmaya devam etmek istiyor musunuz? (e/E: Ana Menüye Döner!) (h/H: Programdan Çýkar!)";
		cin >> transaction;
	} while (transaction == 'e' || transaction == 'E'); // After doing the process, we will see the menu again.
	cout << endl;

	system("cls");
	cout << "Programý Kullandýðýnýz için Teþekkürler!!!" << "\n";
	cout << "Programdan Çýkmak Ýstediniz" << "\n";
	cout << "Çýkmak için Herhangi Bir Tuþa Basýn....." << "";
	_getch();
	exit(0);
}