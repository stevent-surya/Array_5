#include <iostream>
#include <string>
#include <algorithm> // Untuk std::sort
#include <vector>    // Lebih fleksibel dari array C-style
#include <map>       // Untuk membuat urutan prodi kustom

using namespace std;

// Struktur untuk menyimpan data mahasiswa (tidak ada perubahan)
struct Mahasiswa {
	string nim;
	string nama;
	string prodi;
	string jenjang;
};

// Fungsi untuk menentukan prodi berdasarkan NIM (tidak ada perubahan)
void tentukanProdiDanJenjang(Mahasiswa& mhs) {
	char kodeProdi = mhs.nim[4]; // Ambil karakter ke-5 dari NIM (indeks ke-4)

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
		mhs.jenjang = "Tidak Diketahui";
		break;
	}
}

// Fungsi untuk menampilkan satu data mahasiswa (tidak ada perubahan)
void tampilkanData(const Mahasiswa& mhs) {
	cout << "=================================" << endl;
	cout << "NIM     : " << mhs.nim << endl;
	cout << "Nama    : " << mhs.nama << endl;
	cout << "Prodi   : " << mhs.prodi << endl;
	cout << "Jenjang : " << mhs.jenjang << endl;
	cout << "=================================" << endl << endl;
}

// =================================================================
// FUNGSI BARU DAN FUNGSI YANG DIMODIFIKASI
// =================================================================

/**
 * @brief Fungsi BARU untuk menampilkan semua data mahasiswa dalam array.
 *
 * @param arr Array mahasiswa.
 * @param n Jumlah elemen dalam array.
 */
void tampilkanSemuaData(Mahasiswa arr[], int n) {
	for (int i = 0; i < n; i++) {
		tampilkanData(arr[i]);
	}
}

/**
 * @brief Fungsi untuk mengurutkan mahasiswa berdasarkan NIM saja (Ascending).
 *
 * @param arr Array mahasiswa.
 * @param n Jumlah elemen dalam array.
 */
void urutkanBerdasarkanNim(Mahasiswa arr[], int n) {
	sort(arr, arr + n, [](const Mahasiswa& a, const Mahasiswa& b) {
		return a.nim < b.nim; // Membandingkan NIM untuk mengurutkan dari kecil ke besar
		});
}


/**
 * @brief Fungsi BARU untuk mengurutkan berdasarkan urutan prodi kustom,
 * lalu berdasarkan NIM (memenuhi kedua permintaan Anda).
 *
 * @param arr Array mahasiswa.
 * @param n Jumlah elemen dalam array.
 */
void urutkanBerdasarkanProdiKustomDanNim(Mahasiswa arr[], int n) {
	// 1. Buat peta (map) untuk mendefinisikan urutan prodi yang diinginkan.
	// Angka yang lebih kecil memiliki prioritas lebih tinggi.
	map<string, int> urutanProdi = {
		{"Teknik Mesin Industri", 0},
		{"Teknik Mekatronika", 1},
		{"Teknik Perancangan Manufaktur", 2},
		{"Rekayasa Teknik Mesin", 3},
		{"Perancangan Manufaktur", 4},
		{"Teknologi Rekayasa Mekatronika", 5},
		{"Prodi Tidak Dikenal", 6} // Prodi lain diletakkan di akhir
	};

	// 2. Gunakan std::sort dengan lambda custom
	sort(arr, arr + n, [&](const Mahasiswa& a, const Mahasiswa& b) {
		// Ambil urutan numerik dari prodi A dan B
		int urutanA = urutanProdi[a.prodi];
		int urutanB = urutanProdi[b.prodi];

		// Jika urutan prodinya berbeda, urutkan berdasarkan prodi
		if (urutanA != urutanB) {
			return urutanA < urutanB;
		}

		// Jika prodinya sama, urutkan berdasarkan NIM (kecil ke besar)
		return a.nim < b.nim;
		});
}

// Fungsi utama
int main() {
	const int MAX_MAHASISWA = 8;
	Mahasiswa mahasiswa[MAX_MAHASISWA];
	int jumlahMahasiswa = 0;

	// Loop untuk input data
	while (jumlahMahasiswa < MAX_MAHASISWA) {
		cout << "Masukkan Data Mahasiswa ke-" << jumlahMahasiswa + 1 << endl;
		cout << "NIM: ";
		cin >> mahasiswa[jumlahMahasiswa].nim;

		cout << "Nama: ";
		cin.ignore(); // Membersihkan buffer sebelum getline
		getline(cin, mahasiswa[jumlahMahasiswa].nama);

		tentukanProdiDanJenjang(mahasiswa[jumlahMahasiswa]);
		jumlahMahasiswa++;

		char yt;
		cout << endl << "Masukkan Data Lagi (y/t)? ";
		cin >> yt;

		if (yt != 'y' && yt != 'Y') {
			break;
		}
		cout << endl;
	}

	system("CLS"); // Untuk Windows. Gunakan "clear" untuk Linux/Mac.

	// Menampilkan hasil pengurutan pertama (hanya berdasarkan NIM)
	cout << "\n------------------------------------------------------" << endl;
	cout << "   Data Mahasiswa Diurutkan Berdasarkan NIM (A-Z)   " << endl;
	cout << "------------------------------------------------------" << endl;
	urutkanBerdasarkanNim(mahasiswa, jumlahMahasiswa);
	tampilkanSemuaData(mahasiswa, jumlahMahasiswa);

	// Menampilkan hasil pengurutan kedua (sesuai permintaan utama Anda)
	cout << "\n------------------------------------------------------------------" << endl;
	cout << "   Data Diurutkan Berdasarkan Prodi (Kustom) lalu NIM (A-Z)   " << endl;
	cout << "------------------------------------------------------------------" << endl;
	urutkanBerdasarkanProdiKustomDanNim(mahasiswa, jumlahMahasiswa);
	tampilkanSemuaData(mahasiswa, jumlahMahasiswa);


	return 0;
}
