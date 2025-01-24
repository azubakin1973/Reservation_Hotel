
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool criarReserva(vector <vector<string>> & hotel);

void annulerReservation(vector <vector<string>> & hotel);

void modifierReservation(vector <vector<string>> & hotel);

void modifierChambreReservation(vector <vector<string>> & hotel);

void rechercherReservations(vector<vector<string>> & hotel);

bool CroissantNom(const vector<string>& nom1, const vector<string>& nom2);

bool DecroissantNom(const vector<string>& nom1, const vector<string>& nom2);

bool CroissantPrenom(const vector<string>& prenom1, const vector<string>& prenom2);

bool DecroissantPrenom(const vector<string>& prenom1, const vector<string>& prenom2);

bool CroissantChambre(const vector<string>& cham1, const vector<string>& cham2);

void echangerReservations(vector <vector<string>> & hotel);

void croissantDecroissant(vector<vector<string>>& hotel);

bool CroissantChambre(const vector<string>& cham1, const vector<string>& cham2);

void statistiqueReservation(vector <vector<string>> & hotel);



