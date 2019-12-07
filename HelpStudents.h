#ifndef CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
#define CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
#include <vector>
#include <iostream>
#include <fstream>
#include <list>

using namespace std;


class HelpStudents{

public:
    HelpStudents(int  N, int  M, int K, vector < pair< pair <int,int> , int > > ways);
    long long int firstStudent();
    long long int secondStudent();
    long long int thirdStudent();
    long long int fourthStudent();
    long long int fifthStudent();
    vector<int> neig;
    vector <pair <long int,long int>> edges;
    vector<long long int> weights ;
    vector<bool> visited;
    vector <long long int> distance;
    list< pair<long long int,long long int> > *adjacencyList;
    long long int node ;
    long long int edge;
    long long int goal;
    long long int minEdge(list< pair<long long int,long long int> > *adjacencyList,int element);
    // YOU CAN ADD YOUR HELPER FUNCTIONS AND MEMBER FIELDS

};

#endif //CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
