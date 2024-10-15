#include <iostream>
#include <vector>

using namespace std;

// Función para fusionar dos vectores ordenados
vector<int> fusionarlistas(const vector<int>& a, const vector<int>& b) {
	vector<int> resultado;
	int i = 0, j = 0;
	
	// Fusionar elementos de ambos vectores mientras haya elementos en ambos
	while (i < a.size() && j < b.size()) {
		if (a[i] <= b[j]) {
			resultado.push_back(a[i]);
			i++;
		} else {
			resultado.push_back(b[j]);
			j++;
		}
	}
	
	// Añadir los elementos restantes de a, si los hay
	while (i < a.size()) {
		resultado.push_back(a[i]);
		i++;
	}
	
	// Añadir los elementos restantes de b, si los hay
	while (j < b.size()) {
		resultado.push_back(b[j]);
		j++;
	}
	
	return resultado;
}

// Función para fusionar N vectores ordenados
vector<int> combinarn(const vector<vector<int>>& lista) {
	vector<int> resultado;
	
	// Fusionar uno por uno con el resultado acumulado
	for (int i = 0; i < lista.size(); i++) {
		resultado = fusionarlistas(resultado, lista[i]);
	}
	
	return resultado;
}

// Función para imprimir los elementos de un vector
void imprimirlalista(const vector<int>& lista) {
	for (int i = 0; i < lista.size(); i++) {
		cout << lista[i] << " ";
	}
	cout << endl;
}

int main() {
	int n = 3;  // Número de vectores
	
	// Vectores ordenados que representan las listas originales
	vector<vector<int>> lista(n);
	
	lista[0] = {1, 3, 5, 7,7};
	lista[1] = {2, 4, 6, 8};
	lista[2] = {0, 9, 10, 11};
	
	// Fusionar todos los vectores
	vector<int> resultado = combinarn(lista);
	
	// Imprimir el resultado final
	imprimirlalista(resultado);
	
	return 0;
}
