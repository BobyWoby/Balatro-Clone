#pragma once
#include <cstdint>
#include <memory>
#include <vector>
#include <iostream>

class BigInteger
{
public:
	std::vector<uint8_t> digitArr;
	BigInteger() {
		
		digitArr = {0};
	}
	BigInteger(bool empty) {
		if (empty) {
			digitArr = {};
			return;
		}
		else {
			digitArr = { 0 };
		}

	}
	BigInteger(int num) {
		if (!num) {
			digitArr = { 0 };
			return;
		}
		for (int i = 1; i <= num; i *= 10) {
			digitArr.push_back((num / i) % 10);
		}
	}
	BigInteger(std::vector<uint8_t> num) {
		digitArr = num;
	}
	

	BigInteger operator+(BigInteger const& num);
	BigInteger operator-(BigInteger const& num);
	BigInteger operator*(BigInteger const& num);
	std::string getString();
	
};
