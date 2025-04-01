#include "BigInteger.h"
#include "HelperFunctions.h"
#include <sstream>

BigInteger BigInteger::operator+(BigInteger const& num) {
	BigInteger res;
	int i = 0, carry = 0;
	BigInteger op1 = (num.digitArr.size() > this->digitArr.size()) ? num : *this;
	BigInteger op2 = (num.digitArr.size() <= this->digitArr.size()) ? num : *this;

	for (int i = 0; i < op1.digitArr.size(); i++) {
		int dig = 0, n = 0;
		if (i >= op2.digitArr.size()) {
			n = op1.digitArr.at(i);
		}
		else {
			n = op1.digitArr.at(i) + op2.digitArr.at(i);
		}

		dig = n % 10;
		if (res.digitArr.size() == 1 && i == 0) {
			res.digitArr.at(0) = n + carry;
		}
		else {
			res.digitArr.push_back(n + carry);
		}
		carry = n / 10;
	}
	return res;
}

BigInteger BigInteger::operator-(BigInteger const& num) {
	BigInteger res;
	int i = 0, carry = 0;
	return res;
}

BigInteger BigInteger::operator*(BigInteger const& num)
{
	BigInteger res(true);
	int digit = 0, carry = 0;
	for (int i = 0; i < this->digitArr.size(); i++) {
		carry = 0;
		int j = i;
		for (; j < num.digitArr.size() + i; j++) {
			digit = 0 + (this->digitArr.at(i) * num.digitArr.at(j - i)) + carry;
			carry = digit / 10;

			if (j >= res.digitArr.size()) {
				res.digitArr.push_back(digit % 10);
			}
			else {
				res.digitArr.at(j) = digit % 10;
			}
		}
		if (carry) {
			digit = res.digitArr.at(j) + carry;
			res.digitArr.at(j) = digit % 10;
		}
	}
	//check if its all 0s
	int zeros = 0;
	for (auto d : res.digitArr) {
		if (!d) zeros++;
	}
	if (zeros >= res.digitArr.size()) {
		res = BigInteger(0);
	}
	return res;
}

std::string BigInteger::getString()
{
	std::string out = "";
	std::stringstream ss{};
	for (uint8_t digit : digitArr) {
		out = std::to_string(digit) + out;
	}
	if (this->digitArr.size() > 12) {
		int exp = this->digitArr.size();
		std::string tmp = "";
		tmp += out[0];
		tmp += "." + out.substr(1, 4);
		out = tmp + "e" + std::to_string(this->digitArr.size() - 1);
	}
	return out;
}



// Karatsuba algorithm WIP
//BigInteger BigInteger::operator*(BigInteger const& num)
//{
//	BigInteger tmp = num;
//
//	int length = makeEqualLength(*this, tmp);
//	if (length == 0) return BigInteger();
//	if (length == 1) {
//
//		return BigInteger(digitArr.at(0) * tmp.digitArr.at(0));
//	}
//	std::vector<uint8_t> res = { 0 };
//	BigInteger
//		X0(std::vector<uint8_t>(this->digitArr.begin(), this->digitArr.begin() + this->digitArr.size() / 2)),
//		Y0(std::vector<uint8_t>(tmp.digitArr.begin(), tmp.digitArr.begin() + tmp.digitArr.size() / 2)),
//
//		X1(std::vector<uint8_t>(this->digitArr.begin() + this->digitArr.size() / 2, this->digitArr.end())),
//		Y1(std::vector<uint8_t>(tmp.digitArr.begin() + tmp.digitArr.size() / 2, tmp.digitArr.end()));
//
//	BigInteger sum1 = X0 + X1, sum2 = Y0 + Y1, lengthScalar = BigInteger(pow(10, length)), lengthScalar2 = BigInteger(pow(10, length / 2));
//	BigInteger p = sum1 * sum2;
//	BigInteger X1Y1 = X1 * Y1;
//	BigInteger X0Y0 = X0 * Y0;
//
//	//BigInteger res = (X1Y1 * lengthScalar) + (p - );
//	return BigInteger();
//
//}