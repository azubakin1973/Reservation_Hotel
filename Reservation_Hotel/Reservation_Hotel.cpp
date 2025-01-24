// Reservation_Hotel.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <vector>
#include <string>
#include "includes/calculations.h"
#include <algorithm>
using namespace std;


vector<vector<string>> hotel(9,vector<string>(4));


int main()
{
    int choix;
    

    //initializacao dos quartos

    int ncham = 101;
    for (int i = 0; i < 9; i++) {
        hotel[i][0] = to_string(ncham);
        hotel[i][1] = "...";
        hotel[i][2] = "...";
        hotel[i][3] = "non";
        ncham++;
        }

    cout << "Hotel 5 Etoiles ***** \n";
    cout << "========================\n";

    

   
      do {
          
            cout << "\n\nRESERVATION HOTEL\n";
            cout << "-------------------------------------------------\n";
            cout << "MENU GENERAL\n";
            cout << " 1. Creer une reservation\n";
            cout << " 2. Annuler la reservation\n";
            cout << " 3. Modifier une reservation: le nom, le prenom.\n";
            cout << " 4. Modifier la reservation de la chambre, envoyer la reservation a une autre chambre\n";
            cout << " 5. Montrer la liste de reservations(chambre, nom, prenom)\n";
            cout << " 6. Trouver une reservation en tapant le nom, le prenom ou la chambre\n";
            cout << " 7. Echanger les reservations entre les chambres\n";
            cout << " 8. Trier le tableau par reservations, nom ou prenom.\n";
            cout << " 9. Statistique de reservation, pourcentage des chambres occupes\n";
            cout << " 0. Quitter le menu\n";
            cout << "-------------------------------------------------\n";
            cout << "Choix:   ";

            cin >> choix;

            switch (choix) {
            case 1:
                cout << "Creer une reservation\n";
                cout << "_________________________________________________\n\n";
                criarReserva(hotel);
                cout << "_________________________________________________\n\n";


                for (int i = 0; i < 9; i++) {
                    cout << "Chambre: " << hotel[i][0] << ", " << hotel[i][1] << ", " << hotel[i][2] << ", " << hotel[i][3] << endl;
                }break;


            case 2:
                cout << "\n\nAnnuler la reservation\n";
                cout << "------------------------------------------------\n";
                annulerReservation(hotel);
                cout << "------------------------------------------------\n";

                for (int i = 0; i < 9; i++) {
                    cout << "Chambre: " << hotel[i][0] << ", " << hotel[i][1] << ", " << hotel[i][2] << ", " << hotel[i][3] << endl;
                }break;

            case 3:
                cout << "Modifier une reservation: le nom, le prenom.\n";
                cout << "------------------------------------------------\n";
                modifierReservation(hotel);
                cout << "------------------------------------------------\n";

                for (int i = 0; i < 9; i++) {
                    cout << "Chambre: " << hotel[i][0] << ", " << hotel[i][1] << ", " << hotel[i][2] << ", " << hotel[i][3] << endl;
                }break;

            case 4:
                cout << "\n\nModifier la reservation de la chambre, envoyer la reservation à une autre chambre\n";
                cout << "------------------------------------------------\n";
                modifierChambreReservation(hotel);
                cout << "------------------------------------------------\n";

                for (int i = 0; i < 9; i++) {
                    cout << "Chambre: " << hotel[i][0] << ", " << hotel[i][1] << ", " << hotel[i][2] << ", " << hotel[i][3] << endl;
                }break;

            case 5:
                cout << "\n\nMontrer la liste de reservations(chambre, nom, prénom)\n";
                cout << "------------------------------------------------\n";

                for (int i = 0; i < 9; i++) {
                    cout << "Chambre: " << hotel[i][0] << ", " << hotel[i][1] << ", " << hotel[i][2] << ", " << hotel[i][3] << endl;
                }break;


            case 6:
                cout << "\n\nTrouver une reservation en tapant le nom, le prenom ou la chambre\n";
                cout << "------------------------------------------------\n";
                rechercherReservations(hotel);
                break;


            case 7:
                cout << "\n\nEchanger les reservations entre les chambres\n";
                cout << "------------------------------------------------\n";
                echangerReservations(hotel);

                for (int i = 0; i < 9; i++) {
                    cout << "Chambre: " << hotel[i][0] << ", " << hotel[i][1] << ", " << hotel[i][2] << ", " << hotel[i][3] << endl;
                }break;

            case 8:
                cout << "\n\nTrier le tableau par reservations, nom ou prenom.\n";
                cout << "------------------------------------------------\n";
                croissantDecroissant(hotel);
                 break;

            case 9:
                cout << "\n\nStatistique de reservation, pourcentage des chambres occupes\n";
                cout << "------------------------------------------------\n";
                statistiqueReservation(hotel);
                cout << "------------------------------------------------\n";
                break;

            case 0:

                cout << "\n\nPROJET -  Reservation Hotel - FIN\n";
                cout << "------------------------------------------------\n";
                cout << "Pour Alexei de Moraes Zubakin\n";
                cout << "Date: 2024-04-15\n";
                cout << "------------------------------------------------\n";
                cout << "Merci d avoir utilise\n";
                cout << "------------------------------------------------\n";
                cout << "Appuyez sur une touche du clavier pour finir\n";
                cout << "------------------------------------------------\n";

                break;
            }


      } while (choix != 0);



        return 0;
       
}
            
            


       
           



        
       

       
