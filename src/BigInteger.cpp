#include "BigInteger.h"
#include <thread>
#include <sstream>
using namespace std;

BigInteger::BigInteger(int start=0,unsigned base=10,int max_size=100)
							:fBase(base),fMax_Size(max_size),fStart(start)
{
	fData=new vector<int>;
	string tmp=to_string(start);
	for(unsigned i=0;i<tmp.size();++i)
		fData->push_back(tmp.at(i)-48);
	fLength=fData->size();
}

BigInteger::~BigInteger()
{
	delete fData;
}

BigInteger::BigInteger(const BigInteger& rhs)
:fLength(move(rhs.fLength)),fBase(rhs.fBase),fMax_Size(rhs.fMax_Size),fStart(rhs.fStart)
{
		delete fData;
		fData=rhs.fData;
}

BigInteger::BigInteger(BigInteger&& rhs)
:fLength(move(rhs.fLength)),fBase(move(rhs.fBase)),fMax_Size(move(rhs.fMax_Size)),fStart(move(rhs.fStart))
{
	delete fData;
	fData=move(rhs.fData);
	rhs.fData=nullptr;
	rhs.fBase=0;
	rhs.fMax_Size=0;
	rhs.fStart=0;
	rhs.fLength=0;
}

BigInteger& BigInteger::operator=(const BigInteger& rhs)
{
	if(this!=&rhs)
	{
		delete fData;
		fData=rhs.fData;
		fLength=rhs.fLength;
		fBase=rhs.fBase;
		fMax_Size=rhs.fMax_Size;
		fStart=rhs.fStart;
	}
	return *this;
}

BigInteger& BigInteger::operator=(BigInteger&& rhs)
{
	if(this!=&rhs)
	{
		delete fData;
		fData=rhs.fData;		 			rhs.fData=nullptr;
		fLength=rhs.fLength;			rhs.fLength=0;
		fBase=rhs.fBase;					rhs.fBase=0;
		fMax_Size=rhs.fMax_Size;	rhs.fMax_Size=0;
		fStart=rhs.fStart;				rhs.fStart=0;
	}
	return *this;
}

BigInteger BigInteger::operator+(const BigInteger& rhs)const
{
	BigInteger tmp(*this);
	return tmp.add(rhs);
}

BigInteger BigInteger::operator-(const BigInteger& rhs)const
{
	BigInteger tmp(*this);
	return tmp.subtract(rhs);
}

BigInteger BigInteger::operator*(const BigInteger& rhs)const
{
	BigInteger tmp(*this);
	return tmp.multiply(rhs);
}

BigInteger BigInteger::operator/(const BigInteger& rhs)const
{
	BigInteger tmp(*this);
	return tmp.divide(rhs);
}

BigInteger BigInteger::operator%(const BigInteger& rhs)const
{
	BigInteger tmp(*this);
	return tmp.modulo(rhs);
}

BigInteger& BigInteger::operator^(const int power)
{
	return this->power(power);
}

BigInteger& BigInteger::operator+=(const BigInteger& rhs)
{
	BigInteger tmp(*this);
	return *this=move(tmp.add(rhs));
}

BigInteger& BigInteger::operator-=(const BigInteger& rhs)
{
	BigInteger tmp(*this);
	return *this=move(tmp.subtract(rhs));
}

BigInteger& BigInteger::operator*=(const BigInteger& rhs)
{
	BigInteger tmp(*this);
	return *this=move(tmp.multiply(rhs));
}

BigInteger& BigInteger::operator/=(const BigInteger& rhs)
{
	BigInteger tmp(*this);
	return *this=move(tmp.divide(rhs));
}

BigInteger& BigInteger::operator%=(const BigInteger& rhs)
{
	BigInteger tmp(*this);
	return *this=move(tmp.modulo(rhs));
}

BigInteger& BigInteger::operator++()
{
	BigInteger tmp(1,10,1);
	*this+=tmp;
	return *this;
}

BigInteger BigInteger::operator++(int)
{
	BigInteger tmp(*this);
	++*this;
	return tmp;
}

BigInteger& BigInteger::operator--()
{
	BigInteger tmp(1,10,1);
	*this-=tmp;
	return *this;
}

BigInteger BigInteger::operator--(int)
{
	BigInteger tmp(*this);
	--*this;
	return tmp;
}

ostream& BigInteger::operator<<(ostream& out)
{
	for(unsigned i=0; i<fLength; ++i)out<< fData->at(i);
	return out;
}

template<typename T>
inline string BigInteger::to_string(T& t)
{
	ostringstream tmp;
	tmp<<t;
	return tmp.str();
}

BigInteger BigInteger::add(const BigInteger& rhs)
{
	BigInteger tmp;
	//if(tmp.fLength==rhs.fLength)
	return tmp;
}

BigInteger BigInteger::subtract(const BigInteger& rhs)
{
	BigInteger tmp;
	return tmp;
}

BigInteger BigInteger::multiply(const BigInteger& rhs)
{
	BigInteger tmp;
	return tmp;
}

BigInteger BigInteger::divide(const BigInteger& rhs)
{
	BigInteger tmp;
	return tmp;
}

BigInteger BigInteger::modulo(const BigInteger& rhs)
{
	BigInteger tmp;
	return tmp; 
}

BigInteger& BigInteger::power(const int power)
{
	BigInteger tmp;
	return *this;
}
