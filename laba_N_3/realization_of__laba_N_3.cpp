#include "Laba_N_3.h"

Exhibit::Exhibit(const string& name, const string& material, int year)
    : name(name), material(material), year(year) {
}

const string& Exhibit::getName() const {
    return name;
}

const string& Exhibit::getMaterial() const { 
    return material; 
}

int Exhibit::getYear() const {
    return year;
}

void Exhibit::setName(const string& name) {
    this->name = name;
}

void Exhibit::setMaterial(const string& material) { 
    this->material = material;
}

void Exhibit::setYear(int year) {
    this->year = year;
}

ostream& operator<<(ostream& os, const Exhibit& exhibit) {
    os << exhibit.name << "\n" << exhibit.material << "\n" << exhibit.year << "\n"; 
    return os;
}

istream& operator>>(istream& is, Exhibit& exhibit) {
    getline(is, exhibit.name);
    getline(is, exhibit.material);
    is >> exhibit.year;
    is.ignore(); // kak ya ponyal, ignore() ignoriryet fisrt symbol stroki, ved ego ne schitivaem
    return is;
}

namespace database {
    void load_exhibits(vector<Exhibit>& exhibits, const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            Exhibit exhibit;
            while (file >> exhibit) {
                exhibits.push_back(exhibit);
            }
            file.close();
        }
    }

    void save_exhibits(const vector<Exhibit>& exhibits, const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& exhibit : exhibits) {
                file << exhibit;
            }
            file.close();
        }
    }

    void add_exhibit(vector<Exhibit>& exhibits) {
        string name, material; 
        int year;

        cout << "\nWrite the name of exhibit: ";
        getline(cin, name);
        cout << "\nWrite the material of exhibit: "; 
        getline(cin, material);
        cout << "\nWrite the age of exhibit: ";
        cin >> year;
        cin.ignore(); 

        exhibits.emplace_back(name, material, year);
    }

    void edit_exhibit(vector<Exhibit>& exhibits) {
        int index;
        cout << "\nWrite the index of exhibit, which you would edit: ";
        cin >> index;
        cin.ignore();

        if (index >= 0 && index < exhibits.size()) {
            string name, material;
            int year;

            cout << "\nWrite new name of exhibit: ";
            getline(cin, name);
            cout << "\nWrite new material of exhibit: "; 
            getline(cin, material);
            cout << "\nWrite new age of exhibit: ";
            cin >> year;
            cin.ignore(); 

            exhibits[index].setName(name);
            exhibits[index].setMaterial(material); 
            exhibits[index].setYear(year);
        }
        else {
            cout << "\nExhibit not founded.\n";
        }
    }

    void delete_exhibit(vector<Exhibit>& exhibits) {
        int index;
        cout << "\nWrite the index of exhibit, which you would delete: ";
        cin >> index;

        if (index >= 0 && index < exhibits.size()) {
            exhibits.erase(exhibits.begin() + index);
        }
        else {
            cout << "Exhibit not founded.\n";
        }
    }

    void list_exhibits(const vector<Exhibit>& exhibits) {
        for (size_t i = 0; i < exhibits.size(); ++i) {
            cout << "Index: " << i << "\n" << exhibits[i] << "\n";
        }
    }

    void search_exhibits(const vector<Exhibit>& exhibits) {
        string query;
        cout << "\nWrite the index of exhibit, which you would find: ";
        getline(cin, query);

        for (const auto& exhibit : exhibits) {
            if (exhibit.getName().find(query) != string::npos) {
                cout << exhibit << "\n";
            }
        }
    }
}