#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>



using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::numeric_limits;
using std::streamsize;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::sort;
using std::invalid_argument;
using std::cerr;
using std::to_string;
using std::left;
using std::setw;
using std::ios;
using std::remove_if;
using std::remove_copy_if;
using std::back_inserter;


using namespace std::chrono;

// Abstract class
class Zmogus {

protected:
    string var, pav;
public:

    Zmogus(const string& v, const string& p):var(v),pav(p) {}

    virtual string getVar() const =0;
    virtual string getPav() const =0;

    virtual void setVar(const string& v) =0;
    virtual void setPav(const string& p) =0;

    virtual ~Zmogus() {};

};

class Studentas : public Zmogus{

private:
    string kategorija;
    vector<int> paz;
    int egz;
    float rez, rezv, rezm;
public:
    Studentas() : Zmogus("null","null"), egz(0), rez(0), rezv(0), rezm(0) {}
    Studentas(const string& v, const string& p, const string& kat, const vector<int>& pazymiai, int e)
        : Zmogus(v, p), kategorija(kat), paz(pazymiai), egz(e), rez(0), rezv(0), rezm(0) {}

    string getVar() const { return var; }
    string getPav() const { return pav; }
    string getKategorija() const { return kategorija; }
    vector<int> getPaz() const { return paz; }
    int getEgz() const { return egz; }
    float getRez() const { return rez; }
    float getRezv() const { return rezv; }
    float getRezm() const { return rezm; }

    void setVar(const string& v) { var = v; }
    void setPav(const string& p) { pav = p; }
    void setKategorija(const string& kat) { kategorija = kat; }
    void setPaz(const vector<int>& pazymiai) { paz = pazymiai; }
    void setEgz(int e) { egz = e; }
    void setRez(float r) { rez = r; }
    void setRezv(float rv) { rezv = rv; }
    void setRezm(float rm) { rezm = rm; }

    //Destructor
    ~Studentas() {}

     //Copy Constructor
    Studentas(const Studentas& other) : Zmogus(other) {
        var = other.var;
        pav = other.pav;
        kategorija = other.kategorija;
        paz = other.paz;
        egz = other.egz;
        rez = other.rez;
        rezv = other.rezv;
        rezm = other.rezm;
    }

    //Copy Assignment Operator
    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            Zmogus::operator=(other);
            var = other.var;
            pav = other.pav;
            kategorija = other.kategorija;
            paz = other.paz;
            egz = other.egz;
            rez = other.rez;
            rezv = other.rezv;
            rezm = other.rezm;
        }
        return *this;
    }


    //Isvesties operatorius
    friend  std::ostream& operator<<(std::ostream& os, const Studentas& student) {

        os << std::left << std::setw(20) << student.getVar() << std::left << std::setw(20) << student.getPav();
        os << std::left << std::setw(20) << student.getRezv()<<std::left << std::setw(20) << student.getRezm();

        return os;
    }

    //Ivesties operatorius
    friend std::istream& operator>>(std::istream& is, Studentas& student) {

        string v, p;
        cout<<"Iveskite varda ir pavarde: ";
        is >> v >> p;
        student.setVar(v);
        student.setPav(p);

        vector<int> pazymiai;

        bool generuotiPaz;
            while(true){
            try{
                cout << "Sugeneruoti pazymius atsitiktinai(0 - NE, 1 - TAIP):";
                is >> generuotiPaz;

                if(is.fail() || (generuotiPaz != 0 && generuotiPaz != 1)){
                    throw invalid_argument("Nevalidus pasirinkimas. Prasome ivesti 0 arba 1.");
                }else{
                    break;
                }
            }catch (invalid_argument e){
                cerr << e.what() << endl;
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

                if (generuotiPaz==0){
                     cout << "Iveskite studento namu darbu rezultatus (baigti su -1): ";
                     while (true) {
                        try{
                            int pazymys;
                            is >> pazymys;

                            if (is.fail() || pazymys<-1 ||pazymys>10) {
                                throw invalid_argument( "Nevalidus pazymys. Prasome ivesti pazymius : ");
                            } else if (pazymys == -1) {
                                break;
                            } else {
                                pazymiai.push_back(pazymys);
                            }
                        }catch (invalid_argument e){
                            cerr << e.what() << endl;
                            is.clear();
                            is.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        student.setPaz(pazymiai);
                    }


                    while (true) {
                        try{
                            int eg;
                            cout << "Iveskite studento egzamino rezultata: ";
                            is >> eg;
                            student.setEgz(eg);

                            if (is.fail() || eg<1 ||eg>10) {
                                throw invalid_argument( "Nevalidus rezultatas. Prasome ivesti pazymi.");
                            } else {
                                break;
                            }
                        }catch (invalid_argument e){
                            cerr << e.what() << endl;
                            is.clear();
                            is.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }



                }else{
                    srand(time(NULL));
                    int ndkiekis;
                    int pazymys;
                    while (true) {
                        try{
                            cout << "Kiek norite pazymiu? ";
                            is >> ndkiekis;

                            if (is.fail() || (ndkiekis<0)) {
                                throw invalid_argument( "Nevalidus pasirinkimas. Prasome ivesti pazymiu kieki.");
                            } else {
                                break;
                            }
                        }catch (invalid_argument e){
                            cerr << e.what() << endl;
                            is.clear();
                            is.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }

                    cout << "Atsitiktinai sugeneruoti studento namu darbu pazymiai:" ;
                    for(int k = 0; k < ndkiekis; k++) {
                        pazymys = 1 + rand() % 10;
                        pazymiai.push_back(pazymys);
                        cout << pazymys << " ";
                    }
                    student.setPaz(pazymiai);
                    cout << endl;
                    student.setEgz(1 + rand() % 10);
                    cout << "Egzaminas: " << student.getEgz() <<endl;

                }

        return is;
    }
};

float vidurkis(vector<int> pazymiai);
float mediana(vector<int> pazymiai);
float skaiciuotiGalutiniBala(Studentas studentas, bool naudotiMediana);
bool palygStudentByKat(const Studentas& a, const Studentas& b);
bool palygStudentByVar(const Studentas& a, const Studentas& b);
bool palygStudentByVar(const Studentas& a, const Studentas& b);
void spausdintiDuomenis(vector<Studentas> studentai);
bool maziau5(const Studentas& student);
bool daugiau5(const Studentas& student);
void rusiuotiDuomenisIsGeneruotoFailo(string failoPavadinimas, int sKiekis, duration<double> diff, int t, double &suma,string rusiuoti,double &sumaNusk,double &sumaRus,double &sumaKiet,double &sumaVarg);
void rusiuotiDuomenisIsEgzistFailo(string failoPavadinimas, int sKiekis, duration<double> diff, int t, double &suma,string rusiuoti,double &sumaNusk,double &sumaRus,double &sumaKiet,double &sumaVarg, int strategija);
void nuskaitytiDuomenisIsFailo(string failoPavadinimas, vector<Studentas>& studentai);
int kiekEiluciu(string failoPavadinimas);
int kiekStulp(string failoPavadinimas);
int GetRandomPaz(int minimum, int maximum);
bool checkFile(string file_name);


#endif // MYLIB_H_INCLUDED
