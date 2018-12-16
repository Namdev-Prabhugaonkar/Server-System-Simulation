
/* 
 * File:   main.cpp
 * Author: namdevprabhugaonkar
 *
 * Created on December 13, 2018, 2:42 PM
 */

#include <iostream>
#include "customer.h"

using namespace std;

//ostream& operator<< (ostream& os, customerType& c)
//{
//    os << "[#" << c.customerNumber << " ar" << c.arrivalTime << " tr"
//    		<< c.transactionTime << " srv" << c.serviceTime << "]";
//    return os;
//}


ostream& operator<< (ostream& os, customerType& c)
{
    os << "for Customer " << c.customerNumber << " whose arrival time= " << c.arrivalTime << " Transaction time= "
    		<< c.transactionTime << " and service time= " << c.serviceTime  <<". The wait time for this customer is "<<c.serviceTime-c.arrivalTime;
      
    return os;
}

// cout<<"At clock "<<clock<< " server " << i <<" starts with customer number: " <<customerType.customerNumber;
//cout<<" whose arrival time is "<<customerType.arrivalTime<<" Transacation time= "<<customerType.transactionTime<<" and service time is: "<<customerType.serviceTime<<endl;


istream& operator>> (istream& is, customerType& c)
{
    is >> c.customerNumber >> c.arrivalTime >> c.transactionTime;
    return is;
}



