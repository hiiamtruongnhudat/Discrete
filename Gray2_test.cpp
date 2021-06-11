// C++ program for Binary To Gray
// and Gray to Binary conversion
#include <bits/stdc++.h>
using namespace std;

// Helper function to xor two characters
char xor_c(char a, char b) { return (a == b) ? '0' : '1'; }

// Helper function to flip the bit
char flip(char c) { return (c == '0') ? '1' : '0'; }

// function to convert binary string
// to gray string
string binarytoGray(string binary)
{
	string gray = "";

	// MSB of gray code is same as binary code
	gray += binary[0];

	// Compute remaining bits, next bit is comuted by
	// doing XOR of previous and current in Binary
	for (int i = 1; i < binary.length(); i++) {
		// Concatenate XOR of previous bit
		// with current bit
		gray += xor_c(binary[i - 1], binary[i]);
	}

	return gray;
}

// function to convert gray code string
// to binary string
string graytoBinary(string gray)
{
	string binary = "";

	// MSB of binary code is same as gray code
	binary += gray[0];
	// binary = "0";
	// Compute remaining bits
	for (int i = 1; i < gray.length(); i++) {
		// If current bit is 0, concatenate
		// previous bit
		if (gray[i] == '0')
			binary += binary[i - 1];

		// Else, concatenate invert of
		// previous bit
		else
		// char flip(char c) { return (c == '0') ? '1' : '0'; }
			binary += flip(binary[i - 1]);
		/*
		0 1 1 0 1
		0
		i = 1; gray[1] =1 ;
		flip(0) ->1 => binary = 01;
		i = 2; gray[2] = 1;
		filip(1) -> 0 => binary = 010
		i = 3; gray[3] = 0;
		=> binary = 0100
		i =4; gray[4] = 1;
		flip(binary[3] = 0) -> binary = 01001
		*/
	}
	return binary;
}

// Driver program to test above functions


int main()
{
	// string binary = "01001";
	cout << binarytoGray("01001");
	// int t; cin >> t;
	// while ( t-- )
	// {
		// string binary;
		// cin >> binary;
		// cout << binarytoGray(binary) << endl;
	// }
	return 0;
}
