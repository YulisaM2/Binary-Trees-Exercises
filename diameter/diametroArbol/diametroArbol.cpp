// diametroArbol.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>

 //struct TreeNode {
 //    int val;
 //    TreeNode *left;
 //    TreeNode *right;
 //    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 //};
	// Puedo tener un camino que cruce por la raiz(sumatoria de altura de dos hojas)
	 // Sino, ocupo los caminos mas largos entre el subtree izquierdo y derecho
	 // Comparar si la sumatoria de las alturas, o de los caminosSubtrees son mayores

	 // Comparar sumatoria de alturas con 
	 //									caminoSubtreeIzq
	 //									caminoSubtreeDer

	 int calcAltura(TreeNode* r) {
	 if (r == NULL) {
		 return 0;
	 }

	 int alturaIzq = calcAltura(r->left);
	 int alturaDer = calcAltura(r->right);

	 return 1 + (alturaIzq > alturaDer ? alturaIzq : alturaDer);
 }


 int calcDiametro(TreeNode* r) {
	 if (r == NULL) {
		 return 0;
	 }

	 int alturaIzq = calcAltura(r->left);
	 int alturaDer = calcAltura(r->right);

	 int caminoLargoIzq = calcDiametro(r->left);
	 int caminoLargoDer = calcDiametro(r->right);

	 int mayorCamino = (caminoLargoIzq > caminoLargoDer ? caminoLargoIzq : caminoLargoDer);

	 // No se agrega + 1 a la sumatoria de alturas pues estas ya consideran todos los edges desde que fueron calculados con calcAltura
	 return (mayorCamino > alturaIzq + alturaDer ? mayorCamino : alturaIzq + alturaDer);
 }

 int diameterOfBST(TreeNode* r) {
	 // Si la raiz es NULL o no tiene hijos, no hay edges
	 if (r == NULL) {
		 return 0;
	 }
	 if (r->left == NULL && r->right == NULL) {
		 return 0;
	 }

	 return calcDiametro(r);
 }


int main()
{
    return 0;
}

