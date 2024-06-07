#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
int n = 0, sdh = 5;
struct DonHang {
    char MaDh[10];
    char sdtNguoiGui[15];
    char TenNguoiGui[30];
    char sdtNguoiNhan[15];
    char TenNguoiNhan[30];
    char TenSp[30];
    char GiaThanh[20];
    char TinhTrang[30];
} **dsdh, donhang, *tmp;
void Them();
void Sua();
void Xoa();
void SapXep();
void TimKiem();
void In();
void ThongKe();
void LuuDuLieu();
void DocDuLieu();
int main() {
    char ch;
    dsdh = (struct DonHang**)calloc(sdh, sizeof(struct DonHang*));
    DocDuLieu(); // Đọc dữ liệu từ tệp khi chương trình bắt đầu
    while (1) {
        system("cls");
        printf("		|-----------------------------------------|\n");
        printf("		|He Thong Quan Ly Don Hang(Giao va Nhan)  |\n");
        printf("		|-----------------------------------------|\n");
        printf("		|   1.Them Don Hang                       |\n");
        printf("		|-----------------------------------------|\n");
        printf("		|   2.Sua Don Hang                        |\n");
        printf("		|-----------------------------------------|\n");
        printf("		|   3.Xoa Don Hang                        |\n");
        printf("		|-----------------------------------------|\n");
        printf("		|   4.Sap Xep Don Hang                    |\n");
        printf("		|-----------------------------------------|\n");
        printf("		|   5.Tim Kiem Don Hang                   |\n");
        printf("		|-----------------------------------------|\n");
        printf("		|   6.In Danh Sach Don Hang               |\n");
        printf("		|-----------------------------------------|\n");
        printf("		|   7.Thong ke                            |\n");
        printf("		|-----------------------------------------|\n");
        printf("		|  Bam phim khac de ket thuc.             |\n");
        printf("		|-----------------------------------------|\n");
        fflush(stdin);
        ch = getch();
        if (ch == '1') Them();
          else if (ch == '2') Sua();
          else if (ch == '3') Xoa();
          else if (ch == '4') SapXep();
          else if (ch == '5') TimKiem();
          else if (ch == '6') In();
          else if (ch == '7') ThongKe();
        else {
            printf("BAN CO MUON KET THUC??\n");
            printf("Bam Y hoac y de ket thuc\n");
            printf("Bam phim khac de quay lai:");
            ch = getch();
            if (ch == 'Y' || ch == 'y') {
                LuuDuLieu(); // Lưu dữ liệu vào tệp khi chương trình kết thúc
                break;
            }
        }
    }
    return 0;
}
void Them() {
    while (1) {
        fflush(stdin);
        printf("don hang thu %d la:\n", n + 1);
        printf("nhap ma don hang(nhap 0 de ket thuc):");
        gets(donhang.MaDh);
        if (strcmp(donhang.MaDh, "0") == 0) break;
        printf("nhap sdt nguoi gui:");
        gets(donhang.sdtNguoiGui);
        printf("nhap ten nguoi gui:");
        gets(donhang.TenNguoiGui);
        printf("nhap ten nguoi nhan:");
        gets(donhang.TenNguoiNhan);
        printf("nhap sdt nguoi nhan:");
        gets(donhang.sdtNguoiNhan);
        printf("nhap ten san pham:");
        gets(donhang.TenSp);
        printf("nhap gia thanh san pham(VND):");
        gets(donhang.GiaThanh);
        printf("nhap tinh trang san pham:");
        gets(donhang.TinhTrang);
        dsdh[n] = (struct DonHang*)malloc(sizeof(struct DonHang));
        *(dsdh[n]) = donhang;
        n++;
        if (n >= sdh) {
            sdh += 5;
            dsdh = (struct DonHang**)realloc(dsdh, sdh * sizeof(struct DonHang*));
        }
    }
}
void Sua() {
    while (1) {
        int i, chon;
        char a;
        printf("Chon don hang ban muon sua:\n");
        for (i = 0; i < n; i++) {
            printf(" %d. %s\n", i + 1, dsdh[i]->MaDh);
        }
        printf("(Bam 0 de ket thuc:)");
        a = getch();
        if (a == '0') break;
        int c = a - '1';
        if (c < 0 || c >= n) {
            printf("\nLua chon khong hop le!\n");
            continue;  
        }
        while (1) {
            printf("\nThong tin don hang hien tai:\n");
	    printf("\n|--------------------------------|");
	    printf("\n|1.Madh:%-25s|",dsdh[c]->MaDh);
	    printf("\n|--------------------------------|");
	    printf("\n|2.sdtNguoiGui:%-18s|",dsdh[c]->sdtNguoiGui);
	    printf("\n|--------------------------------|");
	    printf("\n|3.TenNguoiGui:%-18s|",dsdh[c]->TenNguoiGui);
	    printf("\n|--------------------------------|");
	    printf("\n|4.sdtNguoiNhan:%-17s|",dsdh[c]->sdtNguoiNhan);
	    printf("\n|--------------------------------|");
	    printf("\n|5.TenNguoiNhan:%-17s|",dsdh[c]->TenNguoiNhan);
	    printf("\n|--------------------------------|");
	    printf("\n|6.TenSp:%-24s|",dsdh[c]->TenSp);
	    printf("\n|--------------------------------|");
	    printf("\n|7.GiaThanh:%-21s|",dsdh[c]->GiaThanh);
	    printf("\n|--------------------------------|");
	    printf("\n|8.TinhTrang:%-20s|",dsdh[c]->TinhTrang);
	    printf("\n|--------------------------------|");
	    printf("\n(bam 0 de ket thuc.)\n");
            chon = getch() - '0';
            if (chon == 0) break;
            fflush(stdin);
            switch (chon) {
            	case 1:
            		printf("nhap ma don hang moi:");
            		gets(dsdh[c]->MaDh);
            		break;
                case 2:
                    printf("Nhap sdt nguoi gui moi: ");
                    gets(dsdh[c]->sdtNguoiGui);
                    break;
                case 3:
                    printf("Nhap ten nguoi gui moi: ");
                    gets(dsdh[c]->TenNguoiGui);
                    break;
                case 4:
                    printf("Nhap ten nguoi nhan moi: ");
                    gets(dsdh[c]->TenNguoiNhan);
                    break;
                case 5:
                    printf("Nhap sdt nguoi nhan moi: ");
                    gets(dsdh[c]->sdtNguoiNhan);
                    break;
                case 6:
                    printf("Nhap ten san pham moi: ");
                    gets(dsdh[c]->TenSp);
                    break;
                case 7:
                    printf("Nhap gia thanh moi: ");
                    gets(dsdh[c]->GiaThanh);
                    break;
                case 8: 
                    printf("Nhap tinh trang moi: ");
                    gets(dsdh[c]->TinhTrang);
                    break;
                default:
                    printf("Lua chon khong hop le\n");
                    continue;
            }
            system("cls");
        }
    }
}
void Xoa() {
    while (1) {
        char ch;
        int i;
        printf("Chon don hang ban muon xoa:\n");
        for (i = 0; i < n; i++) {
            printf(" %d. %s\n", i + 1, dsdh[i]->MaDh);
        }
        printf("(Bam 0 de quay lai)\n");
        ch = getch();
        if (ch == '0') break;
        int c = ch - '1';
        if (c < 0 || c >= n) {
            printf("\nLua chon khong hop le!\n");
            continue;
        }

        free(dsdh[c]);
        for (i = c; i < n - 1; i++) {
            dsdh[i] = dsdh[i + 1];
        }
        n--;
        printf("\nDon hang da xoa thanh cong\n");
        getch();
    }
}
void SapXep(){
    while(1){
        char ch;
        int i,j;
        printf("1.Sap xep theo gia thanh tang dan.\n");
        printf("2.Sap xep theo gia thanh giam dan.\n");
        printf("3.Sap xep theo ten san pham theo thu tu ABC .\n");
        printf("(bam 0 de quay lai)\n");
        ch=getch();
        if(ch=='0') break;
        int c= ch-'0';
        switch(c){
            case 1:
                for(i=0;i<n-1;i++)
                    for(j=i+1;j<n;j++)
                        if(atoi(dsdh[i]->GiaThanh) > atoi(dsdh[j]->GiaThanh)){
                            tmp = dsdh[i];
                            dsdh[i] = dsdh[j];
                            dsdh[j] = tmp;
                        }
                printf("da sap xep thanh cong.\n");
                break;
            case 2:
                for(i=0;i<n-1;i++)
                    for(j=i+1;j<n;j++)
                        if(atoi(dsdh[i]->GiaThanh) < atoi(dsdh[j]->GiaThanh)){
                            tmp = dsdh[i];
                            dsdh[i] = dsdh[j];
                            dsdh[j] = tmp;
                        }
                printf("da sap xep thanh cong.\n");
                break;
            case 3:
                for(i=0;i<n-1;i++)
                    for(j=i+1;j<n;j++)
                        if(strcmp(dsdh[i]->TenSp, dsdh[j]->TenSp) > 0){
                            tmp = dsdh[i];
                            dsdh[i] = dsdh[j];
                            dsdh[j] = tmp;
                        }
                printf("da sap xep thanh cong.\n");
                break;
            default:
                printf("hay lua chon lai:\n");
                continue;
        }
        printf("bam phim bat ki de quay lai.");
        getch();
        break;
    }
}
void In(){
    system("cls");
    int i;
    printf("\ndanh sach cac don hang la:");
    for(i=0;i<n;i++){
    printf("\n|--------------------------------|");
    printf("\n|Madh:%-27s|",dsdh[i]->MaDh);
    printf("\n|--------------------------------|");
    printf("\n|sdtNguoiGui:%-20s|",dsdh[i]->sdtNguoiGui);
    printf("\n|--------------------------------|");
    printf("\n|TenNguoiGui:%-20s|",dsdh[i]->TenNguoiGui);
    printf("\n|--------------------------------|");
    printf("\n|sdtNguoiNhan:%-19s|",dsdh[i]->sdtNguoiNhan);
    printf("\n|--------------------------------|");
    printf("\n|TenNguoiNhan:%-19s|",dsdh[i]->TenNguoiNhan);
    printf("\n|--------------------------------|");
    printf("\n|TenSp:%-26s|",dsdh[i]->TenSp);
    printf("\n|--------------------------------|");
    printf("\n|GiaThanh:%-23s|",dsdh[i]->GiaThanh);
    printf("\n|--------------------------------|");
    printf("\n|TinhTrang:%-22s|",dsdh[i]->TinhTrang);
    printf("\n|--------------------------------|");
}
    printf("\n(bam phim bat ky de thoat)\n");
    getch();
}

void TimKiem(){
    char tk[30];
    printf("\nNhap noi dung ban muon tim kiem:");
    gets(tk);
    system("cls");
    printf("\nKet qua tim kiem:\n");
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(dsdh[i]->MaDh, tk) || strstr(dsdh[i]->TenNguoiGui, tk) ||
            strstr(dsdh[i]->TenNguoiNhan, tk) || strstr(dsdh[i]->TenSp, tk) ||
            strstr(dsdh[i]->sdtNguoiGui, tk) || strstr(dsdh[i]->sdtNguoiNhan, tk) ||
            strstr(dsdh[i]->GiaThanh, tk) || strstr(dsdh[i]->TinhTrang, tk)) {
            printf("\n|--------------------------------|");
    printf("\n|Madh:%-27s|",dsdh[i]->MaDh);
    printf("\n|--------------------------------|");
    printf("\n|sdtNguoiGui:%-20s|",dsdh[i]->sdtNguoiGui);
    printf("\n|--------------------------------|");
    printf("\n|TenNguoiGui:%-20s|",dsdh[i]->TenNguoiGui);
    printf("\n|--------------------------------|");
    printf("\n|sdtNguoiNhan:%-19s|",dsdh[i]->sdtNguoiNhan);
    printf("\n|--------------------------------|");
    printf("\n|TenNguoiNhan:%-19s|",dsdh[i]->TenNguoiNhan);
    printf("\n|--------------------------------|");
    printf("\n|TenSp:%-26s|",dsdh[i]->TenSp);
    printf("\n|--------------------------------|");
    printf("\n|GiaThanh:%-23s|",dsdh[i]->GiaThanh);
    printf("\n|--------------------------------|");
    printf("\n|TinhTrang:%-22s|",dsdh[i]->TinhTrang);
    printf("\n|--------------------------------|");
            found = 1;
        }
    }
    if (!found) {
        printf("\nKhong tim thay don hang phu hop\n");
    }
    printf("\nBam phim bat ky de thoat\n");
    getch();
}

void ThongKe(){
    while(1){
        char ch;
        int i,b,c;
        printf("1.Thong ke so don hang theo gia thanh tu X(VND) den Y(VND).\n");
        printf("2.Thong ke so san pham theo trang thai.\n");
        printf("(Bam 0 de quay lai.)\n");
        ch=getch();
        if(ch=='0') break;
        c=ch-'0';
        b=ch-'1';
        switch(c){
            case 1:
                // Chức năng thống kê theo giá thành chưa được thực hiện
                break;
            case 2:
                // Chức năng thống kê theo trạng thái chưa được thực hiện
                break;
            default:
                printf("hay lua chon lai:\n");
                continue;
        }
    }
}

void LuuDuLieu() {
    FILE *file = fopen("donhang.txt", "w");
    if (file == NULL) {
        printf("Khong the mo file de ghi du lieu!\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s\n",
                dsdh[i]->MaDh,
                dsdh[i]->sdtNguoiGui,
                dsdh[i]->TenNguoiGui,
                dsdh[i]->sdtNguoiNhan,
                dsdh[i]->TenNguoiNhan,
                dsdh[i]->TenSp,
                dsdh[i]->GiaThanh,
                dsdh[i]->TinhTrang);
    }
    fclose(file);
}

void DocDuLieu() {
    FILE *file = fopen("donhang.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file de doc du lieu!\n");
        return;
    }
    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                  donhang.MaDh,
                  donhang.sdtNguoiGui,
                  donhang.TenNguoiGui,
                  donhang.sdtNguoiNhan,
                  donhang.TenNguoiNhan,
                  donhang.TenSp,
                  donhang.GiaThanh,
                  donhang.TinhTrang) != EOF) {
        dsdh[n] = (struct DonHang*)malloc(sizeof(struct DonHang));
        *(dsdh[n]) = donhang;
        n++;
        if (n >= sdh) {
            sdh += 5;
            dsdh = (struct DonHang**)realloc(dsdh, sdh * sizeof(struct DonHang*));
        }
    }
    fclose(file);
}
