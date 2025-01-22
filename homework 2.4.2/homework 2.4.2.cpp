#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> 
using namespace std;


class Adress {
private:
    std::string city;
    std::string street;
    int housenumber;
    int flatnumber;
public:
    Adress(std::string& city, std::string& street, int housenumber, int flatnumber)
        : city(city), street(street), housenumber(housenumber), flatnumber(flatnumber) {}

    void saveToFile(ofstream& fout) const {
        fout << city << "," << street << "," << housenumber << "," << flatnumber << std::endl;
    }

    const std::string& getCity() const {
        return city;
    }
};


int main()
{
    vector<Adress> adresses;
    ifstream fin("C:/Users/Констатин/Desktop/учаба/адреса/in.txt");
    ofstream fout("C:/Users/Констатин/Desktop/учаба/адреса/out.txt");
    
    if (!fin.is_open()) {
        cout << "Не удалось открыть файл!" << std::endl;
        return 1;
    }

    
    string city;
    string street;
    int housenumber;
    int flatnumber;
    int count{};

    fin >> count;

    while (fin >> city >> street >> housenumber >> flatnumber)
    {
        adresses.emplace_back(city, street, housenumber, flatnumber);


    }
    fout << count << "\n";

    sort(adresses.begin(), adresses.end(), [](const Adress& a, const Adress& b) {

        return a.getCity() < b.getCity();

        });

    for (const auto& adress : adresses) {
        adress.saveToFile(fout);
    }


    fin.close();
    fout.close();
}


