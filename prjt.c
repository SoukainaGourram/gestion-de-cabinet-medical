#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_APPOINTMENTS 100

typedef struct {
    char nom[50];
    char prenom[50];
    int age;
    char profession[50];
    char situationFamiliale[50];
    char adresse[100];
    char affiliationMutuelle[50];
    char telephone[20];
} Patient;
typedef struct {
    int jour;
    int mois;
    int annee;
}Date;
typedef struct {
      char patientC[100];
     char MedecinC [100];
    Date date[20];
    char etat[50];
} RendezVous;

typedef struct {
    char nom[50];
    char specialite[50];
} Medecin;

typedef struct {
    int debutConsultation;
    int finConsultation;
    float tarif;
} Comptabilite;

Patient patients[MAX_PATIENTS];
int patientCount = 0;

RendezVous rendezVous[MAX_APPOINTMENTS];
int rendezVousCount = 0;

Medecin medecins[MAX_PATIENTS];
int medecinCount = 0;

void ajouterPatient() {
    Patient nouveauPatient;
    printf("Nom: ");
    scanf("%s", nouveauPatient.nom);
    printf("Prénom: ");
    scanf("%s", nouveauPatient.prenom);
    printf(" age: "); 
    scanf("%d", &nouveauPatient.age);
    printf("adresse: ");
    scanf("%s",nouveauPatient.adresse);
    printf("Situation familiale: ");
    scanf("%s",  nouveauPatient.situationFamiliale);
    printf("Affiliation Mutuelle: ");
    scanf("%s", nouveauPatient.affiliationMutuelle);
    printf("Téléphone: ");
    scanf("%s", nouveauPatient.telephone);



    patients[patientCount] = nouveauPatient;
    patientCount++;
    printf("Nouveau patient ajouté avec succès.\n");
}

void rechercherPatient() {
    char nomRecherche[50];
    printf("Nom du patient à rechercher: ");
    scanf("%s", nomRecherche);

    int i;
    for (i = 0; i < patientCount; i++) {
        if (strcmp(nomRecherche, patients[i].nom) == 0) {
            printf("Patient trouvé :\n");
            printf("Nom: %s\n", patients[i].nom);
            printf("Prénom: %s\n", patients[i].prenom);
            printf("Âge: %d\n", patients[i].age);
            printf("Profession: %s\n", patients[i].profession);
            printf("Situation familiale: %s\n", patients[i].situationFamiliale);
            printf("Adresse: %s\n", patients[i].adresse);
            printf("Affiliation Mutuelle: %s\n", patients[i].affiliationMutuelle);
            printf("Téléphone: %s\n", patients[i].telephone);

            return;
        }
    }

    printf("Aucun patient trouvé .\n");
}

void planifierRendezVous() {
    if (rendezVousCount >= MAX_APPOINTMENTS) {
        printf("Nombre maximum de rendez-vous atteint.\n");
        return;
    }

    RendezVous nouveauRendezVous;
    printf("Nom du patient: ");
    scanf("%s", nouveauRendezVous.patientC);
    printf("Nom du médecin: ");
    scanf("%s", nouveauRendezVous.MedecinC);
    printf("Date du rendez-vous(jour mois annee): ");
    scanf("%d %d %d", &nouveauRendezVous.date->jour, &nouveauRendezVous.date->mois, &nouveauRendezVous.date->annee);
    printf("État du rendez-vous: ");
    scanf("%s", nouveauRendezVous.etat);

    rendezVous[rendezVousCount] = nouveauRendezVous;
    rendezVousCount ++ ;
    printf("Rendez-vous planifier avec succès.\n");
    printf("\n");

}

void gererComptabilite() {
    int choix;
    printf("Type de soin :\n");
    printf("1. Consultation\n");
    printf("2. Consultation avec radio\n");
    printf("Choix: ");
    scanf("%d", &choix);

    float tarif = 0;

    switch (choix) {
        case 1:
            tarif = 350;
            break;
        case 2:
            tarif = 350 + 150;
            break ;
        default:
            printf("Choix invalide. Veuillez réessayer.\n");
            return;
    }

    printf("Le tarif à payer est de %.2f DH.\n", tarif);
}

int main() {
    int choix;
    do {
        printf("----------------------------Cabinet Médical - Menu-------------------------\n-");
        printf("-------------------------1. Ajouter un patient--------------------------\n");
        printf("--------------------------2. Rechercher un patient--------------------------\n");
        printf("--------------------------3. Planifier un rendez-vous--------------------------\n");
        printf("--------------------------4. Gérer la comptabilité-------------------------------\n");
        printf("--------------------------5. Quitter----------------------------------\n");
        printf("------------------------------------Choix:----------------------------\n");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterPatient();
                break;
            case 2:
                rechercherPatient();
                break;
            case 3:
                planifierRendezVous();
                break;
            case 4:
                gererComptabilite();
                break;
            case 5:
                printf("bonne santé !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
        printf("\n");
    } while (choix != 5);

    return 0;
}