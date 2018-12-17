
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

#include "customer.h"
#include "server.h"
using namespace std;

int main() {
    int simulationTime;
    int customercount = 0;
    int servercount = 0;
    int serverIdlecount = 0;
    int Srcnt = 0;
    int currentwaittime = 0;
    int maxwaittime = 0;
    int serverIdletime = 0;
    cout << "Enter simulation time: ";
    cin>>simulationTime;
    //int simulationTime = 100;
    int numberOfServers;
    float avgwaittime = 0;
    cout << "Enter number of servers: ";
    cin>>numberOfServers;

    //int numberOfServers=3;

    // create and initialize servers
    vector <serverType> servers;
    serverType s;
    s.busy = false;
    for (int i = 0; i < numberOfServers; i++) servers.push_back(s);

    // create customer Queue
    queue<customerType> customerQueue;
    // read customer arrival patterns into customer Q : assuming it is sorted by arrival time
    {
        customerType cust;
        ifstream fin;
        fin.open("simulation.txt");
        while (!fin.eof()) {
            fin >> cust;
            customerQueue.push(cust);
        }
        fin.close();
    }

    // start the simulation loop
    for (int clock = 1; clock <= simulationTime; clock++) {
        // update all servers
        for (int i = 0; i < numberOfServers; i++) {
            if (servers[i].busy) {
                servers[i].transactionTime--;
                if (servers[i].transactionTime <= 0) {
                    servers[i].busy = false; // done with current customer

                    cout << "At clock " << clock << " server"
                            " " << i << " finish " << servers[i].currentCustomer.customerNumber << endl;
                }
            }

            // assign waiting customer (if any) to idle server
            if (servers[i].busy == false) {

                if (customerQueue.empty()) continue; // nobody in customerQ
                // servers[i].ServeridleTime++;
                if (customerQueue.front().arrivalTime > clock) continue; // front customer has not arrived yet

                // assign first ready customer to the server
                customerType readyC = customerQueue.front();
                customerQueue.pop();
                customercount++;
                readyC.serviceTime = clock; // record starting service time
                servers[i].busy = true;
                servercount = i + 1; //to count number of servers used in simulation
                servers[i].currentCustomer = readyC;
                servers[i].transactionTime = readyC.transactionTime;
                servers[i].ServerworkingTime += readyC.transactionTime;
                avgwaittime += (servers[i].currentCustomer.serviceTime)-(servers[i].currentCustomer.arrivalTime);
                cout << "At clock " << clock << " server " << i << " start " << servers[i].currentCustomer << endl;

                currentwaittime = (servers[i].currentCustomer.serviceTime)-(servers[i].currentCustomer.arrivalTime);

                if (maxwaittime < currentwaittime) {
                    maxwaittime = currentwaittime;
                }

            }
        }
    }
    cout << "Results: " << endl;
    cout << "Customer count= " << customercount << endl;
    cout << "Average wait time= " << (avgwaittime) / customercount << endl;
    cout << "Maximum wait time= " << maxwaittime << endl;
    cout << "Number of servers used during simulation= " << servercount << endl;
    for (int i = 0; i < servercount; i++) {
        // cout<<"server ["<<i<<"] Idle time= "<<servers[i].ServeridleTime<<endl;

        // servers[i].ServerworkingTime=simulationTime-servers[i].ServeridleTime;

        cout << "server [" << i << "]s Working time= " << servers[i].ServerworkingTime << endl;
        cout << "Idle time of the server[" << i << "] during simulation= " << simulationTime - servers[i].ServerworkingTime << endl;
        cout << "server [" << i << "]s Efficiency= " << (servers[i].ServerworkingTime / simulationTime)*100 << "%" << endl;
    }
    cout << "****************End Of Simulation****************" << endl;

    cout << endl;
}




