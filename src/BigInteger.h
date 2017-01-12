#ifndef BIGDINTEGER_H
#define BIGDINTEGER_H

#include <vector>
#include <ostream>
#include <string>

class BigInteger
{
	public:
	
		/*constructors*/
		BigInteger(int,unsigned,int);
		BigInteger(const BigInteger&);	//copy constructor
		BigInteger(BigInteger&&);	//move constructor
		~BigInteger();
		
		/*unary arithimetic operators*/
		BigInteger operator+(const BigInteger&)const;
		BigInteger operator-(const BigInteger&)const;
		BigInteger operator*(const BigInteger&)const;
		BigInteger operator/(const BigInteger&)const;
		BigInteger operator%(const BigInteger&)const;
		BigInteger& operator^(const int);
		
		/*assignment operators*/
		BigInteger& operator=(const BigInteger&); //copy assignment
		BigInteger& operator=(BigInteger&&);	//move assignment
		
		/*increment and decrement operators*/
		BigInteger& operator++(); //pre-increment
		BigInteger operator++(int);	//post-increment
		BigInteger& operator--();	//pre-decrement
		BigInteger operator--(int);	//post-decrement
		
		/*binary arithimetic operators*/
		BigInteger& operator+=(const BigInteger&);
		BigInteger& operator-=(const BigInteger&);
	  BigInteger& operator*=(const BigInteger&);
		BigInteger& operator/=(const BigInteger&);
		BigInteger& operator%=(const BigInteger&);
		
		/*comparison operators*/
		inline bool operator<(const BigInteger&)const;
		inline bool operator>(const BigInteger&)const;
		inline bool operator<=(const BigInteger&)const;
		inline bool operator>=(const BigInteger&)const;
		inline bool operator==(const BigInteger&)const;
		inline bool operator!=(const BigInteger&)const;
		
		/*bit shift operator*/
		std::ostream& operator<<(std::ostream& os); //class console output
		
		
	private:
	
	//member functions
	template<typename T>
	inline std::string to_string(T&);
	BigInteger add(const BigInteger&);
	BigInteger subtract(const BigInteger&);
	BigInteger multiply(const BigInteger&);
	BigInteger divide(const BigInteger&);
	BigInteger modulo(const BigInteger&);
	BigInteger& power(const int);
	
	bool equal(const BigInteger& rhs);
	bool less_than(const BigInteger& rhs);
		
	//data members
	std::vector<int>* fData;
	unsigned fLength;
	unsigned fBase;
	int fMax_Size;
	int fStart;
};

inline bool BigInteger::operator<(const BigInteger& rhs)const
{
	BigInteger tmp(*this);
	return (tmp.less_than(rhs));
}

inline bool BigInteger::operator>(const BigInteger& rhs)const
{
	return (rhs<*this);
}

inline bool BigInteger::operator<=(const BigInteger& rhs)const
{
	return !(*this>rhs);
}

inline bool BigInteger::operator>=(const BigInteger& rhs)const
{
	return !(*this<rhs);
}

inline bool BigInteger::operator==(const BigInteger& rhs)const
{
	BigInteger tmp(*this);
	return (tmp.equal(rhs));
}

inline bool BigInteger::operator!=(const BigInteger& rhs)const
{
	return !(*this==rhs);
}

#endif //BIGINTEGER_H