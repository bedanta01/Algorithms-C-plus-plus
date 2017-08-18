#include <iostream>
#include<map>
#include<vector>
#include<typeinfo>
#include<sstream>
#include<map>
#include<algorithm>
using namespace std;

int vars,no_of_clauses;
//vector< vector<int> > clauses;
map<int, bool> sol;

using namespace std;



bool dpll(vector< vector<int> > clauses){

    vector< vector<int> > :: iterator i;
    vector<int>:: iterator j;
    map<int, bool> assigned;

    auto remove_unit_clause = [&](vector<int> i)->bool{
        return(i.size()==1);
    };

    auto remove_true_clause = [&](vector<int>i)->bool{
        if(i.size()==1){
            return true;
        }
        vector<int>:: iterator it;
        bool is_true = false;
        for(it=i.begin();it!=i.end();it++){
            if(assigned.find(*it)!=assigned.end()){
                if(*it<0){
                    is_true = (-1)*assigned[*it];
                }
                else if(*it>0){
                    is_true = assigned[*it];
                }
            }
        }
        return is_true;
    };

    auto remove_false_literal=[&](int num)->bool{
        return(assigned.find(abs(num))==assigned.end()?false:(num<0?assigned[num]:(-1)*assigned[num]));
    };
    //auto remove_true_clause = [&]()


    if(clauses.size()==0){
        return true;
    }
    for(i=clauses.begin();i!=clauses.end();i++){
            if(i->empty()){
               return false;
        }
    }

    //unit propagation

    for(i=clauses.begin();i!=clauses.end();i++){
        if(i->size()==1){
            j = i->begin();
            if(*j<0){
                int index = -1*(*j);
                sol[index] = false;
                assigned[index] = false;
            }
            else{
                int index = *j;
                sol[index] = true;
                assigned[index] = true;
            }
        }
    }

    //remove unit and true clause
    auto iterator = remove_if(clauses.begin(),clauses.end(),remove_true_clause);
    clauses.erase(iterator,clauses.end());

    //remove false literals
    for(i=clauses.begin();i<clauses.end();i++){
        auto iterator = remove_if(i->begin(),i->end(),remove_false_literal);
        i->erase(iterator,i->end());
    }

    //remove true clauses merge with unit clause
    //auto iterator = remove_if(clauses.begin(),clauses.end(),remove_true_clause);
    //clauses.erase(iterator,clauses.end());

    //print clauses
    for(i=clauses.begin();i<clauses.end();i++){
        for(j=i->begin();j!=i->end();j++){
            cout<<*j<<" ";
        }
        cout<<endl;
    }


}

int main()
{
    string line;
    string p,cnf;
    vector< vector<int> > clauses;

    while(getline(cin,line)){
        if(line[0]== 'p'){
            break;
        }
    };
    istringstream iss(line);
    iss >> p >> cnf >> vars >> no_of_clauses;

    while(getline(cin,line)){
        if(line[0]=='\0'){
            break;
        }
        istringstream iss(line);
        int literal;
        vector<int> c;
        while(iss >> literal){
            if(literal!=0){
                c.push_back(literal);
            }

        }
        clauses.push_back(c);
    }
    dpll(clauses);
    //cout<<clauses.size();

    return 0;
}
