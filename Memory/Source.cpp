#include <iostream>
#include <ctime>

using namespace std;

void Fill(int arr[], const int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\t';
	}
	cout << endl;
}
void back_add(int*& arr,int& n, int a) {
	int* buff = new int[n + 1];
	for (int i = 0; i < n; i++) {
		buff[i] = arr[i];
	}
	delete[] arr;
	arr = buff;
	arr[n] = a;
	n++;
}
void front_add(int*& arr, int& n, int a) {
	int* buff = new int[n+1];
	for (int i = 0; i < n; i++) {
		buff[i+1] = arr[i];
	}
	delete[] arr;
	arr = buff;
	arr[0] = a;
	n++;
}

void main() {
	srand(time(0));
	int n = 5;
	int a;
	int* arr = new int[n];
	Fill(arr, n);
	Print(arr, n);
	cout << "Additional element:"; cin >> a;
	front_add(arr, n, a);
	back_add(arr, n, a);
	Print(arr, n);
	delete[] arr;
}