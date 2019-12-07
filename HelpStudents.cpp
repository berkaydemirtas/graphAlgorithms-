/*
Student Name:Berkay Demirtaş
Student Number:2017400234
Project Number: 4
Compile Status: [SUCCESS]
Running Status: [SUCCESS]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include <set>
#include "HelpStudents.h"
#include <queue>
#include <zconf.h>


using namespace std;

HelpStudents::HelpStudents(int  N, int  M, int K, vector < pair< pair <int,int> , int > > ways) {


    ;
      node =N;
      edge=M;
      goal=K;
      distance.resize(N+1);
     distance[1]=0;

      visited.resize(N+1);
      neig.resize(N+2);




      neig[1]=0;
     for(int i=1;i<N+1;i++){

         distance[i]=0;
         visited[i]=false;
         neig[i+1]=i+1;
     }



    adjacencyList = new list< pair<long long int,long long int> >[N+1];
     for(long long int i=0;i<M;i++){

         long long int u=ways[i].first.first;
         long long int v=ways[i].first.second;
         long long int w=ways[i].second;

         adjacencyList[u].push_back(make_pair(v, w));
         adjacencyList[v].push_back(make_pair(u, w));


     }

}

long long int HelpStudents::firstStudent() {


   set<pair<long long int,long long int>,less<>> s;


   s.insert(make_pair(0,1));
    while(!s.empty()){

        pair<long long int ,long long int> tmp=*(s.begin());
        s.erase(s.begin());
        list< pair<long long int, long long int> >::iterator i;

        for ( i = adjacencyList[tmp.second].begin(); i != adjacencyList[tmp.second].end(); ++i){

           long long int vertice=(*i).first;
           long long int dist=(*i).second;

           if(distance[vertice]>distance[tmp.second]+dist ){

               s.erase(s.find(make_pair(distance[vertice],vertice)));
               distance[vertice]=distance[tmp.second]+dist;

               s.insert(make_pair(distance[vertice],vertice));


           }
           else if(distance[vertice]==0){
               distance[vertice]=distance[tmp.second]+dist;
               s.insert(make_pair(distance[vertice],vertice));
           }

       }



    }



    return distance[goal];

    // IMPLEMENT ME!
}
long long int HelpStudents::secondStudent() {

    set<pair<long long int,long long int>,less<>> s;


    s.insert(make_pair(0,1));
    while(!s.empty()){

        pair<long long int ,long long int> tmp=*(s.begin());
        s.erase(s.begin());
        list< pair<long long int, long long int> >::iterator i;

        visited[tmp.second]=true;
        for ( i = adjacencyList[tmp.second].begin(); i != adjacencyList[tmp.second].end(); ++i){

            long long int vertice=(*i).first;
            long long int dist=(*i).second;

            if(visited[vertice])
                continue;

            if(distance[vertice]>dist ){

                s.erase(s.find(make_pair(distance[vertice],vertice)));
                distance[vertice]=dist;

                s.insert(make_pair(distance[vertice],vertice));
                neig[vertice]=tmp.second;

            }
            else if(distance[vertice]==0){
                distance[vertice]=dist;
                s.insert(make_pair(distance[vertice],vertice));
                neig[vertice]=tmp.second;
            }


        }



    }
    int max=distance[goal];
    int a=neig[goal];

    if(neig[goal]==goal)
        return -1;

    while(true){

        if(a==0)
            return max;

        if(max<distance[a])
        max=distance[a];


        a=neig[a];
    }




    // IMPLEMENT ME!
}
long long int HelpStudents::thirdStudent() {

    queue<pair<int,int>> que;
    que.push(make_pair(0,1));
    while(!que.empty()){

        pair<long long int ,long long int> tmp= (que.front());
        que.pop();
        list< pair<long long int, long long int> >::iterator i;

        visited[tmp.second]=true;
        for ( i = adjacencyList[tmp.second].begin(); i != adjacencyList[tmp.second].end(); ++i){

            long long int vertice=(*i).first;


            if(visited[vertice])
                continue;

            else{

                distance[vertice]=distance[tmp.second]+1;
                visited[vertice]=true;
                que.push(make_pair(distance[vertice],vertice));

            }

        }



    }

    return distance[goal];

}
long long int HelpStudents::fourthStudent() {

    int element=1;
    while(element!=goal){


        long long int min=5476547856;
        long long int vert=0;
        long long int count=0;
        list< pair<long long int, long long int> >::iterator i;
        visited[element]=true;
        for ( i = adjacencyList[element].begin(); i != adjacencyList[element].end(); ++i){

            long long int vertice=(*i).first;
            long long int dist=(*i).second;






            count++;

            if(dist==min){
                if(vert>vertice){
                    vert=vertice;

                }

                            }
            if(dist<min){
                vert=vertice;
                min=dist;



            }


        }



        if(count==0)
            return -1;

        pair<long long int,long long int> m=make_pair(vert,min);
        pair<long long int,long long int> n=make_pair(element,min);

        adjacencyList[element].remove(m);
        adjacencyList[vert].remove(n);




        distance[vert]=distance[element]+min;

        element=vert;
        }

    return distance[goal];

}
long long int HelpStudents::fifthStudent() {


    int power=0;
    int c=1;

    set<pair<long long int,long long int>,less<>> s;


    s.insert(make_pair(0,1));
    while(!s.empty()){

        pair<long long int ,long long int> tmp=*(s.begin());
        s.erase(s.begin());
        list< pair<long long int, long long int> >::iterator i;

        for ( i = adjacencyList[tmp.second].begin(); i != adjacencyList[tmp.second].end(); ++i) {

            long long int vertice = (*i).first;
            long long int dist = (*i).second;

            if (power % 3 == 1) {

                if (distance[vertice] > distance[tmp.second] + dist) {

                    s.erase(s.find(make_pair(distance[vertice], vertice)));
                    distance[vertice] = distance[tmp.second] + dist;

                    s.insert(make_pair(distance[vertice], vertice));
                    adjacencyList[tmp.second].remove(make_pair(vertice,dist));


                } else if (distance[vertice] == 0) {
                    distance[vertice] = distance[tmp.second] + dist;
                    s.insert(make_pair(distance[vertice], vertice));
                    adjacencyList[tmp.second].remove(make_pair(vertice,dist));
                }

            }

            if(power%3==2){
                if(distance[vertice]>distance[tmp.second]){

                    s.erase(s.find(make_pair(distance[vertice], vertice)));
                    distance[vertice] = distance[tmp.second] ;

                    s.insert(make_pair(distance[vertice], vertice));
                    adjacencyList[tmp.second].remove(make_pair(vertice,dist));

                }

                else if(distance[vertice]==0){
                    distance[vertice]=distance[tmp.second];
                    adjacencyList[tmp.second].remove(make_pair(vertice,dist));
                    s.insert(make_pair(distance[vertice], vertice));

                }

            }
            if(power%3==0 ){

                long long int a=minEdge(adjacencyList,tmp.second);

                if(2*a<dist){

                    if(2*a+distance[tmp.second]<distance[vertice]){

                        distance[vertice]=2*a+distance[tmp.second];
                        adjacencyList[tmp.second].remove(make_pair(vertice,dist));
                        s.insert(make_pair(distance[vertice], vertice));

                    }


                }

                if(distance[vertice]==0){
                    distance[vertice]=2*a+distance[tmp.second];
                    adjacencyList[tmp.second].remove(make_pair(vertice,dist));
                    s.insert(make_pair(distance[vertice], vertice));

                }


            }
        }


        power++;

    }



return distance[goal];





}

long long int HelpStudents:: minEdge(list< pair<long long int,long long int> > *adjacencyList,int element){

    list< pair<long long int, long long int> >::iterator i;

    long long int min=LONG_LONG_MAX;
    for ( i = adjacencyList[element].begin(); i != adjacencyList[element].end(); ++i){

        if((*i).second<min){

            min=(*i).second;

        }




    }


    return min;
}

// YOU CAN ADD YOUR HELPER FUNCTIONS