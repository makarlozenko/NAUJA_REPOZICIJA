#include "mylib.h"

int main() {

    bool naudotiFaila;
    while(true){
        try{
            cout << "Naudoti faila ar ranka (0 - failas, 1 - ranka): ";
            cin >> naudotiFaila;

            if(cin.fail() || (naudotiFaila != 0 && naudotiFaila != 1)){
                throw invalid_argument("Nevalidus pasirinkimas. Prasome ivesti 0 arba 1.");
            }else{
                break;
            }
        }catch (invalid_argument e){
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }



    if (naudotiFaila==0){
        bool generuotiFaila;
        while(true){
            try{
                cout << "Generuoti faila ar ne (0 - NE, 1 - TAIP): ";
                cin >> generuotiFaila;

                if(cin.fail() || (generuotiFaila != 0 && generuotiFaila != 1)){
                    throw invalid_argument("Nevalidus pasirinkimas. Prasome ivesti 0 arba 1.");
                }else{
                    break;
                }
            }catch (invalid_argument e){
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        if (generuotiFaila==1) {

            int testuSk;
            cout<<"Kiek norite padaryti testu? ";
            cin >>testuSk;

            bool senasnaujas;
            while(true){
                try{
                    cout << "Naudosim sena '0' arba nauja '1' faila: ";
                    cin >> senasnaujas;

                    if(cin.fail() || (senasnaujas != 0 && senasnaujas != 1)){
                        throw invalid_argument("Nevalidus pasirinkimas. Prasome ivesti 0 arba 1.");
                    }else{
                        break;
                    }
                }catch (invalid_argument e){
                    cerr << e.what() << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            string naujasFailas;
            int sKiekis;
            int ndKiekis;

            if (senasnaujas==0){

                cout << "Iveskite seno failo pavadinima: ";
                cin >> naujasFailas;


            } else {
                cout << "Iveskite naujo failo pavadinima: ";
                cin >> naujasFailas;

                cout<<"Kiek norite studentu? ";
                cin>>sKiekis;

                cout<<"Kiek norite namu darbu? ";
                cin>>ndKiekis;
            }

            string rusiuoti;
            cout <<"Rusiuoti pagal pasirnkta parametra: v - varda, p-pavarde, gp - galutini pazymi: ";
            cin >> rusiuoti;

            double suma=0;
            double sumaNusk=0;
            double sumaRus=0;
            double sumaKiet=0;
            double sumaVarg=0;

            for (int t=1; t<=testuSk; t++){
                vector <Studentas> studentai;

                auto start = high_resolution_clock::now();

                if (checkFile(naujasFailas+to_string(t)+".txt")){
                    string egzfailas = naujasFailas+to_string(t)+".txt";
                    cout << "Failas jau egzistuoja"<<endl;
                    int strategija;
                    while(true){
                        try{
                            cout << "Kokia strategija naudosime: 0 - pradine, 1 - du konteineriai, 2 - vienas konteineris, 3 - vienas konteineris patobulintas: ";;
                            cin >> strategija;

                            if(cin.fail() || (strategija != 0 && strategija != 1 && strategija != 2 && strategija != 3)){
                                throw invalid_argument("Nevalidus pasirinkimas. Prasome ivesti teisinga skaiciu.");
                            }else{
                                break;
                            }
                        }catch (invalid_argument e){
                            cerr << e.what() << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }

                    for (int t=1; t<=testuSk; t++){
                        auto end = high_resolution_clock::now();
                        duration<double> diff = start-start;
                        rusiuotiDuomenisIsEgzistFailo(egzfailas, sKiekis,  diff, t, suma, rusiuoti, sumaNusk,sumaRus,sumaKiet,sumaVarg,strategija);
                    }
                    break;
                }else{
                ofstream nFailas (naujasFailas+to_string(t)+".txt");

                srand(time(NULL));
                bool naudotiMediana;
                int pazymysF;
                string baseVardas = "Vardas";
                string basePavarde = "Pavarde";
                for (int i=0; i < sKiekis; i++){
                    Studentas studentas;
                    string newName = baseVardas + to_string(i+1);
                    studentas.setVar(newName);
                    string newSurname = basePavarde + to_string(i+1);
                    studentas.setPav(newSurname);


                    for(int k = 0; k < ndKiekis; k++) {
                        pazymysF = GetRandomPaz(1, 10);
                        studentas.getPaz().push_back(pazymysF);
                    }
                    int egz = GetRandomPaz(1, 10);
                    studentas.setEgz(egz);

                    studentai.push_back(studentas);
                }


                nFailas <<left << setw(30) << "Vardas"<< left << setw(30) << "Pavarde";
                for (int j=1; j<=ndKiekis; j++){
                    nFailas << left << setw(5) << "ND"+to_string(j);
                }
                nFailas << left << setw(20) << "Egzaminas"<<endl ;

                for (Studentas student : studentai) {
                    nFailas << left << setw(30) << student.getVar() << left << setw(30)  << student.getPav() ;
                    for (int paz : student.getPaz()){
                        nFailas << left << setw(5) << paz;
                    }
                    nFailas << left << setw(20) << student.getEgz()<<endl;
                }
                nFailas.close();

                auto end = high_resolution_clock::now();
                duration<double> diff = end-start;
                cout << sKiekis << " elementu uzpildymas uztruko: "<< diff.count() << " s\n";

                rusiuotiDuomenisIsGeneruotoFailo(naujasFailas, sKiekis,  diff, t, suma,rusiuoti,sumaNusk,sumaRus,sumaKiet,sumaVarg);
                }


            }
            cout<<"Padarytu testu laiko vidurkis: "<<suma/testuSk<< " s"<<endl;
            cout<<"Failu nuskaitymu laiko vidurkis: "<<sumaNusk/testuSk<< " s"<<endl;
            cout<<"Failu rusiavimo laiko vidurkis: "<<sumaRus/testuSk<< " s"<<endl;
            cout<<"Kietakiu irasymo laiko vidurkis: "<<sumaKiet/testuSk<< " s"<<endl;
            cout<<"Vargsiuku irasymo laiko vidurkis: "<<sumaVarg/testuSk<< " s"<<endl;



        }else{
            vector <Studentas> studentai;
            string failoPavadinimas;
            cout << "Iveskite failo pavadinima: ";
            cin >> failoPavadinimas;
            nuskaitytiDuomenisIsFailo(failoPavadinimas, studentai);
            int eil=kiekEiluciu(failoPavadinimas);
            bool naudotiMediana;
            for (int m = 0; m < eil-1; m++) {
                double gp=skaiciuotiGalutiniBala(studentai[m], 1);
                studentai[m].setRezm(gp);
                double gp1=skaiciuotiGalutiniBala(studentai[m], 0);
                studentai[m].setRezv(gp1);
            }
            spausdintiDuomenis(studentai);
        }


    }else{
        int studentuSkaicius;
        while (true) {
            try{
                cout << "Iveskite studentu skaiciu: ";
                cin >> studentuSkaicius;

                if (cin.fail() || (studentuSkaicius < 1)) {
                    throw invalid_argument( "Nevalidus pasirinkimas. Prasome ivesti studentu skaiciu.");
                } else {
                    break;
                }
            }catch (invalid_argument e){
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }



        vector<Studentas> studentai(studentuSkaicius);

        for (int i = 0; i < studentuSkaicius; i++) {
            cout << "Iveskite " << i + 1 << " studento duomenis:" << endl;

            Studentas naujasStudentas;
            cin >> naujasStudentas;

            naujasStudentas.setRezv(skaiciuotiGalutiniBala(naujasStudentas, 0));
            naujasStudentas.setRezm(skaiciuotiGalutiniBala(naujasStudentas, 1));
            studentai[i] = naujasStudentas;
        }

        spausdintiDuomenis(studentai);

    return 0;
    }
}

