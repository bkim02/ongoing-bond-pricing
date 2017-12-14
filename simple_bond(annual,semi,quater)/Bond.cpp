
#include <stdio.h>
#include <iostream>
#include <cmath>
#include "Bond.h"
using namespace std;
/////constructors///////////

Bond::Bond(double pr,double rat1,double rat2,double ytm,char typ){
	
	setPrincipal(pr);
	setMarketRate(rat1);
	setCouponRate(rat2);
	setMaturity(ytm);
	setPaymentType(typ);
}

//////setting and getting parameters for bonds
void Bond::setPrincipal(double x){
	principal=x;
	
}
double Bond::getPrincipal(){
	
	return principal;
}
void Bond::setMarketRate(double rat){

	market_rate=rat;
}
double Bond::getMarketRate(){
	return market_rate;
}
void Bond::setCouponRate(double rat){
	
	coupon_rate=rat;
}
double Bond::getCouponRate(){
	return coupon_rate;
}
void Bond::setMaturity(double mat){
	
	yearsToMaturity=mat;
}
double Bond::getMaturity(){
	return yearsToMaturity;
}

void Bond::setPaymentType(char x){
	
	paymentType=x;
}
char Bond::getPaymentType(){
	return paymentType;
}





////Actual calculating of Bond price
double Bond::getBondPrice(){
	double bondPrice=0.0;
	
	int scalingFactor=0;
	
	//================Segmentation=================
	if(getPaymentType()==Bond_annual_type){
		//annual based calculation
		scalingFactor=1;
		
	}else if(getPaymentType()==Bond_semi_annual_type){
		
		//semi-annual based
		scalingFactor=2;
		
	}else if(getPaymentType()==Bond_quater_type){
		scalingFactor=4;
		//quaterly based
	}else{
		cout<<"invalid type,start again"<<endl;
		
	}
	

	//########calculating############
	
	double coupon=getPrincipal()*(getCouponRate()/scalingFactor);
	
	double period=getMaturity()*scalingFactor;
	
 	double yield=getMarketRate()/scalingFactor;
	
	double pvCoupons=(coupon*(1-pow((1+yield),-period)))/yield;
	
	double pvRedemption=getPrincipal()*pow((1+yield),-period);
	bondPrice=pvRedemption+pvCoupons;
	
	//==================printing=================
	double arr[]={coupon,period,yield,pvCoupons,pvRedemption,bondPrice};
	string names[]={"coupon","period","yield","pvCoupons","pvRedemption","bondPrice"};

	cout<<"the Bond "<<endl;
	for(int i=0;i<6;i++){
		cout<<names[i]<<" : "<<arr[i]<<endl;
	}
	if(bondPrice>getPrincipal()){
		cout<<"Premium bond"<<endl;
	}else if(bondPrice<getPrincipal()){
		cout<<"Coupon bond"<<endl;
	}else{
		cout<<"Par bond"<<endl;
	}
	
	return bondPrice;
}
Bond::~Bond(){
	cout<<"Destruct"<<endl;
}



