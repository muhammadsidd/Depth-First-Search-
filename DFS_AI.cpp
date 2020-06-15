#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <stack>
#include <list>
#include <iomanip>
#include<cctype>
#include <iterator>
#include <sstream>
#include <forward_list>


using namespace std;

string name;
int x_axis;
int y_axis;


//i just create a structure for the node, with the name, the x, y axis and the neighbor vector 
struct node{

string name;
int x_axis;
int y_axis;

vector<node> neighbor;
bool visited=false;

};

//lines vector just fills up with the points that i grabat the location txt 
vector<node> lines;


//i create a helper function that will return the index of the string i need, for when i update the neighbors i need to know where in my ines vector
// is this string(A1) located
int find_name(string name,vector<node> lines){

for(int i=0; i<lines.size();i++){
    if(lines[i].name==name){
     return i;   
    }
}

};

void DFS(node start,node end){

    start.visited=true;
    
    if(start.name==end.name){
        cout<<"Found:"<<endl;
       // break;
    }


int main(){
    string line;
    int number_of_lines=0;
    
    node n;
    //int num_lines1;
    //int num_lines2;
    string line2;
    ifstream locations;
    ifstream connections;
    
    //open the location file to get the lines
    locations.open("locations.txt");
    //connections.open("connections.txt");

    if(locations.is_open()){
        while(!locations.eof()){
            //i just iterate through the lines and put the objects in a structure vector 
            getline(locations,line);
            stringstream ss(line);
            //cout<< line << endl;

            if(line=="END"){
                break;
            }

            ss>>name>>x_axis>>y_axis;
            
            n.name=name;
            //n=temp[x_axis][y_axis];
            n.x_axis=x_axis;
            n.y_axis=y_axis;
            //as i read the lines put them in a vector call lines
            lines.push_back(n);
            
            ss.clear();
            ++number_of_lines;
        }
        locations.close();
    }

    //cout << number_of_lines<<endl;
    
    /* 
    for(int i=0; i< lines.size(); ++i){
    
       
        cout<< lines[i].name<< " "<< lines[i].x_axis<<" "<< lines[i].y_axis<<endl;
       
    }
    */
    //open the connections file to reade the lines and grab teh neighbors of teh string
    connections.open("connections.txt");
    
    int index;
    int index2;
    int temp=0;
    string name0;
    int number;
    string name1;
    string name2;
    string name3;
    string name4;
    string name5;
    string name6;


//check this part, i want to say that if the integer next to thename is 1 it means that it has 1 neighbor, so find it in the lines vector and push back into 
//the neighbor vector of that string and so on, with possibiltie of the string been 2,3,4,5.
    if(connections.is_open()){
        while(!connections.eof()){
            
            getline(connections,line2);
            stringstream ss1(line2);
            //cout<<line2<<endl;

            if(line2=="END"){
                break;
           }
           ss1>>name0>>number>>name1>>name2>>name3>>name4;
           // cout<<name0<<"::"<<number<<"::"<<name1<<"::"<<name2<<"::"<<name3<<"::"<<name4<<endl;
            //cout<<number;


           if(number== 1 ){
                ss1>>name0>>number>>name1;
                cout<<name0<<number<<name1;
               
               index=find_name(name1,lines);
               index2=find_name(name0,lines);
               lines[index2].neighbor.push_back(lines[index]);
               
           }
          else if(number == 2 ){
               ss1>>name0>>number>>name1>>name2;

               //cout<<"Inside::::::::::::"<<endl;
                //cout<<name0<<number<<name1<<name2;

               index=find_name(name0,lines);
               int index1=find_name(name1,lines);
               int index2=find_name(name2,lines);
               lines[index].neighbor.push_back(lines[index1]);
               lines[index].neighbor.push_back(lines[index2]); 
               
           
           }
          else if(number==3 ){
               ss1>>name0>>number>>name1>>name2>>name3;
               //cout<<name0<<number<<name1<<name2<<name3;
               index= find_name(name0,lines);
               int index1=find_name(name1,lines);
               int index2=find_name(name2, lines);
               int index3=find_name(name3, lines);
               lines[index].neighbor.push_back(lines[index1]);
               lines[index].neighbor.push_back(lines[index2]);
               lines[index].neighbor.push_back(lines[index3]);
               
           }
           else if(number==4 ){
               ss1>>name0>>number>>name1>>name2>>name3>>name4;
               index=find_name(name0,lines);
               int index1=find_name(name1,lines);
               int index2=find_name(name2,lines);
               int index3=find_name(name3,lines);
               int index4=find_name(name4, lines);
               lines[index].neighbor.push_back(lines[index1]);
               lines[index].neighbor.push_back(lines[index2]);
               lines[index].neighbor.push_back(lines[index3]);
               lines[index].neighbor.push_back(lines[index4]);




           }
           else if(number==5 ){
               ss1>>name0>>number>>name1>>name2>>name3>>name4;
               index=find_name(name0,lines);
               int index1=find_name(name1,lines);
               int index2=find_name(name2,lines);
               int index3=find_name(name3,lines);
               int index4=find_name(name4, lines);
               int index5=find_name(name5,lines);
               lines[index].neighbor.push_back(lines[index1]);
               lines[index].neighbor.push_back(lines[index2]);
               lines[index].neighbor.push_back(lines[index3]);
               lines[index].neighbor.push_back(lines[index4]);
                lines[index].neighbor.push_back(lines[index5]); 
                //lines[index].neighbor.front();
           }
          else if(number==6 ){
              ss1>>name0>>number>>name1>>name2>>name3>>name4>>name5>>name6;
               index=find_name(name0,lines);
               int index1=find_name(name1,lines);
               int index2=find_name(name2,lines);
               int index3=find_name(name3,lines);
               int index4=find_name(name4, lines);
               int index5=find_name(name5,lines);
               int index6=find_name(name6, lines);
               lines[index].neighbor.push_back(lines[index1]);
               lines[index].neighbor.push_back(lines[index2]);
               lines[index].neighbor.push_back(lines[index3]);
               lines[index].neighbor.push_back(lines[index4]);
                lines[index].neighbor.push_back(lines[index5]);  
                lines[index].neighbor.push_back(lines[index6]); 
                
           }
          }
          connections.close();       
        }

        for(int i=0; i<lines.size();i++){
            cout << "inside first:: "<<lines[i].name<<" "<<lines[i].x_axis<<" "<<lines[i].y_axis<< endl;
          
          for(int j=0; j<lines[i].neighbor.size();j++){
              cout << "inside ssecond"<< endl;
            cout<<" Neighbors: " <<lines[i].neighbor[j].name<<","<<endl;
            }
        }    





    return 0;
}