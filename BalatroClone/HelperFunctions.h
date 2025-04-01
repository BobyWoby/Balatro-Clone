#pragma once
#include "BigInteger.h"


int makeEqualLength(BigInteger& num1, BigInteger& num2) { // return the length once youve made them equal
	if (num1.digitArr.size() < num2.digitArr.size()) {
		for (int i = num1.digitArr.size(); i < num2.digitArr.size(); i++) {
			//num1.digitArr[i] = 10;
			num1.digitArr.push_back(10);
		}
	}
	else if (num1.digitArr.size() > num2.digitArr.size()){
		for (int i = num2.digitArr.size(); i < num1.digitArr.size(); i++) {
			//num2.digitArr[i] = 10;
			num2.digitArr.push_back(10);
		}
	}
	return num1.digitArr.size();
}
