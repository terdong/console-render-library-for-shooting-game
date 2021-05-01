#ifndef TG__TEAMPCLASS__H
#define TG__TEAMPCLASS__H

namespace TeamGehem{

class CTeampClass
{
public:
	CTeampClass():temp_(0)
	void foo();
	int temp_;
	CTeampClass operator+ (const CTeampClass& a_temp)
	{
		temp_ += a_temp.temp_;

		CTeampClass resultClass;
		resultClass.temp_ = this->temp_;
		foo();

		return resultClass;
	}
};

void CTeampClass::foo()
{
	CTeampClass a_temp;
	a_temp.temp_ = 10;

	CTeampClass a_temp2 = this + a_temp;

	bool flag = true;
	flag = false;
}
}
#endif // TG__TEAMPCLASS__H