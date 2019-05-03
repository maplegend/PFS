#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class BigInt{

	bool negative = false;
	std::vector<char> data;

	void normalize();
public:
	BigInt(unsigned long long n);
	BigInt(std::string str);
	BigInt();
	~BigInt();

	BigInt operator*(const BigInt& lsh) const;
	BigInt operator/(const BigInt& lsh) const;
	BigInt operator^(const BigInt& lsh) const;
	BigInt operator+(const BigInt& lsh) const;
	BigInt operator-(const BigInt& lsh) const;
	BigInt operator%(const BigInt& lsh) const;

	BigInt & operator*=(const BigInt& lsh);
	BigInt& operator/=(const BigInt& lsh);
	BigInt& operator^=(const BigInt& lsh);
	BigInt& operator+=(const BigInt& lsh);
	BigInt& operator-=(const BigInt& lsh);

	BigInt operator-() const;
	BigInt& operator++();

	bool operator>(const BigInt& lsh) const;
	bool operator<(const BigInt& lsh) const;
	bool operator>=(const BigInt& lsh) const;
	bool operator<=(const BigInt& lsh) const;
	bool operator==(const BigInt& lsh) const;
	bool operator!=(const BigInt& lsh) const;

	bool is_even() const;
	

	char& operator[](int i);
	char get(int i, bool abs = false) const;

	void add_back(char val);
	void add_back(const BigInt& val);
	void insert(const BigInt& val);

	long long value() const;
	unsigned int size() const;
	void set_negative(bool negative);
	bool is_negative() const;

	friend std::ostream& operator<<(std::ostream& out, const BigInt val);
	
};

