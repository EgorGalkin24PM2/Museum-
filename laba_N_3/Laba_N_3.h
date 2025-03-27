#ifndef LABA_N_3_H
#define LABA_N_3_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Exhibit {
private:
    string name;
    string material; 
    int year;

public:
    Exhibit() : name(""), material(""), year(0) {}
    Exhibit(const string& name, const string& material, int year);

    const string& getName() const;
    const string& getMaterial() const; 
    int getYear() const;

    void setName(const string& name);
    void setMaterial(const string& material); 
    void setYear(int year);

    friend ostream& operator<<(ostream& os, const Exhibit& exhibit);
    friend istream& operator>>(istream& is, Exhibit& exhibit);
};

namespace database {
    void load_exhibits(vector<Exhibit>& exhibits, const string& filename);
    void save_exhibits(const vector<Exhibit>& exhibits, const string& filename);
    void add_exhibit(vector<Exhibit>& exhibits);
    void edit_exhibit(vector<Exhibit>& exhibits);
    void delete_exhibit(vector<Exhibit>& exhibits);
    void list_exhibits(const vector<Exhibit>& exhibits);
    void search_exhibits(const vector<Exhibit>& exhibits);
}

#endif 
