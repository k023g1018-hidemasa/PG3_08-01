
#include <stdio.h>
#include<string>
#include<chrono>

void MemoryCopy(std::string& str, std::string& str2) {
	auto start = std::chrono::high_resolution_clock::now();//開始時間
	 str2 = str;//str2をコピー
	auto end= std::chrono::high_resolution_clock::now();

	
	double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	//処理に要した時間をミリ秒に変換
	printf_s("コピーの時間::%lf\n", elapsed);

	
}
void MemoryMove(std::string& str, std::string& str2) {
	auto start = std::chrono::high_resolution_clock::now();//開始時間
	
	//std::string str2 = std::move(str);//str3にstrの中身をムーブ、この後strの利用は保証されない
	str2=(std::move(str));


	auto end = std::chrono::high_resolution_clock::now();


	double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	//処理に要した時間をミリ秒に変換
	printf_s("ムーブの時間::%lf\n", elapsed);
}


//std::chrono::microseconds

int main() {

	std::string str1(1000000000, 'a');
	std::string str2;
	std::string str3;

	MemoryCopy(str1,str2);

	MemoryMove(str1, str3);


	return 0;
}