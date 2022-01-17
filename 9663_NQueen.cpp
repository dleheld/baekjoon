//백트래킹의 대표적인 문제 NQueen
#include <stdio.h>
#include <iostream>
using namespace std;
#define ABS(x) (x > 0 ? x : -(x))
int Row[1000] = { 0 }; //Row 값엔 해당 Queen의 Col이 들어간다
int ans = 0;
int N;
bool promising(int q) { //이미 놔있는 queen들
	for (int i = 1; i < q; ++i) {
		if (Row[q] == Row[i] || ABS(Row[q] - Row[i]) == ABS(q - i))
			return false;
	}
	return true;
}
void queens(int q) {
	if (!promising(q)) return; //중요 유망하지 않으면 함수 실행x
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