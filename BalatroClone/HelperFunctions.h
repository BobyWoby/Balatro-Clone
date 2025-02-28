#pragma once

void add(int* num1, int* num2, int* out) {
	for (int i = 0; i < 0xfff - 1; i++) {
		if (num1[i] + num2[i] > 10) {
			out[i + 1] = (num1[i] + num2[i]) / 10;
			out[i] = (num1[i] + num2[i]) % 10;
		}
	}
}

void add(int* num1, int* num2, int* out) {
	for (int i = 0; i < 0xfff - 1; i++) {
		if (num1[i] + num2[i] > 10) {
			out[i + 1] = (num1[i] + num2[i]) / 10;
			out[i] = (num1[i] + num2[i]) % 10;
		}
	}
}

