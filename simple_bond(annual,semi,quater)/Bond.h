
#ifndef Bond_h
#define Bond_h

class Bond{
public:
	//-------------------------Constant types-------------
	const char Bond_annual_type='A';
	const char Bond_semi_annual_type='S';
	const char Bond_quater_type='Q';
	//-------------------------Constructors------------
	Bond();
	Bond(double,double,double,double,char);//over-loading new constructor which allowed to set initial value in the main funcion.
	//---------------------------Set and get --------------
	void setPrincipal(double);
	double getPrincipal();
	void setCouponRate(double);
	double getCouponRate();
	void setMarketRate(double);
	double getMarketRate();
	void setMaturity(double);
	double getMaturity();
	void setPaymentType(char);
	char getPaymentType();
	//-----------------------------Acutal Pricer--------------
	double getBondPrice();
	
	//=============Destructor-------------------
	~Bond();
	
private:
	double principal;
	double coupon_rate;
	double market_rate;
	double yearsToMaturity;
	char paymentType; //'A':Annual 'S':semiannual 'Q':quaterly
	
	
	
};
#endif /* Bond_h */
