#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> simple_union(vector<int> a, vector<int> b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int>::iterator eit, it;
    vector<int> temp(a.size()+b.size()), result;

    eit = set_union(a.begin(), a.end(), b.begin(), b.end(), temp.begin());
    for(it = temp.begin(); it!=eit; it++)
        result.push_back(*it);

    return result;
}
vector<int> simple_intersection(vector<int> a, vector<int> b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int>::iterator eit, it;
    vector<int> temp(a.size()), result;

    eit = set_intersection(a.begin(), a.end(), b.begin(), b.end(), temp.begin());
    for(it = temp.begin(); it!=eit; it++)
        result.push_back(*it);

    return result;
}
vector<int> simple_difference(vector<int> a, vector<int> b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int>::iterator eit, it;
    vector<int> temp(a.size()), result;

    eit = set_difference(a.begin(), a.end(), b.begin(), b.end(), temp.begin());
    for(it = temp.begin(); it!=eit; it++)
        result.push_back(*it);

    return result;
}

int main () {
    
    vector<int> a;
    a.push_back(17);
    a.push_back(5);
    a.push_back(7);
    a.push_back(11);

    vector<int> b;
    b.push_back(9);
    b.push_back(11);
    b.push_back(5);
    b.push_back(19);
    b.push_back(2);
    /*-----------------------------*/
    cout << "INTERSECTION: ";
    vector<int> intersection;
    intersection = simple_intersection(a, b);

    for(int i=0; i<intersection.size(); i++){
        cout << intersection[i] << " ";
    }
    cout << endl;
    cout << intersection.size() << endl;
    /*-------------------------*/
    cout << "UNION: ";
    vector<int> un;
    un = simple_union(a, b);

    for(int i=0; i<un.size(); i++){
        cout << un[i] << " ";
    }
    cout << endl;
    cout << un.size() << endl;
    /*------------------------*/
    cout << "DIFFERENCE: ";
    vector<int> difference;
    difference = simple_difference(a, b);

    for(int i=0; i<difference.size(); i++){
        cout << difference[i] << " ";
    }
    cout << endl;
    cout << difference.size() << endl;
    /*----------------------*/

    return 0;

}