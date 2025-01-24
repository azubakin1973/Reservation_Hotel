
#include <iostream>
#include <vector>
#include "calculations.h"
#include <algorithm>
#include < cctype>

using namespace std;

//MENU 1********** Funcao para criar a reserva *****************

bool criarReserva(vector<vector<string>> & hotel) {
    string numeroChambre, nom, prenom;
    cout << "Entrez le numero de la chambre: ";
    cin >> numeroChambre;
    cout << "Entrez le nom: ";
    cin >> nom;
    cout << "Entrez le prenom: ";
    cin >> prenom;

    // Procurar o numero do quarto na matriz hotel e atualizar a reserva

    for (int i = 0; i < 9; i++) {
        if (hotel[i][0] == numeroChambre) {
            if (hotel[i][3] == "non") { // Verifica se o quarto nao esta reservado
                hotel[i][1] = nom;
                hotel[i][2] = prenom;
                hotel[i][3] = "oui";
                cout << "La reservation pour la chambre " << numeroChambre << " a ete creee." << endl;
                return true; // Reserva criada com sucesso
            }
            else {
                cout << "Desole, la chambre " << numeroChambre << " est deja reservee.\n" << endl;
                return false; // Quarto ja esta reservado
            }

            }
    }
    cout << "Desole, la chambre " << numeroChambre << " n'existe pas." << "\n" << "\n";
    return false; // Quarto nao encontrado
}


//MENU 2 ********** Funcao para cancelar a reserva *****************


void annulerReservation(vector<vector<string>> & hotel) {
    string numeroChambre;
    cout << "Entrez le numero de la chambre a annuler: ";
    cin >> numeroChambre;

    // Procurar o numero do quarto na matriz hotel e cancelar a reserva
    for (int i = 0; i < 9; i++) {
        if (hotel[i][0] == numeroChambre) {
            // Limpar o nome, sobrenome e definir "non" para indicar que a reserva foi cancelada
            hotel[i][1] = "...";
            hotel[i][2] = "...";
            hotel[i][3] = "non";
            cout << "La reservation pour la chambre " << numeroChambre << " a ete annulee." << endl;
            return ;
        }
    }
    cout << "Desole, la chambre " << numeroChambre << " n a pas de reservation a annuler." << endl;
}

//MENU 3  ************ Funcao para modificar reserva **************

void modifierReservation(vector<vector<string>> & hotel) {
    string numeroChambre;
    cout << "Entrez le numero de la chambre a modifier: ";
    cin >> numeroChambre;

    // Procurar o numero do quarto na matriz hotel e modificar a reserva
    for (int i = 0; i < 9; i++) {
        if (hotel[i][0] == numeroChambre) {
            string nouveauNom, nouveauPrenom;
            cout << "Entrez le nouveau nom: ";
            cin >> nouveauNom;
            cout << "Entrez le nouveau prenom: ";
            cin >> nouveauPrenom;

            // Atualizar o nom e prenom na matriz hotel
            hotel[i][1] = nouveauNom;
            hotel[i][2] = nouveauPrenom;

            cout << "La reservation pour la chambre " << numeroChambre << " a ete modifiee." << endl;
            return;
        }
    }
    cout << "Desole, la chambre " << numeroChambre << " n a pas de reservation a modifier." << endl;
}

//MENU 4 ***************Funcao para transferir uma reserva***************

void modifierChambreReservation(vector<vector<string>> & hotel) {
    string ancienChambre, nouveauChambre;
    cout << "Entrez le numero de la chambre a deplacer : ";
    cin >> ancienChambre;
    cout << "Entrez le numero de la nouvelle chambre : ";
    cin >> nouveauChambre;
    

    // Procurar o antigo quarto e  o novo quarto na matriz hotel
    int ancien = -1, nouveau = -1;
    for (int i = 0; i < 9; i++) {
        if (hotel[i][0] == ancienChambre) {
            ancien = i;
        }
        if (hotel[i][0] == nouveauChambre) {
            nouveau = i;
        }
    }

    // Verificar se ambos os quartos existem
    if (ancien == -1) {
        cout << "Desole, la chambre " << ancienChambre << " n existe pas." << endl;
        return;
    }
    if (nouveau == -1) {
        cout << "Desole, la chambre " << nouveauChambre << " n existe pas." << endl;
        return;
    }
    
    // Verificar se o novo quarto esta vazio
    if (hotel[nouveau][3] == "oui") {
        cout << "\n**********Desole, la chambre " << nouveauChambre << " est deja occupee.*********" << endl;
        return;
    }
        
    // Transferir os dados da reserva do quarto antigo para o novo quarto
    hotel[nouveau][1] = hotel[ancien][1]; // Nome
    hotel[nouveau][2] = hotel[ancien][2]; // Sobrenome
    hotel[nouveau][3] = "oui"; // Indicar que o novo quarto esta ocupado

    // Limpar os dados do quarto antigo
    hotel[ancien][1] = "...";
    hotel[ancien][2] = "...";
    hotel[ancien][3] = "non"; // Indicar que o quarto antigo esta livre

    cout << "La reservation pour la chambre " << ancienChambre << " a ete deplacee a la chambre " << nouveauChambre << "." << endl;
}


//MENU 6 ************* Funcao para achar a reserva pelo nome, prenom ou quarto*******************


string lowercase(string str) {
    string lowercasestr = str;
    for (char& c : lowercasestr) {
        c = tolower(c);
    }
    return lowercasestr;
}
void rechercherReservations(vector<vector<string>>& hotel) {
    bool trouve = false;
    string recherche, recherchelower;
    cout << "Pour rechercher une reservation, veuillez taper le nom ou le prenom ou la chambre: ";
    cin >> recherche;
    recherchelower = lowercase(recherche);

    cout << "Chambre\tNom\tPrenom\tReservation" << endl;
    for (const auto& Reshotel : hotel) {
        string nomlower = lowercase(Reshotel[1]);
        string prenomlower = lowercase(Reshotel[2]);
        string chambre = lowercase(Reshotel[0]);
        if (nomlower == recherchelower || prenomlower == recherchelower || chambre == recherchelower) {
            cout << Reshotel[0] << "\t" << Reshotel[1] << "\t" << Reshotel[2] << "\t" << Reshotel[3] << endl;
            trouve = true;
        }
    }
         if (!trouve) {
        cout << "Aucune reservation trouvee pour '" << recherche << "'" << endl;
         }
}

//MENU 7 ***************Funcao para trocar as reservas de posicao******************

void echangerReservations(vector<vector<string>> & hotel) {
    string chambre1, chambre2;
    bool found1 = false, found2 = false;

    cout << "Entrez le numero de la premiere chambre : ";
    cin >> chambre1;
    cout << "Entrez le numero de la deuxieme chambre : ";
    cin >> chambre2;

    // Percorrer a matriz hotel e encontrar as posicoes das duas reservas
    int pos1 = -1, pos2 = -1;
    for (int i = 0; i < 9; i++) {
        if (hotel[i][0] == chambre1) {
            pos1 = i;
            found1 = true;
        }
        if (hotel[i][0] == chambre2) {
            pos2 = i;
            found2 = true;
        }
        if (found1 && found2) {
            break;
        }
    }

    // Verificar se ambas as reservas foram encontradas
    if (!found1) {
        cout << "Reservation pour la chambre " << chambre1 << " non trouvee." << endl;
        return;
    }
    if (!found2) {
        cout << "Reservation pour la chambre " << chambre2 << " non trouvee." << endl;
        return;
    }

    // Armazenar temporariamente as informacoes da primeira reserva
    string tempNom = hotel[pos1][1];
    string tempPrenom = hotel[pos1][2];
    string tempEtat = hotel[pos1][3];

    // Atualizar a primeira reserva com as informacoes da segunda reserva
    hotel[pos1][1] = hotel[pos2][1];
    hotel[pos1][2] = hotel[pos2][2];
    hotel[pos1][3] = hotel[pos2][3];

    // Atualizar a segunda reserva com as informacoes armazenadas temporariamente
    hotel[pos2][1] = tempNom;
    hotel[pos2][2] = tempPrenom;
    hotel[pos2][3] = tempEtat;

    cout << "Les reservations pour les chambres " << chambre1 << " et " << chambre2 << " ont ete echangees." << endl;

}


//MENU 8 **************Funcao para colocar em ordem crescente e decrescente **************

bool CroissantNom(const vector<string> & nom1, const vector<string> & nom2) {
    return nom1[1] < nom2[1];
}

bool DecroissantNom(const vector<string>& nom1,const vector<string>& nom2) {
    return nom1[1] > nom2[1];
}

bool CroissantPrenom(const vector<string>& prenom1, const vector<string>& prenom2) {
    return prenom1[2] < prenom2[2];
}

bool DecroissantPrenom(const vector<string>& prenom1, const vector<string>& prenom2) {
    return prenom1[2] > prenom2[2];
}
bool CroissantChambre(const vector<string>& cham1, const vector<string>& cham2) {
    return cham1[0] < cham2[0];
}

void croissantDecroissant(vector<vector<string>>& hotel) {


    cout << " Ordre Croissant ou Decroissant? (C/D) ";
    char resp;
    cin >> resp;
    cout << " Par Nom ou Prenom? (N/P) ";
    char resp1;
    cin >> resp1;

    if ((resp == 'c' || resp == 'C') && (resp1 == 'n' || resp1 == 'N')) {
        sort(hotel.begin(), hotel.end(), CroissantNom);

        for (int i = 0; i < 9; i++) {
            cout << "Chambre: " << hotel[i][0] << ", " << hotel[i][1] << ", " << hotel[i][2] << ", " << hotel[i][3] << endl;
        }

        sort(hotel.begin(), hotel.end(), CroissantChambre);
    }
    else if ((resp == 'd' || resp == 'D') && (resp1 == 'n' || resp1 == 'N')) {
        sort(hotel.begin(), hotel.end(), DecroissantNom);

        for (int i = 0; i < 9; i++) {
            cout << "Chambre: " << hotel[i][0] << ", " << hotel[i][1] << ", " << hotel[i][2] << ", " << hotel[i][3] << endl;
        }

        sort(hotel.begin(), hotel.end(), CroissantChambre);
    }
    else if ((resp == 'c' || resp == 'C') && (resp1 == 'p' || resp1 == 'P')) {
        sort(hotel.begin(), hotel.end(), CroissantPrenom);

        for (int i = 0; i < 9; i++) {
            cout << "Chambre: " << hotel[i][0] << ", " << hotel[i][1] << ", " << hotel[i][2] << ", " << hotel[i][3] << endl;
        }

        sort(hotel.begin(), hotel.end(), CroissantChambre);
    }
    else if ((resp == 'd' || resp == 'D') && (resp1 == 'p' || resp1 == 'P')) {
        sort(hotel.begin(), hotel.end(), DecroissantPrenom);

        for (int i = 0; i < 9; i++) {
            cout << "Chambre: " << hotel[i][0] << ", " << hotel[i][1] << ", " << hotel[i][2] << ", " << hotel[i][3] << endl;
        }

        sort(hotel.begin(), hotel.end(), CroissantChambre);


    }
    else {
        cout << "Choix invalide!" << endl;

        for (const auto& reservation : hotel) {
            for (const auto& list : reservation) {
                cout << list << " ";
            }
            cout << endl;
        }
    }
}
   
  


//MENU 9 **************Funcao para percentual de quartos ocupados**************

void statistiqueReservation(vector<vector<string>> & hotel) {
    int totalChambres = 9; // Total de quartos na matriz hotel
    int chambresOccupees = 0;
    for (int i = 0; i < totalChambres; ++i) {
        if (hotel[i][3] == "oui") {
            chambresOccupees++;
        }
    }

    double pourcentageOccupation = (chambresOccupees * 100.0) / totalChambres;

    cout << "Pourcentage des chambres occupees : " << pourcentageOccupation << "%" << endl;
}