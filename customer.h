/* 
 * File:   customer.h
 * Author: namdevprabhugaonkar
 *
 * Created on December 13, 2018, 2:44 PM
 */


#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <iostream>
#include <queue>

using namespace std;

class customerType
{
	friend istream& operator >> (istream&, customerType&);
	friend ostream& operator << (ostream&, customerType&);

public:
    int customerNumber;
    int arrivalTime;		// arrival time at checkout queue
    int transactionTime;	// the length required to go through checkout, it can be # of items
    int serviceTime; 		// start of checkout service, used to calculate waiting time
};


#endif /* CUSTOMER_H_ */
