#pragma once
#include "ItemMb.h"

const unsigned int NB_CASES_CARRE = 9; 

struct Tableau2D {
	ItemMb** tableau;  //adresse du tableau bidimensionnel en m�moire dynamique  
	unsigned int nb_lignes; //nombre de lignes du tableau
	unsigned int nb_colonnes; //nombre de colonnes du tableau
};

struct LabyrintheMb {
	Tableau2D tableau1; //Tableau repr�sentant la face 1 du ruban
	Tableau2D tableau2; //Tableau repr�sentant la face 2 du ruban
};

struct IndexPositionMb {
	int n_ligne; //Num�ro de ligne
	int n_colonne; //Num�ro de colonne
	bool face;	//Bool�en indiquant soit la face recto (0) ou verso (1)
};

struct Pile {
	int capacite; //Capacit� de la Pile
	int sommet; //Indice du sommet de la Pile
	IndexPositionMb* tableau; //Tableau qui repr�sente la Pile
};

struct Carre {
	IndexPositionMb cases[NB_CASES_CARRE]; //Tableau de NB_CASES_CARRE(9) 
	//qui contiennent les positions connexes d'une position donn�e
};

struct Liste {
	IndexPositionMb* tab; //Tableau qui repr�sente la liste des positions 
	int nb; //Repr�sente le dernier indice de la liste
};

/*
@brief allouer dynamiquement une struct Tableau2D et la retourner
@see d�sallouer l'espace m�moire r�serv� ensuite
@param[in] le nombre de colonnes voulus
@param[in] le nombre de lignes voulus
@return le Tableau2D allou� dynamiquement
@pre nb_colonnes >=0 && nb_lignes >=0
*/
Tableau2D initialiser(unsigned int nb_colonnes, unsigned int nb_lignes);

/*
@brief initialise un LabyrintheMb
@param[in] Tableau2D servant � l'initialisation
@param[in] Tableau2D servant � l'initialisation
return Le LabyrintheMb initialis�
*/
LabyrintheMb initialiser(Tableau2D tab1, Tableau2D tab2);

/*
@brief D�sallouer et d�truire un LabyrintheMb
@param [in-out] LabyrintheMb � d�sallouer
*/
void detruire(LabyrintheMb lab);

/*
@brief Affiche le contenu d'un LabyrintheMb
@param[in] le LabyrintheMb � afficher
*/
void afficher(LabyrintheMb lab);

/*
@brief affiche le contenu d'un LabyrintheMb ainsi que son chemin connexe 
@param[in] le LabyrintheMb � afficher
*/
void afficherSp4(LabyrintheMb lab, Liste liste);

/*
@brief D�sallouer et d�truire un Tableau2D
@param [in-out] Tableau2D � d�sallouer
*/
void detruire(Tableau2D tab);

/*
@brief Empiler un IndexPositionMb sur une pile
@param[in-out] p : la pile
@param[in] it : l'item � empiler
@pre p n'est pas pleine
*/
void empiler(Pile& p, const ItemMb it);

/*
@brief D�piler l'ItemMb au sommet de la pile
@param[in-out] p : la pile
@pre p n'est pas vide
*/
void depiler(Pile& p);

/*
@brief Test de Pile pleine
@param[in] p : la pile test�e
@return true si p est pleine, false sinon
*/
bool estPleine(const Pile& p);

/*
@brief Test de pile vide
@param[in] p : la pile test�e
@return true si p est vide, false sinon
*/
bool estVide(const Pile& p);

/*
@brief Initialiser une Pile Vide en m�moire dynamique
@param[out] p : la pile � initialiser
*/
void initialiser(Pile& p, unsigned int colonnes, unsigned int lignes);

/*
@brief D�sallouer une pile
@param[in-out] p : la pile � d�sallouer
*/
void detruire(Pile& p);

/*
@brief Initialise les 8 positions connexes a une position dans la struct Carre
@param[in] pos : l'IndexPositionMb d'une case
@param[in] lab : Labyrinthe du programme
@return la Struct Carre qui indique les 8 cases connexes a la case pos en in
*/
Carre initialiser(IndexPositionMb pos, LabyrintheMb lab);

/*
@brief Retourne la position du Dragon dans un labyrinthe
@param[in] lab : le LabyrintheMb dans lequel trouv� la position du Dragon
@return L'IndexPositionMb du Dragon dans le LabyrintheMb
*/
IndexPositionMb trouver_dragon(LabyrintheMb lab);
/*
@brief Donne la liste du chemin des 20 premi�res cases
@param[in] lab : Le LabyrintheMb dans lequel trouv� le chemin connexe
@param[in-out] L : la liste qui doit inidiquer le chemin connexe des 20 
premi�res cases
*/
void missionDragonSp4(LabyrintheMb lab, Liste& L);

/*
@brief Retourne l'IndexPositionMb stock� au sommet de la Pile
@param[in] p : La Pile 
@return L'IndexPositionMb stock� au sommet de la Pile 
@pre La Pile n'est pas vide
*/
IndexPositionMb sommet(const Pile& p);

/*
@brief Retournes 1 si l'objet donn� en in se trouve � la pos donn� dans 
le LabyrintheMb
@param[in] l'IndexPositionMb ou chercher
@param[in] lab : Le LabyrintheMb ou chercher
@param[in] objet : l'objet � trouver 
@return bool�en 1 si l'objet donn� est trouv� sinon 0
*/
bool trouver_objet_lab(IndexPositionMb pos, LabyrintheMb lab, 
	unsigned int objet);

/*
@brief initialises une liste en allocation dynamique
@param[in] lab : Le LabyrintheMb qui sert pour l'initialisation
@param[in-out] l : La Liste � initialiser
*/
void initialiser(Liste& l, LabyrintheMb lab);

/*
@brief detruit une liste
@param[in-out] l : La Liste � d�truire
*/
void detruire(Liste& l);

/*
@brief Retournes l'IndexPositionMb stock� � une certaine position de la liste
@param[in] pos : l'indice ou chercher
@param[in] l : la Liste ou chercher
@return l'IndexPositionMb � return
*/
IndexPositionMb lire(Liste& l, unsigned int pos);

/*
@brief ecris au dernier indice d'une liste
@param[in] it : l'IndexPositionMb � �crire
@param[in-out] l : La Liste ou �crire
*/
void ecrire_sommet(Liste& l, const IndexPositionMb it);

/*
@brief supprimes le dernier indice d'une liste
@param[in-out] l : La Liste ou supprimer le dernier indice
*/
void supprimer_sommet(Liste& l);

/*
@brief indique si une liste est vide ou non
@param[in] l : la liste donn�
@return bool�en : 1 si la liste est vide 0 sinon
*/
bool estVide(Liste& l);

/*
@brief indique si une position est connexe � une autre 
@param[in] pos_file : l'IndexPositionMb � comparer 
@param[in] pos : l'IndexPositionMb � comparer
@param[in] lab : le LabyrintheMb ou voir si les positions sont connexes
@return bool�en : 1 si la liste est vide 0 sinon
*/
bool estConnexe(IndexPositionMb pos_file, IndexPositionMb pos, 
	LabyrintheMb lab);

/*
@brief indique si une case appartient � une liste
@param[in] pos : l'IndexPositionMb � �crire
@param[in] l : La Liste ou chercher l'IndexPositionMb
@return bool�en : 1 si la pos est contenu dans la liste 0 sinon
*/
bool case_visitee(Liste l,IndexPositionMb pos);
