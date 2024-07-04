#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Disciplina {
public:
    string name;
    string form_control;
    double count_hours;
};

bool Vozrastanie(Disciplina a, Disciplina b) {
    return a.count_hours < b.count_hours;
}

bool Ubivanie(Disciplina a, Disciplina b) {
    return a.count_hours > b.count_hours;
}


int main()
{
    ofstream file;
    file.open("Disciplina.txt", ios::app);
  
    Disciplina dis;
    cout << "Vvedite nazvanie\n";
    cin >> dis.name;

    cout << "Vvedite formu controla\n";
    cin >> dis.form_control;

    cout << "Vvedite obem chasov\n";
    cin >> dis.count_hours;

    file << dis.name + " " + dis.form_control + " " + to_string(dis.count_hours) + "\n";
    file.close();

    cout << "Dlya sortirovki po vozrastaniu vvedite 1, dlya ubivaniya 2, inache 0\n";
    string sort;
    cin >> sort;

    if (sort == "1") {
        vector<Disciplina> d;
        ifstream file;
        file.open("Disciplina.txt");
        while (file >> dis.name >> dis.form_control >> dis.count_hours) {
            d.push_back(dis);
        }
        file.close();

        std::sort(d.begin(), d.end(), Vozrastanie);

        ofstream files;
        files.open("Disciplina.txt", ios::out);
        for (int i = 0; i < d.size(); i++) {
            files << d[i].name + " " + d[i].form_control + " " + to_string(d[i].count_hours) + "\n";
        }
        files.close();
    }
    else if (sort == "2") {
        vector<Disciplina> d;
        ifstream file;
        file.open("Disciplina.txt");
        while (file >> dis.name >> dis.form_control >> dis.count_hours) {
            d.push_back(dis);
        }
        file.close();

        std::sort(d.begin(), d.end(), Ubivanie);

        ofstream files;
        files.open("Disciplina.txt", ios::out);
        for (int i = 0; i < d.size(); i++) {
            files << d[i].name + " " + d[i].form_control + " " + to_string(d[i].count_hours) + "\n";
        }
        files.close();
    }
}
