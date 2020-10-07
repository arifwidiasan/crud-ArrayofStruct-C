#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data_mahasiswa{
	char npm[12];
	char nama[50];
	char kota[50];
	char nohp[50];
	char umur[4];
	char jurusan[50];
	char semester[4];
};
typedef struct data_mahasiswa mhs;

mhs data[50];

int size=0,x;
void tambah(char npm[12],char nama[50],char kota[50], char nohp[50], char umur[4], char jurusan[50], char semester[4]){
	strcpy(data[size].npm,npm);
	strcpy(data[size].nama,nama);
	strcpy(data[size].kota,kota);
	strcpy(data[size].nohp,nohp);
	strcpy(data[size].umur,umur);
	strcpy(data[size].jurusan,jurusan);
	strcpy(data[size].semester,semester);
	size++;
}

void tampil(){
	int i;
	if(size>0){
		for(i=1;i<size;i++){
			x=strlen(data[i].npm);
			if(x>=1){
			printf("\nMahasiswa ke - [%d]\n",i);
			printf("NPM \t\t\t: %s\n",data[i].npm);	
			printf("Nama \t\t\t: %s\n",data[i].nama);
			printf("Kota \t\t\t: %s\n",data[i].kota);
			printf("No HP \t\t\t: %s\n",data[i].nohp);
			printf("Umur \t\t\t: %s\n",data[i].umur);
			printf("Jurusan \t\t: %s\n",data[i].jurusan);
			printf("Semester \t\t: %s\n\n",data[i].semester);	
			}
		}
	}
}
int main() {
	size = sizeof(mhs)/sizeof(data[0]);
	int i=1;
	int pilih=0,pilih_edit;
	char npm[12],nama[50],kota[50],nohp[14],umur[4],jurusan[50],semester[3];
	awal:
	printf("====== Data Mahasiswa ======\n");
	printf("Menu :\n1. Tampil Data\n2. Tambah Data\n3. Update Data\n4. Hapus Data\n5. Keluar\nPilih menu : ");
	scanf("%d",&pilih);
	if(pilih==1){
		printf("List Data Mahasiswa: \n\n");
		tampil();
		printf("\nTekan sembarang tombol untuk lanjut");
		getch();
		system("cls");
		goto awal;
	}
	else if(pilih==2){
		printf("\nNPM : ");
		scanf("%s",&npm);
		printf("Nama : ");
		scanf(" %[^\n]s",&nama);
		printf("Kota : ");
		scanf("%s",&kota);
		printf("No HP : ");
		scanf("%s",&nohp);
		printf("Umur : ");
		scanf("%s",&umur);
		printf("Jurusan : ");
		scanf("%s",&jurusan);
		printf("Semester : ");
		scanf("%s",&semester);
		tambah(npm,nama,kota,nohp,umur,jurusan,semester);
		printf("\nData Berhasi Ditambahkan!");
		getch();
		system("cls");
		goto awal;	
	}else if(pilih==3){
		int no;
		tampil();
		printf("Masukkan nomor data mahasiswa ke-[x] yang ingin diedit : ");
		inputedit:
		scanf("%d",&no);
		if(no>size){
			printf("Tidak ada data mahasiswa nomor ke %d, mohon masukkan nomor kembali : ");
			goto inputedit;
		}else{
			system("cls");
			printf("======Pengeditan Data Mahasiswa======");
			printf("\nNPM \t\t\t: %s\n",data[no].npm);	
			printf("Nama \t\t\t: %s\n",data[no].nama);
			printf("Kota \t\t\t: %s\n",data[no].kota);
			printf("No HP \t\t\t: %s\n",data[no].nohp);
			printf("Umur \t\t\t: %s\n",data[no].umur);
			printf("Jurusan \t\t: %s\n",data[no].jurusan);
			printf("Semester \t\t: %s\n\n",data[no].semester);
			printf("\nPilih data yang ingin diedit sesuai nomor (1.npm;2.nama;3.kota;4.no hp;5.umur;6.jurusan;7.semester) = ");
			scanf("%d",&pilih_edit);
			if(pilih_edit==1){
				printf("\nNPM : ");
				scanf(" %[^\n]%*c",data[no].npm);
			}
			else if(pilih_edit==2){
				printf("\nNama : ");
				scanf(" %[^\n]%*c",data[no].nama);	
			}
			else if(pilih_edit==3){
				printf("\nKota : ");
				scanf(" %[^\n]%*c",data[no].kota);	
			}
			else if(pilih_edit==4){
				printf("\nNo HP : ");
				scanf(" %[^\n]%*c",data[no].nohp);	
			}
			else if(pilih_edit==5){
				printf("\nUmur : ");
				scanf(" %[^\n]%*c",data[no].umur);	
			}
			else if(pilih_edit==6){
				printf("\nJurusan : ");
				scanf(" %[^\n]%*c",data[no].jurusan);	
			}
			else if(pilih_edit==7){
				printf("\nSemester : ");
				scanf(" %[^\n]%*c",data[no].semester);	
			}else{
				printf("\npilihan salah");
			}
			printf("\nData berhasil diedit !");
			getch();
			system("cls");
			goto awal;
		}
	}else if(pilih==4){
		int no;
		tampil();
		printf("\nMasukkan nomor data yang akan dihapus : ");
		inputhapus:
		scanf("%d",&no);
		if(no>size){
			printf("Tidak ada data mahasiswa nomor ke %d, mohon masukkan kembali : ");
			goto inputhapus;
		}else{
			for(no;no<size;no++){
			strcpy(data[no].npm,data[no+1].npm);
			strcpy(data[no].nama,data[no+1].nama);
			strcpy(data[no].kota,data[no+1].kota);
			strcpy(data[no].nohp,data[no+1].nohp);
			strcpy(data[no].umur,data[no+1].umur);
			strcpy(data[no].jurusan,data[no+1].jurusan);
			strcpy(data[no].semester,data[no+1].semester);
		}
			printf("data berhasil dihapus");
			getch();
			system("cls");
			goto awal;
		}
	}else if(pilih==5){
		printf("\nTerima Kasih!");
	}else{
		printf("Inputan anda salah.");
	}
	return 0;
}
