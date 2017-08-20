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

bool sort_clause(const vector<int> a,const vector<int> b){
        return (a.size()<b.size());
    }

using namespace std;



bool dpll(vector< vector<int> > clauses,map<int,bool> assigned){

    if(clauses.size()==0){
        sol = assigned;
        return true;
    }
    for(vector< vector<int> > :: iterator i=clauses.begin();i!=clauses.end();i++){
            if(i->empty()){
               return false;
        }
    }


    vector< vector<int> > :: iterator i;
    vector<int>:: iterator j;

    cout<<"clause"<<endl;
    for(i=clauses.begin();i<clauses.end();i++){

            for(j=i->begin();j!=i->end();j++){
                cout<<*j<<" ";
            }
            cout<<endl;
    }
    cout<<endl;

    /*auto remove_unit_clause = [&](vector<int> i)->bool{
        return(i.size()==1);
    };*/



    auto remove_true_clause = [&](vector<int>i)->bool{
        if(i.size()==1){
            return true;
        }
        vector<int>:: iterator it;
        bool is_true = false;
        for(it=i.begin();it!=i.end();it++){

            if(assigned.find(abs(*it))!=assigned.end()){
                //cout<<(assigned[abs(*it)]+1)%2<<" ";
                if(*it<0){
                    is_true = (assigned[abs(*it)]+1)%2;
                }
                else if(*it>0){
                    is_true = assigned[abs(*it)];
                }
            }
        }
        return is_true;
    };


    auto remove_false_literal=[&](int num)->bool{
        return((assigned.find(abs(num))==assigned.end())?false:(num<0?assigned[abs(num)]:((assigned[abs(num)]+1)%2)));
    };
    //auto remove_true_clause = [&]()

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

    for(i=clauses.begin();i<clauses.end();i++){
        auto iterator = remove_if(i->begin(),i->end(),remove_false_literal);
        i->erase(iterator,i->end());
    }
    //remove unit and true clause
    auto iterator = remove_if(clauses.begin(),clauses.end(),remove_true_clause);
    clauses.erase(iterator,clauses.end());


    sort(clauses.begin(),clauses.end(),sort_clause);
    vector<vector<int> > clause_copy = clauses;
    for(i=clause_copy.begin();i<clause_copy.end();i++){
            for(j=i->begin();j!=i->end();j++){

                    assigned[abs(*j)] = true;
                    bool l = dpll(clause_copy,assigned);

                    assigned[abs(*j)] = false;
                    bool m = dpll(clause_copy,assigned);
                    return (l || m);
            }

    }


    cout<<"map"<<endl;
    for(map<int ,bool>::iterator p=assigned.begin();p!=assigned.end();p++){
       cout<<p->first<<" "<<p->second;
       cout<<endl;
    }


return true;


}

int main()
{
    string line;
    string p,cnf;
    vector< vector<int> > clauses;
    map<int, bool> assigned;

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
    cout<<dpll(clauses,assigned);
    //cout<<clauses.size();

    return 0;
}
