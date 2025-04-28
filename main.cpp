#include <iomanip>
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Funkcija, lai zimetu karatavas atkariba no kludu skaita
void zimeKaratavas(int kludas) {
    cout << "  _______" << endl;
    cout << "  |     |" << endl;

    // Galva
    cout << "  |     ";
    if (kludas > 0)
        cout << "O";
    else
        cout << " ";
    cout << endl;

    // Kermenis un rokas
    cout << "  |    ";
    if (kludas > 2)
        cout << "/";
    else
        cout << " ";

    if (kludas > 1)
        cout << "|";
    else
        cout << " ";

    if (kludas > 3)
        cout << "\\";
    else
        cout << " ";
    cout << endl;

    // Kajas
    cout << "  |    ";
    if (kludas > 4)
        cout << "/";
    else
        cout << " ";
    cout << " ";
    if (kludas > 5)
        cout << "\\";
    else
        cout << " ";
    cout << endl;

    cout << "__|__" << endl << endl;
}
// Funkcija, kas izveles vai speletajs speles viens vai buus 2 speletaji, kur viens no viniem uzraksta minamo vardu

int speletaji = speletajuskaits;
cout<< "Izvelaties speletaju skaitu: Ja spelesiet viens, tad rakstiet 1, ja divi speletaji, tad rakstiet 2" <<endl;
cin>> speletajuskaits
 if (speletajuskaits == 2) {
    cout<< "Ievadi minamo vardu:" << endl;
    cin>> izveletiesVardu; << endl<< endl<< endl<< endl<< endl<<endl<< endl<< endl<< endl<< endl<< endl<< endl<< endl<< endl<< endl<< endl<< endl;
    cout<< "2, speletajs, varat sakt minet vardu";


 }

// Funkcija, lai izveelas nejausu vardu no saraksta
string izveletiesVardu() {
    vector<string> vardi = {"PROGRAMME", "KARATAVAS", "DATORS", "STUDENTS", "SKOLA"};
    srand(time(0));
    return vardi[rand() % vardi.size()];
}

// Galvena speles funkcija
void spelet() {
    string vards = izveletiesVardu();  // Nejausi izvelets vards
    string atminamiVardi(vards.length(), '_');  // Aizvietojam visus burtus ar "_"
    vector<char> minetieBurti;  // Speletaja meginatie burti
    int kludas = 0;  // Nepareizo meginajumu skaits
    bool uzvara = false;

    cout << "Sveiks speletaj! Si ir karatavu spele!" << endl;
    cout << "Tev jaatmin vards, minot burtus. Nepareizi minejumi tiks registreti." << endl << endl;

    // Speles cikls
    while (kludas < 6 && !uzvara) {
        zimeKaratavas(kludas);
        cout << "Vards: " << atminamiVardi << endl;
        cout << "Jau meginatie burti: ";
        for (char x : minetieBurti) {
            cout << x << " ";
        }
        cout << endl;

        char minetsBurts;
        cout << "Ievadi burtu: ";
        cin >> minetsBurts;
        minetsBurts = toupper(minetsBurts); // Nodrosinam lielos burtus, citadak uzskaitis to ka kludu

        // Parbaude vai burts jau ir minets
        if (find(minetieBurti.begin(), minetieBurti.end(), minetsBurts) != minetieBurti.end()) {
            cout << "Tu jau meginaji so burtu! Megini velreiz." << endl;
            continue;
        }

        minetieBurti.push_back(minetsBurts);
        bool atrodasVarda = false;

        // Aizvietojam atminetos burtus
        for (int i = 0; i < vards.length(); i++) {
            if (vards[i] == minetsBurts) {
                atminamiVardi[i] = minetsBurts;
                atrodasVarda = true;
            }
        }

        // Ja burts nebija varda, palielina kludu skaitu
        if (!atrodasVarda) {
            kludas++;
            cout << "Nepareizs burts! Tev ir " << (6 - kludas) << " dzivibas atlicis." << endl;
        }

        // Parbauda, vai speletajs ir uzvarejis
        if (atminamiVardi == vards) {
            uzvara = true;
        }
    }

    // Speles beigas
    zimeKaratavas(kludas);
    if (uzvara) {
        cout << "Apsveicu! Tu uzvareji! Pareizais vards bija: " << vards << endl;
    } else {
        cout << "Diemzel tu zaudeji. Pareizais vards bija: " << vards << endl;
    }
}

int main() {
    char atkal;

    do {
        spelet();
        cout << "Vai velies spelet velreiz? (J/N): ";
        cin >> atkal;
        atkal = toupper(atkal);
    } while (atkal == 'J');

    cout << "Paldies par speli!" << endl;
    return 0;
}

