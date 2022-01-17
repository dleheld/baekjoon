//��Ʈ��ŷ�� ��ǥ���� ���� NQueen
#include <stdio.h>
#include <iostream>
using namespace std;
#define ABS(x) (x > 0 ? x : -(x))
int Row[1000] = { 0 }; //Row ���� �ش� Queen�� Col�� ����
int ans = 0;
int N;
bool promising(int q) { //�̹� ���ִ� queen��
	for (int i = 1; i < q; ++i) {
		if (Row[q] == Row[i] || ABS(Row[q] - Row[i]) == ABS(q - i))
			return false;
	}
	return true;
}
void queens(int q) {
	if (!promising(q)) return; //�߿� �������� ������ �Լ� ����x
	if (q == N) {
		ans++;
		return;
	}
	for (int i = 1; i <= N; ++i) {
		Row[q + 1] = i;
		queens(q + 1);
	}
}
int main() {
	cin >> N;
	queen(0);
	return 0;
}