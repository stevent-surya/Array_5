#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Struktur untuk menyimpan data mahasiswa
struct Mahasiswa {
	string nim; // NIM Mahasiswa
	string nama; // Nama Mahasiswa
	string prodi; // Prodi Mahasiswa
	string jenjang; // Jenjang pendidikan mahasiswa
};

// Fungsi untuk menentukan prodi berdasarkan NIM contohnya 2023'6'048
void tentukanProdiDanJenjang(Mahasiswa& mhs) {
	char kodeProdi = mhs.nim[4]; // Ambil karakter ke 5 dari NIM

	// Menentukan prodi berdasarkan digit ke 6 dari NIM
	// Menentukan jenjang berdasarkan NIM
	switch (kodeProdi) {
	case '1': 
		mhs.prodi = "Teknik Mesin Industri";
		mhs.jenjang = "Diploma";
		break;
	case '2':
		mhs.prodi = "Teknik Mekatronika";
		mhs.jenjang = "Diploma";
		break;
	case '3':
		mhs.prodi = "Teknik Perancangan Manufaktur";
		mhs.jenjang = "Diploma";
		break;
	case '4':
		mhs.prodi = "Rekayasa Teknik Mesin";
		mhs.jenjang = "Sarjana Terapan";
		break;
	case '5':
		mhs.prodi = "Perancangan Manufaktur";
		mhs.jenjang = "Sarjana Terapan";
		break;
	case '6':
		mhs.prodi = "Teknologi Rekayasa Mekatronika";
		mhs.jenjang = "Sarjana Terapan";
		break;
	default:
		mhs.prodi = "Prodi Tidak Dikenal";
		mhs.jenjang = "Sarjana Terapan";
		break;
	}
}


// Fungsi untuk menampikan data mahasiswa
void tampilkanData(const Mahasiswa& mhs) {
	cout << "=================================" << endl;
	cout << "NIM : " << mhs.nim << endl; // Menampilkan NIM mhs
	cout << "Nama :" << mhs.nama << endl; // Menampikan nama mhs
	cout << "Prodi :" << mhs.prodi << endl; // Menampilkan prodi mhs
	cout << "Jenjang :" << mhs.jenjang << endl; // Menampilkan jenjang mhs
	cout << "=================================" << endl <<endl <<endl;
}

// Fungsi untuk mengurutkan data mhs
void  urutkanNim(Mahasiswa arr[], int n) {
	// Menggunakan fungsi sort dari <algorithm>
	sort(arr, arr + n, [](const Mahasiswa& a, const Mahasiswa& b) {
		return a.nim < b.nim; // Membandingkan NIM untuk proses mengurutkan
		});
}

void urutkanProdi(Mahasiswa arr[], int n) {
	sort(arr, arr + n, [](const Mahasiswa& a, const Mahasiswa& b) {
		return a.prodi < b.prodi;
		});
}

// Fungsi utama
int main() {
	Mahasiswa mahasiswa[8];
	int jumlahMahasiswa = 0;

	while (true) {

		if (jumlahMahasiswa < 8) {
			cout <<"Masukkan Data Mahasiwa ke-" << jumlahMahasiswa + 1 << endl;
			cout << "NIM: ";
			cin >> mahasiswa[jumlahMahasiswa].nim;
			cout << "Nama: ";
			cin.ignore();
			getline(cin, mahasiswa[jumlahMahasiswa].nama);

			tentukanProdiDanJenjang(mahasiswa[jumlahMahasiswa]);
			jumlahMahasiswa++;
		}

		char yt;
		cout << endl << "Masukkan Data Lagi(y/t): " <<endl;
		cin >> yt;

		if (yt != 'y' && yt != 'Y') {
			break;
		}
	}
	system("CLS");
	cout << "\nData Mahasiswa Setelah Diurutkan Berdasarkan NIM:" << endl <<endl;
	urutkanProdi(mahasiswa, jumlahMahasiswa);
	for (int i = 0; i < jumlahMahasiswa; i++) {
		tampilkanData(mahasiswa[i]);
	}

	return 0;
}