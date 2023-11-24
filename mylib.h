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

class Studentas {

private:
    string var, pav, kategorija;
    vector<int> paz;
    int egz;
    float rez, rezv, rezm;
public:
    Studentas() : egz(0), rez(0), rezv(0), rezm(0) {}
    Studentas(const string& v, const string& p, const string& kat, const vector<int>& pazymiai, int e)
        : var(v), pav(p), kategorija(kat), paz(pazymiai), egz(e), rez(0), rezv(0), rezm(0) {}

    string getVar() const { return var; }
    string getPav() const { return pav; }
    string getKategorija() const { return kategorija; }
    vector<int> getPaz() const { return paz; }
    int getEgz() const { return egz; }
    float getRez() const { return rez; }
    float getRezV() const { return rezv; }
    float getRezM() const { return rezm; }

    void setVar(const string& v) { var = v; }
    void setPav(const string& p) { pav = p; }
    void setKategorija(const string& kat) { kategorija = kat; }
    void setPaz(const vector<int>& pazymiai) { paz = pazymiai; }
    void setEgz(int e) { egz = e; }
    void setRez(float r) { rez = r; }
    void setRezV(float rv) { rezv = rv; }
    void setRezM(float rm) { rezm = rm; }

    float vidurkis(vector<int> pazymiai);
    float mediana(vector<int> pazymiai);
    float skaiciuotiGalutiniBala(Studentas studentas, bool naudotiMediana);
    int GetRandomPaz(int minimum, int maximum);
    int kiekEiluciu(string failoPavadinimas);
    int kiekStulp(string failoPavadinimas);
    void nuskaitytiDuomenisIsFailo(string failoPavadinimas, vector<Studentas>& studentai);
    bool palygStudentByKat(Studentas a, Studentas b);
    void rusiuotiDuomenisIsGeneruotoFailo(string failoPavadinimas, int sKiekis, duration<double> diff, int t, double &suma,string rusiuoti,double &sumaNusk,double &sumaRus,double &sumaKiet,double &sumaVarg);
    void rusiuotiDuomenisIsEgzistFailo(string failoPavadinimas, int sKiekis, duration<double> diff, int t, double &suma,string rusiuoti,double &sumaNusk,double &sumaRus,double &sumaKiet,double &sumaVarg, int strategija);
    bool palygStudentByVar(Studentas a, Studentas b);
    bool palygStudentByVar(Studentas a, Studentas b);
    void spausdintiDuomenis(vector<Studentas> studentai, bool naudotiMediana, bool naudotiFaila);
    bool checkFile(string file_name);
    bool maziau5(const Studentas& student);
    bool daugiau5(const Studentas& student);

};
#endif // MYLIB_H_INCLUDED
