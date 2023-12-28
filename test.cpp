#include "pch.h"
#include "mylib.h"
#include "mylib.cpp"

TEST(StudentasTest, SkaiciavimuPatikrinimas) {

    Studentas student("Makar", "Lozenko", "Kategorija", { 10, 9, 8 }, 8);

    EXPECT_FLOAT_EQ(student.vidurkis(student.getPaz()), 9.0);

    EXPECT_FLOAT_EQ(student.mediana(student.getPaz()), 9.0);

    float galPazVid = student.skaiciuotiGalutiniBala(student, false);
    EXPECT_FLOAT_EQ(galPazVid, 8.40);

    float galPazMed = student.skaiciuotiGalutiniBala(student, true);
    EXPECT_FLOAT_EQ(galPazMed, 8.40);

}
TEST(StudentasTest, IvedimoPatikrinimas) {

    Studentas student;

    student.setVar("Makar");
    student.setPav("Lozenko");

    EXPECT_EQ(student.getVar(), "Makar");

    EXPECT_EQ(student.getPav(), "Lozenko");

}
