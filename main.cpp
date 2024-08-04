
#include <stdio.h>
#include<string>
#include<chrono>

void MemoryCopy(std::string& str, std::string& str2) {
	auto start = std::chrono::high_resolution_clock::now();//�J�n����
	 str2 = str;//str2���R�s�[
	auto end= std::chrono::high_resolution_clock::now();

	
	double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	//�����ɗv�������Ԃ��~���b�ɕϊ�
	printf_s("�R�s�[�̎���::%lf\n", elapsed);

	
}
void MemoryMove(std::string& str, std::string& str2) {
	auto start = std::chrono::high_resolution_clock::now();//�J�n����
	
	//std::string str2 = std::move(str);//str3��str�̒��g�����[�u�A���̌�str�̗��p�͕ۏ؂���Ȃ�
	str2=(std::move(str));


	auto end = std::chrono::high_resolution_clock::now();


	double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	//�����ɗv�������Ԃ��~���b�ɕϊ�
	printf_s("���[�u�̎���::%lf\n", elapsed);
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