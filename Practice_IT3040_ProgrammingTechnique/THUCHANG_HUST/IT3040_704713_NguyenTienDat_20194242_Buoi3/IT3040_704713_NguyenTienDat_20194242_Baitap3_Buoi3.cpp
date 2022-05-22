#include <iostream>
using namespace std;
#define MAX 100  

int cmin = INT_MAX; //# chi ph� di l?i nh? nh?t gi?a hai th�nh ph? kh�c nhau | du thua???

int n, c[MAX][MAX]; //# s? th�nh ph? v� ma tr?n chi ph�
int best = INT_MAX; //# t?ng chi ph� nh? nh?t c?n t�m, ban d?u d?t b?ng gi� tr? v� c�ng l?n INT_MAX = 2^31-1
int curr = 0; //# t?ng chi ph� t?i th?i di?m hi?n t?i
int mark[MAX]; //# d�nh d?u nh?ng th�nh ph? d� di
int x[MAX]; //# luu gi? c�c th�nh ph? d� di

//# �?c d? li?u v�o
void input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
    for(int i=0; i<MAX; i++) mark[i] = 0;
}



bool isUCV(int j) {
	if (mark[j] == 1) return false;
	return true;
}

//# Thu?t to�n quay lui
void TRY(int k){
    for(int i = 2; i <= n; i++){
		// code here
        if (isUCV(i)) {
        	x[k] = i;
        	mark[i] = 1;
			curr += c[x[k-1]][x[k]];
			// loi giai bo phan cap cuoi, 
			// tinh them chi phi quay tro ve thanh pho 1
			if (k == n) {
				curr += c[x[k]][1]; // tong chi phi cuoi cung;
				best = (best > curr ? curr : best);
				curr -= c[x[k]][1]; // lay xog 1 nhanh, tro lai trang thai cu
			}
			else TRY(k+1);
			
			// thuc hien xog 1 loi giai khoi phuc trang thai ban dau
			mark[i] = 0;
			curr -= c[x[k-1]][x[k]];
		}
    }
}

int main() {
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n");
    input();
    x[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}


// chua bai

//#include <bits/stdc++.h>
//using namespace std;
//#define MAX 100  
//
//int n, c[MAX][MAX]; //# s? th�nh ph? v� ma tr?n chi ph�
//int cmin = INT_MAX; //# chi ph� di l?i nh? nh?t gi?a hai th�nh ph? kh�c nhau
//int best = INT_MAX; //# t?ng chi ph� nh? nh?t c?n t�m, ban d?u d?t b?ng gi� tr? v� c�ng l?n INT_MAX = 2^31-1
//int curr; //# t?ng chi ph� t?i th?i di?m hi?n t?i
//int mark[MAX]; //# d�nh d?u nh?ng th�nh ph? d� di
//int x[MAX]; //# luu gi? c�c th�nh ph? d� di
//
////# �?c d? li?u v�o
//void input(){
//    cin >> n;
//    for (int i = 1; i <= n; ++i)
//        for (int j = 1; j <= n; ++j){
//            cin >> c[i][j];
//            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
//        }
//}
//
////# Thu?t to�n quay lui
//void TRY(int k){
//	// buoc neo de quy
//	if (curr >= best) return;
//	if (k > n) {
//		best = curr;
//		return;
//	}
//    for(int i = 2; i <= n; i++){
//        /*****************
//        # YOUR CODE HERE #
//        *****************/
//        if (mark[i] == 1) continue;
//        // cap nhat trang thai moi
//        mark[i] = 1;
//        x[k] = i;
//        curr += c[x[k-1]][i];
//        if (k==n) curr += c[i][1];
//        
//        TRY(k+1);
//        // quay lai trang thai cu
//        mark[i] = 0;
//        curr -= c[x[k-1]][i];
//        if (k==n) curr -= c[i][1];
//    }
//}
//
//int main() {
//    input();
//    x[1] = 1;
//    TRY(2);
//    cout << best;
//    return 0;
//}
